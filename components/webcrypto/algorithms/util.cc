// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "components/webcrypto/algorithms/util.h"

#include "base/check_op.h"
#include "components/webcrypto/status.h"
#include "crypto/openssl_util.h"
// #include "third_party/boringssl/src/include/openssl/aead.h"
// #include "third_party/boringssl/src/include/openssl/bn.h"
// #include "third_party/boringssl/src/include/openssl/digest.h"
#include "third_party/openssl/openssl/include/openssl/aead.h"
#include "third_party/openssl/openssl/include/openssl/bn.h"
#include "third_party/openssl/openssl/include/openssl/digest.h"
#include "windows.h"

namespace {
using namespace webcrypto;

struct EvpCipherCtxDeleter {
    void operator()(EVP_CIPHER_CTX* p) const { EVP_CIPHER_CTX_free(p); }
};
using ScopedEVP_CIPHER_CTX = std::unique_ptr<EVP_CIPHER_CTX, EvpCipherCtxDeleter>;

// todo(mb): 目前 mb 没有引入 boringssl, 这里先直接使用 openssl 实现, 
// 由于我对密码学不太熟悉, 这里主要参考了网络实现, 并且注释了查到的一些资料
// 加密: key + iv + plaintext + additional_data => ciphertext + tag
// 解密: key + iv + plaintext + additional_data + tag => plaintext
Status AeadEncryptDecryptOpenSSL(webcrypto::EncryptOrDecrypt mode, // 加密或者解密
    base::span<const uint8_t> raw_key,                             // 原始密钥数据
    base::span<const uint8_t> data,                                // 输入数据, 在加密的时候是明文, 在解密的时候是密文
    unsigned int tag_length_bytes,                                 // AEAD 认证标签的长度
    base::span<const uint8_t> iv,                                  // AEAD 模式要求的随机数或计数器
    base::span<const uint8_t> additional_data,                     // 附加认证数据
    const EVP_CIPHER* cipher,                                      // AEAD 算法指针, 目前的实现中只有两个: EVP_aes_128_gcm 和 EVP_aes_256_gcm
    std::vector<uint8_t>* buffer)                                  // 输出数据, 在加密的时候是密文, 在解密的时候是明文
{
    if (!cipher || !buffer || iv.empty() || raw_key.empty())
        return Status::ErrorUnexpected();

    if (mode == DECRYPT) {
        if (data.size() < tag_length_bytes)
            return Status::ErrorDataTooSmall();
    }

    ScopedEVP_CIPHER_CTX ctx(EVP_CIPHER_CTX_new());
    if (!ctx)
        return Status::OperationError();

    int ok = 1;
    int outlen = 0, tmplen = 0;

    auto set_ivlen_if_needed = [&](EVP_CIPHER_CTX* c) -> bool {
        if (!EVP_CIPHER_CTX_ctrl(c, EVP_CTRL_AEAD_SET_IVLEN,
                static_cast<int>(iv.size()), nullptr)) {
            return false;
        }
        return true;
    };

    if (mode == ENCRYPT) {
        ok = EVP_EncryptInit_ex(ctx.get(), cipher, nullptr, nullptr, nullptr);
        if (!ok)
            return Status::OperationError();

        if (!set_ivlen_if_needed(ctx.get()))
            return Status::OperationError();

        ok = EVP_EncryptInit_ex(ctx.get(), nullptr, nullptr, raw_key.data(), iv.data());
        if (!ok)
            return Status::OperationError();

        if (!additional_data.empty()) {
            ok = EVP_EncryptUpdate(ctx.get(), nullptr, &outlen,
                additional_data.data(),
                static_cast<int>(additional_data.size()));
            if (!ok)
                return Status::OperationError();
        }

        buffer->assign(data.size() + tag_length_bytes, 0);

        int total = 0;
        if (!data.empty()) {
            ok = EVP_EncryptUpdate(ctx.get(), buffer->data(), &outlen,
                data.data(), static_cast<int>(data.size()));
            if (!ok)
                return Status::OperationError();
            total += outlen;
        }

        ok = EVP_EncryptFinal_ex(ctx.get(), buffer->data() + total, &tmplen);
        if (!ok)
            return Status::OperationError();

        total += tmplen;

        std::vector<uint8_t> tag(tag_length_bytes);
        ok = EVP_CIPHER_CTX_ctrl(ctx.get(), EVP_CTRL_AEAD_GET_TAG,
            static_cast<int>(tag_length_bytes), tag.data());
        if (!ok)
            return Status::OperationError();

        buffer->resize(total + static_cast<int>(tag.size()));
        std::memcpy(buffer->data() + total, tag.data(), tag.size());
        return Status::Success();

    } else { // DECRYPT
        const size_t ciphertext_len = data.size() - tag_length_bytes;
        const uint8_t* ciphertext = data.data();
        const uint8_t* tag = data.data() + ciphertext_len;

        ok = EVP_DecryptInit_ex(ctx.get(), cipher, nullptr, nullptr, nullptr);
        if (!ok)
            return Status::OperationError();

        if (!set_ivlen_if_needed(ctx.get()))
            return Status::OperationError();

        ok = EVP_DecryptInit_ex(ctx.get(), nullptr, nullptr, raw_key.data(), iv.data());
        if (!ok)
            return Status::OperationError();

        if (!additional_data.empty()) {
            ok = EVP_DecryptUpdate(ctx.get(), nullptr, &outlen,
                additional_data.data(),
                static_cast<int>(additional_data.size()));
            if (!ok)
                return Status::OperationError();
        }

        ok = EVP_CIPHER_CTX_ctrl(ctx.get(), EVP_CTRL_AEAD_SET_TAG,
            static_cast<int>(tag_length_bytes),
            const_cast<uint8_t*>(tag));
        if (!ok)
            return Status::OperationError();

        buffer->assign(ciphertext_len, 0);
        int total = 0;
        if (ciphertext_len > 0) {
            ok = EVP_DecryptUpdate(ctx.get(), buffer->data(), &outlen,
                ciphertext, static_cast<int>(ciphertext_len));
            if (!ok)
                return Status::OperationError();
            total += outlen;
        }

        ok = EVP_DecryptFinal_ex(ctx.get(), buffer->data() + total, &tmplen);
        if (!ok) {
            buffer->clear();
            return Status::OperationError();
        }
        total += tmplen;
        buffer->resize(total);
        return Status::Success();
    }
}
}

