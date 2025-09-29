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

#include <openssl/ssl.h>

int BORINGSSL_enum_c_type_test(void);

int BORINGSSL_enum_c_type_test(void) {
#if defined(__cplusplus)
#error "This is testing the behaviour of the C compiler."
#error "It's pointless to build it in C++ mode."
#endif

  // In C++, the enums in ssl.h are explicitly typed as ints to allow them to
  // be predeclared. This function confirms that the C compiler believes them
  // to be the same size as ints. They may differ in signedness, however.
  return sizeof(enum ssl_private_key_result_t) == sizeof(int);
}
