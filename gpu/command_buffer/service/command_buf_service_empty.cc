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


#include "third_party/angle/include/GLSLANG/ShaderLang.h"
#include "third_party/angle/include/GLSLANG/ShaderVars.h"
#include "third_party/angle/src/common/angle_version_info.h"
#include "third_party/angle/src/gpu_info_util/SystemInfo.h"
#include "ui/gfx/mojom/buffer_types.mojom-shared-internal.h"
#include "ui/gl/angle_platform_impl.h"
#ifdef OS_WIN
#include "ui/gl/direct_composition_support.h"
#include "ui/gl/gl_angle_util_win.h"
#endif
#include "ui/gfx/codec/png_codec.h"
#ifdef OS_WIN
#include "gpu/command_buffer/service/shared_image/d3d_image_backing_factory.h"
#include "gpu/command_buffer/service/dxgi_shared_handle_manager.h"
#endif
#include "gpu/command_buffer/service/shared_image/shared_image_backing.h"
#include "gpu/command_buffer/service/decoder_client.h"
#include "gpu/command_buffer/service/memory_program_cache.h"

#include "gpu/skia_bindings/gles2_implementation_with_grcontext_support.h"
#include "gpu/config/gpu_util.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info_collector.h"
#include "gpu/ipc/common/gpu_preferences.mojom-shared-internal.h"
#include "gpu/ipc/common/gpu_preferences.mojom.h"
#include "gpu/ipc/service/context_url.h"
#include "components/viz/common/resources/resource_format_utils.h"
#ifdef OS_WIN
#include "media/base/win/mf_helpers.h"
#else
#include "ui/ozone/platform/x11/ozone_platform_x11.h"
//#include "ui/ozone/platform/x11/gl_surface_egl_readback_x11.h"
#include "ui/ozone/public/ozone_platform.h"
#include "ui/ozone/public/platform_screen.h"
#include "ui/ozone/public/system_input_injector.h"
#include "ui/ozone/public/surface_factory_ozone.h"
#include "ui/ozone/public/native_pixmap_gl_binding.h"
#include "ui/ozone/common/gl_ozone_egl.h"
#include "ui/ozone/common/egl_util.h"
#include "ui/events/devices/device_data_manager.h"
#include "ui/gfx/client_native_pixmap_factory.h"
#include "ui/gl/gl_fence_android_native_fence_sync.h"
#include "ui/gl/gl_image_native_pixmap.h"
#include "ui/base/ime/input_method.h"
#include "ui/display/types/native_display_delegate.h"
#include "ui/platform_window/platform_window_init_properties.h"
#include "gpu/command_buffer/service/shared_image/ozone_image_backing_factory.h"
#endif
#include "ui/gfx/ipc/color/gfx_param_traits.h" // nogncheck
#include <windows.h>
//#include <Xlib.h>

typedef struct _XDisplay Display;

extern "C" Display * XOpenDisplay(
    const char*	/* display_name */
);

// namespace features {
// // Enables the eye-dropper in the refresh color-picker for Windows, Mac
// // and Linux. This feature will be released for other platforms in later
// // milestones.
// BASE_FEATURE(kEyeDropper, "EyeDropper",
// #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)   
//     base::FEATURE_ENABLED_BY_DEFAULT
// #else
//     base::FEATURE_DISABLED_BY_DEFAULT
// #endif
// );
// }
#ifdef OS_WIN
gpu::D3DImageBackingFactory::~D3DImageBackingFactory(void)
{
    *(int*)1 = 1;
}
#else

