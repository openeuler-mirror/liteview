// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_RENDERER_WEBGRAPHICSCONTEXT3D_PROVIDER_IMPL_H_
#define CONTENT_RENDERER_WEBGRAPHICSCONTEXT3D_PROVIDER_IMPL_H_

#include "base/containers/flat_map.h"
#include "base/memory/ref_counted.h"
#include "components/viz/common/gpu/context_provider.h"
#include "gpu/command_buffer/client/gles2_interface.h"
#include "gpu/command_buffer/client/raster_interface.h"
//#include "gpu/command_buffer/client/webgpu_interface.h"
#include "gpu/command_buffer/client/gles2_implementation.h"
#include "third_party/blink/public/platform/web_graphics_context_3d_provider.h"

namespace cc {
class ImageDecodeCache;
}  // namespace cc

namespace viz {
class ContextProviderCommandBuffer;
}  // namespace viz

namespace gpu {
class ContextSupport;
class GLHelper;
class GLInProcessContext;
class InProcessGpuThreadHolder;
}  // namespace gpu

namespace content {

class WebGraphicsContext3DProviderImpl
    : public blink::WebGraphicsContext3DProvider
    , public viz::ContextLostObserver {
 public:
  WebGraphicsContext3DProviderImpl(/*scoped_refptr<viz::ContextProviderCommandBuffer> provider*/);

  WebGraphicsContext3DProviderImpl(const WebGraphicsContext3DProviderImpl&) =
      delete;
  WebGraphicsContext3DProviderImpl& operator=(const WebGraphicsContext3DProviderImpl&) = delete;

  ~WebGraphicsContext3DProviderImpl() override;

  // WebGraphicsContext3DProvider implementation.
  gpu::InterfaceBase* InterfaceBase() override;
  bool BindToCurrentThread() override;
  gpu::gles2::GLES2Interface* ContextGL() override;
  gpu::raster::RasterInterface* RasterInterface() override;
  gpu::webgpu::WebGPUInterface* WebGPUInterface() override;
  bool IsContextLost() override;
  GrDirectContext* GetGrContext() override;
  const gpu::Capabilities& GetCapabilities() const override;
  const gpu::GpuFeatureInfo& GetGpuFeatureInfo() const override;
  const blink::WebglPreferences& GetWebglPreferences() const override;
  gpu::GLHelper* GetGLHelper() override;
  void SetLostContextCallback(base::RepeatingClosure) override;
  void SetErrorMessageCallback(base::RepeatingCallback<void(const char*, int32_t)>) override;
  cc::ImageDecodeCache* ImageDecodeCache(SkColorType color_type) override;
  gpu::SharedImageInterface* SharedImageInterface() override;
  void CopyVideoFrame(media::PaintCanvasVideoRenderer* video_render,
                      media::VideoFrame* video_frame,
                      cc::PaintCanvas* canvas) override;
  viz::RasterContextProvider* RasterContextProvider() const override;

 private:
  // viz::ContextLostObserver implementation.
  void OnContextLost() override;

  std::unique_ptr <gpu::InProcessGpuThreadHolder> gpu_thread_holder_;
  // The context we use for OpenGL rendering.
  std::unique_ptr<::gpu::GLInProcessContext> context_;
  // The GLES2Implementation we use for OpenGL rendering.
  ::gpu::gles2::GLES2Implementation* real_gl_ = nullptr;
  //::gpu::gles2::GLES2Interface* gl_ = nullptr;

//   scoped_refptr<viz::ContextProviderCommandBuffer> provider_;
//   std::unique_ptr<gpu::GLHelper> gl_helper_;
  base::RepeatingClosure context_lost_callback_;
  //base::flat_map<SkColorType, std::unique_ptr<cc::ImageDecodeCache>> image_decode_cache_map_;
};

}  // namespace content

#endif  // CONTENT_RENDERER_WEBGRAPHICSCONTEXT3D_PROVIDER_IMPL_H_
