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

// asdasd

// class BLINK_COMMON_EXPORT LocalFrameHostProxy
//     : public LocalFrameHost {
//  public:
//   using InterfaceType = LocalFrameHost;
//
//   explicit LocalFrameHostProxy(mojo::MessageReceiverWithResponder* receiver);
//
//   void EnterFullscreen(::blink::mojom::FullscreenOptionsPtr options, EnterFullscreenCallback callback) final;
//
//   void ExitFullscreen() final;
//   bool CreatePortal(::mojo::PendingAssociatedReceiver<::blink::mojom::Portal> portal, ::mojo::PendingAssociatedRemote<::blink::mojom::PortalClient> client,
//   ::blink::mojom::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, ::blink::mojom::FrameReplicationStatePtr* out_initial_replicated_state, ::blink::PortalToken*
//   out_portal_token, ::blink::RemoteFrameToken* out_frame_token, ::base::UnguessableToken* out_devtools_frame_token) final;
//
//   void CreatePortal(::mojo::PendingAssociatedReceiver<::blink::mojom::Portal> portal, ::mojo::PendingAssociatedRemote<::blink::mojom::PortalClient> client,
//   ::blink::mojom::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, CreatePortalCallback callback) final;
//
//   bool AdoptPortal(const ::blink::PortalToken& portal_token, ::blink::mojom::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces,
//   ::blink::mojom::FrameReplicationStatePtr* out_replicated_state, ::blink::RemoteFrameToken* out_frame_token, ::base::UnguessableToken* out_devtools_frame_token) final;
//
//   void AdoptPortal(const ::blink::PortalToken& portal_token, ::blink::mojom::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, AdoptPortalCallback callback) final;
//
//   void CreateFencedFrame(::mojo::PendingAssociatedReceiver<::blink::mojom::FencedFrameOwnerHost> fenced_frame, ::blink::mojom::FencedFrameMode mode,
//   ::blink::mojom::RemoteFrameInterfacesFromRendererPtr remote_frame_interfaces, const ::blink::RemoteFrameToken& frame_token, const ::base::UnguessableToken&
//   devtools_frame_token) final;
//
//  private:
//   mojo::MessageReceiverWithResponder* receiver_;
// };

