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

static const FFCodec * const codec_list[] = {
    &ff_h263_decoder,
    &ff_h264_decoder,
    &ff_mpeg4_decoder,
    &ff_theora_decoder,
    &ff_vp3_decoder,
    &ff_vp8_decoder,
    &ff_aac_decoder,
    &ff_amrnb_decoder,
    &ff_amrwb_decoder,
    &ff_flac_decoder,
    &ff_gsm_ms_decoder,
    &ff_mp3_decoder,
    &ff_vorbis_decoder,
    &ff_pcm_alaw_decoder,
    &ff_pcm_f32le_decoder,
    &ff_pcm_mulaw_decoder,
    &ff_pcm_s16be_decoder,
    &ff_pcm_s16le_decoder,
    &ff_pcm_s24be_decoder,
    &ff_pcm_s24le_decoder,
    &ff_pcm_s32le_decoder,
    &ff_pcm_u8_decoder,
    &ff_libopus_decoder,
    NULL };