namespace webcrypto {

const EVP_MD* GetDigest(const blink::WebCryptoAlgorithm& hash_algorithm)
{
    return GetDigest(hash_algorithm.Id());
}

const EVP_MD* GetDigest(blink::WebCryptoAlgorithmId id)
{
    switch (id) {
    case blink::kWebCryptoAlgorithmIdSha1:
        return EVP_sha1();
    case blink::kWebCryptoAlgorithmIdSha256:
        return EVP_sha256();
    case blink::kWebCryptoAlgorithmIdSha384:
        return EVP_sha384();
    case blink::kWebCryptoAlgorithmIdSha512:
        return EVP_sha512();
    default:
        return nullptr;
    }
}

void TruncateToBitLength(size_t length_bits, std::vector<uint8_t>* bytes)
{
    size_t length_bytes = NumBitsToBytes(length_bits);

    if (bytes->size() != length_bytes) {
        CHECK_LT(length_bytes, bytes->size());
        bytes->resize(length_bytes);
    }

    size_t remainder_bits = length_bits % 8;

    // Zero any "unused bits" in the final byte.
    if (remainder_bits)
        bytes->back() &= ~((0xFF) >> remainder_bits);
}

Status CheckKeyCreationUsages(blink::WebCryptoKeyUsageMask all_possible_usages, blink::WebCryptoKeyUsageMask actual_usages)
{
    if (!ContainsKeyUsages(all_possible_usages, actual_usages))
        return Status::ErrorCreateKeyBadUsages();
    return Status::Success();
}

bool ContainsKeyUsages(blink::WebCryptoKeyUsageMask a, blink::WebCryptoKeyUsageMask b)
{
    return (a & b) == b;
}

Status AeadEncryptDecrypt(EncryptOrDecrypt mode, base::span<const uint8_t> raw_key, base::span<const uint8_t> data, unsigned int tag_length_bytes,
    base::span<const uint8_t> iv, base::span<const uint8_t> additional_data, const EVP_AEAD* aead_alg, std::vector<uint8_t>* buffer)
{
    // OutputDebugStringA("AeadEncryptDecrypt not impl\n");
    // DebugBreak();

    size_t keySize = raw_key.size();
    const EVP_CIPHER* gcm = nullptr;

    if (keySize == 16) { // 本来应该使用 aead_alg, 但是这是 boringssl 的, 直接根据 keySize 判断使用什么算法
        gcm = EVP_aes_128_gcm();
    } else if (keySize == 32) {
        gcm = EVP_aes_256_gcm();
    } else {
        return Status::OperationError();
    }

    return AeadEncryptDecryptOpenSSL(
        mode,
        raw_key,
        data,
        tag_length_bytes,
        iv,
        additional_data,
        gcm,
        buffer);

    //     crypto::OpenSSLErrStackTracer err_tracer(FROM_HERE);
    //     bssl::ScopedEVP_AEAD_CTX ctx;
    //
    //     if (!aead_alg)
    //         return Status::ErrorUnexpected();
    //
    //     if (!EVP_AEAD_CTX_init(ctx.get(), aead_alg, raw_key.data(), raw_key.size(), tag_length_bytes, nullptr)) {
    //         return Status::OperationError();
    //     }
    //
    //     size_t len;
    //     int ok;
    //
    //     if (mode == DECRYPT) {
    //         if (data.size() < tag_length_bytes)
    //             return Status::ErrorDataTooSmall();
    //
    //         buffer->resize(data.size() - tag_length_bytes);
    //
    //         ok = EVP_AEAD_CTX_open(
    //             ctx.get(), buffer->data(), &len, buffer->size(), iv.data(), iv.size(), data.data(), data.size(), additional_data.data(), additional_data.size());
    //     } else {
    //         // No need to check for unsigned integer overflow here (seal fails if
    //         // the output buffer is too small).
    //         buffer->resize(data.size() + EVP_AEAD_max_overhead(aead_alg));
    //
    //         ok = EVP_AEAD_CTX_seal(
    //             ctx.get(), buffer->data(), &len, buffer->size(), iv.data(), iv.size(), data.data(), data.size(), additional_data.data(), additional_data.size());
    //     }
    //
    //     if (!ok)
    //         return Status::OperationError();
    //     buffer->resize(len);
    return Status::Success();
}

} // namespace webcrypto
