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

#include "zip_read_fuzzer.cc"
#include <stdio.h>
#include <stdlib.h>

/* fuzz target entry point, works without libFuzzer */

int main(int argc, char **argv)
{
    FILE *f;
    char *buf = NULL;
    long siz_buf;

    if (argc < 2) {
        fprintf(stderr, "no input file\n");
        goto err;
    }

    f = fopen(argv[1], "rb");
    if (f == NULL) {
        fprintf(stderr, "error opening input file %s\n", argv[1]);
        goto err;
    }

    fseek(f, 0, SEEK_END);

    siz_buf = ftell(f);
    rewind(f);

    if (siz_buf < 1) {
	goto err;
    }

    buf = (char*)malloc(siz_buf);
    if (buf == NULL) {
        fprintf(stderr, "malloc() failed\n");
        goto err;
    }

    if (fread(buf, siz_buf, 1, f) != 1) {
        fprintf(stderr, "fread() failed\n");
        goto err;
    }

    (void)LLVMFuzzerTestOneInput((uint8_t*)buf, siz_buf);

err:
    free(buf);

    return 0;
}
