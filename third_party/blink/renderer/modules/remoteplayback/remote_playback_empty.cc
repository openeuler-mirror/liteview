// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/modules/remoteplayback/remote_playback.h"
#include "third_party/blink/renderer/modules/remoteplayback/remote_playback_metrics.h"
#include "third_party/blink/renderer/modules/remoteplayback/availability_callback_wrapper.h"
#include "services/device/public/mojom/screen_orientation_lock_types.mojom-shared.h"
#include "third_party/blink/renderer/modules/event_target_modules_names.h"
#include <memory>
#include <utility>

namespace blink {

RemotePlayback::RemotePlayback(HTMLMediaElement& element)
    : ExecutionContextLifecycleObserver(element.GetExecutionContext())
    , RemotePlaybackController(element)
    , state_(mojom::blink::PresentationConnectionState::CLOSED)
    , availability_(mojom::ScreenAvailability::UNKNOWN)
    , media_element_(&element)
    , is_listening_(false)
    , presentation_connection_receiver_(this, element.GetExecutionContext())
    , target_presentation_connection_(element.GetExecutionContext())
{

}

RemotePlayback& __cdecl RemotePlayback::From(HTMLMediaElement& element)
{
    RemotePlayback* self = MakeGarbageCollected<RemotePlayback>(element);
    return *self;
}

bool RemotePlayback::RemotePlaybackAvailable(void)const
{
    return false;
}

void RemotePlayback::PromptInternal(void)
{
}

void RemotePlaybackMetrics::RecordRemotePlaybackLocation(RemotePlaybackInitiationLocation) 
{
}

AvailabilityCallbackWrapper::AvailabilityCallbackWrapper(base::RepeatingCallback<void __cdecl(void)>)
{
}

void AvailabilityCallbackWrapper::Trace(cppgc::Visitor*) const
{
    *(int*)1 = 1;
}

int RemotePlayback::WatchAvailabilityInternal(AvailabilityCallbackWrapper*)
{
    return 0;
}

bool RemotePlayback::CancelWatchAvailabilityInternal(int)
{
    return false;
}

const AtomicString& RemotePlayback::InterfaceName() const
{
    return event_target_names::kRemotePlayback;
}

ExecutionContext* RemotePlayback::GetExecutionContext() const
{
    return ExecutionContextLifecycleObserver::GetExecutionContext();
}

void RemotePlayback::AvailabilityChanged(mojom::blink::ScreenAvailability availability)
{
}

const Vector<KURL>& RemotePlayback::Urls() const
{
    // TODO(avayvod): update the URL format and add frame url, mime type and
    // response headers when available.
    return availability_urls_;
}

void RemotePlayback::OnMessage(mojom::blink::PresentationConnectionMessagePtr message)
{
    // Messages are ignored.
}

void RemotePlayback::DidChangeState(mojom::blink::PresentationConnectionState state)
{

}

void RemotePlayback::DidClose(mojom::blink::PresentationConnectionCloseReason reason)
{

}

void RemotePlayback::SourceChanged(const WebURL& source, bool is_source_supported)
{

}

WebString RemotePlayback::GetPresentationId()
{
    return presentation_id_;
}

void RemotePlayback::AddObserver(RemotePlaybackObserver* observer)
{
    //observers_.insert(observer);
}

void RemotePlayback::RemoveObserver(RemotePlaybackObserver* observer)
{
    //observers_.erase(observer);
}

void RemotePlayback::AvailabilityChangedForTesting(bool screen_is_available)
{
}

void RemotePlayback::StateChangedForTesting(bool is_connected)
{
}

bool RemotePlayback::HasPendingActivity() const
{
    return false;
}

void RemotePlayback::Trace(Visitor* visitor) const
{

}

const WrapperTypeInfo& RemotePlayback::wrapper_type_info_ = { 
    gin::kEmbedderNativeGin,
    nullptr,    //bindings::V8InterfaceBridgeBase::InstallInterfaceTemplateFuncType install_interface_template_func;
    nullptr,//bindings::V8InterfaceBridgeBase::InstallContextDependentPropertiesFuncType install_context_dependent_props_func;
    nullptr,//const char* interface_name;
    nullptr,//const WrapperTypeInfo* parent_class;
    0, //unsigned wrapper_type_prototype : 2; // WrapperTypePrototype
    0, //unsigned wrapper_class_id : 2; // WrapperClassId
    0, //unsigned // ActiveScriptWrappableInheritance
    //    active_script_wrappable_inheritance : 1;
    0, //unsigned idl_definition_kind : 3; // IdlDefinitionKind
};

}

std::basic_ostream<char, struct std::char_traits<char> >& device::mojom::operator << (
    std::basic_ostream<char, std::char_traits<char> >& oa, 
    device::mojom::ScreenOrientationLockType)
{
    *(int*)1 = 1;
    return oa;
}