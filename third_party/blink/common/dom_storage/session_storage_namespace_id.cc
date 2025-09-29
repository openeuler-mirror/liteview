// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/public/common/dom_storage/session_storage_namespace_id.h"

#include <algorithm>

#include "base/check_op.h"
#include "base/guid.h"

namespace blink {

SessionStorageNamespaceId AllocateSessionStorageNamespaceId()
{
    static int s_id = 1000;
    s_id++;
    char str_id[256] = { 0 };
    sprintf(str_id, "%d", s_id);
    
//     SessionStorageNamespaceId output = "AllocateSessionStorageNamespaceId:";
//     output += str_id;
//     output += "\n";
//     OutputDebugStringA(output.c_str());

    SessionStorageNamespaceId ret = "SessionStorageNamespaceId_";
    ret += str_id;
    return ret;

//     std::string guid = base::GenerateGUID();
//     std::replace(guid.begin(), guid.end(), '-', '_');
//     // The database deserialization code makes assumptions based on this length.
//     DCHECK_EQ(guid.size(), kSessionStorageNamespaceIdLength);
//     return guid;
}

} // namespace blink
