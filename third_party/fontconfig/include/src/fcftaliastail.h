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

#if HAVE_GNUC_ATTRIBUTE
#ifdef __fcfreetype__
# undef FcFreeTypeCharIndex
extern __typeof (FcFreeTypeCharIndex) FcFreeTypeCharIndex __attribute((alias("IA__FcFreeTypeCharIndex"))) FC_ATTRIBUTE_VISIBILITY_EXPORT;
# undef FcFreeTypeCharSetAndSpacing
extern __typeof (FcFreeTypeCharSetAndSpacing) FcFreeTypeCharSetAndSpacing __attribute((alias("IA__FcFreeTypeCharSetAndSpacing"))) FC_ATTRIBUTE_VISIBILITY_EXPORT;
# undef FcFreeTypeCharSet
extern __typeof (FcFreeTypeCharSet) FcFreeTypeCharSet __attribute((alias("IA__FcFreeTypeCharSet"))) FC_ATTRIBUTE_VISIBILITY_EXPORT;
#endif /* __fcfreetype__ */
#ifdef __fcpat__
# undef FcPatternGetFTFace
extern __typeof (FcPatternGetFTFace) FcPatternGetFTFace __attribute((alias("IA__FcPatternGetFTFace"))) FC_ATTRIBUTE_VISIBILITY_EXPORT;
# undef FcPatternAddFTFace
extern __typeof (FcPatternAddFTFace) FcPatternAddFTFace __attribute((alias("IA__FcPatternAddFTFace"))) FC_ATTRIBUTE_VISIBILITY_EXPORT;
#endif /* __fcpat__ */
#ifdef __fcfreetype__
# undef FcFreeTypeQueryFace
extern __typeof (FcFreeTypeQueryFace) FcFreeTypeQueryFace __attribute((alias("IA__FcFreeTypeQueryFace"))) FC_ATTRIBUTE_VISIBILITY_EXPORT;
#endif /*  */
#endif /* HAVE_GNUC_ATTRIBUTE */
