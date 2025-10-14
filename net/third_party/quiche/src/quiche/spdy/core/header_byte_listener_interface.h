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

#ifndef QUICHE_SPDY_CORE_HEADER_BYTE_LISTENER_INTERFACE_H_
#define QUICHE_SPDY_CORE_HEADER_BYTE_LISTENER_INTERFACE_H_

#include <stddef.h>

#include "quiche/common/platform/api/quiche_export.h"

namespace spdy {

// Listens for the receipt of uncompressed header bytes.
class QUICHE_EXPORT_PRIVATE HeaderByteListenerInterface {
public:
    virtual ~HeaderByteListenerInterface() { }

    // Called when a header block has been parsed, with the number of uncompressed
    // header bytes parsed from the header block.
    virtual void OnHeaderBytesReceived(size_t uncompressed_header_bytes) = 0;
};

} // namespace spdy

#endif // QUICHE_SPDY_CORE_HEADER_BYTE_LISTENER_INTERFACE_H_
