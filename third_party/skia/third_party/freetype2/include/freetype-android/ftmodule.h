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

/*
 * This file registers the FreeType modules compiled into the library.
 *
 * If you use GNU make, this file IS NOT USED!  Instead, it is created in
 * the objects directory (normally `<topdir>/objs/`) based on information
 * from `<topdir>/modules.cfg`.
 *
 * Please read `docs/INSTALL.ANY` and `docs/CUSTOMIZE` how to compile
 * FreeType without GNU make.
 *
 */

FT_USE_MODULE(FT_Module_Class, autofit_module_class)
FT_USE_MODULE(FT_Driver_ClassRec, tt_driver_class)
FT_USE_MODULE(FT_Driver_ClassRec, t1_driver_class)
FT_USE_MODULE(FT_Driver_ClassRec, cff_driver_class)
FT_USE_MODULE(FT_Driver_ClassRec, t1cid_driver_class)
// FT_USE_MODULE( FT_Driver_ClassRec, pfr_driver_class )
// FT_USE_MODULE( FT_Driver_ClassRec, t42_driver_class )
// FT_USE_MODULE( FT_Driver_ClassRec, winfnt_driver_class )
// FT_USE_MODULE( FT_Driver_ClassRec, pcf_driver_class )
// FT_USE_MODULE( FT_Driver_ClassRec, bdf_driver_class )
FT_USE_MODULE(FT_Module_Class, psaux_module_class)
FT_USE_MODULE(FT_Module_Class, psnames_module_class)
FT_USE_MODULE(FT_Module_Class, pshinter_module_class)
FT_USE_MODULE(FT_Module_Class, sfnt_module_class)
FT_USE_MODULE(FT_Renderer_Class, ft_smooth_renderer_class)
FT_USE_MODULE(FT_Renderer_Class, ft_raster1_renderer_class)
// FT_USE_MODULE( FT_Renderer_Class, ft_sdf_renderer_class )
// FT_USE_MODULE( FT_Renderer_Class, ft_bitmap_sdf_renderer_class )
#if defined(FT_CONFIG_OPTION_SVG)
FT_USE_MODULE(FT_Renderer_Class, ft_svg_renderer_class)
#endif

/* EOF */
