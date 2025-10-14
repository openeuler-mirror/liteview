/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2001 Dirk Mueller (mueller@kde.org)
 *           (C) 2006 Alexey Proskuryakov (ap@webkit.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2012 Apple Inc. All
 * rights reserved.
 * Copyright (C) 2008, 2009 Torch Mobile Inc. All rights reserved.
 * (http://www.torchmobile.com/)
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies)
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_DOM_DOCUMENT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_DOM_DOCUMENT_H_

#include <memory>

#include "base/check_op.h"
#include "base/dcheck_is_on.h"
#include "base/gtest_prod_util.h"
#include "base/memory/scoped_refptr.h"
#include "base/time/time.h"
#include "base/timer/elapsed_timer.h"
#include "services/metrics/public/cpp/ukm_source_id.h"
#include "services/network/public/mojom/referrer_policy.mojom-blink-forward.h"
//"E:\mycode\mb108\gen\services\network\public\mojom\referrer_policy.mojom-shared.h"
#include "services/network/public/mojom/restricted_cookie_manager.mojom-blink-forward.h"
#include "services/network/public/mojom/web_sandbox_flags.mojom-blink-forward.h"
#include "third_party/abseil-cpp/absl/types/optional.h"
#include "third_party/blink/public/common/metrics/document_update_reason.h"
#include "third_party/blink/public/common/tokens/tokens.h"
#include "third_party/blink/public/mojom/css/preferred_color_scheme.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/frame/color_scheme.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/input/focus_type.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/page/page.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/permissions/permission.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/permissions_policy/document_policy_feature.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/scroll/scrollbar_mode.mojom-blink-forward.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_typedefs.h"
#include "third_party/blink/renderer/core/accessibility/axid.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/css/media_value_change.h"
#include "third_party/blink/renderer/core/dom/container_node.h"
#include "third_party/blink/renderer/core/dom/create_element_flags.h"
#include "third_party/blink/renderer/core/dom/document_encoding_data.h"
#include "third_party/blink/renderer/core/dom/document_lifecycle.h"
#include "third_party/blink/renderer/core/dom/document_timing.h"
#include "third_party/blink/renderer/core/dom/element.h"
#include "third_party/blink/renderer/core/dom/events/event_path.h"
#include "third_party/blink/renderer/core/dom/live_node_list_registry.h"
#include "third_party/blink/renderer/core/dom/qualified_name.h"
#include "third_party/blink/renderer/core/dom/synchronous_mutation_observer.h"
#include "third_party/blink/renderer/core/dom/text_link_colors.h"
#include "third_party/blink/renderer/core/dom/tree_scope.h"
#include "third_party/blink/renderer/core/dom/user_action_element_set.h"
#include "third_party/blink/renderer/core/editing/forward.h"
#include "third_party/blink/renderer/core/html/forms/listed_element.h"
#include "third_party/blink/renderer/core/html/parser/parser_synchronization_policy.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_hash_map.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_hash_set.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_linked_hash_set.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_vector.h"
#include "third_party/blink/renderer/platform/heap_observer_set.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
#include "third_party/blink/renderer/platform/scheduler/public/post_cancellable_task.h"
#include "third_party/blink/renderer/platform/supplementable.h"
#include "third_party/blink/renderer/platform/timer.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/casting.h"
#include "third_party/blink/renderer/platform/wtf/gc_plugin_ignore.h"
#include "third_party/blink/renderer/platform/wtf/hash_set.h"
#include "third_party/perfetto/include/perfetto/tracing/traced_value_forward.h"

namespace base {
class SingleThreadTaskRunner;
}

namespace cc {
class AnimationTimeline;
}

namespace gfx {
class QuadF;
class RectF;
} // namespace gfx

namespace mojo {
template <typename Interface> class PendingRemote;
} // namespace mojo

namespace ukm {
class UkmRecorder;
} // namespace ukm

namespace net {
class SiteForCookies;
} // namespace net

namespace network {
namespace mojom {
enum class CSPDisposition : int32_t;
} // namespace mojom
} // namespace network

namespace blink {

class Agent;
class AnchorElementInteractionTracker;
class AnimationClock;
class AXContext;
class AXObjectCache;
class Attr;
class BeforeUnloadEventListener;
class CDATASection;
class CSSStyleSheet;
class CanvasFontCache;
class ChromeClient;
class Comment;
class ComputedAccessibleNode;
class DOMWrapperWorld;
class DisplayLockDocumentState;
class DocumentData;
class ElementIntersectionObserverData;
class ComputedStyle;
class ConsoleMessage;
class ContextFeatures;
class CookieJar;
class DOMImplementation;
class DOMWindow;
class DocumentAnimations;
class DocumentFragment;
class DocumentInit;
class DocumentLoader;
class DocumentMarkerController;
class DocumentNameCollection;
class DocumentParser;
class DocumentResourceCoordinator;
class DocumentState;
class DocumentTimeline;
class DocumentType;
class DOMFeaturePolicy;
class Element;
class ElementDataCache;
class ElementRegistrationOptions;
class Event;
class EventFactoryBase;
class EventListener;
template <typename EventType> class EventWithHitTestResults;
class ExceptionState;
class FontMatchingMetrics;
class FocusedElementChangeObserver;
class FormController;
class FragmentDirective;
class FrameCallback;
class FrameScheduler;
class HTMLAllCollection;
class HTMLBodyElement;
class HTMLCollection;
class HTMLDialogElement;
class HTMLElement;
class HTMLFrameOwnerElement;
class HTMLHeadElement;
class HTMLLinkElement;
class HTMLMetaElement;
class CheckPseudoHasCacheScope;
class HitTestRequest;
class HttpRefreshScheduler;
class IdleRequestOptions;
class IdleTask;
class IntersectionObserverController;
class LayoutUpgrade;
class LayoutView;
class LazyLoadImageObserver;
class LiveNodeListBase;
class ListedElement;
class LocalDOMWindow;
class LocalFrame;
class LocalFrameView;
class Locale;
class Location;
class MediaQueryListListener;
class MediaQueryMatcher;
class NodeIterator;
class NthIndexCache;
class Page;
class PendingAnimations;
class PendingLinkPreload;
class ProcessingInstruction;
class PropertyRegistry;
class QualifiedName;
class Range;
class RenderBlockingResourceManager;
class ResizeObserver;
class ResourceFetcher;
class ResourceResponse;
class RootScrollerController;
class SVGDocumentExtensions;
class SVGUseElement;
class ScriptElementBase;
class ScriptPromise;
class ScriptRegexp;
class ScriptRunner;
class ScriptRunnerDelayer;
class ScriptValue;
class ScriptableDocumentParser;
class ScriptedAnimationController;
class ScriptedIdleTaskController;
class SecurityOrigin;
class SelectorQueryCache;
class SerializedScriptValue;
class Settings;
class SlotAssignmentEngine;
class SnapCoordinator;
class StyleEngine;
class StylePropertyMapReadOnly;
class StyleResolver;
class StyleSheetList;
class Text;
class TextAutosizer;
class TransformSource;
class TreeWalker;
class TrustedHTML;
class V8NodeFilter;
class V8ObservableArrayCSSStyleSheet;
class V8UnionElementCreationOptionsOrString;
class V8UnionStringOrTrustedHTML;
class ViewportData;
class VisitedLinkState;
class WebMouseEvent;
class WorkletAnimationController;
enum class CSSPropertyID;
struct AnnotatedRegionValue;
struct FocusParams;
struct IconURL;
struct PhysicalOffset;
struct WebPrintPageDescription;

using MouseEventWithHitTestResults = EventWithHitTestResults<WebMouseEvent>;

enum NodeListInvalidationType : int {
    kDoNotInvalidateOnAttributeChanges = 0,
    kInvalidateOnClassAttrChange,
    kInvalidateOnIdNameAttrChange,
    kInvalidateOnNameAttrChange,
    kInvalidateOnForAttrChange,
    kInvalidateForFormControls,
    kInvalidateOnHRefAttrChange,
    kInvalidateOnAnyAttrChange,
};
const int kNumNodeListInvalidationTypes = kInvalidateOnAnyAttrChange + 1;

enum DocumentClass {
    kDefaultDocumentClass = 0,
    kHTMLDocumentClass = 1,
    kXHTMLDocumentClass = 1 << 1,
    kImageDocumentClass = 1 << 2,
    kPluginDocumentClass = 1 << 3,
    kMediaDocumentClass = 1 << 4,
    kSVGDocumentClass = 1 << 5,
    kXMLDocumentClass = 1 << 6,
};

using DocumentClassFlags = unsigned char;

// A map of IDL attribute name to Element list value, for one particular
// element. For example,
//   el1.ariaActiveDescendant = el2
// would add the following pair to the ExplicitlySetAttrElementMap for el1:
//   ("ariaActiveDescendant", el2)
// This represents 'explicitly set attr-element' in the HTML specification.
// https://whatpr.org/html/3917/common-dom-interfaces.html#reflecting-content-attributes-in-idl-attributes:element-2
// Note that in the interest of simplicitly, attributes that reflect a single
// element reference are implemented using the same ExplicitlySetAttrElementsMap
// storage, but only store a single element vector which is DCHECKED at the
// calling site.
using ExplicitlySetAttrElementsMap = HeapHashMap<QualifiedName, Member<HeapLinkedHashSet<WeakMember<Element>>>>;

// Represents the start and end time of the unload event.
struct UnloadEventTiming {
    bool can_request;
    base::TimeTicks unload_event_start;
    base::TimeTicks unload_event_end;
};

// Used to gather the unload event timing of an unloading document, to be used
// in a new document (if it's same-origin).
struct UnloadEventTimingInfo {
    explicit UnloadEventTimingInfo(scoped_refptr<SecurityOrigin> new_document_origin);
    // The origin of the new document that replaces the older document.
    const scoped_refptr<SecurityOrigin> new_document_origin;
    // The unload timing of the old document. This is only set from
    // Document::DispatchUnloadEvents() of the old document. This might not be set
    // if no old document gets unloaded.
    absl::optional<UnloadEventTiming> unload_timing;
};

// A document (https://dom.spec.whatwg.org/#concept-document) is the root node
// of a tree of DOM nodes, generally resulting from the parsing of a markup
// (typically, HTML) resource.
//
// A document may or may not have a browsing context
// (https://html.spec.whatwg.org/#browsing-context). A document with a browsing
// context is created by navigation, and has a non-null domWindow(), GetFrame(),
// Loader(), etc., and is visible to the user. It will have a valid
// GetExecutionContext(), which will be equal to domWindow(). If the Document
// constructor receives a DocumentInit created WithDocumentLoader(), it will
// have a browsing context.
// Documents created by all other APIs do not have a browsing context. These
// Documents still have a valid GetExecutionContext() (i.e., the domWindow() of
// the Document in which they were created), so they can still access
// script, but return null for domWindow(), GetFrame() and Loader(). Generally,
// they should not downcast the ExecutionContext to a LocalDOMWindow and access
// the properties of the window directly.
// Finally, unit tests are allowed to create a Document that does not even
// have a valid GetExecutionContext(). This is a lightweight way to test
// properties of the Document and the DOM that do not require script.
class CORE_EXPORT Document : public ContainerNode, public TreeScope, public UseCounter, public Supplementable<Document> {
    DEFINE_WRAPPERTYPEINFO();

public:
    // Factory for web-exposed Document constructor. The argument document must be
    // a document instance representing window.document, and it works as the
    // source of ExecutionContext and security origin of the new document.
    // https://dom.spec.whatwg.org/#dom-document-document
    static Document* Create(Document&);

    explicit Document(const DocumentInit& init, DocumentClassFlags flags = kDefaultDocumentClass);
    ~Document() override;

    // Constructs a Document instance without a subclass for testing.
    static Document* CreateForTest(ExecutionContext* execution_context = nullptr);

    static Range* CreateRangeAdjustedToTreeScope(const TreeScope&, const Position&);

    // Support JS introspection of frame policy (e.g. permissions policy).
    DOMFeaturePolicy* featurePolicy();

    MediaQueryMatcher& GetMediaQueryMatcher();

    void MediaQueryAffectingValueChanged(MediaValueChange change);

    // SetMediaFeatureEvaluated and WasMediaFeatureEvaluated are used to prevent
    // UKM sampling of CSS media features more than once per document.
    void SetMediaFeatureEvaluated(int feature);
    bool WasMediaFeatureEvaluated(int feature);

    using TreeScope::getElementById;

    bool IsInitialEmptyDocument() const;
    // Sometimes we permit an initial empty document to cease to be the initial
    // empty document. This is needed for cross-process navigations, where a new
    // LocalFrame needs to be created but the conceptual frame might have had
    // other Documents in a different process. document.open() also causes the
    // document to cease to be the initial empty document.
    void OverrideIsInitialEmptyDocument();

    bool IsPrerendering() const;

    void SetIsTrackingSoftNavigationHeuristics(bool value);

    bool IsTrackingSoftNavigationHeuristics() const;

    network::mojom::ReferrerPolicy GetReferrerPolicy() const;

    bool DocumentPolicyFeatureObserved(mojom::blink::DocumentPolicyFeature feature);

    bool CanContainRangeEndPoint() const override
    {
        return true;
    }

    SelectorQueryCache& GetSelectorQueryCache();

    // Focus Management.
    Element* ActiveElement() const;
    bool hasFocus() const;

    // DOM methods & attributes for Document

    DEFINE_ATTRIBUTE_EVENT_LISTENER(beforecopy, kBeforecopy)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(beforecut, kBeforecut)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(beforepaste, kBeforepaste)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(freeze, kFreeze)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(pointerlockchange, kPointerlockchange)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(pointerlockerror, kPointerlockerror)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(readystatechange, kReadystatechange)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(resume, kResume)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(search, kSearch)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(securitypolicyviolation, kSecuritypolicyviolation)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(visibilitychange, kVisibilitychange)
    DEFINE_ATTRIBUTE_EVENT_LISTENER(prerenderingchange, kPrerenderingchange)

    ViewportData& GetViewportData() const;

    void SetDoctype(DocumentType*);
    DocumentType* doctype() const;

    DOMImplementation& implementation();

    Element* documentElement() const;

    Location* location() const;

    Element* CreateElementForBinding(const AtomicString& local_name, ExceptionState& = ASSERT_NO_EXCEPTION);
    Element* CreateElementForBinding(
        const AtomicString& local_name, const V8UnionElementCreationOptionsOrString* string_or_options, ExceptionState& exception_state);
    Element* createElementNS(const AtomicString& namespace_uri, const AtomicString& qualified_name, ExceptionState&);
    Element* createElementNS(const AtomicString& namespace_uri, const AtomicString& qualified_name,
        const V8UnionElementCreationOptionsOrString* string_or_options, ExceptionState& exception_state);
    DocumentFragment* createDocumentFragment();
    Text* createTextNode(const String& data);
    Comment* createComment(const String& data);
    CDATASection* createCDATASection(const String& data, ExceptionState&);
    ProcessingInstruction* createProcessingInstruction(const String& target, const String& data, ExceptionState&);
    Attr* createAttribute(const AtomicString& name, ExceptionState&);
    Attr* createAttributeNS(const AtomicString& namespace_uri, const AtomicString& qualified_name, ExceptionState&);
    Node* importNode(Node* imported_node, bool deep, ExceptionState&);

    // "create an element" defined in DOM standard. This supports both of
    // autonomous custom elements and customized built-in elements.
    Element* CreateElement(const QualifiedName&, const CreateElementFlags, const AtomicString& is);
    // Creates an element without custom element processing.
    Element* CreateRawElement(const QualifiedName&, const CreateElementFlags = CreateElementFlags());

    Range* caretRangeFromPoint(int x, int y);
    Element* scrollingElement();

    // When calling from C++ code, use this method. scrollingElement() is
    // just for the web IDL implementation.
    //
    // Style/layout-tree needs to be updated before calling this function,
    // otherwise the returned element might be outdated. However, accessing
    // information based on the layout of the previous frame is occasionally
    // the correct behavior [1], hence it's not invalid to call this function
    // while style/layout dirty.
    //
    // [1] https://drafts.csswg.org/scroll-animations-1/#avoiding-cycles
    Element* ScrollingElementNoLayout();

    String readyState() const;

    AtomicString characterSet() const
    {
        return Document::EncodingName();
    }

    AtomicString EncodingName() const;

    void SetContent(const String&);

    String SuggestedMIMEType() const;
    void SetMimeType(const AtomicString&);
    AtomicString contentType() const; // DOM 4 document.contentType

    const AtomicString& ContentLanguage() const;
    void SetContentLanguage(const AtomicString&);

    String xmlEncoding() const;
    String xmlVersion() const;
    enum StandaloneStatus { kStandaloneUnspecified, kStandalone, kNotStandalone };
    bool xmlStandalone() const;
    StandaloneStatus XmlStandaloneStatus() const;
    bool HasXMLDeclaration() const;

    void SetXMLEncoding(const String& encoding);
    void setXMLVersion(const String&, ExceptionState&);
    void setXMLStandalone(bool, ExceptionState&);
    void SetHasXMLDeclaration(bool has_xml_declaration);

    AtomicString visibilityState() const;
    bool IsPageVisible() const;
    bool hidden() const;
    void DidChangeVisibilityState();

    bool prerendering() const;

    uint32_t softNavigations() const;

    bool wasDiscarded() const;
    void SetWasDiscarded(bool);

    // If the document is "prefetch only", it will not be fully contstructed,
    // and should never be displayed. Only a few resources will be loaded and
    // scanned, in order to warm up caches.
    bool IsPrefetchOnly() const;

    Node* adoptNode(Node* source, ExceptionState&);

    HTMLCollection* images();
    HTMLCollection* embeds();
    HTMLCollection* applets();
    HTMLCollection* links();
    HTMLCollection* forms();
    HTMLCollection* anchors();
    HTMLCollection* scripts();
    HTMLAllCollection* all();

    HTMLCollection* WindowNamedItems(const AtomicString& name);
    DocumentNameCollection* DocumentNamedItems(const AtomicString& name);
    HTMLCollection* DocumentAllNamedItems(const AtomicString& name);

    // The unassociated listed elements are listed elements that are not
    // associated to a <form> element.
    const ListedElement::List& UnassociatedListedElements() const;
    void MarkUnassociatedListedElementsDirty();

    // "defaultView" attribute defined in HTML spec.
    DOMWindow* defaultView() const;

    bool IsHTMLDocument() const;
    bool IsXHTMLDocument() const;
    bool IsXMLDocument() const;
    bool IsImageDocument() const;
    bool IsSVGDocument() const;
    bool IsPluginDocument() const;
    bool IsMediaDocument() const;

    bool HasSVGRootNode() const;

    bool IsFrameSet() const;

    bool IsSrcdocDocument() const;
    bool IsMobileDocument() const;

    StyleResolver& GetStyleResolver() const;

    bool IsViewSource() const;
    void SetIsViewSource(bool is_view_source);

    // WebXR DOM Overlay support, cf https://immersive-web.github.io/dom-overlays/
    // True if there's an ongoing "immersive-ar" WebXR session with a DOM Overlay
    // element active. This is needed for applying the :xr-overlay pseudoclass
    // and compositing/paint integration for this mode.
    bool IsXrOverlay() const;
    // Called from modules/xr's XRSystem when DOM Overlay mode starts and ends.
    // This lazy-loads the UA stylesheet and updates the overlay element's
    // pseudoclass.
    void SetIsXrOverlay(bool enabled, Element* overlay_element);

    bool SawElementsInKnownNamespaces() const;

    bool IsScriptExecutionReady() const
    {
        return HaveScriptBlockingStylesheetsLoaded();
    }

    bool IsForExternalHandler() const;

    // This is a DOM function.
    StyleSheetList& StyleSheets();

    StyleEngine& GetStyleEngine() const;

    mojom::blink::PreferredColorScheme GetPreferredColorScheme() const;

    void ScheduleUseShadowTreeUpdate(SVGUseElement&);
    void UnscheduleUseShadowTreeUpdate(SVGUseElement&);

    void EvaluateMediaQueryList();

    FormController& GetFormController();
    DocumentState* GetDocumentState() const;
    void SetStateForNewControls(const Vector<String>&);

    LocalFrameView* View() const; // can be null
    LocalFrame* GetFrame() const; // can be null
    Page* GetPage() const; // can be null
    Settings* GetSettings() const; // can be null

    float DevicePixelRatio() const;

    Range* createRange();

    NodeIterator* createNodeIterator(Node* root, unsigned what_to_show, V8NodeFilter*);
    TreeWalker* createTreeWalker(Node* root, unsigned what_to_show, V8NodeFilter*);

    // Special support for editing
    Text* CreateEditingTextNode(const String&);

    enum class StyleAndLayoutTreeUpdate {
        // Style/layout-tree is not dirty.
        kNone,

        // Style/layout-tree is dirty, and it's possible to understand whether a
        // given element will be affected or not by analyzing its ancestor chain.
        kAnalyzed,

        // Style/layout-tree is dirty, but we cannot decide which specific elements
        // need to have its style or layout tree updated.
        kFull,
    };

    // Looks at various sources that cause style/layout-tree dirtiness,
    // and returns the severity of the needed update.
    //
    // Note that this does not cover "implicit" style/layout-tree dirtiness
    // via layout/container-queries. That is: this function may return kNone,
    // and yet a subsequent layout may need to recalc container-query-dependent
    // styles.
    StyleAndLayoutTreeUpdate CalculateStyleAndLayoutTreeUpdate() const;

    bool NeedsLayoutTreeUpdate() const
    {
        return CalculateStyleAndLayoutTreeUpdate() != StyleAndLayoutTreeUpdate::kNone;
    }

    // Whether we need layout tree update for this node or not, without
    // considering nodes in display locked subtrees.
    bool NeedsLayoutTreeUpdateForNode(const Node&) const;
    // Whether we need layout tree update for this node or not, including nodes in
    // display locked subtrees.
    bool NeedsLayoutTreeUpdateForNodeIncludingDisplayLocked(const Node&) const;

    // Update ComputedStyles and attach LayoutObjects if necessary. This
    // recursively invokes itself for all ancestor LocalFrames, because style in
    // an ancestor frame can affect style in a child frame. This method is
    // appropriate for cases where we need to ensure that the style for a single
    // Document is up-to-date.
    //
    // A call to UpdateStyleAndLayoutTree may be upgraded [1] to also perform
    // layout. This is because updating the style and layout-tree may depend
    // on layout when container queries are used.
    //
    // Whether or not an upgrade should take place is decide by the
    // provided LayoutUpgrade object.
    //
    // [1] See blink::LayoutUpgrade
    void UpdateStyleAndLayoutTree();
    void UpdateStyleAndLayoutTree(LayoutUpgrade&);

    // Same as UpdateStyleAndLayoutTree, but does not recursively update style in
    // ancestor frames. This method is intended to be used in cases where we can
    // guarantee that ancestor frames already have clean style (e.g., from
    // LocalFrameView::UpdateLifecyclePhases, which is a top-down iteration over
    // the entire LocalFrame tree; or from Document::UpdateStyleAndLayout, which
    // does its own ancestor tree walk).
    void UpdateStyleAndLayoutTreeForThisDocument();

    void UpdateStyleAndLayoutTreeForNode(const Node*);
    void UpdateStyleAndLayoutTreeForSubtree(const Node*);

    void UpdateStyleAndLayout(DocumentUpdateReason);
    void LayoutUpdated();
    enum RunPostLayoutTasks {
        kRunPostLayoutTasksAsynchronously,
        kRunPostLayoutTasksSynchronously,
    };
    void UpdateStyleAndLayoutForNode(const Node*, DocumentUpdateReason);
    void UpdateStyleAndLayoutForRange(const Range*, DocumentUpdateReason);
    void IncLayoutCallsCounter();
    void IncLayoutCallsCounterNG();
    void IncLayoutBlockCounter();
    void IncLayoutBlockCounterNG();

    scoped_refptr<const ComputedStyle> StyleForPage(uint32_t page_index);

    // Ensures that location-based data will be valid for a given node.
    //
    // This will run style and layout if they are currently dirty, and it may also
    // run compositing inputs if the node is in a sticky subtree (as the sticky
    // offset may change the node's position).
    //
    // Due to this you should only call this if you definitely need valid location
    // data, otherwise use one of the |UpdateStyleAndLayout...| methods above.
    void EnsurePaintLocationDataValidForNode(const Node*, DocumentUpdateReason reason);
    void EnsurePaintLocationDataValidForNode(const Node*, DocumentUpdateReason reason, CSSPropertyID property_id);

    // Returns true if page box (margin boxes and page borders) is visible.
    bool IsPageBoxVisible(uint32_t page_index);

    // Gets the description for the specified page. This includes preferred page
    // size and margins in pixels, assuming 96 pixels per inch. The size and
    // margins must be initialized to the default values that are used if auto is
    // specified.
    void GetPageDescription(uint32_t page_index, WebPrintPageDescription*);

    ResourceFetcher* Fetcher() const;

    void Initialize();
    virtual void Shutdown();

    // If you have a Document, use GetLayoutView() instead which is faster.
    void GetLayoutObject() const = delete;

    LayoutView* GetLayoutView() const;

    // This will return an AXObjectCache only if there's one or more
    // AXContext associated with this document. When all associated
    // AXContexts are deleted, the AXObjectCache will be removed.
    AXObjectCache* ExistingAXObjectCache() const;
    bool HasAXObjectCache() const;
    Document& AXObjectCacheOwner() const;
    void ClearAXObjectCache();

    // to get visually ordered hebrew and arabic pages right
    bool VisuallyOrdered() const;

    DocumentLoader* Loader() const;

    // This is the DOM API document.open().
    void open(LocalDOMWindow* entered_window, ExceptionState&);
    // This is used internally and does not handle exceptions.
    void open();
    DocumentParser* OpenForNavigation(ParserSynchronizationPolicy, const AtomicString& mime_type, const AtomicString& encoding);
    DocumentParser* ImplicitOpen(ParserSynchronizationPolicy);

    // This is the DOM API document.open() implementation.
    // document.open() opens a new window when called with three arguments.
    Document* open(v8::Isolate*, const AtomicString& type, const AtomicString& replace, ExceptionState&);
    DOMWindow* open(v8::Isolate*, const String& url_string, const AtomicString& name, const AtomicString& features, ExceptionState&);
    // This is the DOM API document.close().
    void close(ExceptionState&);
    // This is used internally and does not handle exceptions.
    void close();

    // Corresponds to "9. Abort the active document of browsingContext."
    // https://html.spec.whatwg.org/C/#navigate
    void Abort();

    void CheckCompleted();

    // Dispatches beforeunload into this document. Returns true if the
    // beforeunload handler indicates that it is safe to proceed with an unload,
    // false otherwise.
    //
    // |chrome_client| is used to synchronously get user consent (via a modal
    // javascript dialog) to allow the unload to proceed if the beforeunload
    // handler returns a non-null value, indicating unsaved state. If a
    // null |chrome_client| is provided and the beforeunload returns a non-null
    // value this function will automatically return false, indicating that the
    // unload should not proceed. A null chrome client is set to by the freezing
    // logic, which uses this to determine if a non-empty beforeunload handler
    // is present before allowing discarding to proceed.
    //
    // |is_reload| indicates if the beforeunload is being triggered because of a
    // reload operation, otherwise it is assumed to be a page close or navigation.
    //
    // |did_allow_navigation| is set to reflect the choice made by the user via
    // the modal dialog. The value is meaningless if |auto_cancel|
    // is true, in which case it will always be set to false.
    bool DispatchBeforeUnloadEvent(ChromeClient* chrome_client, bool is_reload, bool& did_allow_navigation);

    // Dispatches "pagehide", "visibilitychange" and "unload" events, if not
    // dispatched already. Fills `unload_timing_info` if present.
    void DispatchUnloadEvents(UnloadEventTimingInfo* unload_timing_info);

    void DispatchFreezeEvent();

    enum PageDismissalType { kNoDismissal, kBeforeUnloadDismissal, kPageHideDismissal, kUnloadVisibilityChangeDismissal, kUnloadDismissal };
    PageDismissalType PageDismissalEventBeingDispatched() const;

    void CancelParsing();

    void write(const String& text, LocalDOMWindow* entered_window = nullptr, ExceptionState& = ASSERT_NO_EXCEPTION);
    void writeln(const String& text, LocalDOMWindow* entered_window = nullptr, ExceptionState& = ASSERT_NO_EXCEPTION);
    void write(v8::Isolate*, const Vector<String>& text, ExceptionState&);
    void writeln(v8::Isolate*, const Vector<String>& text, ExceptionState&);

    // TrustedHTML variants of the above.
    // TODO(mkwst): Write a spec for this.
    void write(v8::Isolate*, TrustedHTML*, ExceptionState&);
    void writeln(v8::Isolate*, TrustedHTML*, ExceptionState&);

    bool WellFormed() const;

    const DocumentToken& Token();

    // Return the document URL, or an empty URL if it's unavailable.
    // This is not an implementation of web-exposed Document.prototype.URL.
    const KURL& Url() const;
    void SetURL(const KURL&);

    // Bind the url to document.url, if unavailable bind to about:blank.
    KURL urlForBinding() const;

    // To understand how these concepts relate to one another, please see the
    // comments surrounding their declaration.

    // Document base URL.
    // https://html.spec.whatwg.org/C/#document-base-url
    const KURL& BaseURL() const;
    void SetBaseURLOverride(const KURL&);
    const KURL& BaseURLOverride() const;
    KURL ValidBaseElementURL() const;
    const AtomicString& BaseTarget() const;
    void ProcessBaseElement();

    // Fallback base URL.
    // https://html.spec.whatwg.org/C/#fallback-base-url
    KURL FallbackBaseURL() const;

    // Creates URL based on passed relative url and this documents base URL.
    // Depending on base URL value it is possible that parent document
    // base URL will be used instead. Uses CompleteURLWithOverride internally.
    KURL CompleteURL(const String&) const;
    // Creates URL based on passed relative url and passed base URL override.
    KURL CompleteURLWithOverride(const String&, const KURL& base_url_override) const;

    const KURL& WebBundleClaimedUrl() const;

    // Determines whether a new document should take on the same origin as that of
    // the document which created it.
    static bool ShouldInheritSecurityOriginFromOwner(const KURL&);

    CSSStyleSheet& ElementSheet();

    virtual DocumentParser* CreateParser();
    DocumentParser* Parser() const;
    ScriptableDocumentParser* GetScriptableDocumentParser() const;

    // FinishingPrinting denotes that the non-printing layout state is being
    // restored.
    enum PrintingState { kNotPrinting, kBeforePrinting, kPrinting, kFinishingPrinting };
    bool Printing() const;
    bool BeforePrintingOrPrinting() const;
    bool FinishingOrIsPrinting();
    void SetPrinting(PrintingState);
    // Call this if printing is about to begin, so that any unloaded resources
    // (such as lazy-loaded images) necessary for printing are requested and
    // marked as blocking load. Returns whether any resources have started
    // loading as a result.
    bool WillPrintSoon();

    enum PaintPreviewState {
        // A paint preview is not in the process of being captured.
        kNotPaintingPreview = 0,

        // A paint preview is in the process of being captured.
        kPaintingPreview,

        // The same as `kPaintingPreview`, but where appropriate GPU accelerated
        // content should be skipped during painting. This can reduce hangs and
        // memory usage at the expense of a lower fidelity capture.
        kPaintingPreviewSkipAcceleratedContent,
    };
    PaintPreviewState GetPaintPreviewState() const;
    bool IsPrintingOrPaintingPreview() const
    {
        return Printing() || GetPaintPreviewState() != Document::kNotPaintingPreview;
    }

    enum CompatibilityMode { kQuirksMode, kLimitedQuirksMode, kNoQuirksMode };

    void SetCompatibilityMode(CompatibilityMode);
    CompatibilityMode GetCompatibilityMode() const;

    String compatMode() const;

    bool InQuirksMode() const;
    bool InLimitedQuirksMode() const;
    bool InNoQuirksMode() const;
    bool InLineHeightQuirksMode() const
    {
        return !InNoQuirksMode();
    }

    // https://html.spec.whatwg.org/C/#documentreadystate
    enum DocumentReadyState { kLoading, kInteractive, kComplete };

    DocumentReadyState GetReadyState() const;
    void SetReadyState(DocumentReadyState);
    bool IsLoadCompleted() const;

    bool IsFreezingInProgress() const;

    enum ParsingState { kParsing, kInDOMContentLoaded, kFinishedParsing };
    void SetParsingState(ParsingState);
    bool Parsing() const;
    bool HasFinishedParsing() const;

    bool ShouldScheduleLayout() const;

    TextLinkColors& GetTextLinkColors();
    const TextLinkColors& GetTextLinkColors() const;
    VisitedLinkState& GetVisitedLinkState() const;

    MouseEventWithHitTestResults PerformMouseEventHitTest(const HitTestRequest&, const PhysicalOffset&, const WebMouseEvent&);

    void SetHadKeyboardEvent(bool had_keyboard_event);
    bool HadKeyboardEvent() const;
    void SetLastFocusType(mojom::blink::FocusType last_focus_type);
    mojom::blink::FocusType LastFocusType() const;
    bool SetFocusedElement(Element*, const FocusParams&);
    void ClearFocusedElement();
    Element* FocusedElement() const;
    void ClearFocusedElementIfNeeded();
    UserActionElementSet& UserActionElements();
    const UserActionElementSet& UserActionElements() const;

    ExplicitlySetAttrElementsMap* GetExplicitlySetAttrElementsMap(Element*);
    void MoveElementExplicitlySetAttrElementsMapToNewDocument(Element*, Document& new_document);

    // Returns false if the function fails.  e.g. |pseudo| is not supported.
    bool SetPseudoStateForTesting(Element& element, const String& pseudo, bool matches);
    void EnqueueAutofocusCandidate(Element&);
    bool HasAutofocusCandidates() const;
    void FlushAutofocusCandidates();
    void FinalizeAutofocus();
    Element* GetAutofocusDelegate() const;
    void SetSequentialFocusNavigationStartingPoint(Node*);
    Element* SequentialFocusNavigationStartingPoint(mojom::blink::FocusType) const;

    void SetActiveElement(Element*);
    Element* GetActiveElement() const;

    void AddFocusedElementChangeObserver(FocusedElementChangeObserver*);
    void RemoveFocusedElementChangeObserver(FocusedElementChangeObserver*);

    Element* HoverElement() const;

    void RemoveFocusedElementOfSubtree(Node&, bool among_children_only = false);
    void HoveredElementDetached(Element&);
    void ActiveChainNodeDetached(Element&);

    // Updates hover and active state of elements in the Document. The
    // |is_active| param specifies whether the active state should be set or
    // unset. |update_active_chain| is used to prevent updates to elements
    // outside the frozen active chain; passing false will only refresh the
    // active state of elements in the existing chain, but not outside of it. The
    // given element is the inner-most element whose state is being modified.
    // Hover is always applied.
    void UpdateHoverActiveState(bool is_active, bool update_active_chain, Element*);

    // Updates for :target (CSS3 selector).
    void SetCSSTarget(Element*);
    Element* CssTarget() const;
    void SetSelectorFragmentAnchorCSSTarget(Element*);

    void ScheduleLayoutTreeUpdateIfNeeded();
    bool HasPendingForcedStyleRecalc() const;

    void RegisterNodeList(const LiveNodeListBase*);
    void UnregisterNodeList(const LiveNodeListBase*);
    void RegisterNodeListWithIdNameCache(const LiveNodeListBase*);
    void UnregisterNodeListWithIdNameCache(const LiveNodeListBase*);
    bool ShouldInvalidateNodeListCaches(const QualifiedName* attr_name = nullptr) const;
    void InvalidateNodeListCaches(const QualifiedName* attr_name);

    void AttachNodeIterator(NodeIterator*);
    void DetachNodeIterator(NodeIterator*);
    void MoveNodeIteratorsToNewDocument(Node&, Document&);

    void AttachRange(Range*);
    void DetachRange(Range*);

    void DidMoveTreeToNewDocument(const Node& root);
    // nodeChildrenWillBeRemoved is used when removing all node children at once.
    void NodeChildrenWillBeRemoved(ContainerNode&);
    // nodeWillBeRemoved is only safe when removing one node at a time.
    void NodeWillBeRemoved(Node&);
    bool CanAcceptChild(const Node& new_child, const Node* next, const Node* old_child, ExceptionState&) const;

    void DidInsertText(const CharacterData&, unsigned offset, unsigned length);
    void DidRemoveText(const CharacterData&, unsigned offset, unsigned length);
    void DidMergeTextNodes(const Text& merged_node, const Text& node_to_be_removed, unsigned old_length);
    void DidSplitTextNode(const Text& old_node);

    LocalDOMWindow* domWindow() const;

    // Helper functions for forwarding LocalDOMWindow event related tasks to the
    // LocalDOMWindow if it exists.
    void SetWindowAttributeEventListener(const AtomicString& event_type, EventListener*);
    EventListener* GetWindowAttributeEventListener(const AtomicString& event_type);

    static void RegisterEventFactory(std::unique_ptr<EventFactoryBase>);
    static Event* createEvent(ScriptState*, const String& event_type, ExceptionState&);

    // keep track of what types of event listeners are registered, so we don't
    // dispatch events unnecessarily
    enum ListenerType {
        kDOMSubtreeModifiedListener = 1,
        kDOMNodeInsertedListener = 1 << 1,
        kDOMNodeRemovedListener = 1 << 2,
        kDOMNodeRemovedFromDocumentListener = 1 << 3,
        kDOMNodeInsertedIntoDocumentListener = 1 << 4,
        kDOMCharacterDataModifiedListener = 1 << 5,
        kAnimationEndListener = 1 << 6,
        kAnimationStartListener = 1 << 7,
        kAnimationIterationListener = 1 << 8,
        kAnimationCancelListener = 1 << 9,
        kTransitionRunListener = 1 << 10,
        kTransitionStartListener = 1 << 11,
        kTransitionEndListener = 1 << 12,
        kTransitionCancelListener = 1 << 13,
        kScrollListener = 1 << 14,
        kLoadListenerAtCapturePhaseOrAtStyleElement = 1 << 15,
        // 0 bits remaining
    };

    bool HasListenerType(ListenerType listener_type) const;
    void AddListenerTypeIfNeeded(const AtomicString& event_type, EventTarget&);

    bool HasMutationObserversOfType(MutationType type) const;
    bool HasMutationObservers() const;
    void AddMutationObserverTypes(MutationType types);

    IntersectionObserverController* GetIntersectionObserverController();
    IntersectionObserverController& EnsureIntersectionObserverController();

    // This is used to track IntersectionObservers for which this document is the
    // explicit root. The IntersectionObserverController tracks *all* observers
    // associated with this document; usually that's what you want.
    ElementIntersectionObserverData* DocumentExplicitRootIntersectionObserverData() const;
    ElementIntersectionObserverData& EnsureDocumentExplicitRootIntersectionObserverData();

    const ScriptRegexp& EnsureEmailRegexp() const;

    // Returns the owning element in the parent document. Returns nullptr if
    // this is the top level document or the owner is remote.
    HTMLFrameOwnerElement* LocalOwner() const;

    void WillChangeFrameOwnerProperties(
        int margin_width, int margin_height, mojom::blink::ScrollbarMode, bool is_display_none, mojom::blink::ColorScheme color_scheme);

    String title() const;
    void setTitle(const String&);

    Element* TitleElement() const;
    void SetTitleElement(Element*);
    void RemoveTitle(Element* title_element);

    const AtomicString& dir();
    void setDir(const AtomicString&);

    String cookie(ExceptionState&) const;
    void setCookie(const String&, ExceptionState&);
    bool CookiesEnabled() const;

    void SetCookieManager(mojo::PendingRemote<network::mojom::blink::RestrictedCookieManager> cookie_manager);

    const AtomicString& referrer() const;

    String domain() const;
    void setDomain(const String& new_domain, ExceptionState&);

    void OverrideLastModified(const AtomicString& modified);
    absl::optional<base::Time> lastModifiedTime() const;
    String lastModified() const;

    // The cookieURL is used to query the cookie database for this document's
    // cookies. For example, if the cookie URL is http://example.com, we'll
    // use the non-Secure cookies for example.com when computing
    // document.cookie.
    //
    // Q: How is the cookieURL different from the document's URL?
    // A: The two URLs are the same almost all the time.  However, if one
    //    document inherits the security context of another document, it
    //    inherits its cookieURL but not its URL.
    //
    const KURL& CookieURL() const;

    // Returns null if the document is not attached to a frame.
    scoped_refptr<const SecurityOrigin> TopFrameOrigin() const;

    net::SiteForCookies SiteForCookies() const;

    // Permissions service helper methods to facilitate requesting and checking
    // storage access permissions.
    mojom::blink::PermissionService* GetPermissionService(ExecutionContext* execution_context);
    void PermissionServiceConnectionError();

    // Storage Access API methods to check for or request access to storage that
    // may otherwise be blocked.
    ScriptPromise hasStorageAccess(ScriptState* script_state);
    ScriptPromise requestStorageAccess(ScriptState* script_state);
    ScriptPromise requestStorageAccessForOrigin(ScriptState* script_state, const AtomicString& site);

    // Fragment directive API, currently used to feature detect text-fragments.
    // https://wicg.github.io/scroll-to-text-fragment/#feature-detectability
    FragmentDirective& fragmentDirective() const;

    // Sends a query via Mojo to ask whether the user has any trust tokens. This
    // can reject on permissions errors (e.g. associating |issuer| with the
    // top-level origin would exceed the top-level origin's limit on the number of
    // associated issuers) or on other internal errors (e.g. the network service
    // is unavailable).
    ScriptPromise hasTrustToken(ScriptState* script_state, const String& issuer, ExceptionState&);

    // Sends a query via Mojo to ask whether the user has a redemption record.
    // This can reject on permissions errors (e.g. associating |issuer| with the
    // top-level origin would exceed the top-level origin's limit on the number of
    // associated issuers) or on other internal errors (e.g. the network service
    // is unavailable).
    ScriptPromise hasRedemptionRecord(ScriptState* script_state, const String& issuer, ExceptionState&);

    // The following implements the rule from HTML 4 for what valid names are.
    // To get this right for all the XML cases, we probably have to improve this
    // or move it and make it sensitive to the type of document.
    static bool IsValidName(const StringView&);

    // The following breaks a qualified name into a prefix and a local name.
    // It also does a validity check, and returns false if the qualified name
    // is invalid.  It also sets ExceptionCode when name is invalid.
    static bool ParseQualifiedName(const AtomicString& qualified_name, AtomicString& prefix, AtomicString& local_name, ExceptionState&);

    // Checks to make sure prefix and namespace do not conflict (per DOM Core 3)
    static bool HasValidNamespaceForElements(const QualifiedName&);
    static bool HasValidNamespaceForAttributes(const QualifiedName&);

    // "body element" as defined by HTML5
    // (https://html.spec.whatwg.org/C/#the-body-element-2).
    // That is, the first body or frameset child of the document element.
    HTMLElement* body() const;

    // "HTML body element" as defined by CSSOM View spec
    // (https://drafts.csswg.org/cssom-view/#the-html-body-element).
    // That is, the first body child of the document element.
    HTMLBodyElement* FirstBodyElement() const;

    void setBody(HTMLElement*, ExceptionState&);
    void WillInsertBody();

    HTMLHeadElement* head() const;

    // Decide which element is to define the viewport's overflow policy.
    Element* ViewportDefiningElement() const;

    DocumentMarkerController& Markers() const;

    // Support for Javascript execCommand, and related methods
    // See "core/editing/commands/document_exec_command.cc" for implementations.
    bool execCommand(const String& command, bool show_ui, const V8UnionStringOrTrustedHTML* value, ExceptionState&);

    bool execCommand(const String& command, bool show_ui, const String& value, ExceptionState&);

    bool IsRunningExecCommand() const;
    bool queryCommandEnabled(const String& command, ExceptionState&);
    bool queryCommandIndeterm(const String& command, ExceptionState&);
    bool queryCommandState(const String& command, ExceptionState&);
    bool queryCommandSupported(const String& command, ExceptionState&);
    String queryCommandValue(const String& command, ExceptionState&);

    KURL OpenSearchDescriptionURL();

    // designMode support
    bool InDesignMode() const;
    String designMode() const;
    void setDesignMode(const String&);

    // The document of the parent frame.
    Document* ParentDocument() const;
    Document& TopDocument() const;

    // Will only return nullptr if the document has Shutdown() or in unit tests.
    // See `execution_context_` for details.
    ExecutionContext* GetExecutionContext() const final;

    // Return the agent. Can only be null in unit tests.
    Agent* GetAgent() const;

    ScriptRunner* GetScriptRunner();
    const base::ElapsedTimer& GetStartTime() const;

    V8HTMLOrSVGScriptElement* currentScriptForBinding() const;
    void PushCurrentScript(ScriptElementBase*);
    void PopCurrentScript(ScriptElementBase*);

    void SetTransformSource(std::unique_ptr<TransformSource>);
    TransformSource* GetTransformSource() const;

    void IncDOMTreeVersion();
    uint64_t DomTreeVersion() const;

    uint64_t StyleVersion() const;

    enum PendingSheetLayout { kNoLayoutWithPendingSheets, kDidLayoutWithPendingSheets, kIgnoreLayoutWithPendingSheets };

    Vector<IconURL> IconURLs(int icon_types_mask);

    void UpdateThemeColorCache();
    absl::optional<Color> ThemeColor();

    // Returns the HTMLLinkElement currently in use for the Web Manifest.
    // Returns null if there is no such element.
    HTMLLinkElement* LinkManifest() const;

    // Returns the HTMLLinkElement holding the canonical URL. Returns null if
    // there is no such element.
    HTMLLinkElement* LinkCanonical() const;

    void SetShouldUpdateSelectionAfterLayout(bool flag);
    bool ShouldUpdateSelectionAfterLayout() const;
    void SendFocusNotification(Element*, mojom::blink::FocusType);

    bool IsDNSPrefetchEnabled() const;
    void ParseDNSPrefetchControlHeader(const String&);

    void MarkFirstPaint();
    void OnPaintFinished();
    void OnLargestContentfulPaintUpdated();
    void OnPrepareToStopParsing();
    void FinishedParsing();

    void SetEncodingData(const DocumentEncodingData& new_data);
    const WTF::TextEncoding& Encoding() const;

    bool EncodingWasDetectedHeuristically() const;
    bool SawDecodingError() const;

    void SetAnnotatedRegionsDirty(bool f);
    bool AnnotatedRegionsDirty() const;
    bool HasAnnotatedRegions() const;
    void SetHasAnnotatedRegions(bool f);
    const Vector<AnnotatedRegionValue>& AnnotatedRegions() const;
    void SetAnnotatedRegions(const Vector<AnnotatedRegionValue>&);

    void RemovedEventListener(const AtomicString& event_type, const RegisteredEventListener&) final;
    void RemoveAllEventListeners() final;

    const SVGDocumentExtensions* SvgExtensions() const;
    SVGDocumentExtensions& AccessSVGExtensions();

    bool AllowInlineEventHandler(Node*, EventListener*, const String& context_url, const WTF::OrdinalNumber& context_line);

    void StatePopped(scoped_refptr<SerializedScriptValue>);

    enum LoadEventProgress {
        kLoadEventNotRun,
        kLoadEventInProgress,
        kLoadEventCompleted,
        kBeforeUnloadEventInProgress,
        // Advanced to only if the beforeunload event in this document and
        // subdocuments isn't canceled and will cause an unload. If beforeunload is
        // canceled |load_event_progress_| will revert to its value prior to the
        // beforeunload being dispatched.
        kBeforeUnloadEventHandled,
        kPageHideInProgress,
        kUnloadVisibilityChangeInProgress,
        kUnloadEventInProgress,
        kUnloadEventHandled
    };
    bool LoadEventStillNeeded() const;
    bool LoadEventStarted() const;
    bool LoadEventFinished() const;
    bool BeforeUnloadStarted() const;
    bool ProcessingBeforeUnload() const;
    bool UnloadStarted() const;
    bool UnloadEventInProgress() const;

    void BeforeUnloadDoneWillUnload();

    void SetContainsPlugins();
    bool ContainsPlugins() const;

    void EnqueueResizeEvent();
    void EnqueueScrollEventForNode(Node*);
    void EnqueueScrollEndEventForNode(Node*);
    void EnqueueOverscrollEventForNode(Node* target, double delta_x, double delta_y);
    void EnqueueDisplayLockActivationTask(base::OnceClosure);
    void EnqueueAnimationFrameTask(base::OnceClosure);
    void EnqueueAnimationFrameEvent(Event*);
    // Only one event for a target/event type combination will be dispatched per
    // frame.
    void EnqueueUniqueAnimationFrameEvent(Event*);
    void EnqueueMediaQueryChangeListeners(HeapVector<Member<MediaQueryListListener>>&);
    void EnqueueVisualViewportScrollEvent();
    void EnqueueVisualViewportResizeEvent();

    void DispatchEventsForPrinting();

    void exitPointerLock();
    Element* PointerLockElement() const;

    // Used to allow element that loads data without going through a FrameLoader
    // to delay the 'load' event.
    void IncrementLoadEventDelayCount();
    void DecrementLoadEventDelayCount();
    void CheckLoadEventSoon();
    bool IsDelayingLoadEvent();
    void LoadPluginsSoon();
    // This calls CheckCompleted() sync and thus can cause JavaScript execution.
    void DecrementLoadEventDelayCountAndCheckLoadEvent();
    // Objects and embeds depend on "being rendered" for delaying the load event.
    // This method makes sure we run a layout tree update before unblocking the
    // load event after such elements have been inserted.
    //
    // Spec:
    //
    // https://html.spec.whatwg.org/multipage/iframe-embed-object.html#the-object-element
    // https://html.spec.whatwg.org/multipage/iframe-embed-object.html#the-embed-element
    void DelayLoadEventUntilLayoutTreeUpdate();

    const EventPath::NodePath& GetOrCalculateEventNodePath(Node& node);

    const DocumentTiming& GetTiming() const;

    bool ShouldMarkFontPerformance() const
    {
        return !IsInitialEmptyDocument() && !IsXMLDocument() && IsInOutermostMainFrame();
    }

    int RequestAnimationFrame(FrameCallback*);
    void CancelAnimationFrame(int id);
    void ServiceScriptedAnimations(base::TimeTicks monotonic_animation_start_time, bool can_throttle = false);

    int RequestIdleCallback(IdleTask*, const IdleRequestOptions*);
    void CancelIdleCallback(int id);

    ScriptedAnimationController& GetScriptedAnimationController();

    void InitDNSPrefetch();

    bool IsInDocumentWrite() const;

    TextAutosizer* GetTextAutosizer();

    ScriptValue registerElement(ScriptState*, const AtomicString& name, const ElementRegistrationOptions*, ExceptionState&);

    void AdjustQuadsForScrollAndAbsoluteZoom(Vector<gfx::QuadF>&, const LayoutObject&) const;
    void AdjustRectForScrollAndAbsoluteZoom(gfx::RectF&, const LayoutObject&) const;

    void SetContextFeatures(ContextFeatures&);
    ContextFeatures& GetContextFeatures() const;

    ElementDataCache* GetElementDataCache();

    void DidLoadAllScriptBlockingResources();
    void DidAddPendingParserBlockingStylesheet();
    void DidLoadAllPendingParserBlockingStylesheets();
    void DidRemoveAllPendingStylesheets();

    bool InStyleRecalc() const;

    // Return a Locale for the default locale if the argument is null or empty.
    Locale& GetCachedLocale(const AtomicString& locale = g_null_atom);

    AnimationClock& GetAnimationClock();
    const AnimationClock& GetAnimationClock() const;
    DocumentAnimations& GetDocumentAnimations() const;
    DocumentTimeline& Timeline() const;
    PendingAnimations& GetPendingAnimations();
    WorkletAnimationController& GetWorkletAnimationController();

    void AttachCompositorTimeline(cc::AnimationTimeline*) const;

    void AddToTopLayer(Element*, const Element* before = nullptr);
    void RemoveFromTopLayer(Element*);
    //   const HeapVector<Member<Element>>& TopLayerElements() const {
    //     return top_layer_elements_;
    //   }

    HTMLDialogElement* ActiveModalDialog() const;

    Element* PopupHintShowing() const;
    void SetPopupHintShowing(Element* element);
    //   HeapVector<Member<Element>>& PopupStack() { return popup_stack_; }
    //   const HeapVector<Member<Element>>& PopupStack() const { return popup_stack_; }
    //   bool PopupAutoShowing() const { return !popup_stack_.empty(); }
    Element* TopmostPopupAutoOrHint() const;
    HeapHashSet<Member<Element>>& PopupsWaitingToHide();
    const Element* PopUpMousedownTarget() const;
    void SetPopUpMousedownTarget(const Element*);

    // Add an element to the set of elements that, because of CSS toggle
    // creation, need style recalc done later.
    void AddToRecalcStyleForToggle(Element* element);

    // Call SetNeedsStyleRecalc for elements from AddToRecalcStyleForToggle;
    // return whether any calls were made.
    bool SetNeedsStyleRecalcForToggles();

    // A non-null template_document_host_ implies that |this| was created by
    // EnsureTemplateDocument().
    bool IsTemplateDocument() const;
    Document& EnsureTemplateDocument();
    Document* TemplateDocumentHost();

    // TODO(thestig): Rename these and related functions, since we can call them
    // for controls outside of forms as well.
    void DidAssociateFormControl(Element*);

    void AddConsoleMessage(ConsoleMessage* message, bool discard_duplicates = false) const;

    DocumentLifecycle& Lifecycle();
    const DocumentLifecycle& Lifecycle() const;
    bool IsActive() const;
    bool IsDetached() const;

    bool IsStopped() const;
    bool InPostLifecycleSteps() const;

    enum HttpRefreshType { kHttpRefreshFromHeader, kHttpRefreshFromMetaTag };
    void MaybeHandleHttpRefresh(const String&, HttpRefreshType);
    bool IsHttpRefreshScheduledWithin(base::TimeDelta interval);

    // Marks the Document has having at least one Element which depends
    // on the specified ViewportUnitFlags.
    void AddViewportUnitFlags(unsigned flags);

    bool HasViewportUnits() const;
    bool HasStaticViewportUnits() const;
    bool HasDynamicViewportUnits() const;

    void LayoutViewportWasResized();
    // dv*
    void DynamicViewportUnitsChanged();

    void InvalidateStyleAndLayoutForFontUpdates();

    void Trace(Visitor*) const override;

    AtomicString ConvertLocalName(const AtomicString&);

    void PlatformColorsChanged();

    NthIndexCache* GetNthIndexCache() const;

    CheckPseudoHasCacheScope* GetCheckPseudoHasCacheScope() const;

    CanvasFontCache* GetCanvasFontCache();

    // Used by unit tests so that all parsing will be synchronous for
    // controlling parsing and chunking precisely.
    static void SetForceSynchronousParsingForTesting(bool);
    static bool ForceSynchronousParsingForTesting();

    void IncrementNodeCount();
    void DecrementNodeCount();
    int NodeCount() const;

    SnapCoordinator& GetSnapCoordinator();
    void PerformScrollSnappingTasks();

    void SetContainsShadowRoot();

    bool MayContainShadowRoots() const;

    RootScrollerController& GetRootScrollerController() const;

    AnchorElementInteractionTracker* GetAnchorElementInteractionTracker() const;

    // Returns true if this document has a frame and it is a main frame.
    // See `Frame::IsMainFrame`.
    bool IsInMainFrame() const;

    // Returns true if this document has a frame and is an outermost main frame.
    // See `Frame::IsOutermostMainFrame`.
    bool IsInOutermostMainFrame() const;

    const PropertyRegistry* GetPropertyRegistry() const;
    PropertyRegistry& EnsurePropertyRegistry();

    // May return nullptr when PerformanceManager instrumentation is disabled.
    DocumentResourceCoordinator* GetResourceCoordinator();

    const AtomicString& bgColor() const;
    void setBgColor(const AtomicString&);
    const AtomicString& fgColor() const;
    void setFgColor(const AtomicString&);
    const AtomicString& alinkColor() const;
    void setAlinkColor(const AtomicString&);
    const AtomicString& linkColor() const;
    void setLinkColor(const AtomicString&);
    const AtomicString& vlinkColor() const;
    void setVlinkColor(const AtomicString&);

    void clear()
    {
    }

    void captureEvents()
    {
    }
    void releaseEvents()
    {
    }

    ukm::UkmRecorder* UkmRecorder();
    ukm::SourceId UkmSourceID() const;

    // Tracks and reports UKM metrics of the number of attempted font family match
    // attempts (both successful and not successful) by the page.
    FontMatchingMetrics* GetFontMatchingMetrics();

    scoped_refptr<base::SingleThreadTaskRunner> GetTaskRunner(TaskType);

    StylePropertyMapReadOnly* ComputedStyleMap(Element*);
    void AddComputedStyleMapItem(Element*, StylePropertyMapReadOnly*);
    StylePropertyMapReadOnly* RemoveComputedStyleMapItem(Element*);

    SlotAssignmentEngine& GetSlotAssignmentEngine();

    bool IsSlotAssignmentDirty() const;

#if DCHECK_IS_ON()
    unsigned& SlotAssignmentRecalcForbiddenRecursionDepth();
    bool IsSlotAssignmentRecalcForbidden();
#endif

#if EXPENSIVE_DCHECKS_ARE_ON()
    void AssertLayoutTreeUpdatedAfterLayout();
#endif

    unsigned& FlatTreeTraversalForbiddenRecursionDepth();
    bool IsFlatTreeTraversalForbidden();

    unsigned& SlotAssignmentRecalcDepth();
    bool IsInSlotAssignmentRecalc() const;

    bool IsVerticalScrollEnforced() const;
    bool IsFocusAllowed() const;

    LazyLoadImageObserver& EnsureLazyLoadImageObserver();

    void IncrementNumberOfCanvases();

    void ProcessJavaScriptUrl(const KURL&, scoped_refptr<const DOMWrapperWorld> world);

    DisplayLockDocumentState& GetDisplayLockDocumentState() const;

    // Deferred compositor commits are disallowed by default, and are only allowed
    // for same-origin navigations to an html document fetched with http.
    bool DeferredCompositorCommitIsAllowed() const;
    void SetDeferredCompositorCommitIsAllowed(bool new_value);

    // Returns whether the document is inside the scope specified in the Web App
    // Manifest. If the document doesn't run in a context of a Web App or has no
    // associated Web App Manifest, it will return false.
    bool IsInWebAppScope() const;

    ComputedAccessibleNode* GetOrCreateComputedAccessibleNode(AXID ax_id);

    // Return true if any accessibility contexts have been enabled.
    bool IsAccessibilityEnabled() const;

    void DispatchHandleLoadStart();
    void DispatchHandleLoadOrLayoutComplete();

    bool HaveRenderBlockingStylesheetsLoaded() const;
    bool HaveRenderBlockingResourcesLoaded() const;

    // Sets a beforeunload handler for documents which are embedding plugins. This
    // includes PluginDocument as well as an HTMLDocument which embeds a plugin
    // inside a cross-process frame (MimeHandlerView).
    void SetShowBeforeUnloadDialog(bool show_dialog);

    void ColorSchemeChanged();

    // A new vision deficiency is being emulated through DevTools.
    void VisionDeficiencyChanged();

    // A META element with name=color-scheme was added, removed, or modified.
    // Update the presentation level color-scheme property for the root element.
    void ColorSchemeMetaChanged();

    // A META element with name=supports-reduced-motion was added, removed, or
    // modified. Re-collect the META values.
    void SupportsReducedMotionMetaChanged();

    // Use counter related functions.
    void CountUse(mojom::WebFeature feature) final;
    void CountDeprecation(mojom::WebFeature feature) final;
    void CountUse(mojom::WebFeature feature) const;
    void CountProperty(CSSPropertyID property_id) const;
    void CountAnimatedProperty(CSSPropertyID property_id) const;
    // Return whether the Feature was previously counted for this document.
    // NOTE: only for use in testing.
    bool IsUseCounted(mojom::WebFeature) const;
    // Return whether the property was previously counted for this document.
    // NOTE: only for use in testing.
    bool IsPropertyCounted(CSSPropertyID property) const;
    // Return whether the animated property was previously counted for this
    // document.
    // NOTE: only for use in testing.
    bool IsAnimatedPropertyCounted(CSSPropertyID property) const;
    void ClearUseCounterForTesting(mojom::WebFeature);

    void UpdateForcedColors();
    bool InForcedColorsMode() const;
    bool InDarkMode();

    // Capture the toggle event during parsing either by HTML parser or XML
    // parser.
    void SetToggleDuringParsing(bool toggle_during_parsing);
    bool ToggleDuringParsing();

    // We setup a dummy document to sanitize clipboard markup before pasting.
    // Sets and indicates whether this is the dummy document.
    void SetIsForMarkupSanitization(bool is_for_sanitization);
    bool IsForMarkupSanitization() const;

    bool HasPendingJavaScriptUrlsForTest();

    void ApplyScrollRestorationLogic();

    void MarkHasFindInPageRequest();
    void MarkHasFindInPageContentVisibilityActiveMatch();
    void MarkHasFindInPageBeforematchExpandedHiddenMatchable();

    void CancelPendingJavaScriptUrls();

    HeapObserverSet<SynchronousMutationObserver>& SynchronousMutationObserverSet();

    void NotifyUpdateCharacterData(CharacterData* character_data, unsigned offset, unsigned old_length, unsigned new_length);
    void NotifyChangeChildren(const ContainerNode& container, const ContainerNode::ChildrenChange& change);
    void NotifyAttributeChanged(const Element& element, const QualifiedName& name, const AtomicString& old_value, const AtomicString& new_value);

    RenderBlockingResourceManager* GetRenderBlockingResourceManager();

    // Called when a previously render-blocking resource is no longer render-
    // blocking, due to it has finished loading or has given up render-blocking.
    void RenderBlockingResourceUnblocked();

    bool RenderingHasBegun() const;

    void IncrementLazyAdsFrameCount();
    void IncrementLazyEmbedsFrameCount();
    void IncrementImmediateChildFrameCreationCount();
    int GetImmediateChildFrameCreationCount() const;

    enum class DeclarativeShadowRootAllowState : uint8_t { kNotSet, kAllow, kDeny };
    DeclarativeShadowRootAllowState GetDeclarativeShadowRootAllowState() const;
    void setAllowDeclarativeShadowRoots(bool val);

    void SetFindInPageActiveMatchNode(Node*);
    const Node* GetFindInPageActiveMatchNode() const;

    void ActivateForPrerendering(const mojom::blink::PrerenderPageActivationParams& params);

    void AddWillDispatchPrerenderingchangeCallback(base::OnceClosure);

    void AddPostPrerenderingActivationStep(base::OnceClosure callback);

    class CORE_EXPORT PaintPreviewScope {
        STACK_ALLOCATED();

    public:
        PaintPreviewScope(Document& document, PaintPreviewState state);
        ~PaintPreviewScope();

        PaintPreviewScope(PaintPreviewScope&) = delete;
        PaintPreviewScope& operator=(PaintPreviewScope&) = delete;

    private:
        Document& document_;
    };

    bool IsDirAttributeDirty();
    void SetDirAttributeDirty();

    ResizeObserver& EnsureResizeObserver();

    void ObserveForIntrinsicSize(Element* element);
    void UnobserveForIntrinsicSize(Element* element);

    // Returns true if motion should be forcibly reduced in animations on this
    // document. This returns true if all of the following conditions are true:
    // 1. The user prefers reduced motion.
    // 2. The document does not contain a meta tag indicating it supports and uses
    //    prefers-reduced-motion media queries.
    // 3. The ForceReduceMotion feature is enabled.
    // For more details and explanation, see
    // https://github.com/flackr/reduce-motion/blob/main/explainer.md
    bool ShouldForceReduceMotion() const;

    void AddPendingLinkHeaderPreload(const PendingLinkPreload&);

    // Has no effect if the preload is not initiated by link header.
    void RemovePendingLinkHeaderPreloadIfNeeded(const PendingLinkPreload&);

    void WriteIntoTrace(perfetto::TracedValue ctx) const;

    // TODO(https://crbug.com/1296161): Delete this function.
    void CheckPartitionedCookiesOriginTrial(const ResourceResponse& response);

    void IncrementIgnoreDestructiveWriteModuleScriptCount();
    unsigned GetIgnoreDestructiveWriteModuleScriptCount();

protected:
    void ClearXMLVersion();

    virtual Document* CloneDocumentWithoutChildren() const;

    void LockCompatibilityMode();
    ParserSynchronizationPolicy GetParserSynchronizationPolicy() const;

    void OnAdoptedStyleSheetSet(ScriptState*, V8ObservableArrayCSSStyleSheet&, uint32_t, Member<CSSStyleSheet>&, ExceptionState&) override;
    void OnAdoptedStyleSheetDelete(ScriptState*, V8ObservableArrayCSSStyleSheet&, uint32_t, ExceptionState&) override;

private:
    friend class DocumentTest;
    friend class IgnoreDestructiveWriteCountIncrementer;
    friend class ThrowOnDynamicMarkupInsertionCountIncrementer;
    friend class IgnoreOpensDuringUnloadCountIncrementer;
    friend class NthIndexCache;
    friend class CheckPseudoHasCacheScope;
    friend class CanvasRenderingAPIUkmMetricsTest;
    friend class OffscreenCanvasRenderingAPIUkmMetricsTest;
    FRIEND_TEST_ALL_PREFIXES(LazyLoadAutomaticImagesTest, LoadAllImagesIfPrinting);
    FRIEND_TEST_ALL_PREFIXES(FrameFetchContextSubresourceFilterTest, DuringOnFreeze);
    FRIEND_TEST_ALL_PREFIXES(DocumentTest, FindInPageUkm);
    FRIEND_TEST_ALL_PREFIXES(DocumentTest, FindInPageUkmInFrame);
    FRIEND_TEST_ALL_PREFIXES(TextFinderSimTest, BeforeMatchExpandedHiddenMatchableUkm);
    FRIEND_TEST_ALL_PREFIXES(TextFinderSimTest, BeforeMatchExpandedHiddenMatchableUkmNoHandler);

    // Listed elements that are not associated to a <form> element.
    class UnassociatedListedElementsList {
        DISALLOW_NEW();

    public:
        void MarkDirty();
        const ListedElement::List& Get(const Document& owner);
        void Trace(Visitor*) const;

    private:
        ListedElement::List list_;
        // Set this flag if the stored unassociated listed elements were changed.
        bool dirty_ = false;
    };

    friend class AXContext;
    void AddAXContext(AXContext*);
    void RemoveAXContext(AXContext*);
    // Called when the AXMode of an existing AXContext changes.
    void AXContextModeChanged();

    bool IsDocumentFragment() const = delete;

    bool IsDocumentNode() const = delete; // This will catch anyone doing an unnecessary check.
    bool IsElementNode() const = delete; // This will catch anyone doing an unnecessary check.

    ScriptedIdleTaskController& EnsureScriptedIdleTaskController();

    bool HasPendingVisualUpdate() const;

    bool ShouldScheduleLayoutTreeUpdate() const;
    void ScheduleLayoutTreeUpdate();

    // See UpdateStyleAndLayoutTreeForThisDocument for an explanation of
    // the "ForThisDocument" suffix.
    //
    // These functions do not take into account dirtiness of parent frames:
    // they are assumed to be clean. If it isn't possible to guarantee
    // clean parent frames, use Needs[Full]LayoutTreeUpdate() instead.
    bool NeedsLayoutTreeUpdateForThisDocument() const
    {
        return CalculateStyleAndLayoutTreeUpdateForThisDocument() != StyleAndLayoutTreeUpdate::kNone;
    }

    StyleAndLayoutTreeUpdate CalculateStyleAndLayoutTreeUpdateForThisDocument() const;
    StyleAndLayoutTreeUpdate CalculateStyleAndLayoutTreeUpdateForParentFrame() const;

    void UpdateUseShadowTreesIfNeeded();
    void EvaluateMediaQueryListIfNeeded();

    void UpdateStyleInvalidationIfNeeded();
    void UpdateStyle();
    bool ChildrenCanHaveStyle() const final;

    // Objects and embeds depend on "being rendered" for delaying the load event.
    // This method unblocks the load event after the first layout tree update
    // after parsing finished.
    void UnblockLoadEventAfterLayoutTreeUpdate();

    // ImplicitClose() actually does the work of closing the input stream.
    void ImplicitClose();
    bool ShouldComplete();

    // Returns |true| if both document and its owning frame are still attached.
    // Any of them could be detached during the check, e.g. by calling
    // iframe.remove() from an event handler.
    bool CheckCompletedInternal();

    void DetachParser();

    void BeginLifecycleUpdatesIfRenderingReady();

    void ChildrenChanged(const ChildrenChange&) override;

    String nodeName() const final;
    bool ChildTypeAllowed(NodeType) const final;
    Node* Clone(Document&, CloneChildrenFlag) const override;
    void CloneDataFromDocument(const Document&);

    void UpdateTitle(const String&);
    void DispatchDidReceiveTitle();
    void UpdateSelectionAfterLayout();
    void UpdateBaseURL();

    void ExecuteScriptsWaitingForResources();
    void ExecuteJavaScriptUrls();

    enum class MilestoneForDelayedAsyncScript {
        kFirstPaint,
        kFinishedParsing,
        kLcpCandidate,
        kPaint,
    };
    void MaybeExecuteDelayedAsyncScripts(MilestoneForDelayedAsyncScript);

    void LoadEventDelayTimerFired(TimerBase*);
    void PluginLoadingTimerFired(TimerBase*);

    void AddListenerType(ListenerType listener_type);
    void AddMutationEventListenerTypeIfEnabled(ListenerType);

    void DidAssociateFormControlsTimerFired(TimerBase*);

    void ClearFocusedElementTimerFired(TimerBase*);

    bool HaveScriptBlockingStylesheetsLoaded() const;

    void SetHoverElement(Element*);

    using EventFactorySet = HashSet<std::unique_ptr<EventFactoryBase>>;
    static EventFactorySet& EventFactories();

    void SetNthIndexCache(NthIndexCache* nth_index_cache);

    void SetCheckPseudoHasCacheScope(CheckPseudoHasCacheScope* check_pseudo_has_cache_scope);

    void UpdateActiveState(bool is_active, bool update_active_chain, Element*);
    void UpdateHoverState(Element*);

    const AtomicString& BodyAttributeValue(const QualifiedName&) const;
    void SetBodyAttribute(const QualifiedName&, const AtomicString&);

    // Returns true if use of |method_name| for markup insertion is allowed by
    // permissions policy; otherwise returns false and throws a DOM exception.
    bool AllowedToUseDynamicMarkUpInsertion(const char* method_name, ExceptionState&);

    void SetFreezingInProgress(bool is_freezing_in_progress);

    void NotifyFocusedElementChanged(Element* old_focused_element, Element* new_focused_element, mojom::blink::FocusType focus_type);
    void DisplayNoneChangedForFrame();

    // Handles a connection error to |trust_token_query_answerer_| by rejecting
    // all pending promises created by |hasTrustToken| and |hasRedemptionRecord|.
    void TrustTokenQueryAnswererConnectionError();

    void RunPostPrerenderingActivationSteps();

    // const DocumentToken token_;
    HeapVector<Member<ScriptElementBase>> current_script_stack_;
    HeapVector2<Member<ScriptElementBase>> current_script_stack2_;
};

// extern template class CORE_EXTERN_TEMPLATE_EXPORT Supplement<Document>;
//
// inline void Document::ScheduleLayoutTreeUpdateIfNeeded() {
//   // Inline early out to avoid the function calls below.
//   if (HasPendingVisualUpdate())
//     return;
//   if (ShouldScheduleLayoutTreeUpdate() && NeedsLayoutTreeUpdate())
//     ScheduleLayoutTreeUpdate();
// }

// This is needed to avoid ambiguous overloads with the Node and TreeScope
// versions.
DEFINE_COMPARISON_OPERATORS_WITH_REFERENCES(Document)
//
// // Put these methods here, because they require the Document definition, but we
// // really want to inline them.
//
// inline bool Node::IsDocumentNode() const {
//   return this == GetDocument();
// }
//
// Node* EventTargetNodeForDocument(Document*);
//
// template <>
// struct DowncastTraits<Document> {
//   static bool AllowFrom(const Node& node) { return node.IsDocumentNode(); }
// };

} // namespace blink

#ifndef NDEBUG
// Outside the blink namespace for ease of invocation from gdb.
CORE_EXPORT void ShowLiveDocumentInstances();
#endif

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_DOM_DOCUMENT_H_
