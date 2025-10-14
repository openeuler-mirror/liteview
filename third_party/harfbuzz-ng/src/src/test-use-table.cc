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

#include "hb-ot-shaper-use-table.hh"

int main(int argc, char** argv)
{
    if (argc != 2) {
        for (unsigned u = 0; u < 0x10FFFFu; u++)
            printf("U+%04X %d\n", u, hb_use_get_category(u));
        return 0;
    }

    hb_codepoint_t u;
    sscanf(argv[1], "%x", &u);

    printf("%d\n", hb_use_get_category(u));

    return 0;
}
