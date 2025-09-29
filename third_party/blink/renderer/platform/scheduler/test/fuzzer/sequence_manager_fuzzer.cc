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

#include <stdlib.h>
#include <iostream>

#include "testing/libfuzzer/proto/lpm_interface.h"
#include "third_party/blink/renderer/platform/scheduler/test/fuzzer/proto/sequence_manager_test_description.pb.h"
#include "third_party/blink/renderer/platform/scheduler/test/fuzzer/sequence_manager_fuzzer_processor.h"
#include "third_party/blink/renderer/platform/wtf/allocator/partitions.h"

// Tests some APIs in base::sequence_manager::SequenceManager (ones defined in
// SequenceManagerTesrDescription proto) for crashes, hangs, memory leaks,
// etc ... by running randomly generated tests, and exposing problematic corner
// cases. For more details, check out go/libfuzzer-chromium.
DEFINE_BINARY_PROTO_FUZZER(const base::sequence_manager::SequenceManagerTestDescription& fuzzer_input)
{
    if (getenv("LPM_DUMP_NATIVE_INPUT")) {
        std::cout << fuzzer_input.DebugString() << std::endl;
    }

    WTF::Partitions::Initialize();
    base::sequence_manager::SequenceManagerFuzzerProcessor::ParseAndRun(fuzzer_input);
}