// class BLINK_COMMON_EXPORT LocalFrameProxy
//     : public LocalFrame {
//  public:
//   using InterfaceType = LocalFrame;
//
//   explicit LocalFrameProxy(mojo::MessageReceiverWithResponder* receiver);
//
//   void GetTextSurroundingSelection(uint32_t max_length, GetTextSurroundingSelectionCallback callback) final;
//
//   void SendInterventionReport(const std::string& id, const std::string& message) final;
//
//   void SetFrameOwnerProperties(::blink::mojom::FrameOwnerPropertiesPtr properties) final;
//
//   void NotifyUserActivation(::blink::mojom::UserActivationNotificationType notification_type) final;
//
//   void NotifyVirtualKeyboardOverlayRect(const ::gfx::Rect& keyboard_rect) final;
//
//   void AddMessageToConsole(::blink::mojom::ConsoleMessageLevel level, const std::string& message, bool discard_duplicates) final;
//
//   void AddInspectorIssue(::blink::mojom::InspectorIssueInfoPtr info) final;
//
//   void SwapInImmediately() final;
//
//   void CheckCompleted() final;
//
//   void StopLoading() final;
//
//   void Collapse(bool collapsed) final;
//
//   void EnableViewSourceMode() final;
//
//   void Focus() final;
//
//   void ClearFocusedElement() final;
//
//   //void GetResourceSnapshotForWebBundle(::mojo::PendingReceiver<::data_decoder::mojom::ResourceSnapshotForWebBundle> receiver) final;
//
//   void CopyImageAt(const ::gfx::Point& window_point) final;
//
//   void SaveImageAt(const ::gfx::Point& window_point) final;
//
//   void ReportBlinkFeatureUsage(const std::vector<::blink::mojom::WebFeature>& features) final;
//
//   void RenderFallbackContent() final;
//
//   void RenderFallbackContentWithResourceTiming(::blink::mojom::ResourceTimingInfoPtr timing, const std::string& server_timing_value) final;
//
//   void BeforeUnload(bool is_reload, BeforeUnloadCallback callback) final;
//
//   void MediaPlayerActionAt(const ::gfx::Point& location, ::blink::mojom::MediaPlayerActionPtr action) final;
//
//   void PluginActionAt(const ::gfx::Point& location, PluginActionType action) final;
//
//   void AdvanceFocusInFrame(::blink::mojom::FocusType focus_type, const absl::optional<::blink::RemoteFrameToken>& source_frame_token) final;
//
//   void AdvanceFocusForIME(::blink::mojom::FocusType focus_type) final;
//
//   void ReportContentSecurityPolicyViolation(::network::mojom::CSPViolationPtr violation) final;
//
//   void DidUpdateFramePolicy(const ::blink::FramePolicy& frame_policy) final;
//
//   void PostMessageEvent(const absl::optional<::blink::RemoteFrameToken>& source_frame_token, const ::std::u16string& source_origin, const ::std::u16string& target_origin,
//   ::blink::TransferableMessage message) final;
//
//   void JavaScriptMethodExecuteRequest(const ::std::u16string& object_name, const ::std::u16string& method_name, ::base::Value::List arguments, bool wants_result,
//   JavaScriptMethodExecuteRequestCallback callback) final;
//
//   void JavaScriptExecuteRequest(const ::std::u16string& javascript, bool wants_result, JavaScriptExecuteRequestCallback callback) final;
//
//   void JavaScriptExecuteRequestForTests(const ::std::u16string& javascript, bool has_user_gesture, bool resolve_promises, int32_t world_id,
//   JavaScriptExecuteRequestForTestsCallback callback) final;
//
//   void JavaScriptExecuteRequestInIsolatedWorld(const ::std::u16string& javascript, bool wants_result, int32_t world_id, JavaScriptExecuteRequestInIsolatedWorldCallback callback)
//   final;
//
//   void BindReportingObserver(::mojo::PendingReceiver<::blink::mojom::ReportingObserver> receiver) final;
//
//   void UpdateOpener(const absl::optional<::blink::FrameToken>& opener_frame_token) final;
//
//   void GetSavableResourceLinks(GetSavableResourceLinksCallback callback) final;
//
//   void MixedContentFound(const ::GURL& main_resource_url, const ::GURL& mixed_content_url, ::blink::mojom::RequestContextType request_context, bool was_allowed, const ::GURL&
//   url_before_redirects, bool had_redirect, ::network::mojom::SourceLocationPtr source_location) final;
//
//   void BindDevToolsAgent(::mojo::PendingAssociatedRemote<::blink::mojom::DevToolsAgentHost> agent_host, ::mojo::PendingAssociatedReceiver<::blink::mojom::DevToolsAgent> agent)
//   final;
//
//   void HandleRendererDebugURL(const ::GURL& url) final;
//
//   void GetCanonicalUrlForSharing(GetCanonicalUrlForSharingCallback callback) final;
//
//   void GetOpenGraphMetadata(GetOpenGraphMetadataCallback callback) final;
//
//   void SetNavigationApiHistoryEntriesForRestore(::blink::mojom::NavigationApiHistoryEntryArraysPtr entry_arrays) final;
//
//   void NotifyNavigationApiOfDisposedEntries(const std::vector<std::string>& keys) final;
//
//   void TraverseCancelled(const std::string& navigation_api_key, TraverseCancelledReason reason) final;
//
//  private:
//   mojo::MessageReceiverWithResponder* receiver_;
// };

// class BLINK_COMMON_EXPORT HighPriorityLocalFrameProxy
//     : public HighPriorityLocalFrame {
//  public:
//   using InterfaceType = HighPriorityLocalFrame;
//
//   explicit HighPriorityLocalFrameProxy(mojo::MessageReceiverWithResponder* receiver);
//
//   void DispatchBeforeUnload(bool is_reload, DispatchBeforeUnloadCallback callback) final;
//
//  private:
//   mojo::MessageReceiverWithResponder* receiver_;
// };