std::unique_ptr<gl::GLFenceAndroidNativeFenceSync> gl::GLFenceAndroidNativeFenceSync::CreateForGpuFence()
{
    printf("GLFenceAndroidNativeFenceSync::CreateForGpuFence not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

gpu::OzoneImageBackingFactory::OzoneImageBackingFactory(gpu::SharedContextState* shared_context_state, 
    gpu::GpuDriverBugWorkarounds const& workarounds, gpu::GpuPreferences const& gpu_preferences)
    : shared_context_state_(shared_context_state)
    , workarounds_(workarounds)
    , use_passthrough_(false
        //gpu_preferences.use_passthrough_cmd_decoder && gles2::PassthroughCommandDecoderSupported()
    )
{
    printf("ui::OzoneImageBackingFactory not impl\n");
    *(int*)1 = 1;
}

gpu::OzoneImageBackingFactory::~OzoneImageBackingFactory()
{
    printf("ui::OzoneImageBackingFactory not impl\n");
    *(int*)1 = 1;
}

std::unique_ptr<gpu::SharedImageBacking> gpu::OzoneImageBackingFactory::CreateSharedImage(
    const gpu::Mailbox& mailbox, viz::SharedImageFormat format, gpu::SurfaceHandle surface_handle, const gfx::Size& size,
    const gfx::ColorSpace& color_space, GrSurfaceOrigin surface_origin, SkAlphaType alpha_type, uint32_t usage, bool is_thread_safe)
{
    printf("OzoneImageBackingFactory::CreateSharedImage not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

std::unique_ptr<gpu::SharedImageBacking> gpu::OzoneImageBackingFactory::CreateSharedImage(const gpu::Mailbox& mailbox, 
    viz::SharedImageFormat format, const gfx::Size& size, const gfx::ColorSpace& color_space,
    GrSurfaceOrigin surface_origin, SkAlphaType alpha_type, uint32_t usage, base::span<const uint8_t> pixel_data)
{
    printf("OzoneImageBackingFactory::CreateSharedImage not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

std::unique_ptr<gpu::SharedImageBacking> gpu::OzoneImageBackingFactory::CreateSharedImage(const gpu::Mailbox& mailbox, int client_id, 
    gfx::GpuMemoryBufferHandle handle, gfx::BufferFormat format,
    gfx::BufferPlane plane, gpu::SurfaceHandle surface_handle, const gfx::Size& size, const gfx::ColorSpace& color_space, 
    GrSurfaceOrigin surface_origin, SkAlphaType alpha_type,
    uint32_t usage)
{
    printf("OzoneImageBackingFactory::CreateSharedImage not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

bool gpu::OzoneImageBackingFactory::IsSupported(uint32_t usage, viz::SharedImageFormat format, const gfx::Size& size, bool thread_safe, gfx::GpuMemoryBufferType gmb_type, GrContextType gr_context_type,
    base::span<const uint8_t> pixel_data)
{
    printf("OzoneImageBackingFactory::IsSupported not impl\n");
    *(int*)1 = 1;
    return false;
}

std::unique_ptr<gl::GLFenceAndroidNativeFenceSync> gl::GLFenceAndroidNativeFenceSync::CreateFromGpuFence(gfx::GpuFence const&)
{
    printf("GLFenceAndroidNativeFenceSync::CreateFromGpuFence not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

bool gl::GLImageNativePixmap::InitializeFromTexture(uint32_t texture_id)
{
    printf("GLImageNativePixmap::InitializeFromTexture not impl\n");
    *(int*)1 = 1;
    return false;
}

gl::GLImageNativePixmap::GLImageNativePixmap(const gfx::Size& size, gfx::BufferFormat format, gfx::BufferPlane plane)
    : GLImageEGL(size)
    , format_(format)
    , plane_(plane)
    , has_image_flush_external_(false/*gl::GLSurfaceEGL::GetGLDisplayEGL()->ext->b_EGL_EXT_image_flush_external*/)
    , has_image_dma_buf_export_(false/*gl::GLSurfaceEGL::GetGLDisplayEGL()->ext->b_EGL_MESA_image_dma_buf_export*/)
{
    printf("GLImageNativePixmap::GLImageNativePixmap not impl\n");
    *(int*)1 = 1;
}

gl::GLImageNativePixmap::~GLImageNativePixmap() { }

unsigned gl::GLImageNativePixmap::GetInternalFormat()
{
    *(int*)1 = 1;
    return 0;
}

unsigned gl::GLImageNativePixmap::GetDataType()
{
    *(int*)1 = 1;
    return 0;
}

bool gl::GLImageNativePixmap::BindTexImage(unsigned target)
{
    *(int*)1 = 1;
    return false;
}

bool gl::GLImageNativePixmap::CopyTexImage(unsigned target)
{
    *(int*)1 = 1;
    return false;
}

bool gl::GLImageNativePixmap::CopyTexSubImage(unsigned target, const gfx::Point& offset, const gfx::Rect& rect)
{
    *(int*)1 = 1;
    return false;
}

void gl::GLImageNativePixmap::Flush()
{
    *(int*)1 = 1;
}
void gl::GLImageNativePixmap::OnMemoryDump(base::trace_event::ProcessMemoryDump* pmd, uint64_t process_tracing_id, const std::string& dump_name)
{
    *(int*)1 = 1;
}

scoped_refptr<gfx::NativePixmap> gl::GLImageNativePixmap::GetNativePixmap()
{
    *(int*)1 = 1;
    return nullptr;
}

namespace ui {
OzonePlatform* CreateOzonePlatformX11();
OzonePlatform* CreateOzonePlatformHeadless();
OzonePlatform* CreateOzonePlatformWayland();

gfx::ClientNativePixmapFactory* CreateClientNativePixmapFactoryX11();
gfx::ClientNativePixmapFactory* CreateClientNativePixmapFactoryHeadless();
gfx::ClientNativePixmapFactory* CreateClientNativePixmapFactoryWayland();

namespace {

class GLOzoneEGLX11 : public GLOzoneEGL {
public:
    GLOzoneEGLX11() = default;

    GLOzoneEGLX11(const GLOzoneEGLX11&) = delete;
    GLOzoneEGLX11& operator=(const GLOzoneEGLX11&) = delete;

    ~GLOzoneEGLX11() override = default;

    // GLOzone:
    bool InitializeStaticGLBindings(const gl::GLImplementationParts& implementation) override
    {
        is_swiftshader_ = gl::IsSoftwareGLImplementation(implementation);
        printf("InitializeStaticGLBindings, is_swiftshader_: %d\n", is_swiftshader_);
        return GLOzoneEGL::InitializeStaticGLBindings(implementation);
    }

    bool CanImportNativePixmap() override
    {
        //return gl::GLSurfaceEGL::GetGLDisplayEGL()->ext->b_EGL_EXT_image_dma_buf_import;
        printf("GLOzoneEGLX11 CanImportNativePixmap not impl\n");
        *(int*)1 = 1;
        return false;
    }

    std::unique_ptr<NativePixmapGLBinding> ImportNativePixmap(
        scoped_refptr<gfx::NativePixmap> pixmap, 
        gfx::BufferFormat plane_format, gfx::BufferPlane plane,
        gfx::Size plane_size, 
        const gfx::ColorSpace& color_space, 
        GLenum target, 
        GLuint texture_id) override
    {
        //return NativePixmapEGLBinding::Create(pixmap, plane_format, plane, plane_size, color_space, target, texture_id);
        printf("GLOzoneEGLX11::ImportNativePixmap not impl\n");
        *(int*)1 = 1;
    }

    scoped_refptr<gl::GLSurface> CreateViewGLSurface(gl::GLDisplay* display, gfx::AcceleratedWidget window) override
    {
        printf("GLOzoneEGLX11 CreateViewGLSurface not impl\n");
        *(int*)1 = 1;
        return nullptr;

//         if (is_swiftshader_) {
//             return gl::InitializeGLSurface(base::MakeRefCounted<GLSurfaceEglReadbackX11>(display->GetAs<gl::GLDisplayEGL>(), window));
//         } else {
//             switch (gl::GetGLImplementation()) {
//                 case gl::kGLImplementationEGLGLES2:
//                     DCHECK(window != gfx::kNullAcceleratedWidget);
//                     return gl::InitializeGLSurface(new gl::NativeViewGLSurfaceEGLX11GLES2(display->GetAs<gl::GLDisplayEGL>(), static_cast<x11::Window>(window)));
//                 case gl::kGLImplementationEGLANGLE:
//                     DCHECK(window != gfx::kNullAcceleratedWidget);
//                     return gl::InitializeGLSurface(new gl::NativeViewGLSurfaceEGLX11(display->GetAs<gl::GLDisplayEGL>(), static_cast<x11::Window>(window)));
//                 default:
//                     NOTREACHED();
//                     return nullptr;
//             }
//         }
    }

    scoped_refptr<gl::GLSurface> CreateOffscreenGLSurface(gl::GLDisplay* display, const gfx::Size& size) override
    {
        gl::GLDisplayEGL* egl_display = display->GetAs<gl::GLDisplayEGL>();
        if (egl_display->IsEGLSurfacelessContextSupported() && size.width() == 0 && size.height() == 0) {
            return InitializeGLSurface(new gl::SurfacelessEGL(egl_display, size));
        } else {
            return InitializeGLSurface(new gl::PbufferGLSurfaceEGL(egl_display, size));
        }
    }

protected:
    // GLOzoneEGL:
    gl::EGLDisplayPlatform GetNativeDisplay() override
    {
        //printf("GLOzoneEGLX11 GetNativeDisplay not impl\n");
        //return gl::EGLDisplayPlatform((EGLNativeDisplayType)(XOpenDisplay(NULL)), 0);
        return gl::EGLDisplayPlatform(EGL_DEFAULT_DISPLAY);
        //return gl::EGLDisplayPlatform(reinterpret_cast<EGLNativeDisplayType>(x11::Connection::Get()->GetXlibDisplay().display()));
    }

    bool LoadGLES2Bindings(const gl::GLImplementationParts& implementation) override
    {
        return LoadDefaultEGLGLES2Bindings(implementation);
    }

private:
    bool is_swiftshader_ = false;
};

} // namespace

class X11SurfaceFactoryEmpty : public SurfaceFactoryOzone {
public:
    X11SurfaceFactoryEmpty()
        : egl_implementation_(std::make_unique<GLOzoneEGLX11>())
    {

    }

    ~X11SurfaceFactoryEmpty() override
    {

    }

    std::vector<gl::GLImplementationParts> GetAllowedGLImplementations() override
    {
        std::vector<gl::GLImplementationParts> impls;
        impls.emplace_back(gl::GLImplementationParts(gl::kGLImplementationEGLANGLE));
        return impls;
    }

    GLOzone* GetGLOzone(const gl::GLImplementationParts& implementation) override
    {
        switch (implementation.gl) {
            case gl::kGLImplementationDesktopGL:
                //return glx_implementation_.get();
                printf("X11SurfaceFactory::GetGLOzone, gl::kGLImplementationDesktopGL not impl\n");
                *(int*)1 = 1;
                return nullptr;
            case gl::kGLImplementationEGLGLES2:
            case gl::kGLImplementationEGLANGLE:
                return egl_implementation_.get();
            default:
                return nullptr;
        }
        //return nullptr;
    }

    std::unique_ptr<GLOzone> egl_implementation_;
};

class OzonePlatformX11Empty : public OzonePlatform {
    /*virtual*/ bool InitializeUI(const OzonePlatform::InitParams& params) override
    {
        surface_factory_ozone_ = std::make_unique<X11SurfaceFactoryEmpty>();
        return true;
    }
    /*virtual*/ void InitializeGPU(const OzonePlatform::InitParams& params) override
    {
    }

    /*virtual*/ ui::SurfaceFactoryOzone* GetSurfaceFactoryOzone() override
    {
        return surface_factory_ozone_.get();
    }
    /*virtual*/ ui::OverlayManagerOzone* GetOverlayManager() override
    {
        printf("OzonePlatformX11Empty::GetOverlayManager not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ ui::CursorFactory* GetCursorFactory() override
    {
        printf("OzonePlatformX11Empty::GetCursorFactory not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ ui::InputController* GetInputController() override
    {
        printf("OzonePlatformX11Empty::GetInputController not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ ui::GpuPlatformSupportHost* GetGpuPlatformSupportHost() override
    {
        printf("OzonePlatformX11Empty::GetGpuPlatformSupportHost not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ std::unique_ptr<ui::SystemInputInjector> CreateSystemInputInjector() override
    {
        printf("OzonePlatformX11Empty::CreateSystemInputInjector not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ std::unique_ptr<ui::PlatformWindow> CreatePlatformWindow(PlatformWindowDelegate* delegate, ui::PlatformWindowInitProperties properties) override
    {
        printf("OzonePlatformX11Empty::CreatePlatformWindow not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ std::unique_ptr<display::NativeDisplayDelegate> CreateNativeDisplayDelegate() override
    {
        printf("OzonePlatformX11Empty::CreateNativeDisplayDelegate not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ std::unique_ptr<ui::PlatformScreen> CreateScreen() override
    {
        printf("OzonePlatformX11Empty::CreateScreen not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }
    /*virtual*/ void InitScreen(ui::PlatformScreen* screen) override
    {
        printf("OzonePlatformX11Empty::InitScreen not impl\n");
        *(int*)1 = 1;
    }
    /*virtual*/ std::unique_ptr<ui::InputMethod> CreateInputMethod(ui::ImeKeyEventDispatcher* ime_key_event_dispatcher, gfx::AcceleratedWidget widget) override
    {
        printf("OzonePlatformX11Empty::CreateInputMethod not impl\n");
        *(int*)1 = 1;
        return nullptr;
    }

private:
    //std::unique_ptr<X11SurfaceFactory> surface_factory_ozone_;
    std::unique_ptr<X11SurfaceFactoryEmpty> surface_factory_ozone_;
};

}

ui::OzonePlatform* ui::CreateOzonePlatformX11()
{
    return new ui::OzonePlatformX11Empty();
}

ui::OzonePlatform* ui::CreateOzonePlatformHeadless()
{
    printf("ui::CreateOzonePlatformHeadless not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

ui::OzonePlatform* ui::CreateOzonePlatformWayland()
{
    printf("ui::CreateOzonePlatformWayland not impl\n");
    *(int*)1 = 1;
    return nullptr;
}

gfx::ClientNativePixmapFactory* ui::CreateClientNativePixmapFactoryX11()
{
    *(int*)1 = 1;
    return nullptr;
}

gfx::ClientNativePixmapFactory* ui::CreateClientNativePixmapFactoryHeadless()
{
    *(int*)1 = 1;
    return nullptr;
}

gfx::ClientNativePixmapFactory* ui::CreateClientNativePixmapFactoryWayland()
{
    *(int*)1 = 1;
    return nullptr;
}

#endif

gpu::gles2::MemoryProgramCache::ProgramCacheValue::~ProgramCacheValue(void)
{
    *(int*)1 = 1;
}

gpu::gles2::MemoryProgramCache::~MemoryProgramCache(void)
{

}

void gpu::gles2::MemoryProgramCache::LoadProgram(const std::string& key, const std::string& program)
{
    *(int*)1 = 1;
}

size_t gpu::gles2::MemoryProgramCache::Trim(size_t)
{
    *(int*)1 = 1;
    return 0;
}

gpu::gles2::ProgramCache::ProgramLoadResult 
gpu::gles2::MemoryProgramCache::LoadLinkedProgram(
    GLuint program, 
    gpu::gles2::Shader* shader_a,
    gpu::gles2::Shader* shader_b, const gpu::gles2::ProgramCache::LocationMap* bind_attrib_location_map,
    const std::vector<std::string>& transform_feedback_varyings, GLenum transform_feedback_buffer_mode, gpu::DecoderClient* client)
{
    *(int*)1 = 1;
    return gpu::gles2::ProgramCache::ProgramLoadResult::PROGRAM_LOAD_FAILURE;
}

void gpu::gles2::MemoryProgramCache::SaveLinkedProgram(
    GLuint program, 
    const gpu::gles2::Shader* shader_a, 
    const gpu::gles2::Shader* shader_b, 
    const gpu::gles2::ProgramCache::LocationMap* bind_attrib_location_map,
    const std::vector<std::string>& transform_feedback_varyings, 
    GLenum transform_feedback_buffer_mode, 
    gpu::DecoderClient* client)
{
    *(int*)1 = 1;
}

#ifdef OS_WIN
gpu::D3DImageBackingFactory::SwapChainBackings::SwapChainBackings(
    std::unique_ptr<gpu::SharedImageBacking> front_buffer, 
    std::unique_ptr<gpu::SharedImageBacking> back_buffer)
    : front_buffer(std::move(front_buffer))
    , back_buffer(std::move(back_buffer))
{
    *(int*)1 = 1;
}

std::unique_ptr<gpu::SharedImageBacking> 
gpu::D3DImageBackingFactory::CreateSharedImage(
    const gpu::Mailbox& mailbox, int client_id, 
    gfx::GpuMemoryBufferHandle handle, 
    gfx::BufferFormat format,
    gfx::BufferPlane plane, 
    gpu::SurfaceHandle surface_handle,
    const gfx::Size& size, 
    const gfx::ColorSpace& color_space, 
    GrSurfaceOrigin surface_origin, SkAlphaType alpha_type,
    uint32_t usage)
{
    *(int*)1 = 1;
    return nullptr;
}

std::unique_ptr<gpu::SharedImageBacking>
gpu::D3DImageBackingFactory::CreateSharedImage(
    const gpu::Mailbox& mailbox, 
    viz::SharedImageFormat format, const gfx::Size& size,
    const gfx::ColorSpace& color_space, 
    GrSurfaceOrigin surface_origin, 
    SkAlphaType alpha_type, 
    uint32_t usage, 
    base::span<const uint8_t> pixel_data)
{
    *(int*)1 = 1;
    return nullptr;
}

std::unique_ptr<gpu::SharedImageBacking>
gpu::D3DImageBackingFactory::CreateSharedImage(
    const Mailbox& mailbox, 
    viz::SharedImageFormat format, 
    SurfaceHandle surface_handle,
    const gfx::Size& size, 
    const gfx::ColorSpace& color_space, 
    GrSurfaceOrigin surface_origin, 
    SkAlphaType alpha_type, 
    uint32_t usage, 
    bool is_thread_safe)
{
    *(int*)1 = 1;
    return nullptr;
}

bool gpu::D3DImageBackingFactory::IsSupported(
    uint32_t usage, 
    viz::SharedImageFormat format, 
    const gfx::Size& size, 
    bool thread_safe, 
    gfx::GpuMemoryBufferType gmb_type,
    GrContextType gr_context_type, 
    base::span<const uint8_t> pixel_data)
{
    *(int*)1 = 1;
    return false;
}
#endif

bool mojo::StructTraits<gfx::mojom::BufferUsageAndFormatDataView, gfx::BufferUsageAndFormat>::Read(
    gfx::mojom::BufferUsageAndFormatDataView, gfx::BufferUsageAndFormat*)
{
    *(int*)1 = 1;
    return false;
}

void IPC::ParamTraits<gfx::ColorSpace>::Write(base::Pickle*, gfx::ColorSpace const&)
{
    *(int*)1 = 1;
}

bool IPC::ParamTraits<gfx::ColorSpace>::Read(base::Pickle const*, base::PickleIterator*, gfx::ColorSpace*)
{
    *(int*)1 = 1;
    return false;
}

#ifdef OS_WIN
gpu::DXGISharedHandleManager::~DXGISharedHandleManager(void)
{
    *(int*)1 = 1;
}
#endif

void gpu::gles2::MemoryProgramCache::ClearBackend(void)
{
    *(int*)1 = 1;
}

#ifdef OS_WIN
#if !defined(ENABLE_MB_MEDIA) 
long media::SetDebugName(IDXGIObject*, char const*)
{
    *(int*)1 = 1;
    return 0;
}

long __cdecl media::SetDebugName(ID3D11DeviceChild*, char const*)
{
    *(int*)1 = 1;
    return 0;
}
#endif

Microsoft::WRL::ComPtr<struct ID3D11Device> gl::QueryD3D11DeviceObjectFromANGLE(void)
{
    OutputDebugStringA("gl::QueryD3D11DeviceObjectFromANGLE not impl\n");
    return nullptr;
}
#endif

#ifdef OS_LINUX
namespace angle
{
GPUDeviceInfo::GPUDeviceInfo() = default;

GPUDeviceInfo::~GPUDeviceInfo() = default;

GPUDeviceInfo::GPUDeviceInfo(const GPUDeviceInfo& other) = default;

SystemInfo::SystemInfo() = default;

SystemInfo::~SystemInfo() = default;

SystemInfo::SystemInfo(const SystemInfo& other) = default;

bool GetSystemInfoVulkan(angle::SystemInfo* info)
{
    return false;
}
}

void ui::DeviceDataManager::CreateInstance()
{

}

#endif // OS_LINUX

#ifdef OS_WIN
void gl::ShutdownDirectComposition(void)
{
    OutputDebugStringA("gl::ShutdownDirectComposition not impl\n");
}

void gl::InitializeDirectComposition(gl::GLDisplayEGL*)
{
    OutputDebugStringA("gl::InitializeDirectComposition not impl\n");
}
#endif

unsigned int viz::GLDataType(class viz::SharedImageFormat)
{
    *(int*)1 = 1;
    return 0;
}

unsigned int viz::GLDataFormat(class viz::SharedImageFormat)
{
    *(int*)1 = 1;
    return 0;
}

gpu::gles2::MemoryProgramCache::MemoryProgramCache(
    size_t max_cache_size_bytes, 
    bool disable_gpu_shader_disk_cache, 
    bool disable_program_caching_for_transform_feedback, 
    gpu::GpuProcessActivityFlags* activity_flags)
    : ProgramCache(max_cache_size_bytes)
    , disable_gpu_shader_disk_cache_(disable_gpu_shader_disk_cache)
    , disable_program_caching_for_transform_feedback_(disable_program_caching_for_transform_feedback)
    , compress_program_binaries_(false)
    , curr_size_bytes_(0)
    , store_(ProgramLRUCache::NO_AUTO_EVICT)
    , activity_flags_(activity_flags)
{
    *(int*)1 = 1;
}

#ifdef OS_WIN
gpu::DXGISharedHandleManager::DXGISharedHandleManager(Microsoft::WRL::ComPtr<ID3D11Device>)
{
    *(int*)1 = 1;
}

gpu::D3DImageBackingFactory::D3DImageBackingFactory(Microsoft::WRL::ComPtr<ID3D11Device> d3d11_device, scoped_refptr<DXGISharedHandleManager> dxgi_shared_handle_manager)
{
    *(int*)1 = 1;
}

gpu::D3DImageBackingFactory::SwapChainBackings::~SwapChainBackings(void)
{
    *(int*)1 = 1;
}
#endif

gpu::ContextUrl::ContextUrl(class GURL)
{
    OutputDebugStringA("ContextUrl not impl\n");
}

gfx::PNGCodec::Comment::~Comment(void)
{
    *(int*)1 = 1;
}

#ifdef OS_WIN
gpu::D3DImageBackingFactory::SwapChainBackings gpu::D3DImageBackingFactory::CreateSwapChain(
    const gpu::Mailbox& front_buffer_mailbox, 
    const gpu::Mailbox& back_buffer_mailbox,
    viz::ResourceFormat format, const gfx::Size& size, 
    const gfx::ColorSpace& color_space, 
    GrSurfaceOrigin surface_origin, 
    SkAlphaType alpha_type, 
    uint32_t usage)
{
    *(int*)1 = 1;
    return { nullptr, nullptr };
}

bool gpu::D3DImageBackingFactory::IsSwapChainSupported(void)
{
    *(int*)1 = 1;
    return false;
}
#endif

void gpu::ContextUrl::SetActiveUrl(class gpu::ContextUrl const&)
{
    *(int*)1 = 1;
}

bool gfx::PNGCodec::Encode(
    const unsigned char* input, 
    gfx::PNGCodec::ColorFormat format, 
    const Size& size, 
    int row_byte_width, 
    bool discard_transparency, 
    const std::vector<gfx::PNGCodec::Comment>& comments,
    std::vector<unsigned char>* output)
{
    *(int*)1 = 1;
    return false;
}

#ifdef OS_WIN
bool gpu::D3DImageBackingFactory::IsD3DSharedImageSupported(gpu::GpuPreferences const&)
{
    OutputDebugStringA("gpu::D3DImageBackingFactory::IsD3DSharedImageSupported not impl\n");
    return false;
}
#endif

gpu::mojom::internal::GpuPreferences_Data::GpuPreferences_Data(void)
{
    *(int*)1 = 1;
}

gfx::mojom::internal::BufferUsageAndFormat_Data::BufferUsageAndFormat_Data(void)
{
    *(int*)1 = 1;
}

bool gpu::mojom::GpuPreferences::Validate(void const*, mojo::internal::ValidationContext*)
{
    *(int*)1 = 1;
    return false;
}

int viz::BitsPerPixel(class viz::SharedImageFormat)
{
    *(int*)1 = 1;
    return 0;
}

gfx::BufferFormat viz::BufferFormat(viz::SharedImageFormat)
{
    *(int*)1 = 1;
    return gfx::BufferFormat::RGBA_1010102;
}

unsigned int viz::GLInternalFormat(viz::SharedImageFormat)
{
    *(int*)1 = 1;
    return 0;
}

bool viz::IsResourceFormatCompressed(viz::SharedImageFormat)
{
    *(int*)1 = 1;
    return false;
}

void angle::ResetPlatform(void*)
{
    *(int*)1 = 1;
}

// ui/gl/angle_platform_impl.cc
bool angle::InitializePlatform(void*)
{
    OutputDebugStringA("angle::InitializePlatform not impl\n");
    return false;
}

// int angle::GetANGLECommitHashSize(void)
// {
//     *(int*)1 = 1;
//     return 0;
// }
// 
// char const* angle::GetANGLECommitHash(void)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }

// ShBuiltInResources::ShBuiltInResources(void)
// {
//     *(int*)1 = 1;
// }
// 
// ShCompileOptions::ShCompileOptions(void)
// {
//     *(int*)1 = 1;
// }
//
// ShBuiltInResources& ShBuiltInResources::operator=(ShBuiltInResources const& self)
// {
//     *(int*)1 = 1;
//     return (ShBuiltInResources&)self;
// }
// 
// ShCompileOptions& ShCompileOptions::operator=(ShCompileOptions const& self)
// {
//     *(int*)1 = 1;
//     return (ShCompileOptions&)self;
// }
//
// void sh::Destruct(void*)
// {
//     *(int*)1 = 1;
// }
// 
// void sh::ClearResults(void* const)
// {
//     *(int*)1 = 1;
// }
// 
// void sh::InitBuiltInResources(ShBuiltInResources*)
// {
//     *(int*)1 = 1;
// }
// 
// void* sh::ConstructCompiler(unsigned int, ShShaderSpec, ShShaderOutput, ShBuiltInResources const*)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
// 
// sh::InterfaceBlock::InterfaceBlock(void)
// {
//     *(int*)1 = 1;
// }
// 
// sh::InterfaceBlock::~InterfaceBlock(void)
// {
//     *(int*)1 = 1;
// }
// 
// sh::ShaderVariable::ShaderVariable(struct sh::ShaderVariable const&)
// {
//     *(int*)1 = 1;
// }
// 
// sh::ShaderVariable::ShaderVariable(void)
// {
//     *(int*)1 = 1;
// }
// 
// sh::ShaderVariable::~ShaderVariable(void)
// {
//     *(int*)1 = 1;
// }
// 
// sh::InterfaceBlock& sh::InterfaceBlock::operator=(const sh::InterfaceBlock& a)
// {
//     *(int*)1 = 1;
//     return (sh::InterfaceBlock&)a;
// }
// 
// sh::ShaderVariable& sh::ShaderVariable::operator=(const sh::ShaderVariable& a)
// {
//     *(int*)1 = 1;
//     return (sh::ShaderVariable&)a;
// }
// 
// bool sh::ShaderVariable::isSameVaryingAtLinkTime(sh::ShaderVariable const&, int) const
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// int sh::GetShaderVersion(void* const)
// {
//     *(int*)1 = 1;
//     return 0;
// }
// 
// const std::string& sh::GetBuiltInResourcesString(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return std::string();
// }
// 
// const std::string& sh::GetInfoLog(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return std::string();
// }
// 
// const std::string& sh::GetObjectCode(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return std::string();
// }
// 
// 
// const std::vector<sh::InterfaceBlock>* sh::GetInterfaceBlocks(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
// const std::vector<sh::ShaderVariable>* sh::GetAttributes(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
// const std::vector<sh::ShaderVariable>* sh::GetOutputVariables(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
// const std::vector<sh::ShaderVariable>* sh::GetUniforms(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
// 
// const std::vector<sh::ShaderVariable>* sh::GetVaryings(const ShHandle handle)
// {
//     *(int*)1 = 1;
//     return nullptr;
// }
// 
// bool sh::Initialize(void)
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// bool sh::CheckVariablesWithinPackingLimits(int maxVectors, const std::vector<sh::ShaderVariable>& variables)
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// bool sh::Compile(const ShHandle handle,
//     const char* const shaderStrings[],
//     size_t numStrings,
//     const ShCompileOptions& compileOptions)
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// bool sh::Finalize(void)
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// bool sh::ShaderVariable::findInfoByMappedName(
//     const std::string& mappedFullName,
//     const ShaderVariable** leafVar,
//     std::string* originalFullName) const
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// bool sh::ShaderVariable::isSameUniformAtLinkTime(sh::ShaderVariable const&) const
// {
//     *(int*)1 = 1;
//     return false;
// }
// 
// bool sh::InterfaceBlock::isSameInterfaceBlockAtLinkTime(sh::InterfaceBlock const&) const
// {
//     *(int*)1 = 1;
//     return false;
// }



