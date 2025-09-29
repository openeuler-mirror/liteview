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

static const AVCodecParser * const parser_list[] = {
    &ff_aac_parser,
    &ff_flac_parser,
    &ff_gsm_parser,
    &ff_h263_parser,
    &ff_h264_parser,
    &ff_mpeg4video_parser,
    &ff_mpegaudio_parser,
    &ff_opus_parser,
    &ff_vorbis_parser,
    &ff_vp3_parser,
    &ff_vp8_parser,
    &ff_vp9_parser,
    NULL };
