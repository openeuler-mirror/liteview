//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//

if (slen-- == 0) {
    break;
}
*o++ = base64_table_enc_6bit[*s >> 2];
st.carry = (*s++ << 4) & 0x30;
st.bytes++;
olen += 1;

// Deliberate fallthrough:
BASE64_FALLTHROUGH

case 1:
if (slen-- == 0) {
    break;
}
*o++ = base64_table_enc_6bit[st.carry | (*s >> 4)];
st.carry = (*s++ << 2) & 0x3C;
st.bytes++;
olen += 1;

// Deliberate fallthrough:
BASE64_FALLTHROUGH

case 2:
if (slen-- == 0) {
    break;
}
*o++ = base64_table_enc_6bit[st.carry | (*s >> 6)];
*o++ = base64_table_enc_6bit[*s++ & 0x3F];
st.bytes = 0;
olen += 2;
}
}
state->bytes = st.bytes;
state->carry = st.carry;
*outlen = olen;
