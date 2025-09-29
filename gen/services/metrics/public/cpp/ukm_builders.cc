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


// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#include "services/metrics/public/cpp/ukm_builders.h"

namespace ukm {
namespace builders {
const char AboutThisSiteStatus::kEntryName[] = "AboutThisSiteStatus";
const uint64_t AboutThisSiteStatus::kEntryNameHash;

AboutThisSiteStatus::AboutThisSiteStatus(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AboutThisSiteStatus::AboutThisSiteStatus(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AboutThisSiteStatus::~AboutThisSiteStatus() = default;
const char AboutThisSiteStatus::kStatusName[] = "Status";
const uint64_t AboutThisSiteStatus::kStatusNameHash;

AboutThisSiteStatus& AboutThisSiteStatus::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}
const char AbusiveExperienceHeuristic::kEntryName[] = "AbusiveExperienceHeuristic";
const uint64_t AbusiveExperienceHeuristic::kEntryNameHash;

AbusiveExperienceHeuristic::AbusiveExperienceHeuristic(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic::AbusiveExperienceHeuristic(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic::~AbusiveExperienceHeuristic() = default;
const char AbusiveExperienceHeuristic::kDidTabUnderName[] = "DidTabUnder";
const uint64_t AbusiveExperienceHeuristic::kDidTabUnderNameHash;

AbusiveExperienceHeuristic& AbusiveExperienceHeuristic::SetDidTabUnder(int64_t value)
{
    SetMetricInternal(kDidTabUnderNameHash, value);
    return *this;
}

const char AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptName[] = "DidWindowOpenFromAdScript";
const uint64_t AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptNameHash;

AbusiveExperienceHeuristic& AbusiveExperienceHeuristic::SetDidWindowOpenFromAdScript(int64_t value)
{
    SetMetricInternal(kDidWindowOpenFromAdScriptNameHash, value);
    return *this;
}

const char AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeName[] = "DidWindowOpenFromAdSubframe";
const uint64_t AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeNameHash;

AbusiveExperienceHeuristic& AbusiveExperienceHeuristic::SetDidWindowOpenFromAdSubframe(int64_t value)
{
    SetMetricInternal(kDidWindowOpenFromAdSubframeNameHash, value);
    return *this;
}
const char AbusiveExperienceHeuristic_JavaScriptDialog::kEntryName[] = "AbusiveExperienceHeuristic.JavaScriptDialog";
const uint64_t AbusiveExperienceHeuristic_JavaScriptDialog::kEntryNameHash;

AbusiveExperienceHeuristic_JavaScriptDialog::AbusiveExperienceHeuristic_JavaScriptDialog(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_JavaScriptDialog::AbusiveExperienceHeuristic_JavaScriptDialog(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_JavaScriptDialog::~AbusiveExperienceHeuristic_JavaScriptDialog() = default;
const char AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseName[] = "DismissalCause";
const uint64_t AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseNameHash;

AbusiveExperienceHeuristic_JavaScriptDialog& AbusiveExperienceHeuristic_JavaScriptDialog::SetDismissalCause(int64_t value)
{
    SetMetricInternal(kDismissalCauseNameHash, value);
    return *this;
}
const char AbusiveExperienceHeuristic_TabUnder::kEntryName[] = "AbusiveExperienceHeuristic.TabUnder";
const uint64_t AbusiveExperienceHeuristic_TabUnder::kEntryNameHash;

AbusiveExperienceHeuristic_TabUnder::AbusiveExperienceHeuristic_TabUnder(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_TabUnder::AbusiveExperienceHeuristic_TabUnder(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_TabUnder::~AbusiveExperienceHeuristic_TabUnder() = default;
const char AbusiveExperienceHeuristic_TabUnder::kDidTabUnderName[] = "DidTabUnder";
const uint64_t AbusiveExperienceHeuristic_TabUnder::kDidTabUnderNameHash;

AbusiveExperienceHeuristic_TabUnder& AbusiveExperienceHeuristic_TabUnder::SetDidTabUnder(int64_t value)
{
    SetMetricInternal(kDidTabUnderNameHash, value);
    return *this;
}
const char AbusiveExperienceHeuristic_WindowOpen::kEntryName[] = "AbusiveExperienceHeuristic.WindowOpen";
const uint64_t AbusiveExperienceHeuristic_WindowOpen::kEntryNameHash;

AbusiveExperienceHeuristic_WindowOpen::AbusiveExperienceHeuristic_WindowOpen(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_WindowOpen::AbusiveExperienceHeuristic_WindowOpen(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AbusiveExperienceHeuristic_WindowOpen::~AbusiveExperienceHeuristic_WindowOpen() = default;
const char AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptName[] = "FromAdScript";
const uint64_t AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptNameHash;

AbusiveExperienceHeuristic_WindowOpen& AbusiveExperienceHeuristic_WindowOpen::SetFromAdScript(int64_t value)
{
    SetMetricInternal(kFromAdScriptNameHash, value);
    return *this;
}

const char AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeName[] = "FromAdSubframe";
const uint64_t AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeNameHash;

AbusiveExperienceHeuristic_WindowOpen& AbusiveExperienceHeuristic_WindowOpen::SetFromAdSubframe(int64_t value)
{
    SetMetricInternal(kFromAdSubframeNameHash, value);
    return *this;
}
const char Accessibility_ImageDescriptions::kEntryName[] = "Accessibility.ImageDescriptions";
const uint64_t Accessibility_ImageDescriptions::kEntryNameHash;

Accessibility_ImageDescriptions::Accessibility_ImageDescriptions(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Accessibility_ImageDescriptions::Accessibility_ImageDescriptions(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Accessibility_ImageDescriptions::~Accessibility_ImageDescriptions() = default;
const char Accessibility_ImageDescriptions::kDescriptionName[] = "Description";
const uint64_t Accessibility_ImageDescriptions::kDescriptionNameHash;

Accessibility_ImageDescriptions& Accessibility_ImageDescriptions::SetDescription(int64_t value)
{
    SetMetricInternal(kDescriptionNameHash, value);
    return *this;
}

const char Accessibility_ImageDescriptions::kImageAlreadyHasLabelName[] = "ImageAlreadyHasLabel";
const uint64_t Accessibility_ImageDescriptions::kImageAlreadyHasLabelNameHash;

Accessibility_ImageDescriptions& Accessibility_ImageDescriptions::SetImageAlreadyHasLabel(int64_t value)
{
    SetMetricInternal(kImageAlreadyHasLabelNameHash, value);
    return *this;
}

const char Accessibility_ImageDescriptions::kOCRName[] = "OCR";
const uint64_t Accessibility_ImageDescriptions::kOCRNameHash;

Accessibility_ImageDescriptions& Accessibility_ImageDescriptions::SetOCR(int64_t value)
{
    SetMetricInternal(kOCRNameHash, value);
    return *this;
}
const char Accessibility_Renderer::kEntryName[] = "Accessibility.Renderer";
const uint64_t Accessibility_Renderer::kEntryNameHash;

Accessibility_Renderer::Accessibility_Renderer(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Accessibility_Renderer::Accessibility_Renderer(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Accessibility_Renderer::~Accessibility_Renderer() = default;
const char Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsName[] = "CpuTime.SendPendingAccessibilityEvents";
const uint64_t Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsNameHash;

Accessibility_Renderer& Accessibility_Renderer::SetCpuTime_SendPendingAccessibilityEvents(int64_t value)
{
    SetMetricInternal(kCpuTime_SendPendingAccessibilityEventsNameHash, value);
    return *this;
}
const char AccuracyTipDialog::kEntryName[] = "AccuracyTipDialog";
const uint64_t AccuracyTipDialog::kEntryNameHash;

AccuracyTipDialog::AccuracyTipDialog(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AccuracyTipDialog::AccuracyTipDialog(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AccuracyTipDialog::~AccuracyTipDialog() = default;
const char AccuracyTipDialog::kInteractionName[] = "Interaction";
const uint64_t AccuracyTipDialog::kInteractionNameHash;

AccuracyTipDialog& AccuracyTipDialog::SetInteraction(int64_t value)
{
    SetMetricInternal(kInteractionNameHash, value);
    return *this;
}

const char AccuracyTipDialog::kTimeSpentName[] = "TimeSpent";
const uint64_t AccuracyTipDialog::kTimeSpentNameHash;

AccuracyTipDialog& AccuracyTipDialog::SetTimeSpent(int64_t value)
{
    SetMetricInternal(kTimeSpentNameHash, value);
    return *this;
}
const char AccuracyTipStatus::kEntryName[] = "AccuracyTipStatus";
const uint64_t AccuracyTipStatus::kEntryNameHash;

AccuracyTipStatus::AccuracyTipStatus(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AccuracyTipStatus::AccuracyTipStatus(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AccuracyTipStatus::~AccuracyTipStatus() = default;
const char AccuracyTipStatus::kStatusName[] = "Status";
const uint64_t AccuracyTipStatus::kStatusNameHash;

AccuracyTipStatus& AccuracyTipStatus::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}
const char AdFrameLoad::kEntryName[] = "AdFrameLoad";
const uint64_t AdFrameLoad::kEntryNameHash;

AdFrameLoad::AdFrameLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdFrameLoad::AdFrameLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdFrameLoad::~AdFrameLoad() = default;
const char AdFrameLoad::kCpuTime_PeakWindowedPercentName[] = "CpuTime.PeakWindowedPercent";
const uint64_t AdFrameLoad::kCpuTime_PeakWindowedPercentNameHash;

AdFrameLoad& AdFrameLoad::SetCpuTime_PeakWindowedPercent(int64_t value)
{
    SetMetricInternal(kCpuTime_PeakWindowedPercentNameHash, value);
    return *this;
}

const char AdFrameLoad::kCpuTime_PreActivationName[] = "CpuTime.PreActivation";
const uint64_t AdFrameLoad::kCpuTime_PreActivationNameHash;

AdFrameLoad& AdFrameLoad::SetCpuTime_PreActivation(int64_t value)
{
    SetMetricInternal(kCpuTime_PreActivationNameHash, value);
    return *this;
}

const char AdFrameLoad::kCpuTime_TotalName[] = "CpuTime.Total";
const uint64_t AdFrameLoad::kCpuTime_TotalNameHash;

AdFrameLoad& AdFrameLoad::SetCpuTime_Total(int64_t value)
{
    SetMetricInternal(kCpuTime_TotalNameHash, value);
    return *this;
}

const char AdFrameLoad::kFrameDepthName[] = "FrameDepth";
const uint64_t AdFrameLoad::kFrameDepthNameHash;

AdFrameLoad& AdFrameLoad::SetFrameDepth(int64_t value)
{
    SetMetricInternal(kFrameDepthNameHash, value);
    return *this;
}

const char AdFrameLoad::kLoading_CacheBytes2Name[] = "Loading.CacheBytes2";
const uint64_t AdFrameLoad::kLoading_CacheBytes2NameHash;

AdFrameLoad& AdFrameLoad::SetLoading_CacheBytes2(int64_t value)
{
    SetMetricInternal(kLoading_CacheBytes2NameHash, value);
    return *this;
}

const char AdFrameLoad::kLoading_ImageBytesName[] = "Loading.ImageBytes";
const uint64_t AdFrameLoad::kLoading_ImageBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_ImageBytes(int64_t value)
{
    SetMetricInternal(kLoading_ImageBytesNameHash, value);
    return *this;
}

const char AdFrameLoad::kLoading_JavascriptBytesName[] = "Loading.JavascriptBytes";
const uint64_t AdFrameLoad::kLoading_JavascriptBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_JavascriptBytes(int64_t value)
{
    SetMetricInternal(kLoading_JavascriptBytesNameHash, value);
    return *this;
}

const char AdFrameLoad::kLoading_NetworkBytesName[] = "Loading.NetworkBytes";
const uint64_t AdFrameLoad::kLoading_NetworkBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_NetworkBytes(int64_t value)
{
    SetMetricInternal(kLoading_NetworkBytesNameHash, value);
    return *this;
}

const char AdFrameLoad::kLoading_NumResourcesName[] = "Loading.NumResources";
const uint64_t AdFrameLoad::kLoading_NumResourcesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_NumResources(int64_t value)
{
    SetMetricInternal(kLoading_NumResourcesNameHash, value);
    return *this;
}

const char AdFrameLoad::kLoading_VideoBytesName[] = "Loading.VideoBytes";
const uint64_t AdFrameLoad::kLoading_VideoBytesNameHash;

AdFrameLoad& AdFrameLoad::SetLoading_VideoBytes(int64_t value)
{
    SetMetricInternal(kLoading_VideoBytesNameHash, value);
    return *this;
}

const char AdFrameLoad::kStatus_CrossOriginName[] = "Status.CrossOrigin";
const uint64_t AdFrameLoad::kStatus_CrossOriginNameHash;

AdFrameLoad& AdFrameLoad::SetStatus_CrossOrigin(int64_t value)
{
    SetMetricInternal(kStatus_CrossOriginNameHash, value);
    return *this;
}

const char AdFrameLoad::kStatus_MediaName[] = "Status.Media";
const uint64_t AdFrameLoad::kStatus_MediaNameHash;

AdFrameLoad& AdFrameLoad::SetStatus_Media(int64_t value)
{
    SetMetricInternal(kStatus_MediaNameHash, value);
    return *this;
}

const char AdFrameLoad::kStatus_UserActivationName[] = "Status.UserActivation";
const uint64_t AdFrameLoad::kStatus_UserActivationNameHash;

AdFrameLoad& AdFrameLoad::SetStatus_UserActivation(int64_t value)
{
    SetMetricInternal(kStatus_UserActivationNameHash, value);
    return *this;
}

const char AdFrameLoad::kTiming_FirstContentfulPaintName[] = "Timing.FirstContentfulPaint";
const uint64_t AdFrameLoad::kTiming_FirstContentfulPaintNameHash;

AdFrameLoad& AdFrameLoad::SetTiming_FirstContentfulPaint(int64_t value)
{
    SetMetricInternal(kTiming_FirstContentfulPaintNameHash, value);
    return *this;
}

const char AdFrameLoad::kTiming_InteractiveName[] = "Timing.Interactive";
const uint64_t AdFrameLoad::kTiming_InteractiveNameHash;

AdFrameLoad& AdFrameLoad::SetTiming_Interactive(int64_t value)
{
    SetMetricInternal(kTiming_InteractiveNameHash, value);
    return *this;
}

const char AdFrameLoad::kVisibility_FrameHeightName[] = "Visibility.FrameHeight";
const uint64_t AdFrameLoad::kVisibility_FrameHeightNameHash;

AdFrameLoad& AdFrameLoad::SetVisibility_FrameHeight(int64_t value)
{
    SetMetricInternal(kVisibility_FrameHeightNameHash, value);
    return *this;
}

const char AdFrameLoad::kVisibility_FrameWidthName[] = "Visibility.FrameWidth";
const uint64_t AdFrameLoad::kVisibility_FrameWidthNameHash;

AdFrameLoad& AdFrameLoad::SetVisibility_FrameWidth(int64_t value)
{
    SetMetricInternal(kVisibility_FrameWidthNameHash, value);
    return *this;
}

const char AdFrameLoad::kVisibility_HiddenName[] = "Visibility.Hidden";
const uint64_t AdFrameLoad::kVisibility_HiddenNameHash;

AdFrameLoad& AdFrameLoad::SetVisibility_Hidden(int64_t value)
{
    SetMetricInternal(kVisibility_HiddenNameHash, value);
    return *this;
}
const char AdPageLoad::kEntryName[] = "AdPageLoad";
const uint64_t AdPageLoad::kEntryNameHash;

AdPageLoad::AdPageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdPageLoad::AdPageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdPageLoad::~AdPageLoad() = default;
const char AdPageLoad::kAdBytesName[] = "AdBytes";
const uint64_t AdPageLoad::kAdBytesNameHash;

AdPageLoad& AdPageLoad::SetAdBytes(int64_t value)
{
    SetMetricInternal(kAdBytesNameHash, value);
    return *this;
}

const char AdPageLoad::kAdCpuTimeName[] = "AdCpuTime";
const uint64_t AdPageLoad::kAdCpuTimeNameHash;

AdPageLoad& AdPageLoad::SetAdCpuTime(int64_t value)
{
    SetMetricInternal(kAdCpuTimeNameHash, value);
    return *this;
}

const char AdPageLoad::kAdJavascriptBytesName[] = "AdJavascriptBytes";
const uint64_t AdPageLoad::kAdJavascriptBytesNameHash;

AdPageLoad& AdPageLoad::SetAdJavascriptBytes(int64_t value)
{
    SetMetricInternal(kAdJavascriptBytesNameHash, value);
    return *this;
}

const char AdPageLoad::kAdVideoBytesName[] = "AdVideoBytes";
const uint64_t AdPageLoad::kAdVideoBytesNameHash;

AdPageLoad& AdPageLoad::SetAdVideoBytes(int64_t value)
{
    SetMetricInternal(kAdVideoBytesNameHash, value);
    return *this;
}

const char AdPageLoad::kMainframeAdBytesName[] = "MainframeAdBytes";
const uint64_t AdPageLoad::kMainframeAdBytesNameHash;

AdPageLoad& AdPageLoad::SetMainframeAdBytes(int64_t value)
{
    SetMetricInternal(kMainframeAdBytesNameHash, value);
    return *this;
}

const char AdPageLoad::kMaxAdDensityByAreaName[] = "MaxAdDensityByArea";
const uint64_t AdPageLoad::kMaxAdDensityByAreaNameHash;

AdPageLoad& AdPageLoad::SetMaxAdDensityByArea(int64_t value)
{
    SetMetricInternal(kMaxAdDensityByAreaNameHash, value);
    return *this;
}

const char AdPageLoad::kMaxAdDensityByHeightName[] = "MaxAdDensityByHeight";
const uint64_t AdPageLoad::kMaxAdDensityByHeightNameHash;

AdPageLoad& AdPageLoad::SetMaxAdDensityByHeight(int64_t value)
{
    SetMetricInternal(kMaxAdDensityByHeightNameHash, value);
    return *this;
}

const char AdPageLoad::kTotalBytesName[] = "TotalBytes";
const uint64_t AdPageLoad::kTotalBytesNameHash;

AdPageLoad& AdPageLoad::SetTotalBytes(int64_t value)
{
    SetMetricInternal(kTotalBytesNameHash, value);
    return *this;
}
const char AdPageLoadCustomSampling2::kEntryName[] = "AdPageLoadCustomSampling2";
const uint64_t AdPageLoadCustomSampling2::kEntryNameHash;

AdPageLoadCustomSampling2::AdPageLoadCustomSampling2(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdPageLoadCustomSampling2::AdPageLoadCustomSampling2(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdPageLoadCustomSampling2::~AdPageLoadCustomSampling2() = default;
const char AdPageLoadCustomSampling2::kAverageViewportAdDensityName[] = "AverageViewportAdDensity";
const uint64_t AdPageLoadCustomSampling2::kAverageViewportAdDensityNameHash;

AdPageLoadCustomSampling2& AdPageLoadCustomSampling2::SetAverageViewportAdDensity(int64_t value)
{
    SetMetricInternal(kAverageViewportAdDensityNameHash, value);
    return *this;
}

const char AdPageLoadCustomSampling2::kKurtosisViewportAdDensityName[] = "KurtosisViewportAdDensity";
const uint64_t AdPageLoadCustomSampling2::kKurtosisViewportAdDensityNameHash;

AdPageLoadCustomSampling2& AdPageLoadCustomSampling2::SetKurtosisViewportAdDensity(int64_t value)
{
    SetMetricInternal(kKurtosisViewportAdDensityNameHash, value);
    return *this;
}

const char AdPageLoadCustomSampling2::kSkewnessViewportAdDensityName[] = "SkewnessViewportAdDensity";
const uint64_t AdPageLoadCustomSampling2::kSkewnessViewportAdDensityNameHash;

AdPageLoadCustomSampling2& AdPageLoadCustomSampling2::SetSkewnessViewportAdDensity(int64_t value)
{
    SetMetricInternal(kSkewnessViewportAdDensityNameHash, value);
    return *this;
}

const char AdPageLoadCustomSampling2::kVarianceViewportAdDensityName[] = "VarianceViewportAdDensity";
const uint64_t AdPageLoadCustomSampling2::kVarianceViewportAdDensityNameHash;

AdPageLoadCustomSampling2& AdPageLoadCustomSampling2::SetVarianceViewportAdDensity(int64_t value)
{
    SetMetricInternal(kVarianceViewportAdDensityNameHash, value);
    return *this;
}
const char AdsIntervention_LastIntervention::kEntryName[] = "AdsIntervention.LastIntervention";
const uint64_t AdsIntervention_LastIntervention::kEntryNameHash;

AdsIntervention_LastIntervention::AdsIntervention_LastIntervention(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdsIntervention_LastIntervention::AdsIntervention_LastIntervention(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AdsIntervention_LastIntervention::~AdsIntervention_LastIntervention() = default;
const char AdsIntervention_LastIntervention::kInterventionStatusName[] = "InterventionStatus";
const uint64_t AdsIntervention_LastIntervention::kInterventionStatusNameHash;

AdsIntervention_LastIntervention& AdsIntervention_LastIntervention::SetInterventionStatus(int64_t value)
{
    SetMetricInternal(kInterventionStatusNameHash, value);
    return *this;
}

const char AdsIntervention_LastIntervention::kInterventionTypeName[] = "InterventionType";
const uint64_t AdsIntervention_LastIntervention::kInterventionTypeNameHash;

AdsIntervention_LastIntervention& AdsIntervention_LastIntervention::SetInterventionType(int64_t value)
{
    SetMetricInternal(kInterventionTypeNameHash, value);
    return *this;
}
const char AmpPageLoad::kEntryName[] = "AmpPageLoad";
const uint64_t AmpPageLoad::kEntryNameHash;

AmpPageLoad::AmpPageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AmpPageLoad::AmpPageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AmpPageLoad::~AmpPageLoad() = default;
const char AmpPageLoad::kMainFrameAmpPageLoadName[] = "MainFrameAmpPageLoad";
const uint64_t AmpPageLoad::kMainFrameAmpPageLoadNameHash;

AmpPageLoad& AmpPageLoad::SetMainFrameAmpPageLoad(int64_t value)
{
    SetMetricInternal(kMainFrameAmpPageLoadNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration2Name[]
    = "SubFrame.InteractiveTiming.AverageUserInteractionLatencyOverBudget.MaxEventDuration2";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration2NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration2NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4Name[] = "SubFrame.InteractiveTiming.FirstInputDelay4";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_FirstInputDelay4(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_FirstInputDelay4NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_NumInteractionsName[] = "SubFrame.InteractiveTiming.NumInteractions";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_NumInteractionsNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_NumInteractions(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_NumInteractionsNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration2Name[]
    = "SubFrame.InteractiveTiming.SlowUserInteractionLatencyOverBudget.HighPercentile2.MaxEventDuration2";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration2NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration2NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration2Name[]
    = "SubFrame.InteractiveTiming.SumOfUserInteractionLatencyOverBudget.MaxEventDuration2";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration2NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration2NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[]
    = "SubFrame.InteractiveTiming.UserInteractionLatency.HighPercentile2.MaxEventDuration";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2Name[]
    = "SubFrame.InteractiveTiming.WorstUserInteractionLatency.MaxEventDuration2";
const uint64_t AmpPageLoad::kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreName[] = "SubFrame.LayoutInstability.CumulativeShiftScore";
const uint64_t AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_LayoutInstability_CumulativeShiftScore(int64_t value)
{
    SetMetricInternal(kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName[] = "SubFrame.LayoutInstability.CumulativeShiftScore.BeforeInputOrScroll";
const uint64_t AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScroll(int64_t value)
{
    SetMetricInternal(kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[]
    = "SubFrame.LayoutInstability.MaxCumulativeShiftScore.SessionWindow.Gap1000ms.Max5000ms";
const uint64_t AmpPageLoad::kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value)
{
    SetMetricInternal(kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaName[] = "SubFrame.MainFrameToSubFrameNavigationDelta";
const uint64_t AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MainFrameToSubFrameNavigationDelta(int64_t value)
{
    SetMetricInternal(kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_AllowUserZoomName[] = "SubFrame.MobileFriendliness.AllowUserZoom";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_AllowUserZoomNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_AllowUserZoom(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_AllowUserZoomNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_BadTapTargetsRatioName[] = "SubFrame.MobileFriendliness.BadTapTargetsRatio";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_BadTapTargetsRatioNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_BadTapTargetsRatio(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_BadTapTargetsRatioNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_SmallTextRatioName[] = "SubFrame.MobileFriendliness.SmallTextRatio";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_SmallTextRatioNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_SmallTextRatio(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_SmallTextRatioNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_TextContentOutsideViewportPercentageName[] = "SubFrame.MobileFriendliness.TextContentOutsideViewportPercentage";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_TextContentOutsideViewportPercentageNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_TextContentOutsideViewportPercentage(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_TextContentOutsideViewportPercentageNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_ViewportDeviceWidthName[] = "SubFrame.MobileFriendliness.ViewportDeviceWidth";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_ViewportDeviceWidthNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_ViewportDeviceWidth(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_ViewportDeviceWidthNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_ViewportHardcodedWidthName[] = "SubFrame.MobileFriendliness.ViewportHardcodedWidth";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_ViewportHardcodedWidthNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_ViewportHardcodedWidth(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_ViewportHardcodedWidthNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_MobileFriendliness_ViewportInitialScaleX10Name[] = "SubFrame.MobileFriendliness.ViewportInitialScaleX10";
const uint64_t AmpPageLoad::kSubFrame_MobileFriendliness_ViewportInitialScaleX10NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_MobileFriendliness_ViewportInitialScaleX10(int64_t value)
{
    SetMetricInternal(kSubFrame_MobileFriendliness_ViewportInitialScaleX10NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName[] = "SubFrame.PaintTiming.NavigationToFirstContentfulPaint";
const uint64_t AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_PaintTiming_NavigationToFirstContentfulPaint(int64_t value)
{
    SetMetricInternal(kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstPaintName[] = "SubFrame.PaintTiming.NavigationToFirstPaint";
const uint64_t AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstPaintNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_PaintTiming_NavigationToFirstPaint(int64_t value)
{
    SetMetricInternal(kSubFrame_PaintTiming_NavigationToFirstPaintNameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2Name[] = "SubFrame.PaintTiming.NavigationToLargestContentfulPaint2";
const uint64_t AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2NameHash;

AmpPageLoad& AmpPageLoad::SetSubFrame_PaintTiming_NavigationToLargestContentfulPaint2(int64_t value)
{
    SetMetricInternal(kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2NameHash, value);
    return *this;
}

const char AmpPageLoad::kSubFrameAmpPageLoadName[] = "SubFrameAmpPageLoad";
const uint64_t AmpPageLoad::kSubFrameAmpPageLoadNameHash;

AmpPageLoad& AmpPageLoad::SetSubFrameAmpPageLoad(int64_t value)
{
    SetMetricInternal(kSubFrameAmpPageLoadNameHash, value);
    return *this;
}
const char Android_DarkTheme_AutoDarkMode::kEntryName[] = "Android.DarkTheme.AutoDarkMode";
const uint64_t Android_DarkTheme_AutoDarkMode::kEntryNameHash;

Android_DarkTheme_AutoDarkMode::Android_DarkTheme_AutoDarkMode(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_DarkTheme_AutoDarkMode::Android_DarkTheme_AutoDarkMode(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_DarkTheme_AutoDarkMode::~Android_DarkTheme_AutoDarkMode() = default;
const char Android_DarkTheme_AutoDarkMode::kDisabledByUserName[] = "DisabledByUser";
const uint64_t Android_DarkTheme_AutoDarkMode::kDisabledByUserNameHash;

Android_DarkTheme_AutoDarkMode& Android_DarkTheme_AutoDarkMode::SetDisabledByUser(int64_t value)
{
    SetMetricInternal(kDisabledByUserNameHash, value);
    return *this;
}
const char Android_MultiWindowChangeActivity::kEntryName[] = "Android.MultiWindowChangeActivity";
const uint64_t Android_MultiWindowChangeActivity::kEntryNameHash;

Android_MultiWindowChangeActivity::Android_MultiWindowChangeActivity(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_MultiWindowChangeActivity::Android_MultiWindowChangeActivity(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_MultiWindowChangeActivity::~Android_MultiWindowChangeActivity() = default;
const char Android_MultiWindowChangeActivity::kActivityTypeName[] = "ActivityType";
const uint64_t Android_MultiWindowChangeActivity::kActivityTypeNameHash;

Android_MultiWindowChangeActivity& Android_MultiWindowChangeActivity::SetActivityType(int64_t value)
{
    SetMetricInternal(kActivityTypeNameHash, value);
    return *this;
}
const char Android_MultiWindowState::kEntryName[] = "Android.MultiWindowState";
const uint64_t Android_MultiWindowState::kEntryNameHash;

Android_MultiWindowState::Android_MultiWindowState(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_MultiWindowState::Android_MultiWindowState(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_MultiWindowState::~Android_MultiWindowState() = default;
const char Android_MultiWindowState::kWindowStateName[] = "WindowState";
const uint64_t Android_MultiWindowState::kWindowStateNameHash;

Android_MultiWindowState& Android_MultiWindowState::SetWindowState(int64_t value)
{
    SetMetricInternal(kWindowStateNameHash, value);
    return *this;
}
const char Android_ScreenRotation::kEntryName[] = "Android.ScreenRotation";
const uint64_t Android_ScreenRotation::kEntryNameHash;

Android_ScreenRotation::Android_ScreenRotation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_ScreenRotation::Android_ScreenRotation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_ScreenRotation::~Android_ScreenRotation() = default;
const char Android_ScreenRotation::kTargetDeviceOrientationName[] = "TargetDeviceOrientation";
const uint64_t Android_ScreenRotation::kTargetDeviceOrientationNameHash;

Android_ScreenRotation& Android_ScreenRotation::SetTargetDeviceOrientation(int64_t value)
{
    SetMetricInternal(kTargetDeviceOrientationNameHash, value);
    return *this;
}
const char Android_UserRequestedUserAgentChange::kEntryName[] = "Android.UserRequestedUserAgentChange";
const uint64_t Android_UserRequestedUserAgentChange::kEntryNameHash;

Android_UserRequestedUserAgentChange::Android_UserRequestedUserAgentChange(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_UserRequestedUserAgentChange::Android_UserRequestedUserAgentChange(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Android_UserRequestedUserAgentChange::~Android_UserRequestedUserAgentChange() = default;
const char Android_UserRequestedUserAgentChange::kUserAgentTypeName[] = "UserAgentType";
const uint64_t Android_UserRequestedUserAgentChange::kUserAgentTypeNameHash;

Android_UserRequestedUserAgentChange& Android_UserRequestedUserAgentChange::SetUserAgentType(int64_t value)
{
    SetMetricInternal(kUserAgentTypeNameHash, value);
    return *this;
}
const char AppListAppClickData::kEntryName[] = "AppListAppClickData";
const uint64_t AppListAppClickData::kEntryNameHash;

AppListAppClickData::AppListAppClickData(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AppListAppClickData::AppListAppClickData(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AppListAppClickData::~AppListAppClickData() = default;
const char AppListAppClickData::kAppLaunchIdName[] = "AppLaunchId";
const uint64_t AppListAppClickData::kAppLaunchIdNameHash;

AppListAppClickData& AppListAppClickData::SetAppLaunchId(int64_t value)
{
    SetMetricInternal(kAppLaunchIdNameHash, value);
    return *this;
}

const char AppListAppClickData::kAppTypeName[] = "AppType";
const uint64_t AppListAppClickData::kAppTypeNameHash;

AppListAppClickData& AppListAppClickData::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char AppListAppClickData::kClickRankName[] = "ClickRank";
const uint64_t AppListAppClickData::kClickRankNameHash;

AppListAppClickData& AppListAppClickData::SetClickRank(int64_t value)
{
    SetMetricInternal(kClickRankNameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour00Name[] = "ClicksEachHour00";
const uint64_t AppListAppClickData::kClicksEachHour00NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour00(int64_t value)
{
    SetMetricInternal(kClicksEachHour00NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour01Name[] = "ClicksEachHour01";
const uint64_t AppListAppClickData::kClicksEachHour01NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour01(int64_t value)
{
    SetMetricInternal(kClicksEachHour01NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour02Name[] = "ClicksEachHour02";
const uint64_t AppListAppClickData::kClicksEachHour02NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour02(int64_t value)
{
    SetMetricInternal(kClicksEachHour02NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour03Name[] = "ClicksEachHour03";
const uint64_t AppListAppClickData::kClicksEachHour03NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour03(int64_t value)
{
    SetMetricInternal(kClicksEachHour03NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour04Name[] = "ClicksEachHour04";
const uint64_t AppListAppClickData::kClicksEachHour04NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour04(int64_t value)
{
    SetMetricInternal(kClicksEachHour04NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour05Name[] = "ClicksEachHour05";
const uint64_t AppListAppClickData::kClicksEachHour05NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour05(int64_t value)
{
    SetMetricInternal(kClicksEachHour05NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour06Name[] = "ClicksEachHour06";
const uint64_t AppListAppClickData::kClicksEachHour06NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour06(int64_t value)
{
    SetMetricInternal(kClicksEachHour06NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour07Name[] = "ClicksEachHour07";
const uint64_t AppListAppClickData::kClicksEachHour07NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour07(int64_t value)
{
    SetMetricInternal(kClicksEachHour07NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour08Name[] = "ClicksEachHour08";
const uint64_t AppListAppClickData::kClicksEachHour08NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour08(int64_t value)
{
    SetMetricInternal(kClicksEachHour08NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour09Name[] = "ClicksEachHour09";
const uint64_t AppListAppClickData::kClicksEachHour09NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour09(int64_t value)
{
    SetMetricInternal(kClicksEachHour09NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour10Name[] = "ClicksEachHour10";
const uint64_t AppListAppClickData::kClicksEachHour10NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour10(int64_t value)
{
    SetMetricInternal(kClicksEachHour10NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour11Name[] = "ClicksEachHour11";
const uint64_t AppListAppClickData::kClicksEachHour11NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour11(int64_t value)
{
    SetMetricInternal(kClicksEachHour11NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour12Name[] = "ClicksEachHour12";
const uint64_t AppListAppClickData::kClicksEachHour12NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour12(int64_t value)
{
    SetMetricInternal(kClicksEachHour12NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour13Name[] = "ClicksEachHour13";
const uint64_t AppListAppClickData::kClicksEachHour13NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour13(int64_t value)
{
    SetMetricInternal(kClicksEachHour13NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour14Name[] = "ClicksEachHour14";
const uint64_t AppListAppClickData::kClicksEachHour14NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour14(int64_t value)
{
    SetMetricInternal(kClicksEachHour14NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour15Name[] = "ClicksEachHour15";
const uint64_t AppListAppClickData::kClicksEachHour15NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour15(int64_t value)
{
    SetMetricInternal(kClicksEachHour15NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour16Name[] = "ClicksEachHour16";
const uint64_t AppListAppClickData::kClicksEachHour16NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour16(int64_t value)
{
    SetMetricInternal(kClicksEachHour16NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour17Name[] = "ClicksEachHour17";
const uint64_t AppListAppClickData::kClicksEachHour17NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour17(int64_t value)
{
    SetMetricInternal(kClicksEachHour17NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour18Name[] = "ClicksEachHour18";
const uint64_t AppListAppClickData::kClicksEachHour18NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour18(int64_t value)
{
    SetMetricInternal(kClicksEachHour18NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour19Name[] = "ClicksEachHour19";
const uint64_t AppListAppClickData::kClicksEachHour19NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour19(int64_t value)
{
    SetMetricInternal(kClicksEachHour19NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour20Name[] = "ClicksEachHour20";
const uint64_t AppListAppClickData::kClicksEachHour20NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour20(int64_t value)
{
    SetMetricInternal(kClicksEachHour20NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour21Name[] = "ClicksEachHour21";
const uint64_t AppListAppClickData::kClicksEachHour21NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour21(int64_t value)
{
    SetMetricInternal(kClicksEachHour21NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour22Name[] = "ClicksEachHour22";
const uint64_t AppListAppClickData::kClicksEachHour22NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour22(int64_t value)
{
    SetMetricInternal(kClicksEachHour22NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksEachHour23Name[] = "ClicksEachHour23";
const uint64_t AppListAppClickData::kClicksEachHour23NameHash;

AppListAppClickData& AppListAppClickData::SetClicksEachHour23(int64_t value)
{
    SetMetricInternal(kClicksEachHour23NameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksLast24HoursName[] = "ClicksLast24Hours";
const uint64_t AppListAppClickData::kClicksLast24HoursNameHash;

AppListAppClickData& AppListAppClickData::SetClicksLast24Hours(int64_t value)
{
    SetMetricInternal(kClicksLast24HoursNameHash, value);
    return *this;
}

const char AppListAppClickData::kClicksLastHourName[] = "ClicksLastHour";
const uint64_t AppListAppClickData::kClicksLastHourNameHash;

AppListAppClickData& AppListAppClickData::SetClicksLastHour(int64_t value)
{
    SetMetricInternal(kClicksLastHourNameHash, value);
    return *this;
}

const char AppListAppClickData::kLastLaunchedFromName[] = "LastLaunchedFrom";
const uint64_t AppListAppClickData::kLastLaunchedFromNameHash;

AppListAppClickData& AppListAppClickData::SetLastLaunchedFrom(int64_t value)
{
    SetMetricInternal(kLastLaunchedFromNameHash, value);
    return *this;
}

const char AppListAppClickData::kMostRecentlyUsedIndexName[] = "MostRecentlyUsedIndex";
const uint64_t AppListAppClickData::kMostRecentlyUsedIndexNameHash;

AppListAppClickData& AppListAppClickData::SetMostRecentlyUsedIndex(int64_t value)
{
    SetMetricInternal(kMostRecentlyUsedIndexNameHash, value);
    return *this;
}

const char AppListAppClickData::kSequenceNumberName[] = "SequenceNumber";
const uint64_t AppListAppClickData::kSequenceNumberNameHash;

AppListAppClickData& AppListAppClickData::SetSequenceNumber(int64_t value)
{
    SetMetricInternal(kSequenceNumberNameHash, value);
    return *this;
}

const char AppListAppClickData::kTimeSinceLastClickName[] = "TimeSinceLastClick";
const uint64_t AppListAppClickData::kTimeSinceLastClickNameHash;

AppListAppClickData& AppListAppClickData::SetTimeSinceLastClick(int64_t value)
{
    SetMetricInternal(kTimeSinceLastClickNameHash, value);
    return *this;
}

const char AppListAppClickData::kTotalClicksName[] = "TotalClicks";
const uint64_t AppListAppClickData::kTotalClicksNameHash;

AppListAppClickData& AppListAppClickData::SetTotalClicks(int64_t value)
{
    SetMetricInternal(kTotalClicksNameHash, value);
    return *this;
}
const char AppListAppLaunch::kEntryName[] = "AppListAppLaunch";
const uint64_t AppListAppLaunch::kEntryNameHash;

AppListAppLaunch::AppListAppLaunch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AppListAppLaunch::AppListAppLaunch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AppListAppLaunch::~AppListAppLaunch() = default;
const char AppListAppLaunch::kAllClicksLast24HoursName[] = "AllClicksLast24Hours";
const uint64_t AppListAppLaunch::kAllClicksLast24HoursNameHash;

AppListAppLaunch& AppListAppLaunch::SetAllClicksLast24Hours(int64_t value)
{
    SetMetricInternal(kAllClicksLast24HoursNameHash, value);
    return *this;
}

const char AppListAppLaunch::kAllClicksLastHourName[] = "AllClicksLastHour";
const uint64_t AppListAppLaunch::kAllClicksLastHourNameHash;

AppListAppLaunch& AppListAppLaunch::SetAllClicksLastHour(int64_t value)
{
    SetMetricInternal(kAllClicksLastHourNameHash, value);
    return *this;
}

const char AppListAppLaunch::kAppTypeName[] = "AppType";
const uint64_t AppListAppLaunch::kAppTypeNameHash;

AppListAppLaunch& AppListAppLaunch::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char AppListAppLaunch::kClickMethodName[] = "ClickMethod";
const uint64_t AppListAppLaunch::kClickMethodNameHash;

AppListAppLaunch& AppListAppLaunch::SetClickMethod(int64_t value)
{
    SetMetricInternal(kClickMethodNameHash, value);
    return *this;
}

const char AppListAppLaunch::kDayOfWeekName[] = "DayOfWeek";
const uint64_t AppListAppLaunch::kDayOfWeekNameHash;

AppListAppLaunch& AppListAppLaunch::SetDayOfWeek(int64_t value)
{
    SetMetricInternal(kDayOfWeekNameHash, value);
    return *this;
}

const char AppListAppLaunch::kDeviceModeName[] = "DeviceMode";
const uint64_t AppListAppLaunch::kDeviceModeNameHash;

AppListAppLaunch& AppListAppLaunch::SetDeviceMode(int64_t value)
{
    SetMetricInternal(kDeviceModeNameHash, value);
    return *this;
}

const char AppListAppLaunch::kDeviceTypeName[] = "DeviceType";
const uint64_t AppListAppLaunch::kDeviceTypeNameHash;

AppListAppLaunch& AppListAppLaunch::SetDeviceType(int64_t value)
{
    SetMetricInternal(kDeviceTypeNameHash, value);
    return *this;
}

const char AppListAppLaunch::kHourOfDayName[] = "HourOfDay";
const uint64_t AppListAppLaunch::kHourOfDayNameHash;

AppListAppLaunch& AppListAppLaunch::SetHourOfDay(int64_t value)
{
    SetMetricInternal(kHourOfDayNameHash, value);
    return *this;
}

const char AppListAppLaunch::kLaunchedFromName[] = "LaunchedFrom";
const uint64_t AppListAppLaunch::kLaunchedFromNameHash;

AppListAppLaunch& AppListAppLaunch::SetLaunchedFrom(int64_t value)
{
    SetMetricInternal(kLaunchedFromNameHash, value);
    return *this;
}

const char AppListAppLaunch::kPositionIndexName[] = "PositionIndex";
const uint64_t AppListAppLaunch::kPositionIndexNameHash;

AppListAppLaunch& AppListAppLaunch::SetPositionIndex(int64_t value)
{
    SetMetricInternal(kPositionIndexNameHash, value);
    return *this;
}

const char AppListAppLaunch::kTotalHoursName[] = "TotalHours";
const uint64_t AppListAppLaunch::kTotalHoursNameHash;

AppListAppLaunch& AppListAppLaunch::SetTotalHours(int64_t value)
{
    SetMetricInternal(kTotalHoursNameHash, value);
    return *this;
}
const char Autofill_AddressProfileImport::kEntryName[] = "Autofill.AddressProfileImport";
const uint64_t Autofill_AddressProfileImport::kEntryNameHash;

Autofill_AddressProfileImport::Autofill_AddressProfileImport(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_AddressProfileImport::Autofill_AddressProfileImport(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_AddressProfileImport::~Autofill_AddressProfileImport() = default;
const char Autofill_AddressProfileImport::kAutocompleteUnrecognizedImportName[] = "AutocompleteUnrecognizedImport";
const uint64_t Autofill_AddressProfileImport::kAutocompleteUnrecognizedImportNameHash;

Autofill_AddressProfileImport& Autofill_AddressProfileImport::SetAutocompleteUnrecognizedImport(int64_t value)
{
    SetMetricInternal(kAutocompleteUnrecognizedImportNameHash, value);
    return *this;
}

const char Autofill_AddressProfileImport::kImportTypeName[] = "ImportType";
const uint64_t Autofill_AddressProfileImport::kImportTypeNameHash;

Autofill_AddressProfileImport& Autofill_AddressProfileImport::SetImportType(int64_t value)
{
    SetMetricInternal(kImportTypeNameHash, value);
    return *this;
}

const char Autofill_AddressProfileImport::kNumberOfEditedFieldsName[] = "NumberOfEditedFields";
const uint64_t Autofill_AddressProfileImport::kNumberOfEditedFieldsNameHash;

Autofill_AddressProfileImport& Autofill_AddressProfileImport::SetNumberOfEditedFields(int64_t value)
{
    SetMetricInternal(kNumberOfEditedFieldsNameHash, value);
    return *this;
}

const char Autofill_AddressProfileImport::kPhoneNumberStatusName[] = "PhoneNumberStatus";
const uint64_t Autofill_AddressProfileImport::kPhoneNumberStatusNameHash;

Autofill_AddressProfileImport& Autofill_AddressProfileImport::SetPhoneNumberStatus(int64_t value)
{
    SetMetricInternal(kPhoneNumberStatusNameHash, value);
    return *this;
}

const char Autofill_AddressProfileImport::kUserDecisionName[] = "UserDecision";
const uint64_t Autofill_AddressProfileImport::kUserDecisionNameHash;

Autofill_AddressProfileImport& Autofill_AddressProfileImport::SetUserDecision(int64_t value)
{
    SetMetricInternal(kUserDecisionNameHash, value);
    return *this;
}
const char Autofill_CardUploadDecision::kEntryName[] = "Autofill.CardUploadDecision";
const uint64_t Autofill_CardUploadDecision::kEntryNameHash;

Autofill_CardUploadDecision::Autofill_CardUploadDecision(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_CardUploadDecision::Autofill_CardUploadDecision(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_CardUploadDecision::~Autofill_CardUploadDecision() = default;
const char Autofill_CardUploadDecision::kUploadDecisionName[] = "UploadDecision";
const uint64_t Autofill_CardUploadDecision::kUploadDecisionNameHash;

Autofill_CardUploadDecision& Autofill_CardUploadDecision::SetUploadDecision(int64_t value)
{
    SetMetricInternal(kUploadDecisionNameHash, value);
    return *this;
}
const char Autofill_CreditCardFill::kEntryName[] = "Autofill.CreditCardFill";
const uint64_t Autofill_CreditCardFill::kEntryNameHash;

Autofill_CreditCardFill::Autofill_CreditCardFill(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_CreditCardFill::Autofill_CreditCardFill(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_CreditCardFill::~Autofill_CreditCardFill() = default;
const char Autofill_CreditCardFill::kFillable_AfterSecurity_BitmaskName[] = "Fillable.AfterSecurity.Bitmask";
const uint64_t Autofill_CreditCardFill::kFillable_AfterSecurity_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_AfterSecurity_Bitmask(int64_t value)
{
    SetMetricInternal(kFillable_AfterSecurity_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_AfterSecurity_QualitativeName[] = "Fillable.AfterSecurity.Qualitative";
const uint64_t Autofill_CreditCardFill::kFillable_AfterSecurity_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_AfterSecurity_Qualitative(int64_t value)
{
    SetMetricInternal(kFillable_AfterSecurity_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_BitmaskName[] = "Fillable.AfterSecurity.Visible.Bitmask";
const uint64_t Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_AfterSecurity_Visible_Bitmask(int64_t value)
{
    SetMetricInternal(kFillable_AfterSecurity_Visible_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_QualitativeName[] = "Fillable.AfterSecurity.Visible.Qualitative";
const uint64_t Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_AfterSecurity_Visible_Qualitative(int64_t value)
{
    SetMetricInternal(kFillable_AfterSecurity_Visible_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_BeforeSecurity_BitmaskName[] = "Fillable.BeforeSecurity.Bitmask";
const uint64_t Autofill_CreditCardFill::kFillable_BeforeSecurity_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_BeforeSecurity_Bitmask(int64_t value)
{
    SetMetricInternal(kFillable_BeforeSecurity_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_BeforeSecurity_QualitativeName[] = "Fillable.BeforeSecurity.Qualitative";
const uint64_t Autofill_CreditCardFill::kFillable_BeforeSecurity_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_BeforeSecurity_Qualitative(int64_t value)
{
    SetMetricInternal(kFillable_BeforeSecurity_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_BitmaskName[] = "Fillable.BeforeSecurity.Visible.Bitmask";
const uint64_t Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_BeforeSecurity_Visible_Bitmask(int64_t value)
{
    SetMetricInternal(kFillable_BeforeSecurity_Visible_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_QualitativeName[] = "Fillable.BeforeSecurity.Visible.Qualitative";
const uint64_t Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFillable_BeforeSecurity_Visible_Qualitative(int64_t value)
{
    SetMetricInternal(kFillable_BeforeSecurity_Visible_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_AfterSecurity_BitmaskName[] = "Filled.AfterSecurity.Bitmask";
const uint64_t Autofill_CreditCardFill::kFilled_AfterSecurity_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_AfterSecurity_Bitmask(int64_t value)
{
    SetMetricInternal(kFilled_AfterSecurity_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_AfterSecurity_QualitativeName[] = "Filled.AfterSecurity.Qualitative";
const uint64_t Autofill_CreditCardFill::kFilled_AfterSecurity_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_AfterSecurity_Qualitative(int64_t value)
{
    SetMetricInternal(kFilled_AfterSecurity_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_BitmaskName[] = "Filled.AfterSecurity.Visible.Bitmask";
const uint64_t Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_AfterSecurity_Visible_Bitmask(int64_t value)
{
    SetMetricInternal(kFilled_AfterSecurity_Visible_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_QualitativeName[] = "Filled.AfterSecurity.Visible.Qualitative";
const uint64_t Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_AfterSecurity_Visible_Qualitative(int64_t value)
{
    SetMetricInternal(kFilled_AfterSecurity_Visible_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_BeforeSecurity_BitmaskName[] = "Filled.BeforeSecurity.Bitmask";
const uint64_t Autofill_CreditCardFill::kFilled_BeforeSecurity_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_BeforeSecurity_Bitmask(int64_t value)
{
    SetMetricInternal(kFilled_BeforeSecurity_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_BeforeSecurity_QualitativeName[] = "Filled.BeforeSecurity.Qualitative";
const uint64_t Autofill_CreditCardFill::kFilled_BeforeSecurity_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_BeforeSecurity_Qualitative(int64_t value)
{
    SetMetricInternal(kFilled_BeforeSecurity_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_BitmaskName[] = "Filled.BeforeSecurity.Visible.Bitmask";
const uint64_t Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_BitmaskNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_BeforeSecurity_Visible_Bitmask(int64_t value)
{
    SetMetricInternal(kFilled_BeforeSecurity_Visible_BitmaskNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_QualitativeName[] = "Filled.BeforeSecurity.Visible.Qualitative";
const uint64_t Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_QualitativeNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFilled_BeforeSecurity_Visible_Qualitative(int64_t value)
{
    SetMetricInternal(kFilled_BeforeSecurity_Visible_QualitativeNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_CreditCardFill::kFormSignatureNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_CreditCardFill::kSharedAutofillName[] = "SharedAutofill";
const uint64_t Autofill_CreditCardFill::kSharedAutofillNameHash;

Autofill_CreditCardFill& Autofill_CreditCardFill::SetSharedAutofill(int64_t value)
{
    SetMetricInternal(kSharedAutofillNameHash, value);
    return *this;
}
const char Autofill_DeveloperEngagement::kEntryName[] = "Autofill.DeveloperEngagement";
const uint64_t Autofill_DeveloperEngagement::kEntryNameHash;

Autofill_DeveloperEngagement::Autofill_DeveloperEngagement(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_DeveloperEngagement::Autofill_DeveloperEngagement(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_DeveloperEngagement::~Autofill_DeveloperEngagement() = default;
const char Autofill_DeveloperEngagement::kDeveloperEngagementName[] = "DeveloperEngagement";
const uint64_t Autofill_DeveloperEngagement::kDeveloperEngagementNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetDeveloperEngagement(int64_t value)
{
    SetMetricInternal(kDeveloperEngagementNameHash, value);
    return *this;
}

const char Autofill_DeveloperEngagement::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_DeveloperEngagement::kFormSignatureNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_DeveloperEngagement::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_DeveloperEngagement::kFormTypesNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetFormTypes(int64_t value)
{
    SetMetricInternal(kFormTypesNameHash, value);
    return *this;
}

const char Autofill_DeveloperEngagement::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_DeveloperEngagement::kIsForCreditCardNameHash;

Autofill_DeveloperEngagement& Autofill_DeveloperEngagement::SetIsForCreditCard(int64_t value)
{
    SetMetricInternal(kIsForCreditCardNameHash, value);
    return *this;
}
const char Autofill_EditedAutofilledFieldAtSubmission::kEntryName[] = "Autofill.EditedAutofilledFieldAtSubmission";
const uint64_t Autofill_EditedAutofilledFieldAtSubmission::kEntryNameHash;

Autofill_EditedAutofilledFieldAtSubmission::Autofill_EditedAutofilledFieldAtSubmission(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_EditedAutofilledFieldAtSubmission::Autofill_EditedAutofilledFieldAtSubmission(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_EditedAutofilledFieldAtSubmission::~Autofill_EditedAutofilledFieldAtSubmission() = default;
const char Autofill_EditedAutofilledFieldAtSubmission::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_EditedAutofilledFieldAtSubmission::kFieldSignatureNameHash;

Autofill_EditedAutofilledFieldAtSubmission& Autofill_EditedAutofilledFieldAtSubmission::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_EditedAutofilledFieldAtSubmission::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_EditedAutofilledFieldAtSubmission::kFormSignatureNameHash;

Autofill_EditedAutofilledFieldAtSubmission& Autofill_EditedAutofilledFieldAtSubmission::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_EditedAutofilledFieldAtSubmission::kOverallTypeName[] = "OverallType";
const uint64_t Autofill_EditedAutofilledFieldAtSubmission::kOverallTypeNameHash;

Autofill_EditedAutofilledFieldAtSubmission& Autofill_EditedAutofilledFieldAtSubmission::SetOverallType(int64_t value)
{
    SetMetricInternal(kOverallTypeNameHash, value);
    return *this;
}
const char Autofill_FieldFillStatus::kEntryName[] = "Autofill.FieldFillStatus";
const uint64_t Autofill_FieldFillStatus::kEntryNameHash;

Autofill_FieldFillStatus::Autofill_FieldFillStatus(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FieldFillStatus::Autofill_FieldFillStatus(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FieldFillStatus::~Autofill_FieldFillStatus() = default;
const char Autofill_FieldFillStatus::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_FieldFillStatus::kFieldSignatureNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_FieldFillStatus::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_FieldFillStatus::kFormSignatureNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_FieldFillStatus::kIsAutofilledName[] = "IsAutofilled";
const uint64_t Autofill_FieldFillStatus::kIsAutofilledNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetIsAutofilled(int64_t value)
{
    SetMetricInternal(kIsAutofilledNameHash, value);
    return *this;
}

const char Autofill_FieldFillStatus::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FieldFillStatus::kMillisecondsSinceFormParsedNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}

const char Autofill_FieldFillStatus::kPredictionSourceName[] = "PredictionSource";
const uint64_t Autofill_FieldFillStatus::kPredictionSourceNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetPredictionSource(int64_t value)
{
    SetMetricInternal(kPredictionSourceNameHash, value);
    return *this;
}

const char Autofill_FieldFillStatus::kValidationEventName[] = "ValidationEvent";
const uint64_t Autofill_FieldFillStatus::kValidationEventNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetValidationEvent(int64_t value)
{
    SetMetricInternal(kValidationEventNameHash, value);
    return *this;
}

const char Autofill_FieldFillStatus::kWasPreviouslyAutofilledName[] = "WasPreviouslyAutofilled";
const uint64_t Autofill_FieldFillStatus::kWasPreviouslyAutofilledNameHash;

Autofill_FieldFillStatus& Autofill_FieldFillStatus::SetWasPreviouslyAutofilled(int64_t value)
{
    SetMetricInternal(kWasPreviouslyAutofilledNameHash, value);
    return *this;
}
const char Autofill_FieldTypeValidation::kEntryName[] = "Autofill.FieldTypeValidation";
const uint64_t Autofill_FieldTypeValidation::kEntryNameHash;

Autofill_FieldTypeValidation::Autofill_FieldTypeValidation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FieldTypeValidation::Autofill_FieldTypeValidation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FieldTypeValidation::~Autofill_FieldTypeValidation() = default;
const char Autofill_FieldTypeValidation::kActualTypeName[] = "ActualType";
const uint64_t Autofill_FieldTypeValidation::kActualTypeNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetActualType(int64_t value)
{
    SetMetricInternal(kActualTypeNameHash, value);
    return *this;
}

const char Autofill_FieldTypeValidation::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_FieldTypeValidation::kFieldSignatureNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_FieldTypeValidation::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_FieldTypeValidation::kFormSignatureNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}

const char Autofill_FieldTypeValidation::kPredictedTypeName[] = "PredictedType";
const uint64_t Autofill_FieldTypeValidation::kPredictedTypeNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetPredictedType(int64_t value)
{
    SetMetricInternal(kPredictedTypeNameHash, value);
    return *this;
}

const char Autofill_FieldTypeValidation::kPredictionSourceName[] = "PredictionSource";
const uint64_t Autofill_FieldTypeValidation::kPredictionSourceNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetPredictionSource(int64_t value)
{
    SetMetricInternal(kPredictionSourceNameHash, value);
    return *this;
}

const char Autofill_FieldTypeValidation::kValidationEventName[] = "ValidationEvent";
const uint64_t Autofill_FieldTypeValidation::kValidationEventNameHash;

Autofill_FieldTypeValidation& Autofill_FieldTypeValidation::SetValidationEvent(int64_t value)
{
    SetMetricInternal(kValidationEventNameHash, value);
    return *this;
}
const char Autofill_FormEvent::kEntryName[] = "Autofill.FormEvent";
const uint64_t Autofill_FormEvent::kEntryNameHash;

Autofill_FormEvent::Autofill_FormEvent(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FormEvent::Autofill_FormEvent(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FormEvent::~Autofill_FormEvent() = default;
const char Autofill_FormEvent::kAutofillFormEventName[] = "AutofillFormEvent";
const uint64_t Autofill_FormEvent::kAutofillFormEventNameHash;

Autofill_FormEvent& Autofill_FormEvent::SetAutofillFormEvent(int64_t value)
{
    SetMetricInternal(kAutofillFormEventNameHash, value);
    return *this;
}

const char Autofill_FormEvent::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_FormEvent::kFormTypesNameHash;

Autofill_FormEvent& Autofill_FormEvent::SetFormTypes(int64_t value)
{
    SetMetricInternal(kFormTypesNameHash, value);
    return *this;
}

const char Autofill_FormEvent::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FormEvent::kMillisecondsSinceFormParsedNameHash;

Autofill_FormEvent& Autofill_FormEvent::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}
const char Autofill_FormFillSuccessIOS::kEntryName[] = "Autofill.FormFillSuccessIOS";
const uint64_t Autofill_FormFillSuccessIOS::kEntryNameHash;

Autofill_FormFillSuccessIOS::Autofill_FormFillSuccessIOS(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FormFillSuccessIOS::Autofill_FormFillSuccessIOS(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FormFillSuccessIOS::~Autofill_FormFillSuccessIOS() = default;
const char Autofill_FormFillSuccessIOS::kFormFillSuccessName[] = "FormFillSuccess";
const uint64_t Autofill_FormFillSuccessIOS::kFormFillSuccessNameHash;

Autofill_FormFillSuccessIOS& Autofill_FormFillSuccessIOS::SetFormFillSuccess(int64_t value)
{
    SetMetricInternal(kFormFillSuccessNameHash, value);
    return *this;
}
const char Autofill_FormSubmitted::kEntryName[] = "Autofill.FormSubmitted";
const uint64_t Autofill_FormSubmitted::kEntryNameHash;

Autofill_FormSubmitted::Autofill_FormSubmitted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FormSubmitted::Autofill_FormSubmitted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_FormSubmitted::~Autofill_FormSubmitted() = default;
const char Autofill_FormSubmitted::kAutocompleteFillsName[] = "AutocompleteFills";
const uint64_t Autofill_FormSubmitted::kAutocompleteFillsNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetAutocompleteFills(int64_t value)
{
    SetMetricInternal(kAutocompleteFillsNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kAutofillAssistantIntentName[] = "AutofillAssistantIntent";
const uint64_t Autofill_FormSubmitted::kAutofillAssistantIntentNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetAutofillAssistantIntent(int64_t value)
{
    SetMetricInternal(kAutofillAssistantIntentNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kAutofillFillsName[] = "AutofillFills";
const uint64_t Autofill_FormSubmitted::kAutofillFillsNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetAutofillFills(int64_t value)
{
    SetMetricInternal(kAutofillFillsNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kAutofillFormSubmittedStateName[] = "AutofillFormSubmittedState";
const uint64_t Autofill_FormSubmitted::kAutofillFormSubmittedStateNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetAutofillFormSubmittedState(int64_t value)
{
    SetMetricInternal(kAutofillFormSubmittedStateNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kFormElementUserModificationsName[] = "FormElementUserModifications";
const uint64_t Autofill_FormSubmitted::kFormElementUserModificationsNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetFormElementUserModifications(int64_t value)
{
    SetMetricInternal(kFormElementUserModificationsNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_FormSubmitted::kFormSignatureNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_FormSubmitted::kFormTypesNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetFormTypes(int64_t value)
{
    SetMetricInternal(kFormTypesNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kHasUpiVpaFieldName[] = "HasUpiVpaField";
const uint64_t Autofill_FormSubmitted::kHasUpiVpaFieldNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetHasUpiVpaField(int64_t value)
{
    SetMetricInternal(kHasUpiVpaFieldNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_FormSubmitted::kIsForCreditCardNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetIsForCreditCard(int64_t value)
{
    SetMetricInternal(kIsForCreditCardNameHash, value);
    return *this;
}

const char Autofill_FormSubmitted::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_FormSubmitted::kMillisecondsSinceFormParsedNameHash;

Autofill_FormSubmitted& Autofill_FormSubmitted::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}
const char Autofill_HiddenRepresentationalFieldSkipDecision::kEntryName[] = "Autofill.HiddenRepresentationalFieldSkipDecision";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kEntryNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision::Autofill_HiddenRepresentationalFieldSkipDecision(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_HiddenRepresentationalFieldSkipDecision::Autofill_HiddenRepresentationalFieldSkipDecision(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_HiddenRepresentationalFieldSkipDecision::~Autofill_HiddenRepresentationalFieldSkipDecision() = default;
const char Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeName[] = "FieldOverallType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFieldOverallType(int64_t value)
{
    SetMetricInternal(kFieldOverallTypeNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupName[] = "FieldTypeGroup";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFieldTypeGroup(int64_t value)
{
    SetMetricInternal(kFieldTypeGroupNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetHeuristicType(int64_t value)
{
    SetMetricInternal(kHeuristicTypeNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeName[] = "HtmlFieldMode";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetHtmlFieldMode(int64_t value)
{
    SetMetricInternal(kHtmlFieldModeNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetHtmlFieldType(int64_t value)
{
    SetMetricInternal(kHtmlFieldTypeNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedName[] = "IsSkipped";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetIsSkipped(int64_t value)
{
    SetMetricInternal(kIsSkippedNameHash, value);
    return *this;
}

const char Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeName[] = "ServerType";
const uint64_t Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeNameHash;

Autofill_HiddenRepresentationalFieldSkipDecision& Autofill_HiddenRepresentationalFieldSkipDecision::SetServerType(int64_t value)
{
    SetMetricInternal(kServerTypeNameHash, value);
    return *this;
}
const char Autofill_InteractedWithForm::kEntryName[] = "Autofill.InteractedWithForm";
const uint64_t Autofill_InteractedWithForm::kEntryNameHash;

Autofill_InteractedWithForm::Autofill_InteractedWithForm(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_InteractedWithForm::Autofill_InteractedWithForm(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_InteractedWithForm::~Autofill_InteractedWithForm() = default;
const char Autofill_InteractedWithForm::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_InteractedWithForm::kFormSignatureNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_InteractedWithForm::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_InteractedWithForm::kFormTypesNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetFormTypes(int64_t value)
{
    SetMetricInternal(kFormTypesNameHash, value);
    return *this;
}

const char Autofill_InteractedWithForm::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_InteractedWithForm::kIsForCreditCardNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetIsForCreditCard(int64_t value)
{
    SetMetricInternal(kIsForCreditCardNameHash, value);
    return *this;
}

const char Autofill_InteractedWithForm::kLocalRecordTypeCountName[] = "LocalRecordTypeCount";
const uint64_t Autofill_InteractedWithForm::kLocalRecordTypeCountNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetLocalRecordTypeCount(int64_t value)
{
    SetMetricInternal(kLocalRecordTypeCountNameHash, value);
    return *this;
}

const char Autofill_InteractedWithForm::kServerRecordTypeCountName[] = "ServerRecordTypeCount";
const uint64_t Autofill_InteractedWithForm::kServerRecordTypeCountNameHash;

Autofill_InteractedWithForm& Autofill_InteractedWithForm::SetServerRecordTypeCount(int64_t value)
{
    SetMetricInternal(kServerRecordTypeCountNameHash, value);
    return *this;
}
const char Autofill_KeyMetrics::kEntryName[] = "Autofill.KeyMetrics";
const uint64_t Autofill_KeyMetrics::kEntryNameHash;

Autofill_KeyMetrics::Autofill_KeyMetrics(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_KeyMetrics::Autofill_KeyMetrics(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_KeyMetrics::~Autofill_KeyMetrics() = default;
const char Autofill_KeyMetrics::kAutofillAssistantIntentName[] = "AutofillAssistantIntent";
const uint64_t Autofill_KeyMetrics::kAutofillAssistantIntentNameHash;

Autofill_KeyMetrics& Autofill_KeyMetrics::SetAutofillAssistantIntent(int64_t value)
{
    SetMetricInternal(kAutofillAssistantIntentNameHash, value);
    return *this;
}

const char Autofill_KeyMetrics::kFillingAcceptanceName[] = "FillingAcceptance";
const uint64_t Autofill_KeyMetrics::kFillingAcceptanceNameHash;

Autofill_KeyMetrics& Autofill_KeyMetrics::SetFillingAcceptance(int64_t value)
{
    SetMetricInternal(kFillingAcceptanceNameHash, value);
    return *this;
}

const char Autofill_KeyMetrics::kFillingAssistanceName[] = "FillingAssistance";
const uint64_t Autofill_KeyMetrics::kFillingAssistanceNameHash;

Autofill_KeyMetrics& Autofill_KeyMetrics::SetFillingAssistance(int64_t value)
{
    SetMetricInternal(kFillingAssistanceNameHash, value);
    return *this;
}

const char Autofill_KeyMetrics::kFillingCorrectnessName[] = "FillingCorrectness";
const uint64_t Autofill_KeyMetrics::kFillingCorrectnessNameHash;

Autofill_KeyMetrics& Autofill_KeyMetrics::SetFillingCorrectness(int64_t value)
{
    SetMetricInternal(kFillingCorrectnessNameHash, value);
    return *this;
}

const char Autofill_KeyMetrics::kFillingReadinessName[] = "FillingReadiness";
const uint64_t Autofill_KeyMetrics::kFillingReadinessNameHash;

Autofill_KeyMetrics& Autofill_KeyMetrics::SetFillingReadiness(int64_t value)
{
    SetMetricInternal(kFillingReadinessNameHash, value);
    return *this;
}

const char Autofill_KeyMetrics::kFormTypesName[] = "FormTypes";
const uint64_t Autofill_KeyMetrics::kFormTypesNameHash;

Autofill_KeyMetrics& Autofill_KeyMetrics::SetFormTypes(int64_t value)
{
    SetMetricInternal(kFormTypesNameHash, value);
    return *this;
}
const char Autofill_RepeatedServerTypePredictionRationalized::kEntryName[] = "Autofill.RepeatedServerTypePredictionRationalized";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kEntryNameHash;

Autofill_RepeatedServerTypePredictionRationalized::Autofill_RepeatedServerTypePredictionRationalized(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_RepeatedServerTypePredictionRationalized::Autofill_RepeatedServerTypePredictionRationalized(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_RepeatedServerTypePredictionRationalized::~Autofill_RepeatedServerTypePredictionRationalized() = default;
const char Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeName[] = "FieldNewOverallType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldNewOverallType(int64_t value)
{
    SetMetricInternal(kFieldNewOverallTypeNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeName[] = "FieldOldOverallType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldOldOverallType(int64_t value)
{
    SetMetricInternal(kFieldOldOverallTypeNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupName[] = "FieldTypeGroup";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFieldTypeGroup(int64_t value)
{
    SetMetricInternal(kFieldTypeGroupNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetHeuristicType(int64_t value)
{
    SetMetricInternal(kHeuristicTypeNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeName[] = "HtmlFieldMode";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetHtmlFieldMode(int64_t value)
{
    SetMetricInternal(kHtmlFieldModeNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetHtmlFieldType(int64_t value)
{
    SetMetricInternal(kHtmlFieldTypeNameHash, value);
    return *this;
}

const char Autofill_RepeatedServerTypePredictionRationalized::kServerTypeName[] = "ServerType";
const uint64_t Autofill_RepeatedServerTypePredictionRationalized::kServerTypeNameHash;

Autofill_RepeatedServerTypePredictionRationalized& Autofill_RepeatedServerTypePredictionRationalized::SetServerType(int64_t value)
{
    SetMetricInternal(kServerTypeNameHash, value);
    return *this;
}
const char Autofill_SuggestionFilled::kEntryName[] = "Autofill.SuggestionFilled";
const uint64_t Autofill_SuggestionFilled::kEntryNameHash;

Autofill_SuggestionFilled::Autofill_SuggestionFilled(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_SuggestionFilled::Autofill_SuggestionFilled(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_SuggestionFilled::~Autofill_SuggestionFilled() = default;
const char Autofill_SuggestionFilled::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_SuggestionFilled::kFieldSignatureNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_SuggestionFilled::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_SuggestionFilled::kFormSignatureNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_SuggestionFilled::kIsForCreditCardName[] = "IsForCreditCard";
const uint64_t Autofill_SuggestionFilled::kIsForCreditCardNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetIsForCreditCard(int64_t value)
{
    SetMetricInternal(kIsForCreditCardNameHash, value);
    return *this;
}

const char Autofill_SuggestionFilled::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_SuggestionFilled::kMillisecondsSinceFormParsedNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}

const char Autofill_SuggestionFilled::kRecordTypeName[] = "RecordType";
const uint64_t Autofill_SuggestionFilled::kRecordTypeNameHash;

Autofill_SuggestionFilled& Autofill_SuggestionFilled::SetRecordType(int64_t value)
{
    SetMetricInternal(kRecordTypeNameHash, value);
    return *this;
}
const char Autofill_SuggestionsShown::kEntryName[] = "Autofill.SuggestionsShown";
const uint64_t Autofill_SuggestionsShown::kEntryNameHash;

Autofill_SuggestionsShown::Autofill_SuggestionsShown(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_SuggestionsShown::Autofill_SuggestionsShown(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_SuggestionsShown::~Autofill_SuggestionsShown() = default;
const char Autofill_SuggestionsShown::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_SuggestionsShown::kFieldSignatureNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_SuggestionsShown::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_SuggestionsShown::kFormSignatureNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_SuggestionsShown::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_SuggestionsShown::kHeuristicTypeNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetHeuristicType(int64_t value)
{
    SetMetricInternal(kHeuristicTypeNameHash, value);
    return *this;
}

const char Autofill_SuggestionsShown::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_SuggestionsShown::kHtmlFieldTypeNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetHtmlFieldType(int64_t value)
{
    SetMetricInternal(kHtmlFieldTypeNameHash, value);
    return *this;
}

const char Autofill_SuggestionsShown::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_SuggestionsShown::kMillisecondsSinceFormParsedNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}

const char Autofill_SuggestionsShown::kServerTypeName[] = "ServerType";
const uint64_t Autofill_SuggestionsShown::kServerTypeNameHash;

Autofill_SuggestionsShown& Autofill_SuggestionsShown::SetServerType(int64_t value)
{
    SetMetricInternal(kServerTypeNameHash, value);
    return *this;
}
const char Autofill_TextFieldDidChange::kEntryName[] = "Autofill.TextFieldDidChange";
const uint64_t Autofill_TextFieldDidChange::kEntryNameHash;

Autofill_TextFieldDidChange::Autofill_TextFieldDidChange(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_TextFieldDidChange::Autofill_TextFieldDidChange(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Autofill_TextFieldDidChange::~Autofill_TextFieldDidChange() = default;
const char Autofill_TextFieldDidChange::kFieldSignatureName[] = "FieldSignature";
const uint64_t Autofill_TextFieldDidChange::kFieldSignatureNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetFieldSignature(int64_t value)
{
    SetMetricInternal(kFieldSignatureNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kFieldTypeGroupName[] = "FieldTypeGroup";
const uint64_t Autofill_TextFieldDidChange::kFieldTypeGroupNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetFieldTypeGroup(int64_t value)
{
    SetMetricInternal(kFieldTypeGroupNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kFormSignatureName[] = "FormSignature";
const uint64_t Autofill_TextFieldDidChange::kFormSignatureNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetFormSignature(int64_t value)
{
    SetMetricInternal(kFormSignatureNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kHeuristicTypeName[] = "HeuristicType";
const uint64_t Autofill_TextFieldDidChange::kHeuristicTypeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetHeuristicType(int64_t value)
{
    SetMetricInternal(kHeuristicTypeNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kHtmlFieldModeName[] = "HtmlFieldMode";
const uint64_t Autofill_TextFieldDidChange::kHtmlFieldModeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetHtmlFieldMode(int64_t value)
{
    SetMetricInternal(kHtmlFieldModeNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kHtmlFieldTypeName[] = "HtmlFieldType";
const uint64_t Autofill_TextFieldDidChange::kHtmlFieldTypeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetHtmlFieldType(int64_t value)
{
    SetMetricInternal(kHtmlFieldTypeNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kIsAutofilledName[] = "IsAutofilled";
const uint64_t Autofill_TextFieldDidChange::kIsAutofilledNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetIsAutofilled(int64_t value)
{
    SetMetricInternal(kIsAutofilledNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kIsEmptyName[] = "IsEmpty";
const uint64_t Autofill_TextFieldDidChange::kIsEmptyNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetIsEmpty(int64_t value)
{
    SetMetricInternal(kIsEmptyNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedName[] = "MillisecondsSinceFormParsed";
const uint64_t Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetMillisecondsSinceFormParsed(int64_t value)
{
    SetMetricInternal(kMillisecondsSinceFormParsedNameHash, value);
    return *this;
}

const char Autofill_TextFieldDidChange::kServerTypeName[] = "ServerType";
const uint64_t Autofill_TextFieldDidChange::kServerTypeNameHash;

Autofill_TextFieldDidChange& Autofill_TextFieldDidChange::SetServerType(int64_t value)
{
    SetMetricInternal(kServerTypeNameHash, value);
    return *this;
}
const char AutofillAssistant_CollectContact::kEntryName[] = "AutofillAssistant.CollectContact";
const uint64_t AutofillAssistant_CollectContact::kEntryNameHash;

AutofillAssistant_CollectContact::AutofillAssistant_CollectContact(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectContact::AutofillAssistant_CollectContact(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectContact::~AutofillAssistant_CollectContact() = default;
const char AutofillAssistant_CollectContact::kCompleteContactProfilesCountName[] = "CompleteContactProfilesCount";
const uint64_t AutofillAssistant_CollectContact::kCompleteContactProfilesCountNameHash;

AutofillAssistant_CollectContact& AutofillAssistant_CollectContact::SetCompleteContactProfilesCount(int64_t value)
{
    SetMetricInternal(kCompleteContactProfilesCountNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectContact::kContactModifiedName[] = "ContactModified";
const uint64_t AutofillAssistant_CollectContact::kContactModifiedNameHash;

AutofillAssistant_CollectContact& AutofillAssistant_CollectContact::SetContactModified(int64_t value)
{
    SetMetricInternal(kContactModifiedNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectContact::kIncompleteContactProfilesCountName[] = "IncompleteContactProfilesCount";
const uint64_t AutofillAssistant_CollectContact::kIncompleteContactProfilesCountNameHash;

AutofillAssistant_CollectContact& AutofillAssistant_CollectContact::SetIncompleteContactProfilesCount(int64_t value)
{
    SetMetricInternal(kIncompleteContactProfilesCountNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectContact::kInitialContactFieldsStatusName[] = "InitialContactFieldsStatus";
const uint64_t AutofillAssistant_CollectContact::kInitialContactFieldsStatusNameHash;

AutofillAssistant_CollectContact& AutofillAssistant_CollectContact::SetInitialContactFieldsStatus(int64_t value)
{
    SetMetricInternal(kInitialContactFieldsStatusNameHash, value);
    return *this;
}
const char AutofillAssistant_CollectPayment::kEntryName[] = "AutofillAssistant.CollectPayment";
const uint64_t AutofillAssistant_CollectPayment::kEntryNameHash;

AutofillAssistant_CollectPayment::AutofillAssistant_CollectPayment(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectPayment::AutofillAssistant_CollectPayment(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectPayment::~AutofillAssistant_CollectPayment() = default;
const char AutofillAssistant_CollectPayment::kCompleteCreditCardsCountName[] = "CompleteCreditCardsCount";
const uint64_t AutofillAssistant_CollectPayment::kCompleteCreditCardsCountNameHash;

AutofillAssistant_CollectPayment& AutofillAssistant_CollectPayment::SetCompleteCreditCardsCount(int64_t value)
{
    SetMetricInternal(kCompleteCreditCardsCountNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectPayment::kCreditCardModifiedName[] = "CreditCardModified";
const uint64_t AutofillAssistant_CollectPayment::kCreditCardModifiedNameHash;

AutofillAssistant_CollectPayment& AutofillAssistant_CollectPayment::SetCreditCardModified(int64_t value)
{
    SetMetricInternal(kCreditCardModifiedNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectPayment::kIncompleteCreditCardsCountName[] = "IncompleteCreditCardsCount";
const uint64_t AutofillAssistant_CollectPayment::kIncompleteCreditCardsCountNameHash;

AutofillAssistant_CollectPayment& AutofillAssistant_CollectPayment::SetIncompleteCreditCardsCount(int64_t value)
{
    SetMetricInternal(kIncompleteCreditCardsCountNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectPayment::kInitialBillingAddressFieldsStatusName[] = "InitialBillingAddressFieldsStatus";
const uint64_t AutofillAssistant_CollectPayment::kInitialBillingAddressFieldsStatusNameHash;

AutofillAssistant_CollectPayment& AutofillAssistant_CollectPayment::SetInitialBillingAddressFieldsStatus(int64_t value)
{
    SetMetricInternal(kInitialBillingAddressFieldsStatusNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectPayment::kInitialCreditCardFieldsStatusName[] = "InitialCreditCardFieldsStatus";
const uint64_t AutofillAssistant_CollectPayment::kInitialCreditCardFieldsStatusNameHash;

AutofillAssistant_CollectPayment& AutofillAssistant_CollectPayment::SetInitialCreditCardFieldsStatus(int64_t value)
{
    SetMetricInternal(kInitialCreditCardFieldsStatusNameHash, value);
    return *this;
}
const char AutofillAssistant_CollectShippingAddress::kEntryName[] = "AutofillAssistant.CollectShippingAddress";
const uint64_t AutofillAssistant_CollectShippingAddress::kEntryNameHash;

AutofillAssistant_CollectShippingAddress::AutofillAssistant_CollectShippingAddress(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectShippingAddress::AutofillAssistant_CollectShippingAddress(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectShippingAddress::~AutofillAssistant_CollectShippingAddress() = default;
const char AutofillAssistant_CollectShippingAddress::kCompleteShippingProfilesCountName[] = "CompleteShippingProfilesCount";
const uint64_t AutofillAssistant_CollectShippingAddress::kCompleteShippingProfilesCountNameHash;

AutofillAssistant_CollectShippingAddress& AutofillAssistant_CollectShippingAddress::SetCompleteShippingProfilesCount(int64_t value)
{
    SetMetricInternal(kCompleteShippingProfilesCountNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectShippingAddress::kIncompleteShippingProfilesCountName[] = "IncompleteShippingProfilesCount";
const uint64_t AutofillAssistant_CollectShippingAddress::kIncompleteShippingProfilesCountNameHash;

AutofillAssistant_CollectShippingAddress& AutofillAssistant_CollectShippingAddress::SetIncompleteShippingProfilesCount(int64_t value)
{
    SetMetricInternal(kIncompleteShippingProfilesCountNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectShippingAddress::kInitialShippingFieldsStatusName[] = "InitialShippingFieldsStatus";
const uint64_t AutofillAssistant_CollectShippingAddress::kInitialShippingFieldsStatusNameHash;

AutofillAssistant_CollectShippingAddress& AutofillAssistant_CollectShippingAddress::SetInitialShippingFieldsStatus(int64_t value)
{
    SetMetricInternal(kInitialShippingFieldsStatusNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectShippingAddress::kShippingModifiedName[] = "ShippingModified";
const uint64_t AutofillAssistant_CollectShippingAddress::kShippingModifiedNameHash;

AutofillAssistant_CollectShippingAddress& AutofillAssistant_CollectShippingAddress::SetShippingModified(int64_t value)
{
    SetMetricInternal(kShippingModifiedNameHash, value);
    return *this;
}
const char AutofillAssistant_CollectUserDataResult::kEntryName[] = "AutofillAssistant.CollectUserDataResult";
const uint64_t AutofillAssistant_CollectUserDataResult::kEntryNameHash;

AutofillAssistant_CollectUserDataResult::AutofillAssistant_CollectUserDataResult(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectUserDataResult::AutofillAssistant_CollectUserDataResult(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_CollectUserDataResult::~AutofillAssistant_CollectUserDataResult() = default;
const char AutofillAssistant_CollectUserDataResult::kResultName[] = "Result";
const uint64_t AutofillAssistant_CollectUserDataResult::kResultNameHash;

AutofillAssistant_CollectUserDataResult& AutofillAssistant_CollectUserDataResult::SetResult(int64_t value)
{
    SetMetricInternal(kResultNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectUserDataResult::kTimeTakenMsName[] = "TimeTakenMs";
const uint64_t AutofillAssistant_CollectUserDataResult::kTimeTakenMsNameHash;

AutofillAssistant_CollectUserDataResult& AutofillAssistant_CollectUserDataResult::SetTimeTakenMs(int64_t value)
{
    SetMetricInternal(kTimeTakenMsNameHash, value);
    return *this;
}

const char AutofillAssistant_CollectUserDataResult::kUserDataSourceName[] = "UserDataSource";
const uint64_t AutofillAssistant_CollectUserDataResult::kUserDataSourceNameHash;

AutofillAssistant_CollectUserDataResult& AutofillAssistant_CollectUserDataResult::SetUserDataSource(int64_t value)
{
    SetMetricInternal(kUserDataSourceNameHash, value);
    return *this;
}
const char AutofillAssistant_FlowFinished::kEntryName[] = "AutofillAssistant.FlowFinished";
const uint64_t AutofillAssistant_FlowFinished::kEntryNameHash;

AutofillAssistant_FlowFinished::AutofillAssistant_FlowFinished(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_FlowFinished::AutofillAssistant_FlowFinished(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_FlowFinished::~AutofillAssistant_FlowFinished() = default;
const char AutofillAssistant_FlowFinished::kFlowFinishedStateName[] = "FlowFinishedState";
const uint64_t AutofillAssistant_FlowFinished::kFlowFinishedStateNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetFlowFinishedState(int64_t value)
{
    SetMetricInternal(kFlowFinishedStateNameHash, value);
    return *this;
}

const char AutofillAssistant_FlowFinished::kNumActionsName[] = "NumActions";
const uint64_t AutofillAssistant_FlowFinished::kNumActionsNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetNumActions(int64_t value)
{
    SetMetricInternal(kNumActionsNameHash, value);
    return *this;
}

const char AutofillAssistant_FlowFinished::kNumJsFlowActionsName[] = "NumJsFlowActions";
const uint64_t AutofillAssistant_FlowFinished::kNumJsFlowActionsNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetNumJsFlowActions(int64_t value)
{
    SetMetricInternal(kNumJsFlowActionsNameHash, value);
    return *this;
}

const char AutofillAssistant_FlowFinished::kNumRoundtripsName[] = "NumRoundtrips";
const uint64_t AutofillAssistant_FlowFinished::kNumRoundtripsNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetNumRoundtrips(int64_t value)
{
    SetMetricInternal(kNumRoundtripsNameHash, value);
    return *this;
}

const char AutofillAssistant_FlowFinished::kTotalDecodedGetActionsSizeInBytesName[] = "TotalDecodedGetActionsSizeInBytes";
const uint64_t AutofillAssistant_FlowFinished::kTotalDecodedGetActionsSizeInBytesNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetTotalDecodedGetActionsSizeInBytes(int64_t value)
{
    SetMetricInternal(kTotalDecodedGetActionsSizeInBytesNameHash, value);
    return *this;
}

const char AutofillAssistant_FlowFinished::kTotalDecodedJsFlowSizeInBytesName[] = "TotalDecodedJsFlowSizeInBytes";
const uint64_t AutofillAssistant_FlowFinished::kTotalDecodedJsFlowSizeInBytesNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetTotalDecodedJsFlowSizeInBytes(int64_t value)
{
    SetMetricInternal(kTotalDecodedJsFlowSizeInBytesNameHash, value);
    return *this;
}

const char AutofillAssistant_FlowFinished::kTotalEncodedGetActionsSizeInBytesName[] = "TotalEncodedGetActionsSizeInBytes";
const uint64_t AutofillAssistant_FlowFinished::kTotalEncodedGetActionsSizeInBytesNameHash;

AutofillAssistant_FlowFinished& AutofillAssistant_FlowFinished::SetTotalEncodedGetActionsSizeInBytes(int64_t value)
{
    SetMetricInternal(kTotalEncodedGetActionsSizeInBytesNameHash, value);
    return *this;
}
const char AutofillAssistant_InChromeTriggering::kEntryName[] = "AutofillAssistant.InChromeTriggering";
const uint64_t AutofillAssistant_InChromeTriggering::kEntryNameHash;

AutofillAssistant_InChromeTriggering::AutofillAssistant_InChromeTriggering(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_InChromeTriggering::AutofillAssistant_InChromeTriggering(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_InChromeTriggering::~AutofillAssistant_InChromeTriggering() = default;
const char AutofillAssistant_InChromeTriggering::kInChromeTriggerActionName[] = "InChromeTriggerAction";
const uint64_t AutofillAssistant_InChromeTriggering::kInChromeTriggerActionNameHash;

AutofillAssistant_InChromeTriggering& AutofillAssistant_InChromeTriggering::SetInChromeTriggerAction(int64_t value)
{
    SetMetricInternal(kInChromeTriggerActionNameHash, value);
    return *this;
}
const char AutofillAssistant_LiteScriptFinished::kEntryName[] = "AutofillAssistant.LiteScriptFinished";
const uint64_t AutofillAssistant_LiteScriptFinished::kEntryNameHash;

AutofillAssistant_LiteScriptFinished::AutofillAssistant_LiteScriptFinished(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptFinished::AutofillAssistant_LiteScriptFinished(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptFinished::~AutofillAssistant_LiteScriptFinished() = default;
const char AutofillAssistant_LiteScriptFinished::kLiteScriptFinishedName[] = "LiteScriptFinished";
const uint64_t AutofillAssistant_LiteScriptFinished::kLiteScriptFinishedNameHash;

AutofillAssistant_LiteScriptFinished& AutofillAssistant_LiteScriptFinished::SetLiteScriptFinished(int64_t value)
{
    SetMetricInternal(kLiteScriptFinishedNameHash, value);
    return *this;
}

const char AutofillAssistant_LiteScriptFinished::kTriggerUITypeName[] = "TriggerUIType";
const uint64_t AutofillAssistant_LiteScriptFinished::kTriggerUITypeNameHash;

AutofillAssistant_LiteScriptFinished& AutofillAssistant_LiteScriptFinished::SetTriggerUIType(int64_t value)
{
    SetMetricInternal(kTriggerUITypeNameHash, value);
    return *this;
}
const char AutofillAssistant_LiteScriptOnboarding::kEntryName[] = "AutofillAssistant.LiteScriptOnboarding";
const uint64_t AutofillAssistant_LiteScriptOnboarding::kEntryNameHash;

AutofillAssistant_LiteScriptOnboarding::AutofillAssistant_LiteScriptOnboarding(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptOnboarding::AutofillAssistant_LiteScriptOnboarding(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptOnboarding::~AutofillAssistant_LiteScriptOnboarding() = default;
const char AutofillAssistant_LiteScriptOnboarding::kLiteScriptOnboardingName[] = "LiteScriptOnboarding";
const uint64_t AutofillAssistant_LiteScriptOnboarding::kLiteScriptOnboardingNameHash;

AutofillAssistant_LiteScriptOnboarding& AutofillAssistant_LiteScriptOnboarding::SetLiteScriptOnboarding(int64_t value)
{
    SetMetricInternal(kLiteScriptOnboardingNameHash, value);
    return *this;
}

const char AutofillAssistant_LiteScriptOnboarding::kTriggerUITypeName[] = "TriggerUIType";
const uint64_t AutofillAssistant_LiteScriptOnboarding::kTriggerUITypeNameHash;

AutofillAssistant_LiteScriptOnboarding& AutofillAssistant_LiteScriptOnboarding::SetTriggerUIType(int64_t value)
{
    SetMetricInternal(kTriggerUITypeNameHash, value);
    return *this;
}
const char AutofillAssistant_LiteScriptShownToUser::kEntryName[] = "AutofillAssistant.LiteScriptShownToUser";
const uint64_t AutofillAssistant_LiteScriptShownToUser::kEntryNameHash;

AutofillAssistant_LiteScriptShownToUser::AutofillAssistant_LiteScriptShownToUser(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptShownToUser::AutofillAssistant_LiteScriptShownToUser(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptShownToUser::~AutofillAssistant_LiteScriptShownToUser() = default;
const char AutofillAssistant_LiteScriptShownToUser::kLiteScriptShownToUserName[] = "LiteScriptShownToUser";
const uint64_t AutofillAssistant_LiteScriptShownToUser::kLiteScriptShownToUserNameHash;

AutofillAssistant_LiteScriptShownToUser& AutofillAssistant_LiteScriptShownToUser::SetLiteScriptShownToUser(int64_t value)
{
    SetMetricInternal(kLiteScriptShownToUserNameHash, value);
    return *this;
}

const char AutofillAssistant_LiteScriptShownToUser::kTriggerUITypeName[] = "TriggerUIType";
const uint64_t AutofillAssistant_LiteScriptShownToUser::kTriggerUITypeNameHash;

AutofillAssistant_LiteScriptShownToUser& AutofillAssistant_LiteScriptShownToUser::SetTriggerUIType(int64_t value)
{
    SetMetricInternal(kTriggerUITypeNameHash, value);
    return *this;
}
const char AutofillAssistant_LiteScriptStarted::kEntryName[] = "AutofillAssistant.LiteScriptStarted";
const uint64_t AutofillAssistant_LiteScriptStarted::kEntryNameHash;

AutofillAssistant_LiteScriptStarted::AutofillAssistant_LiteScriptStarted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptStarted::AutofillAssistant_LiteScriptStarted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_LiteScriptStarted::~AutofillAssistant_LiteScriptStarted() = default;
const char AutofillAssistant_LiteScriptStarted::kLiteScriptStartedName[] = "LiteScriptStarted";
const uint64_t AutofillAssistant_LiteScriptStarted::kLiteScriptStartedNameHash;

AutofillAssistant_LiteScriptStarted& AutofillAssistant_LiteScriptStarted::SetLiteScriptStarted(int64_t value)
{
    SetMetricInternal(kLiteScriptStartedNameHash, value);
    return *this;
}

const char AutofillAssistant_LiteScriptStarted::kTriggerUITypeName[] = "TriggerUIType";
const uint64_t AutofillAssistant_LiteScriptStarted::kTriggerUITypeNameHash;

AutofillAssistant_LiteScriptStarted& AutofillAssistant_LiteScriptStarted::SetTriggerUIType(int64_t value)
{
    SetMetricInternal(kTriggerUITypeNameHash, value);
    return *this;
}
const char AutofillAssistant_RegularScriptOnboarding::kEntryName[] = "AutofillAssistant.RegularScriptOnboarding";
const uint64_t AutofillAssistant_RegularScriptOnboarding::kEntryNameHash;

AutofillAssistant_RegularScriptOnboarding::AutofillAssistant_RegularScriptOnboarding(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_RegularScriptOnboarding::AutofillAssistant_RegularScriptOnboarding(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_RegularScriptOnboarding::~AutofillAssistant_RegularScriptOnboarding() = default;
const char AutofillAssistant_RegularScriptOnboarding::kOnboardingName[] = "Onboarding";
const uint64_t AutofillAssistant_RegularScriptOnboarding::kOnboardingNameHash;

AutofillAssistant_RegularScriptOnboarding& AutofillAssistant_RegularScriptOnboarding::SetOnboarding(int64_t value)
{
    SetMetricInternal(kOnboardingNameHash, value);
    return *this;
}
const char AutofillAssistant_StartRequest::kEntryName[] = "AutofillAssistant.StartRequest";
const uint64_t AutofillAssistant_StartRequest::kEntryNameHash;

AutofillAssistant_StartRequest::AutofillAssistant_StartRequest(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_StartRequest::AutofillAssistant_StartRequest(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_StartRequest::~AutofillAssistant_StartRequest() = default;
const char AutofillAssistant_StartRequest::kCallerName[] = "Caller";
const uint64_t AutofillAssistant_StartRequest::kCallerNameHash;

AutofillAssistant_StartRequest& AutofillAssistant_StartRequest::SetCaller(int64_t value)
{
    SetMetricInternal(kCallerNameHash, value);
    return *this;
}

const char AutofillAssistant_StartRequest::kExperimentsName[] = "Experiments";
const uint64_t AutofillAssistant_StartRequest::kExperimentsNameHash;

AutofillAssistant_StartRequest& AutofillAssistant_StartRequest::SetExperiments(int64_t value)
{
    SetMetricInternal(kExperimentsNameHash, value);
    return *this;
}

const char AutofillAssistant_StartRequest::kIntentName[] = "Intent";
const uint64_t AutofillAssistant_StartRequest::kIntentNameHash;

AutofillAssistant_StartRequest& AutofillAssistant_StartRequest::SetIntent(int64_t value)
{
    SetMetricInternal(kIntentNameHash, value);
    return *this;
}

const char AutofillAssistant_StartRequest::kSourceName[] = "Source";
const uint64_t AutofillAssistant_StartRequest::kSourceNameHash;

AutofillAssistant_StartRequest& AutofillAssistant_StartRequest::SetSource(int64_t value)
{
    SetMetricInternal(kSourceNameHash, value);
    return *this;
}

const char AutofillAssistant_StartRequest::kStartedName[] = "Started";
const uint64_t AutofillAssistant_StartRequest::kStartedNameHash;

AutofillAssistant_StartRequest& AutofillAssistant_StartRequest::SetStarted(int64_t value)
{
    SetMetricInternal(kStartedNameHash, value);
    return *this;
}
const char AutofillAssistant_Timing::kEntryName[] = "AutofillAssistant.Timing";
const uint64_t AutofillAssistant_Timing::kEntryNameHash;

AutofillAssistant_Timing::AutofillAssistant_Timing(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_Timing::AutofillAssistant_Timing(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

AutofillAssistant_Timing::~AutofillAssistant_Timing() = default;
const char AutofillAssistant_Timing::kTriggerConditionEvaluationMsName[] = "TriggerConditionEvaluationMs";
const uint64_t AutofillAssistant_Timing::kTriggerConditionEvaluationMsNameHash;

AutofillAssistant_Timing& AutofillAssistant_Timing::SetTriggerConditionEvaluationMs(int64_t value)
{
    SetMetricInternal(kTriggerConditionEvaluationMsNameHash, value);
    return *this;
}
const char BackForwardCacheDisabledForRenderFrameHostReason::kEntryName[] = "BackForwardCacheDisabledForRenderFrameHostReason";
const uint64_t BackForwardCacheDisabledForRenderFrameHostReason::kEntryNameHash;

BackForwardCacheDisabledForRenderFrameHostReason::BackForwardCacheDisabledForRenderFrameHostReason(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackForwardCacheDisabledForRenderFrameHostReason::BackForwardCacheDisabledForRenderFrameHostReason(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackForwardCacheDisabledForRenderFrameHostReason::~BackForwardCacheDisabledForRenderFrameHostReason() = default;
const char BackForwardCacheDisabledForRenderFrameHostReason::kReason2Name[] = "Reason2";
const uint64_t BackForwardCacheDisabledForRenderFrameHostReason::kReason2NameHash;

BackForwardCacheDisabledForRenderFrameHostReason& BackForwardCacheDisabledForRenderFrameHostReason::SetReason2(int64_t value)
{
    SetMetricInternal(kReason2NameHash, value);
    return *this;
}
const char BackForwardCacheDisallowActivationReason::kEntryName[] = "BackForwardCacheDisallowActivationReason";
const uint64_t BackForwardCacheDisallowActivationReason::kEntryNameHash;

BackForwardCacheDisallowActivationReason::BackForwardCacheDisallowActivationReason(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackForwardCacheDisallowActivationReason::BackForwardCacheDisallowActivationReason(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackForwardCacheDisallowActivationReason::~BackForwardCacheDisallowActivationReason() = default;
const char BackForwardCacheDisallowActivationReason::kReasonName[] = "Reason";
const uint64_t BackForwardCacheDisallowActivationReason::kReasonNameHash;

BackForwardCacheDisallowActivationReason& BackForwardCacheDisallowActivationReason::SetReason(int64_t value)
{
    SetMetricInternal(kReasonNameHash, value);
    return *this;
}
const char BackgroundFetch::kEntryName[] = "BackgroundFetch";
const uint64_t BackgroundFetch::kEntryNameHash;

BackgroundFetch::BackgroundFetch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundFetch::BackgroundFetch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundFetch::~BackgroundFetch() = default;
const char BackgroundFetch::kDeniedDueToPermissionsName[] = "DeniedDueToPermissions";
const uint64_t BackgroundFetch::kDeniedDueToPermissionsNameHash;

BackgroundFetch& BackgroundFetch::SetDeniedDueToPermissions(int64_t value)
{
    SetMetricInternal(kDeniedDueToPermissionsNameHash, value);
    return *this;
}

const char BackgroundFetch::kDownloadTotalName[] = "DownloadTotal";
const uint64_t BackgroundFetch::kDownloadTotalNameHash;

BackgroundFetch& BackgroundFetch::SetDownloadTotal(int64_t value)
{
    SetMetricInternal(kDownloadTotalNameHash, value);
    return *this;
}

const char BackgroundFetch::kHasTitleName[] = "HasTitle";
const uint64_t BackgroundFetch::kHasTitleNameHash;

BackgroundFetch& BackgroundFetch::SetHasTitle(int64_t value)
{
    SetMetricInternal(kHasTitleNameHash, value);
    return *this;
}

const char BackgroundFetch::kNumIconsName[] = "NumIcons";
const uint64_t BackgroundFetch::kNumIconsNameHash;

BackgroundFetch& BackgroundFetch::SetNumIcons(int64_t value)
{
    SetMetricInternal(kNumIconsNameHash, value);
    return *this;
}

const char BackgroundFetch::kNumRequestsInFetchName[] = "NumRequestsInFetch";
const uint64_t BackgroundFetch::kNumRequestsInFetchNameHash;

BackgroundFetch& BackgroundFetch::SetNumRequestsInFetch(int64_t value)
{
    SetMetricInternal(kNumRequestsInFetchNameHash, value);
    return *this;
}

const char BackgroundFetch::kRatioOfIdealToChosenIconSizeName[] = "RatioOfIdealToChosenIconSize";
const uint64_t BackgroundFetch::kRatioOfIdealToChosenIconSizeNameHash;

BackgroundFetch& BackgroundFetch::SetRatioOfIdealToChosenIconSize(int64_t value)
{
    SetMetricInternal(kRatioOfIdealToChosenIconSizeNameHash, value);
    return *this;
}
const char BackgroundFetchDeletingRegistration::kEntryName[] = "BackgroundFetchDeletingRegistration";
const uint64_t BackgroundFetchDeletingRegistration::kEntryNameHash;

BackgroundFetchDeletingRegistration::BackgroundFetchDeletingRegistration(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundFetchDeletingRegistration::BackgroundFetchDeletingRegistration(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundFetchDeletingRegistration::~BackgroundFetchDeletingRegistration() = default;
const char BackgroundFetchDeletingRegistration::kUserInitiatedAbortName[] = "UserInitiatedAbort";
const uint64_t BackgroundFetchDeletingRegistration::kUserInitiatedAbortNameHash;

BackgroundFetchDeletingRegistration& BackgroundFetchDeletingRegistration::SetUserInitiatedAbort(int64_t value)
{
    SetMetricInternal(kUserInitiatedAbortNameHash, value);
    return *this;
}
const char BackgroundSyncCompleted::kEntryName[] = "BackgroundSyncCompleted";
const uint64_t BackgroundSyncCompleted::kEntryNameHash;

BackgroundSyncCompleted::BackgroundSyncCompleted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundSyncCompleted::BackgroundSyncCompleted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundSyncCompleted::~BackgroundSyncCompleted() = default;
const char BackgroundSyncCompleted::kMaxAttemptsName[] = "MaxAttempts";
const uint64_t BackgroundSyncCompleted::kMaxAttemptsNameHash;

BackgroundSyncCompleted& BackgroundSyncCompleted::SetMaxAttempts(int64_t value)
{
    SetMetricInternal(kMaxAttemptsNameHash, value);
    return *this;
}

const char BackgroundSyncCompleted::kNumAttemptsName[] = "NumAttempts";
const uint64_t BackgroundSyncCompleted::kNumAttemptsNameHash;

BackgroundSyncCompleted& BackgroundSyncCompleted::SetNumAttempts(int64_t value)
{
    SetMetricInternal(kNumAttemptsNameHash, value);
    return *this;
}

const char BackgroundSyncCompleted::kStatusName[] = "Status";
const uint64_t BackgroundSyncCompleted::kStatusNameHash;

BackgroundSyncCompleted& BackgroundSyncCompleted::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}
const char BackgroundSyncRegistered::kEntryName[] = "BackgroundSyncRegistered";
const uint64_t BackgroundSyncRegistered::kEntryNameHash;

BackgroundSyncRegistered::BackgroundSyncRegistered(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundSyncRegistered::BackgroundSyncRegistered(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BackgroundSyncRegistered::~BackgroundSyncRegistered() = default;
const char BackgroundSyncRegistered::kCanFireName[] = "CanFire";
const uint64_t BackgroundSyncRegistered::kCanFireNameHash;

BackgroundSyncRegistered& BackgroundSyncRegistered::SetCanFire(int64_t value)
{
    SetMetricInternal(kCanFireNameHash, value);
    return *this;
}

const char BackgroundSyncRegistered::kIsReregisteredName[] = "IsReregistered";
const uint64_t BackgroundSyncRegistered::kIsReregisteredNameHash;

BackgroundSyncRegistered& BackgroundSyncRegistered::SetIsReregistered(int64_t value)
{
    SetMetricInternal(kIsReregisteredNameHash, value);
    return *this;
}
const char Badging::kEntryName[] = "Badging";
const uint64_t Badging::kEntryNameHash;

Badging::Badging(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Badging::Badging(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Badging::~Badging() = default;
const char Badging::kUpdateAppBadgeName[] = "UpdateAppBadge";
const uint64_t Badging::kUpdateAppBadgeNameHash;

Badging& Badging::SetUpdateAppBadge(int64_t value)
{
    SetMetricInternal(kUpdateAppBadgeNameHash, value);
    return *this;
}
const char Blink_AutomaticLazyLoadFrame::kEntryName[] = "Blink.AutomaticLazyLoadFrame";
const uint64_t Blink_AutomaticLazyLoadFrame::kEntryNameHash;

Blink_AutomaticLazyLoadFrame::Blink_AutomaticLazyLoadFrame(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_AutomaticLazyLoadFrame::Blink_AutomaticLazyLoadFrame(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_AutomaticLazyLoadFrame::~Blink_AutomaticLazyLoadFrame() = default;
const char Blink_AutomaticLazyLoadFrame::kLazyAdsFrameCountName[] = "LazyAdsFrameCount";
const uint64_t Blink_AutomaticLazyLoadFrame::kLazyAdsFrameCountNameHash;

Blink_AutomaticLazyLoadFrame& Blink_AutomaticLazyLoadFrame::SetLazyAdsFrameCount(int64_t value)
{
    SetMetricInternal(kLazyAdsFrameCountNameHash, value);
    return *this;
}

const char Blink_AutomaticLazyLoadFrame::kLazyEmbedsFrameCountName[] = "LazyEmbedsFrameCount";
const uint64_t Blink_AutomaticLazyLoadFrame::kLazyEmbedsFrameCountNameHash;

Blink_AutomaticLazyLoadFrame& Blink_AutomaticLazyLoadFrame::SetLazyEmbedsFrameCount(int64_t value)
{
    SetMetricInternal(kLazyEmbedsFrameCountNameHash, value);
    return *this;
}
const char Blink_ContextMenu_ImageSelection::kEntryName[] = "Blink.ContextMenu.ImageSelection";
const uint64_t Blink_ContextMenu_ImageSelection::kEntryNameHash;

Blink_ContextMenu_ImageSelection::Blink_ContextMenu_ImageSelection(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_ContextMenu_ImageSelection::Blink_ContextMenu_ImageSelection(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_ContextMenu_ImageSelection::~Blink_ContextMenu_ImageSelection() = default;
const char Blink_ContextMenu_ImageSelection::kOutcomeName[] = "Outcome";
const uint64_t Blink_ContextMenu_ImageSelection::kOutcomeNameHash;

Blink_ContextMenu_ImageSelection& Blink_ContextMenu_ImageSelection::SetOutcome(int64_t value)
{
    SetMetricInternal(kOutcomeNameHash, value);
    return *this;
}
const char Blink_DeveloperMetricsRare::kEntryName[] = "Blink.DeveloperMetricsRare";
const uint64_t Blink_DeveloperMetricsRare::kEntryNameHash;

Blink_DeveloperMetricsRare::Blink_DeveloperMetricsRare(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_DeveloperMetricsRare::Blink_DeveloperMetricsRare(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_DeveloperMetricsRare::~Blink_DeveloperMetricsRare() = default;
const char Blink_DeveloperMetricsRare::kFeatureName[] = "Feature";
const uint64_t Blink_DeveloperMetricsRare::kFeatureNameHash;

Blink_DeveloperMetricsRare& Blink_DeveloperMetricsRare::SetFeature(int64_t value)
{
    SetMetricInternal(kFeatureNameHash, value);
    return *this;
}

const char Blink_DeveloperMetricsRare::kIsMainFrameFeatureName[] = "IsMainFrameFeature";
const uint64_t Blink_DeveloperMetricsRare::kIsMainFrameFeatureNameHash;

Blink_DeveloperMetricsRare& Blink_DeveloperMetricsRare::SetIsMainFrameFeature(int64_t value)
{
    SetMetricInternal(kIsMainFrameFeatureNameHash, value);
    return *this;
}
const char Blink_FedCm::kEntryName[] = "Blink.FedCm";
const uint64_t Blink_FedCm::kEntryNameHash;

Blink_FedCm::Blink_FedCm(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_FedCm::Blink_FedCm(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_FedCm::~Blink_FedCm() = default;
const char Blink_FedCm::kFedCmSessionIDName[] = "FedCmSessionID";
const uint64_t Blink_FedCm::kFedCmSessionIDNameHash;

Blink_FedCm& Blink_FedCm::SetFedCmSessionID(int64_t value)
{
    SetMetricInternal(kFedCmSessionIDNameHash, value);
    return *this;
}

const char Blink_FedCm::kStatus_RequestIdTokenName[] = "Status.RequestIdToken";
const uint64_t Blink_FedCm::kStatus_RequestIdTokenNameHash;

Blink_FedCm& Blink_FedCm::SetStatus_RequestIdToken(int64_t value)
{
    SetMetricInternal(kStatus_RequestIdTokenNameHash, value);
    return *this;
}

const char Blink_FedCm::kTiming_CancelOnDialogName[] = "Timing.CancelOnDialog";
const uint64_t Blink_FedCm::kTiming_CancelOnDialogNameHash;

Blink_FedCm& Blink_FedCm::SetTiming_CancelOnDialog(int64_t value)
{
    SetMetricInternal(kTiming_CancelOnDialogNameHash, value);
    return *this;
}

const char Blink_FedCm::kTiming_ContinueOnDialogName[] = "Timing.ContinueOnDialog";
const uint64_t Blink_FedCm::kTiming_ContinueOnDialogNameHash;

Blink_FedCm& Blink_FedCm::SetTiming_ContinueOnDialog(int64_t value)
{
    SetMetricInternal(kTiming_ContinueOnDialogNameHash, value);
    return *this;
}

const char Blink_FedCm::kTiming_IdTokenResponseName[] = "Timing.IdTokenResponse";
const uint64_t Blink_FedCm::kTiming_IdTokenResponseNameHash;

Blink_FedCm& Blink_FedCm::SetTiming_IdTokenResponse(int64_t value)
{
    SetMetricInternal(kTiming_IdTokenResponseNameHash, value);
    return *this;
}

const char Blink_FedCm::kTiming_ShowAccountsDialogName[] = "Timing.ShowAccountsDialog";
const uint64_t Blink_FedCm::kTiming_ShowAccountsDialogNameHash;

Blink_FedCm& Blink_FedCm::SetTiming_ShowAccountsDialog(int64_t value)
{
    SetMetricInternal(kTiming_ShowAccountsDialogNameHash, value);
    return *this;
}

const char Blink_FedCm::kTiming_TurnaroundTimeName[] = "Timing.TurnaroundTime";
const uint64_t Blink_FedCm::kTiming_TurnaroundTimeNameHash;

Blink_FedCm& Blink_FedCm::SetTiming_TurnaroundTime(int64_t value)
{
    SetMetricInternal(kTiming_TurnaroundTimeNameHash, value);
    return *this;
}
const char Blink_FedCmIdp::kEntryName[] = "Blink.FedCmIdp";
const uint64_t Blink_FedCmIdp::kEntryNameHash;

Blink_FedCmIdp::Blink_FedCmIdp(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_FedCmIdp::Blink_FedCmIdp(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_FedCmIdp::~Blink_FedCmIdp() = default;
const char Blink_FedCmIdp::kFedCmSessionIDName[] = "FedCmSessionID";
const uint64_t Blink_FedCmIdp::kFedCmSessionIDNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetFedCmSessionID(int64_t value)
{
    SetMetricInternal(kFedCmSessionIDNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kStatus_RequestIdTokenName[] = "Status.RequestIdToken";
const uint64_t Blink_FedCmIdp::kStatus_RequestIdTokenNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetStatus_RequestIdToken(int64_t value)
{
    SetMetricInternal(kStatus_RequestIdTokenNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kStatus_SignInStateMatchName[] = "Status.SignInStateMatch";
const uint64_t Blink_FedCmIdp::kStatus_SignInStateMatchNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetStatus_SignInStateMatch(int64_t value)
{
    SetMetricInternal(kStatus_SignInStateMatchNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kTiming_CancelOnDialogName[] = "Timing.CancelOnDialog";
const uint64_t Blink_FedCmIdp::kTiming_CancelOnDialogNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetTiming_CancelOnDialog(int64_t value)
{
    SetMetricInternal(kTiming_CancelOnDialogNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kTiming_ContinueOnDialogName[] = "Timing.ContinueOnDialog";
const uint64_t Blink_FedCmIdp::kTiming_ContinueOnDialogNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetTiming_ContinueOnDialog(int64_t value)
{
    SetMetricInternal(kTiming_ContinueOnDialogNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kTiming_IdTokenResponseName[] = "Timing.IdTokenResponse";
const uint64_t Blink_FedCmIdp::kTiming_IdTokenResponseNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetTiming_IdTokenResponse(int64_t value)
{
    SetMetricInternal(kTiming_IdTokenResponseNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kTiming_ShowAccountsDialogName[] = "Timing.ShowAccountsDialog";
const uint64_t Blink_FedCmIdp::kTiming_ShowAccountsDialogNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetTiming_ShowAccountsDialog(int64_t value)
{
    SetMetricInternal(kTiming_ShowAccountsDialogNameHash, value);
    return *this;
}

const char Blink_FedCmIdp::kTiming_TurnaroundTimeName[] = "Timing.TurnaroundTime";
const uint64_t Blink_FedCmIdp::kTiming_TurnaroundTimeNameHash;

Blink_FedCmIdp& Blink_FedCmIdp::SetTiming_TurnaroundTime(int64_t value)
{
    SetMetricInternal(kTiming_TurnaroundTimeNameHash, value);
    return *this;
}
const char Blink_FindInPage::kEntryName[] = "Blink.FindInPage";
const uint64_t Blink_FindInPage::kEntryNameHash;

Blink_FindInPage::Blink_FindInPage(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_FindInPage::Blink_FindInPage(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_FindInPage::~Blink_FindInPage() = default;
const char Blink_FindInPage::kBeforematchExpandedHiddenMatchableName[] = "BeforematchExpandedHiddenMatchable";
const uint64_t Blink_FindInPage::kBeforematchExpandedHiddenMatchableNameHash;

Blink_FindInPage& Blink_FindInPage::SetBeforematchExpandedHiddenMatchable(int64_t value)
{
    SetMetricInternal(kBeforematchExpandedHiddenMatchableNameHash, value);
    return *this;
}

const char Blink_FindInPage::kDidHaveRenderSubtreeMatchName[] = "DidHaveRenderSubtreeMatch";
const uint64_t Blink_FindInPage::kDidHaveRenderSubtreeMatchNameHash;

Blink_FindInPage& Blink_FindInPage::SetDidHaveRenderSubtreeMatch(int64_t value)
{
    SetMetricInternal(kDidHaveRenderSubtreeMatchNameHash, value);
    return *this;
}

const char Blink_FindInPage::kDidSearchName[] = "DidSearch";
const uint64_t Blink_FindInPage::kDidSearchNameHash;

Blink_FindInPage& Blink_FindInPage::SetDidSearch(int64_t value)
{
    SetMetricInternal(kDidSearchNameHash, value);
    return *this;
}
const char Blink_HTMLParsing::kEntryName[] = "Blink.HTMLParsing";
const uint64_t Blink_HTMLParsing::kEntryNameHash;

Blink_HTMLParsing::Blink_HTMLParsing(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_HTMLParsing::Blink_HTMLParsing(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_HTMLParsing::~Blink_HTMLParsing() = default;
const char Blink_HTMLParsing::kChunkCountName[] = "ChunkCount";
const uint64_t Blink_HTMLParsing::kChunkCountNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetChunkCount(int64_t value)
{
    SetMetricInternal(kChunkCountNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kParsingTimeMaxName[] = "ParsingTimeMax";
const uint64_t Blink_HTMLParsing::kParsingTimeMaxNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeMax(int64_t value)
{
    SetMetricInternal(kParsingTimeMaxNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kParsingTimeMinName[] = "ParsingTimeMin";
const uint64_t Blink_HTMLParsing::kParsingTimeMinNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeMin(int64_t value)
{
    SetMetricInternal(kParsingTimeMinNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kParsingTimeTotalName[] = "ParsingTimeTotal";
const uint64_t Blink_HTMLParsing::kParsingTimeTotalNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetParsingTimeTotal(int64_t value)
{
    SetMetricInternal(kParsingTimeTotalNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kTokensParsedAverageName[] = "TokensParsedAverage";
const uint64_t Blink_HTMLParsing::kTokensParsedAverageNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedAverage(int64_t value)
{
    SetMetricInternal(kTokensParsedAverageNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kTokensParsedMaxName[] = "TokensParsedMax";
const uint64_t Blink_HTMLParsing::kTokensParsedMaxNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedMax(int64_t value)
{
    SetMetricInternal(kTokensParsedMaxNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kTokensParsedMinName[] = "TokensParsedMin";
const uint64_t Blink_HTMLParsing::kTokensParsedMinNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedMin(int64_t value)
{
    SetMetricInternal(kTokensParsedMinNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kTokensParsedTotalName[] = "TokensParsedTotal";
const uint64_t Blink_HTMLParsing::kTokensParsedTotalNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetTokensParsedTotal(int64_t value)
{
    SetMetricInternal(kTokensParsedTotalNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kYieldedTimeAverageName[] = "YieldedTimeAverage";
const uint64_t Blink_HTMLParsing::kYieldedTimeAverageNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeAverage(int64_t value)
{
    SetMetricInternal(kYieldedTimeAverageNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kYieldedTimeMaxName[] = "YieldedTimeMax";
const uint64_t Blink_HTMLParsing::kYieldedTimeMaxNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeMax(int64_t value)
{
    SetMetricInternal(kYieldedTimeMaxNameHash, value);
    return *this;
}

const char Blink_HTMLParsing::kYieldedTimeMinName[] = "YieldedTimeMin";
const uint64_t Blink_HTMLParsing::kYieldedTimeMinNameHash;

Blink_HTMLParsing& Blink_HTMLParsing::SetYieldedTimeMin(int64_t value)
{
    SetMetricInternal(kYieldedTimeMinNameHash, value);
    return *this;
}
const char Blink_PageLoad::kEntryName[] = "Blink.PageLoad";
const uint64_t Blink_PageLoad::kEntryNameHash;

Blink_PageLoad::Blink_PageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PageLoad::Blink_PageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PageLoad::~Blink_PageLoad() = default;
const char Blink_PageLoad::kAccessibilityName[] = "Accessibility";
const uint64_t Blink_PageLoad::kAccessibilityNameHash;

Blink_PageLoad& Blink_PageLoad::SetAccessibility(int64_t value)
{
    SetMetricInternal(kAccessibilityNameHash, value);
    return *this;
}

const char Blink_PageLoad::kAnchorElementMetricsIntersectionObserverName[] = "AnchorElementMetricsIntersectionObserver";
const uint64_t Blink_PageLoad::kAnchorElementMetricsIntersectionObserverNameHash;

Blink_PageLoad& Blink_PageLoad::SetAnchorElementMetricsIntersectionObserver(int64_t value)
{
    SetMetricInternal(kAnchorElementMetricsIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_PageLoad::kAnimateName[] = "Animate";
const uint64_t Blink_PageLoad::kAnimateNameHash;

Blink_PageLoad& Blink_PageLoad::SetAnimate(int64_t value)
{
    SetMetricInternal(kAnimateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kCompositingCommitName[] = "CompositingCommit";
const uint64_t Blink_PageLoad::kCompositingCommitNameHash;

Blink_PageLoad& Blink_PageLoad::SetCompositingCommit(int64_t value)
{
    SetMetricInternal(kCompositingCommitNameHash, value);
    return *this;
}

const char Blink_PageLoad::kCompositingInputsName[] = "CompositingInputs";
const uint64_t Blink_PageLoad::kCompositingInputsNameHash;

Blink_PageLoad& Blink_PageLoad::SetCompositingInputs(int64_t value)
{
    SetMetricInternal(kCompositingInputsNameHash, value);
    return *this;
}

const char Blink_PageLoad::kContentDocumentUpdateName[] = "ContentDocumentUpdate";
const uint64_t Blink_PageLoad::kContentDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetContentDocumentUpdate(int64_t value)
{
    SetMetricInternal(kContentDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kDisplayLockIntersectionObserverName[] = "DisplayLockIntersectionObserver";
const uint64_t Blink_PageLoad::kDisplayLockIntersectionObserverNameHash;

Blink_PageLoad& Blink_PageLoad::SetDisplayLockIntersectionObserver(int64_t value)
{
    SetMetricInternal(kDisplayLockIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_PageLoad::kForcedStyleAndLayoutName[] = "ForcedStyleAndLayout";
const uint64_t Blink_PageLoad::kForcedStyleAndLayoutNameHash;

Blink_PageLoad& Blink_PageLoad::SetForcedStyleAndLayout(int64_t value)
{
    SetMetricInternal(kForcedStyleAndLayoutNameHash, value);
    return *this;
}

const char Blink_PageLoad::kHandleInputEventsName[] = "HandleInputEvents";
const uint64_t Blink_PageLoad::kHandleInputEventsNameHash;

Blink_PageLoad& Blink_PageLoad::SetHandleInputEvents(int64_t value)
{
    SetMetricInternal(kHandleInputEventsNameHash, value);
    return *this;
}

const char Blink_PageLoad::kHitTestDocumentUpdateName[] = "HitTestDocumentUpdate";
const uint64_t Blink_PageLoad::kHitTestDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetHitTestDocumentUpdate(int64_t value)
{
    SetMetricInternal(kHitTestDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kImplCompositorCommitName[] = "ImplCompositorCommit";
const uint64_t Blink_PageLoad::kImplCompositorCommitNameHash;

Blink_PageLoad& Blink_PageLoad::SetImplCompositorCommit(int64_t value)
{
    SetMetricInternal(kImplCompositorCommitNameHash, value);
    return *this;
}

const char Blink_PageLoad::kIntersectionObservationName[] = "IntersectionObservation";
const uint64_t Blink_PageLoad::kIntersectionObservationNameHash;

Blink_PageLoad& Blink_PageLoad::SetIntersectionObservation(int64_t value)
{
    SetMetricInternal(kIntersectionObservationNameHash, value);
    return *this;
}

const char Blink_PageLoad::kIntersectionObservationInternalCountName[] = "IntersectionObservationInternalCount";
const uint64_t Blink_PageLoad::kIntersectionObservationInternalCountNameHash;

Blink_PageLoad& Blink_PageLoad::SetIntersectionObservationInternalCount(int64_t value)
{
    SetMetricInternal(kIntersectionObservationInternalCountNameHash, value);
    return *this;
}

const char Blink_PageLoad::kIntersectionObservationJavascriptCountName[] = "IntersectionObservationJavascriptCount";
const uint64_t Blink_PageLoad::kIntersectionObservationJavascriptCountNameHash;

Blink_PageLoad& Blink_PageLoad::SetIntersectionObservationJavascriptCount(int64_t value)
{
    SetMetricInternal(kIntersectionObservationJavascriptCountNameHash, value);
    return *this;
}

const char Blink_PageLoad::kJavascriptDocumentUpdateName[] = "JavascriptDocumentUpdate";
const uint64_t Blink_PageLoad::kJavascriptDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetJavascriptDocumentUpdate(int64_t value)
{
    SetMetricInternal(kJavascriptDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kJavascriptIntersectionObserverName[] = "JavascriptIntersectionObserver";
const uint64_t Blink_PageLoad::kJavascriptIntersectionObserverNameHash;

Blink_PageLoad& Blink_PageLoad::SetJavascriptIntersectionObserver(int64_t value)
{
    SetMetricInternal(kJavascriptIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_PageLoad::kLayoutName[] = "Layout";
const uint64_t Blink_PageLoad::kLayoutNameHash;

Blink_PageLoad& Blink_PageLoad::SetLayout(int64_t value)
{
    SetMetricInternal(kLayoutNameHash, value);
    return *this;
}

const char Blink_PageLoad::kLazyLoadIntersectionObserverName[] = "LazyLoadIntersectionObserver";
const uint64_t Blink_PageLoad::kLazyLoadIntersectionObserverNameHash;

Blink_PageLoad& Blink_PageLoad::SetLazyLoadIntersectionObserver(int64_t value)
{
    SetMetricInternal(kLazyLoadIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_PageLoad::kMainFrameName[] = "MainFrame";
const uint64_t Blink_PageLoad::kMainFrameNameHash;

Blink_PageLoad& Blink_PageLoad::SetMainFrame(int64_t value)
{
    SetMetricInternal(kMainFrameNameHash, value);
    return *this;
}

const char Blink_PageLoad::kMediaIntersectionObserverName[] = "MediaIntersectionObserver";
const uint64_t Blink_PageLoad::kMediaIntersectionObserverNameHash;

Blink_PageLoad& Blink_PageLoad::SetMediaIntersectionObserver(int64_t value)
{
    SetMetricInternal(kMediaIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_PageLoad::kPaintName[] = "Paint";
const uint64_t Blink_PageLoad::kPaintNameHash;

Blink_PageLoad& Blink_PageLoad::SetPaint(int64_t value)
{
    SetMetricInternal(kPaintNameHash, value);
    return *this;
}

const char Blink_PageLoad::kParseStyleSheetName[] = "ParseStyleSheet";
const uint64_t Blink_PageLoad::kParseStyleSheetNameHash;

Blink_PageLoad& Blink_PageLoad::SetParseStyleSheet(int64_t value)
{
    SetMetricInternal(kParseStyleSheetNameHash, value);
    return *this;
}

const char Blink_PageLoad::kPrePaintName[] = "PrePaint";
const uint64_t Blink_PageLoad::kPrePaintNameHash;

Blink_PageLoad& Blink_PageLoad::SetPrePaint(int64_t value)
{
    SetMetricInternal(kPrePaintNameHash, value);
    return *this;
}

const char Blink_PageLoad::kScrollDocumentUpdateName[] = "ScrollDocumentUpdate";
const uint64_t Blink_PageLoad::kScrollDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetScrollDocumentUpdate(int64_t value)
{
    SetMetricInternal(kScrollDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kServiceDocumentUpdateName[] = "ServiceDocumentUpdate";
const uint64_t Blink_PageLoad::kServiceDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetServiceDocumentUpdate(int64_t value)
{
    SetMetricInternal(kServiceDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kStyleName[] = "Style";
const uint64_t Blink_PageLoad::kStyleNameHash;

Blink_PageLoad& Blink_PageLoad::SetStyle(int64_t value)
{
    SetMetricInternal(kStyleNameHash, value);
    return *this;
}

const char Blink_PageLoad::kUpdateLayersName[] = "UpdateLayers";
const uint64_t Blink_PageLoad::kUpdateLayersNameHash;

Blink_PageLoad& Blink_PageLoad::SetUpdateLayers(int64_t value)
{
    SetMetricInternal(kUpdateLayersNameHash, value);
    return *this;
}

const char Blink_PageLoad::kUpdateViewportIntersectionName[] = "UpdateViewportIntersection";
const uint64_t Blink_PageLoad::kUpdateViewportIntersectionNameHash;

Blink_PageLoad& Blink_PageLoad::SetUpdateViewportIntersection(int64_t value)
{
    SetMetricInternal(kUpdateViewportIntersectionNameHash, value);
    return *this;
}

const char Blink_PageLoad::kUserDrivenDocumentUpdateName[] = "UserDrivenDocumentUpdate";
const uint64_t Blink_PageLoad::kUserDrivenDocumentUpdateNameHash;

Blink_PageLoad& Blink_PageLoad::SetUserDrivenDocumentUpdate(int64_t value)
{
    SetMetricInternal(kUserDrivenDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_PageLoad::kWaitForCommitName[] = "WaitForCommit";
const uint64_t Blink_PageLoad::kWaitForCommitNameHash;

Blink_PageLoad& Blink_PageLoad::SetWaitForCommit(int64_t value)
{
    SetMetricInternal(kWaitForCommitNameHash, value);
    return *this;
}
const char Blink_PaintTiming::kEntryName[] = "Blink.PaintTiming";
const uint64_t Blink_PaintTiming::kEntryNameHash;

Blink_PaintTiming::Blink_PaintTiming(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PaintTiming::Blink_PaintTiming(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_PaintTiming::~Blink_PaintTiming() = default;
const char Blink_PaintTiming::kLCPDebugging_HasViewportImageName[] = "LCPDebugging.HasViewportImage";
const uint64_t Blink_PaintTiming::kLCPDebugging_HasViewportImageNameHash;

Blink_PaintTiming& Blink_PaintTiming::SetLCPDebugging_HasViewportImage(int64_t value)
{
    SetMetricInternal(kLCPDebugging_HasViewportImageNameHash, value);
    return *this;
}
const char Blink_Script_AsyncScripts::kEntryName[] = "Blink.Script.AsyncScripts";
const uint64_t Blink_Script_AsyncScripts::kEntryNameHash;

Blink_Script_AsyncScripts::Blink_Script_AsyncScripts(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_Script_AsyncScripts::Blink_Script_AsyncScripts(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_Script_AsyncScripts::~Blink_Script_AsyncScripts() = default;

const char Blink_UpdateTime::kEntryName[] = "Blink.UpdateTime";
const uint64_t Blink_UpdateTime::kEntryNameHash;

Blink_UpdateTime::Blink_UpdateTime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_UpdateTime::Blink_UpdateTime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_UpdateTime::~Blink_UpdateTime() = default;
const char Blink_UpdateTime::kAccessibilityName[] = "Accessibility";
const uint64_t Blink_UpdateTime::kAccessibilityNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAccessibility(int64_t value)
{
    SetMetricInternal(kAccessibilityNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kAccessibilityBeginMainFrameName[] = "AccessibilityBeginMainFrame";
const uint64_t Blink_UpdateTime::kAccessibilityBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAccessibilityBeginMainFrame(int64_t value)
{
    SetMetricInternal(kAccessibilityBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverName[] = "AnchorElementMetricsIntersectionObserver";
const uint64_t Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAnchorElementMetricsIntersectionObserver(int64_t value)
{
    SetMetricInternal(kAnchorElementMetricsIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverBeginMainFrameName[] = "AnchorElementMetricsIntersectionObserverBeginMainFrame";
const uint64_t Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAnchorElementMetricsIntersectionObserverBeginMainFrame(int64_t value)
{
    SetMetricInternal(kAnchorElementMetricsIntersectionObserverBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kAnimateName[] = "Animate";
const uint64_t Blink_UpdateTime::kAnimateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAnimate(int64_t value)
{
    SetMetricInternal(kAnimateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kAnimateBeginMainFrameName[] = "AnimateBeginMainFrame";
const uint64_t Blink_UpdateTime::kAnimateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetAnimateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kAnimateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kCompositingCommitName[] = "CompositingCommit";
const uint64_t Blink_UpdateTime::kCompositingCommitNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingCommit(int64_t value)
{
    SetMetricInternal(kCompositingCommitNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kCompositingCommitBeginMainFrameName[] = "CompositingCommitBeginMainFrame";
const uint64_t Blink_UpdateTime::kCompositingCommitBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingCommitBeginMainFrame(int64_t value)
{
    SetMetricInternal(kCompositingCommitBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kCompositingInputsName[] = "CompositingInputs";
const uint64_t Blink_UpdateTime::kCompositingInputsNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingInputs(int64_t value)
{
    SetMetricInternal(kCompositingInputsNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kCompositingInputsBeginMainFrameName[] = "CompositingInputsBeginMainFrame";
const uint64_t Blink_UpdateTime::kCompositingInputsBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetCompositingInputsBeginMainFrame(int64_t value)
{
    SetMetricInternal(kCompositingInputsBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kContentDocumentUpdateName[] = "ContentDocumentUpdate";
const uint64_t Blink_UpdateTime::kContentDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetContentDocumentUpdate(int64_t value)
{
    SetMetricInternal(kContentDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kContentDocumentUpdateBeginMainFrameName[] = "ContentDocumentUpdateBeginMainFrame";
const uint64_t Blink_UpdateTime::kContentDocumentUpdateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetContentDocumentUpdateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kContentDocumentUpdateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kDisplayLockIntersectionObserverName[] = "DisplayLockIntersectionObserver";
const uint64_t Blink_UpdateTime::kDisplayLockIntersectionObserverNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetDisplayLockIntersectionObserver(int64_t value)
{
    SetMetricInternal(kDisplayLockIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kDisplayLockIntersectionObserverBeginMainFrameName[] = "DisplayLockIntersectionObserverBeginMainFrame";
const uint64_t Blink_UpdateTime::kDisplayLockIntersectionObserverBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetDisplayLockIntersectionObserverBeginMainFrame(int64_t value)
{
    SetMetricInternal(kDisplayLockIntersectionObserverBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kForcedStyleAndLayoutName[] = "ForcedStyleAndLayout";
const uint64_t Blink_UpdateTime::kForcedStyleAndLayoutNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetForcedStyleAndLayout(int64_t value)
{
    SetMetricInternal(kForcedStyleAndLayoutNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kForcedStyleAndLayoutBeginMainFrameName[] = "ForcedStyleAndLayoutBeginMainFrame";
const uint64_t Blink_UpdateTime::kForcedStyleAndLayoutBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetForcedStyleAndLayoutBeginMainFrame(int64_t value)
{
    SetMetricInternal(kForcedStyleAndLayoutBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kHandleInputEventsName[] = "HandleInputEvents";
const uint64_t Blink_UpdateTime::kHandleInputEventsNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHandleInputEvents(int64_t value)
{
    SetMetricInternal(kHandleInputEventsNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kHandleInputEventsBeginMainFrameName[] = "HandleInputEventsBeginMainFrame";
const uint64_t Blink_UpdateTime::kHandleInputEventsBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHandleInputEventsBeginMainFrame(int64_t value)
{
    SetMetricInternal(kHandleInputEventsBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kHitTestDocumentUpdateName[] = "HitTestDocumentUpdate";
const uint64_t Blink_UpdateTime::kHitTestDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHitTestDocumentUpdate(int64_t value)
{
    SetMetricInternal(kHitTestDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kHitTestDocumentUpdateBeginMainFrameName[] = "HitTestDocumentUpdateBeginMainFrame";
const uint64_t Blink_UpdateTime::kHitTestDocumentUpdateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetHitTestDocumentUpdateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kHitTestDocumentUpdateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kImplCompositorCommitName[] = "ImplCompositorCommit";
const uint64_t Blink_UpdateTime::kImplCompositorCommitNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetImplCompositorCommit(int64_t value)
{
    SetMetricInternal(kImplCompositorCommitNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kImplCompositorCommitBeginMainFrameName[] = "ImplCompositorCommitBeginMainFrame";
const uint64_t Blink_UpdateTime::kImplCompositorCommitBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetImplCompositorCommitBeginMainFrame(int64_t value)
{
    SetMetricInternal(kImplCompositorCommitBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kIntersectionObservationName[] = "IntersectionObservation";
const uint64_t Blink_UpdateTime::kIntersectionObservationNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservation(int64_t value)
{
    SetMetricInternal(kIntersectionObservationNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kIntersectionObservationBeginMainFrameName[] = "IntersectionObservationBeginMainFrame";
const uint64_t Blink_UpdateTime::kIntersectionObservationBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationBeginMainFrame(int64_t value)
{
    SetMetricInternal(kIntersectionObservationBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kIntersectionObservationInternalCountName[] = "IntersectionObservationInternalCount";
const uint64_t Blink_UpdateTime::kIntersectionObservationInternalCountNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationInternalCount(int64_t value)
{
    SetMetricInternal(kIntersectionObservationInternalCountNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kIntersectionObservationInternalCountBeginMainFrameName[] = "IntersectionObservationInternalCountBeginMainFrame";
const uint64_t Blink_UpdateTime::kIntersectionObservationInternalCountBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationInternalCountBeginMainFrame(int64_t value)
{
    SetMetricInternal(kIntersectionObservationInternalCountBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kIntersectionObservationJavascriptCountName[] = "IntersectionObservationJavascriptCount";
const uint64_t Blink_UpdateTime::kIntersectionObservationJavascriptCountNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationJavascriptCount(int64_t value)
{
    SetMetricInternal(kIntersectionObservationJavascriptCountNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kIntersectionObservationJavascriptCountBeginMainFrameName[] = "IntersectionObservationJavascriptCountBeginMainFrame";
const uint64_t Blink_UpdateTime::kIntersectionObservationJavascriptCountBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetIntersectionObservationJavascriptCountBeginMainFrame(int64_t value)
{
    SetMetricInternal(kIntersectionObservationJavascriptCountBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kJavascriptDocumentUpdateName[] = "JavascriptDocumentUpdate";
const uint64_t Blink_UpdateTime::kJavascriptDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetJavascriptDocumentUpdate(int64_t value)
{
    SetMetricInternal(kJavascriptDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kJavascriptDocumentUpdateBeginMainFrameName[] = "JavascriptDocumentUpdateBeginMainFrame";
const uint64_t Blink_UpdateTime::kJavascriptDocumentUpdateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetJavascriptDocumentUpdateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kJavascriptDocumentUpdateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kJavascriptIntersectionObserverName[] = "JavascriptIntersectionObserver";
const uint64_t Blink_UpdateTime::kJavascriptIntersectionObserverNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetJavascriptIntersectionObserver(int64_t value)
{
    SetMetricInternal(kJavascriptIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kJavascriptIntersectionObserverBeginMainFrameName[] = "JavascriptIntersectionObserverBeginMainFrame";
const uint64_t Blink_UpdateTime::kJavascriptIntersectionObserverBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetJavascriptIntersectionObserverBeginMainFrame(int64_t value)
{
    SetMetricInternal(kJavascriptIntersectionObserverBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kLayoutName[] = "Layout";
const uint64_t Blink_UpdateTime::kLayoutNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetLayout(int64_t value)
{
    SetMetricInternal(kLayoutNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kLayoutBeginMainFrameName[] = "LayoutBeginMainFrame";
const uint64_t Blink_UpdateTime::kLayoutBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetLayoutBeginMainFrame(int64_t value)
{
    SetMetricInternal(kLayoutBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kLazyLoadIntersectionObserverName[] = "LazyLoadIntersectionObserver";
const uint64_t Blink_UpdateTime::kLazyLoadIntersectionObserverNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetLazyLoadIntersectionObserver(int64_t value)
{
    SetMetricInternal(kLazyLoadIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kLazyLoadIntersectionObserverBeginMainFrameName[] = "LazyLoadIntersectionObserverBeginMainFrame";
const uint64_t Blink_UpdateTime::kLazyLoadIntersectionObserverBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetLazyLoadIntersectionObserverBeginMainFrame(int64_t value)
{
    SetMetricInternal(kLazyLoadIntersectionObserverBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kMainFrameName[] = "MainFrame";
const uint64_t Blink_UpdateTime::kMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMainFrame(int64_t value)
{
    SetMetricInternal(kMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kMainFrameIsBeforeFCPName[] = "MainFrameIsBeforeFCP";
const uint64_t Blink_UpdateTime::kMainFrameIsBeforeFCPNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMainFrameIsBeforeFCP(int64_t value)
{
    SetMetricInternal(kMainFrameIsBeforeFCPNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kMainFrameReasonsName[] = "MainFrameReasons";
const uint64_t Blink_UpdateTime::kMainFrameReasonsNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMainFrameReasons(int64_t value)
{
    SetMetricInternal(kMainFrameReasonsNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kMediaIntersectionObserverName[] = "MediaIntersectionObserver";
const uint64_t Blink_UpdateTime::kMediaIntersectionObserverNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMediaIntersectionObserver(int64_t value)
{
    SetMetricInternal(kMediaIntersectionObserverNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kMediaIntersectionObserverBeginMainFrameName[] = "MediaIntersectionObserverBeginMainFrame";
const uint64_t Blink_UpdateTime::kMediaIntersectionObserverBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetMediaIntersectionObserverBeginMainFrame(int64_t value)
{
    SetMetricInternal(kMediaIntersectionObserverBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kPaintName[] = "Paint";
const uint64_t Blink_UpdateTime::kPaintNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPaint(int64_t value)
{
    SetMetricInternal(kPaintNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kPaintBeginMainFrameName[] = "PaintBeginMainFrame";
const uint64_t Blink_UpdateTime::kPaintBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPaintBeginMainFrame(int64_t value)
{
    SetMetricInternal(kPaintBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kParseStyleSheetName[] = "ParseStyleSheet";
const uint64_t Blink_UpdateTime::kParseStyleSheetNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetParseStyleSheet(int64_t value)
{
    SetMetricInternal(kParseStyleSheetNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kParseStyleSheetBeginMainFrameName[] = "ParseStyleSheetBeginMainFrame";
const uint64_t Blink_UpdateTime::kParseStyleSheetBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetParseStyleSheetBeginMainFrame(int64_t value)
{
    SetMetricInternal(kParseStyleSheetBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kPrePaintName[] = "PrePaint";
const uint64_t Blink_UpdateTime::kPrePaintNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPrePaint(int64_t value)
{
    SetMetricInternal(kPrePaintNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kPrePaintBeginMainFrameName[] = "PrePaintBeginMainFrame";
const uint64_t Blink_UpdateTime::kPrePaintBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetPrePaintBeginMainFrame(int64_t value)
{
    SetMetricInternal(kPrePaintBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kScrollDocumentUpdateName[] = "ScrollDocumentUpdate";
const uint64_t Blink_UpdateTime::kScrollDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetScrollDocumentUpdate(int64_t value)
{
    SetMetricInternal(kScrollDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kScrollDocumentUpdateBeginMainFrameName[] = "ScrollDocumentUpdateBeginMainFrame";
const uint64_t Blink_UpdateTime::kScrollDocumentUpdateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetScrollDocumentUpdateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kScrollDocumentUpdateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kServiceDocumentUpdateName[] = "ServiceDocumentUpdate";
const uint64_t Blink_UpdateTime::kServiceDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetServiceDocumentUpdate(int64_t value)
{
    SetMetricInternal(kServiceDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kServiceDocumentUpdateBeginMainFrameName[] = "ServiceDocumentUpdateBeginMainFrame";
const uint64_t Blink_UpdateTime::kServiceDocumentUpdateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetServiceDocumentUpdateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kServiceDocumentUpdateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kStyleName[] = "Style";
const uint64_t Blink_UpdateTime::kStyleNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetStyle(int64_t value)
{
    SetMetricInternal(kStyleNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kStyleBeginMainFrameName[] = "StyleBeginMainFrame";
const uint64_t Blink_UpdateTime::kStyleBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetStyleBeginMainFrame(int64_t value)
{
    SetMetricInternal(kStyleBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kStylePercentageName[] = "StylePercentage";
const uint64_t Blink_UpdateTime::kStylePercentageNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetStylePercentage(int64_t value)
{
    SetMetricInternal(kStylePercentageNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kUpdateLayersName[] = "UpdateLayers";
const uint64_t Blink_UpdateTime::kUpdateLayersNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUpdateLayers(int64_t value)
{
    SetMetricInternal(kUpdateLayersNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kUpdateLayersBeginMainFrameName[] = "UpdateLayersBeginMainFrame";
const uint64_t Blink_UpdateTime::kUpdateLayersBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUpdateLayersBeginMainFrame(int64_t value)
{
    SetMetricInternal(kUpdateLayersBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kUpdateViewportIntersectionName[] = "UpdateViewportIntersection";
const uint64_t Blink_UpdateTime::kUpdateViewportIntersectionNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUpdateViewportIntersection(int64_t value)
{
    SetMetricInternal(kUpdateViewportIntersectionNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kUpdateViewportIntersectionBeginMainFrameName[] = "UpdateViewportIntersectionBeginMainFrame";
const uint64_t Blink_UpdateTime::kUpdateViewportIntersectionBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUpdateViewportIntersectionBeginMainFrame(int64_t value)
{
    SetMetricInternal(kUpdateViewportIntersectionBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kUserDrivenDocumentUpdateName[] = "UserDrivenDocumentUpdate";
const uint64_t Blink_UpdateTime::kUserDrivenDocumentUpdateNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUserDrivenDocumentUpdate(int64_t value)
{
    SetMetricInternal(kUserDrivenDocumentUpdateNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kUserDrivenDocumentUpdateBeginMainFrameName[] = "UserDrivenDocumentUpdateBeginMainFrame";
const uint64_t Blink_UpdateTime::kUserDrivenDocumentUpdateBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetUserDrivenDocumentUpdateBeginMainFrame(int64_t value)
{
    SetMetricInternal(kUserDrivenDocumentUpdateBeginMainFrameNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kWaitForCommitName[] = "WaitForCommit";
const uint64_t Blink_UpdateTime::kWaitForCommitNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetWaitForCommit(int64_t value)
{
    SetMetricInternal(kWaitForCommitNameHash, value);
    return *this;
}

const char Blink_UpdateTime::kWaitForCommitBeginMainFrameName[] = "WaitForCommitBeginMainFrame";
const uint64_t Blink_UpdateTime::kWaitForCommitBeginMainFrameNameHash;

Blink_UpdateTime& Blink_UpdateTime::SetWaitForCommitBeginMainFrame(int64_t value)
{
    SetMetricInternal(kWaitForCommitBeginMainFrameNameHash, value);
    return *this;
}
const char Blink_UseCounter::kEntryName[] = "Blink.UseCounter";
const uint64_t Blink_UseCounter::kEntryNameHash;

Blink_UseCounter::Blink_UseCounter(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_UseCounter::Blink_UseCounter(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Blink_UseCounter::~Blink_UseCounter() = default;
const char Blink_UseCounter::kFeatureName[] = "Feature";
const uint64_t Blink_UseCounter::kFeatureNameHash;

Blink_UseCounter& Blink_UseCounter::SetFeature(int64_t value)
{
    SetMetricInternal(kFeatureNameHash, value);
    return *this;
}

const char Blink_UseCounter::kIsMainFrameFeatureName[] = "IsMainFrameFeature";
const uint64_t Blink_UseCounter::kIsMainFrameFeatureNameHash;

Blink_UseCounter& Blink_UseCounter::SetIsMainFrameFeature(int64_t value)
{
    SetMetricInternal(kIsMainFrameFeatureNameHash, value);
    return *this;
}
const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kEntryName[] = "BrowsingTopics.DocumentBrowsingTopicsApiResult";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kEntryNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult::BrowsingTopics_DocumentBrowsingTopicsApiResult(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BrowsingTopics_DocumentBrowsingTopicsApiResult::BrowsingTopics_DocumentBrowsingTopicsApiResult(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BrowsingTopics_DocumentBrowsingTopicsApiResult::~BrowsingTopics_DocumentBrowsingTopicsApiResult() = default;
const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kEmptyReasonName[] = "EmptyReason";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kEmptyReasonNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetEmptyReason(int64_t value)
{
    SetMetricInternal(kEmptyReasonNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0Name[] = "ReturnedTopic0";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0NameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic0(int64_t value)
{
    SetMetricInternal(kReturnedTopic0NameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0IsTrueTopTopicName[] = "ReturnedTopic0IsTrueTopTopic";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0IsTrueTopTopicNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic0IsTrueTopTopic(int64_t value)
{
    SetMetricInternal(kReturnedTopic0IsTrueTopTopicNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0ModelVersionName[] = "ReturnedTopic0ModelVersion";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0ModelVersionNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic0ModelVersion(int64_t value)
{
    SetMetricInternal(kReturnedTopic0ModelVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0TaxonomyVersionName[] = "ReturnedTopic0TaxonomyVersion";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0TaxonomyVersionNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic0TaxonomyVersion(int64_t value)
{
    SetMetricInternal(kReturnedTopic0TaxonomyVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1Name[] = "ReturnedTopic1";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1NameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic1(int64_t value)
{
    SetMetricInternal(kReturnedTopic1NameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1IsTrueTopTopicName[] = "ReturnedTopic1IsTrueTopTopic";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1IsTrueTopTopicNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic1IsTrueTopTopic(int64_t value)
{
    SetMetricInternal(kReturnedTopic1IsTrueTopTopicNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1ModelVersionName[] = "ReturnedTopic1ModelVersion";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1ModelVersionNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic1ModelVersion(int64_t value)
{
    SetMetricInternal(kReturnedTopic1ModelVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1TaxonomyVersionName[] = "ReturnedTopic1TaxonomyVersion";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1TaxonomyVersionNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic1TaxonomyVersion(int64_t value)
{
    SetMetricInternal(kReturnedTopic1TaxonomyVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2Name[] = "ReturnedTopic2";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2NameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic2(int64_t value)
{
    SetMetricInternal(kReturnedTopic2NameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2IsTrueTopTopicName[] = "ReturnedTopic2IsTrueTopTopic";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2IsTrueTopTopicNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic2IsTrueTopTopic(int64_t value)
{
    SetMetricInternal(kReturnedTopic2IsTrueTopTopicNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2ModelVersionName[] = "ReturnedTopic2ModelVersion";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2ModelVersionNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic2ModelVersion(int64_t value)
{
    SetMetricInternal(kReturnedTopic2ModelVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2TaxonomyVersionName[] = "ReturnedTopic2TaxonomyVersion";
const uint64_t BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2TaxonomyVersionNameHash;

BrowsingTopics_DocumentBrowsingTopicsApiResult& BrowsingTopics_DocumentBrowsingTopicsApiResult::SetReturnedTopic2TaxonomyVersion(int64_t value)
{
    SetMetricInternal(kReturnedTopic2TaxonomyVersionNameHash, value);
    return *this;
}
const char BrowsingTopics_EpochTopicsCalculationResult::kEntryName[] = "BrowsingTopics.EpochTopicsCalculationResult";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kEntryNameHash;

BrowsingTopics_EpochTopicsCalculationResult::BrowsingTopics_EpochTopicsCalculationResult(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BrowsingTopics_EpochTopicsCalculationResult::BrowsingTopics_EpochTopicsCalculationResult(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BrowsingTopics_EpochTopicsCalculationResult::~BrowsingTopics_EpochTopicsCalculationResult() = default;
const char BrowsingTopics_EpochTopicsCalculationResult::kModelVersionName[] = "ModelVersion";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kModelVersionNameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetModelVersion(int64_t value)
{
    SetMetricInternal(kModelVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kPaddedTopicsStartIndexName[] = "PaddedTopicsStartIndex";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kPaddedTopicsStartIndexNameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetPaddedTopicsStartIndex(int64_t value)
{
    SetMetricInternal(kPaddedTopicsStartIndexNameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kTaxonomyVersionName[] = "TaxonomyVersion";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kTaxonomyVersionNameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetTaxonomyVersion(int64_t value)
{
    SetMetricInternal(kTaxonomyVersionNameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kTopTopic0Name[] = "TopTopic0";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kTopTopic0NameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetTopTopic0(int64_t value)
{
    SetMetricInternal(kTopTopic0NameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kTopTopic1Name[] = "TopTopic1";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kTopTopic1NameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetTopTopic1(int64_t value)
{
    SetMetricInternal(kTopTopic1NameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kTopTopic2Name[] = "TopTopic2";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kTopTopic2NameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetTopTopic2(int64_t value)
{
    SetMetricInternal(kTopTopic2NameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kTopTopic3Name[] = "TopTopic3";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kTopTopic3NameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetTopTopic3(int64_t value)
{
    SetMetricInternal(kTopTopic3NameHash, value);
    return *this;
}

const char BrowsingTopics_EpochTopicsCalculationResult::kTopTopic4Name[] = "TopTopic4";
const uint64_t BrowsingTopics_EpochTopicsCalculationResult::kTopTopic4NameHash;

BrowsingTopics_EpochTopicsCalculationResult& BrowsingTopics_EpochTopicsCalculationResult::SetTopTopic4(int64_t value)
{
    SetMetricInternal(kTopTopic4NameHash, value);
    return *this;
}
const char BrowsingTopics_PageLoad::kEntryName[] = "BrowsingTopics.PageLoad";
const uint64_t BrowsingTopics_PageLoad::kEntryNameHash;

BrowsingTopics_PageLoad::BrowsingTopics_PageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BrowsingTopics_PageLoad::BrowsingTopics_PageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

BrowsingTopics_PageLoad::~BrowsingTopics_PageLoad() = default;
const char BrowsingTopics_PageLoad::kTopicsRequestingContextDomainsCountName[] = "TopicsRequestingContextDomainsCount";
const uint64_t BrowsingTopics_PageLoad::kTopicsRequestingContextDomainsCountNameHash;

BrowsingTopics_PageLoad& BrowsingTopics_PageLoad::SetTopicsRequestingContextDomainsCount(int64_t value)
{
    SetMetricInternal(kTopicsRequestingContextDomainsCountNameHash, value);
    return *this;
}
const char ChargeEventHistory::kEntryName[] = "ChargeEventHistory";
const uint64_t ChargeEventHistory::kEntryNameHash;

ChargeEventHistory::ChargeEventHistory(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChargeEventHistory::ChargeEventHistory(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChargeEventHistory::~ChargeEventHistory() = default;
const char ChargeEventHistory::kChargeEventHistoryDurationName[] = "ChargeEventHistoryDuration";
const uint64_t ChargeEventHistory::kChargeEventHistoryDurationNameHash;

ChargeEventHistory& ChargeEventHistory::SetChargeEventHistoryDuration(int64_t value)
{
    SetMetricInternal(kChargeEventHistoryDurationNameHash, value);
    return *this;
}

const char ChargeEventHistory::kChargeEventHistoryIndexName[] = "ChargeEventHistoryIndex";
const uint64_t ChargeEventHistory::kChargeEventHistoryIndexNameHash;

ChargeEventHistory& ChargeEventHistory::SetChargeEventHistoryIndex(int64_t value)
{
    SetMetricInternal(kChargeEventHistoryIndexNameHash, value);
    return *this;
}

const char ChargeEventHistory::kChargeEventHistorySizeName[] = "ChargeEventHistorySize";
const uint64_t ChargeEventHistory::kChargeEventHistorySizeNameHash;

ChargeEventHistory& ChargeEventHistory::SetChargeEventHistorySize(int64_t value)
{
    SetMetricInternal(kChargeEventHistorySizeNameHash, value);
    return *this;
}

const char ChargeEventHistory::kChargeEventHistoryStartTimeName[] = "ChargeEventHistoryStartTime";
const uint64_t ChargeEventHistory::kChargeEventHistoryStartTimeNameHash;

ChargeEventHistory& ChargeEventHistory::SetChargeEventHistoryStartTime(int64_t value)
{
    SetMetricInternal(kChargeEventHistoryStartTimeNameHash, value);
    return *this;
}

const char ChargeEventHistory::kEventIdName[] = "EventId";
const uint64_t ChargeEventHistory::kEventIdNameHash;

ChargeEventHistory& ChargeEventHistory::SetEventId(int64_t value)
{
    SetMetricInternal(kEventIdNameHash, value);
    return *this;
}
const char ChromeOS_WebsiteUsageTime::kEntryName[] = "ChromeOS.WebsiteUsageTime";
const uint64_t ChromeOS_WebsiteUsageTime::kEntryNameHash;

ChromeOS_WebsiteUsageTime::ChromeOS_WebsiteUsageTime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOS_WebsiteUsageTime::ChromeOS_WebsiteUsageTime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOS_WebsiteUsageTime::~ChromeOS_WebsiteUsageTime() = default;
const char ChromeOS_WebsiteUsageTime::kDurationName[] = "Duration";
const uint64_t ChromeOS_WebsiteUsageTime::kDurationNameHash;

ChromeOS_WebsiteUsageTime& ChromeOS_WebsiteUsageTime::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char ChromeOS_WebsiteUsageTime::kIsFromLastLoginName[] = "IsFromLastLogin";
const uint64_t ChromeOS_WebsiteUsageTime::kIsFromLastLoginNameHash;

ChromeOS_WebsiteUsageTime& ChromeOS_WebsiteUsageTime::SetIsFromLastLogin(int64_t value)
{
    SetMetricInternal(kIsFromLastLoginNameHash, value);
    return *this;
}

const char ChromeOS_WebsiteUsageTime::kPromotableName[] = "Promotable";
const uint64_t ChromeOS_WebsiteUsageTime::kPromotableNameHash;

ChromeOS_WebsiteUsageTime& ChromeOS_WebsiteUsageTime::SetPromotable(int64_t value)
{
    SetMetricInternal(kPromotableNameHash, value);
    return *this;
}

const char ChromeOS_WebsiteUsageTime::kUrlContentName[] = "UrlContent";
const uint64_t ChromeOS_WebsiteUsageTime::kUrlContentNameHash;

ChromeOS_WebsiteUsageTime& ChromeOS_WebsiteUsageTime::SetUrlContent(int64_t value)
{
    SetMetricInternal(kUrlContentNameHash, value);
    return *this;
}

const char ChromeOS_WebsiteUsageTime::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOS_WebsiteUsageTime::kUserDeviceMatrixNameHash;

ChromeOS_WebsiteUsageTime& ChromeOS_WebsiteUsageTime::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ChromeOSApp_InputEvent::kEntryName[] = "ChromeOSApp.InputEvent";
const uint64_t ChromeOSApp_InputEvent::kEntryNameHash;

ChromeOSApp_InputEvent::ChromeOSApp_InputEvent(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_InputEvent::ChromeOSApp_InputEvent(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_InputEvent::~ChromeOSApp_InputEvent() = default;
const char ChromeOSApp_InputEvent::kAppInputEventCountName[] = "AppInputEventCount";
const uint64_t ChromeOSApp_InputEvent::kAppInputEventCountNameHash;

ChromeOSApp_InputEvent& ChromeOSApp_InputEvent::SetAppInputEventCount(int64_t value)
{
    SetMetricInternal(kAppInputEventCountNameHash, value);
    return *this;
}

const char ChromeOSApp_InputEvent::kAppInputEventSourceName[] = "AppInputEventSource";
const uint64_t ChromeOSApp_InputEvent::kAppInputEventSourceNameHash;

ChromeOSApp_InputEvent& ChromeOSApp_InputEvent::SetAppInputEventSource(int64_t value)
{
    SetMetricInternal(kAppInputEventSourceNameHash, value);
    return *this;
}

const char ChromeOSApp_InputEvent::kAppTypeName[] = "AppType";
const uint64_t ChromeOSApp_InputEvent::kAppTypeNameHash;

ChromeOSApp_InputEvent& ChromeOSApp_InputEvent::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char ChromeOSApp_InputEvent::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOSApp_InputEvent::kUserDeviceMatrixNameHash;

ChromeOSApp_InputEvent& ChromeOSApp_InputEvent::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ChromeOSApp_InstalledApp::kEntryName[] = "ChromeOSApp.InstalledApp";
const uint64_t ChromeOSApp_InstalledApp::kEntryNameHash;

ChromeOSApp_InstalledApp::ChromeOSApp_InstalledApp(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_InstalledApp::ChromeOSApp_InstalledApp(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_InstalledApp::~ChromeOSApp_InstalledApp() = default;
const char ChromeOSApp_InstalledApp::kAppTypeName[] = "AppType";
const uint64_t ChromeOSApp_InstalledApp::kAppTypeNameHash;

ChromeOSApp_InstalledApp& ChromeOSApp_InstalledApp::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char ChromeOSApp_InstalledApp::kInstallReasonName[] = "InstallReason";
const uint64_t ChromeOSApp_InstalledApp::kInstallReasonNameHash;

ChromeOSApp_InstalledApp& ChromeOSApp_InstalledApp::SetInstallReason(int64_t value)
{
    SetMetricInternal(kInstallReasonNameHash, value);
    return *this;
}

const char ChromeOSApp_InstalledApp::kInstallSource2Name[] = "InstallSource2";
const uint64_t ChromeOSApp_InstalledApp::kInstallSource2NameHash;

ChromeOSApp_InstalledApp& ChromeOSApp_InstalledApp::SetInstallSource2(int64_t value)
{
    SetMetricInternal(kInstallSource2NameHash, value);
    return *this;
}

const char ChromeOSApp_InstalledApp::kInstallTimeName[] = "InstallTime";
const uint64_t ChromeOSApp_InstalledApp::kInstallTimeNameHash;

ChromeOSApp_InstalledApp& ChromeOSApp_InstalledApp::SetInstallTime(int64_t value)
{
    SetMetricInternal(kInstallTimeNameHash, value);
    return *this;
}

const char ChromeOSApp_InstalledApp::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOSApp_InstalledApp::kUserDeviceMatrixNameHash;

ChromeOSApp_InstalledApp& ChromeOSApp_InstalledApp::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ChromeOSApp_Launch::kEntryName[] = "ChromeOSApp.Launch";
const uint64_t ChromeOSApp_Launch::kEntryNameHash;

ChromeOSApp_Launch::ChromeOSApp_Launch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_Launch::ChromeOSApp_Launch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_Launch::~ChromeOSApp_Launch() = default;
const char ChromeOSApp_Launch::kAppTypeName[] = "AppType";
const uint64_t ChromeOSApp_Launch::kAppTypeNameHash;

ChromeOSApp_Launch& ChromeOSApp_Launch::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char ChromeOSApp_Launch::kLaunchSourceName[] = "LaunchSource";
const uint64_t ChromeOSApp_Launch::kLaunchSourceNameHash;

ChromeOSApp_Launch& ChromeOSApp_Launch::SetLaunchSource(int64_t value)
{
    SetMetricInternal(kLaunchSourceNameHash, value);
    return *this;
}

const char ChromeOSApp_Launch::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOSApp_Launch::kUserDeviceMatrixNameHash;

ChromeOSApp_Launch& ChromeOSApp_Launch::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ChromeOSApp_UninstallApp::kEntryName[] = "ChromeOSApp.UninstallApp";
const uint64_t ChromeOSApp_UninstallApp::kEntryNameHash;

ChromeOSApp_UninstallApp::ChromeOSApp_UninstallApp(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_UninstallApp::ChromeOSApp_UninstallApp(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_UninstallApp::~ChromeOSApp_UninstallApp() = default;
const char ChromeOSApp_UninstallApp::kAppTypeName[] = "AppType";
const uint64_t ChromeOSApp_UninstallApp::kAppTypeNameHash;

ChromeOSApp_UninstallApp& ChromeOSApp_UninstallApp::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char ChromeOSApp_UninstallApp::kUninstallSourceName[] = "UninstallSource";
const uint64_t ChromeOSApp_UninstallApp::kUninstallSourceNameHash;

ChromeOSApp_UninstallApp& ChromeOSApp_UninstallApp::SetUninstallSource(int64_t value)
{
    SetMetricInternal(kUninstallSourceNameHash, value);
    return *this;
}

const char ChromeOSApp_UninstallApp::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOSApp_UninstallApp::kUserDeviceMatrixNameHash;

ChromeOSApp_UninstallApp& ChromeOSApp_UninstallApp::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ChromeOSApp_UsageTime::kEntryName[] = "ChromeOSApp.UsageTime";
const uint64_t ChromeOSApp_UsageTime::kEntryNameHash;

ChromeOSApp_UsageTime::ChromeOSApp_UsageTime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_UsageTime::ChromeOSApp_UsageTime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_UsageTime::~ChromeOSApp_UsageTime() = default;
const char ChromeOSApp_UsageTime::kAppTypeName[] = "AppType";
const uint64_t ChromeOSApp_UsageTime::kAppTypeNameHash;

ChromeOSApp_UsageTime& ChromeOSApp_UsageTime::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char ChromeOSApp_UsageTime::kDurationName[] = "Duration";
const uint64_t ChromeOSApp_UsageTime::kDurationNameHash;

ChromeOSApp_UsageTime& ChromeOSApp_UsageTime::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char ChromeOSApp_UsageTime::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOSApp_UsageTime::kUserDeviceMatrixNameHash;

ChromeOSApp_UsageTime& ChromeOSApp_UsageTime::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ChromeOSApp_UsageTimeReusedSourceId::kEntryName[] = "ChromeOSApp.UsageTimeReusedSourceId";
const uint64_t ChromeOSApp_UsageTimeReusedSourceId::kEntryNameHash;

ChromeOSApp_UsageTimeReusedSourceId::ChromeOSApp_UsageTimeReusedSourceId(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_UsageTimeReusedSourceId::ChromeOSApp_UsageTimeReusedSourceId(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ChromeOSApp_UsageTimeReusedSourceId::~ChromeOSApp_UsageTimeReusedSourceId() = default;
const char ChromeOSApp_UsageTimeReusedSourceId::kAppTypeName[] = "AppType";
const uint64_t ChromeOSApp_UsageTimeReusedSourceId::kAppTypeNameHash;

ChromeOSApp_UsageTimeReusedSourceId& ChromeOSApp_UsageTimeReusedSourceId::SetAppType(int64_t value)
{
    SetMetricInternal(kAppTypeNameHash, value);
    return *this;
}

const char ChromeOSApp_UsageTimeReusedSourceId::kDurationName[] = "Duration";
const uint64_t ChromeOSApp_UsageTimeReusedSourceId::kDurationNameHash;

ChromeOSApp_UsageTimeReusedSourceId& ChromeOSApp_UsageTimeReusedSourceId::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char ChromeOSApp_UsageTimeReusedSourceId::kUserDeviceMatrixName[] = "UserDeviceMatrix";
const uint64_t ChromeOSApp_UsageTimeReusedSourceId::kUserDeviceMatrixNameHash;

ChromeOSApp_UsageTimeReusedSourceId& ChromeOSApp_UsageTimeReusedSourceId::SetUserDeviceMatrix(int64_t value)
{
    SetMetricInternal(kUserDeviceMatrixNameHash, value);
    return *this;
}
const char ClickInput::kEntryName[] = "ClickInput";
const uint64_t ClickInput::kEntryNameHash;

ClickInput::ClickInput(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ClickInput::ClickInput(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ClickInput::~ClickInput() = default;
const char ClickInput::kExperimental_ClickInputBurstName[] = "Experimental.ClickInputBurst";
const uint64_t ClickInput::kExperimental_ClickInputBurstNameHash;

ClickInput& ClickInput::SetExperimental_ClickInputBurst(int64_t value)
{
    SetMetricInternal(kExperimental_ClickInputBurstNameHash, value);
    return *this;
}
const char ClientRenderingAPI::kEntryName[] = "ClientRenderingAPI";
const uint64_t ClientRenderingAPI::kEntryNameHash;

ClientRenderingAPI::ClientRenderingAPI(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ClientRenderingAPI::ClientRenderingAPI(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ClientRenderingAPI::~ClientRenderingAPI() = default;
const char ClientRenderingAPI::kCanvas_RenderingContextName[] = "Canvas.RenderingContext";
const uint64_t ClientRenderingAPI::kCanvas_RenderingContextNameHash;

ClientRenderingAPI& ClientRenderingAPI::SetCanvas_RenderingContext(int64_t value)
{
    SetMetricInternal(kCanvas_RenderingContextNameHash, value);
    return *this;
}

const char ClientRenderingAPI::kCanvas_RenderingContextDrawnToName[] = "Canvas.RenderingContextDrawnTo";
const uint64_t ClientRenderingAPI::kCanvas_RenderingContextDrawnToNameHash;

ClientRenderingAPI& ClientRenderingAPI::SetCanvas_RenderingContextDrawnTo(int64_t value)
{
    SetMetricInternal(kCanvas_RenderingContextDrawnToNameHash, value);
    return *this;
}

const char ClientRenderingAPI::kGPUDeviceName[] = "GPUDevice";
const uint64_t ClientRenderingAPI::kGPUDeviceNameHash;

ClientRenderingAPI& ClientRenderingAPI::SetGPUDevice(int64_t value)
{
    SetMetricInternal(kGPUDeviceNameHash, value);
    return *this;
}

const char ClientRenderingAPI::kOffscreenCanvas_RenderingContextName[] = "OffscreenCanvas.RenderingContext";
const uint64_t ClientRenderingAPI::kOffscreenCanvas_RenderingContextNameHash;

ClientRenderingAPI& ClientRenderingAPI::SetOffscreenCanvas_RenderingContext(int64_t value)
{
    SetMetricInternal(kOffscreenCanvas_RenderingContextNameHash, value);
    return *this;
}

const char ClientRenderingAPI::kOffscreenCanvas_RenderingContextDrawnToName[] = "OffscreenCanvas.RenderingContextDrawnTo";
const uint64_t ClientRenderingAPI::kOffscreenCanvas_RenderingContextDrawnToNameHash;

ClientRenderingAPI& ClientRenderingAPI::SetOffscreenCanvas_RenderingContextDrawnTo(int64_t value)
{
    SetMetricInternal(kOffscreenCanvas_RenderingContextDrawnToNameHash, value);
    return *this;
}
const char Compositor_Rendering::kEntryName[] = "Compositor.Rendering";
const uint64_t Compositor_Rendering::kEntryNameHash;

Compositor_Rendering::Compositor_Rendering(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Compositor_Rendering::Compositor_Rendering(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Compositor_Rendering::~Compositor_Rendering() = default;
const char Compositor_Rendering::kCheckerboardedImagesCountName[] = "CheckerboardedImagesCount";
const uint64_t Compositor_Rendering::kCheckerboardedImagesCountNameHash;

Compositor_Rendering& Compositor_Rendering::SetCheckerboardedImagesCount(int64_t value)
{
    SetMetricInternal(kCheckerboardedImagesCountNameHash, value);
    return *this;
}
const char Compositor_UserInteraction::kEntryName[] = "Compositor.UserInteraction";
const uint64_t Compositor_UserInteraction::kEntryNameHash;

Compositor_UserInteraction::Compositor_UserInteraction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Compositor_UserInteraction::Compositor_UserInteraction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Compositor_UserInteraction::~Compositor_UserInteraction() = default;
const char Compositor_UserInteraction::kCheckerboardedContentAreaName[] = "CheckerboardedContentArea";
const uint64_t Compositor_UserInteraction::kCheckerboardedContentAreaNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetCheckerboardedContentArea(int64_t value)
{
    SetMetricInternal(kCheckerboardedContentAreaNameHash, value);
    return *this;
}

const char Compositor_UserInteraction::kCheckerboardedContentAreaRatioName[] = "CheckerboardedContentAreaRatio";
const uint64_t Compositor_UserInteraction::kCheckerboardedContentAreaRatioNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetCheckerboardedContentAreaRatio(int64_t value)
{
    SetMetricInternal(kCheckerboardedContentAreaRatioNameHash, value);
    return *this;
}

const char Compositor_UserInteraction::kCheckerboardedImagesCountName[] = "CheckerboardedImagesCount";
const uint64_t Compositor_UserInteraction::kCheckerboardedImagesCountNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetCheckerboardedImagesCount(int64_t value)
{
    SetMetricInternal(kCheckerboardedImagesCountNameHash, value);
    return *this;
}

const char Compositor_UserInteraction::kNumMissingTilesName[] = "NumMissingTiles";
const uint64_t Compositor_UserInteraction::kNumMissingTilesNameHash;

Compositor_UserInteraction& Compositor_UserInteraction::SetNumMissingTiles(int64_t value)
{
    SetMetricInternal(kNumMissingTilesNameHash, value);
    return *this;
}
const char ContactsPicker_ShareStatistics::kEntryName[] = "ContactsPicker.ShareStatistics";
const uint64_t ContactsPicker_ShareStatistics::kEntryNameHash;

ContactsPicker_ShareStatistics::ContactsPicker_ShareStatistics(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContactsPicker_ShareStatistics::ContactsPicker_ShareStatistics(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContactsPicker_ShareStatistics::~ContactsPicker_ShareStatistics() = default;
const char ContactsPicker_ShareStatistics::kPropertiesRequestedName[] = "PropertiesRequested";
const uint64_t ContactsPicker_ShareStatistics::kPropertiesRequestedNameHash;

ContactsPicker_ShareStatistics& ContactsPicker_ShareStatistics::SetPropertiesRequested(int64_t value)
{
    SetMetricInternal(kPropertiesRequestedNameHash, value);
    return *this;
}

const char ContactsPicker_ShareStatistics::kSelectCountName[] = "SelectCount";
const uint64_t ContactsPicker_ShareStatistics::kSelectCountNameHash;

ContactsPicker_ShareStatistics& ContactsPicker_ShareStatistics::SetSelectCount(int64_t value)
{
    SetMetricInternal(kSelectCountNameHash, value);
    return *this;
}

const char ContactsPicker_ShareStatistics::kSelectPercentageName[] = "SelectPercentage";
const uint64_t ContactsPicker_ShareStatistics::kSelectPercentageNameHash;

ContactsPicker_ShareStatistics& ContactsPicker_ShareStatistics::SetSelectPercentage(int64_t value)
{
    SetMetricInternal(kSelectPercentageNameHash, value);
    return *this;
}
const char ContentIndex_Added::kEntryName[] = "ContentIndex.Added";
const uint64_t ContentIndex_Added::kEntryNameHash;

ContentIndex_Added::ContentIndex_Added(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContentIndex_Added::ContentIndex_Added(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContentIndex_Added::~ContentIndex_Added() = default;
const char ContentIndex_Added::kCategoryName[] = "Category";
const uint64_t ContentIndex_Added::kCategoryNameHash;

ContentIndex_Added& ContentIndex_Added::SetCategory(int64_t value)
{
    SetMetricInternal(kCategoryNameHash, value);
    return *this;
}
const char ContentIndex_DeletedByUser::kEntryName[] = "ContentIndex.DeletedByUser";
const uint64_t ContentIndex_DeletedByUser::kEntryNameHash;

ContentIndex_DeletedByUser::ContentIndex_DeletedByUser(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContentIndex_DeletedByUser::ContentIndex_DeletedByUser(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContentIndex_DeletedByUser::~ContentIndex_DeletedByUser() = default;
const char ContentIndex_DeletedByUser::kDeletedName[] = "Deleted";
const uint64_t ContentIndex_DeletedByUser::kDeletedNameHash;

ContentIndex_DeletedByUser& ContentIndex_DeletedByUser::SetDeleted(int64_t value)
{
    SetMetricInternal(kDeletedNameHash, value);
    return *this;
}
const char ContentIndex_Opened::kEntryName[] = "ContentIndex.Opened";
const uint64_t ContentIndex_Opened::kEntryNameHash;

ContentIndex_Opened::ContentIndex_Opened(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContentIndex_Opened::ContentIndex_Opened(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContentIndex_Opened::~ContentIndex_Opened() = default;
const char ContentIndex_Opened::kIsOfflineName[] = "IsOffline";
const uint64_t ContentIndex_Opened::kIsOfflineNameHash;

ContentIndex_Opened& ContentIndex_Opened::SetIsOffline(int64_t value)
{
    SetMetricInternal(kIsOfflineNameHash, value);
    return *this;
}
const char ContextMenuAndroid_Selected::kEntryName[] = "ContextMenuAndroid.Selected";
const uint64_t ContextMenuAndroid_Selected::kEntryNameHash;

ContextMenuAndroid_Selected::ContextMenuAndroid_Selected(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContextMenuAndroid_Selected::ContextMenuAndroid_Selected(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContextMenuAndroid_Selected::~ContextMenuAndroid_Selected() = default;
const char ContextMenuAndroid_Selected::kActionName[] = "Action";
const uint64_t ContextMenuAndroid_Selected::kActionNameHash;

ContextMenuAndroid_Selected& ContextMenuAndroid_Selected::SetAction(int64_t value)
{
    SetMetricInternal(kActionNameHash, value);
    return *this;
}
const char ContextMenuAndroid_Shown::kEntryName[] = "ContextMenuAndroid.Shown";
const uint64_t ContextMenuAndroid_Shown::kEntryNameHash;

ContextMenuAndroid_Shown::ContextMenuAndroid_Shown(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContextMenuAndroid_Shown::ContextMenuAndroid_Shown(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ContextMenuAndroid_Shown::~ContextMenuAndroid_Shown() = default;
const char ContextMenuAndroid_Shown::kSearchByImageName[] = "SearchByImage";
const uint64_t ContextMenuAndroid_Shown::kSearchByImageNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetSearchByImage(int64_t value)
{
    SetMetricInternal(kSearchByImageNameHash, value);
    return *this;
}

const char ContextMenuAndroid_Shown::kSearchWithGoogleLensName[] = "SearchWithGoogleLens";
const uint64_t ContextMenuAndroid_Shown::kSearchWithGoogleLensNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetSearchWithGoogleLens(int64_t value)
{
    SetMetricInternal(kSearchWithGoogleLensNameHash, value);
    return *this;
}

const char ContextMenuAndroid_Shown::kShopWithGoogleLensName[] = "ShopWithGoogleLens";
const uint64_t ContextMenuAndroid_Shown::kShopWithGoogleLensNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetShopWithGoogleLens(int64_t value)
{
    SetMetricInternal(kShopWithGoogleLensNameHash, value);
    return *this;
}

const char ContextMenuAndroid_Shown::kShopWithGoogleLensChipName[] = "ShopWithGoogleLensChip";
const uint64_t ContextMenuAndroid_Shown::kShopWithGoogleLensChipNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetShopWithGoogleLensChip(int64_t value)
{
    SetMetricInternal(kShopWithGoogleLensChipNameHash, value);
    return *this;
}

const char ContextMenuAndroid_Shown::kTranslateWithGoogleLensChipName[] = "TranslateWithGoogleLensChip";
const uint64_t ContextMenuAndroid_Shown::kTranslateWithGoogleLensChipNameHash;

ContextMenuAndroid_Shown& ContextMenuAndroid_Shown::SetTranslateWithGoogleLensChip(int64_t value)
{
    SetMetricInternal(kTranslateWithGoogleLensChipNameHash, value);
    return *this;
}
const char CPUUsageMeasurement::kEntryName[] = "CPUUsageMeasurement";
const uint64_t CPUUsageMeasurement::kEntryNameHash;

CPUUsageMeasurement::CPUUsageMeasurement(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

CPUUsageMeasurement::CPUUsageMeasurement(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

CPUUsageMeasurement::~CPUUsageMeasurement() = default;
const char CPUUsageMeasurement::kCPUUsageName[] = "CPUUsage";
const uint64_t CPUUsageMeasurement::kCPUUsageNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetCPUUsage(int64_t value)
{
    SetMetricInternal(kCPUUsageNameHash, value);
    return *this;
}

const char CPUUsageMeasurement::kEventTypeName[] = "EventType";
const uint64_t CPUUsageMeasurement::kEventTypeNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetEventType(int64_t value)
{
    SetMetricInternal(kEventTypeNameHash, value);
    return *this;
}

const char CPUUsageMeasurement::kIsVisibleName[] = "IsVisible";
const uint64_t CPUUsageMeasurement::kIsVisibleNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetIsVisible(int64_t value)
{
    SetMetricInternal(kIsVisibleNameHash, value);
    return *this;
}

const char CPUUsageMeasurement::kNumberOfCoresidentTabsName[] = "NumberOfCoresidentTabs";
const uint64_t CPUUsageMeasurement::kNumberOfCoresidentTabsNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetNumberOfCoresidentTabs(int64_t value)
{
    SetMetricInternal(kNumberOfCoresidentTabsNameHash, value);
    return *this;
}

const char CPUUsageMeasurement::kObservationWindowSizeMsName[] = "ObservationWindowSizeMs";
const uint64_t CPUUsageMeasurement::kObservationWindowSizeMsNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetObservationWindowSizeMs(int64_t value)
{
    SetMetricInternal(kObservationWindowSizeMsNameHash, value);
    return *this;
}

const char CPUUsageMeasurement::kProcessUptimeMsName[] = "ProcessUptimeMs";
const uint64_t CPUUsageMeasurement::kProcessUptimeMsNameHash;

CPUUsageMeasurement& CPUUsageMeasurement::SetProcessUptimeMs(int64_t value)
{
    SetMetricInternal(kProcessUptimeMsNameHash, value);
    return *this;
}
const char CrossOriginSubframeWithoutEmbeddingControl::kEntryName[] = "CrossOriginSubframeWithoutEmbeddingControl";
const uint64_t CrossOriginSubframeWithoutEmbeddingControl::kEntryNameHash;

CrossOriginSubframeWithoutEmbeddingControl::CrossOriginSubframeWithoutEmbeddingControl(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

CrossOriginSubframeWithoutEmbeddingControl::CrossOriginSubframeWithoutEmbeddingControl(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

CrossOriginSubframeWithoutEmbeddingControl::~CrossOriginSubframeWithoutEmbeddingControl() = default;
const char CrossOriginSubframeWithoutEmbeddingControl::kSubframeEmbeddedName[] = "SubframeEmbedded";
const uint64_t CrossOriginSubframeWithoutEmbeddingControl::kSubframeEmbeddedNameHash;

CrossOriginSubframeWithoutEmbeddingControl& CrossOriginSubframeWithoutEmbeddingControl::SetSubframeEmbedded(int64_t value)
{
    SetMetricInternal(kSubframeEmbeddedNameHash, value);
    return *this;
}
const char DailyChargeSummary::kEntryName[] = "DailyChargeSummary";
const uint64_t DailyChargeSummary::kEntryNameHash;

DailyChargeSummary::DailyChargeSummary(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DailyChargeSummary::DailyChargeSummary(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DailyChargeSummary::~DailyChargeSummary() = default;
const char DailyChargeSummary::kDailySummaryHoldTimeOnAcName[] = "DailySummaryHoldTimeOnAc";
const uint64_t DailyChargeSummary::kDailySummaryHoldTimeOnAcNameHash;

DailyChargeSummary& DailyChargeSummary::SetDailySummaryHoldTimeOnAc(int64_t value)
{
    SetMetricInternal(kDailySummaryHoldTimeOnAcNameHash, value);
    return *this;
}

const char DailyChargeSummary::kDailySummaryIndexName[] = "DailySummaryIndex";
const uint64_t DailyChargeSummary::kDailySummaryIndexNameHash;

DailyChargeSummary& DailyChargeSummary::SetDailySummaryIndex(int64_t value)
{
    SetMetricInternal(kDailySummaryIndexNameHash, value);
    return *this;
}

const char DailyChargeSummary::kDailySummaryNumDaysDistanceName[] = "DailySummaryNumDaysDistance";
const uint64_t DailyChargeSummary::kDailySummaryNumDaysDistanceNameHash;

DailyChargeSummary& DailyChargeSummary::SetDailySummaryNumDaysDistance(int64_t value)
{
    SetMetricInternal(kDailySummaryNumDaysDistanceNameHash, value);
    return *this;
}

const char DailyChargeSummary::kDailySummarySizeName[] = "DailySummarySize";
const uint64_t DailyChargeSummary::kDailySummarySizeNameHash;

DailyChargeSummary& DailyChargeSummary::SetDailySummarySize(int64_t value)
{
    SetMetricInternal(kDailySummarySizeNameHash, value);
    return *this;
}

const char DailyChargeSummary::kDailySummaryTimeFullOnAcName[] = "DailySummaryTimeFullOnAc";
const uint64_t DailyChargeSummary::kDailySummaryTimeFullOnAcNameHash;

DailyChargeSummary& DailyChargeSummary::SetDailySummaryTimeFullOnAc(int64_t value)
{
    SetMetricInternal(kDailySummaryTimeFullOnAcNameHash, value);
    return *this;
}

const char DailyChargeSummary::kDailySummaryTimeOnAcName[] = "DailySummaryTimeOnAc";
const uint64_t DailyChargeSummary::kDailySummaryTimeOnAcNameHash;

DailyChargeSummary& DailyChargeSummary::SetDailySummaryTimeOnAc(int64_t value)
{
    SetMetricInternal(kDailySummaryTimeOnAcNameHash, value);
    return *this;
}

const char DailyChargeSummary::kEventIdName[] = "EventId";
const uint64_t DailyChargeSummary::kEventIdNameHash;

DailyChargeSummary& DailyChargeSummary::SetEventId(int64_t value)
{
    SetMetricInternal(kEventIdNameHash, value);
    return *this;
}
const char DataReductionProxy::kEntryName[] = "DataReductionProxy";
const uint64_t DataReductionProxy::kEntryNameHash;

DataReductionProxy::DataReductionProxy(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DataReductionProxy::DataReductionProxy(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DataReductionProxy::~DataReductionProxy() = default;
const char DataReductionProxy::kDataSaverPageUUIDName[] = "DataSaverPageUUID";
const uint64_t DataReductionProxy::kDataSaverPageUUIDNameHash;

DataReductionProxy& DataReductionProxy::SetDataSaverPageUUID(int64_t value)
{
    SetMetricInternal(kDataSaverPageUUIDNameHash, value);
    return *this;
}

const char DataReductionProxy::kEstimatedOriginalNetworkBytesName[] = "EstimatedOriginalNetworkBytes";
const uint64_t DataReductionProxy::kEstimatedOriginalNetworkBytesNameHash;

DataReductionProxy& DataReductionProxy::SetEstimatedOriginalNetworkBytes(int64_t value)
{
    SetMetricInternal(kEstimatedOriginalNetworkBytesNameHash, value);
    return *this;
}
const char DIPS_Redirect::kEntryName[] = "DIPS.Redirect";
const uint64_t DIPS_Redirect::kEntryNameHash;

DIPS_Redirect::DIPS_Redirect(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DIPS_Redirect::DIPS_Redirect(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DIPS_Redirect::~DIPS_Redirect() = default;
const char DIPS_Redirect::kClientBounceDelayName[] = "ClientBounceDelay";
const uint64_t DIPS_Redirect::kClientBounceDelayNameHash;

DIPS_Redirect& DIPS_Redirect::SetClientBounceDelay(int64_t value)
{
    SetMetricInternal(kClientBounceDelayNameHash, value);
    return *this;
}

const char DIPS_Redirect::kCookieAccessTypeName[] = "CookieAccessType";
const uint64_t DIPS_Redirect::kCookieAccessTypeNameHash;

DIPS_Redirect& DIPS_Redirect::SetCookieAccessType(int64_t value)
{
    SetMetricInternal(kCookieAccessTypeNameHash, value);
    return *this;
}

const char DIPS_Redirect::kHasStickyActivationName[] = "HasStickyActivation";
const uint64_t DIPS_Redirect::kHasStickyActivationNameHash;

DIPS_Redirect& DIPS_Redirect::SetHasStickyActivation(int64_t value)
{
    SetMetricInternal(kHasStickyActivationNameHash, value);
    return *this;
}

const char DIPS_Redirect::kInitialAndFinalSitesSameName[] = "InitialAndFinalSitesSame";
const uint64_t DIPS_Redirect::kInitialAndFinalSitesSameNameHash;

DIPS_Redirect& DIPS_Redirect::SetInitialAndFinalSitesSame(int64_t value)
{
    SetMetricInternal(kInitialAndFinalSitesSameNameHash, value);
    return *this;
}

const char DIPS_Redirect::kRedirectAndFinalSiteSameName[] = "RedirectAndFinalSiteSame";
const uint64_t DIPS_Redirect::kRedirectAndFinalSiteSameNameHash;

DIPS_Redirect& DIPS_Redirect::SetRedirectAndFinalSiteSame(int64_t value)
{
    SetMetricInternal(kRedirectAndFinalSiteSameNameHash, value);
    return *this;
}

const char DIPS_Redirect::kRedirectAndInitialSiteSameName[] = "RedirectAndInitialSiteSame";
const uint64_t DIPS_Redirect::kRedirectAndInitialSiteSameNameHash;

DIPS_Redirect& DIPS_Redirect::SetRedirectAndInitialSiteSame(int64_t value)
{
    SetMetricInternal(kRedirectAndInitialSiteSameNameHash, value);
    return *this;
}

const char DIPS_Redirect::kRedirectChainIndexName[] = "RedirectChainIndex";
const uint64_t DIPS_Redirect::kRedirectChainIndexNameHash;

DIPS_Redirect& DIPS_Redirect::SetRedirectChainIndex(int64_t value)
{
    SetMetricInternal(kRedirectChainIndexNameHash, value);
    return *this;
}

const char DIPS_Redirect::kRedirectChainLengthName[] = "RedirectChainLength";
const uint64_t DIPS_Redirect::kRedirectChainLengthNameHash;

DIPS_Redirect& DIPS_Redirect::SetRedirectChainLength(int64_t value)
{
    SetMetricInternal(kRedirectChainLengthNameHash, value);
    return *this;
}

const char DIPS_Redirect::kRedirectTypeName[] = "RedirectType";
const uint64_t DIPS_Redirect::kRedirectTypeNameHash;

DIPS_Redirect& DIPS_Redirect::SetRedirectType(int64_t value)
{
    SetMetricInternal(kRedirectTypeNameHash, value);
    return *this;
}

const char DIPS_Redirect::kSiteEngagementLevelName[] = "SiteEngagementLevel";
const uint64_t DIPS_Redirect::kSiteEngagementLevelNameHash;

DIPS_Redirect& DIPS_Redirect::SetSiteEngagementLevel(int64_t value)
{
    SetMetricInternal(kSiteEngagementLevelNameHash, value);
    return *this;
}
const char DocumentCreated::kEntryName[] = "DocumentCreated";
const uint64_t DocumentCreated::kEntryNameHash;

DocumentCreated::DocumentCreated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DocumentCreated::DocumentCreated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

DocumentCreated::~DocumentCreated() = default;
const char DocumentCreated::kIsCrossOriginFrameName[] = "IsCrossOriginFrame";
const uint64_t DocumentCreated::kIsCrossOriginFrameNameHash;

DocumentCreated& DocumentCreated::SetIsCrossOriginFrame(int64_t value)
{
    SetMetricInternal(kIsCrossOriginFrameNameHash, value);
    return *this;
}

const char DocumentCreated::kIsCrossSiteFrameName[] = "IsCrossSiteFrame";
const uint64_t DocumentCreated::kIsCrossSiteFrameNameHash;

DocumentCreated& DocumentCreated::SetIsCrossSiteFrame(int64_t value)
{
    SetMetricInternal(kIsCrossSiteFrameNameHash, value);
    return *this;
}

const char DocumentCreated::kIsMainFrameName[] = "IsMainFrame";
const uint64_t DocumentCreated::kIsMainFrameNameHash;

DocumentCreated& DocumentCreated::SetIsMainFrame(int64_t value)
{
    SetMetricInternal(kIsMainFrameNameHash, value);
    return *this;
}

const char DocumentCreated::kNavigationSourceIdName[] = "NavigationSourceId";
const uint64_t DocumentCreated::kNavigationSourceIdNameHash;

DocumentCreated& DocumentCreated::SetNavigationSourceId(int64_t value)
{
    SetMetricInternal(kNavigationSourceIdNameHash, value);
    return *this;
}
const char Download_Completed::kEntryName[] = "Download.Completed";
const uint64_t Download_Completed::kEntryNameHash;

Download_Completed::Download_Completed(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Completed::Download_Completed(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Completed::~Download_Completed() = default;
const char Download_Completed::kBytesWastedName[] = "BytesWasted";
const uint64_t Download_Completed::kBytesWastedNameHash;

Download_Completed& Download_Completed::SetBytesWasted(int64_t value)
{
    SetMetricInternal(kBytesWastedNameHash, value);
    return *this;
}

const char Download_Completed::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Completed::kDownloadIdNameHash;

Download_Completed& Download_Completed::SetDownloadId(int64_t value)
{
    SetMetricInternal(kDownloadIdNameHash, value);
    return *this;
}

const char Download_Completed::kResultingFileSizeName[] = "ResultingFileSize";
const uint64_t Download_Completed::kResultingFileSizeNameHash;

Download_Completed& Download_Completed::SetResultingFileSize(int64_t value)
{
    SetMetricInternal(kResultingFileSizeNameHash, value);
    return *this;
}

const char Download_Completed::kTimeSinceStartName[] = "TimeSinceStart";
const uint64_t Download_Completed::kTimeSinceStartNameHash;

Download_Completed& Download_Completed::SetTimeSinceStart(int64_t value)
{
    SetMetricInternal(kTimeSinceStartNameHash, value);
    return *this;
}
const char Download_Interrupted::kEntryName[] = "Download.Interrupted";
const uint64_t Download_Interrupted::kEntryNameHash;

Download_Interrupted::Download_Interrupted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Interrupted::Download_Interrupted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Interrupted::~Download_Interrupted() = default;
const char Download_Interrupted::kBytesWastedName[] = "BytesWasted";
const uint64_t Download_Interrupted::kBytesWastedNameHash;

Download_Interrupted& Download_Interrupted::SetBytesWasted(int64_t value)
{
    SetMetricInternal(kBytesWastedNameHash, value);
    return *this;
}

const char Download_Interrupted::kChangeInFileSizeName[] = "ChangeInFileSize";
const uint64_t Download_Interrupted::kChangeInFileSizeNameHash;

Download_Interrupted& Download_Interrupted::SetChangeInFileSize(int64_t value)
{
    SetMetricInternal(kChangeInFileSizeNameHash, value);
    return *this;
}

const char Download_Interrupted::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Interrupted::kDownloadIdNameHash;

Download_Interrupted& Download_Interrupted::SetDownloadId(int64_t value)
{
    SetMetricInternal(kDownloadIdNameHash, value);
    return *this;
}

const char Download_Interrupted::kReasonName[] = "Reason";
const uint64_t Download_Interrupted::kReasonNameHash;

Download_Interrupted& Download_Interrupted::SetReason(int64_t value)
{
    SetMetricInternal(kReasonNameHash, value);
    return *this;
}

const char Download_Interrupted::kResultingFileSizeName[] = "ResultingFileSize";
const uint64_t Download_Interrupted::kResultingFileSizeNameHash;

Download_Interrupted& Download_Interrupted::SetResultingFileSize(int64_t value)
{
    SetMetricInternal(kResultingFileSizeNameHash, value);
    return *this;
}

const char Download_Interrupted::kTimeSinceStartName[] = "TimeSinceStart";
const uint64_t Download_Interrupted::kTimeSinceStartNameHash;

Download_Interrupted& Download_Interrupted::SetTimeSinceStart(int64_t value)
{
    SetMetricInternal(kTimeSinceStartNameHash, value);
    return *this;
}
const char Download_Resumed::kEntryName[] = "Download.Resumed";
const uint64_t Download_Resumed::kEntryNameHash;

Download_Resumed::Download_Resumed(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Resumed::Download_Resumed(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Resumed::~Download_Resumed() = default;
const char Download_Resumed::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Resumed::kDownloadIdNameHash;

Download_Resumed& Download_Resumed::SetDownloadId(int64_t value)
{
    SetMetricInternal(kDownloadIdNameHash, value);
    return *this;
}

const char Download_Resumed::kModeName[] = "Mode";
const uint64_t Download_Resumed::kModeNameHash;

Download_Resumed& Download_Resumed::SetMode(int64_t value)
{
    SetMetricInternal(kModeNameHash, value);
    return *this;
}

const char Download_Resumed::kTimeSinceStartName[] = "TimeSinceStart";
const uint64_t Download_Resumed::kTimeSinceStartNameHash;

Download_Resumed& Download_Resumed::SetTimeSinceStart(int64_t value)
{
    SetMetricInternal(kTimeSinceStartNameHash, value);
    return *this;
}
const char Download_Started::kEntryName[] = "Download.Started";
const uint64_t Download_Started::kEntryNameHash;

Download_Started::Download_Started(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Started::Download_Started(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Download_Started::~Download_Started() = default;
const char Download_Started::kDownloadConnectionSecurityName[] = "DownloadConnectionSecurity";
const uint64_t Download_Started::kDownloadConnectionSecurityNameHash;

Download_Started& Download_Started::SetDownloadConnectionSecurity(int64_t value)
{
    SetMetricInternal(kDownloadConnectionSecurityNameHash, value);
    return *this;
}

const char Download_Started::kDownloadIdName[] = "DownloadId";
const uint64_t Download_Started::kDownloadIdNameHash;

Download_Started& Download_Started::SetDownloadId(int64_t value)
{
    SetMetricInternal(kDownloadIdNameHash, value);
    return *this;
}

const char Download_Started::kDownloadSourceName[] = "DownloadSource";
const uint64_t Download_Started::kDownloadSourceNameHash;

Download_Started& Download_Started::SetDownloadSource(int64_t value)
{
    SetMetricInternal(kDownloadSourceNameHash, value);
    return *this;
}

const char Download_Started::kFileTypeName[] = "FileType";
const uint64_t Download_Started::kFileTypeNameHash;

Download_Started& Download_Started::SetFileType(int64_t value)
{
    SetMetricInternal(kFileTypeNameHash, value);
    return *this;
}

const char Download_Started::kIsSameHostDownloadName[] = "IsSameHostDownload";
const uint64_t Download_Started::kIsSameHostDownloadNameHash;

Download_Started& Download_Started::SetIsSameHostDownload(int64_t value)
{
    SetMetricInternal(kIsSameHostDownloadNameHash, value);
    return *this;
}
const char Event_ScrollBegin_Touch::kEntryName[] = "Event.ScrollBegin.Touch";
const uint64_t Event_ScrollBegin_Touch::kEntryNameHash;

Event_ScrollBegin_Touch::Event_ScrollBegin_Touch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollBegin_Touch::Event_ScrollBegin_Touch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollBegin_Touch::~Event_ScrollBegin_Touch() = default;
const char Event_ScrollBegin_Touch::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollBegin_Touch::kIsMainThreadNameHash;

Event_ScrollBegin_Touch& Event_ScrollBegin_Touch::SetIsMainThread(int64_t value)
{
    SetMetricInternal(kIsMainThreadNameHash, value);
    return *this;
}

const char Event_ScrollBegin_Touch::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollBegin_Touch::kTimeToHandledNameHash;

Event_ScrollBegin_Touch& Event_ScrollBegin_Touch::SetTimeToHandled(int64_t value)
{
    SetMetricInternal(kTimeToHandledNameHash, value);
    return *this;
}

const char Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollBegin_Touch& Event_ScrollBegin_Touch::SetTimeToScrollUpdateSwapBegin(int64_t value)
{
    SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
    return *this;
}
const char Event_ScrollBegin_Wheel::kEntryName[] = "Event.ScrollBegin.Wheel";
const uint64_t Event_ScrollBegin_Wheel::kEntryNameHash;

Event_ScrollBegin_Wheel::Event_ScrollBegin_Wheel(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollBegin_Wheel::Event_ScrollBegin_Wheel(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollBegin_Wheel::~Event_ScrollBegin_Wheel() = default;
const char Event_ScrollBegin_Wheel::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollBegin_Wheel::kIsMainThreadNameHash;

Event_ScrollBegin_Wheel& Event_ScrollBegin_Wheel::SetIsMainThread(int64_t value)
{
    SetMetricInternal(kIsMainThreadNameHash, value);
    return *this;
}

const char Event_ScrollBegin_Wheel::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollBegin_Wheel::kTimeToHandledNameHash;

Event_ScrollBegin_Wheel& Event_ScrollBegin_Wheel::SetTimeToHandled(int64_t value)
{
    SetMetricInternal(kTimeToHandledNameHash, value);
    return *this;
}

const char Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollBegin_Wheel& Event_ScrollBegin_Wheel::SetTimeToScrollUpdateSwapBegin(int64_t value)
{
    SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
    return *this;
}
const char Event_ScrollUpdate_Touch::kEntryName[] = "Event.ScrollUpdate.Touch";
const uint64_t Event_ScrollUpdate_Touch::kEntryNameHash;

Event_ScrollUpdate_Touch::Event_ScrollUpdate_Touch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollUpdate_Touch::Event_ScrollUpdate_Touch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollUpdate_Touch::~Event_ScrollUpdate_Touch() = default;
const char Event_ScrollUpdate_Touch::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollUpdate_Touch::kIsMainThreadNameHash;

Event_ScrollUpdate_Touch& Event_ScrollUpdate_Touch::SetIsMainThread(int64_t value)
{
    SetMetricInternal(kIsMainThreadNameHash, value);
    return *this;
}

const char Event_ScrollUpdate_Touch::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollUpdate_Touch::kTimeToHandledNameHash;

Event_ScrollUpdate_Touch& Event_ScrollUpdate_Touch::SetTimeToHandled(int64_t value)
{
    SetMetricInternal(kTimeToHandledNameHash, value);
    return *this;
}

const char Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollUpdate_Touch& Event_ScrollUpdate_Touch::SetTimeToScrollUpdateSwapBegin(int64_t value)
{
    SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
    return *this;
}
const char Event_ScrollUpdate_Wheel::kEntryName[] = "Event.ScrollUpdate.Wheel";
const uint64_t Event_ScrollUpdate_Wheel::kEntryNameHash;

Event_ScrollUpdate_Wheel::Event_ScrollUpdate_Wheel(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollUpdate_Wheel::Event_ScrollUpdate_Wheel(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Event_ScrollUpdate_Wheel::~Event_ScrollUpdate_Wheel() = default;
const char Event_ScrollUpdate_Wheel::kIsMainThreadName[] = "IsMainThread";
const uint64_t Event_ScrollUpdate_Wheel::kIsMainThreadNameHash;

Event_ScrollUpdate_Wheel& Event_ScrollUpdate_Wheel::SetIsMainThread(int64_t value)
{
    SetMetricInternal(kIsMainThreadNameHash, value);
    return *this;
}

const char Event_ScrollUpdate_Wheel::kTimeToHandledName[] = "TimeToHandled";
const uint64_t Event_ScrollUpdate_Wheel::kTimeToHandledNameHash;

Event_ScrollUpdate_Wheel& Event_ScrollUpdate_Wheel::SetTimeToHandled(int64_t value)
{
    SetMetricInternal(kTimeToHandledNameHash, value);
    return *this;
}

const char Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginName[] = "TimeToScrollUpdateSwapBegin";
const uint64_t Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginNameHash;

Event_ScrollUpdate_Wheel& Event_ScrollUpdate_Wheel::SetTimeToScrollUpdateSwapBegin(int64_t value)
{
    SetMetricInternal(kTimeToScrollUpdateSwapBeginNameHash, value);
    return *this;
}
const char Extensions_WebRequest_KeepaliveRequestFinished::kEntryName[] = "Extensions.WebRequest.KeepaliveRequestFinished";
const uint64_t Extensions_WebRequest_KeepaliveRequestFinished::kEntryNameHash;

Extensions_WebRequest_KeepaliveRequestFinished::Extensions_WebRequest_KeepaliveRequestFinished(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Extensions_WebRequest_KeepaliveRequestFinished::Extensions_WebRequest_KeepaliveRequestFinished(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Extensions_WebRequest_KeepaliveRequestFinished::~Extensions_WebRequest_KeepaliveRequestFinished() = default;
const char Extensions_WebRequest_KeepaliveRequestFinished::kNumRedirectsName[] = "NumRedirects";
const uint64_t Extensions_WebRequest_KeepaliveRequestFinished::kNumRedirectsNameHash;

Extensions_WebRequest_KeepaliveRequestFinished& Extensions_WebRequest_KeepaliveRequestFinished::SetNumRedirects(int64_t value)
{
    SetMetricInternal(kNumRedirectsNameHash, value);
    return *this;
}

const char Extensions_WebRequest_KeepaliveRequestFinished::kStateName[] = "State";
const uint64_t Extensions_WebRequest_KeepaliveRequestFinished::kStateNameHash;

Extensions_WebRequest_KeepaliveRequestFinished& Extensions_WebRequest_KeepaliveRequestFinished::SetState(int64_t value)
{
    SetMetricInternal(kStateNameHash, value);
    return *this;
}
const char FileSystemAPI_WebRequest::kEntryName[] = "FileSystemAPI.WebRequest";
const uint64_t FileSystemAPI_WebRequest::kEntryNameHash;

FileSystemAPI_WebRequest::FileSystemAPI_WebRequest(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FileSystemAPI_WebRequest::FileSystemAPI_WebRequest(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FileSystemAPI_WebRequest::~FileSystemAPI_WebRequest() = default;
const char FileSystemAPI_WebRequest::kPersistentName[] = "Persistent";
const uint64_t FileSystemAPI_WebRequest::kPersistentNameHash;

FileSystemAPI_WebRequest& FileSystemAPI_WebRequest::SetPersistent(int64_t value)
{
    SetMetricInternal(kPersistentNameHash, value);
    return *this;
}

const char FileSystemAPI_WebRequest::kTemporaryName[] = "Temporary";
const uint64_t FileSystemAPI_WebRequest::kTemporaryNameHash;

FileSystemAPI_WebRequest& FileSystemAPI_WebRequest::SetTemporary(int64_t value)
{
    SetMetricInternal(kTemporaryNameHash, value);
    return *this;
}
const char FlocPageLoad::kEntryName[] = "FlocPageLoad";
const uint64_t FlocPageLoad::kEntryNameHash;

FlocPageLoad::FlocPageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FlocPageLoad::FlocPageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FlocPageLoad::~FlocPageLoad() = default;
const char FlocPageLoad::kFlocIdName[] = "FlocId";
const uint64_t FlocPageLoad::kFlocIdNameHash;

FlocPageLoad& FlocPageLoad::SetFlocId(int64_t value)
{
    SetMetricInternal(kFlocIdNameHash, value);
    return *this;
}
const char FontMatchAttempts::kEntryName[] = "FontMatchAttempts";
const uint64_t FontMatchAttempts::kEntryNameHash;

FontMatchAttempts::FontMatchAttempts(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FontMatchAttempts::FontMatchAttempts(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

FontMatchAttempts::~FontMatchAttempts() = default;
const char FontMatchAttempts::kLoadContextName[] = "LoadContext";
const uint64_t FontMatchAttempts::kLoadContextNameHash;

FontMatchAttempts& FontMatchAttempts::SetLoadContext(int64_t value)
{
    SetMetricInternal(kLoadContextNameHash, value);
    return *this;
}

const char FontMatchAttempts::kLocalFontFailuresName[] = "LocalFontFailures";
const uint64_t FontMatchAttempts::kLocalFontFailuresNameHash;

FontMatchAttempts& FontMatchAttempts::SetLocalFontFailures(int64_t value)
{
    SetMetricInternal(kLocalFontFailuresNameHash, value);
    return *this;
}

const char FontMatchAttempts::kLocalFontSuccessesName[] = "LocalFontSuccesses";
const uint64_t FontMatchAttempts::kLocalFontSuccessesNameHash;

FontMatchAttempts& FontMatchAttempts::SetLocalFontSuccesses(int64_t value)
{
    SetMetricInternal(kLocalFontSuccessesNameHash, value);
    return *this;
}

const char FontMatchAttempts::kLocalFontTotalName[] = "LocalFontTotal";
const uint64_t FontMatchAttempts::kLocalFontTotalNameHash;

FontMatchAttempts& FontMatchAttempts::SetLocalFontTotal(int64_t value)
{
    SetMetricInternal(kLocalFontTotalNameHash, value);
    return *this;
}

const char FontMatchAttempts::kSystemFontFamilyFailuresName[] = "SystemFontFamilyFailures";
const uint64_t FontMatchAttempts::kSystemFontFamilyFailuresNameHash;

FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilyFailures(int64_t value)
{
    SetMetricInternal(kSystemFontFamilyFailuresNameHash, value);
    return *this;
}

const char FontMatchAttempts::kSystemFontFamilySuccessesName[] = "SystemFontFamilySuccesses";
const uint64_t FontMatchAttempts::kSystemFontFamilySuccessesNameHash;

FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilySuccesses(int64_t value)
{
    SetMetricInternal(kSystemFontFamilySuccessesNameHash, value);
    return *this;
}

const char FontMatchAttempts::kSystemFontFamilyTotalName[] = "SystemFontFamilyTotal";
const uint64_t FontMatchAttempts::kSystemFontFamilyTotalNameHash;

FontMatchAttempts& FontMatchAttempts::SetSystemFontFamilyTotal(int64_t value)
{
    SetMetricInternal(kSystemFontFamilyTotalNameHash, value);
    return *this;
}

const char FontMatchAttempts::kWebFontFamilyFailuresName[] = "WebFontFamilyFailures";
const uint64_t FontMatchAttempts::kWebFontFamilyFailuresNameHash;

FontMatchAttempts& FontMatchAttempts::SetWebFontFamilyFailures(int64_t value)
{
    SetMetricInternal(kWebFontFamilyFailuresNameHash, value);
    return *this;
}

const char FontMatchAttempts::kWebFontFamilySuccessesName[] = "WebFontFamilySuccesses";
const uint64_t FontMatchAttempts::kWebFontFamilySuccessesNameHash;

FontMatchAttempts& FontMatchAttempts::SetWebFontFamilySuccesses(int64_t value)
{
    SetMetricInternal(kWebFontFamilySuccessesNameHash, value);
    return *this;
}

const char FontMatchAttempts::kWebFontFamilyTotalName[] = "WebFontFamilyTotal";
const uint64_t FontMatchAttempts::kWebFontFamilyTotalNameHash;

FontMatchAttempts& FontMatchAttempts::SetWebFontFamilyTotal(int64_t value)
{
    SetMetricInternal(kWebFontFamilyTotalNameHash, value);
    return *this;
}
const char GamingInputOverlay_Customization::kEntryName[] = "GamingInputOverlay.Customization";
const uint64_t GamingInputOverlay_Customization::kEntryNameHash;

GamingInputOverlay_Customization::GamingInputOverlay_Customization(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GamingInputOverlay_Customization::GamingInputOverlay_Customization(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GamingInputOverlay_Customization::~GamingInputOverlay_Customization() = default;
const char GamingInputOverlay_Customization::kCustomizationUsedName[] = "CustomizationUsed";
const uint64_t GamingInputOverlay_Customization::kCustomizationUsedNameHash;

GamingInputOverlay_Customization& GamingInputOverlay_Customization::SetCustomizationUsed(int64_t value)
{
    SetMetricInternal(kCustomizationUsedNameHash, value);
    return *this;
}
const char GamingInputOverlay_Feature::kEntryName[] = "GamingInputOverlay.Feature";
const uint64_t GamingInputOverlay_Feature::kEntryNameHash;

GamingInputOverlay_Feature::GamingInputOverlay_Feature(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GamingInputOverlay_Feature::GamingInputOverlay_Feature(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GamingInputOverlay_Feature::~GamingInputOverlay_Feature() = default;
const char GamingInputOverlay_Feature::kFeatureStateOnName[] = "FeatureStateOn";
const uint64_t GamingInputOverlay_Feature::kFeatureStateOnNameHash;

GamingInputOverlay_Feature& GamingInputOverlay_Feature::SetFeatureStateOn(int64_t value)
{
    SetMetricInternal(kFeatureStateOnNameHash, value);
    return *this;
}
const char GamingInputOverlay_MappingHint::kEntryName[] = "GamingInputOverlay.MappingHint";
const uint64_t GamingInputOverlay_MappingHint::kEntryNameHash;

GamingInputOverlay_MappingHint::GamingInputOverlay_MappingHint(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GamingInputOverlay_MappingHint::GamingInputOverlay_MappingHint(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GamingInputOverlay_MappingHint::~GamingInputOverlay_MappingHint() = default;
const char GamingInputOverlay_MappingHint::kMappingHintStateOnName[] = "MappingHintStateOn";
const uint64_t GamingInputOverlay_MappingHint::kMappingHintStateOnNameHash;

GamingInputOverlay_MappingHint& GamingInputOverlay_MappingHint::SetMappingHintStateOn(int64_t value)
{
    SetMetricInternal(kMappingHintStateOnNameHash, value);
    return *this;
}
const char GeneratedNavigation::kEntryName[] = "GeneratedNavigation";
const uint64_t GeneratedNavigation::kEntryNameHash;

GeneratedNavigation::GeneratedNavigation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GeneratedNavigation::GeneratedNavigation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GeneratedNavigation::~GeneratedNavigation() = default;
const char GeneratedNavigation::kFinalURLIsDefaultSearchEngineName[] = "FinalURLIsDefaultSearchEngine";
const uint64_t GeneratedNavigation::kFinalURLIsDefaultSearchEngineNameHash;

GeneratedNavigation& GeneratedNavigation::SetFinalURLIsDefaultSearchEngine(int64_t value)
{
    SetMetricInternal(kFinalURLIsDefaultSearchEngineNameHash, value);
    return *this;
}

const char GeneratedNavigation::kFinalURLIsHomePageName[] = "FinalURLIsHomePage";
const uint64_t GeneratedNavigation::kFinalURLIsHomePageNameHash;

GeneratedNavigation& GeneratedNavigation::SetFinalURLIsHomePage(int64_t value)
{
    SetMetricInternal(kFinalURLIsHomePageNameHash, value);
    return *this;
}

const char GeneratedNavigation::kFirstURLIsDefaultSearchEngineName[] = "FirstURLIsDefaultSearchEngine";
const uint64_t GeneratedNavigation::kFirstURLIsDefaultSearchEngineNameHash;

GeneratedNavigation& GeneratedNavigation::SetFirstURLIsDefaultSearchEngine(int64_t value)
{
    SetMetricInternal(kFirstURLIsDefaultSearchEngineNameHash, value);
    return *this;
}

const char GeneratedNavigation::kFirstURLIsHomePageName[] = "FirstURLIsHomePage";
const uint64_t GeneratedNavigation::kFirstURLIsHomePageNameHash;

GeneratedNavigation& GeneratedNavigation::SetFirstURLIsHomePage(int64_t value)
{
    SetMetricInternal(kFirstURLIsHomePageNameHash, value);
    return *this;
}
const char GoogleDocsOfflineExtension::kEntryName[] = "GoogleDocsOfflineExtension";
const uint64_t GoogleDocsOfflineExtension::kEntryNameHash;

GoogleDocsOfflineExtension::GoogleDocsOfflineExtension(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GoogleDocsOfflineExtension::GoogleDocsOfflineExtension(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

GoogleDocsOfflineExtension::~GoogleDocsOfflineExtension() = default;
const char GoogleDocsOfflineExtension::kResourceRequestedName[] = "ResourceRequested";
const uint64_t GoogleDocsOfflineExtension::kResourceRequestedNameHash;

GoogleDocsOfflineExtension& GoogleDocsOfflineExtension::SetResourceRequested(int64_t value)
{
    SetMetricInternal(kResourceRequestedNameHash, value);
    return *this;
}
const char Graphics_Smoothness_EventLatency::kEntryName[] = "Graphics.Smoothness.EventLatency";
const uint64_t Graphics_Smoothness_EventLatency::kEntryNameHash;

Graphics_Smoothness_EventLatency::Graphics_Smoothness_EventLatency(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_EventLatency::Graphics_Smoothness_EventLatency(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_EventLatency::~Graphics_Smoothness_EventLatency() = default;
const char Graphics_Smoothness_EventLatency::kActivationName[] = "Activation";
const uint64_t Graphics_Smoothness_EventLatency::kActivationNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetActivation(int64_t value)
{
    SetMetricInternal(kActivationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameName[] = "BeginImplFrameToSendBeginMainFrame";
const uint64_t Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetBeginImplFrameToSendBeginMainFrame(int64_t value)
{
    SetMetricInternal(kBeginImplFrameToSendBeginMainFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kCommitName[] = "Commit";
const uint64_t Graphics_Smoothness_EventLatency::kCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetCommit(int64_t value)
{
    SetMetricInternal(kCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameName[] = "EndActivateToSubmitCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetEndActivateToSubmitCompositorFrame(int64_t value)
{
    SetMetricInternal(kEndActivateToSubmitCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kEndCommitToActivationName[] = "EndCommitToActivation";
const uint64_t Graphics_Smoothness_EventLatency::kEndCommitToActivationNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetEndCommitToActivation(int64_t value)
{
    SetMetricInternal(kEndCommitToActivationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kEventTypeName[] = "EventType";
const uint64_t Graphics_Smoothness_EventLatency::kEventTypeNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetEventType(int64_t value)
{
    SetMetricInternal(kEventTypeNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kGenerationToRendererCompositorName[] = "GenerationToRendererCompositor";
const uint64_t Graphics_Smoothness_EventLatency::kGenerationToRendererCompositorNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetGenerationToRendererCompositor(int64_t value)
{
    SetMetricInternal(kGenerationToRendererCompositorNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kPinchInputTypeName[] = "PinchInputType";
const uint64_t Graphics_Smoothness_EventLatency::kPinchInputTypeNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetPinchInputType(int64_t value)
{
    SetMetricInternal(kPinchInputTypeNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToActivationName[] = "RendererCompositorFinishedToActivation";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToActivationNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToActivation(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToActivationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToBeginImplFrameName[] = "RendererCompositorFinishedToBeginImplFrame";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToBeginImplFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToBeginImplFrame(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToBeginImplFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToCommitName[] = "RendererCompositorFinishedToCommit";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToCommit(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndActivateName[] = "RendererCompositorFinishedToEndActivate";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndActivateNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToEndActivate(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToEndActivateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndCommitName[] = "RendererCompositorFinishedToEndCommit";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToEndCommit(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToEndCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSendBeginMainFrameName[] = "RendererCompositorFinishedToSendBeginMainFrame";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSendBeginMainFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToSendBeginMainFrame(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToSendBeginMainFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSubmitCompositorFrameName[] = "RendererCompositorFinishedToSubmitCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSubmitCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorFinishedToSubmitCompositorFrame(int64_t value)
{
    SetMetricInternal(kRendererCompositorFinishedToSubmitCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorProcessingName[] = "RendererCompositorProcessing";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorProcessingNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorProcessing(int64_t value)
{
    SetMetricInternal(kRendererCompositorProcessingNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorQueueingDelayName[] = "RendererCompositorQueueingDelay";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorQueueingDelayNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorQueueingDelay(int64_t value)
{
    SetMetricInternal(kRendererCompositorQueueingDelayNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererCompositorToMainName[] = "RendererCompositorToMain";
const uint64_t Graphics_Smoothness_EventLatency::kRendererCompositorToMainNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererCompositorToMain(int64_t value)
{
    SetMetricInternal(kRendererCompositorToMainNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToActivationName[] = "RendererMainFinishedToActivation";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToActivationNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToActivation(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToActivationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToBeginImplFrameName[] = "RendererMainFinishedToBeginImplFrame";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToBeginImplFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToBeginImplFrame(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToBeginImplFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToCommitName[] = "RendererMainFinishedToCommit";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToCommit(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndActivateName[] = "RendererMainFinishedToEndActivate";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndActivateNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToEndActivate(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToEndActivateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndCommitName[] = "RendererMainFinishedToEndCommit";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToEndCommit(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToEndCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToSendBeginMainFrameName[] = "RendererMainFinishedToSendBeginMainFrame";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToSendBeginMainFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToSendBeginMainFrame(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToSendBeginMainFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainFinishedToSubmitCompositorFrameName[] = "RendererMainFinishedToSubmitCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainFinishedToSubmitCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainFinishedToSubmitCompositorFrame(int64_t value)
{
    SetMetricInternal(kRendererMainFinishedToSubmitCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kRendererMainProcessingName[] = "RendererMainProcessing";
const uint64_t Graphics_Smoothness_EventLatency::kRendererMainProcessingNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetRendererMainProcessing(int64_t value)
{
    SetMetricInternal(kRendererMainProcessingNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kScrollInputTypeName[] = "ScrollInputType";
const uint64_t Graphics_Smoothness_EventLatency::kScrollInputTypeNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetScrollInputType(int64_t value)
{
    SetMetricInternal(kScrollInputTypeNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitName[] = "SendBeginMainFrameToCommit";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AccessibilityName[] = "SendBeginMainFrameToCommit.Accessibility";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AccessibilityNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_Accessibility(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_AccessibilityNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AnimateName[] = "SendBeginMainFrameToCommit.Animate";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AnimateNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_Animate(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_AnimateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_BeginMainSentToStartedName[] = "SendBeginMainFrameToCommit.BeginMainSentToStarted";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_BeginMainSentToStarted(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositeCommitName[] = "SendBeginMainFrameToCommit.CompositeCommit";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositeCommitNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_CompositeCommit(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_CompositeCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositingInputsName[] = "SendBeginMainFrameToCommit.CompositingInputs";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositingInputsNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_CompositingInputs(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_CompositingInputsNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_HandleInputEventsName[] = "SendBeginMainFrameToCommit.HandleInputEvents";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_HandleInputEventsNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_HandleInputEvents(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_HandleInputEventsNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_LayoutUpdateName[] = "SendBeginMainFrameToCommit.LayoutUpdate";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_LayoutUpdateNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_LayoutUpdate(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_LayoutUpdateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PaintName[] = "SendBeginMainFrameToCommit.Paint";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PaintNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_Paint(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_PaintNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PrepaintName[] = "SendBeginMainFrameToCommit.Prepaint";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PrepaintNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_Prepaint(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_PrepaintNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_StyleUpdateName[] = "SendBeginMainFrameToCommit.StyleUpdate";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_StyleUpdateNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_StyleUpdate(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_StyleUpdateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_UpdateLayersName[] = "SendBeginMainFrameToCommit.UpdateLayers";
const uint64_t Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_UpdateLayersNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSendBeginMainFrameToCommit_UpdateLayers(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_UpdateLayersNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameName[] = "SubmitCompositorFrameToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.BufferAvailableToBufferReady";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReady(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.BufferReadyToLatch";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatch(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.LatchToSwapEnd";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEnd(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.ReceivedCompositorFrameToStartDraw";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDraw(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.StartDrawToSwapStart";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStart(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SubmitToReceiveCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrame(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SwapEndToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrame(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SwapStartToBufferAvailable";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailable(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SwapStartToSwapEnd";
const uint64_t Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEnd(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash, value);
    return *this;
}

const char Graphics_Smoothness_EventLatency::kTotalLatencyName[] = "TotalLatency";
const uint64_t Graphics_Smoothness_EventLatency::kTotalLatencyNameHash;

Graphics_Smoothness_EventLatency& Graphics_Smoothness_EventLatency::SetTotalLatency(int64_t value)
{
    SetMetricInternal(kTotalLatencyNameHash, value);
    return *this;
}
const char Graphics_Smoothness_Latency::kEntryName[] = "Graphics.Smoothness.Latency";
const uint64_t Graphics_Smoothness_Latency::kEntryNameHash;

Graphics_Smoothness_Latency::Graphics_Smoothness_Latency(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_Latency::Graphics_Smoothness_Latency(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_Latency::~Graphics_Smoothness_Latency() = default;
const char Graphics_Smoothness_Latency::kActivationName[] = "Activation";
const uint64_t Graphics_Smoothness_Latency::kActivationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetActivation(int64_t value)
{
    SetMetricInternal(kActivationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameName[] = "BeginImplFrameToSendBeginMainFrame";
const uint64_t Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetBeginImplFrameToSendBeginMainFrame(int64_t value)
{
    SetMetricInternal(kBeginImplFrameToSendBeginMainFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kCanvasAnimationName[] = "CanvasAnimation";
const uint64_t Graphics_Smoothness_Latency::kCanvasAnimationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetCanvasAnimation(int64_t value)
{
    SetMetricInternal(kCanvasAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kCommitName[] = "Commit";
const uint64_t Graphics_Smoothness_Latency::kCommitNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetCommit(int64_t value)
{
    SetMetricInternal(kCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kCompositorAnimationName[] = "CompositorAnimation";
const uint64_t Graphics_Smoothness_Latency::kCompositorAnimationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetCompositorAnimation(int64_t value)
{
    SetMetricInternal(kCompositorAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameName[] = "EndActivateToSubmitCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetEndActivateToSubmitCompositorFrame(int64_t value)
{
    SetMetricInternal(kEndActivateToSubmitCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kEndCommitToActivationName[] = "EndCommitToActivation";
const uint64_t Graphics_Smoothness_Latency::kEndCommitToActivationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetEndCommitToActivation(int64_t value)
{
    SetMetricInternal(kEndCommitToActivationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kJSAnimationName[] = "JSAnimation";
const uint64_t Graphics_Smoothness_Latency::kJSAnimationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetJSAnimation(int64_t value)
{
    SetMetricInternal(kJSAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kMainThreadAnimationName[] = "MainThreadAnimation";
const uint64_t Graphics_Smoothness_Latency::kMainThreadAnimationNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetMainThreadAnimation(int64_t value)
{
    SetMetricInternal(kMainThreadAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kMissedFrameName[] = "MissedFrame";
const uint64_t Graphics_Smoothness_Latency::kMissedFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetMissedFrame(int64_t value)
{
    SetMetricInternal(kMissedFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kPinchZoomName[] = "PinchZoom";
const uint64_t Graphics_Smoothness_Latency::kPinchZoomNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetPinchZoom(int64_t value)
{
    SetMetricInternal(kPinchZoomNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kRAFName[] = "RAF";
const uint64_t Graphics_Smoothness_Latency::kRAFNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetRAF(int64_t value)
{
    SetMetricInternal(kRAFNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kScrollbarScrollName[] = "ScrollbarScroll";
const uint64_t Graphics_Smoothness_Latency::kScrollbarScrollNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetScrollbarScroll(int64_t value)
{
    SetMetricInternal(kScrollbarScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitName[] = "SendBeginMainFrameToCommit";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AccessibilityName[] = "SendBeginMainFrameToCommit.Accessibility";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AccessibilityNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_Accessibility(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_AccessibilityNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AnimateName[] = "SendBeginMainFrameToCommit.Animate";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AnimateNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_Animate(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_AnimateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_BeginMainSentToStartedName[] = "SendBeginMainFrameToCommit.BeginMainSentToStarted";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_BeginMainSentToStarted(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositeCommitName[] = "SendBeginMainFrameToCommit.CompositeCommit";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositeCommitNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_CompositeCommit(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_CompositeCommitNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositingInputsName[] = "SendBeginMainFrameToCommit.CompositingInputs";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositingInputsNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_CompositingInputs(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_CompositingInputsNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_HandleInputEventsName[] = "SendBeginMainFrameToCommit.HandleInputEvents";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_HandleInputEventsNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_HandleInputEvents(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_HandleInputEventsNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_LayoutUpdateName[] = "SendBeginMainFrameToCommit.LayoutUpdate";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_LayoutUpdateNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_LayoutUpdate(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_LayoutUpdateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PaintName[] = "SendBeginMainFrameToCommit.Paint";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PaintNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_Paint(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_PaintNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PrepaintName[] = "SendBeginMainFrameToCommit.Prepaint";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PrepaintNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_Prepaint(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_PrepaintNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_StyleUpdateName[] = "SendBeginMainFrameToCommit.StyleUpdate";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_StyleUpdateNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_StyleUpdate(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_StyleUpdateNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_UpdateLayersName[] = "SendBeginMainFrameToCommit.UpdateLayers";
const uint64_t Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_UpdateLayersNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSendBeginMainFrameToCommit_UpdateLayers(int64_t value)
{
    SetMetricInternal(kSendBeginMainFrameToCommit_UpdateLayersNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameName[] = "SubmitCompositorFrameToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.BufferAvailableToBufferReady";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReady(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.BufferReadyToLatch";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatch(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.LatchToSwapEnd";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEnd(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.ReceivedCompositorFrameToStartDraw";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDraw(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.StartDrawToSwapStart";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStart(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SubmitToReceiveCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrame(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SwapEndToPresentationCompositorFrame";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrame(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SwapStartToBufferAvailable";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailable(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName[]
    = "SubmitCompositorFrameToPresentationCompositorFrame.SwapStartToSwapEnd";
const uint64_t Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEnd(int64_t value)
{
    SetMetricInternal(kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kTotalLatencyName[] = "TotalLatency";
const uint64_t Graphics_Smoothness_Latency::kTotalLatencyNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetTotalLatency(int64_t value)
{
    SetMetricInternal(kTotalLatencyNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kTouchScrollName[] = "TouchScroll";
const uint64_t Graphics_Smoothness_Latency::kTouchScrollNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetTouchScroll(int64_t value)
{
    SetMetricInternal(kTouchScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kUnknownName[] = "Unknown";
const uint64_t Graphics_Smoothness_Latency::kUnknownNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetUnknown(int64_t value)
{
    SetMetricInternal(kUnknownNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kVideoName[] = "Video";
const uint64_t Graphics_Smoothness_Latency::kVideoNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetVideo(int64_t value)
{
    SetMetricInternal(kVideoNameHash, value);
    return *this;
}

const char Graphics_Smoothness_Latency::kWheelScrollName[] = "WheelScroll";
const uint64_t Graphics_Smoothness_Latency::kWheelScrollNameHash;

Graphics_Smoothness_Latency& Graphics_Smoothness_Latency::SetWheelScroll(int64_t value)
{
    SetMetricInternal(kWheelScrollNameHash, value);
    return *this;
}
const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kEntryName[] = "Graphics.Smoothness.NormalizedPercentDroppedFrames";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kEntryNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames::Graphics_Smoothness_NormalizedPercentDroppedFrames(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_NormalizedPercentDroppedFrames::Graphics_Smoothness_NormalizedPercentDroppedFrames(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_NormalizedPercentDroppedFrames::~Graphics_Smoothness_NormalizedPercentDroppedFrames() = default;
const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kAboveThresholdName[] = "AboveThreshold";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kAboveThresholdNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetAboveThreshold(int64_t value)
{
    SetMetricInternal(kAboveThresholdNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kAverageName[] = "Average";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kAverageNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetAverage(int64_t value)
{
    SetMetricInternal(kAverageNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedMedianName[] = "CompositorFocusedMedian";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedMedianNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetCompositorFocusedMedian(int64_t value)
{
    SetMetricInternal(kCompositorFocusedMedianNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedPercentile95Name[] = "CompositorFocusedPercentile95";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedPercentile95NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetCompositorFocusedPercentile95(int64_t value)
{
    SetMetricInternal(kCompositorFocusedPercentile95NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedVarianceName[] = "CompositorFocusedVariance";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedVarianceNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetCompositorFocusedVariance(int64_t value)
{
    SetMetricInternal(kCompositorFocusedVarianceNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedMedianName[] = "MainFocusedMedian";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedMedianNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetMainFocusedMedian(int64_t value)
{
    SetMetricInternal(kMainFocusedMedianNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedPercentile95Name[] = "MainFocusedPercentile95";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedPercentile95NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetMainFocusedPercentile95(int64_t value)
{
    SetMetricInternal(kMainFocusedPercentile95NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedVarianceName[] = "MainFocusedVariance";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedVarianceNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetMainFocusedVariance(int64_t value)
{
    SetMetricInternal(kMainFocusedVarianceNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kMedianName[] = "Median";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kMedianNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetMedian(int64_t value)
{
    SetMetricInternal(kMedianNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kPercentile95Name[] = "Percentile95";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kPercentile95NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetPercentile95(int64_t value)
{
    SetMetricInternal(kPercentile95NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedMedianName[] = "ScrollFocusedMedian";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedMedianNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetScrollFocusedMedian(int64_t value)
{
    SetMetricInternal(kScrollFocusedMedianNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedPercentile95Name[] = "ScrollFocusedPercentile95";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedPercentile95NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetScrollFocusedPercentile95(int64_t value)
{
    SetMetricInternal(kScrollFocusedPercentile95NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedVarianceName[] = "ScrollFocusedVariance";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedVarianceNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetScrollFocusedVariance(int64_t value)
{
    SetMetricInternal(kScrollFocusedVarianceNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessBadName[] = "SmoothnessBad";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessBadNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessBad(int64_t value)
{
    SetMetricInternal(kSmoothnessBadNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessGoodName[] = "SmoothnessGood";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessGoodNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessGood(int64_t value)
{
    SetMetricInternal(kSmoothnessGoodNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessOkayName[] = "SmoothnessOkay";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessOkayNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessOkay(int64_t value)
{
    SetMetricInternal(kSmoothnessOkayNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad25to50Name[] = "SmoothnessVeryBad25to50";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad25to50NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessVeryBad25to50(int64_t value)
{
    SetMetricInternal(kSmoothnessVeryBad25to50NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad50to75Name[] = "SmoothnessVeryBad50to75";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad50to75NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessVeryBad50to75(int64_t value)
{
    SetMetricInternal(kSmoothnessVeryBad50to75NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad75to100Name[] = "SmoothnessVeryBad75to100";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad75to100NameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessVeryBad75to100(int64_t value)
{
    SetMetricInternal(kSmoothnessVeryBad75to100NameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryGoodName[] = "SmoothnessVeryGood";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryGoodNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetSmoothnessVeryGood(int64_t value)
{
    SetMetricInternal(kSmoothnessVeryGoodNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kVarianceName[] = "Variance";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kVarianceNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetVariance(int64_t value)
{
    SetMetricInternal(kVarianceNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseName[] = "WorstCase";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetWorstCase(int64_t value)
{
    SetMetricInternal(kWorstCaseNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter1SecName[] = "WorstCaseAfter1Sec";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter1SecNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetWorstCaseAfter1Sec(int64_t value)
{
    SetMetricInternal(kWorstCaseAfter1SecNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter2SecName[] = "WorstCaseAfter2Sec";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter2SecNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetWorstCaseAfter2Sec(int64_t value)
{
    SetMetricInternal(kWorstCaseAfter2SecNameHash, value);
    return *this;
}

const char Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter5SecName[] = "WorstCaseAfter5Sec";
const uint64_t Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter5SecNameHash;

Graphics_Smoothness_NormalizedPercentDroppedFrames& Graphics_Smoothness_NormalizedPercentDroppedFrames::SetWorstCaseAfter5Sec(int64_t value)
{
    SetMetricInternal(kWorstCaseAfter5SecNameHash, value);
    return *this;
}
const char Graphics_Smoothness_PercentDroppedFrames::kEntryName[] = "Graphics.Smoothness.PercentDroppedFrames";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kEntryNameHash;

Graphics_Smoothness_PercentDroppedFrames::Graphics_Smoothness_PercentDroppedFrames(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_PercentDroppedFrames::Graphics_Smoothness_PercentDroppedFrames(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Graphics_Smoothness_PercentDroppedFrames::~Graphics_Smoothness_PercentDroppedFrames() = default;
const char Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsName[] = "AllAnimations";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetAllAnimations(int64_t value)
{
    SetMetricInternal(kAllAnimationsNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsName[] = "AllInteractions";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetAllInteractions(int64_t value)
{
    SetMetricInternal(kAllInteractionsNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kAllSequencesName[] = "AllSequences";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kAllSequencesNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetAllSequences(int64_t value)
{
    SetMetricInternal(kAllSequencesNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationName[] = "CompositorThread.CompositorAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_CompositorAnimation(int64_t value)
{
    SetMetricInternal(kCompositorThread_CompositorAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationName[] = "CompositorThread.MainThreadAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_MainThreadAnimation(int64_t value)
{
    SetMetricInternal(kCompositorThread_MainThreadAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomName[] = "CompositorThread.PinchZoom";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_PinchZoom(int64_t value)
{
    SetMetricInternal(kCompositorThread_PinchZoomNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFName[] = "CompositorThread.RAF";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_RAF(int64_t value)
{
    SetMetricInternal(kCompositorThread_RAFNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_ScrollbarScrollName[] = "CompositorThread.ScrollbarScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_ScrollbarScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_ScrollbarScroll(int64_t value)
{
    SetMetricInternal(kCompositorThread_ScrollbarScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollName[] = "CompositorThread.TouchScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_TouchScroll(int64_t value)
{
    SetMetricInternal(kCompositorThread_TouchScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoName[] = "CompositorThread.Video";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_Video(int64_t value)
{
    SetMetricInternal(kCompositorThread_VideoNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollName[] = "CompositorThread.WheelScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetCompositorThread_WheelScroll(int64_t value)
{
    SetMetricInternal(kCompositorThread_WheelScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_CanvasAnimationName[] = "MainThread.CanvasAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_CanvasAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_CanvasAnimation(int64_t value)
{
    SetMetricInternal(kMainThread_CanvasAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationName[] = "MainThread.CompositorAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_CompositorAnimation(int64_t value)
{
    SetMetricInternal(kMainThread_CompositorAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_JSAnimationName[] = "MainThread.JSAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_JSAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_JSAnimation(int64_t value)
{
    SetMetricInternal(kMainThread_JSAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationName[] = "MainThread.MainThreadAnimation";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_MainThreadAnimation(int64_t value)
{
    SetMetricInternal(kMainThread_MainThreadAnimationNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomName[] = "MainThread.PinchZoom";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_PinchZoom(int64_t value)
{
    SetMetricInternal(kMainThread_PinchZoomNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFName[] = "MainThread.RAF";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_RAF(int64_t value)
{
    SetMetricInternal(kMainThread_RAFNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_ScrollbarScrollName[] = "MainThread.ScrollbarScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_ScrollbarScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_ScrollbarScroll(int64_t value)
{
    SetMetricInternal(kMainThread_ScrollbarScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollName[] = "MainThread.TouchScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_TouchScroll(int64_t value)
{
    SetMetricInternal(kMainThread_TouchScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoName[] = "MainThread.Video";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_Video(int64_t value)
{
    SetMetricInternal(kMainThread_VideoNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollName[] = "MainThread.WheelScroll";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetMainThread_WheelScroll(int64_t value)
{
    SetMetricInternal(kMainThread_WheelScrollNameHash, value);
    return *this;
}

const char Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomName[] = "SlowerThread.PinchZoom";
const uint64_t Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomNameHash;

Graphics_Smoothness_PercentDroppedFrames& Graphics_Smoothness_PercentDroppedFrames::SetSlowerThread_PinchZoom(int64_t value)
{
    SetMetricInternal(kSlowerThread_PinchZoomNameHash, value);
    return *this;
}
const char HistoryClusters::kEntryName[] = "HistoryClusters";
const uint64_t HistoryClusters::kEntryNameHash;

HistoryClusters::HistoryClusters(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

HistoryClusters::HistoryClusters(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

HistoryClusters::~HistoryClusters() = default;
const char HistoryClusters::kFinalStateName[] = "FinalState";
const uint64_t HistoryClusters::kFinalStateNameHash;

HistoryClusters& HistoryClusters::SetFinalState(int64_t value)
{
    SetMetricInternal(kFinalStateNameHash, value);
    return *this;
}

const char HistoryClusters::kInitialStateName[] = "InitialState";
const uint64_t HistoryClusters::kInitialStateNameHash;

HistoryClusters& HistoryClusters::SetInitialState(int64_t value)
{
    SetMetricInternal(kInitialStateNameHash, value);
    return *this;
}

const char HistoryClusters::kNumQueriesName[] = "NumQueries";
const uint64_t HistoryClusters::kNumQueriesNameHash;

HistoryClusters& HistoryClusters::SetNumQueries(int64_t value)
{
    SetMetricInternal(kNumQueriesNameHash, value);
    return *this;
}

const char HistoryClusters::kNumTogglesToBasicHistoryName[] = "NumTogglesToBasicHistory";
const uint64_t HistoryClusters::kNumTogglesToBasicHistoryNameHash;

HistoryClusters& HistoryClusters::SetNumTogglesToBasicHistory(int64_t value)
{
    SetMetricInternal(kNumTogglesToBasicHistoryNameHash, value);
    return *this;
}
const char HistoryManipulationIntervention::kEntryName[] = "HistoryManipulationIntervention";
const uint64_t HistoryManipulationIntervention::kEntryNameHash;

HistoryManipulationIntervention::HistoryManipulationIntervention(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

HistoryManipulationIntervention::HistoryManipulationIntervention(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

HistoryManipulationIntervention::~HistoryManipulationIntervention() = default;

const char HistoryNavigation::kEntryName[] = "HistoryNavigation";
const uint64_t HistoryNavigation::kEntryNameHash;

HistoryNavigation::HistoryNavigation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

HistoryNavigation::HistoryNavigation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

HistoryNavigation::~HistoryNavigation() = default;
const char HistoryNavigation::kAverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2Name[]
    = "AverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore.MaxEventDuration2";
const uint64_t HistoryNavigation::kAverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2NameHash;

HistoryNavigation& HistoryNavigation::SetAverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kAverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2NameHash, value);
    return *this;
}

const char HistoryNavigation::kBackForwardCache_BlocklistedFeaturesName[] = "BackForwardCache.BlocklistedFeatures";
const uint64_t HistoryNavigation::kBackForwardCache_BlocklistedFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_BlocklistedFeatures(int64_t value)
{
    SetMetricInternal(kBackForwardCache_BlocklistedFeaturesNameHash, value);
    return *this;
}

const char HistoryNavigation::kBackForwardCache_BrowsingInstanceNotSwappedReasonName[] = "BackForwardCache.BrowsingInstanceNotSwappedReason";
const uint64_t HistoryNavigation::kBackForwardCache_BrowsingInstanceNotSwappedReasonNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_BrowsingInstanceNotSwappedReason(int64_t value)
{
    SetMetricInternal(kBackForwardCache_BrowsingInstanceNotSwappedReasonNameHash, value);
    return *this;
}

const char HistoryNavigation::kBackForwardCache_DisabledForRenderFrameHostReasonCountName[] = "BackForwardCache.DisabledForRenderFrameHostReasonCount";
const uint64_t HistoryNavigation::kBackForwardCache_DisabledForRenderFrameHostReasonCountNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_DisabledForRenderFrameHostReasonCount(int64_t value)
{
    SetMetricInternal(kBackForwardCache_DisabledForRenderFrameHostReasonCountNameHash, value);
    return *this;
}

const char HistoryNavigation::kBackForwardCache_IsAmpPageName[] = "BackForwardCache.IsAmpPage";
const uint64_t HistoryNavigation::kBackForwardCache_IsAmpPageNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_IsAmpPage(int64_t value)
{
    SetMetricInternal(kBackForwardCache_IsAmpPageNameHash, value);
    return *this;
}

const char HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheName[] = "BackForwardCache.IsServedFromBackForwardCache";
const uint64_t HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_IsServedFromBackForwardCache(int64_t value)
{
    SetMetricInternal(kBackForwardCache_IsServedFromBackForwardCacheNameHash, value);
    return *this;
}

const char HistoryNavigation::kBackForwardCache_NotRestoredReasonsName[] = "BackForwardCache.NotRestoredReasons";
const uint64_t HistoryNavigation::kBackForwardCache_NotRestoredReasonsNameHash;

HistoryNavigation& HistoryNavigation::SetBackForwardCache_NotRestoredReasons(int64_t value)
{
    SetMetricInternal(kBackForwardCache_NotRestoredReasonsNameHash, value);
    return *this;
}

const char HistoryNavigation::kCrossOriginSubframesFeaturesName[] = "CrossOriginSubframesFeatures";
const uint64_t HistoryNavigation::kCrossOriginSubframesFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetCrossOriginSubframesFeatures(int64_t value)
{
    SetMetricInternal(kCrossOriginSubframesFeaturesNameHash, value);
    return *this;
}

const char HistoryNavigation::kCumulativeShiftScoreAfterBackForwardCacheRestoreName[] = "CumulativeShiftScoreAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kCumulativeShiftScoreAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetCumulativeShiftScoreAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kCumulativeShiftScoreAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kFirstInputDelayAfterBackForwardCacheRestoreName[] = "FirstInputDelayAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kFirstInputDelayAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetFirstInputDelayAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kFirstInputDelayAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kFirstRequestAnimationFrameAfterBackForwardCacheRestoreName[] = "FirstRequestAnimationFrameAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kFirstRequestAnimationFrameAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetFirstRequestAnimationFrameAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kFirstRequestAnimationFrameAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kForegroundDurationAfterBackForwardCacheRestoreName[] = "ForegroundDurationAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kForegroundDurationAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetForegroundDurationAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kForegroundDurationAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName[] = "LastCommittedCrossDocumentNavigationSourceIdForTheSameDocument";
const uint64_t HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetLastCommittedCrossDocumentNavigationSourceIdForTheSameDocument(int64_t value)
{
    SetMetricInternal(kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash, value);
    return *this;
}

const char HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentName[] = "LastCommittedSourceIdForTheSameDocument";
const uint64_t HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetLastCommittedSourceIdForTheSameDocument(int64_t value)
{
    SetMetricInternal(kLastCommittedSourceIdForTheSameDocumentNameHash, value);
    return *this;
}

const char HistoryNavigation::kMainFrameFeaturesName[] = "MainFrameFeatures";
const uint64_t HistoryNavigation::kMainFrameFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetMainFrameFeatures(int64_t value)
{
    SetMetricInternal(kMainFrameFeaturesNameHash, value);
    return *this;
}

const char HistoryNavigation::kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msName[]
    = "MaxCumulativeShiftScoreAfterBackForwardCacheRestore.SessionWindow.Gap1000ms.Max5000ms";
const uint64_t HistoryNavigation::kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msNameHash;

HistoryNavigation& HistoryNavigation::SetMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000ms(int64_t value)
{
    SetMetricInternal(kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msNameHash, value);
    return *this;
}

const char HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentName[] = "NavigatedToTheMostRecentEntryForDocument";
const uint64_t HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetNavigatedToTheMostRecentEntryForDocument(int64_t value)
{
    SetMetricInternal(kNavigatedToTheMostRecentEntryForDocumentNameHash, value);
    return *this;
}

const char HistoryNavigation::kNavigationToFirstPaintAfterBackForwardCacheRestoreName[] = "NavigationToFirstPaintAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kNavigationToFirstPaintAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetNavigationToFirstPaintAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kNavigationToFirstPaintAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kNumInteractionsAfterBackForwardCacheRestoreName[] = "NumInteractionsAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kNumInteractionsAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetNumInteractionsAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kNumInteractionsAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kPageEndReasonAfterBackForwardCacheRestoreName[] = "PageEndReasonAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kPageEndReasonAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetPageEndReasonAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kPageEndReasonAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kSameOriginSubframesFeaturesName[] = "SameOriginSubframesFeatures";
const uint64_t HistoryNavigation::kSameOriginSubframesFeaturesNameHash;

HistoryNavigation& HistoryNavigation::SetSameOriginSubframesFeatures(int64_t value)
{
    SetMetricInternal(kSameOriginSubframesFeaturesNameHash, value);
    return *this;
}

const char HistoryNavigation::kSecondRequestAnimationFrameAfterBackForwardCacheRestoreName[] = "SecondRequestAnimationFrameAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kSecondRequestAnimationFrameAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetSecondRequestAnimationFrameAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kSecondRequestAnimationFrameAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kSlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration2Name[]
    = "SlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore.HighPercentile2.MaxEventDuration2";
const uint64_t HistoryNavigation::kSlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration2NameHash;

HistoryNavigation& HistoryNavigation::SetSlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kSlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration2NameHash, value);
    return *this;
}

const char HistoryNavigation::kSumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2Name[]
    = "SumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore.MaxEventDuration2";
const uint64_t HistoryNavigation::kSumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2NameHash;

HistoryNavigation& HistoryNavigation::SetSumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kSumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2NameHash, value);
    return *this;
}

const char HistoryNavigation::kThirdRequestAnimationFrameAfterBackForwardCacheRestoreName[] = "ThirdRequestAnimationFrameAfterBackForwardCacheRestore";
const uint64_t HistoryNavigation::kThirdRequestAnimationFrameAfterBackForwardCacheRestoreNameHash;

HistoryNavigation& HistoryNavigation::SetThirdRequestAnimationFrameAfterBackForwardCacheRestore(int64_t value)
{
    SetMetricInternal(kThirdRequestAnimationFrameAfterBackForwardCacheRestoreNameHash, value);
    return *this;
}

const char HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentName[] = "TimeSinceNavigatedAwayFromDocument";
const uint64_t HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentNameHash;

HistoryNavigation& HistoryNavigation::SetTimeSinceNavigatedAwayFromDocument(int64_t value)
{
    SetMetricInternal(kTimeSinceNavigatedAwayFromDocumentNameHash, value);
    return *this;
}

const char HistoryNavigation::kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationName[]
    = "UserInteractionLatencyAfterBackForwardCacheRestore.HighPercentile2.MaxEventDuration";
const uint64_t HistoryNavigation::kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationNameHash;

HistoryNavigation& HistoryNavigation::SetUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationNameHash, value);
    return *this;
}

const char HistoryNavigation::kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2Name[]
    = "WorstUserInteractionLatencyAfterBackForwardCacheRestore.MaxEventDuration2";
const uint64_t HistoryNavigation::kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2NameHash;

HistoryNavigation& HistoryNavigation::SetWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2(int64_t value)
{
    SetMetricInternal(kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2NameHash, value);
    return *this;
}
const char Identifiability::kEntryName[] = "Identifiability";
const uint64_t Identifiability::kEntryNameHash;

Identifiability::Identifiability(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Identifiability::Identifiability(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Identifiability::~Identifiability() = default;
const char Identifiability::kGeneratorVersion_926Name[] = "GeneratorVersion.926";
const uint64_t Identifiability::kGeneratorVersion_926NameHash;

Identifiability& Identifiability::SetGeneratorVersion_926(int64_t value)
{
    SetMetricInternal(kGeneratorVersion_926NameHash, value);
    return *this;
}

const char Identifiability::kStudyGeneration_626Name[] = "StudyGeneration.626";
const uint64_t Identifiability::kStudyGeneration_626NameHash;

Identifiability& Identifiability::SetStudyGeneration_626(int64_t value)
{
    SetMetricInternal(kStudyGeneration_626NameHash, value);
    return *this;
}
const char InputEvent::kEntryName[] = "InputEvent";
const uint64_t InputEvent::kEntryNameHash;

InputEvent::InputEvent(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputEvent::InputEvent(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputEvent::~InputEvent() = default;
const char InputEvent::kEventTypeName[] = "EventType";
const uint64_t InputEvent::kEventTypeNameHash;

InputEvent& InputEvent::SetEventType(int64_t value)
{
    SetMetricInternal(kEventTypeNameHash, value);
    return *this;
}

const char InputEvent::kInteractiveTiming_InputDelayName[] = "InteractiveTiming.InputDelay";
const uint64_t InputEvent::kInteractiveTiming_InputDelayNameHash;

InputEvent& InputEvent::SetInteractiveTiming_InputDelay(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_InputDelayNameHash, value);
    return *this;
}

const char InputEvent::kInteractiveTiming_ProcessingFinishedToNextPaintName[] = "InteractiveTiming.ProcessingFinishedToNextPaint";
const uint64_t InputEvent::kInteractiveTiming_ProcessingFinishedToNextPaintNameHash;

InputEvent& InputEvent::SetInteractiveTiming_ProcessingFinishedToNextPaint(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_ProcessingFinishedToNextPaintNameHash, value);
    return *this;
}

const char InputEvent::kInteractiveTiming_ProcessingTimeName[] = "InteractiveTiming.ProcessingTime";
const uint64_t InputEvent::kInteractiveTiming_ProcessingTimeNameHash;

InputEvent& InputEvent::SetInteractiveTiming_ProcessingTime(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_ProcessingTimeNameHash, value);
    return *this;
}
const char InputMethod_Assistive_Match::kEntryName[] = "InputMethod.Assistive.Match";
const uint64_t InputMethod_Assistive_Match::kEntryNameHash;

InputMethod_Assistive_Match::InputMethod_Assistive_Match(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputMethod_Assistive_Match::InputMethod_Assistive_Match(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputMethod_Assistive_Match::~InputMethod_Assistive_Match() = default;
const char InputMethod_Assistive_Match::kTypeName[] = "Type";
const uint64_t InputMethod_Assistive_Match::kTypeNameHash;

InputMethod_Assistive_Match& InputMethod_Assistive_Match::SetType(int64_t value)
{
    SetMetricInternal(kTypeNameHash, value);
    return *this;
}
const char InputMethod_NonCompliantApi::kEntryName[] = "InputMethod.NonCompliantApi";
const uint64_t InputMethod_NonCompliantApi::kEntryNameHash;

InputMethod_NonCompliantApi::InputMethod_NonCompliantApi(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputMethod_NonCompliantApi::InputMethod_NonCompliantApi(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InputMethod_NonCompliantApi::~InputMethod_NonCompliantApi() = default;
const char InputMethod_NonCompliantApi::kNonCompliantOperationName[] = "NonCompliantOperation";
const uint64_t InputMethod_NonCompliantApi::kNonCompliantOperationNameHash;

InputMethod_NonCompliantApi& InputMethod_NonCompliantApi::SetNonCompliantOperation(int64_t value)
{
    SetMetricInternal(kNonCompliantOperationNameHash, value);
    return *this;
}
const char InstalledRelatedApps::kEntryName[] = "InstalledRelatedApps";
const uint64_t InstalledRelatedApps::kEntryNameHash;

InstalledRelatedApps::InstalledRelatedApps(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InstalledRelatedApps::InstalledRelatedApps(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

InstalledRelatedApps::~InstalledRelatedApps() = default;
const char InstalledRelatedApps::kCalledName[] = "Called";
const uint64_t InstalledRelatedApps::kCalledNameHash;

InstalledRelatedApps& InstalledRelatedApps::SetCalled(int64_t value)
{
    SetMetricInternal(kCalledNameHash, value);
    return *this;
}
const char IOS_FindInPageSearchMatches::kEntryName[] = "IOS.FindInPageSearchMatches";
const uint64_t IOS_FindInPageSearchMatches::kEntryNameHash;

IOS_FindInPageSearchMatches::IOS_FindInPageSearchMatches(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_FindInPageSearchMatches::IOS_FindInPageSearchMatches(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_FindInPageSearchMatches::~IOS_FindInPageSearchMatches() = default;
const char IOS_FindInPageSearchMatches::kHasMatchesName[] = "HasMatches";
const uint64_t IOS_FindInPageSearchMatches::kHasMatchesNameHash;

IOS_FindInPageSearchMatches& IOS_FindInPageSearchMatches::SetHasMatches(int64_t value)
{
    SetMetricInternal(kHasMatchesNameHash, value);
    return *this;
}
const char IOS_IsDefaultBrowser::kEntryName[] = "IOS.IsDefaultBrowser";
const uint64_t IOS_IsDefaultBrowser::kEntryNameHash;

IOS_IsDefaultBrowser::IOS_IsDefaultBrowser(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_IsDefaultBrowser::IOS_IsDefaultBrowser(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_IsDefaultBrowser::~IOS_IsDefaultBrowser() = default;
const char IOS_IsDefaultBrowser::kIsDefaultBrowserName[] = "IsDefaultBrowser";
const uint64_t IOS_IsDefaultBrowser::kIsDefaultBrowserNameHash;

IOS_IsDefaultBrowser& IOS_IsDefaultBrowser::SetIsDefaultBrowser(int64_t value)
{
    SetMetricInternal(kIsDefaultBrowserNameHash, value);
    return *this;
}
const char IOS_PageAddedToReadingList::kEntryName[] = "IOS.PageAddedToReadingList";
const uint64_t IOS_PageAddedToReadingList::kEntryNameHash;

IOS_PageAddedToReadingList::IOS_PageAddedToReadingList(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_PageAddedToReadingList::IOS_PageAddedToReadingList(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_PageAddedToReadingList::~IOS_PageAddedToReadingList() = default;
const char IOS_PageAddedToReadingList::kAddedFromMessagesName[] = "AddedFromMessages";
const uint64_t IOS_PageAddedToReadingList::kAddedFromMessagesNameHash;

IOS_PageAddedToReadingList& IOS_PageAddedToReadingList::SetAddedFromMessages(int64_t value)
{
    SetMetricInternal(kAddedFromMessagesNameHash, value);
    return *this;
}
const char IOS_PageReadability::kEntryName[] = "IOS.PageReadability";
const uint64_t IOS_PageReadability::kEntryNameHash;

IOS_PageReadability::IOS_PageReadability(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_PageReadability::IOS_PageReadability(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_PageReadability::~IOS_PageReadability() = default;
const char IOS_PageReadability::kDidAcceptName[] = "DidAccept";
const uint64_t IOS_PageReadability::kDidAcceptNameHash;

IOS_PageReadability& IOS_PageReadability::SetDidAccept(int64_t value)
{
    SetMetricInternal(kDidAcceptNameHash, value);
    return *this;
}

const char IOS_PageReadability::kDistilibilityLongScoreName[] = "DistilibilityLongScore";
const uint64_t IOS_PageReadability::kDistilibilityLongScoreNameHash;

IOS_PageReadability& IOS_PageReadability::SetDistilibilityLongScore(int64_t value)
{
    SetMetricInternal(kDistilibilityLongScoreNameHash, value);
    return *this;
}

const char IOS_PageReadability::kDistilibilityScoreName[] = "DistilibilityScore";
const uint64_t IOS_PageReadability::kDistilibilityScoreNameHash;

IOS_PageReadability& IOS_PageReadability::SetDistilibilityScore(int64_t value)
{
    SetMetricInternal(kDistilibilityScoreNameHash, value);
    return *this;
}
const char IOS_PageZoomChanged::kEntryName[] = "IOS.PageZoomChanged";
const uint64_t IOS_PageZoomChanged::kEntryNameHash;

IOS_PageZoomChanged::IOS_PageZoomChanged(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_PageZoomChanged::IOS_PageZoomChanged(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_PageZoomChanged::~IOS_PageZoomChanged() = default;
const char IOS_PageZoomChanged::kContentSizeCategoryName[] = "ContentSizeCategory";
const uint64_t IOS_PageZoomChanged::kContentSizeCategoryNameHash;

IOS_PageZoomChanged& IOS_PageZoomChanged::SetContentSizeCategory(int64_t value)
{
    SetMetricInternal(kContentSizeCategoryNameHash, value);
    return *this;
}

const char IOS_PageZoomChanged::kOverallZoomLevelName[] = "OverallZoomLevel";
const uint64_t IOS_PageZoomChanged::kOverallZoomLevelNameHash;

IOS_PageZoomChanged& IOS_PageZoomChanged::SetOverallZoomLevel(int64_t value)
{
    SetMetricInternal(kOverallZoomLevelNameHash, value);
    return *this;
}

const char IOS_PageZoomChanged::kUserZoomLevelName[] = "UserZoomLevel";
const uint64_t IOS_PageZoomChanged::kUserZoomLevelNameHash;

IOS_PageZoomChanged& IOS_PageZoomChanged::SetUserZoomLevel(int64_t value)
{
    SetMetricInternal(kUserZoomLevelNameHash, value);
    return *this;
}
const char IOS_RendererGone::kEntryName[] = "IOS.RendererGone";
const uint64_t IOS_RendererGone::kEntryNameHash;

IOS_RendererGone::IOS_RendererGone(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_RendererGone::IOS_RendererGone(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_RendererGone::~IOS_RendererGone() = default;
const char IOS_RendererGone::kAliveRecentlyRendererCountName[] = "AliveRecentlyRendererCount";
const uint64_t IOS_RendererGone::kAliveRecentlyRendererCountNameHash;

IOS_RendererGone& IOS_RendererGone::SetAliveRecentlyRendererCount(int64_t value)
{
    SetMetricInternal(kAliveRecentlyRendererCountNameHash, value);
    return *this;
}

const char IOS_RendererGone::kAliveRendererCountName[] = "AliveRendererCount";
const uint64_t IOS_RendererGone::kAliveRendererCountNameHash;

IOS_RendererGone& IOS_RendererGone::SetAliveRendererCount(int64_t value)
{
    SetMetricInternal(kAliveRendererCountNameHash, value);
    return *this;
}

const char IOS_RendererGone::kInForegroundName[] = "InForeground";
const uint64_t IOS_RendererGone::kInForegroundNameHash;

IOS_RendererGone& IOS_RendererGone::SetInForeground(int64_t value)
{
    SetMetricInternal(kInForegroundNameHash, value);
    return *this;
}

const char IOS_RendererGone::kSawMemoryWarningName[] = "SawMemoryWarning";
const uint64_t IOS_RendererGone::kSawMemoryWarningNameHash;

IOS_RendererGone& IOS_RendererGone::SetSawMemoryWarning(int64_t value)
{
    SetMetricInternal(kSawMemoryWarningNameHash, value);
    return *this;
}
const char IOS_URLMismatchInLegacyAndSlimNavigationManager::kEntryName[] = "IOS.URLMismatchInLegacyAndSlimNavigationManager";
const uint64_t IOS_URLMismatchInLegacyAndSlimNavigationManager::kEntryNameHash;

IOS_URLMismatchInLegacyAndSlimNavigationManager::IOS_URLMismatchInLegacyAndSlimNavigationManager(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_URLMismatchInLegacyAndSlimNavigationManager::IOS_URLMismatchInLegacyAndSlimNavigationManager(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

IOS_URLMismatchInLegacyAndSlimNavigationManager::~IOS_URLMismatchInLegacyAndSlimNavigationManager() = default;
const char IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchName[] = "HasMismatch";
const uint64_t IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchNameHash;

IOS_URLMismatchInLegacyAndSlimNavigationManager& IOS_URLMismatchInLegacyAndSlimNavigationManager::SetHasMismatch(int64_t value)
{
    SetMetricInternal(kHasMismatchNameHash, value);
    return *this;
}
const char JavascriptFrameworkPageLoad::kEntryName[] = "JavascriptFrameworkPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kEntryNameHash;

JavascriptFrameworkPageLoad::JavascriptFrameworkPageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

JavascriptFrameworkPageLoad::JavascriptFrameworkPageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

JavascriptFrameworkPageLoad::~JavascriptFrameworkPageLoad() = default;
const char JavascriptFrameworkPageLoad::kAngularPageLoadName[] = "AngularPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kAngularPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetAngularPageLoad(int64_t value)
{
    SetMetricInternal(kAngularPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kGatsbyPageLoadName[] = "GatsbyPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kGatsbyPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetGatsbyPageLoad(int64_t value)
{
    SetMetricInternal(kGatsbyPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kNextJSPageLoadName[] = "NextJSPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kNextJSPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetNextJSPageLoad(int64_t value)
{
    SetMetricInternal(kNextJSPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kNuxtJSPageLoadName[] = "NuxtJSPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kNuxtJSPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetNuxtJSPageLoad(int64_t value)
{
    SetMetricInternal(kNuxtJSPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kPreactPageLoadName[] = "PreactPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kPreactPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetPreactPageLoad(int64_t value)
{
    SetMetricInternal(kPreactPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kReactPageLoadName[] = "ReactPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kReactPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetReactPageLoad(int64_t value)
{
    SetMetricInternal(kReactPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kSapperPageLoadName[] = "SapperPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kSapperPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetSapperPageLoad(int64_t value)
{
    SetMetricInternal(kSapperPageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kSveltePageLoadName[] = "SveltePageLoad";
const uint64_t JavascriptFrameworkPageLoad::kSveltePageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetSveltePageLoad(int64_t value)
{
    SetMetricInternal(kSveltePageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kVuePageLoadName[] = "VuePageLoad";
const uint64_t JavascriptFrameworkPageLoad::kVuePageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetVuePageLoad(int64_t value)
{
    SetMetricInternal(kVuePageLoadNameHash, value);
    return *this;
}

const char JavascriptFrameworkPageLoad::kVuePressPageLoadName[] = "VuePressPageLoad";
const uint64_t JavascriptFrameworkPageLoad::kVuePressPageLoadNameHash;

JavascriptFrameworkPageLoad& JavascriptFrameworkPageLoad::SetVuePressPageLoad(int64_t value)
{
    SetMetricInternal(kVuePressPageLoadNameHash, value);
    return *this;
}
const char LoadCountsPerTopLevelDocument::kEntryName[] = "LoadCountsPerTopLevelDocument";
const uint64_t LoadCountsPerTopLevelDocument::kEntryNameHash;

LoadCountsPerTopLevelDocument::LoadCountsPerTopLevelDocument(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LoadCountsPerTopLevelDocument::LoadCountsPerTopLevelDocument(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LoadCountsPerTopLevelDocument::~LoadCountsPerTopLevelDocument() = default;
const char LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_HiddenName[] = "NumMainFrameSameDocumentLoads_Hidden";
const uint64_t LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_HiddenNameHash;

LoadCountsPerTopLevelDocument& LoadCountsPerTopLevelDocument::SetNumMainFrameSameDocumentLoads_Hidden(int64_t value)
{
    SetMetricInternal(kNumMainFrameSameDocumentLoads_HiddenNameHash, value);
    return *this;
}

const char LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_VisibleName[] = "NumMainFrameSameDocumentLoads_Visible";
const uint64_t LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_VisibleNameHash;

LoadCountsPerTopLevelDocument& LoadCountsPerTopLevelDocument::SetNumMainFrameSameDocumentLoads_Visible(int64_t value)
{
    SetMetricInternal(kNumMainFrameSameDocumentLoads_VisibleNameHash, value);
    return *this;
}

const char LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_HiddenName[] = "NumSubFrameDifferentDocumentLoads_Hidden";
const uint64_t LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_HiddenNameHash;

LoadCountsPerTopLevelDocument& LoadCountsPerTopLevelDocument::SetNumSubFrameDifferentDocumentLoads_Hidden(int64_t value)
{
    SetMetricInternal(kNumSubFrameDifferentDocumentLoads_HiddenNameHash, value);
    return *this;
}

const char LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_VisibleName[] = "NumSubFrameDifferentDocumentLoads_Visible";
const uint64_t LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_VisibleNameHash;

LoadCountsPerTopLevelDocument& LoadCountsPerTopLevelDocument::SetNumSubFrameDifferentDocumentLoads_Visible(int64_t value)
{
    SetMetricInternal(kNumSubFrameDifferentDocumentLoads_VisibleNameHash, value);
    return *this;
}

const char LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_HiddenName[] = "NumSubFrameSameDocumentLoads_Hidden";
const uint64_t LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_HiddenNameHash;

LoadCountsPerTopLevelDocument& LoadCountsPerTopLevelDocument::SetNumSubFrameSameDocumentLoads_Hidden(int64_t value)
{
    SetMetricInternal(kNumSubFrameSameDocumentLoads_HiddenNameHash, value);
    return *this;
}

const char LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_VisibleName[] = "NumSubFrameSameDocumentLoads_Visible";
const uint64_t LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_VisibleNameHash;

LoadCountsPerTopLevelDocument& LoadCountsPerTopLevelDocument::SetNumSubFrameSameDocumentLoads_Visible(int64_t value)
{
    SetMetricInternal(kNumSubFrameSameDocumentLoads_VisibleNameHash, value);
    return *this;
}
const char LoadingPredictor::kEntryName[] = "LoadingPredictor";
const uint64_t LoadingPredictor::kEntryNameHash;

LoadingPredictor::LoadingPredictor(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LoadingPredictor::LoadingPredictor(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LoadingPredictor::~LoadingPredictor() = default;
const char LoadingPredictor::kCorrectSubresourceOriginPreconnectsInitiatedName[] = "CorrectSubresourceOriginPreconnectsInitiated";
const uint64_t LoadingPredictor::kCorrectSubresourceOriginPreconnectsInitiatedNameHash;

LoadingPredictor& LoadingPredictor::SetCorrectSubresourceOriginPreconnectsInitiated(int64_t value)
{
    SetMetricInternal(kCorrectSubresourceOriginPreconnectsInitiatedNameHash, value);
    return *this;
}

const char LoadingPredictor::kCorrectSubresourcePrefetchesInitiatedName[] = "CorrectSubresourcePrefetchesInitiated";
const uint64_t LoadingPredictor::kCorrectSubresourcePrefetchesInitiatedNameHash;

LoadingPredictor& LoadingPredictor::SetCorrectSubresourcePrefetchesInitiated(int64_t value)
{
    SetMetricInternal(kCorrectSubresourcePrefetchesInitiatedNameHash, value);
    return *this;
}

const char LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsName[] = "LocalPredictionCorrectlyPredictedOrigins";
const uint64_t LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetLocalPredictionCorrectlyPredictedOrigins(int64_t value)
{
    SetMetricInternal(kLocalPredictionCorrectlyPredictedOriginsNameHash, value);
    return *this;
}

const char LoadingPredictor::kLocalPredictionOriginsName[] = "LocalPredictionOrigins";
const uint64_t LoadingPredictor::kLocalPredictionOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetLocalPredictionOrigins(int64_t value)
{
    SetMetricInternal(kLocalPredictionOriginsNameHash, value);
    return *this;
}

const char LoadingPredictor::kNavigationStartToFirstSubresourcePrefetchInitiatedName[] = "NavigationStartToFirstSubresourcePrefetchInitiated";
const uint64_t LoadingPredictor::kNavigationStartToFirstSubresourcePrefetchInitiatedNameHash;

LoadingPredictor& LoadingPredictor::SetNavigationStartToFirstSubresourcePrefetchInitiated(int64_t value)
{
    SetMetricInternal(kNavigationStartToFirstSubresourcePrefetchInitiatedNameHash, value);
    return *this;
}

const char LoadingPredictor::kNavigationStartToNavigationCommitName[] = "NavigationStartToNavigationCommit";
const uint64_t LoadingPredictor::kNavigationStartToNavigationCommitNameHash;

LoadingPredictor& LoadingPredictor::SetNavigationStartToNavigationCommit(int64_t value)
{
    SetMetricInternal(kNavigationStartToNavigationCommitNameHash, value);
    return *this;
}

const char LoadingPredictor::kNavigationStartToOptimizationGuidePredictionArrivedName[] = "NavigationStartToOptimizationGuidePredictionArrived";
const uint64_t LoadingPredictor::kNavigationStartToOptimizationGuidePredictionArrivedNameHash;

LoadingPredictor& LoadingPredictor::SetNavigationStartToOptimizationGuidePredictionArrived(int64_t value)
{
    SetMetricInternal(kNavigationStartToOptimizationGuidePredictionArrivedNameHash, value);
    return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsName[] = "OptimizationGuidePredictionCorrectlyPredictedOrigins";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionCorrectlyPredictedOrigins(int64_t value)
{
    SetMetricInternal(kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash, value);
    return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName[] = "OptimizationGuidePredictionCorrectlyPredictedSubresources";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionCorrectlyPredictedSubresources(int64_t value)
{
    SetMetricInternal(kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash, value);
    return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionDecisionName[] = "OptimizationGuidePredictionDecision";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionDecisionNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionDecision(int64_t value)
{
    SetMetricInternal(kOptimizationGuidePredictionDecisionNameHash, value);
    return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionOriginsName[] = "OptimizationGuidePredictionOrigins";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionOriginsNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionOrigins(int64_t value)
{
    SetMetricInternal(kOptimizationGuidePredictionOriginsNameHash, value);
    return *this;
}

const char LoadingPredictor::kOptimizationGuidePredictionSubresourcesName[] = "OptimizationGuidePredictionSubresources";
const uint64_t LoadingPredictor::kOptimizationGuidePredictionSubresourcesNameHash;

LoadingPredictor& LoadingPredictor::SetOptimizationGuidePredictionSubresources(int64_t value)
{
    SetMetricInternal(kOptimizationGuidePredictionSubresourcesNameHash, value);
    return *this;
}

const char LoadingPredictor::kSubresourceOriginPreconnectsInitiatedName[] = "SubresourceOriginPreconnectsInitiated";
const uint64_t LoadingPredictor::kSubresourceOriginPreconnectsInitiatedNameHash;

LoadingPredictor& LoadingPredictor::SetSubresourceOriginPreconnectsInitiated(int64_t value)
{
    SetMetricInternal(kSubresourceOriginPreconnectsInitiatedNameHash, value);
    return *this;
}

const char LoadingPredictor::kSubresourcePrefetchesInitiatedName[] = "SubresourcePrefetchesInitiated";
const uint64_t LoadingPredictor::kSubresourcePrefetchesInitiatedNameHash;

LoadingPredictor& LoadingPredictor::SetSubresourcePrefetchesInitiated(int64_t value)
{
    SetMetricInternal(kSubresourcePrefetchesInitiatedNameHash, value);
    return *this;
}
const char LocalNetworkRequests::kEntryName[] = "LocalNetworkRequests";
const uint64_t LocalNetworkRequests::kEntryNameHash;

LocalNetworkRequests::LocalNetworkRequests(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LocalNetworkRequests::LocalNetworkRequests(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LocalNetworkRequests::~LocalNetworkRequests() = default;
const char LocalNetworkRequests::kCount_FailedName[] = "Count.Failed";
const uint64_t LocalNetworkRequests::kCount_FailedNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetCount_Failed(int64_t value)
{
    SetMetricInternal(kCount_FailedNameHash, value);
    return *this;
}

const char LocalNetworkRequests::kCount_SuccessfulName[] = "Count.Successful";
const uint64_t LocalNetworkRequests::kCount_SuccessfulNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetCount_Successful(int64_t value)
{
    SetMetricInternal(kCount_SuccessfulNameHash, value);
    return *this;
}

const char LocalNetworkRequests::kPortTypeName[] = "PortType";
const uint64_t LocalNetworkRequests::kPortTypeNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetPortType(int64_t value)
{
    SetMetricInternal(kPortTypeNameHash, value);
    return *this;
}

const char LocalNetworkRequests::kResourceTypeName[] = "ResourceType";
const uint64_t LocalNetworkRequests::kResourceTypeNameHash;

LocalNetworkRequests& LocalNetworkRequests::SetResourceType(int64_t value)
{
    SetMetricInternal(kResourceTypeNameHash, value);
    return *this;
}
const char LoginDetection::kEntryName[] = "LoginDetection";
const uint64_t LoginDetection::kEntryNameHash;

LoginDetection::LoginDetection(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LoginDetection::LoginDetection(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LoginDetection::~LoginDetection() = default;
const char LoginDetection::kPage_LoginTypeName[] = "Page.LoginType";
const uint64_t LoginDetection::kPage_LoginTypeNameHash;

LoginDetection& LoginDetection::SetPage_LoginType(int64_t value)
{
    SetMetricInternal(kPage_LoginTypeNameHash, value);
    return *this;
}
const char LookalikeUrl_NavigationSuggestion::kEntryName[] = "LookalikeUrl.NavigationSuggestion";
const uint64_t LookalikeUrl_NavigationSuggestion::kEntryNameHash;

LookalikeUrl_NavigationSuggestion::LookalikeUrl_NavigationSuggestion(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LookalikeUrl_NavigationSuggestion::LookalikeUrl_NavigationSuggestion(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

LookalikeUrl_NavigationSuggestion::~LookalikeUrl_NavigationSuggestion() = default;
const char LookalikeUrl_NavigationSuggestion::kMatchTypeName[] = "MatchType";
const uint64_t LookalikeUrl_NavigationSuggestion::kMatchTypeNameHash;

LookalikeUrl_NavigationSuggestion& LookalikeUrl_NavigationSuggestion::SetMatchType(int64_t value)
{
    SetMetricInternal(kMatchTypeNameHash, value);
    return *this;
}

const char LookalikeUrl_NavigationSuggestion::kTriggeredByInitialUrlName[] = "TriggeredByInitialUrl";
const uint64_t LookalikeUrl_NavigationSuggestion::kTriggeredByInitialUrlNameHash;

LookalikeUrl_NavigationSuggestion& LookalikeUrl_NavigationSuggestion::SetTriggeredByInitialUrl(int64_t value)
{
    SetMetricInternal(kTriggeredByInitialUrlNameHash, value);
    return *this;
}

const char LookalikeUrl_NavigationSuggestion::kUserActionName[] = "UserAction";
const uint64_t LookalikeUrl_NavigationSuggestion::kUserActionNameHash;

LookalikeUrl_NavigationSuggestion& LookalikeUrl_NavigationSuggestion::SetUserAction(int64_t value)
{
    SetMetricInternal(kUserActionNameHash, value);
    return *this;
}
const char MainFrameNavigation::kEntryName[] = "MainFrameNavigation";
const uint64_t MainFrameNavigation::kEntryNameHash;

MainFrameNavigation::MainFrameNavigation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MainFrameNavigation::MainFrameNavigation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MainFrameNavigation::~MainFrameNavigation() = default;
const char MainFrameNavigation::kDidCommitName[] = "DidCommit";
const uint64_t MainFrameNavigation::kDidCommitNameHash;

MainFrameNavigation& MainFrameNavigation::SetDidCommit(int64_t value)
{
    SetMetricInternal(kDidCommitNameHash, value);
    return *this;
}
const char Media_Autoplay_Attempt::kEntryName[] = "Media.Autoplay.Attempt";
const uint64_t Media_Autoplay_Attempt::kEntryNameHash;

Media_Autoplay_Attempt::Media_Autoplay_Attempt(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Attempt::Media_Autoplay_Attempt(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Attempt::~Media_Autoplay_Attempt() = default;
const char Media_Autoplay_Attempt::kAudioTrackName[] = "AudioTrack";
const uint64_t Media_Autoplay_Attempt::kAudioTrackNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetAudioTrack(int64_t value)
{
    SetMetricInternal(kAudioTrackNameHash, value);
    return *this;
}

const char Media_Autoplay_Attempt::kHighMediaEngagementName[] = "HighMediaEngagement";
const uint64_t Media_Autoplay_Attempt::kHighMediaEngagementNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetHighMediaEngagement(int64_t value)
{
    SetMetricInternal(kHighMediaEngagementNameHash, value);
    return *this;
}

const char Media_Autoplay_Attempt::kMutedName[] = "Muted";
const uint64_t Media_Autoplay_Attempt::kMutedNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetMuted(int64_t value)
{
    SetMetricInternal(kMutedNameHash, value);
    return *this;
}

const char Media_Autoplay_Attempt::kSourceName[] = "Source";
const uint64_t Media_Autoplay_Attempt::kSourceNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetSource(int64_t value)
{
    SetMetricInternal(kSourceNameHash, value);
    return *this;
}

const char Media_Autoplay_Attempt::kUserGestureRequiredName[] = "UserGestureRequired";
const uint64_t Media_Autoplay_Attempt::kUserGestureRequiredNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetUserGestureRequired(int64_t value)
{
    SetMetricInternal(kUserGestureRequiredNameHash, value);
    return *this;
}

const char Media_Autoplay_Attempt::kUserGestureStatusName[] = "UserGestureStatus";
const uint64_t Media_Autoplay_Attempt::kUserGestureStatusNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetUserGestureStatus(int64_t value)
{
    SetMetricInternal(kUserGestureStatusNameHash, value);
    return *this;
}

const char Media_Autoplay_Attempt::kVideoTrackName[] = "VideoTrack";
const uint64_t Media_Autoplay_Attempt::kVideoTrackNameHash;

Media_Autoplay_Attempt& Media_Autoplay_Attempt::SetVideoTrack(int64_t value)
{
    SetMetricInternal(kVideoTrackNameHash, value);
    return *this;
}
const char Media_Autoplay_AudioContext::kEntryName[] = "Media.Autoplay.AudioContext";
const uint64_t Media_Autoplay_AudioContext::kEntryNameHash;

Media_Autoplay_AudioContext::Media_Autoplay_AudioContext(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_AudioContext::Media_Autoplay_AudioContext(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_AudioContext::~Media_Autoplay_AudioContext() = default;
const char Media_Autoplay_AudioContext::kSourceNodeStartedName[] = "SourceNodeStarted";
const uint64_t Media_Autoplay_AudioContext::kSourceNodeStartedNameHash;

Media_Autoplay_AudioContext& Media_Autoplay_AudioContext::SetSourceNodeStarted(int64_t value)
{
    SetMetricInternal(kSourceNodeStartedNameHash, value);
    return *this;
}

const char Media_Autoplay_AudioContext::kStatusName[] = "Status";
const uint64_t Media_Autoplay_AudioContext::kStatusNameHash;

Media_Autoplay_AudioContext& Media_Autoplay_AudioContext::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}

const char Media_Autoplay_AudioContext::kUnlockTypeName[] = "UnlockType";
const uint64_t Media_Autoplay_AudioContext::kUnlockTypeNameHash;

Media_Autoplay_AudioContext& Media_Autoplay_AudioContext::SetUnlockType(int64_t value)
{
    SetMetricInternal(kUnlockTypeNameHash, value);
    return *this;
}
const char Media_Autoplay_Muted_UnmuteAction::kEntryName[] = "Media.Autoplay.Muted.UnmuteAction";
const uint64_t Media_Autoplay_Muted_UnmuteAction::kEntryNameHash;

Media_Autoplay_Muted_UnmuteAction::Media_Autoplay_Muted_UnmuteAction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Muted_UnmuteAction::Media_Autoplay_Muted_UnmuteAction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Autoplay_Muted_UnmuteAction::~Media_Autoplay_Muted_UnmuteAction() = default;
const char Media_Autoplay_Muted_UnmuteAction::kResultName[] = "Result";
const uint64_t Media_Autoplay_Muted_UnmuteAction::kResultNameHash;

Media_Autoplay_Muted_UnmuteAction& Media_Autoplay_Muted_UnmuteAction::SetResult(int64_t value)
{
    SetMetricInternal(kResultNameHash, value);
    return *this;
}

const char Media_Autoplay_Muted_UnmuteAction::kSourceName[] = "Source";
const uint64_t Media_Autoplay_Muted_UnmuteAction::kSourceNameHash;

Media_Autoplay_Muted_UnmuteAction& Media_Autoplay_Muted_UnmuteAction::SetSource(int64_t value)
{
    SetMetricInternal(kSourceNameHash, value);
    return *this;
}
const char Media_BasicPlayback::kEntryName[] = "Media.BasicPlayback";
const uint64_t Media_BasicPlayback::kEntryNameHash;

Media_BasicPlayback::Media_BasicPlayback(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_BasicPlayback::Media_BasicPlayback(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_BasicPlayback::~Media_BasicPlayback() = default;
const char Media_BasicPlayback::kAudioCodecName[] = "AudioCodec";
const uint64_t Media_BasicPlayback::kAudioCodecNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioCodec(int64_t value)
{
    SetMetricInternal(kAudioCodecNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kAudioCodecProfileName[] = "AudioCodecProfile";
const uint64_t Media_BasicPlayback::kAudioCodecProfileNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioCodecProfile(int64_t value)
{
    SetMetricInternal(kAudioCodecProfileNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kAudioDecoderNameName[] = "AudioDecoderName";
const uint64_t Media_BasicPlayback::kAudioDecoderNameNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioDecoderName(int64_t value)
{
    SetMetricInternal(kAudioDecoderNameNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kAudioEncryptionSchemeName[] = "AudioEncryptionScheme";
const uint64_t Media_BasicPlayback::kAudioEncryptionSchemeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAudioEncryptionScheme(int64_t value)
{
    SetMetricInternal(kAudioEncryptionSchemeNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kAutoplayInitiatedName[] = "AutoplayInitiated";
const uint64_t Media_BasicPlayback::kAutoplayInitiatedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetAutoplayInitiated(int64_t value)
{
    SetMetricInternal(kAutoplayInitiatedNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kCompletedRebuffersCountName[] = "CompletedRebuffersCount";
const uint64_t Media_BasicPlayback::kCompletedRebuffersCountNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetCompletedRebuffersCount(int64_t value)
{
    SetMetricInternal(kCompletedRebuffersCountNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kCompletedRebuffersDurationName[] = "CompletedRebuffersDuration";
const uint64_t Media_BasicPlayback::kCompletedRebuffersDurationNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetCompletedRebuffersDuration(int64_t value)
{
    SetMetricInternal(kCompletedRebuffersDurationNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kDurationName[] = "Duration";
const uint64_t Media_BasicPlayback::kDurationNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kHasAudioName[] = "HasAudio";
const uint64_t Media_BasicPlayback::kHasAudioNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetHasAudio(int64_t value)
{
    SetMetricInternal(kHasAudioNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kHasVideoName[] = "HasVideo";
const uint64_t Media_BasicPlayback::kHasVideoNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetHasVideo(int64_t value)
{
    SetMetricInternal(kHasVideoNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kIsBackgroundName[] = "IsBackground";
const uint64_t Media_BasicPlayback::kIsBackgroundNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsBackground(int64_t value)
{
    SetMetricInternal(kIsBackgroundNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kIsEMEName[] = "IsEME";
const uint64_t Media_BasicPlayback::kIsEMENameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsEME(int64_t value)
{
    SetMetricInternal(kIsEMENameHash, value);
    return *this;
}

const char Media_BasicPlayback::kIsMSEName[] = "IsMSE";
const uint64_t Media_BasicPlayback::kIsMSENameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsMSE(int64_t value)
{
    SetMetricInternal(kIsMSENameHash, value);
    return *this;
}

const char Media_BasicPlayback::kIsMutedName[] = "IsMuted";
const uint64_t Media_BasicPlayback::kIsMutedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsMuted(int64_t value)
{
    SetMetricInternal(kIsMutedNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_BasicPlayback::kIsTopFrameNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetIsTopFrame(int64_t value)
{
    SetMetricInternal(kIsTopFrameNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kLastPipelineStatusName[] = "LastPipelineStatus";
const uint64_t Media_BasicPlayback::kLastPipelineStatusNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetLastPipelineStatus(int64_t value)
{
    SetMetricInternal(kLastPipelineStatusNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kMeanTimeBetweenRebuffersName[] = "MeanTimeBetweenRebuffers";
const uint64_t Media_BasicPlayback::kMeanTimeBetweenRebuffersNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetMeanTimeBetweenRebuffers(int64_t value)
{
    SetMetricInternal(kMeanTimeBetweenRebuffersNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kMediaStreamTypeName[] = "MediaStreamType";
const uint64_t Media_BasicPlayback::kMediaStreamTypeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetMediaStreamType(int64_t value)
{
    SetMetricInternal(kMediaStreamTypeNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kPlayerIDName[] = "PlayerID";
const uint64_t Media_BasicPlayback::kPlayerIDNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetPlayerID(int64_t value)
{
    SetMetricInternal(kPlayerIDNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kRebuffersCountName[] = "RebuffersCount";
const uint64_t Media_BasicPlayback::kRebuffersCountNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetRebuffersCount(int64_t value)
{
    SetMetricInternal(kRebuffersCountNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoCodecName[] = "VideoCodec";
const uint64_t Media_BasicPlayback::kVideoCodecNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoCodec(int64_t value)
{
    SetMetricInternal(kVideoCodecNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoCodecProfileName[] = "VideoCodecProfile";
const uint64_t Media_BasicPlayback::kVideoCodecProfileNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoCodecProfile(int64_t value)
{
    SetMetricInternal(kVideoCodecProfileNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoDecoderNameName[] = "VideoDecoderName";
const uint64_t Media_BasicPlayback::kVideoDecoderNameNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoDecoderName(int64_t value)
{
    SetMetricInternal(kVideoDecoderNameNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoEncryptionSchemeName[] = "VideoEncryptionScheme";
const uint64_t Media_BasicPlayback::kVideoEncryptionSchemeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoEncryptionScheme(int64_t value)
{
    SetMetricInternal(kVideoEncryptionSchemeNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoFramesDecodedName[] = "VideoFramesDecoded";
const uint64_t Media_BasicPlayback::kVideoFramesDecodedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoFramesDecoded(int64_t value)
{
    SetMetricInternal(kVideoFramesDecodedNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoFramesDroppedName[] = "VideoFramesDropped";
const uint64_t Media_BasicPlayback::kVideoFramesDroppedNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoFramesDropped(int64_t value)
{
    SetMetricInternal(kVideoFramesDroppedNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoNaturalHeightName[] = "VideoNaturalHeight";
const uint64_t Media_BasicPlayback::kVideoNaturalHeightNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoNaturalHeight(int64_t value)
{
    SetMetricInternal(kVideoNaturalHeightNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kVideoNaturalWidthName[] = "VideoNaturalWidth";
const uint64_t Media_BasicPlayback::kVideoNaturalWidthNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetVideoNaturalWidth(int64_t value)
{
    SetMetricInternal(kVideoNaturalWidthNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTimeName[] = "WatchTime";
const uint64_t Media_BasicPlayback::kWatchTimeNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime(int64_t value)
{
    SetMetricInternal(kWatchTimeNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_ACName[] = "WatchTime.AC";
const uint64_t Media_BasicPlayback::kWatchTime_ACNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_AC(int64_t value)
{
    SetMetricInternal(kWatchTime_ACNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_BatteryName[] = "WatchTime.Battery";
const uint64_t Media_BasicPlayback::kWatchTime_BatteryNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_Battery(int64_t value)
{
    SetMetricInternal(kWatchTime_BatteryNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_DisplayFullscreenName[] = "WatchTime.DisplayFullscreen";
const uint64_t Media_BasicPlayback::kWatchTime_DisplayFullscreenNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_DisplayFullscreen(int64_t value)
{
    SetMetricInternal(kWatchTime_DisplayFullscreenNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_DisplayInlineName[] = "WatchTime.DisplayInline";
const uint64_t Media_BasicPlayback::kWatchTime_DisplayInlineNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_DisplayInline(int64_t value)
{
    SetMetricInternal(kWatchTime_DisplayInlineNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_DisplayPictureInPictureName[] = "WatchTime.DisplayPictureInPicture";
const uint64_t Media_BasicPlayback::kWatchTime_DisplayPictureInPictureNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_DisplayPictureInPicture(int64_t value)
{
    SetMetricInternal(kWatchTime_DisplayPictureInPictureNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_NativeControlsOffName[] = "WatchTime.NativeControlsOff";
const uint64_t Media_BasicPlayback::kWatchTime_NativeControlsOffNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_NativeControlsOff(int64_t value)
{
    SetMetricInternal(kWatchTime_NativeControlsOffNameHash, value);
    return *this;
}

const char Media_BasicPlayback::kWatchTime_NativeControlsOnName[] = "WatchTime.NativeControlsOn";
const uint64_t Media_BasicPlayback::kWatchTime_NativeControlsOnNameHash;

Media_BasicPlayback& Media_BasicPlayback::SetWatchTime_NativeControlsOn(int64_t value)
{
    SetMetricInternal(kWatchTime_NativeControlsOnNameHash, value);
    return *this;
}
const char Media_EME_ApiPromiseRejection::kEntryName[] = "Media.EME.ApiPromiseRejection";
const uint64_t Media_EME_ApiPromiseRejection::kEntryNameHash;

Media_EME_ApiPromiseRejection::Media_EME_ApiPromiseRejection(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_ApiPromiseRejection::Media_EME_ApiPromiseRejection(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_ApiPromiseRejection::~Media_EME_ApiPromiseRejection() = default;
const char Media_EME_ApiPromiseRejection::kApiName[] = "Api";
const uint64_t Media_EME_ApiPromiseRejection::kApiNameHash;

Media_EME_ApiPromiseRejection& Media_EME_ApiPromiseRejection::SetApi(int64_t value)
{
    SetMetricInternal(kApiNameHash, value);
    return *this;
}

const char Media_EME_ApiPromiseRejection::kKeySystemName[] = "KeySystem";
const uint64_t Media_EME_ApiPromiseRejection::kKeySystemNameHash;

Media_EME_ApiPromiseRejection& Media_EME_ApiPromiseRejection::SetKeySystem(int64_t value)
{
    SetMetricInternal(kKeySystemNameHash, value);
    return *this;
}

const char Media_EME_ApiPromiseRejection::kSystemCodeName[] = "SystemCode";
const uint64_t Media_EME_ApiPromiseRejection::kSystemCodeNameHash;

Media_EME_ApiPromiseRejection& Media_EME_ApiPromiseRejection::SetSystemCode(int64_t value)
{
    SetMetricInternal(kSystemCodeNameHash, value);
    return *this;
}

const char Media_EME_ApiPromiseRejection::kUseHardwareSecureCodecsName[] = "UseHardwareSecureCodecs";
const uint64_t Media_EME_ApiPromiseRejection::kUseHardwareSecureCodecsNameHash;

Media_EME_ApiPromiseRejection& Media_EME_ApiPromiseRejection::SetUseHardwareSecureCodecs(int64_t value)
{
    SetMetricInternal(kUseHardwareSecureCodecsNameHash, value);
    return *this;
}
const char Media_EME_CreateMediaKeys::kEntryName[] = "Media.EME.CreateMediaKeys";
const uint64_t Media_EME_CreateMediaKeys::kEntryNameHash;

Media_EME_CreateMediaKeys::Media_EME_CreateMediaKeys(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_CreateMediaKeys::Media_EME_CreateMediaKeys(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_CreateMediaKeys::~Media_EME_CreateMediaKeys() = default;
const char Media_EME_CreateMediaKeys::kIsAdFrameName[] = "IsAdFrame";
const uint64_t Media_EME_CreateMediaKeys::kIsAdFrameNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetIsAdFrame(int64_t value)
{
    SetMetricInternal(kIsAdFrameNameHash, value);
    return *this;
}

const char Media_EME_CreateMediaKeys::kIsCrossOriginName[] = "IsCrossOrigin";
const uint64_t Media_EME_CreateMediaKeys::kIsCrossOriginNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetIsCrossOrigin(int64_t value)
{
    SetMetricInternal(kIsCrossOriginNameHash, value);
    return *this;
}

const char Media_EME_CreateMediaKeys::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_EME_CreateMediaKeys::kIsTopFrameNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetIsTopFrame(int64_t value)
{
    SetMetricInternal(kIsTopFrameNameHash, value);
    return *this;
}

const char Media_EME_CreateMediaKeys::kKeySystemName[] = "KeySystem";
const uint64_t Media_EME_CreateMediaKeys::kKeySystemNameHash;

Media_EME_CreateMediaKeys& Media_EME_CreateMediaKeys::SetKeySystem(int64_t value)
{
    SetMetricInternal(kKeySystemNameHash, value);
    return *this;
}
const char Media_EME_GetStatusForPolicy::kEntryName[] = "Media.EME.GetStatusForPolicy";
const uint64_t Media_EME_GetStatusForPolicy::kEntryNameHash;

Media_EME_GetStatusForPolicy::Media_EME_GetStatusForPolicy(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_GetStatusForPolicy::Media_EME_GetStatusForPolicy(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_GetStatusForPolicy::~Media_EME_GetStatusForPolicy() = default;
const char Media_EME_GetStatusForPolicy::kIsAdFrameName[] = "IsAdFrame";
const uint64_t Media_EME_GetStatusForPolicy::kIsAdFrameNameHash;

Media_EME_GetStatusForPolicy& Media_EME_GetStatusForPolicy::SetIsAdFrame(int64_t value)
{
    SetMetricInternal(kIsAdFrameNameHash, value);
    return *this;
}

const char Media_EME_GetStatusForPolicy::kKeySystemName[] = "KeySystem";
const uint64_t Media_EME_GetStatusForPolicy::kKeySystemNameHash;

Media_EME_GetStatusForPolicy& Media_EME_GetStatusForPolicy::SetKeySystem(int64_t value)
{
    SetMetricInternal(kKeySystemNameHash, value);
    return *this;
}

const char Media_EME_GetStatusForPolicy::kMinHdcpVersionName[] = "MinHdcpVersion";
const uint64_t Media_EME_GetStatusForPolicy::kMinHdcpVersionNameHash;

Media_EME_GetStatusForPolicy& Media_EME_GetStatusForPolicy::SetMinHdcpVersion(int64_t value)
{
    SetMetricInternal(kMinHdcpVersionNameHash, value);
    return *this;
}

const char Media_EME_GetStatusForPolicy::kUseHardwareSecureCodecsName[] = "UseHardwareSecureCodecs";
const uint64_t Media_EME_GetStatusForPolicy::kUseHardwareSecureCodecsNameHash;

Media_EME_GetStatusForPolicy& Media_EME_GetStatusForPolicy::SetUseHardwareSecureCodecs(int64_t value)
{
    SetMetricInternal(kUseHardwareSecureCodecsNameHash, value);
    return *this;
}
const char Media_EME_RequestMediaKeySystemAccess::kEntryName[] = "Media.EME.RequestMediaKeySystemAccess";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kEntryNameHash;

Media_EME_RequestMediaKeySystemAccess::Media_EME_RequestMediaKeySystemAccess(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_RequestMediaKeySystemAccess::Media_EME_RequestMediaKeySystemAccess(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_EME_RequestMediaKeySystemAccess::~Media_EME_RequestMediaKeySystemAccess() = default;
const char Media_EME_RequestMediaKeySystemAccess::kIsAdFrameName[] = "IsAdFrame";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kIsAdFrameNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetIsAdFrame(int64_t value)
{
    SetMetricInternal(kIsAdFrameNameHash, value);
    return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginName[] = "IsCrossOrigin";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetIsCrossOrigin(int64_t value)
{
    SetMetricInternal(kIsCrossOriginNameHash, value);
    return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kIsTopFrameNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetIsTopFrame(int64_t value)
{
    SetMetricInternal(kIsTopFrameNameHash, value);
    return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kKeySystemName[] = "KeySystem";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kKeySystemNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetKeySystem(int64_t value)
{
    SetMetricInternal(kKeySystemNameHash, value);
    return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesName[] = "VideoCapabilities";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetVideoCapabilities(int64_t value)
{
    SetMetricInternal(kVideoCapabilitiesNameHash, value);
    return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessName[] = "VideoCapabilities.HasEmptyRobustness";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetVideoCapabilities_HasEmptyRobustness(int64_t value)
{
    SetMetricInternal(kVideoCapabilities_HasEmptyRobustnessNameHash, value);
    return *this;
}

const char Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessName[] = "VideoCapabilities.HasHwSecureAllRobustness";
const uint64_t Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessNameHash;

Media_EME_RequestMediaKeySystemAccess& Media_EME_RequestMediaKeySystemAccess::SetVideoCapabilities_HasHwSecureAllRobustness(int64_t value)
{
    SetMetricInternal(kVideoCapabilities_HasHwSecureAllRobustnessNameHash, value);
    return *this;
}
const char Media_Engagement_SessionFinished::kEntryName[] = "Media.Engagement.SessionFinished";
const uint64_t Media_Engagement_SessionFinished::kEntryNameHash;

Media_Engagement_SessionFinished::Media_Engagement_SessionFinished(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Engagement_SessionFinished::Media_Engagement_SessionFinished(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Engagement_SessionFinished::~Media_Engagement_SessionFinished() = default;
const char Media_Engagement_SessionFinished::kEngagement_IsHighName[] = "Engagement.IsHigh";
const uint64_t Media_Engagement_SessionFinished::kEngagement_IsHighNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetEngagement_IsHigh(int64_t value)
{
    SetMetricInternal(kEngagement_IsHighNameHash, value);
    return *this;
}

const char Media_Engagement_SessionFinished::kEngagement_ScoreName[] = "Engagement.Score";
const uint64_t Media_Engagement_SessionFinished::kEngagement_ScoreNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetEngagement_Score(int64_t value)
{
    SetMetricInternal(kEngagement_ScoreNameHash, value);
    return *this;
}

const char Media_Engagement_SessionFinished::kPlaybacks_TotalName[] = "Playbacks.Total";
const uint64_t Media_Engagement_SessionFinished::kPlaybacks_TotalNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetPlaybacks_Total(int64_t value)
{
    SetMetricInternal(kPlaybacks_TotalNameHash, value);
    return *this;
}

const char Media_Engagement_SessionFinished::kPlayer_Audible_DeltaName[] = "Player.Audible.Delta";
const uint64_t Media_Engagement_SessionFinished::kPlayer_Audible_DeltaNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetPlayer_Audible_Delta(int64_t value)
{
    SetMetricInternal(kPlayer_Audible_DeltaNameHash, value);
    return *this;
}

const char Media_Engagement_SessionFinished::kPlayer_Significant_DeltaName[] = "Player.Significant.Delta";
const uint64_t Media_Engagement_SessionFinished::kPlayer_Significant_DeltaNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetPlayer_Significant_Delta(int64_t value)
{
    SetMetricInternal(kPlayer_Significant_DeltaNameHash, value);
    return *this;
}

const char Media_Engagement_SessionFinished::kVisits_TotalName[] = "Visits.Total";
const uint64_t Media_Engagement_SessionFinished::kVisits_TotalNameHash;

Media_Engagement_SessionFinished& Media_Engagement_SessionFinished::SetVisits_Total(int64_t value)
{
    SetMetricInternal(kVisits_TotalNameHash, value);
    return *this;
}
const char Media_Engagement_ShortPlaybackIgnored::kEntryName[] = "Media.Engagement.ShortPlaybackIgnored";
const uint64_t Media_Engagement_ShortPlaybackIgnored::kEntryNameHash;

Media_Engagement_ShortPlaybackIgnored::Media_Engagement_ShortPlaybackIgnored(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Engagement_ShortPlaybackIgnored::Media_Engagement_ShortPlaybackIgnored(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Engagement_ShortPlaybackIgnored::~Media_Engagement_ShortPlaybackIgnored() = default;
const char Media_Engagement_ShortPlaybackIgnored::kLengthName[] = "Length";
const uint64_t Media_Engagement_ShortPlaybackIgnored::kLengthNameHash;

Media_Engagement_ShortPlaybackIgnored& Media_Engagement_ShortPlaybackIgnored::SetLength(int64_t value)
{
    SetMetricInternal(kLengthNameHash, value);
    return *this;
}
const char Media_Feed_Discover::kEntryName[] = "Media.Feed.Discover";
const uint64_t Media_Feed_Discover::kEntryNameHash;

Media_Feed_Discover::Media_Feed_Discover(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Feed_Discover::Media_Feed_Discover(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Feed_Discover::~Media_Feed_Discover() = default;
const char Media_Feed_Discover::kHasMediaFeedName[] = "HasMediaFeed";
const uint64_t Media_Feed_Discover::kHasMediaFeedNameHash;

Media_Feed_Discover& Media_Feed_Discover::SetHasMediaFeed(int64_t value)
{
    SetMetricInternal(kHasMediaFeedNameHash, value);
    return *this;
}
const char Media_GlobalMediaControls_ActionButtonPressed::kEntryName[] = "Media.GlobalMediaControls.ActionButtonPressed";
const uint64_t Media_GlobalMediaControls_ActionButtonPressed::kEntryNameHash;

Media_GlobalMediaControls_ActionButtonPressed::Media_GlobalMediaControls_ActionButtonPressed(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_GlobalMediaControls_ActionButtonPressed::Media_GlobalMediaControls_ActionButtonPressed(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_GlobalMediaControls_ActionButtonPressed::~Media_GlobalMediaControls_ActionButtonPressed() = default;
const char Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionName[] = "MediaSessionAction";
const uint64_t Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionNameHash;

Media_GlobalMediaControls_ActionButtonPressed& Media_GlobalMediaControls_ActionButtonPressed::SetMediaSessionAction(int64_t value)
{
    SetMetricInternal(kMediaSessionActionNameHash, value);
    return *this;
}
const char Media_Learning_PredictionRecord::kEntryName[] = "Media.Learning.PredictionRecord";
const uint64_t Media_Learning_PredictionRecord::kEntryNameHash;

Media_Learning_PredictionRecord::Media_Learning_PredictionRecord(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Learning_PredictionRecord::Media_Learning_PredictionRecord(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_Learning_PredictionRecord::~Media_Learning_PredictionRecord() = default;
const char Media_Learning_PredictionRecord::kLearningTaskName[] = "LearningTask";
const uint64_t Media_Learning_PredictionRecord::kLearningTaskNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetLearningTask(int64_t value)
{
    SetMetricInternal(kLearningTaskNameHash, value);
    return *this;
}

const char Media_Learning_PredictionRecord::kObservedValueName[] = "ObservedValue";
const uint64_t Media_Learning_PredictionRecord::kObservedValueNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetObservedValue(int64_t value)
{
    SetMetricInternal(kObservedValueNameHash, value);
    return *this;
}

const char Media_Learning_PredictionRecord::kPredictedValueName[] = "PredictedValue";
const uint64_t Media_Learning_PredictionRecord::kPredictedValueNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetPredictedValue(int64_t value)
{
    SetMetricInternal(kPredictedValueNameHash, value);
    return *this;
}

const char Media_Learning_PredictionRecord::kTrainingDataSizeName[] = "TrainingDataSize";
const uint64_t Media_Learning_PredictionRecord::kTrainingDataSizeNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetTrainingDataSize(int64_t value)
{
    SetMetricInternal(kTrainingDataSizeNameHash, value);
    return *this;
}

const char Media_Learning_PredictionRecord::kTrainingDataTotalWeightName[] = "TrainingDataTotalWeight";
const uint64_t Media_Learning_PredictionRecord::kTrainingDataTotalWeightNameHash;

Media_Learning_PredictionRecord& Media_Learning_PredictionRecord::SetTrainingDataTotalWeight(int64_t value)
{
    SetMetricInternal(kTrainingDataTotalWeightNameHash, value);
    return *this;
}
const char Media_SiteMuted::kEntryName[] = "Media.SiteMuted";
const uint64_t Media_SiteMuted::kEntryNameHash;

Media_SiteMuted::Media_SiteMuted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_SiteMuted::Media_SiteMuted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_SiteMuted::~Media_SiteMuted() = default;
const char Media_SiteMuted::kMuteReasonName[] = "MuteReason";
const uint64_t Media_SiteMuted::kMuteReasonNameHash;

Media_SiteMuted& Media_SiteMuted::SetMuteReason(int64_t value)
{
    SetMetricInternal(kMuteReasonNameHash, value);
    return *this;
}
const char Media_VideoDecodePerfRecord::kEntryName[] = "Media.VideoDecodePerfRecord";
const uint64_t Media_VideoDecodePerfRecord::kEntryNameHash;

Media_VideoDecodePerfRecord::Media_VideoDecodePerfRecord(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_VideoDecodePerfRecord::Media_VideoDecodePerfRecord(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_VideoDecodePerfRecord::~Media_VideoDecodePerfRecord() = default;
const char Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientName[] = "Perf.ApiWouldClaimIsPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_ApiWouldClaimIsPowerEfficient(int64_t value)
{
    SetMetricInternal(kPerf_ApiWouldClaimIsPowerEfficientNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothName[] = "Perf.ApiWouldClaimIsSmooth";
const uint64_t Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_ApiWouldClaimIsSmooth(int64_t value)
{
    SetMetricInternal(kPerf_ApiWouldClaimIsSmoothNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedName[] = "Perf.PastVideoFramesDecoded";
const uint64_t Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_PastVideoFramesDecoded(int64_t value)
{
    SetMetricInternal(kPerf_PastVideoFramesDecodedNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedName[] = "Perf.PastVideoFramesDropped";
const uint64_t Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_PastVideoFramesDropped(int64_t value)
{
    SetMetricInternal(kPerf_PastVideoFramesDroppedNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientName[] = "Perf.PastVideoFramesPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_PastVideoFramesPowerEfficient(int64_t value)
{
    SetMetricInternal(kPerf_PastVideoFramesPowerEfficientNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientName[] = "Perf.RecordIsPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_RecordIsPowerEfficient(int64_t value)
{
    SetMetricInternal(kPerf_RecordIsPowerEfficientNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothName[] = "Perf.RecordIsSmooth";
const uint64_t Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_RecordIsSmooth(int64_t value)
{
    SetMetricInternal(kPerf_RecordIsSmoothNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedName[] = "Perf.VideoFramesDecoded";
const uint64_t Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_VideoFramesDecoded(int64_t value)
{
    SetMetricInternal(kPerf_VideoFramesDecodedNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedName[] = "Perf.VideoFramesDropped";
const uint64_t Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_VideoFramesDropped(int64_t value)
{
    SetMetricInternal(kPerf_VideoFramesDroppedNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientName[] = "Perf.VideoFramesPowerEfficient";
const uint64_t Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetPerf_VideoFramesPowerEfficient(int64_t value)
{
    SetMetricInternal(kPerf_VideoFramesPowerEfficientNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_CodecProfileName[] = "Video.CodecProfile";
const uint64_t Media_VideoDecodePerfRecord::kVideo_CodecProfileNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_CodecProfile(int64_t value)
{
    SetMetricInternal(kVideo_CodecProfileNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_EME_KeySystemName[] = "Video.EME.KeySystem";
const uint64_t Media_VideoDecodePerfRecord::kVideo_EME_KeySystemNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_EME_KeySystem(int64_t value)
{
    SetMetricInternal(kVideo_EME_KeySystemNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsName[] = "Video.EME.UseHwSecureCodecs";
const uint64_t Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_EME_UseHwSecureCodecs(int64_t value)
{
    SetMetricInternal(kVideo_EME_UseHwSecureCodecsNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_FramesPerSecondName[] = "Video.FramesPerSecond";
const uint64_t Media_VideoDecodePerfRecord::kVideo_FramesPerSecondNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_FramesPerSecond(int64_t value)
{
    SetMetricInternal(kVideo_FramesPerSecondNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_InTopFrameName[] = "Video.InTopFrame";
const uint64_t Media_VideoDecodePerfRecord::kVideo_InTopFrameNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_InTopFrame(int64_t value)
{
    SetMetricInternal(kVideo_InTopFrameNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_NaturalHeightName[] = "Video.NaturalHeight";
const uint64_t Media_VideoDecodePerfRecord::kVideo_NaturalHeightNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_NaturalHeight(int64_t value)
{
    SetMetricInternal(kVideo_NaturalHeightNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_NaturalWidthName[] = "Video.NaturalWidth";
const uint64_t Media_VideoDecodePerfRecord::kVideo_NaturalWidthNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_NaturalWidth(int64_t value)
{
    SetMetricInternal(kVideo_NaturalWidthNameHash, value);
    return *this;
}

const char Media_VideoDecodePerfRecord::kVideo_PlayerIDName[] = "Video.PlayerID";
const uint64_t Media_VideoDecodePerfRecord::kVideo_PlayerIDNameHash;

Media_VideoDecodePerfRecord& Media_VideoDecodePerfRecord::SetVideo_PlayerID(int64_t value)
{
    SetMetricInternal(kVideo_PlayerIDNameHash, value);
    return *this;
}
const char Media_WebAudio_AudioContext_AudibleTime::kEntryName[] = "Media.WebAudio.AudioContext.AudibleTime";
const uint64_t Media_WebAudio_AudioContext_AudibleTime::kEntryNameHash;

Media_WebAudio_AudioContext_AudibleTime::Media_WebAudio_AudioContext_AudibleTime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_WebAudio_AudioContext_AudibleTime::Media_WebAudio_AudioContext_AudibleTime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_WebAudio_AudioContext_AudibleTime::~Media_WebAudio_AudioContext_AudibleTime() = default;
const char Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeName[] = "AudibleTime";
const uint64_t Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeNameHash;

Media_WebAudio_AudioContext_AudibleTime& Media_WebAudio_AudioContext_AudibleTime::SetAudibleTime(int64_t value)
{
    SetMetricInternal(kAudibleTimeNameHash, value);
    return *this;
}

const char Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameName[] = "IsMainFrame";
const uint64_t Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameNameHash;

Media_WebAudio_AudioContext_AudibleTime& Media_WebAudio_AudioContext_AudibleTime::SetIsMainFrame(int64_t value)
{
    SetMetricInternal(kIsMainFrameNameHash, value);
    return *this;
}
const char Media_WebMediaPlayerState::kEntryName[] = "Media.WebMediaPlayerState";
const uint64_t Media_WebMediaPlayerState::kEntryNameHash;

Media_WebMediaPlayerState::Media_WebMediaPlayerState(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_WebMediaPlayerState::Media_WebMediaPlayerState(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Media_WebMediaPlayerState::~Media_WebMediaPlayerState() = default;
const char Media_WebMediaPlayerState::kAudioEncryptionTypeName[] = "AudioEncryptionType";
const uint64_t Media_WebMediaPlayerState::kAudioEncryptionTypeNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetAudioEncryptionType(int64_t value)
{
    SetMetricInternal(kAudioEncryptionTypeNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kContainerNameName[] = "ContainerName";
const uint64_t Media_WebMediaPlayerState::kContainerNameNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetContainerName(int64_t value)
{
    SetMetricInternal(kContainerNameNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kFinalPipelineStatusName[] = "FinalPipelineStatus";
const uint64_t Media_WebMediaPlayerState::kFinalPipelineStatusNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetFinalPipelineStatus(int64_t value)
{
    SetMetricInternal(kFinalPipelineStatusNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kIsEMEName[] = "IsEME";
const uint64_t Media_WebMediaPlayerState::kIsEMENameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsEME(int64_t value)
{
    SetMetricInternal(kIsEMENameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kIsHardwareSecureName[] = "IsHardwareSecure";
const uint64_t Media_WebMediaPlayerState::kIsHardwareSecureNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsHardwareSecure(int64_t value)
{
    SetMetricInternal(kIsHardwareSecureNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kIsMSEName[] = "IsMSE";
const uint64_t Media_WebMediaPlayerState::kIsMSENameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsMSE(int64_t value)
{
    SetMetricInternal(kIsMSENameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kIsTopFrameName[] = "IsTopFrame";
const uint64_t Media_WebMediaPlayerState::kIsTopFrameNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetIsTopFrame(int64_t value)
{
    SetMetricInternal(kIsTopFrameNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kKeySystemName[] = "KeySystem";
const uint64_t Media_WebMediaPlayerState::kKeySystemNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetKeySystem(int64_t value)
{
    SetMetricInternal(kKeySystemNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kPlayerIDName[] = "PlayerID";
const uint64_t Media_WebMediaPlayerState::kPlayerIDNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetPlayerID(int64_t value)
{
    SetMetricInternal(kPlayerIDNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kRendererTypeName[] = "RendererType";
const uint64_t Media_WebMediaPlayerState::kRendererTypeNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetRendererType(int64_t value)
{
    SetMetricInternal(kRendererTypeNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kTimeToFirstFrameName[] = "TimeToFirstFrame";
const uint64_t Media_WebMediaPlayerState::kTimeToFirstFrameNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetTimeToFirstFrame(int64_t value)
{
    SetMetricInternal(kTimeToFirstFrameNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kTimeToMetadataName[] = "TimeToMetadata";
const uint64_t Media_WebMediaPlayerState::kTimeToMetadataNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetTimeToMetadata(int64_t value)
{
    SetMetricInternal(kTimeToMetadataNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kTimeToPlayReadyName[] = "TimeToPlayReady";
const uint64_t Media_WebMediaPlayerState::kTimeToPlayReadyNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetTimeToPlayReady(int64_t value)
{
    SetMetricInternal(kTimeToPlayReadyNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kURLSchemeName[] = "URLScheme";
const uint64_t Media_WebMediaPlayerState::kURLSchemeNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetURLScheme(int64_t value)
{
    SetMetricInternal(kURLSchemeNameHash, value);
    return *this;
}

const char Media_WebMediaPlayerState::kVideoEncryptionTypeName[] = "VideoEncryptionType";
const uint64_t Media_WebMediaPlayerState::kVideoEncryptionTypeNameHash;

Media_WebMediaPlayerState& Media_WebMediaPlayerState::SetVideoEncryptionType(int64_t value)
{
    SetMetricInternal(kVideoEncryptionTypeNameHash, value);
    return *this;
}
const char MediaRouter_CastWebSenderExtensionLoadUrl::kEntryName[] = "MediaRouter.CastWebSenderExtensionLoadUrl";
const uint64_t MediaRouter_CastWebSenderExtensionLoadUrl::kEntryNameHash;

MediaRouter_CastWebSenderExtensionLoadUrl::MediaRouter_CastWebSenderExtensionLoadUrl(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MediaRouter_CastWebSenderExtensionLoadUrl::MediaRouter_CastWebSenderExtensionLoadUrl(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MediaRouter_CastWebSenderExtensionLoadUrl::~MediaRouter_CastWebSenderExtensionLoadUrl() = default;
const char MediaRouter_CastWebSenderExtensionLoadUrl::kHasOccurredName[] = "HasOccurred";
const uint64_t MediaRouter_CastWebSenderExtensionLoadUrl::kHasOccurredNameHash;

MediaRouter_CastWebSenderExtensionLoadUrl& MediaRouter_CastWebSenderExtensionLoadUrl::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char MediaRouter_SiteInitiatedMirroringStarted::kEntryName[] = "MediaRouter.SiteInitiatedMirroringStarted";
const uint64_t MediaRouter_SiteInitiatedMirroringStarted::kEntryNameHash;

MediaRouter_SiteInitiatedMirroringStarted::MediaRouter_SiteInitiatedMirroringStarted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MediaRouter_SiteInitiatedMirroringStarted::MediaRouter_SiteInitiatedMirroringStarted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MediaRouter_SiteInitiatedMirroringStarted::~MediaRouter_SiteInitiatedMirroringStarted() = default;
const char MediaRouter_SiteInitiatedMirroringStarted::kAllowAudioCaptureName[] = "AllowAudioCapture";
const uint64_t MediaRouter_SiteInitiatedMirroringStarted::kAllowAudioCaptureNameHash;

MediaRouter_SiteInitiatedMirroringStarted& MediaRouter_SiteInitiatedMirroringStarted::SetAllowAudioCapture(int64_t value)
{
    SetMetricInternal(kAllowAudioCaptureNameHash, value);
    return *this;
}
const char MediaRouter_TabMirroringStarted::kEntryName[] = "MediaRouter.TabMirroringStarted";
const uint64_t MediaRouter_TabMirroringStarted::kEntryNameHash;

MediaRouter_TabMirroringStarted::MediaRouter_TabMirroringStarted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MediaRouter_TabMirroringStarted::MediaRouter_TabMirroringStarted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MediaRouter_TabMirroringStarted::~MediaRouter_TabMirroringStarted() = default;
const char MediaRouter_TabMirroringStarted::kAudioStateName[] = "AudioState";
const uint64_t MediaRouter_TabMirroringStarted::kAudioStateNameHash;

MediaRouter_TabMirroringStarted& MediaRouter_TabMirroringStarted::SetAudioState(int64_t value)
{
    SetMetricInternal(kAudioStateNameHash, value);
    return *this;
}
const char Memory_Experimental::kEntryName[] = "Memory.Experimental";
const uint64_t Memory_Experimental::kEntryNameHash;

Memory_Experimental::Memory_Experimental(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Memory_Experimental::Memory_Experimental(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Memory_Experimental::~Memory_Experimental() = default;
const char Memory_Experimental::kArrayBufferName[] = "ArrayBuffer";
const uint64_t Memory_Experimental::kArrayBufferNameHash;

Memory_Experimental& Memory_Experimental::SetArrayBuffer(int64_t value)
{
    SetMetricInternal(kArrayBufferNameHash, value);
    return *this;
}

const char Memory_Experimental::kBlinkGCName[] = "BlinkGC";
const uint64_t Memory_Experimental::kBlinkGCNameHash;

Memory_Experimental& Memory_Experimental::SetBlinkGC(int64_t value)
{
    SetMetricInternal(kBlinkGCNameHash, value);
    return *this;
}

const char Memory_Experimental::kBlinkGC_AllocatedObjectsName[] = "BlinkGC.AllocatedObjects";
const uint64_t Memory_Experimental::kBlinkGC_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetBlinkGC_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kBlinkGC_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kCanvasResourceProvider_SkSurfaceName[] = "CanvasResourceProvider.SkSurface";
const uint64_t Memory_Experimental::kCanvasResourceProvider_SkSurfaceNameHash;

Memory_Experimental& Memory_Experimental::SetCanvasResourceProvider_SkSurface(int64_t value)
{
    SetMetricInternal(kCanvasResourceProvider_SkSurfaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kCommandBufferName[] = "CommandBuffer";
const uint64_t Memory_Experimental::kCommandBufferNameHash;

Memory_Experimental& Memory_Experimental::SetCommandBuffer(int64_t value)
{
    SetMetricInternal(kCommandBufferNameHash, value);
    return *this;
}

const char Memory_Experimental::kDiscardableName[] = "Discardable";
const uint64_t Memory_Experimental::kDiscardableNameHash;

Memory_Experimental& Memory_Experimental::SetDiscardable(int64_t value)
{
    SetMetricInternal(kDiscardableNameHash, value);
    return *this;
}

const char Memory_Experimental::kDownloadServiceName[] = "DownloadService";
const uint64_t Memory_Experimental::kDownloadServiceNameHash;

Memory_Experimental& Memory_Experimental::SetDownloadService(int64_t value)
{
    SetMetricInternal(kDownloadServiceNameHash, value);
    return *this;
}

const char Memory_Experimental::kExtensions_ValueStoreName[] = "Extensions.ValueStore";
const uint64_t Memory_Experimental::kExtensions_ValueStoreNameHash;

Memory_Experimental& Memory_Experimental::SetExtensions_ValueStore(int64_t value)
{
    SetMetricInternal(kExtensions_ValueStoreNameHash, value);
    return *this;
}

const char Memory_Experimental::kFontCachesName[] = "FontCaches";
const uint64_t Memory_Experimental::kFontCachesNameHash;

Memory_Experimental& Memory_Experimental::SetFontCaches(int64_t value)
{
    SetMetricInternal(kFontCachesNameHash, value);
    return *this;
}

const char Memory_Experimental::kGpuMemoryName[] = "GpuMemory";
const uint64_t Memory_Experimental::kGpuMemoryNameHash;

Memory_Experimental& Memory_Experimental::SetGpuMemory(int64_t value)
{
    SetMetricInternal(kGpuMemoryNameHash, value);
    return *this;
}

const char Memory_Experimental::kHistoryName[] = "History";
const uint64_t Memory_Experimental::kHistoryNameHash;

Memory_Experimental& Memory_Experimental::SetHistory(int64_t value)
{
    SetMetricInternal(kHistoryNameHash, value);
    return *this;
}

const char Memory_Experimental::kIsVisibleName[] = "IsVisible";
const uint64_t Memory_Experimental::kIsVisibleNameHash;

Memory_Experimental& Memory_Experimental::SetIsVisible(int64_t value)
{
    SetMetricInternal(kIsVisibleNameHash, value);
    return *this;
}

const char Memory_Experimental::kJavaHeapName[] = "JavaHeap";
const uint64_t Memory_Experimental::kJavaHeapNameHash;

Memory_Experimental& Memory_Experimental::SetJavaHeap(int64_t value)
{
    SetMetricInternal(kJavaHeapNameHash, value);
    return *this;
}

const char Memory_Experimental::kLevelDatabaseName[] = "LevelDatabase";
const uint64_t Memory_Experimental::kLevelDatabaseNameHash;

Memory_Experimental& Memory_Experimental::SetLevelDatabase(int64_t value)
{
    SetMetricInternal(kLevelDatabaseNameHash, value);
    return *this;
}

const char Memory_Experimental::kMallocName[] = "Malloc";
const uint64_t Memory_Experimental::kMallocNameHash;

Memory_Experimental& Memory_Experimental::SetMalloc(int64_t value)
{
    SetMetricInternal(kMallocNameHash, value);
    return *this;
}

const char Memory_Experimental::kMalloc_AllocatedObjectsName[] = "Malloc.AllocatedObjects";
const uint64_t Memory_Experimental::kMalloc_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetMalloc_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kMalloc_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfAdSubframesName[] = "NumberOfAdSubframes";
const uint64_t Memory_Experimental::kNumberOfAdSubframesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfAdSubframes(int64_t value)
{
    SetMetricInternal(kNumberOfAdSubframesNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfArrayBufferContentsName[] = "NumberOfArrayBufferContents";
const uint64_t Memory_Experimental::kNumberOfArrayBufferContentsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfArrayBufferContents(int64_t value)
{
    SetMetricInternal(kNumberOfArrayBufferContentsNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfDetachedScriptStatesName[] = "NumberOfDetachedScriptStates";
const uint64_t Memory_Experimental::kNumberOfDetachedScriptStatesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfDetachedScriptStates(int64_t value)
{
    SetMetricInternal(kNumberOfDetachedScriptStatesNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfDocumentsName[] = "NumberOfDocuments";
const uint64_t Memory_Experimental::kNumberOfDocumentsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfDocuments(int64_t value)
{
    SetMetricInternal(kNumberOfDocumentsNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfExtensionsName[] = "NumberOfExtensions";
const uint64_t Memory_Experimental::kNumberOfExtensionsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfExtensions(int64_t value)
{
    SetMetricInternal(kNumberOfExtensionsNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfFramesName[] = "NumberOfFrames";
const uint64_t Memory_Experimental::kNumberOfFramesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfFrames(int64_t value)
{
    SetMetricInternal(kNumberOfFramesNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfLayoutObjectsName[] = "NumberOfLayoutObjects";
const uint64_t Memory_Experimental::kNumberOfLayoutObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfLayoutObjects(int64_t value)
{
    SetMetricInternal(kNumberOfLayoutObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfMojoHandlesName[] = "NumberOfMojoHandles";
const uint64_t Memory_Experimental::kNumberOfMojoHandlesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfMojoHandles(int64_t value)
{
    SetMetricInternal(kNumberOfMojoHandlesNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfNodesName[] = "NumberOfNodes";
const uint64_t Memory_Experimental::kNumberOfNodesNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfNodes(int64_t value)
{
    SetMetricInternal(kNumberOfNodesNameHash, value);
    return *this;
}

const char Memory_Experimental::kNumberOfWebMediaPlayersName[] = "NumberOfWebMediaPlayers";
const uint64_t Memory_Experimental::kNumberOfWebMediaPlayersNameHash;

Memory_Experimental& Memory_Experimental::SetNumberOfWebMediaPlayers(int64_t value)
{
    SetMetricInternal(kNumberOfWebMediaPlayersNameHash, value);
    return *this;
}

const char Memory_Experimental::kOmniboxSuggestionsName[] = "OmniboxSuggestions";
const uint64_t Memory_Experimental::kOmniboxSuggestionsNameHash;

Memory_Experimental& Memory_Experimental::SetOmniboxSuggestions(int64_t value)
{
    SetMetricInternal(kOmniboxSuggestionsNameHash, value);
    return *this;
}

const char Memory_Experimental::kPartitionAllocName[] = "PartitionAlloc";
const uint64_t Memory_Experimental::kPartitionAllocNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc(int64_t value)
{
    SetMetricInternal(kPartitionAllocNameHash, value);
    return *this;
}

const char Memory_Experimental::kPartitionAlloc_AllocatedObjectsName[] = "PartitionAlloc.AllocatedObjects";
const uint64_t Memory_Experimental::kPartitionAlloc_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kPartitionAlloc_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferName[] = "PartitionAlloc.Partitions.ArrayBuffer";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_ArrayBuffer(int64_t value)
{
    SetMetricInternal(kPartitionAlloc_Partitions_ArrayBufferNameHash, value);
    return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_BufferName[] = "PartitionAlloc.Partitions.Buffer";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_BufferNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_Buffer(int64_t value)
{
    SetMetricInternal(kPartitionAlloc_Partitions_BufferNameHash, value);
    return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_FastMallocName[] = "PartitionAlloc.Partitions.FastMalloc";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_FastMallocNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_FastMalloc(int64_t value)
{
    SetMetricInternal(kPartitionAlloc_Partitions_FastMallocNameHash, value);
    return *this;
}

const char Memory_Experimental::kPartitionAlloc_Partitions_LayoutName[] = "PartitionAlloc.Partitions.Layout";
const uint64_t Memory_Experimental::kPartitionAlloc_Partitions_LayoutNameHash;

Memory_Experimental& Memory_Experimental::SetPartitionAlloc_Partitions_Layout(int64_t value)
{
    SetMetricInternal(kPartitionAlloc_Partitions_LayoutNameHash, value);
    return *this;
}

const char Memory_Experimental::kPrivateMemoryFootprintName[] = "PrivateMemoryFootprint";
const uint64_t Memory_Experimental::kPrivateMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetPrivateMemoryFootprint(int64_t value)
{
    SetMetricInternal(kPrivateMemoryFootprintNameHash, value);
    return *this;
}

const char Memory_Experimental::kPrivateSwapFootprintName[] = "PrivateSwapFootprint";
const uint64_t Memory_Experimental::kPrivateSwapFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetPrivateSwapFootprint(int64_t value)
{
    SetMetricInternal(kPrivateSwapFootprintNameHash, value);
    return *this;
}

const char Memory_Experimental::kProcessTypeName[] = "ProcessType";
const uint64_t Memory_Experimental::kProcessTypeNameHash;

Memory_Experimental& Memory_Experimental::SetProcessType(int64_t value)
{
    SetMetricInternal(kProcessTypeNameHash, value);
    return *this;
}

const char Memory_Experimental::kResidentName[] = "Resident";
const uint64_t Memory_Experimental::kResidentNameHash;

Memory_Experimental& Memory_Experimental::SetResident(int64_t value)
{
    SetMetricInternal(kResidentNameHash, value);
    return *this;
}

const char Memory_Experimental::kSharedMemoryFootprintName[] = "SharedMemoryFootprint";
const uint64_t Memory_Experimental::kSharedMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetSharedMemoryFootprint(int64_t value)
{
    SetMetricInternal(kSharedMemoryFootprintNameHash, value);
    return *this;
}

const char Memory_Experimental::kSiteStorageName[] = "SiteStorage";
const uint64_t Memory_Experimental::kSiteStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage(int64_t value)
{
    SetMetricInternal(kSiteStorageNameHash, value);
    return *this;
}

const char Memory_Experimental::kSiteStorage_BlobStorageName[] = "SiteStorage.BlobStorage";
const uint64_t Memory_Experimental::kSiteStorage_BlobStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_BlobStorage(int64_t value)
{
    SetMetricInternal(kSiteStorage_BlobStorageNameHash, value);
    return *this;
}

const char Memory_Experimental::kSiteStorage_IndexDBName[] = "SiteStorage.IndexDB";
const uint64_t Memory_Experimental::kSiteStorage_IndexDBNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_IndexDB(int64_t value)
{
    SetMetricInternal(kSiteStorage_IndexDBNameHash, value);
    return *this;
}

const char Memory_Experimental::kSiteStorage_LocalStorageName[] = "SiteStorage.LocalStorage";
const uint64_t Memory_Experimental::kSiteStorage_LocalStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_LocalStorage(int64_t value)
{
    SetMetricInternal(kSiteStorage_LocalStorageNameHash, value);
    return *this;
}

const char Memory_Experimental::kSiteStorage_SessionStorageName[] = "SiteStorage.SessionStorage";
const uint64_t Memory_Experimental::kSiteStorage_SessionStorageNameHash;

Memory_Experimental& Memory_Experimental::SetSiteStorage_SessionStorage(int64_t value)
{
    SetMetricInternal(kSiteStorage_SessionStorageNameHash, value);
    return *this;
}

const char Memory_Experimental::kSkiaName[] = "Skia";
const uint64_t Memory_Experimental::kSkiaNameHash;

Memory_Experimental& Memory_Experimental::SetSkia(int64_t value)
{
    SetMetricInternal(kSkiaNameHash, value);
    return *this;
}

const char Memory_Experimental::kSkia_SkGlyphCacheName[] = "Skia.SkGlyphCache";
const uint64_t Memory_Experimental::kSkia_SkGlyphCacheNameHash;

Memory_Experimental& Memory_Experimental::SetSkia_SkGlyphCache(int64_t value)
{
    SetMetricInternal(kSkia_SkGlyphCacheNameHash, value);
    return *this;
}

const char Memory_Experimental::kSkia_SkResourceCacheName[] = "Skia.SkResourceCache";
const uint64_t Memory_Experimental::kSkia_SkResourceCacheNameHash;

Memory_Experimental& Memory_Experimental::SetSkia_SkResourceCache(int64_t value)
{
    SetMetricInternal(kSkia_SkResourceCacheNameHash, value);
    return *this;
}

const char Memory_Experimental::kSqliteName[] = "Sqlite";
const uint64_t Memory_Experimental::kSqliteNameHash;

Memory_Experimental& Memory_Experimental::SetSqlite(int64_t value)
{
    SetMetricInternal(kSqliteNameHash, value);
    return *this;
}

const char Memory_Experimental::kSyncName[] = "Sync";
const uint64_t Memory_Experimental::kSyncNameHash;

Memory_Experimental& Memory_Experimental::SetSync(int64_t value)
{
    SetMetricInternal(kSyncNameHash, value);
    return *this;
}

const char Memory_Experimental::kTabRestoreName[] = "TabRestore";
const uint64_t Memory_Experimental::kTabRestoreNameHash;

Memory_Experimental& Memory_Experimental::SetTabRestore(int64_t value)
{
    SetMetricInternal(kTabRestoreNameHash, value);
    return *this;
}

const char Memory_Experimental::kTimeSinceLastNavigationName[] = "TimeSinceLastNavigation";
const uint64_t Memory_Experimental::kTimeSinceLastNavigationNameHash;

Memory_Experimental& Memory_Experimental::SetTimeSinceLastNavigation(int64_t value)
{
    SetMetricInternal(kTimeSinceLastNavigationNameHash, value);
    return *this;
}

const char Memory_Experimental::kTimeSinceLastVisibilityChangeName[] = "TimeSinceLastVisibilityChange";
const uint64_t Memory_Experimental::kTimeSinceLastVisibilityChangeNameHash;

Memory_Experimental& Memory_Experimental::SetTimeSinceLastVisibilityChange(int64_t value)
{
    SetMetricInternal(kTimeSinceLastVisibilityChangeNameHash, value);
    return *this;
}

const char Memory_Experimental::kTotal2_PrivateMemoryFootprintName[] = "Total2.PrivateMemoryFootprint";
const uint64_t Memory_Experimental::kTotal2_PrivateMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetTotal2_PrivateMemoryFootprint(int64_t value)
{
    SetMetricInternal(kTotal2_PrivateMemoryFootprintNameHash, value);
    return *this;
}

const char Memory_Experimental::kTotal2_SharedMemoryFootprintName[] = "Total2.SharedMemoryFootprint";
const uint64_t Memory_Experimental::kTotal2_SharedMemoryFootprintNameHash;

Memory_Experimental& Memory_Experimental::SetTotal2_SharedMemoryFootprint(int64_t value)
{
    SetMetricInternal(kTotal2_SharedMemoryFootprintNameHash, value);
    return *this;
}

const char Memory_Experimental::kUIName[] = "UI";
const uint64_t Memory_Experimental::kUINameHash;

Memory_Experimental& Memory_Experimental::SetUI(int64_t value)
{
    SetMetricInternal(kUINameHash, value);
    return *this;
}

const char Memory_Experimental::kUptimeName[] = "Uptime";
const uint64_t Memory_Experimental::kUptimeNameHash;

Memory_Experimental& Memory_Experimental::SetUptime(int64_t value)
{
    SetMetricInternal(kUptimeNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8Name[] = "V8";
const uint64_t Memory_Experimental::kV8NameHash;

Memory_Experimental& Memory_Experimental::SetV8(int64_t value)
{
    SetMetricInternal(kV8NameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_AllocatedObjectsName[] = "V8.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_MainName[] = "V8.Main";
const uint64_t Memory_Experimental::kV8_MainNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main(int64_t value)
{
    SetMetricInternal(kV8_MainNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_AllocatedObjectsName[] = "V8.Main.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_GlobalHandlesName[] = "V8.Main.GlobalHandles";
const uint64_t Memory_Experimental::kV8_Main_GlobalHandlesNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_GlobalHandles(int64_t value)
{
    SetMetricInternal(kV8_Main_GlobalHandlesNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_GlobalHandles_AllocatedObjectsName[] = "V8.Main.GlobalHandles.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_GlobalHandles_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_GlobalHandles_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_GlobalHandles_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_HeapName[] = "V8.Main.Heap";
const uint64_t Memory_Experimental::kV8_Main_HeapNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap(int64_t value)
{
    SetMetricInternal(kV8_Main_HeapNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_AllocatedObjectsName[] = "V8.Main.Heap.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceName[] = "V8.Main.Heap.CodeLargeObjectSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeLargeObjectSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_CodeLargeObjectSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName[] = "V8.Main.Heap.CodeLargeObjectSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeSpaceName[] = "V8.Main.Heap.CodeSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_CodeSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsName[] = "V8.Main.Heap.CodeSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_CodeSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceName[] = "V8.Main.Heap.LargeObjectSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_LargeObjectSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_LargeObjectSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName[] = "V8.Main.Heap.LargeObjectSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_LargeObjectSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_MapSpaceName[] = "V8.Main.Heap.MapSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_MapSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_MapSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_MapSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsName[] = "V8.Main.Heap.MapSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_MapSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceName[] = "V8.Main.Heap.NewLargeObjectSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewLargeObjectSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_NewLargeObjectSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName[] = "V8.Main.Heap.NewLargeObjectSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewLargeObjectSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewSpaceName[] = "V8.Main.Heap.NewSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_NewSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsName[] = "V8.Main.Heap.NewSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_NewSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_OldSpaceName[] = "V8.Main.Heap.OldSpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_OldSpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_OldSpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_OldSpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsName[] = "V8.Main.Heap.OldSpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_OldSpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceName[] = "V8.Main.Heap.ReadOnlySpace";
const uint64_t Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_ReadOnlySpace(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_ReadOnlySpaceNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName[] = "V8.Main.Heap.ReadOnlySpace.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Heap_ReadOnlySpace_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Main_MallocName[] = "V8.Main.Malloc";
const uint64_t Memory_Experimental::kV8_Main_MallocNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Main_Malloc(int64_t value)
{
    SetMetricInternal(kV8_Main_MallocNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_WorkersName[] = "V8.Workers";
const uint64_t Memory_Experimental::kV8_WorkersNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Workers(int64_t value)
{
    SetMetricInternal(kV8_WorkersNameHash, value);
    return *this;
}

const char Memory_Experimental::kV8_Workers_AllocatedObjectsName[] = "V8.Workers.AllocatedObjects";
const uint64_t Memory_Experimental::kV8_Workers_AllocatedObjectsNameHash;

Memory_Experimental& Memory_Experimental::SetV8_Workers_AllocatedObjects(int64_t value)
{
    SetMetricInternal(kV8_Workers_AllocatedObjectsNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCacheName[] = "WebCache";
const uint64_t Memory_Experimental::kWebCacheNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache(int64_t value)
{
    SetMetricInternal(kWebCacheNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_CSSStylesheetResourcesName[] = "WebCache.CSSStylesheetResources";
const uint64_t Memory_Experimental::kWebCache_CSSStylesheetResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_CSSStylesheetResources(int64_t value)
{
    SetMetricInternal(kWebCache_CSSStylesheetResourcesNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsName[] = "WebCache.EncodedSizeDuplicatedInDataUrls";
const uint64_t Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_EncodedSizeDuplicatedInDataUrls(int64_t value)
{
    SetMetricInternal(kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_FontResourcesName[] = "WebCache.FontResources";
const uint64_t Memory_Experimental::kWebCache_FontResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_FontResources(int64_t value)
{
    SetMetricInternal(kWebCache_FontResourcesNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_ImageResourcesName[] = "WebCache.ImageResources";
const uint64_t Memory_Experimental::kWebCache_ImageResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_ImageResources(int64_t value)
{
    SetMetricInternal(kWebCache_ImageResourcesNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_OtherResourcesName[] = "WebCache.OtherResources";
const uint64_t Memory_Experimental::kWebCache_OtherResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_OtherResources(int64_t value)
{
    SetMetricInternal(kWebCache_OtherResourcesNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_ScriptResourcesName[] = "WebCache.ScriptResources";
const uint64_t Memory_Experimental::kWebCache_ScriptResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_ScriptResources(int64_t value)
{
    SetMetricInternal(kWebCache_ScriptResourcesNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_V8CodeCacheName[] = "WebCache.V8CodeCache";
const uint64_t Memory_Experimental::kWebCache_V8CodeCacheNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_V8CodeCache(int64_t value)
{
    SetMetricInternal(kWebCache_V8CodeCacheNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebCache_XSLStylesheetResourcesName[] = "WebCache.XSLStylesheetResources";
const uint64_t Memory_Experimental::kWebCache_XSLStylesheetResourcesNameHash;

Memory_Experimental& Memory_Experimental::SetWebCache_XSLStylesheetResources(int64_t value)
{
    SetMetricInternal(kWebCache_XSLStylesheetResourcesNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebMediaPlayer_AudioName[] = "WebMediaPlayer.Audio";
const uint64_t Memory_Experimental::kWebMediaPlayer_AudioNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_Audio(int64_t value)
{
    SetMetricInternal(kWebMediaPlayer_AudioNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebMediaPlayer_DataSourceName[] = "WebMediaPlayer.DataSource";
const uint64_t Memory_Experimental::kWebMediaPlayer_DataSourceNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_DataSource(int64_t value)
{
    SetMetricInternal(kWebMediaPlayer_DataSourceNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebMediaPlayer_DemuxerName[] = "WebMediaPlayer.Demuxer";
const uint64_t Memory_Experimental::kWebMediaPlayer_DemuxerNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_Demuxer(int64_t value)
{
    SetMetricInternal(kWebMediaPlayer_DemuxerNameHash, value);
    return *this;
}

const char Memory_Experimental::kWebMediaPlayer_VideoName[] = "WebMediaPlayer.Video";
const uint64_t Memory_Experimental::kWebMediaPlayer_VideoNameHash;

Memory_Experimental& Memory_Experimental::SetWebMediaPlayer_Video(int64_t value)
{
    SetMetricInternal(kWebMediaPlayer_VideoNameHash, value);
    return *this;
}
const char Memory_TabFootprint::kEntryName[] = "Memory.TabFootprint";
const uint64_t Memory_TabFootprint::kEntryNameHash;

Memory_TabFootprint::Memory_TabFootprint(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Memory_TabFootprint::Memory_TabFootprint(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Memory_TabFootprint::~Memory_TabFootprint() = default;
const char Memory_TabFootprint::kMainFrameProcessPMFName[] = "MainFrameProcessPMF";
const uint64_t Memory_TabFootprint::kMainFrameProcessPMFNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetMainFrameProcessPMF(int64_t value)
{
    SetMetricInternal(kMainFrameProcessPMFNameHash, value);
    return *this;
}

const char Memory_TabFootprint::kSubFrameProcessPMF_ExcludedName[] = "SubFrameProcessPMF.Excluded";
const uint64_t Memory_TabFootprint::kSubFrameProcessPMF_ExcludedNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetSubFrameProcessPMF_Excluded(int64_t value)
{
    SetMetricInternal(kSubFrameProcessPMF_ExcludedNameHash, value);
    return *this;
}

const char Memory_TabFootprint::kSubFrameProcessPMF_IncludedName[] = "SubFrameProcessPMF.Included";
const uint64_t Memory_TabFootprint::kSubFrameProcessPMF_IncludedNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetSubFrameProcessPMF_Included(int64_t value)
{
    SetMetricInternal(kSubFrameProcessPMF_IncludedNameHash, value);
    return *this;
}

const char Memory_TabFootprint::kSubFrameProcessPMF_TotalName[] = "SubFrameProcessPMF.Total";
const uint64_t Memory_TabFootprint::kSubFrameProcessPMF_TotalNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetSubFrameProcessPMF_Total(int64_t value)
{
    SetMetricInternal(kSubFrameProcessPMF_TotalNameHash, value);
    return *this;
}

const char Memory_TabFootprint::kTabPMFName[] = "TabPMF";
const uint64_t Memory_TabFootprint::kTabPMFNameHash;

Memory_TabFootprint& Memory_TabFootprint::SetTabPMF(int64_t value)
{
    SetMetricInternal(kTabPMFNameHash, value);
    return *this;
}
const char MixedContentAutoupgrade_ResourceRequest::kEntryName[] = "MixedContentAutoupgrade.ResourceRequest";
const uint64_t MixedContentAutoupgrade_ResourceRequest::kEntryNameHash;

MixedContentAutoupgrade_ResourceRequest::MixedContentAutoupgrade_ResourceRequest(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MixedContentAutoupgrade_ResourceRequest::MixedContentAutoupgrade_ResourceRequest(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MixedContentAutoupgrade_ResourceRequest::~MixedContentAutoupgrade_ResourceRequest() = default;
const char MixedContentAutoupgrade_ResourceRequest::kCodeName[] = "Code";
const uint64_t MixedContentAutoupgrade_ResourceRequest::kCodeNameHash;

MixedContentAutoupgrade_ResourceRequest& MixedContentAutoupgrade_ResourceRequest::SetCode(int64_t value)
{
    SetMetricInternal(kCodeNameHash, value);
    return *this;
}

const char MixedContentAutoupgrade_ResourceRequest::kStatusName[] = "Status";
const uint64_t MixedContentAutoupgrade_ResourceRequest::kStatusNameHash;

MixedContentAutoupgrade_ResourceRequest& MixedContentAutoupgrade_ResourceRequest::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}
const char MobileFriendliness::kEntryName[] = "MobileFriendliness";
const uint64_t MobileFriendliness::kEntryNameHash;

MobileFriendliness::MobileFriendliness(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileFriendliness::MobileFriendliness(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileFriendliness::~MobileFriendliness() = default;
const char MobileFriendliness::kAllowUserZoomName[] = "AllowUserZoom";
const uint64_t MobileFriendliness::kAllowUserZoomNameHash;

MobileFriendliness& MobileFriendliness::SetAllowUserZoom(int64_t value)
{
    SetMetricInternal(kAllowUserZoomNameHash, value);
    return *this;
}

const char MobileFriendliness::kBadTapTargetsRatioName[] = "BadTapTargetsRatio";
const uint64_t MobileFriendliness::kBadTapTargetsRatioNameHash;

MobileFriendliness& MobileFriendliness::SetBadTapTargetsRatio(int64_t value)
{
    SetMetricInternal(kBadTapTargetsRatioNameHash, value);
    return *this;
}

const char MobileFriendliness::kSmallTextRatioName[] = "SmallTextRatio";
const uint64_t MobileFriendliness::kSmallTextRatioNameHash;

MobileFriendliness& MobileFriendliness::SetSmallTextRatio(int64_t value)
{
    SetMetricInternal(kSmallTextRatioNameHash, value);
    return *this;
}

const char MobileFriendliness::kTextContentOutsideViewportPercentageName[] = "TextContentOutsideViewportPercentage";
const uint64_t MobileFriendliness::kTextContentOutsideViewportPercentageNameHash;

MobileFriendliness& MobileFriendliness::SetTextContentOutsideViewportPercentage(int64_t value)
{
    SetMetricInternal(kTextContentOutsideViewportPercentageNameHash, value);
    return *this;
}

const char MobileFriendliness::kViewportDeviceWidthName[] = "ViewportDeviceWidth";
const uint64_t MobileFriendliness::kViewportDeviceWidthNameHash;

MobileFriendliness& MobileFriendliness::SetViewportDeviceWidth(int64_t value)
{
    SetMetricInternal(kViewportDeviceWidthNameHash, value);
    return *this;
}

const char MobileFriendliness::kViewportHardcodedWidthName[] = "ViewportHardcodedWidth";
const uint64_t MobileFriendliness::kViewportHardcodedWidthNameHash;

MobileFriendliness& MobileFriendliness::SetViewportHardcodedWidth(int64_t value)
{
    SetMetricInternal(kViewportHardcodedWidthNameHash, value);
    return *this;
}

const char MobileFriendliness::kViewportInitialScaleX10Name[] = "ViewportInitialScaleX10";
const uint64_t MobileFriendliness::kViewportInitialScaleX10NameHash;

MobileFriendliness& MobileFriendliness::SetViewportInitialScaleX10(int64_t value)
{
    SetMetricInternal(kViewportInitialScaleX10NameHash, value);
    return *this;
}
const char MobileMenu_DirectShare::kEntryName[] = "MobileMenu.DirectShare";
const uint64_t MobileMenu_DirectShare::kEntryNameHash;

MobileMenu_DirectShare::MobileMenu_DirectShare(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileMenu_DirectShare::MobileMenu_DirectShare(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileMenu_DirectShare::~MobileMenu_DirectShare() = default;
const char MobileMenu_DirectShare::kHasOccurredName[] = "HasOccurred";
const uint64_t MobileMenu_DirectShare::kHasOccurredNameHash;

MobileMenu_DirectShare& MobileMenu_DirectShare::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char MobileMenu_FindInPage::kEntryName[] = "MobileMenu.FindInPage";
const uint64_t MobileMenu_FindInPage::kEntryNameHash;

MobileMenu_FindInPage::MobileMenu_FindInPage(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileMenu_FindInPage::MobileMenu_FindInPage(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileMenu_FindInPage::~MobileMenu_FindInPage() = default;
const char MobileMenu_FindInPage::kHasOccurredName[] = "HasOccurred";
const uint64_t MobileMenu_FindInPage::kHasOccurredNameHash;

MobileMenu_FindInPage& MobileMenu_FindInPage::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char MobileMenu_Share::kEntryName[] = "MobileMenu.Share";
const uint64_t MobileMenu_Share::kEntryNameHash;

MobileMenu_Share::MobileMenu_Share(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileMenu_Share::MobileMenu_Share(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

MobileMenu_Share::~MobileMenu_Share() = default;
const char MobileMenu_Share::kHasOccurredName[] = "HasOccurred";
const uint64_t MobileMenu_Share::kHasOccurredNameHash;

MobileMenu_Share& MobileMenu_Share::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char Navigation_IDNA2008Transition::kEntryName[] = "Navigation.IDNA2008Transition";
const uint64_t Navigation_IDNA2008Transition::kEntryNameHash;

Navigation_IDNA2008Transition::Navigation_IDNA2008Transition(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Navigation_IDNA2008Transition::Navigation_IDNA2008Transition(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Navigation_IDNA2008Transition::~Navigation_IDNA2008Transition() = default;
const char Navigation_IDNA2008Transition::kCharacterName[] = "Character";
const uint64_t Navigation_IDNA2008Transition::kCharacterNameHash;

Navigation_IDNA2008Transition& Navigation_IDNA2008Transition::SetCharacter(int64_t value)
{
    SetMetricInternal(kCharacterNameHash, value);
    return *this;
}
const char Navigation_ReceivedResponse::kEntryName[] = "Navigation.ReceivedResponse";
const uint64_t Navigation_ReceivedResponse::kEntryNameHash;

Navigation_ReceivedResponse::Navigation_ReceivedResponse(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Navigation_ReceivedResponse::Navigation_ReceivedResponse(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Navigation_ReceivedResponse::~Navigation_ReceivedResponse() = default;
const char Navigation_ReceivedResponse::kHasAcceptCHFrameName[] = "HasAcceptCHFrame";
const uint64_t Navigation_ReceivedResponse::kHasAcceptCHFrameNameHash;

Navigation_ReceivedResponse& Navigation_ReceivedResponse::SetHasAcceptCHFrame(int64_t value)
{
    SetMetricInternal(kHasAcceptCHFrameNameHash, value);
    return *this;
}

const char Navigation_ReceivedResponse::kNavigationFirstResponseLatencyName[] = "NavigationFirstResponseLatency";
const uint64_t Navigation_ReceivedResponse::kNavigationFirstResponseLatencyNameHash;

Navigation_ReceivedResponse& Navigation_ReceivedResponse::SetNavigationFirstResponseLatency(int64_t value)
{
    SetMetricInternal(kNavigationFirstResponseLatencyNameHash, value);
    return *this;
}
const char NavigationPredictorAnchorElementMetrics::kEntryName[] = "NavigationPredictorAnchorElementMetrics";
const uint64_t NavigationPredictorAnchorElementMetrics::kEntryNameHash;

NavigationPredictorAnchorElementMetrics::NavigationPredictorAnchorElementMetrics(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationPredictorAnchorElementMetrics::NavigationPredictorAnchorElementMetrics(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationPredictorAnchorElementMetrics::~NavigationPredictorAnchorElementMetrics() = default;
const char NavigationPredictorAnchorElementMetrics::kAnchorIndexName[] = "AnchorIndex";
const uint64_t NavigationPredictorAnchorElementMetrics::kAnchorIndexNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetAnchorIndex(int64_t value)
{
    SetMetricInternal(kAnchorIndexNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kBucketedPathHashName[] = "BucketedPathHash";
const uint64_t NavigationPredictorAnchorElementMetrics::kBucketedPathHashNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetBucketedPathHash(int64_t value)
{
    SetMetricInternal(kBucketedPathHashNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kContainsImageName[] = "ContainsImage";
const uint64_t NavigationPredictorAnchorElementMetrics::kContainsImageNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetContainsImage(int64_t value)
{
    SetMetricInternal(kContainsImageNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kFontSizeName[] = "FontSize";
const uint64_t NavigationPredictorAnchorElementMetrics::kFontSizeNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetFontSize(int64_t value)
{
    SetMetricInternal(kFontSizeNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kHasTextSiblingName[] = "HasTextSibling";
const uint64_t NavigationPredictorAnchorElementMetrics::kHasTextSiblingNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetHasTextSibling(int64_t value)
{
    SetMetricInternal(kHasTextSiblingNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kIsBoldName[] = "IsBold";
const uint64_t NavigationPredictorAnchorElementMetrics::kIsBoldNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetIsBold(int64_t value)
{
    SetMetricInternal(kIsBoldNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kIsInIframeName[] = "IsInIframe";
const uint64_t NavigationPredictorAnchorElementMetrics::kIsInIframeNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetIsInIframe(int64_t value)
{
    SetMetricInternal(kIsInIframeNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneName[] = "IsURLIncrementedByOne";
const uint64_t NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetIsURLIncrementedByOne(int64_t value)
{
    SetMetricInternal(kIsURLIncrementedByOneNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kNavigationStartToLinkLoggedMsName[] = "NavigationStartToLinkLoggedMs";
const uint64_t NavigationPredictorAnchorElementMetrics::kNavigationStartToLinkLoggedMsNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetNavigationStartToLinkLoggedMs(int64_t value)
{
    SetMetricInternal(kNavigationStartToLinkLoggedMsNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kPathDepthName[] = "PathDepth";
const uint64_t NavigationPredictorAnchorElementMetrics::kPathDepthNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetPathDepth(int64_t value)
{
    SetMetricInternal(kPathDepthNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kPathLengthName[] = "PathLength";
const uint64_t NavigationPredictorAnchorElementMetrics::kPathLengthNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetPathLength(int64_t value)
{
    SetMetricInternal(kPathLengthNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kPercentClickableAreaName[] = "PercentClickableArea";
const uint64_t NavigationPredictorAnchorElementMetrics::kPercentClickableAreaNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetPercentClickableArea(int64_t value)
{
    SetMetricInternal(kPercentClickableAreaNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceName[] = "PercentVerticalDistance";
const uint64_t NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetPercentVerticalDistance(int64_t value)
{
    SetMetricInternal(kPercentVerticalDistanceNameHash, value);
    return *this;
}

const char NavigationPredictorAnchorElementMetrics::kSameOriginName[] = "SameOrigin";
const uint64_t NavigationPredictorAnchorElementMetrics::kSameOriginNameHash;

NavigationPredictorAnchorElementMetrics& NavigationPredictorAnchorElementMetrics::SetSameOrigin(int64_t value)
{
    SetMetricInternal(kSameOriginNameHash, value);
    return *this;
}
const char NavigationPredictorPageLinkClick::kEntryName[] = "NavigationPredictorPageLinkClick";
const uint64_t NavigationPredictorPageLinkClick::kEntryNameHash;

NavigationPredictorPageLinkClick::NavigationPredictorPageLinkClick(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationPredictorPageLinkClick::NavigationPredictorPageLinkClick(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationPredictorPageLinkClick::~NavigationPredictorPageLinkClick() = default;
const char NavigationPredictorPageLinkClick::kAnchorElementIndexName[] = "AnchorElementIndex";
const uint64_t NavigationPredictorPageLinkClick::kAnchorElementIndexNameHash;

NavigationPredictorPageLinkClick& NavigationPredictorPageLinkClick::SetAnchorElementIndex(int64_t value)
{
    SetMetricInternal(kAnchorElementIndexNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkClick::kHrefUnchangedName[] = "HrefUnchanged";
const uint64_t NavigationPredictorPageLinkClick::kHrefUnchangedNameHash;

NavigationPredictorPageLinkClick& NavigationPredictorPageLinkClick::SetHrefUnchanged(int64_t value)
{
    SetMetricInternal(kHrefUnchangedNameHash, value);
    return *this;
}
const char NavigationPredictorPageLinkMetrics::kEntryName[] = "NavigationPredictorPageLinkMetrics";
const uint64_t NavigationPredictorPageLinkMetrics::kEntryNameHash;

NavigationPredictorPageLinkMetrics::NavigationPredictorPageLinkMetrics(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationPredictorPageLinkMetrics::NavigationPredictorPageLinkMetrics(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationPredictorPageLinkMetrics::~NavigationPredictorPageLinkMetrics() = default;
const char NavigationPredictorPageLinkMetrics::kMedianLinkLocationName[] = "MedianLinkLocation";
const uint64_t NavigationPredictorPageLinkMetrics::kMedianLinkLocationNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetMedianLinkLocation(int64_t value)
{
    SetMetricInternal(kMedianLinkLocationNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageName[] = "NumberOfAnchors.ContainsImage";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_ContainsImage(int64_t value)
{
    SetMetricInternal(kNumberOfAnchors_ContainsImageNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeName[] = "NumberOfAnchors.InIframe";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_InIframe(int64_t value)
{
    SetMetricInternal(kNumberOfAnchors_InIframeNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostName[] = "NumberOfAnchors.SameHost";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_SameHost(int64_t value)
{
    SetMetricInternal(kNumberOfAnchors_SameHostNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalName[] = "NumberOfAnchors.Total";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_Total(int64_t value)
{
    SetMetricInternal(kNumberOfAnchors_TotalNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedName[] = "NumberOfAnchors.URLIncremented";
const uint64_t NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetNumberOfAnchors_URLIncremented(int64_t value)
{
    SetMetricInternal(kNumberOfAnchors_URLIncrementedNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kTotalClickableSpaceName[] = "TotalClickableSpace";
const uint64_t NavigationPredictorPageLinkMetrics::kTotalClickableSpaceNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetTotalClickableSpace(int64_t value)
{
    SetMetricInternal(kTotalClickableSpaceNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kViewport_HeightName[] = "Viewport.Height";
const uint64_t NavigationPredictorPageLinkMetrics::kViewport_HeightNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetViewport_Height(int64_t value)
{
    SetMetricInternal(kViewport_HeightNameHash, value);
    return *this;
}

const char NavigationPredictorPageLinkMetrics::kViewport_WidthName[] = "Viewport.Width";
const uint64_t NavigationPredictorPageLinkMetrics::kViewport_WidthNameHash;

NavigationPredictorPageLinkMetrics& NavigationPredictorPageLinkMetrics::SetViewport_Width(int64_t value)
{
    SetMetricInternal(kViewport_WidthNameHash, value);
    return *this;
}
const char NavigationThrottleDeferredTime::kEntryName[] = "NavigationThrottleDeferredTime";
const uint64_t NavigationThrottleDeferredTime::kEntryNameHash;

NavigationThrottleDeferredTime::NavigationThrottleDeferredTime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationThrottleDeferredTime::NavigationThrottleDeferredTime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationThrottleDeferredTime::~NavigationThrottleDeferredTime() = default;
const char NavigationThrottleDeferredTime::kDurationOfNavigationDeferralMsName[] = "DurationOfNavigationDeferralMs";
const uint64_t NavigationThrottleDeferredTime::kDurationOfNavigationDeferralMsNameHash;

NavigationThrottleDeferredTime& NavigationThrottleDeferredTime::SetDurationOfNavigationDeferralMs(int64_t value)
{
    SetMetricInternal(kDurationOfNavigationDeferralMsNameHash, value);
    return *this;
}

const char NavigationThrottleDeferredTime::kNavigationThrottleEventTypeName[] = "NavigationThrottleEventType";
const uint64_t NavigationThrottleDeferredTime::kNavigationThrottleEventTypeNameHash;

NavigationThrottleDeferredTime& NavigationThrottleDeferredTime::SetNavigationThrottleEventType(int64_t value)
{
    SetMetricInternal(kNavigationThrottleEventTypeNameHash, value);
    return *this;
}

const char NavigationThrottleDeferredTime::kNavigationThrottleNameHashName[] = "NavigationThrottleNameHash";
const uint64_t NavigationThrottleDeferredTime::kNavigationThrottleNameHashNameHash;

NavigationThrottleDeferredTime& NavigationThrottleDeferredTime::SetNavigationThrottleNameHash(int64_t value)
{
    SetMetricInternal(kNavigationThrottleNameHashNameHash, value);
    return *this;
}
const char NavigationTiming::kEntryName[] = "NavigationTiming";
const uint64_t NavigationTiming::kEntryNameHash;

NavigationTiming::NavigationTiming(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationTiming::NavigationTiming(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NavigationTiming::~NavigationTiming() = default;
const char NavigationTiming::kFinalLoaderCallbackName[] = "FinalLoaderCallback";
const uint64_t NavigationTiming::kFinalLoaderCallbackNameHash;

NavigationTiming& NavigationTiming::SetFinalLoaderCallback(int64_t value)
{
    SetMetricInternal(kFinalLoaderCallbackNameHash, value);
    return *this;
}

const char NavigationTiming::kFinalRequestStartName[] = "FinalRequestStart";
const uint64_t NavigationTiming::kFinalRequestStartNameHash;

NavigationTiming& NavigationTiming::SetFinalRequestStart(int64_t value)
{
    SetMetricInternal(kFinalRequestStartNameHash, value);
    return *this;
}

const char NavigationTiming::kFinalResponseStartName[] = "FinalResponseStart";
const uint64_t NavigationTiming::kFinalResponseStartNameHash;

NavigationTiming& NavigationTiming::SetFinalResponseStart(int64_t value)
{
    SetMetricInternal(kFinalResponseStartNameHash, value);
    return *this;
}

const char NavigationTiming::kFirstLoaderCallbackName[] = "FirstLoaderCallback";
const uint64_t NavigationTiming::kFirstLoaderCallbackNameHash;

NavigationTiming& NavigationTiming::SetFirstLoaderCallback(int64_t value)
{
    SetMetricInternal(kFirstLoaderCallbackNameHash, value);
    return *this;
}

const char NavigationTiming::kFirstRequestStartName[] = "FirstRequestStart";
const uint64_t NavigationTiming::kFirstRequestStartNameHash;

NavigationTiming& NavigationTiming::SetFirstRequestStart(int64_t value)
{
    SetMetricInternal(kFirstRequestStartNameHash, value);
    return *this;
}

const char NavigationTiming::kFirstResponseStartName[] = "FirstResponseStart";
const uint64_t NavigationTiming::kFirstResponseStartNameHash;

NavigationTiming& NavigationTiming::SetFirstResponseStart(int64_t value)
{
    SetMetricInternal(kFirstResponseStartNameHash, value);
    return *this;
}

const char NavigationTiming::kNavigationCommitSentName[] = "NavigationCommitSent";
const uint64_t NavigationTiming::kNavigationCommitSentNameHash;

NavigationTiming& NavigationTiming::SetNavigationCommitSent(int64_t value)
{
    SetMetricInternal(kNavigationCommitSentNameHash, value);
    return *this;
}
const char Net_LegacyTLSVersion::kEntryName[] = "Net.LegacyTLSVersion";
const uint64_t Net_LegacyTLSVersion::kEntryNameHash;

Net_LegacyTLSVersion::Net_LegacyTLSVersion(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Net_LegacyTLSVersion::Net_LegacyTLSVersion(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Net_LegacyTLSVersion::~Net_LegacyTLSVersion() = default;
const char Net_LegacyTLSVersion::kIsAdResourceName[] = "IsAdResource";
const uint64_t Net_LegacyTLSVersion::kIsAdResourceNameHash;

Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsAdResource(int64_t value)
{
    SetMetricInternal(kIsAdResourceNameHash, value);
    return *this;
}

const char Net_LegacyTLSVersion::kIsMainFrameName[] = "IsMainFrame";
const uint64_t Net_LegacyTLSVersion::kIsMainFrameNameHash;

Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsMainFrame(int64_t value)
{
    SetMetricInternal(kIsMainFrameNameHash, value);
    return *this;
}

const char Net_LegacyTLSVersion::kIsSubresourceName[] = "IsSubresource";
const uint64_t Net_LegacyTLSVersion::kIsSubresourceNameHash;

Net_LegacyTLSVersion& Net_LegacyTLSVersion::SetIsSubresource(int64_t value)
{
    SetMetricInternal(kIsSubresourceNameHash, value);
    return *this;
}
const char Network_CacheTransparency::kEntryName[] = "Network.CacheTransparency";
const uint64_t Network_CacheTransparency::kEntryNameHash;

Network_CacheTransparency::Network_CacheTransparency(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Network_CacheTransparency::Network_CacheTransparency(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Network_CacheTransparency::~Network_CacheTransparency() = default;
const char Network_CacheTransparency::kFoundPervasivePayloadName[] = "FoundPervasivePayload";
const uint64_t Network_CacheTransparency::kFoundPervasivePayloadNameHash;

Network_CacheTransparency& Network_CacheTransparency::SetFoundPervasivePayload(int64_t value)
{
    SetMetricInternal(kFoundPervasivePayloadNameHash, value);
    return *this;
}

const char Network_CacheTransparency::kTotalBytesFetchedName[] = "TotalBytesFetched";
const uint64_t Network_CacheTransparency::kTotalBytesFetchedNameHash;

Network_CacheTransparency& Network_CacheTransparency::SetTotalBytesFetched(int64_t value)
{
    SetMetricInternal(kTotalBytesFetchedNameHash, value);
    return *this;
}
const char NoStatePrefetch::kEntryName[] = "NoStatePrefetch";
const uint64_t NoStatePrefetch::kEntryNameHash;

NoStatePrefetch::NoStatePrefetch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NoStatePrefetch::NoStatePrefetch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

NoStatePrefetch::~NoStatePrefetch() = default;
const char NoStatePrefetch::kPrefetchedRecently_FinalStatusName[] = "PrefetchedRecently.FinalStatus";
const uint64_t NoStatePrefetch::kPrefetchedRecently_FinalStatusNameHash;

NoStatePrefetch& NoStatePrefetch::SetPrefetchedRecently_FinalStatus(int64_t value)
{
    SetMetricInternal(kPrefetchedRecently_FinalStatusNameHash, value);
    return *this;
}

const char NoStatePrefetch::kPrefetchedRecently_OriginName[] = "PrefetchedRecently.Origin";
const uint64_t NoStatePrefetch::kPrefetchedRecently_OriginNameHash;

NoStatePrefetch& NoStatePrefetch::SetPrefetchedRecently_Origin(int64_t value)
{
    SetMetricInternal(kPrefetchedRecently_OriginNameHash, value);
    return *this;
}

const char NoStatePrefetch::kPrefetchedRecently_PrefetchAgeName[] = "PrefetchedRecently.PrefetchAge";
const uint64_t NoStatePrefetch::kPrefetchedRecently_PrefetchAgeNameHash;

NoStatePrefetch& NoStatePrefetch::SetPrefetchedRecently_PrefetchAge(int64_t value)
{
    SetMetricInternal(kPrefetchedRecently_PrefetchAgeNameHash, value);
    return *this;
}
const char Notification::kEntryName[] = "Notification";
const uint64_t Notification::kEntryNameHash;

Notification::Notification(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Notification::Notification(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Notification::~Notification() = default;
const char Notification::kClosedReasonName[] = "ClosedReason";
const uint64_t Notification::kClosedReasonNameHash;

Notification& Notification::SetClosedReason(int64_t value)
{
    SetMetricInternal(kClosedReasonNameHash, value);
    return *this;
}

const char Notification::kDidReplaceAnotherNotificationName[] = "DidReplaceAnotherNotification";
const uint64_t Notification::kDidReplaceAnotherNotificationNameHash;

Notification& Notification::SetDidReplaceAnotherNotification(int64_t value)
{
    SetMetricInternal(kDidReplaceAnotherNotificationNameHash, value);
    return *this;
}

const char Notification::kDidUserOpenSettingsName[] = "DidUserOpenSettings";
const uint64_t Notification::kDidUserOpenSettingsNameHash;

Notification& Notification::SetDidUserOpenSettings(int64_t value)
{
    SetMetricInternal(kDidUserOpenSettingsNameHash, value);
    return *this;
}

const char Notification::kHasBadgeName[] = "HasBadge";
const uint64_t Notification::kHasBadgeNameHash;

Notification& Notification::SetHasBadge(int64_t value)
{
    SetMetricInternal(kHasBadgeNameHash, value);
    return *this;
}

const char Notification::kHasIconName[] = "HasIcon";
const uint64_t Notification::kHasIconNameHash;

Notification& Notification::SetHasIcon(int64_t value)
{
    SetMetricInternal(kHasIconNameHash, value);
    return *this;
}

const char Notification::kHasImageName[] = "HasImage";
const uint64_t Notification::kHasImageNameHash;

Notification& Notification::SetHasImage(int64_t value)
{
    SetMetricInternal(kHasImageNameHash, value);
    return *this;
}

const char Notification::kHasRenotifyName[] = "HasRenotify";
const uint64_t Notification::kHasRenotifyNameHash;

Notification& Notification::SetHasRenotify(int64_t value)
{
    SetMetricInternal(kHasRenotifyNameHash, value);
    return *this;
}

const char Notification::kHasTagName[] = "HasTag";
const uint64_t Notification::kHasTagNameHash;

Notification& Notification::SetHasTag(int64_t value)
{
    SetMetricInternal(kHasTagNameHash, value);
    return *this;
}

const char Notification::kIsSilentName[] = "IsSilent";
const uint64_t Notification::kIsSilentNameHash;

Notification& Notification::SetIsSilent(int64_t value)
{
    SetMetricInternal(kIsSilentNameHash, value);
    return *this;
}

const char Notification::kNumActionButtonClicksName[] = "NumActionButtonClicks";
const uint64_t Notification::kNumActionButtonClicksNameHash;

Notification& Notification::SetNumActionButtonClicks(int64_t value)
{
    SetMetricInternal(kNumActionButtonClicksNameHash, value);
    return *this;
}

const char Notification::kNumActionsName[] = "NumActions";
const uint64_t Notification::kNumActionsNameHash;

Notification& Notification::SetNumActions(int64_t value)
{
    SetMetricInternal(kNumActionsNameHash, value);
    return *this;
}

const char Notification::kNumClicksName[] = "NumClicks";
const uint64_t Notification::kNumClicksNameHash;

Notification& Notification::SetNumClicks(int64_t value)
{
    SetMetricInternal(kNumClicksNameHash, value);
    return *this;
}

const char Notification::kRequireInteractionName[] = "RequireInteraction";
const uint64_t Notification::kRequireInteractionNameHash;

Notification& Notification::SetRequireInteraction(int64_t value)
{
    SetMetricInternal(kRequireInteractionNameHash, value);
    return *this;
}

const char Notification::kTimeUntilCloseName[] = "TimeUntilClose";
const uint64_t Notification::kTimeUntilCloseNameHash;

Notification& Notification::SetTimeUntilClose(int64_t value)
{
    SetMetricInternal(kTimeUntilCloseNameHash, value);
    return *this;
}

const char Notification::kTimeUntilFirstClickName[] = "TimeUntilFirstClick";
const uint64_t Notification::kTimeUntilFirstClickNameHash;

Notification& Notification::SetTimeUntilFirstClick(int64_t value)
{
    SetMetricInternal(kTimeUntilFirstClickNameHash, value);
    return *this;
}

const char Notification::kTimeUntilLastClickName[] = "TimeUntilLastClick";
const uint64_t Notification::kTimeUntilLastClickNameHash;

Notification& Notification::SetTimeUntilLastClick(int64_t value)
{
    SetMetricInternal(kTimeUntilLastClickNameHash, value);
    return *this;
}
const char Omnibox_EditUrlSuggestion_Share::kEntryName[] = "Omnibox.EditUrlSuggestion.Share";
const uint64_t Omnibox_EditUrlSuggestion_Share::kEntryNameHash;

Omnibox_EditUrlSuggestion_Share::Omnibox_EditUrlSuggestion_Share(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Omnibox_EditUrlSuggestion_Share::Omnibox_EditUrlSuggestion_Share(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Omnibox_EditUrlSuggestion_Share::~Omnibox_EditUrlSuggestion_Share() = default;
const char Omnibox_EditUrlSuggestion_Share::kHasOccurredName[] = "HasOccurred";
const uint64_t Omnibox_EditUrlSuggestion_Share::kHasOccurredNameHash;

Omnibox_EditUrlSuggestion_Share& Omnibox_EditUrlSuggestion_Share::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char OmniboxSecurityIndicator_FormSubmission::kEntryName[] = "OmniboxSecurityIndicator.FormSubmission";
const uint64_t OmniboxSecurityIndicator_FormSubmission::kEntryNameHash;

OmniboxSecurityIndicator_FormSubmission::OmniboxSecurityIndicator_FormSubmission(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

OmniboxSecurityIndicator_FormSubmission::OmniboxSecurityIndicator_FormSubmission(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

OmniboxSecurityIndicator_FormSubmission::~OmniboxSecurityIndicator_FormSubmission() = default;
const char OmniboxSecurityIndicator_FormSubmission::kSubmittedName[] = "Submitted";
const uint64_t OmniboxSecurityIndicator_FormSubmission::kSubmittedNameHash;

OmniboxSecurityIndicator_FormSubmission& OmniboxSecurityIndicator_FormSubmission::SetSubmitted(int64_t value)
{
    SetMetricInternal(kSubmittedNameHash, value);
    return *this;
}
const char OptimizationGuide::kEntryName[] = "OptimizationGuide";
const uint64_t OptimizationGuide::kEntryNameHash;

OptimizationGuide::OptimizationGuide(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

OptimizationGuide::OptimizationGuide(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

OptimizationGuide::~OptimizationGuide() = default;
const char OptimizationGuide::kNavigationHintsFetchAttemptStatusName[] = "NavigationHintsFetchAttemptStatus";
const uint64_t OptimizationGuide::kNavigationHintsFetchAttemptStatusNameHash;

OptimizationGuide& OptimizationGuide::SetNavigationHintsFetchAttemptStatus(int64_t value)
{
    SetMetricInternal(kNavigationHintsFetchAttemptStatusNameHash, value);
    return *this;
}

const char OptimizationGuide::kNavigationHintsFetchRequestLatencyName[] = "NavigationHintsFetchRequestLatency";
const uint64_t OptimizationGuide::kNavigationHintsFetchRequestLatencyNameHash;

OptimizationGuide& OptimizationGuide::SetNavigationHintsFetchRequestLatency(int64_t value)
{
    SetMetricInternal(kNavigationHintsFetchRequestLatencyNameHash, value);
    return *this;
}

const char OptimizationGuide::kRegisteredOptimizationTargetsName[] = "RegisteredOptimizationTargets";
const uint64_t OptimizationGuide::kRegisteredOptimizationTargetsNameHash;

OptimizationGuide& OptimizationGuide::SetRegisteredOptimizationTargets(int64_t value)
{
    SetMetricInternal(kRegisteredOptimizationTargetsNameHash, value);
    return *this;
}

const char OptimizationGuide::kRegisteredOptimizationTypesName[] = "RegisteredOptimizationTypes";
const uint64_t OptimizationGuide::kRegisteredOptimizationTypesNameHash;

OptimizationGuide& OptimizationGuide::SetRegisteredOptimizationTypes(int64_t value)
{
    SetMetricInternal(kRegisteredOptimizationTypesNameHash, value);
    return *this;
}
const char PageDomainInfo::kEntryName[] = "PageDomainInfo";
const uint64_t PageDomainInfo::kEntryNameHash;

PageDomainInfo::PageDomainInfo(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageDomainInfo::PageDomainInfo(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageDomainInfo::~PageDomainInfo() = default;
const char PageDomainInfo::kDomainTypeName[] = "DomainType";
const uint64_t PageDomainInfo::kDomainTypeNameHash;

PageDomainInfo& PageDomainInfo::SetDomainType(int64_t value)
{
    SetMetricInternal(kDomainTypeNameHash, value);
    return *this;
}
const char PageForegroundSession::kEntryName[] = "PageForegroundSession";
const uint64_t PageForegroundSession::kEntryNameHash;

PageForegroundSession::PageForegroundSession(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageForegroundSession::PageForegroundSession(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageForegroundSession::~PageForegroundSession() = default;
const char PageForegroundSession::kForegroundDurationName[] = "ForegroundDuration";
const uint64_t PageForegroundSession::kForegroundDurationNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundDuration(int64_t value)
{
    SetMetricInternal(kForegroundDurationNameHash, value);
    return *this;
}

const char PageForegroundSession::kForegroundNumInputEventsName[] = "ForegroundNumInputEvents";
const uint64_t PageForegroundSession::kForegroundNumInputEventsNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundNumInputEvents(int64_t value)
{
    SetMetricInternal(kForegroundNumInputEventsNameHash, value);
    return *this;
}

const char PageForegroundSession::kForegroundTotalAdjustedInputDelayName[] = "ForegroundTotalAdjustedInputDelay";
const uint64_t PageForegroundSession::kForegroundTotalAdjustedInputDelayNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundTotalAdjustedInputDelay(int64_t value)
{
    SetMetricInternal(kForegroundTotalAdjustedInputDelayNameHash, value);
    return *this;
}

const char PageForegroundSession::kForegroundTotalInputDelayName[] = "ForegroundTotalInputDelay";
const uint64_t PageForegroundSession::kForegroundTotalInputDelayNameHash;

PageForegroundSession& PageForegroundSession::SetForegroundTotalInputDelay(int64_t value)
{
    SetMetricInternal(kForegroundTotalInputDelayNameHash, value);
    return *this;
}
const char PageInfoBubble::kEntryName[] = "PageInfoBubble";
const uint64_t PageInfoBubble::kEntryNameHash;

PageInfoBubble::PageInfoBubble(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageInfoBubble::PageInfoBubble(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageInfoBubble::~PageInfoBubble() = default;
const char PageInfoBubble::kActionTakenName[] = "ActionTaken";
const uint64_t PageInfoBubble::kActionTakenNameHash;

PageInfoBubble& PageInfoBubble::SetActionTaken(int64_t value)
{
    SetMetricInternal(kActionTakenNameHash, value);
    return *this;
}
const char PageLoad::kEntryName[] = "PageLoad";
const uint64_t PageLoad::kEntryNameHash;

PageLoad::PageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad::PageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad::~PageLoad() = default;
const char PageLoad::kCpuTimeName[] = "CpuTime";
const uint64_t PageLoad::kCpuTimeNameHash;

PageLoad& PageLoad::SetCpuTime(int64_t value)
{
    SetMetricInternal(kCpuTimeNameHash, value);
    return *this;
}

const char PageLoad::kDayOfWeekName[] = "DayOfWeek";
const uint64_t PageLoad::kDayOfWeekNameHash;

PageLoad& PageLoad::SetDayOfWeek(int64_t value)
{
    SetMetricInternal(kDayOfWeekNameHash, value);
    return *this;
}

const char PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredName[] = "DocumentTiming.NavigationToDOMContentLoadedEventFired";
const uint64_t PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash;

PageLoad& PageLoad::SetDocumentTiming_NavigationToDOMContentLoadedEventFired(int64_t value)
{
    SetMetricInternal(kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash, value);
    return *this;
}

const char PageLoad::kDocumentTiming_NavigationToLoadEventFiredName[] = "DocumentTiming.NavigationToLoadEventFired";
const uint64_t PageLoad::kDocumentTiming_NavigationToLoadEventFiredNameHash;

PageLoad& PageLoad::SetDocumentTiming_NavigationToLoadEventFired(int64_t value)
{
    SetMetricInternal(kDocumentTiming_NavigationToLoadEventFiredNameHash, value);
    return *this;
}

const char PageLoad::kDurationSinceLastVisitSecondsName[] = "DurationSinceLastVisitSeconds";
const uint64_t PageLoad::kDurationSinceLastVisitSecondsNameHash;

PageLoad& PageLoad::SetDurationSinceLastVisitSeconds(int64_t value)
{
    SetMetricInternal(kDurationSinceLastVisitSecondsNameHash, value);
    return *this;
}

const char PageLoad::kExperimental_InputToNavigationStartName[] = "Experimental.InputToNavigationStart";
const uint64_t PageLoad::kExperimental_InputToNavigationStartNameHash;

PageLoad& PageLoad::SetExperimental_InputToNavigationStart(int64_t value)
{
    SetMetricInternal(kExperimental_InputToNavigationStartNameHash, value);
    return *this;
}

const char PageLoad::kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenName[] = "Experimental.LayoutInstability.CumulativeShiftScoreAtFirstOnHidden";
const uint64_t PageLoad::kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenNameHash;

PageLoad& PageLoad::SetExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHidden(int64_t value)
{
    SetMetricInternal(kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenNameHash, value);
    return *this;
}

const char PageLoad::kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msName[]
    = "Experimental.LayoutInstability.MaxCumulativeShiftScoreAtFirstOnHidden.SessionWindow.Gap1000ms.Max5000ms";
const uint64_t PageLoad::kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msNameHash;

PageLoad& PageLoad::SetExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000ms(int64_t value)
{
    SetMetricInternal(kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msNameHash, value);
    return *this;
}

const char PageLoad::kExperimental_Navigation_UserInitiatedName[] = "Experimental.Navigation.UserInitiated";
const uint64_t PageLoad::kExperimental_Navigation_UserInitiatedNameHash;

PageLoad& PageLoad::SetExperimental_Navigation_UserInitiated(int64_t value)
{
    SetMetricInternal(kExperimental_Navigation_UserInitiatedNameHash, value);
    return *this;
}

const char PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintName[] = "Experimental.PaintTiming.NavigationToFirstMeaningfulPaint";
const uint64_t PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash;

PageLoad& PageLoad::SetExperimental_PaintTiming_NavigationToFirstMeaningfulPaint(int64_t value)
{
    SetMetricInternal(kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash, value);
    return *this;
}

const char PageLoad::kHourOfDayName[] = "HourOfDay";
const uint64_t PageLoad::kHourOfDayNameHash;

PageLoad& PageLoad::SetHourOfDay(int64_t value)
{
    SetMetricInternal(kHourOfDayNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationName[]
    = "InteractiveTiming.AverageUserInteractionLatencyOverBudget.MaxEventDuration";
const uint64_t PageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationNameHash;

PageLoad& PageLoad::SetInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_FirstInputDelay4Name[] = "InteractiveTiming.FirstInputDelay4";
const uint64_t PageLoad::kInteractiveTiming_FirstInputDelay4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstInputDelay4(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_FirstInputDelay4NameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_FirstInputProcessingTimesName[] = "InteractiveTiming.FirstInputProcessingTimes";
const uint64_t PageLoad::kInteractiveTiming_FirstInputProcessingTimesNameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstInputProcessingTimes(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_FirstInputProcessingTimesNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_FirstInputTimestamp4Name[] = "InteractiveTiming.FirstInputTimestamp4";
const uint64_t PageLoad::kInteractiveTiming_FirstInputTimestamp4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstInputTimestamp4(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_FirstInputTimestamp4NameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_FirstScrollDelayName[] = "InteractiveTiming.FirstScrollDelay";
const uint64_t PageLoad::kInteractiveTiming_FirstScrollDelayNameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstScrollDelay(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_FirstScrollDelayNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_FirstScrollTimestampName[] = "InteractiveTiming.FirstScrollTimestamp";
const uint64_t PageLoad::kInteractiveTiming_FirstScrollTimestampNameHash;

PageLoad& PageLoad::SetInteractiveTiming_FirstScrollTimestamp(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_FirstScrollTimestampNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_LongestInputDelay4Name[] = "InteractiveTiming.LongestInputDelay4";
const uint64_t PageLoad::kInteractiveTiming_LongestInputDelay4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_LongestInputDelay4(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_LongestInputDelay4NameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_LongestInputTimestamp4Name[] = "InteractiveTiming.LongestInputTimestamp4";
const uint64_t PageLoad::kInteractiveTiming_LongestInputTimestamp4NameHash;

PageLoad& PageLoad::SetInteractiveTiming_LongestInputTimestamp4(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_LongestInputTimestamp4NameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_NumInputEventsName[] = "InteractiveTiming.NumInputEvents";
const uint64_t PageLoad::kInteractiveTiming_NumInputEventsNameHash;

PageLoad& PageLoad::SetInteractiveTiming_NumInputEvents(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_NumInputEventsNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_NumInteractionsName[] = "InteractiveTiming.NumInteractions";
const uint64_t PageLoad::kInteractiveTiming_NumInteractionsNameHash;

PageLoad& PageLoad::SetInteractiveTiming_NumInteractions(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_NumInteractionsNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDurationName[]
    = "InteractiveTiming.SlowUserInteractionLatencyOverBudget.HighPercentile2.MaxEventDuration";
const uint64_t PageLoad::kInteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDurationNameHash;

PageLoad& PageLoad::SetInteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDurationNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDurationName[] = "InteractiveTiming.SumOfUserInteractionLatencyOverBudget.MaxEventDuration";
const uint64_t PageLoad::kInteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDurationNameHash;

PageLoad& PageLoad::SetInteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDurationNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_TotalAdjustedInputDelayName[] = "InteractiveTiming.TotalAdjustedInputDelay";
const uint64_t PageLoad::kInteractiveTiming_TotalAdjustedInputDelayNameHash;

PageLoad& PageLoad::SetInteractiveTiming_TotalAdjustedInputDelay(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_TotalAdjustedInputDelayNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_TotalInputDelayName[] = "InteractiveTiming.TotalInputDelay";
const uint64_t PageLoad::kInteractiveTiming_TotalInputDelayNameHash;

PageLoad& PageLoad::SetInteractiveTiming_TotalInputDelay(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_TotalInputDelayNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[] = "InteractiveTiming.UserInteractionLatency.HighPercentile2.MaxEventDuration";
const uint64_t PageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash;

PageLoad& PageLoad::SetInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationName[]
    = "InteractiveTiming.UserInteractionLatencyAtFirstOnHidden.HighPercentile2.MaxEventDuration";
const uint64_t PageLoad::kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationNameHash;

PageLoad& PageLoad::SetInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationNameHash, value);
    return *this;
}

const char PageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName[] = "InteractiveTiming.WorstUserInteractionLatency.MaxEventDuration";
const uint64_t PageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash;

PageLoad& PageLoad::SetInteractiveTiming_WorstUserInteractionLatency_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash, value);
    return *this;
}

const char PageLoad::kIsCrossProcessNavigationName[] = "IsCrossProcessNavigation";
const uint64_t PageLoad::kIsCrossProcessNavigationNameHash;

PageLoad& PageLoad::SetIsCrossProcessNavigation(int64_t value)
{
    SetMetricInternal(kIsCrossProcessNavigationNameHash, value);
    return *this;
}

const char PageLoad::kIsExistingBookmarkName[] = "IsExistingBookmark";
const uint64_t PageLoad::kIsExistingBookmarkNameHash;

PageLoad& PageLoad::SetIsExistingBookmark(int64_t value)
{
    SetMetricInternal(kIsExistingBookmarkNameHash, value);
    return *this;
}

const char PageLoad::kIsExistingPartOfTabGroupName[] = "IsExistingPartOfTabGroup";
const uint64_t PageLoad::kIsExistingPartOfTabGroupNameHash;

PageLoad& PageLoad::SetIsExistingPartOfTabGroup(int64_t value)
{
    SetMetricInternal(kIsExistingPartOfTabGroupNameHash, value);
    return *this;
}

const char PageLoad::kIsNewBookmarkName[] = "IsNewBookmark";
const uint64_t PageLoad::kIsNewBookmarkNameHash;

PageLoad& PageLoad::SetIsNewBookmark(int64_t value)
{
    SetMetricInternal(kIsNewBookmarkNameHash, value);
    return *this;
}

const char PageLoad::kIsNTPCustomLinkName[] = "IsNTPCustomLink";
const uint64_t PageLoad::kIsNTPCustomLinkNameHash;

PageLoad& PageLoad::SetIsNTPCustomLink(int64_t value)
{
    SetMetricInternal(kIsNTPCustomLinkNameHash, value);
    return *this;
}

const char PageLoad::kIsPlacedInTabGroupName[] = "IsPlacedInTabGroup";
const uint64_t PageLoad::kIsPlacedInTabGroupNameHash;

PageLoad& PageLoad::SetIsPlacedInTabGroup(int64_t value)
{
    SetMetricInternal(kIsPlacedInTabGroupNameHash, value);
    return *this;
}

const char PageLoad::kIsScopedSearchLikeNavigationName[] = "IsScopedSearchLikeNavigation";
const uint64_t PageLoad::kIsScopedSearchLikeNavigationNameHash;

PageLoad& PageLoad::SetIsScopedSearchLikeNavigation(int64_t value)
{
    SetMetricInternal(kIsScopedSearchLikeNavigationNameHash, value);
    return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScoreName[] = "LayoutInstability.CumulativeShiftScore";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScoreNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore(int64_t value)
{
    SetMetricInternal(kLayoutInstability_CumulativeShiftScoreNameHash, value);
    return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName[] = "LayoutInstability.CumulativeShiftScore.BeforeInputOrScroll";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore_BeforeInputOrScroll(int64_t value)
{
    SetMetricInternal(kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash, value);
    return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameName[] = "LayoutInstability.CumulativeShiftScore.MainFrame";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore_MainFrame(int64_t value)
{
    SetMetricInternal(kLayoutInstability_CumulativeShiftScore_MainFrameNameHash, value);
    return *this;
}

const char PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName[] = "LayoutInstability.CumulativeShiftScore.MainFrame.BeforeInputOrScroll";
const uint64_t PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash;

PageLoad& PageLoad::SetLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScroll(int64_t value)
{
    SetMetricInternal(kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash, value);
    return *this;
}

const char PageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[]
    = "LayoutInstability.MaxCumulativeShiftScore.SessionWindow.Gap1000ms.Max5000ms";
const uint64_t PageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash;

PageLoad& PageLoad::SetLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value)
{
    SetMetricInternal(kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash, value);
    return *this;
}

const char PageLoad::kMainDocumentSequenceNumberName[] = "MainDocumentSequenceNumber";
const uint64_t PageLoad::kMainDocumentSequenceNumberNameHash;

PageLoad& PageLoad::SetMainDocumentSequenceNumber(int64_t value)
{
    SetMetricInternal(kMainDocumentSequenceNumberNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_ConnectDelayName[] = "MainFrameResource.ConnectDelay";
const uint64_t PageLoad::kMainFrameResource_ConnectDelayNameHash;

PageLoad& PageLoad::SetMainFrameResource_ConnectDelay(int64_t value)
{
    SetMetricInternal(kMainFrameResource_ConnectDelayNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_DNSDelayName[] = "MainFrameResource.DNSDelay";
const uint64_t PageLoad::kMainFrameResource_DNSDelayNameHash;

PageLoad& PageLoad::SetMainFrameResource_DNSDelay(int64_t value)
{
    SetMetricInternal(kMainFrameResource_DNSDelayNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_HttpProtocolSchemeName[] = "MainFrameResource.HttpProtocolScheme";
const uint64_t PageLoad::kMainFrameResource_HttpProtocolSchemeNameHash;

PageLoad& PageLoad::SetMainFrameResource_HttpProtocolScheme(int64_t value)
{
    SetMetricInternal(kMainFrameResource_HttpProtocolSchemeNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartName[] = "MainFrameResource.NavigationStartToReceiveHeadersStart";
const uint64_t PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash;

PageLoad& PageLoad::SetMainFrameResource_NavigationStartToReceiveHeadersStart(int64_t value)
{
    SetMetricInternal(kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_NavigationStartToRequestStartName[] = "MainFrameResource.NavigationStartToRequestStart";
const uint64_t PageLoad::kMainFrameResource_NavigationStartToRequestStartNameHash;

PageLoad& PageLoad::SetMainFrameResource_NavigationStartToRequestStart(int64_t value)
{
    SetMetricInternal(kMainFrameResource_NavigationStartToRequestStartNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_RedirectCountName[] = "MainFrameResource.RedirectCount";
const uint64_t PageLoad::kMainFrameResource_RedirectCountNameHash;

PageLoad& PageLoad::SetMainFrameResource_RedirectCount(int64_t value)
{
    SetMetricInternal(kMainFrameResource_RedirectCountNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_RequestHadCookiesName[] = "MainFrameResource.RequestHadCookies";
const uint64_t PageLoad::kMainFrameResource_RequestHadCookiesNameHash;

PageLoad& PageLoad::SetMainFrameResource_RequestHadCookies(int64_t value)
{
    SetMetricInternal(kMainFrameResource_RequestHadCookiesNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndName[] = "MainFrameResource.RequestStartToReceiveHeadersEnd";
const uint64_t PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndNameHash;

PageLoad& PageLoad::SetMainFrameResource_RequestStartToReceiveHeadersEnd(int64_t value)
{
    SetMetricInternal(kMainFrameResource_RequestStartToReceiveHeadersEndNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_RequestStartToSendStartName[] = "MainFrameResource.RequestStartToSendStart";
const uint64_t PageLoad::kMainFrameResource_RequestStartToSendStartNameHash;

PageLoad& PageLoad::SetMainFrameResource_RequestStartToSendStart(int64_t value)
{
    SetMetricInternal(kMainFrameResource_RequestStartToSendStartNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndName[] = "MainFrameResource.SendStartToReceiveHeadersEnd";
const uint64_t PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndNameHash;

PageLoad& PageLoad::SetMainFrameResource_SendStartToReceiveHeadersEnd(int64_t value)
{
    SetMetricInternal(kMainFrameResource_SendStartToReceiveHeadersEndNameHash, value);
    return *this;
}

const char PageLoad::kMainFrameResource_SocketReusedName[] = "MainFrameResource.SocketReused";
const uint64_t PageLoad::kMainFrameResource_SocketReusedNameHash;

PageLoad& PageLoad::SetMainFrameResource_SocketReused(int64_t value)
{
    SetMetricInternal(kMainFrameResource_SocketReusedNameHash, value);
    return *this;
}

const char PageLoad::kNavigation_PageEndReason3Name[] = "Navigation.PageEndReason3";
const uint64_t PageLoad::kNavigation_PageEndReason3NameHash;

PageLoad& PageLoad::SetNavigation_PageEndReason3(int64_t value)
{
    SetMetricInternal(kNavigation_PageEndReason3NameHash, value);
    return *this;
}

const char PageLoad::kNavigation_PageTransitionName[] = "Navigation.PageTransition";
const uint64_t PageLoad::kNavigation_PageTransitionNameHash;

PageLoad& PageLoad::SetNavigation_PageTransition(int64_t value)
{
    SetMetricInternal(kNavigation_PageTransitionNameHash, value);
    return *this;
}

const char PageLoad::kNavigationEntryOffsetName[] = "NavigationEntryOffset";
const uint64_t PageLoad::kNavigationEntryOffsetNameHash;

PageLoad& PageLoad::SetNavigationEntryOffset(int64_t value)
{
    SetMetricInternal(kNavigationEntryOffsetNameHash, value);
    return *this;
}

const char PageLoad::kNet_CacheBytes2Name[] = "Net.CacheBytes2";
const uint64_t PageLoad::kNet_CacheBytes2NameHash;

PageLoad& PageLoad::SetNet_CacheBytes2(int64_t value)
{
    SetMetricInternal(kNet_CacheBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartName[] = "Net.DownstreamKbpsEstimate.OnNavigationStart";
const uint64_t PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_DownstreamKbpsEstimate_OnNavigationStart(int64_t value)
{
    SetMetricInternal(kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash, value);
    return *this;
}

const char PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartName[] = "Net.EffectiveConnectionType2.OnNavigationStart";
const uint64_t PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_EffectiveConnectionType2_OnNavigationStart(int64_t value)
{
    SetMetricInternal(kNet_EffectiveConnectionType2_OnNavigationStartNameHash, value);
    return *this;
}

const char PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadName[] = "Net.ErrorCode.OnFailedProvisionalLoad";
const uint64_t PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadNameHash;

PageLoad& PageLoad::SetNet_ErrorCode_OnFailedProvisionalLoad(int64_t value)
{
    SetMetricInternal(kNet_ErrorCode_OnFailedProvisionalLoadNameHash, value);
    return *this;
}

const char PageLoad::kNet_HttpResponseCodeName[] = "Net.HttpResponseCode";
const uint64_t PageLoad::kNet_HttpResponseCodeNameHash;

PageLoad& PageLoad::SetNet_HttpResponseCode(int64_t value)
{
    SetMetricInternal(kNet_HttpResponseCodeNameHash, value);
    return *this;
}

const char PageLoad::kNet_HttpRttEstimate_OnNavigationStartName[] = "Net.HttpRttEstimate.OnNavigationStart";
const uint64_t PageLoad::kNet_HttpRttEstimate_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_HttpRttEstimate_OnNavigationStart(int64_t value)
{
    SetMetricInternal(kNet_HttpRttEstimate_OnNavigationStartNameHash, value);
    return *this;
}

const char PageLoad::kNet_ImageBytes2Name[] = "Net.ImageBytes2";
const uint64_t PageLoad::kNet_ImageBytes2NameHash;

PageLoad& PageLoad::SetNet_ImageBytes2(int64_t value)
{
    SetMetricInternal(kNet_ImageBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_ImageSubframeBytes2Name[] = "Net.ImageSubframeBytes2";
const uint64_t PageLoad::kNet_ImageSubframeBytes2NameHash;

PageLoad& PageLoad::SetNet_ImageSubframeBytes2(int64_t value)
{
    SetMetricInternal(kNet_ImageSubframeBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_JavaScriptBytes2Name[] = "Net.JavaScriptBytes2";
const uint64_t PageLoad::kNet_JavaScriptBytes2NameHash;

PageLoad& PageLoad::SetNet_JavaScriptBytes2(int64_t value)
{
    SetMetricInternal(kNet_JavaScriptBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_JavaScriptMaxBytes2Name[] = "Net.JavaScriptMaxBytes2";
const uint64_t PageLoad::kNet_JavaScriptMaxBytes2NameHash;

PageLoad& PageLoad::SetNet_JavaScriptMaxBytes2(int64_t value)
{
    SetMetricInternal(kNet_JavaScriptMaxBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_MediaBytes2Name[] = "Net.MediaBytes2";
const uint64_t PageLoad::kNet_MediaBytes2NameHash;

PageLoad& PageLoad::SetNet_MediaBytes2(int64_t value)
{
    SetMetricInternal(kNet_MediaBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_NetworkBytes2Name[] = "Net.NetworkBytes2";
const uint64_t PageLoad::kNet_NetworkBytes2NameHash;

PageLoad& PageLoad::SetNet_NetworkBytes2(int64_t value)
{
    SetMetricInternal(kNet_NetworkBytes2NameHash, value);
    return *this;
}

const char PageLoad::kNet_TransportRttEstimate_OnNavigationStartName[] = "Net.TransportRttEstimate.OnNavigationStart";
const uint64_t PageLoad::kNet_TransportRttEstimate_OnNavigationStartNameHash;

PageLoad& PageLoad::SetNet_TransportRttEstimate_OnNavigationStart(int64_t value)
{
    SetMetricInternal(kNet_TransportRttEstimate_OnNavigationStartNameHash, value);
    return *this;
}

const char PageLoad::kOmniboxUrlCopiedName[] = "OmniboxUrlCopied";
const uint64_t PageLoad::kOmniboxUrlCopiedNameHash;

PageLoad& PageLoad::SetOmniboxUrlCopied(int64_t value)
{
    SetMetricInternal(kOmniboxUrlCopiedNameHash, value);
    return *this;
}

const char PageLoad::kPageTiming_ForegroundDurationName[] = "PageTiming.ForegroundDuration";
const uint64_t PageLoad::kPageTiming_ForegroundDurationNameHash;

PageLoad& PageLoad::SetPageTiming_ForegroundDuration(int64_t value)
{
    SetMetricInternal(kPageTiming_ForegroundDurationNameHash, value);
    return *this;
}

const char PageLoad::kPageTiming_NavigationToFailedProvisionalLoadName[] = "PageTiming.NavigationToFailedProvisionalLoad";
const uint64_t PageLoad::kPageTiming_NavigationToFailedProvisionalLoadNameHash;

PageLoad& PageLoad::SetPageTiming_NavigationToFailedProvisionalLoad(int64_t value)
{
    SetMetricInternal(kPageTiming_NavigationToFailedProvisionalLoadNameHash, value);
    return *this;
}

const char PageLoad::kPageTiming_TotalForegroundDurationName[] = "PageTiming.TotalForegroundDuration";
const uint64_t PageLoad::kPageTiming_TotalForegroundDurationNameHash;

PageLoad& PageLoad::SetPageTiming_TotalForegroundDuration(int64_t value)
{
    SetMetricInternal(kPageTiming_TotalForegroundDurationNameHash, value);
    return *this;
}

const char PageLoad::kPageTiming_UserTimingMarkFullyLoadedName[] = "PageTiming.UserTimingMarkFullyLoaded";
const uint64_t PageLoad::kPageTiming_UserTimingMarkFullyLoadedNameHash;

PageLoad& PageLoad::SetPageTiming_UserTimingMarkFullyLoaded(int64_t value)
{
    SetMetricInternal(kPageTiming_UserTimingMarkFullyLoadedNameHash, value);
    return *this;
}

const char PageLoad::kPageTiming_UserTimingMarkFullyVisibleName[] = "PageTiming.UserTimingMarkFullyVisible";
const uint64_t PageLoad::kPageTiming_UserTimingMarkFullyVisibleNameHash;

PageLoad& PageLoad::SetPageTiming_UserTimingMarkFullyVisible(int64_t value)
{
    SetMetricInternal(kPageTiming_UserTimingMarkFullyVisibleNameHash, value);
    return *this;
}

const char PageLoad::kPageTiming_UserTimingMarkInteractiveName[] = "PageTiming.UserTimingMarkInteractive";
const uint64_t PageLoad::kPageTiming_UserTimingMarkInteractiveNameHash;

PageLoad& PageLoad::SetPageTiming_UserTimingMarkInteractive(int64_t value)
{
    SetMetricInternal(kPageTiming_UserTimingMarkInteractiveNameHash, value);
    return *this;
}

const char PageLoad::kPageVisitFinalStatusName[] = "PageVisitFinalStatus";
const uint64_t PageLoad::kPageVisitFinalStatusNameHash;

PageLoad& PageLoad::SetPageVisitFinalStatus(int64_t value)
{
    SetMetricInternal(kPageVisitFinalStatusNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_LargestContentfulPaintBPPName[] = "PaintTiming.LargestContentfulPaintBPP";
const uint64_t PageLoad::kPaintTiming_LargestContentfulPaintBPPNameHash;

PageLoad& PageLoad::SetPaintTiming_LargestContentfulPaintBPP(int64_t value)
{
    SetMetricInternal(kPaintTiming_LargestContentfulPaintBPPNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_LargestContentfulPaintTypeName[] = "PaintTiming.LargestContentfulPaintType";
const uint64_t PageLoad::kPaintTiming_LargestContentfulPaintTypeNameHash;

PageLoad& PageLoad::SetPaintTiming_LargestContentfulPaintType(int64_t value)
{
    SetMetricInternal(kPaintTiming_LargestContentfulPaintTypeNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_NavigationToFirstContentfulPaintName[] = "PaintTiming.NavigationToFirstContentfulPaint";
const uint64_t PageLoad::kPaintTiming_NavigationToFirstContentfulPaintNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToFirstContentfulPaint(int64_t value)
{
    SetMetricInternal(kPaintTiming_NavigationToFirstContentfulPaintNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_NavigationToFirstPaintName[] = "PaintTiming.NavigationToFirstPaint";
const uint64_t PageLoad::kPaintTiming_NavigationToFirstPaintNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToFirstPaint(int64_t value)
{
    SetMetricInternal(kPaintTiming_NavigationToFirstPaintNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2Name[] = "PaintTiming.NavigationToLargestContentfulPaint2";
const uint64_t PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2NameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToLargestContentfulPaint2(int64_t value)
{
    SetMetricInternal(kPaintTiming_NavigationToLargestContentfulPaint2NameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameName[] = "PaintTiming.NavigationToLargestContentfulPaint2.CrossSiteSubFrame";
const uint64_t PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrame(int64_t value)
{
    SetMetricInternal(kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameName[] = "PaintTiming.NavigationToLargestContentfulPaint2.MainFrame";
const uint64_t PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToLargestContentfulPaint2_MainFrame(int64_t value)
{
    SetMetricInternal(kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameNameHash, value);
    return *this;
}

const char PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenName[] = "PaintTiming.NavigationToLargestContentfulPaint2AtFirstOnHidden";
const uint64_t PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenNameHash;

PageLoad& PageLoad::SetPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHidden(int64_t value)
{
    SetMetricInternal(kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenNameHash, value);
    return *this;
}

const char PageLoad::kParseTiming_NavigationToParseStartName[] = "ParseTiming.NavigationToParseStart";
const uint64_t PageLoad::kParseTiming_NavigationToParseStartNameHash;

PageLoad& PageLoad::SetParseTiming_NavigationToParseStart(int64_t value)
{
    SetMetricInternal(kParseTiming_NavigationToParseStartNameHash, value);
    return *this;
}

const char PageLoad::kRefreshRateThrottledName[] = "RefreshRateThrottled";
const uint64_t PageLoad::kRefreshRateThrottledNameHash;

PageLoad& PageLoad::SetRefreshRateThrottled(int64_t value)
{
    SetMetricInternal(kRefreshRateThrottledNameHash, value);
    return *this;
}

const char PageLoad::kSiteEngagementScoreName[] = "SiteEngagementScore";
const uint64_t PageLoad::kSiteEngagementScoreNameHash;

PageLoad& PageLoad::SetSiteEngagementScore(int64_t value)
{
    SetMetricInternal(kSiteEngagementScoreNameHash, value);
    return *this;
}

const char PageLoad::kSiteInstanceRenderProcessAssignmentName[] = "SiteInstanceRenderProcessAssignment";
const uint64_t PageLoad::kSiteInstanceRenderProcessAssignmentNameHash;

PageLoad& PageLoad::SetSiteInstanceRenderProcessAssignment(int64_t value)
{
    SetMetricInternal(kSiteInstanceRenderProcessAssignmentNameHash, value);
    return *this;
}

const char PageLoad::kSoftNavigationCountName[] = "SoftNavigationCount";
const uint64_t PageLoad::kSoftNavigationCountNameHash;

PageLoad& PageLoad::SetSoftNavigationCount(int64_t value)
{
    SetMetricInternal(kSoftNavigationCountNameHash, value);
    return *this;
}

const char PageLoad::kThirdPartyCookieBlockingEnabledForSiteName[] = "ThirdPartyCookieBlockingEnabledForSite";
const uint64_t PageLoad::kThirdPartyCookieBlockingEnabledForSiteNameHash;

PageLoad& PageLoad::SetThirdPartyCookieBlockingEnabledForSite(int64_t value)
{
    SetMetricInternal(kThirdPartyCookieBlockingEnabledForSiteNameHash, value);
    return *this;
}

const char PageLoad::kWasCachedName[] = "WasCached";
const uint64_t PageLoad::kWasCachedNameHash;

PageLoad& PageLoad::SetWasCached(int64_t value)
{
    SetMetricInternal(kWasCachedNameHash, value);
    return *this;
}

const char PageLoad::kWasDiscardedName[] = "WasDiscarded";
const uint64_t PageLoad::kWasDiscardedNameHash;

PageLoad& PageLoad::SetWasDiscarded(int64_t value)
{
    SetMetricInternal(kWasDiscardedNameHash, value);
    return *this;
}
const char PageLoad_FromGoogleSearch::kEntryName[] = "PageLoad.FromGoogleSearch";
const uint64_t PageLoad_FromGoogleSearch::kEntryNameHash;

PageLoad_FromGoogleSearch::PageLoad_FromGoogleSearch(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_FromGoogleSearch::PageLoad_FromGoogleSearch(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_FromGoogleSearch::~PageLoad_FromGoogleSearch() = default;
const char PageLoad_FromGoogleSearch::kGoogleSearchModeName[] = "GoogleSearchMode";
const uint64_t PageLoad_FromGoogleSearch::kGoogleSearchModeNameHash;

PageLoad_FromGoogleSearch& PageLoad_FromGoogleSearch::SetGoogleSearchMode(int64_t value)
{
    SetMetricInternal(kGoogleSearchModeNameHash, value);
    return *this;
}
const char PageLoad_Internal::kEntryName[] = "PageLoad.Internal";
const uint64_t PageLoad_Internal::kEntryNameHash;

PageLoad_Internal::PageLoad_Internal(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_Internal::PageLoad_Internal(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_Internal::~PageLoad_Internal() = default;
const char PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeName[] = "PaintTiming.LargestContentfulPaint.ContentType";
const uint64_t PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeNameHash;

PageLoad_Internal& PageLoad_Internal::SetPaintTiming_LargestContentfulPaint_ContentType(int64_t value)
{
    SetMetricInternal(kPaintTiming_LargestContentfulPaint_ContentTypeNameHash, value);
    return *this;
}

const char PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateName[] = "PaintTiming.LargestContentfulPaint.TerminationState";
const uint64_t PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateNameHash;

PageLoad_Internal& PageLoad_Internal::SetPaintTiming_LargestContentfulPaint_TerminationState(int64_t value)
{
    SetMetricInternal(kPaintTiming_LargestContentfulPaint_TerminationStateNameHash, value);
    return *this;
}
const char PageLoad_ServiceWorkerControlled::kEntryName[] = "PageLoad.ServiceWorkerControlled";
const uint64_t PageLoad_ServiceWorkerControlled::kEntryNameHash;

PageLoad_ServiceWorkerControlled::PageLoad_ServiceWorkerControlled(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_ServiceWorkerControlled::PageLoad_ServiceWorkerControlled(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_ServiceWorkerControlled::~PageLoad_ServiceWorkerControlled() = default;

const char PageLoad_SignedExchange::kEntryName[] = "PageLoad.SignedExchange";
const uint64_t PageLoad_SignedExchange::kEntryNameHash;

PageLoad_SignedExchange::PageLoad_SignedExchange(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_SignedExchange::PageLoad_SignedExchange(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageLoad_SignedExchange::~PageLoad_SignedExchange() = default;
const char PageLoad_SignedExchange::kServedFromGoogleCacheName[] = "ServedFromGoogleCache";
const uint64_t PageLoad_SignedExchange::kServedFromGoogleCacheNameHash;

PageLoad_SignedExchange& PageLoad_SignedExchange::SetServedFromGoogleCache(int64_t value)
{
    SetMetricInternal(kServedFromGoogleCacheNameHash, value);
    return *this;
}
const char PageWithPassword::kEntryName[] = "PageWithPassword";
const uint64_t PageWithPassword::kEntryNameHash;

PageWithPassword::PageWithPassword(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageWithPassword::PageWithPassword(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PageWithPassword::~PageWithPassword() = default;
const char PageWithPassword::kFormManagerAvailableName[] = "FormManagerAvailable";
const uint64_t PageWithPassword::kFormManagerAvailableNameHash;

PageWithPassword& PageWithPassword::SetFormManagerAvailable(int64_t value)
{
    SetMetricInternal(kFormManagerAvailableNameHash, value);
    return *this;
}

const char PageWithPassword::kPageLevelUserActionName[] = "PageLevelUserAction";
const uint64_t PageWithPassword::kPageLevelUserActionNameHash;

PageWithPassword& PageWithPassword::SetPageLevelUserAction(int64_t value)
{
    SetMetricInternal(kPageLevelUserActionNameHash, value);
    return *this;
}

const char PageWithPassword::kProvisionalSaveFailureName[] = "ProvisionalSaveFailure";
const uint64_t PageWithPassword::kProvisionalSaveFailureNameHash;

PageWithPassword& PageWithPassword::SetProvisionalSaveFailure(int64_t value)
{
    SetMetricInternal(kProvisionalSaveFailureNameHash, value);
    return *this;
}

const char PageWithPassword::kUserModifiedPasswordFieldName[] = "UserModifiedPasswordField";
const uint64_t PageWithPassword::kUserModifiedPasswordFieldNameHash;

PageWithPassword& PageWithPassword::SetUserModifiedPasswordField(int64_t value)
{
    SetMetricInternal(kUserModifiedPasswordFieldNameHash, value);
    return *this;
}
const char PaintPreviewCapture::kEntryName[] = "PaintPreviewCapture";
const uint64_t PaintPreviewCapture::kEntryNameHash;

PaintPreviewCapture::PaintPreviewCapture(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaintPreviewCapture::PaintPreviewCapture(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaintPreviewCapture::~PaintPreviewCapture() = default;
const char PaintPreviewCapture::kBlinkCaptureTimeName[] = "BlinkCaptureTime";
const uint64_t PaintPreviewCapture::kBlinkCaptureTimeNameHash;

PaintPreviewCapture& PaintPreviewCapture::SetBlinkCaptureTime(int64_t value)
{
    SetMetricInternal(kBlinkCaptureTimeNameHash, value);
    return *this;
}

const char PaintPreviewCapture::kCompressedOnDiskSizeName[] = "CompressedOnDiskSize";
const uint64_t PaintPreviewCapture::kCompressedOnDiskSizeNameHash;

PaintPreviewCapture& PaintPreviewCapture::SetCompressedOnDiskSize(int64_t value)
{
    SetMetricInternal(kCompressedOnDiskSizeNameHash, value);
    return *this;
}
const char PasswordForm::kEntryName[] = "PasswordForm";
const uint64_t PasswordForm::kEntryNameHash;

PasswordForm::PasswordForm(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordForm::PasswordForm(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordForm::~PasswordForm() = default;
const char PasswordForm::kContext_FormSignatureName[] = "Context.FormSignature";
const uint64_t PasswordForm::kContext_FormSignatureNameHash;

PasswordForm& PasswordForm::SetContext_FormSignature(int64_t value)
{
    SetMetricInternal(kContext_FormSignatureNameHash, value);
    return *this;
}

const char PasswordForm::kDynamicFormChangesName[] = "DynamicFormChanges";
const uint64_t PasswordForm::kDynamicFormChangesNameHash;

PasswordForm& PasswordForm::SetDynamicFormChanges(int64_t value)
{
    SetMetricInternal(kDynamicFormChangesNameHash, value);
    return *this;
}

const char PasswordForm::kFill_FirstFillingResultInRendererName[] = "Fill.FirstFillingResultInRenderer";
const uint64_t PasswordForm::kFill_FirstFillingResultInRendererNameHash;

PasswordForm& PasswordForm::SetFill_FirstFillingResultInRenderer(int64_t value)
{
    SetMetricInternal(kFill_FirstFillingResultInRendererNameHash, value);
    return *this;
}

const char PasswordForm::kFill_FirstWaitForUsernameReasonName[] = "Fill.FirstWaitForUsernameReason";
const uint64_t PasswordForm::kFill_FirstWaitForUsernameReasonNameHash;

PasswordForm& PasswordForm::SetFill_FirstWaitForUsernameReason(int64_t value)
{
    SetMetricInternal(kFill_FirstWaitForUsernameReasonNameHash, value);
    return *this;
}

const char PasswordForm::kFillOnLoadName[] = "FillOnLoad";
const uint64_t PasswordForm::kFillOnLoadNameHash;

PasswordForm& PasswordForm::SetFillOnLoad(int64_t value)
{
    SetMetricInternal(kFillOnLoadNameHash, value);
    return *this;
}

const char PasswordForm::kGeneration_GeneratedPasswordName[] = "Generation.GeneratedPassword";
const uint64_t PasswordForm::kGeneration_GeneratedPasswordNameHash;

PasswordForm& PasswordForm::SetGeneration_GeneratedPassword(int64_t value)
{
    SetMetricInternal(kGeneration_GeneratedPasswordNameHash, value);
    return *this;
}

const char PasswordForm::kGeneration_GeneratedPasswordModifiedName[] = "Generation.GeneratedPasswordModified";
const uint64_t PasswordForm::kGeneration_GeneratedPasswordModifiedNameHash;

PasswordForm& PasswordForm::SetGeneration_GeneratedPasswordModified(int64_t value)
{
    SetMetricInternal(kGeneration_GeneratedPasswordModifiedNameHash, value);
    return *this;
}

const char PasswordForm::kGeneration_PopupShownName[] = "Generation.PopupShown";
const uint64_t PasswordForm::kGeneration_PopupShownNameHash;

PasswordForm& PasswordForm::SetGeneration_PopupShown(int64_t value)
{
    SetMetricInternal(kGeneration_PopupShownNameHash, value);
    return *this;
}

const char PasswordForm::kManagerFill_ActionName[] = "ManagerFill.Action";
const uint64_t PasswordForm::kManagerFill_ActionNameHash;

PasswordForm& PasswordForm::SetManagerFill_Action(int64_t value)
{
    SetMetricInternal(kManagerFill_ActionNameHash, value);
    return *this;
}

const char PasswordForm::kManagerFill_AssistanceName[] = "ManagerFill.Assistance";
const uint64_t PasswordForm::kManagerFill_AssistanceNameHash;

PasswordForm& PasswordForm::SetManagerFill_Assistance(int64_t value)
{
    SetMetricInternal(kManagerFill_AssistanceNameHash, value);
    return *this;
}

const char PasswordForm::kReadonlyWhenFillingName[] = "ReadonlyWhenFilling";
const uint64_t PasswordForm::kReadonlyWhenFillingNameHash;

PasswordForm& PasswordForm::SetReadonlyWhenFilling(int64_t value)
{
    SetMetricInternal(kReadonlyWhenFillingNameHash, value);
    return *this;
}

const char PasswordForm::kReadonlyWhenSavingName[] = "ReadonlyWhenSaving";
const uint64_t PasswordForm::kReadonlyWhenSavingNameHash;

PasswordForm& PasswordForm::SetReadonlyWhenSaving(int64_t value)
{
    SetMetricInternal(kReadonlyWhenSavingNameHash, value);
    return *this;
}

const char PasswordForm::kSaving_Prompt_InteractionName[] = "Saving.Prompt.Interaction";
const uint64_t PasswordForm::kSaving_Prompt_InteractionNameHash;

PasswordForm& PasswordForm::SetSaving_Prompt_Interaction(int64_t value)
{
    SetMetricInternal(kSaving_Prompt_InteractionNameHash, value);
    return *this;
}

const char PasswordForm::kSaving_Prompt_ShownName[] = "Saving.Prompt.Shown";
const uint64_t PasswordForm::kSaving_Prompt_ShownNameHash;

PasswordForm& PasswordForm::SetSaving_Prompt_Shown(int64_t value)
{
    SetMetricInternal(kSaving_Prompt_ShownNameHash, value);
    return *this;
}

const char PasswordForm::kSaving_Prompt_TriggerName[] = "Saving.Prompt.Trigger";
const uint64_t PasswordForm::kSaving_Prompt_TriggerNameHash;

PasswordForm& PasswordForm::SetSaving_Prompt_Trigger(int64_t value)
{
    SetMetricInternal(kSaving_Prompt_TriggerNameHash, value);
    return *this;
}

const char PasswordForm::kSaving_ShowedManualFallbackForSavingName[] = "Saving.ShowedManualFallbackForSaving";
const uint64_t PasswordForm::kSaving_ShowedManualFallbackForSavingNameHash;

PasswordForm& PasswordForm::SetSaving_ShowedManualFallbackForSaving(int64_t value)
{
    SetMetricInternal(kSaving_ShowedManualFallbackForSavingNameHash, value);
    return *this;
}

const char PasswordForm::kSubmission_IndicatorName[] = "Submission.Indicator";
const uint64_t PasswordForm::kSubmission_IndicatorNameHash;

PasswordForm& PasswordForm::SetSubmission_Indicator(int64_t value)
{
    SetMetricInternal(kSubmission_IndicatorNameHash, value);
    return *this;
}

const char PasswordForm::kSubmission_ObservedName[] = "Submission.Observed";
const uint64_t PasswordForm::kSubmission_ObservedNameHash;

PasswordForm& PasswordForm::SetSubmission_Observed(int64_t value)
{
    SetMetricInternal(kSubmission_ObservedNameHash, value);
    return *this;
}

const char PasswordForm::kSubmission_SubmissionResultName[] = "Submission.SubmissionResult";
const uint64_t PasswordForm::kSubmission_SubmissionResultNameHash;

PasswordForm& PasswordForm::SetSubmission_SubmissionResult(int64_t value)
{
    SetMetricInternal(kSubmission_SubmissionResultNameHash, value);
    return *this;
}

const char PasswordForm::kSubmission_SubmittedFormTypeName[] = "Submission.SubmittedFormType";
const uint64_t PasswordForm::kSubmission_SubmittedFormTypeNameHash;

PasswordForm& PasswordForm::SetSubmission_SubmittedFormType(int64_t value)
{
    SetMetricInternal(kSubmission_SubmittedFormTypeNameHash, value);
    return *this;
}

const char PasswordForm::kUpdating_Prompt_InteractionName[] = "Updating.Prompt.Interaction";
const uint64_t PasswordForm::kUpdating_Prompt_InteractionNameHash;

PasswordForm& PasswordForm::SetUpdating_Prompt_Interaction(int64_t value)
{
    SetMetricInternal(kUpdating_Prompt_InteractionNameHash, value);
    return *this;
}

const char PasswordForm::kUpdating_Prompt_ShownName[] = "Updating.Prompt.Shown";
const uint64_t PasswordForm::kUpdating_Prompt_ShownNameHash;

PasswordForm& PasswordForm::SetUpdating_Prompt_Shown(int64_t value)
{
    SetMetricInternal(kUpdating_Prompt_ShownNameHash, value);
    return *this;
}

const char PasswordForm::kUpdating_Prompt_TriggerName[] = "Updating.Prompt.Trigger";
const uint64_t PasswordForm::kUpdating_Prompt_TriggerNameHash;

PasswordForm& PasswordForm::SetUpdating_Prompt_Trigger(int64_t value)
{
    SetMetricInternal(kUpdating_Prompt_TriggerNameHash, value);
    return *this;
}

const char PasswordForm::kUser_Action_CorrectedUsernameInFormName[] = "User.Action.CorrectedUsernameInForm";
const uint64_t PasswordForm::kUser_Action_CorrectedUsernameInFormNameHash;

PasswordForm& PasswordForm::SetUser_Action_CorrectedUsernameInForm(int64_t value)
{
    SetMetricInternal(kUser_Action_CorrectedUsernameInFormNameHash, value);
    return *this;
}

const char PasswordForm::kUser_Action_EditedUsernameInBubbleName[] = "User.Action.EditedUsernameInBubble";
const uint64_t PasswordForm::kUser_Action_EditedUsernameInBubbleNameHash;

PasswordForm& PasswordForm::SetUser_Action_EditedUsernameInBubble(int64_t value)
{
    SetMetricInternal(kUser_Action_EditedUsernameInBubbleNameHash, value);
    return *this;
}

const char PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleName[] = "User.Action.SelectedDifferentPasswordInBubble";
const uint64_t PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleNameHash;

PasswordForm& PasswordForm::SetUser_Action_SelectedDifferentPasswordInBubble(int64_t value)
{
    SetMetricInternal(kUser_Action_SelectedDifferentPasswordInBubbleNameHash, value);
    return *this;
}

const char PasswordForm::kUser_Action_TriggeredManualFallbackForSavingName[] = "User.Action.TriggeredManualFallbackForSaving";
const uint64_t PasswordForm::kUser_Action_TriggeredManualFallbackForSavingNameHash;

PasswordForm& PasswordForm::SetUser_Action_TriggeredManualFallbackForSaving(int64_t value)
{
    SetMetricInternal(kUser_Action_TriggeredManualFallbackForSavingNameHash, value);
    return *this;
}
const char PasswordManager_LeakWarningDialog::kEntryName[] = "PasswordManager.LeakWarningDialog";
const uint64_t PasswordManager_LeakWarningDialog::kEntryNameHash;

PasswordManager_LeakWarningDialog::PasswordManager_LeakWarningDialog(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_LeakWarningDialog::PasswordManager_LeakWarningDialog(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_LeakWarningDialog::~PasswordManager_LeakWarningDialog() = default;
const char PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogDismissalReasonName[] = "PasswordLeakDetectionDialogDismissalReason";
const uint64_t PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogDismissalReasonNameHash;

PasswordManager_LeakWarningDialog& PasswordManager_LeakWarningDialog::SetPasswordLeakDetectionDialogDismissalReason(int64_t value)
{
    SetMetricInternal(kPasswordLeakDetectionDialogDismissalReasonNameHash, value);
    return *this;
}

const char PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogTypeName[] = "PasswordLeakDetectionDialogType";
const uint64_t PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogTypeNameHash;

PasswordManager_LeakWarningDialog& PasswordManager_LeakWarningDialog::SetPasswordLeakDetectionDialogType(int64_t value)
{
    SetMetricInternal(kPasswordLeakDetectionDialogTypeNameHash, value);
    return *this;
}
const char PasswordManager_PasswordChangeFlowDuration::kEntryName[] = "PasswordManager.PasswordChangeFlowDuration";
const uint64_t PasswordManager_PasswordChangeFlowDuration::kEntryNameHash;

PasswordManager_PasswordChangeFlowDuration::PasswordManager_PasswordChangeFlowDuration(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_PasswordChangeFlowDuration::PasswordManager_PasswordChangeFlowDuration(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_PasswordChangeFlowDuration::~PasswordManager_PasswordChangeFlowDuration() = default;
const char PasswordManager_PasswordChangeFlowDuration::kDurationName[] = "Duration";
const uint64_t PasswordManager_PasswordChangeFlowDuration::kDurationNameHash;

PasswordManager_PasswordChangeFlowDuration& PasswordManager_PasswordChangeFlowDuration::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char PasswordManager_PasswordChangeFlowDuration::kEndEventName[] = "EndEvent";
const uint64_t PasswordManager_PasswordChangeFlowDuration::kEndEventNameHash;

PasswordManager_PasswordChangeFlowDuration& PasswordManager_PasswordChangeFlowDuration::SetEndEvent(int64_t value)
{
    SetMetricInternal(kEndEventNameHash, value);
    return *this;
}

const char PasswordManager_PasswordChangeFlowDuration::kEntryPointName[] = "EntryPoint";
const uint64_t PasswordManager_PasswordChangeFlowDuration::kEntryPointNameHash;

PasswordManager_PasswordChangeFlowDuration& PasswordManager_PasswordChangeFlowDuration::SetEntryPoint(int64_t value)
{
    SetMetricInternal(kEntryPointNameHash, value);
    return *this;
}

const char PasswordManager_PasswordChangeFlowDuration::kStartEventName[] = "StartEvent";
const uint64_t PasswordManager_PasswordChangeFlowDuration::kStartEventNameHash;

PasswordManager_PasswordChangeFlowDuration& PasswordManager_PasswordChangeFlowDuration::SetStartEvent(int64_t value)
{
    SetMetricInternal(kStartEventNameHash, value);
    return *this;
}
const char PasswordManager_PasswordChangeTriggered::kEntryName[] = "PasswordManager.PasswordChangeTriggered";
const uint64_t PasswordManager_PasswordChangeTriggered::kEntryNameHash;

PasswordManager_PasswordChangeTriggered::PasswordManager_PasswordChangeTriggered(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_PasswordChangeTriggered::PasswordManager_PasswordChangeTriggered(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_PasswordChangeTriggered::~PasswordManager_PasswordChangeTriggered() = default;
const char PasswordManager_PasswordChangeTriggered::kPasswordChangeTypeName[] = "PasswordChangeType";
const uint64_t PasswordManager_PasswordChangeTriggered::kPasswordChangeTypeNameHash;

PasswordManager_PasswordChangeTriggered& PasswordManager_PasswordChangeTriggered::SetPasswordChangeType(int64_t value)
{
    SetMetricInternal(kPasswordChangeTypeNameHash, value);
    return *this;
}
const char PasswordManager_PasswordFillingIOS::kEntryName[] = "PasswordManager.PasswordFillingIOS";
const uint64_t PasswordManager_PasswordFillingIOS::kEntryNameHash;

PasswordManager_PasswordFillingIOS::PasswordManager_PasswordFillingIOS(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_PasswordFillingIOS::PasswordManager_PasswordFillingIOS(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_PasswordFillingIOS::~PasswordManager_PasswordFillingIOS() = default;
const char PasswordManager_PasswordFillingIOS::kFillingSuccessName[] = "FillingSuccess";
const uint64_t PasswordManager_PasswordFillingIOS::kFillingSuccessNameHash;

PasswordManager_PasswordFillingIOS& PasswordManager_PasswordFillingIOS::SetFillingSuccess(int64_t value)
{
    SetMetricInternal(kFillingSuccessNameHash, value);
    return *this;
}
const char PasswordManager_WellKnownChangePasswordResult::kEntryName[] = "PasswordManager.WellKnownChangePasswordResult";
const uint64_t PasswordManager_WellKnownChangePasswordResult::kEntryNameHash;

PasswordManager_WellKnownChangePasswordResult::PasswordManager_WellKnownChangePasswordResult(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_WellKnownChangePasswordResult::PasswordManager_WellKnownChangePasswordResult(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PasswordManager_WellKnownChangePasswordResult::~PasswordManager_WellKnownChangePasswordResult() = default;
const char PasswordManager_WellKnownChangePasswordResult::kWellKnownChangePasswordResultName[] = "WellKnownChangePasswordResult";
const uint64_t PasswordManager_WellKnownChangePasswordResult::kWellKnownChangePasswordResultNameHash;

PasswordManager_WellKnownChangePasswordResult& PasswordManager_WellKnownChangePasswordResult::SetWellKnownChangePasswordResult(int64_t value)
{
    SetMetricInternal(kWellKnownChangePasswordResultNameHash, value);
    return *this;
}
const char PaymentApp_CheckoutEvents::kEntryName[] = "PaymentApp.CheckoutEvents";
const uint64_t PaymentApp_CheckoutEvents::kEntryNameHash;

PaymentApp_CheckoutEvents::PaymentApp_CheckoutEvents(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaymentApp_CheckoutEvents::PaymentApp_CheckoutEvents(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaymentApp_CheckoutEvents::~PaymentApp_CheckoutEvents() = default;
const char PaymentApp_CheckoutEvents::kCompletionStatusName[] = "CompletionStatus";
const uint64_t PaymentApp_CheckoutEvents::kCompletionStatusNameHash;

PaymentApp_CheckoutEvents& PaymentApp_CheckoutEvents::SetCompletionStatus(int64_t value)
{
    SetMetricInternal(kCompletionStatusNameHash, value);
    return *this;
}

const char PaymentApp_CheckoutEvents::kEventsName[] = "Events";
const uint64_t PaymentApp_CheckoutEvents::kEventsNameHash;

PaymentApp_CheckoutEvents& PaymentApp_CheckoutEvents::SetEvents(int64_t value)
{
    SetMetricInternal(kEventsNameHash, value);
    return *this;
}

const char PaymentApp_CheckoutEvents::kEvents2Name[] = "Events2";
const uint64_t PaymentApp_CheckoutEvents::kEvents2NameHash;

PaymentApp_CheckoutEvents& PaymentApp_CheckoutEvents::SetEvents2(int64_t value)
{
    SetMetricInternal(kEvents2NameHash, value);
    return *this;
}
const char PaymentRequest_CheckoutEvents::kEntryName[] = "PaymentRequest.CheckoutEvents";
const uint64_t PaymentRequest_CheckoutEvents::kEntryNameHash;

PaymentRequest_CheckoutEvents::PaymentRequest_CheckoutEvents(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaymentRequest_CheckoutEvents::PaymentRequest_CheckoutEvents(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaymentRequest_CheckoutEvents::~PaymentRequest_CheckoutEvents() = default;
const char PaymentRequest_CheckoutEvents::kCompletionStatusName[] = "CompletionStatus";
const uint64_t PaymentRequest_CheckoutEvents::kCompletionStatusNameHash;

PaymentRequest_CheckoutEvents& PaymentRequest_CheckoutEvents::SetCompletionStatus(int64_t value)
{
    SetMetricInternal(kCompletionStatusNameHash, value);
    return *this;
}

const char PaymentRequest_CheckoutEvents::kEventsName[] = "Events";
const uint64_t PaymentRequest_CheckoutEvents::kEventsNameHash;

PaymentRequest_CheckoutEvents& PaymentRequest_CheckoutEvents::SetEvents(int64_t value)
{
    SetMetricInternal(kEventsNameHash, value);
    return *this;
}

const char PaymentRequest_CheckoutEvents::kEvents2Name[] = "Events2";
const uint64_t PaymentRequest_CheckoutEvents::kEvents2NameHash;

PaymentRequest_CheckoutEvents& PaymentRequest_CheckoutEvents::SetEvents2(int64_t value)
{
    SetMetricInternal(kEvents2NameHash, value);
    return *this;
}
const char PaymentRequest_TransactionAmount::kEntryName[] = "PaymentRequest.TransactionAmount";
const uint64_t PaymentRequest_TransactionAmount::kEntryNameHash;

PaymentRequest_TransactionAmount::PaymentRequest_TransactionAmount(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaymentRequest_TransactionAmount::PaymentRequest_TransactionAmount(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PaymentRequest_TransactionAmount::~PaymentRequest_TransactionAmount() = default;
const char PaymentRequest_TransactionAmount::kCategoryName[] = "Category";
const uint64_t PaymentRequest_TransactionAmount::kCategoryNameHash;

PaymentRequest_TransactionAmount& PaymentRequest_TransactionAmount::SetCategory(int64_t value)
{
    SetMetricInternal(kCategoryNameHash, value);
    return *this;
}

const char PaymentRequest_TransactionAmount::kCompletionStatusName[] = "CompletionStatus";
const uint64_t PaymentRequest_TransactionAmount::kCompletionStatusNameHash;

PaymentRequest_TransactionAmount& PaymentRequest_TransactionAmount::SetCompletionStatus(int64_t value)
{
    SetMetricInternal(kCompletionStatusNameHash, value);
    return *this;
}
const char Pepper_Broker::kEntryName[] = "Pepper.Broker";
const uint64_t Pepper_Broker::kEntryNameHash;

Pepper_Broker::Pepper_Broker(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Pepper_Broker::Pepper_Broker(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Pepper_Broker::~Pepper_Broker() = default;

const char PerformanceAPI_LongTask::kEntryName[] = "PerformanceAPI.LongTask";
const uint64_t PerformanceAPI_LongTask::kEntryNameHash;

PerformanceAPI_LongTask::PerformanceAPI_LongTask(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_LongTask::PerformanceAPI_LongTask(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_LongTask::~PerformanceAPI_LongTask() = default;
const char PerformanceAPI_LongTask::kDurationName[] = "Duration";
const uint64_t PerformanceAPI_LongTask::kDurationNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char PerformanceAPI_LongTask::kDuration_V8_ExecuteName[] = "Duration.V8.Execute";
const uint64_t PerformanceAPI_LongTask::kDuration_V8_ExecuteNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_Execute(int64_t value)
{
    SetMetricInternal(kDuration_V8_ExecuteNameHash, value);
    return *this;
}

const char PerformanceAPI_LongTask::kDuration_V8_GCName[] = "Duration.V8.GC";
const uint64_t PerformanceAPI_LongTask::kDuration_V8_GCNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC(int64_t value)
{
    SetMetricInternal(kDuration_V8_GCNameHash, value);
    return *this;
}

const char PerformanceAPI_LongTask::kDuration_V8_GC_Full_AtomicName[] = "Duration.V8.GC.Full.Atomic";
const uint64_t PerformanceAPI_LongTask::kDuration_V8_GC_Full_AtomicNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC_Full_Atomic(int64_t value)
{
    SetMetricInternal(kDuration_V8_GC_Full_AtomicNameHash, value);
    return *this;
}

const char PerformanceAPI_LongTask::kDuration_V8_GC_Full_IncrementalName[] = "Duration.V8.GC.Full.Incremental";
const uint64_t PerformanceAPI_LongTask::kDuration_V8_GC_Full_IncrementalNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC_Full_Incremental(int64_t value)
{
    SetMetricInternal(kDuration_V8_GC_Full_IncrementalNameHash, value);
    return *this;
}

const char PerformanceAPI_LongTask::kDuration_V8_GC_YoungName[] = "Duration.V8.GC.Young";
const uint64_t PerformanceAPI_LongTask::kDuration_V8_GC_YoungNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetDuration_V8_GC_Young(int64_t value)
{
    SetMetricInternal(kDuration_V8_GC_YoungNameHash, value);
    return *this;
}

const char PerformanceAPI_LongTask::kStartTimeName[] = "StartTime";
const uint64_t PerformanceAPI_LongTask::kStartTimeNameHash;

PerformanceAPI_LongTask& PerformanceAPI_LongTask::SetStartTime(int64_t value)
{
    SetMetricInternal(kStartTimeNameHash, value);
    return *this;
}
const char PerformanceAPI_Memory::kEntryName[] = "PerformanceAPI.Memory";
const uint64_t PerformanceAPI_Memory::kEntryNameHash;

PerformanceAPI_Memory::PerformanceAPI_Memory(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory::PerformanceAPI_Memory(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory::~PerformanceAPI_Memory() = default;
const char PerformanceAPI_Memory::kDomName[] = "Dom";
const uint64_t PerformanceAPI_Memory::kDomNameHash;

PerformanceAPI_Memory& PerformanceAPI_Memory::SetDom(int64_t value)
{
    SetMetricInternal(kDomNameHash, value);
    return *this;
}

const char PerformanceAPI_Memory::kJavaScriptName[] = "JavaScript";
const uint64_t PerformanceAPI_Memory::kJavaScriptNameHash;

PerformanceAPI_Memory& PerformanceAPI_Memory::SetJavaScript(int64_t value)
{
    SetMetricInternal(kJavaScriptNameHash, value);
    return *this;
}

const char PerformanceAPI_Memory::kJavaScript_DedicatedWorkerName[] = "JavaScript.DedicatedWorker";
const uint64_t PerformanceAPI_Memory::kJavaScript_DedicatedWorkerNameHash;

PerformanceAPI_Memory& PerformanceAPI_Memory::SetJavaScript_DedicatedWorker(int64_t value)
{
    SetMetricInternal(kJavaScript_DedicatedWorkerNameHash, value);
    return *this;
}

const char PerformanceAPI_Memory::kSharedName[] = "Shared";
const uint64_t PerformanceAPI_Memory::kSharedNameHash;

PerformanceAPI_Memory& PerformanceAPI_Memory::SetShared(int64_t value)
{
    SetMetricInternal(kSharedNameHash, value);
    return *this;
}
const char PerformanceAPI_Memory_Legacy::kEntryName[] = "PerformanceAPI.Memory.Legacy";
const uint64_t PerformanceAPI_Memory_Legacy::kEntryNameHash;

PerformanceAPI_Memory_Legacy::PerformanceAPI_Memory_Legacy(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory_Legacy::PerformanceAPI_Memory_Legacy(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceAPI_Memory_Legacy::~PerformanceAPI_Memory_Legacy() = default;
const char PerformanceAPI_Memory_Legacy::kJavaScriptName[] = "JavaScript";
const uint64_t PerformanceAPI_Memory_Legacy::kJavaScriptNameHash;

PerformanceAPI_Memory_Legacy& PerformanceAPI_Memory_Legacy::SetJavaScript(int64_t value)
{
    SetMetricInternal(kJavaScriptNameHash, value);
    return *this;
}
const char PerformanceManager_PageTimelineState::kEntryName[] = "PerformanceManager.PageTimelineState";
const uint64_t PerformanceManager_PageTimelineState::kEntryNameHash;

PerformanceManager_PageTimelineState::PerformanceManager_PageTimelineState(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceManager_PageTimelineState::PerformanceManager_PageTimelineState(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PerformanceManager_PageTimelineState::~PerformanceManager_PageTimelineState() = default;
const char PerformanceManager_PageTimelineState::kBatterySaverModeName[] = "BatterySaverMode";
const uint64_t PerformanceManager_PageTimelineState::kBatterySaverModeNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetBatterySaverMode(int64_t value)
{
    SetMetricInternal(kBatterySaverModeNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kChangedFaviconOrTitleInBackgroundName[] = "ChangedFaviconOrTitleInBackground";
const uint64_t PerformanceManager_PageTimelineState::kChangedFaviconOrTitleInBackgroundNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetChangedFaviconOrTitleInBackground(int64_t value)
{
    SetMetricInternal(kChangedFaviconOrTitleInBackgroundNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kCurrentStateName[] = "CurrentState";
const uint64_t PerformanceManager_PageTimelineState::kCurrentStateNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetCurrentState(int64_t value)
{
    SetMetricInternal(kCurrentStateNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kHasNotificationPermissionName[] = "HasNotificationPermission";
const uint64_t PerformanceManager_PageTimelineState::kHasNotificationPermissionNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetHasNotificationPermission(int64_t value)
{
    SetMetricInternal(kHasNotificationPermissionNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kHighEfficiencyModeName[] = "HighEfficiencyMode";
const uint64_t PerformanceManager_PageTimelineState::kHighEfficiencyModeNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetHighEfficiencyMode(int64_t value)
{
    SetMetricInternal(kHighEfficiencyModeNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kIsActiveTabName[] = "IsActiveTab";
const uint64_t PerformanceManager_PageTimelineState::kIsActiveTabNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetIsActiveTab(int64_t value)
{
    SetMetricInternal(kIsActiveTabNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kIsCapturingMediaName[] = "IsCapturingMedia";
const uint64_t PerformanceManager_PageTimelineState::kIsCapturingMediaNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetIsCapturingMedia(int64_t value)
{
    SetMetricInternal(kIsCapturingMediaNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kIsConnectedToDeviceName[] = "IsConnectedToDevice";
const uint64_t PerformanceManager_PageTimelineState::kIsConnectedToDeviceNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetIsConnectedToDevice(int64_t value)
{
    SetMetricInternal(kIsConnectedToDeviceNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kIsPlayingAudioName[] = "IsPlayingAudio";
const uint64_t PerformanceManager_PageTimelineState::kIsPlayingAudioNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetIsPlayingAudio(int64_t value)
{
    SetMetricInternal(kIsPlayingAudioNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kResidentSetSizeName[] = "ResidentSetSize";
const uint64_t PerformanceManager_PageTimelineState::kResidentSetSizeNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetResidentSetSize(int64_t value)
{
    SetMetricInternal(kResidentSetSizeNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kSliceIdName[] = "SliceId";
const uint64_t PerformanceManager_PageTimelineState::kSliceIdNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetSliceId(int64_t value)
{
    SetMetricInternal(kSliceIdNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kTabIdName[] = "TabId";
const uint64_t PerformanceManager_PageTimelineState::kTabIdNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetTabId(int64_t value)
{
    SetMetricInternal(kTabIdNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kTimeInCurrentStateName[] = "TimeInCurrentState";
const uint64_t PerformanceManager_PageTimelineState::kTimeInCurrentStateNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetTimeInCurrentState(int64_t value)
{
    SetMetricInternal(kTimeInCurrentStateNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kTimeSinceCreationName[] = "TimeSinceCreation";
const uint64_t PerformanceManager_PageTimelineState::kTimeSinceCreationNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetTimeSinceCreation(int64_t value)
{
    SetMetricInternal(kTimeSinceCreationNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kTimeSinceLastSliceName[] = "TimeSinceLastSlice";
const uint64_t PerformanceManager_PageTimelineState::kTimeSinceLastSliceNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetTimeSinceLastSlice(int64_t value)
{
    SetMetricInternal(kTimeSinceLastSliceNameHash, value);
    return *this;
}

const char PerformanceManager_PageTimelineState::kTotalForegroundTimeName[] = "TotalForegroundTime";
const uint64_t PerformanceManager_PageTimelineState::kTotalForegroundTimeNameHash;

PerformanceManager_PageTimelineState& PerformanceManager_PageTimelineState::SetTotalForegroundTime(int64_t value)
{
    SetMetricInternal(kTotalForegroundTimeNameHash, value);
    return *this;
}
const char PeriodicBackgroundSyncEventCompleted::kEntryName[] = "PeriodicBackgroundSyncEventCompleted";
const uint64_t PeriodicBackgroundSyncEventCompleted::kEntryNameHash;

PeriodicBackgroundSyncEventCompleted::PeriodicBackgroundSyncEventCompleted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PeriodicBackgroundSyncEventCompleted::PeriodicBackgroundSyncEventCompleted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PeriodicBackgroundSyncEventCompleted::~PeriodicBackgroundSyncEventCompleted() = default;
const char PeriodicBackgroundSyncEventCompleted::kMaxAttemptsName[] = "MaxAttempts";
const uint64_t PeriodicBackgroundSyncEventCompleted::kMaxAttemptsNameHash;

PeriodicBackgroundSyncEventCompleted& PeriodicBackgroundSyncEventCompleted::SetMaxAttempts(int64_t value)
{
    SetMetricInternal(kMaxAttemptsNameHash, value);
    return *this;
}

const char PeriodicBackgroundSyncEventCompleted::kNumAttemptsName[] = "NumAttempts";
const uint64_t PeriodicBackgroundSyncEventCompleted::kNumAttemptsNameHash;

PeriodicBackgroundSyncEventCompleted& PeriodicBackgroundSyncEventCompleted::SetNumAttempts(int64_t value)
{
    SetMetricInternal(kNumAttemptsNameHash, value);
    return *this;
}

const char PeriodicBackgroundSyncEventCompleted::kStatusName[] = "Status";
const uint64_t PeriodicBackgroundSyncEventCompleted::kStatusNameHash;

PeriodicBackgroundSyncEventCompleted& PeriodicBackgroundSyncEventCompleted::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}
const char PeriodicBackgroundSyncRegistered::kEntryName[] = "PeriodicBackgroundSyncRegistered";
const uint64_t PeriodicBackgroundSyncRegistered::kEntryNameHash;

PeriodicBackgroundSyncRegistered::PeriodicBackgroundSyncRegistered(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PeriodicBackgroundSyncRegistered::PeriodicBackgroundSyncRegistered(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PeriodicBackgroundSyncRegistered::~PeriodicBackgroundSyncRegistered() = default;
const char PeriodicBackgroundSyncRegistered::kIsReregisteredName[] = "IsReregistered";
const uint64_t PeriodicBackgroundSyncRegistered::kIsReregisteredNameHash;

PeriodicBackgroundSyncRegistered& PeriodicBackgroundSyncRegistered::SetIsReregistered(int64_t value)
{
    SetMetricInternal(kIsReregisteredNameHash, value);
    return *this;
}

const char PeriodicBackgroundSyncRegistered::kMinIntervalMsName[] = "MinIntervalMs";
const uint64_t PeriodicBackgroundSyncRegistered::kMinIntervalMsNameHash;

PeriodicBackgroundSyncRegistered& PeriodicBackgroundSyncRegistered::SetMinIntervalMs(int64_t value)
{
    SetMetricInternal(kMinIntervalMsNameHash, value);
    return *this;
}
const char Permission::kEntryName[] = "Permission";
const uint64_t Permission::kEntryNameHash;

Permission::Permission(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Permission::Permission(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Permission::~Permission() = default;
const char Permission::kActionName[] = "Action";
const uint64_t Permission::kActionNameHash;

Permission& Permission::SetAction(int64_t value)
{
    SetMetricInternal(kActionNameHash, value);
    return *this;
}

const char Permission::kGestureName[] = "Gesture";
const uint64_t Permission::kGestureNameHash;

Permission& Permission::SetGesture(int64_t value)
{
    SetMetricInternal(kGestureNameHash, value);
    return *this;
}

const char Permission::kPermissionAutoRevocationHistoryName[] = "PermissionAutoRevocationHistory";
const uint64_t Permission::kPermissionAutoRevocationHistoryNameHash;

Permission& Permission::SetPermissionAutoRevocationHistory(int64_t value)
{
    SetMetricInternal(kPermissionAutoRevocationHistoryNameHash, value);
    return *this;
}

const char Permission::kPermissionTypeName[] = "PermissionType";
const uint64_t Permission::kPermissionTypeNameHash;

Permission& Permission::SetPermissionType(int64_t value)
{
    SetMetricInternal(kPermissionTypeNameHash, value);
    return *this;
}

const char Permission::kPredictionsApiResponse_GrantLikelihoodName[] = "PredictionsApiResponse.GrantLikelihood";
const uint64_t Permission::kPredictionsApiResponse_GrantLikelihoodNameHash;

Permission& Permission::SetPredictionsApiResponse_GrantLikelihood(int64_t value)
{
    SetMetricInternal(kPredictionsApiResponse_GrantLikelihoodNameHash, value);
    return *this;
}

const char Permission::kPredictionsApiResponse_HeldbackName[] = "PredictionsApiResponse.Heldback";
const uint64_t Permission::kPredictionsApiResponse_HeldbackNameHash;

Permission& Permission::SetPredictionsApiResponse_Heldback(int64_t value)
{
    SetMetricInternal(kPredictionsApiResponse_HeldbackNameHash, value);
    return *this;
}

const char Permission::kPriorDismissalsName[] = "PriorDismissals";
const uint64_t Permission::kPriorDismissalsNameHash;

Permission& Permission::SetPriorDismissals(int64_t value)
{
    SetMetricInternal(kPriorDismissalsNameHash, value);
    return *this;
}

const char Permission::kPriorIgnoresName[] = "PriorIgnores";
const uint64_t Permission::kPriorIgnoresNameHash;

Permission& Permission::SetPriorIgnores(int64_t value)
{
    SetMetricInternal(kPriorIgnoresNameHash, value);
    return *this;
}

const char Permission::kPromptDispositionName[] = "PromptDisposition";
const uint64_t Permission::kPromptDispositionNameHash;

Permission& Permission::SetPromptDisposition(int64_t value)
{
    SetMetricInternal(kPromptDispositionNameHash, value);
    return *this;
}

const char Permission::kPromptDispositionReasonName[] = "PromptDispositionReason";
const uint64_t Permission::kPromptDispositionReasonNameHash;

Permission& Permission::SetPromptDispositionReason(int64_t value)
{
    SetMetricInternal(kPromptDispositionReasonNameHash, value);
    return *this;
}

const char Permission::kSatisfiedAdaptiveTriggersName[] = "SatisfiedAdaptiveTriggers";
const uint64_t Permission::kSatisfiedAdaptiveTriggersNameHash;

Permission& Permission::SetSatisfiedAdaptiveTriggers(int64_t value)
{
    SetMetricInternal(kSatisfiedAdaptiveTriggersNameHash, value);
    return *this;
}

const char Permission::kSourceName[] = "Source";
const uint64_t Permission::kSourceNameHash;

Permission& Permission::SetSource(int64_t value)
{
    SetMetricInternal(kSourceNameHash, value);
    return *this;
}

const char Permission::kStats_AllPrompts_CountName[] = "Stats.AllPrompts.Count";
const uint64_t Permission::kStats_AllPrompts_CountNameHash;

Permission& Permission::SetStats_AllPrompts_Count(int64_t value)
{
    SetMetricInternal(kStats_AllPrompts_CountNameHash, value);
    return *this;
}

const char Permission::kStats_AllPrompts_DenyRateName[] = "Stats.AllPrompts.DenyRate";
const uint64_t Permission::kStats_AllPrompts_DenyRateNameHash;

Permission& Permission::SetStats_AllPrompts_DenyRate(int64_t value)
{
    SetMetricInternal(kStats_AllPrompts_DenyRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPrompts_DismissRateName[] = "Stats.AllPrompts.DismissRate";
const uint64_t Permission::kStats_AllPrompts_DismissRateNameHash;

Permission& Permission::SetStats_AllPrompts_DismissRate(int64_t value)
{
    SetMetricInternal(kStats_AllPrompts_DismissRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPrompts_GrantRateName[] = "Stats.AllPrompts.GrantRate";
const uint64_t Permission::kStats_AllPrompts_GrantRateNameHash;

Permission& Permission::SetStats_AllPrompts_GrantRate(int64_t value)
{
    SetMetricInternal(kStats_AllPrompts_GrantRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPrompts_IgnoreRateName[] = "Stats.AllPrompts.IgnoreRate";
const uint64_t Permission::kStats_AllPrompts_IgnoreRateNameHash;

Permission& Permission::SetStats_AllPrompts_IgnoreRate(int64_t value)
{
    SetMetricInternal(kStats_AllPrompts_IgnoreRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPromptsOfType_CountName[] = "Stats.AllPromptsOfType.Count";
const uint64_t Permission::kStats_AllPromptsOfType_CountNameHash;

Permission& Permission::SetStats_AllPromptsOfType_Count(int64_t value)
{
    SetMetricInternal(kStats_AllPromptsOfType_CountNameHash, value);
    return *this;
}

const char Permission::kStats_AllPromptsOfType_DenyRateName[] = "Stats.AllPromptsOfType.DenyRate";
const uint64_t Permission::kStats_AllPromptsOfType_DenyRateNameHash;

Permission& Permission::SetStats_AllPromptsOfType_DenyRate(int64_t value)
{
    SetMetricInternal(kStats_AllPromptsOfType_DenyRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPromptsOfType_DismissRateName[] = "Stats.AllPromptsOfType.DismissRate";
const uint64_t Permission::kStats_AllPromptsOfType_DismissRateNameHash;

Permission& Permission::SetStats_AllPromptsOfType_DismissRate(int64_t value)
{
    SetMetricInternal(kStats_AllPromptsOfType_DismissRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPromptsOfType_GrantRateName[] = "Stats.AllPromptsOfType.GrantRate";
const uint64_t Permission::kStats_AllPromptsOfType_GrantRateNameHash;

Permission& Permission::SetStats_AllPromptsOfType_GrantRate(int64_t value)
{
    SetMetricInternal(kStats_AllPromptsOfType_GrantRateNameHash, value);
    return *this;
}

const char Permission::kStats_AllPromptsOfType_IgnoreRateName[] = "Stats.AllPromptsOfType.IgnoreRate";
const uint64_t Permission::kStats_AllPromptsOfType_IgnoreRateNameHash;

Permission& Permission::SetStats_AllPromptsOfType_IgnoreRate(int64_t value)
{
    SetMetricInternal(kStats_AllPromptsOfType_IgnoreRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPrompts_CountName[] = "Stats.LoudPrompts.Count";
const uint64_t Permission::kStats_LoudPrompts_CountNameHash;

Permission& Permission::SetStats_LoudPrompts_Count(int64_t value)
{
    SetMetricInternal(kStats_LoudPrompts_CountNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPrompts_DenyRateName[] = "Stats.LoudPrompts.DenyRate";
const uint64_t Permission::kStats_LoudPrompts_DenyRateNameHash;

Permission& Permission::SetStats_LoudPrompts_DenyRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPrompts_DenyRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPrompts_DismissRateName[] = "Stats.LoudPrompts.DismissRate";
const uint64_t Permission::kStats_LoudPrompts_DismissRateNameHash;

Permission& Permission::SetStats_LoudPrompts_DismissRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPrompts_DismissRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPrompts_GrantRateName[] = "Stats.LoudPrompts.GrantRate";
const uint64_t Permission::kStats_LoudPrompts_GrantRateNameHash;

Permission& Permission::SetStats_LoudPrompts_GrantRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPrompts_GrantRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPrompts_IgnoreRateName[] = "Stats.LoudPrompts.IgnoreRate";
const uint64_t Permission::kStats_LoudPrompts_IgnoreRateNameHash;

Permission& Permission::SetStats_LoudPrompts_IgnoreRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPrompts_IgnoreRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPromptsOfType_CountName[] = "Stats.LoudPromptsOfType.Count";
const uint64_t Permission::kStats_LoudPromptsOfType_CountNameHash;

Permission& Permission::SetStats_LoudPromptsOfType_Count(int64_t value)
{
    SetMetricInternal(kStats_LoudPromptsOfType_CountNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPromptsOfType_DenyRateName[] = "Stats.LoudPromptsOfType.DenyRate";
const uint64_t Permission::kStats_LoudPromptsOfType_DenyRateNameHash;

Permission& Permission::SetStats_LoudPromptsOfType_DenyRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPromptsOfType_DenyRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPromptsOfType_DismissRateName[] = "Stats.LoudPromptsOfType.DismissRate";
const uint64_t Permission::kStats_LoudPromptsOfType_DismissRateNameHash;

Permission& Permission::SetStats_LoudPromptsOfType_DismissRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPromptsOfType_DismissRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPromptsOfType_GrantRateName[] = "Stats.LoudPromptsOfType.GrantRate";
const uint64_t Permission::kStats_LoudPromptsOfType_GrantRateNameHash;

Permission& Permission::SetStats_LoudPromptsOfType_GrantRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPromptsOfType_GrantRateNameHash, value);
    return *this;
}

const char Permission::kStats_LoudPromptsOfType_IgnoreRateName[] = "Stats.LoudPromptsOfType.IgnoreRate";
const uint64_t Permission::kStats_LoudPromptsOfType_IgnoreRateNameHash;

Permission& Permission::SetStats_LoudPromptsOfType_IgnoreRate(int64_t value)
{
    SetMetricInternal(kStats_LoudPromptsOfType_IgnoreRateNameHash, value);
    return *this;
}

const char Permission::kTimeToDecisionName[] = "TimeToDecision";
const uint64_t Permission::kTimeToDecisionNameHash;

Permission& Permission::SetTimeToDecision(int64_t value)
{
    SetMetricInternal(kTimeToDecisionNameHash, value);
    return *this;
}
const char PermissionUsage::kEntryName[] = "PermissionUsage";
const uint64_t PermissionUsage::kEntryNameHash;

PermissionUsage::PermissionUsage(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PermissionUsage::PermissionUsage(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PermissionUsage::~PermissionUsage() = default;
const char PermissionUsage::kPermissionTypeName[] = "PermissionType";
const uint64_t PermissionUsage::kPermissionTypeNameHash;

PermissionUsage& PermissionUsage::SetPermissionType(int64_t value)
{
    SetMetricInternal(kPermissionTypeNameHash, value);
    return *this;
}
const char Plugins_FlashInstance::kEntryName[] = "Plugins.FlashInstance";
const uint64_t Plugins_FlashInstance::kEntryNameHash;

Plugins_FlashInstance::Plugins_FlashInstance(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Plugins_FlashInstance::Plugins_FlashInstance(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Plugins_FlashInstance::~Plugins_FlashInstance() = default;

const char Popup_Closed::kEntryName[] = "Popup.Closed";
const uint64_t Popup_Closed::kEntryNameHash;

Popup_Closed::Popup_Closed(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Popup_Closed::Popup_Closed(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Popup_Closed::~Popup_Closed() = default;
const char Popup_Closed::kEngagementTimeName[] = "EngagementTime";
const uint64_t Popup_Closed::kEngagementTimeNameHash;

Popup_Closed& Popup_Closed::SetEngagementTime(int64_t value)
{
    SetMetricInternal(kEngagementTimeNameHash, value);
    return *this;
}

const char Popup_Closed::kNumActivationInteractionsName[] = "NumActivationInteractions";
const uint64_t Popup_Closed::kNumActivationInteractionsNameHash;

Popup_Closed& Popup_Closed::SetNumActivationInteractions(int64_t value)
{
    SetMetricInternal(kNumActivationInteractionsNameHash, value);
    return *this;
}

const char Popup_Closed::kNumGestureScrollBeginInteractionsName[] = "NumGestureScrollBeginInteractions";
const uint64_t Popup_Closed::kNumGestureScrollBeginInteractionsNameHash;

Popup_Closed& Popup_Closed::SetNumGestureScrollBeginInteractions(int64_t value)
{
    SetMetricInternal(kNumGestureScrollBeginInteractionsNameHash, value);
    return *this;
}

const char Popup_Closed::kNumInteractionsName[] = "NumInteractions";
const uint64_t Popup_Closed::kNumInteractionsNameHash;

Popup_Closed& Popup_Closed::SetNumInteractions(int64_t value)
{
    SetMetricInternal(kNumInteractionsNameHash, value);
    return *this;
}

const char Popup_Closed::kRedirectCountName[] = "RedirectCount";
const uint64_t Popup_Closed::kRedirectCountNameHash;

Popup_Closed& Popup_Closed::SetRedirectCount(int64_t value)
{
    SetMetricInternal(kRedirectCountNameHash, value);
    return *this;
}

const char Popup_Closed::kSafeBrowsingStatusName[] = "SafeBrowsingStatus";
const uint64_t Popup_Closed::kSafeBrowsingStatusNameHash;

Popup_Closed& Popup_Closed::SetSafeBrowsingStatus(int64_t value)
{
    SetMetricInternal(kSafeBrowsingStatusNameHash, value);
    return *this;
}

const char Popup_Closed::kTrustedName[] = "Trusted";
const uint64_t Popup_Closed::kTrustedNameHash;

Popup_Closed& Popup_Closed::SetTrusted(int64_t value)
{
    SetMetricInternal(kTrustedNameHash, value);
    return *this;
}

const char Popup_Closed::kUserInitiatedCloseName[] = "UserInitiatedClose";
const uint64_t Popup_Closed::kUserInitiatedCloseNameHash;

Popup_Closed& Popup_Closed::SetUserInitiatedClose(int64_t value)
{
    SetMetricInternal(kUserInitiatedCloseNameHash, value);
    return *this;
}

const char Popup_Closed::kWindowOpenDispositionName[] = "WindowOpenDisposition";
const uint64_t Popup_Closed::kWindowOpenDispositionNameHash;

Popup_Closed& Popup_Closed::SetWindowOpenDisposition(int64_t value)
{
    SetMetricInternal(kWindowOpenDispositionNameHash, value);
    return *this;
}
const char Popup_Page::kEntryName[] = "Popup.Page";
const uint64_t Popup_Page::kEntryNameHash;

Popup_Page::Popup_Page(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Popup_Page::Popup_Page(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Popup_Page::~Popup_Page() = default;
const char Popup_Page::kAllowedName[] = "Allowed";
const uint64_t Popup_Page::kAllowedNameHash;

Popup_Page& Popup_Page::SetAllowed(int64_t value)
{
    SetMetricInternal(kAllowedNameHash, value);
    return *this;
}
const char Portal_Activate::kEntryName[] = "Portal.Activate";
const uint64_t Portal_Activate::kEntryNameHash;

Portal_Activate::Portal_Activate(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Portal_Activate::Portal_Activate(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Portal_Activate::~Portal_Activate() = default;
const char Portal_Activate::kPaintTiming_PortalActivationToFirstPaintName[] = "PaintTiming.PortalActivationToFirstPaint";
const uint64_t Portal_Activate::kPaintTiming_PortalActivationToFirstPaintNameHash;

Portal_Activate& Portal_Activate::SetPaintTiming_PortalActivationToFirstPaint(int64_t value)
{
    SetMetricInternal(kPaintTiming_PortalActivationToFirstPaintNameHash, value);
    return *this;
}

const char Portal_Activate::kPortalActivationName[] = "PortalActivation";
const uint64_t Portal_Activate::kPortalActivationNameHash;

Portal_Activate& Portal_Activate::SetPortalActivation(int64_t value)
{
    SetMetricInternal(kPortalActivationNameHash, value);
    return *this;
}

const char Portal_Activate::kPortalActivationBeforeLCPName[] = "PortalActivationBeforeLCP";
const uint64_t Portal_Activate::kPortalActivationBeforeLCPNameHash;

Portal_Activate& Portal_Activate::SetPortalActivationBeforeLCP(int64_t value)
{
    SetMetricInternal(kPortalActivationBeforeLCPNameHash, value);
    return *this;
}
const char PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kEntryName[] = "PostMessage.Incoming.FirstPartyToFirstParty.DifferentBucket";
const uint64_t PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kEntryNameHash;

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::~PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket() = default;
const char PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket& PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::SetSourceFrameSourceId(int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kEntryName[] = "PostMessage.Incoming.FirstPartyToFirstParty.SameBucket";
const uint64_t PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kEntryNameHash;

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::PostMessage_Incoming_FirstPartyToFirstParty_SameBucket(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::PostMessage_Incoming_FirstPartyToFirstParty_SameBucket(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::~PostMessage_Incoming_FirstPartyToFirstParty_SameBucket() = default;
const char PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_FirstPartyToFirstParty_SameBucket& PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::SetSourceFrameSourceId(int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kEntryName[]
    = "PostMessage.Incoming.FirstPartyToThirdParty.DifferentBucket.DifferentOrigin";
const uint64_t PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kEntryNameHash;

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::~PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin() = default;
const char PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin& PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::SetSourceFrameSourceId(
    int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kEntryName[] = "PostMessage.Incoming.FirstPartyToThirdParty.DifferentBucket.SameOrigin";
const uint64_t PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kEntryNameHash;

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::~PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin() = default;
const char PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin& PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::SetSourceFrameSourceId(
    int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_Frame::kEntryName[] = "PostMessage.Incoming.Frame";
const uint64_t PostMessage_Incoming_Frame::kEntryNameHash;

PostMessage_Incoming_Frame::PostMessage_Incoming_Frame(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Frame::PostMessage_Incoming_Frame(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Frame::~PostMessage_Incoming_Frame() = default;
const char PostMessage_Incoming_Frame::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_Frame::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_Frame& PostMessage_Incoming_Frame::SetSourceFrameSourceId(int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_Opaque::kEntryName[] = "PostMessage.Incoming.Opaque";
const uint64_t PostMessage_Incoming_Opaque::kEntryNameHash;

PostMessage_Incoming_Opaque::PostMessage_Incoming_Opaque(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Opaque::PostMessage_Incoming_Opaque(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Opaque::~PostMessage_Incoming_Opaque() = default;
const char PostMessage_Incoming_Opaque::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_Opaque::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_Opaque& PostMessage_Incoming_Opaque::SetSourceFrameSourceId(int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_Page::kEntryName[] = "PostMessage.Incoming.Page";
const uint64_t PostMessage_Incoming_Page::kEntryNameHash;

PostMessage_Incoming_Page::PostMessage_Incoming_Page(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Page::PostMessage_Incoming_Page(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_Page::~PostMessage_Incoming_Page() = default;
const char PostMessage_Incoming_Page::kSourcePageSourceIdName[] = "SourcePageSourceId";
const uint64_t PostMessage_Incoming_Page::kSourcePageSourceIdNameHash;

PostMessage_Incoming_Page& PostMessage_Incoming_Page::SetSourcePageSourceId(int64_t value)
{
    SetMetricInternal(kSourcePageSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kEntryName[]
    = "PostMessage.Incoming.ThirdPartyToFirstParty.DifferentBucket.DifferentOrigin";
const uint64_t PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kEntryNameHash;

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::~PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin() = default;
const char PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin& PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::SetSourceFrameSourceId(
    int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kEntryName[] = "PostMessage.Incoming.ThirdPartyToFirstParty.DifferentBucket.SameOrigin";
const uint64_t PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kEntryNameHash;

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::~PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin() = default;
const char PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin& PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::SetSourceFrameSourceId(
    int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kEntryName[]
    = "PostMessage.Incoming.ThirdPartyToThirdParty.DifferentBucket.DifferentOrigin";
const uint64_t PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kEntryNameHash;

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::~PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin() = default;
const char PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin& PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::SetSourceFrameSourceId(
    int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kEntryName[] = "PostMessage.Incoming.ThirdPartyToThirdParty.DifferentBucket.SameOrigin";
const uint64_t PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kEntryNameHash;

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::~PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin() = default;
const char PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin& PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::SetSourceFrameSourceId(
    int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kEntryName[] = "PostMessage.Incoming.ThirdPartyToThirdParty.SameBucket";
const uint64_t PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kEntryNameHash;

PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::~PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket() = default;
const char PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kSourceFrameSourceIdName[] = "SourceFrameSourceId";
const uint64_t PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kSourceFrameSourceIdNameHash;

PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket& PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::SetSourceFrameSourceId(int64_t value)
{
    SetMetricInternal(kSourceFrameSourceIdNameHash, value);
    return *this;
}
const char PowerUsageScenariosIntervalData::kEntryName[] = "PowerUsageScenariosIntervalData";
const uint64_t PowerUsageScenariosIntervalData::kEntryNameHash;

PowerUsageScenariosIntervalData::PowerUsageScenariosIntervalData(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PowerUsageScenariosIntervalData::PowerUsageScenariosIntervalData(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PowerUsageScenariosIntervalData::~PowerUsageScenariosIntervalData() = default;
const char PowerUsageScenariosIntervalData::kBatteryDischargeModeName[] = "BatteryDischargeMode";
const uint64_t PowerUsageScenariosIntervalData::kBatteryDischargeModeNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetBatteryDischargeMode(int64_t value)
{
    SetMetricInternal(kBatteryDischargeModeNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kBatteryDischargeRateName[] = "BatteryDischargeRate";
const uint64_t PowerUsageScenariosIntervalData::kBatteryDischargeRateNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetBatteryDischargeRate(int64_t value)
{
    SetMetricInternal(kBatteryDischargeRateNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kBrowserShuttingDownName[] = "BrowserShuttingDown";
const uint64_t PowerUsageScenariosIntervalData::kBrowserShuttingDownNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetBrowserShuttingDown(int64_t value)
{
    SetMetricInternal(kBrowserShuttingDownNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kCPUTimeMsName[] = "CPUTimeMs";
const uint64_t PowerUsageScenariosIntervalData::kCPUTimeMsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetCPUTimeMs(int64_t value)
{
    SetMetricInternal(kCPUTimeMsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kDeviceSleptDuringIntervalName[] = "DeviceSleptDuringInterval";
const uint64_t PowerUsageScenariosIntervalData::kDeviceSleptDuringIntervalNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetDeviceSleptDuringInterval(int64_t value)
{
    SetMetricInternal(kDeviceSleptDuringIntervalNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kEnergyImpactScoreName[] = "EnergyImpactScore";
const uint64_t PowerUsageScenariosIntervalData::kEnergyImpactScoreNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetEnergyImpactScore(int64_t value)
{
    SetMetricInternal(kEnergyImpactScoreNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kFullscreenVideoSingleMonitorSecondsName[] = "FullscreenVideoSingleMonitorSeconds";
const uint64_t PowerUsageScenariosIntervalData::kFullscreenVideoSingleMonitorSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetFullscreenVideoSingleMonitorSeconds(int64_t value)
{
    SetMetricInternal(kFullscreenVideoSingleMonitorSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kIdleWakeUpsName[] = "IdleWakeUps";
const uint64_t PowerUsageScenariosIntervalData::kIdleWakeUpsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetIdleWakeUps(int64_t value)
{
    SetMetricInternal(kIdleWakeUpsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kIntervalDurationSecondsName[] = "IntervalDurationSeconds";
const uint64_t PowerUsageScenariosIntervalData::kIntervalDurationSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetIntervalDurationSeconds(int64_t value)
{
    SetMetricInternal(kIntervalDurationSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kMaxTabCountName[] = "MaxTabCount";
const uint64_t PowerUsageScenariosIntervalData::kMaxTabCountNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetMaxTabCount(int64_t value)
{
    SetMetricInternal(kMaxTabCountNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kMaxVisibleWindowCountName[] = "MaxVisibleWindowCount";
const uint64_t PowerUsageScenariosIntervalData::kMaxVisibleWindowCountNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetMaxVisibleWindowCount(int64_t value)
{
    SetMetricInternal(kMaxVisibleWindowCountNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kOriginVisibilityTimeSecondsName[] = "OriginVisibilityTimeSeconds";
const uint64_t PowerUsageScenariosIntervalData::kOriginVisibilityTimeSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetOriginVisibilityTimeSeconds(int64_t value)
{
    SetMetricInternal(kOriginVisibilityTimeSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kPackageExitsName[] = "PackageExits";
const uint64_t PowerUsageScenariosIntervalData::kPackageExitsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetPackageExits(int64_t value)
{
    SetMetricInternal(kPackageExitsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kPlayingAudioSecondsName[] = "PlayingAudioSeconds";
const uint64_t PowerUsageScenariosIntervalData::kPlayingAudioSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetPlayingAudioSeconds(int64_t value)
{
    SetMetricInternal(kPlayingAudioSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kTabClosedName[] = "TabClosed";
const uint64_t PowerUsageScenariosIntervalData::kTabClosedNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetTabClosed(int64_t value)
{
    SetMetricInternal(kTabClosedNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kTimePlayingVideoInVisibleTabName[] = "TimePlayingVideoInVisibleTab";
const uint64_t PowerUsageScenariosIntervalData::kTimePlayingVideoInVisibleTabNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetTimePlayingVideoInVisibleTab(int64_t value)
{
    SetMetricInternal(kTimePlayingVideoInVisibleTabNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kTimeSinceInteractionWithBrowserSecondsName[] = "TimeSinceInteractionWithBrowserSeconds";
const uint64_t PowerUsageScenariosIntervalData::kTimeSinceInteractionWithBrowserSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetTimeSinceInteractionWithBrowserSeconds(int64_t value)
{
    SetMetricInternal(kTimeSinceInteractionWithBrowserSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kTimeSinceInteractionWithSystemSecondsName[] = "TimeSinceInteractionWithSystemSeconds";
const uint64_t PowerUsageScenariosIntervalData::kTimeSinceInteractionWithSystemSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetTimeSinceInteractionWithSystemSeconds(int64_t value)
{
    SetMetricInternal(kTimeSinceInteractionWithSystemSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kTimeWithOpenWebRTCConnectionSecondsName[] = "TimeWithOpenWebRTCConnectionSeconds";
const uint64_t PowerUsageScenariosIntervalData::kTimeWithOpenWebRTCConnectionSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetTimeWithOpenWebRTCConnectionSeconds(int64_t value)
{
    SetMetricInternal(kTimeWithOpenWebRTCConnectionSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kTopLevelNavigationEventsName[] = "TopLevelNavigationEvents";
const uint64_t PowerUsageScenariosIntervalData::kTopLevelNavigationEventsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetTopLevelNavigationEvents(int64_t value)
{
    SetMetricInternal(kTopLevelNavigationEventsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kUptimeSecondsName[] = "UptimeSeconds";
const uint64_t PowerUsageScenariosIntervalData::kUptimeSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetUptimeSeconds(int64_t value)
{
    SetMetricInternal(kUptimeSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kURLVisibilityTimeSecondsName[] = "URLVisibilityTimeSeconds";
const uint64_t PowerUsageScenariosIntervalData::kURLVisibilityTimeSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetURLVisibilityTimeSeconds(int64_t value)
{
    SetMetricInternal(kURLVisibilityTimeSecondsNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kUserInteractionCountName[] = "UserInteractionCount";
const uint64_t PowerUsageScenariosIntervalData::kUserInteractionCountNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetUserInteractionCount(int64_t value)
{
    SetMetricInternal(kUserInteractionCountNameHash, value);
    return *this;
}

const char PowerUsageScenariosIntervalData::kVideoCaptureSecondsName[] = "VideoCaptureSeconds";
const uint64_t PowerUsageScenariosIntervalData::kVideoCaptureSecondsNameHash;

PowerUsageScenariosIntervalData& PowerUsageScenariosIntervalData::SetVideoCaptureSeconds(int64_t value)
{
    SetMetricInternal(kVideoCaptureSecondsNameHash, value);
    return *this;
}
const char PrefetchProxy::kEntryName[] = "PrefetchProxy";
const uint64_t PrefetchProxy::kEntryNameHash;

PrefetchProxy::PrefetchProxy(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrefetchProxy::PrefetchProxy(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrefetchProxy::~PrefetchProxy() = default;
const char PrefetchProxy::kdays_since_last_visit_to_originName[] = "days_since_last_visit_to_origin";
const uint64_t PrefetchProxy::kdays_since_last_visit_to_originNameHash;

PrefetchProxy& PrefetchProxy::Setdays_since_last_visit_to_origin(int64_t value)
{
    SetMetricInternal(kdays_since_last_visit_to_originNameHash, value);
    return *this;
}

const char PrefetchProxy::kprefetch_attempted_countName[] = "prefetch_attempted_count";
const uint64_t PrefetchProxy::kprefetch_attempted_countNameHash;

PrefetchProxy& PrefetchProxy::Setprefetch_attempted_count(int64_t value)
{
    SetMetricInternal(kprefetch_attempted_countNameHash, value);
    return *this;
}

const char PrefetchProxy::kprefetch_eligible_countName[] = "prefetch_eligible_count";
const uint64_t PrefetchProxy::kprefetch_eligible_countNameHash;

PrefetchProxy& PrefetchProxy::Setprefetch_eligible_count(int64_t value)
{
    SetMetricInternal(kprefetch_eligible_countNameHash, value);
    return *this;
}

const char PrefetchProxy::kprefetch_successful_countName[] = "prefetch_successful_count";
const uint64_t PrefetchProxy::kprefetch_successful_countNameHash;

PrefetchProxy& PrefetchProxy::Setprefetch_successful_count(int64_t value)
{
    SetMetricInternal(kprefetch_successful_countNameHash, value);
    return *this;
}
const char PrefetchProxy_AfterSRPClick::kEntryName[] = "PrefetchProxy.AfterSRPClick";
const uint64_t PrefetchProxy_AfterSRPClick::kEntryNameHash;

PrefetchProxy_AfterSRPClick::PrefetchProxy_AfterSRPClick(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrefetchProxy_AfterSRPClick::PrefetchProxy_AfterSRPClick(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrefetchProxy_AfterSRPClick::~PrefetchProxy_AfterSRPClick() = default;
const char PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionName[] = "ClickedLinkSRPPosition";
const uint64_t PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetClickedLinkSRPPosition(int64_t value)
{
    SetMetricInternal(kClickedLinkSRPPositionNameHash, value);
    return *this;
}

const char PrefetchProxy_AfterSRPClick::kPrefetchHeaderLatencyMsName[] = "PrefetchHeaderLatencyMs";
const uint64_t PrefetchProxy_AfterSRPClick::kPrefetchHeaderLatencyMsNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetPrefetchHeaderLatencyMs(int64_t value)
{
    SetMetricInternal(kPrefetchHeaderLatencyMsNameHash, value);
    return *this;
}

const char PrefetchProxy_AfterSRPClick::kPrivatePrefetchName[] = "PrivatePrefetch";
const uint64_t PrefetchProxy_AfterSRPClick::kPrivatePrefetchNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetPrivatePrefetch(int64_t value)
{
    SetMetricInternal(kPrivatePrefetchNameHash, value);
    return *this;
}

const char PrefetchProxy_AfterSRPClick::kProbeLatencyMsName[] = "ProbeLatencyMs";
const uint64_t PrefetchProxy_AfterSRPClick::kProbeLatencyMsNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetProbeLatencyMs(int64_t value)
{
    SetMetricInternal(kProbeLatencyMsNameHash, value);
    return *this;
}

const char PrefetchProxy_AfterSRPClick::kSameTabAsPrefetchingTabName[] = "SameTabAsPrefetchingTab";
const uint64_t PrefetchProxy_AfterSRPClick::kSameTabAsPrefetchingTabNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetSameTabAsPrefetchingTab(int64_t value)
{
    SetMetricInternal(kSameTabAsPrefetchingTabNameHash, value);
    return *this;
}

const char PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusName[] = "SRPClickPrefetchStatus";
const uint64_t PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetSRPClickPrefetchStatus(int64_t value)
{
    SetMetricInternal(kSRPClickPrefetchStatusNameHash, value);
    return *this;
}

const char PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountName[] = "SRPPrefetchEligibleCount";
const uint64_t PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountNameHash;

PrefetchProxy_AfterSRPClick& PrefetchProxy_AfterSRPClick::SetSRPPrefetchEligibleCount(int64_t value)
{
    SetMetricInternal(kSRPPrefetchEligibleCountNameHash, value);
    return *this;
}
const char PrefetchProxy_PrefetchedResource::kEntryName[] = "PrefetchProxy.PrefetchedResource";
const uint64_t PrefetchProxy_PrefetchedResource::kEntryNameHash;

PrefetchProxy_PrefetchedResource::PrefetchProxy_PrefetchedResource(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrefetchProxy_PrefetchedResource::PrefetchProxy_PrefetchedResource(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrefetchProxy_PrefetchedResource::~PrefetchProxy_PrefetchedResource() = default;
const char PrefetchProxy_PrefetchedResource::kDataLengthName[] = "DataLength";
const uint64_t PrefetchProxy_PrefetchedResource::kDataLengthNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetDataLength(int64_t value)
{
    SetMetricInternal(kDataLengthNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kFetchDurationMSName[] = "FetchDurationMS";
const uint64_t PrefetchProxy_PrefetchedResource::kFetchDurationMSNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetFetchDurationMS(int64_t value)
{
    SetMetricInternal(kFetchDurationMSNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kISPFilteringStatusName[] = "ISPFilteringStatus";
const uint64_t PrefetchProxy_PrefetchedResource::kISPFilteringStatusNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetISPFilteringStatus(int64_t value)
{
    SetMetricInternal(kISPFilteringStatusNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kLinkClickedName[] = "LinkClicked";
const uint64_t PrefetchProxy_PrefetchedResource::kLinkClickedNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetLinkClicked(int64_t value)
{
    SetMetricInternal(kLinkClickedNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kLinkPositionName[] = "LinkPosition";
const uint64_t PrefetchProxy_PrefetchedResource::kLinkPositionNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetLinkPosition(int64_t value)
{
    SetMetricInternal(kLinkPositionNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kNavigationStartToFetchStartMSName[] = "NavigationStartToFetchStartMS";
const uint64_t PrefetchProxy_PrefetchedResource::kNavigationStartToFetchStartMSNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetNavigationStartToFetchStartMS(int64_t value)
{
    SetMetricInternal(kNavigationStartToFetchStartMSNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kResourceTypeName[] = "ResourceType";
const uint64_t PrefetchProxy_PrefetchedResource::kResourceTypeNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetResourceType(int64_t value)
{
    SetMetricInternal(kResourceTypeNameHash, value);
    return *this;
}

const char PrefetchProxy_PrefetchedResource::kStatusName[] = "Status";
const uint64_t PrefetchProxy_PrefetchedResource::kStatusNameHash;

PrefetchProxy_PrefetchedResource& PrefetchProxy_PrefetchedResource::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}
const char Preloading_AnchorInteraction::kEntryName[] = "Preloading.AnchorInteraction";
const uint64_t Preloading_AnchorInteraction::kEntryNameHash;

Preloading_AnchorInteraction::Preloading_AnchorInteraction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_AnchorInteraction::Preloading_AnchorInteraction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_AnchorInteraction::~Preloading_AnchorInteraction() = default;
const char Preloading_AnchorInteraction::kAnchorElementPreloaderTypeName[] = "AnchorElementPreloaderType";
const uint64_t Preloading_AnchorInteraction::kAnchorElementPreloaderTypeNameHash;

Preloading_AnchorInteraction& Preloading_AnchorInteraction::SetAnchorElementPreloaderType(int64_t value)
{
    SetMetricInternal(kAnchorElementPreloaderTypeNameHash, value);
    return *this;
}
const char Preloading_Attempt::kEntryName[] = "Preloading.Attempt";
const uint64_t Preloading_Attempt::kEntryNameHash;

Preloading_Attempt::Preloading_Attempt(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Attempt::Preloading_Attempt(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Attempt::~Preloading_Attempt() = default;
const char Preloading_Attempt::kAccurateTriggeringName[] = "AccurateTriggering";
const uint64_t Preloading_Attempt::kAccurateTriggeringNameHash;

Preloading_Attempt& Preloading_Attempt::SetAccurateTriggering(int64_t value)
{
    SetMetricInternal(kAccurateTriggeringNameHash, value);
    return *this;
}

const char Preloading_Attempt::kEligibilityName[] = "Eligibility";
const uint64_t Preloading_Attempt::kEligibilityNameHash;

Preloading_Attempt& Preloading_Attempt::SetEligibility(int64_t value)
{
    SetMetricInternal(kEligibilityNameHash, value);
    return *this;
}

const char Preloading_Attempt::kFailureReasonName[] = "FailureReason";
const uint64_t Preloading_Attempt::kFailureReasonNameHash;

Preloading_Attempt& Preloading_Attempt::SetFailureReason(int64_t value)
{
    SetMetricInternal(kFailureReasonNameHash, value);
    return *this;
}

const char Preloading_Attempt::kHoldbackStatusName[] = "HoldbackStatus";
const uint64_t Preloading_Attempt::kHoldbackStatusNameHash;

Preloading_Attempt& Preloading_Attempt::SetHoldbackStatus(int64_t value)
{
    SetMetricInternal(kHoldbackStatusNameHash, value);
    return *this;
}

const char Preloading_Attempt::kPreloadingPredictorName[] = "PreloadingPredictor";
const uint64_t Preloading_Attempt::kPreloadingPredictorNameHash;

Preloading_Attempt& Preloading_Attempt::SetPreloadingPredictor(int64_t value)
{
    SetMetricInternal(kPreloadingPredictorNameHash, value);
    return *this;
}

const char Preloading_Attempt::kPreloadingTypeName[] = "PreloadingType";
const uint64_t Preloading_Attempt::kPreloadingTypeNameHash;

Preloading_Attempt& Preloading_Attempt::SetPreloadingType(int64_t value)
{
    SetMetricInternal(kPreloadingTypeNameHash, value);
    return *this;
}

const char Preloading_Attempt::kTriggeringOutcomeName[] = "TriggeringOutcome";
const uint64_t Preloading_Attempt::kTriggeringOutcomeNameHash;

Preloading_Attempt& Preloading_Attempt::SetTriggeringOutcome(int64_t value)
{
    SetMetricInternal(kTriggeringOutcomeNameHash, value);
    return *this;
}
const char Preloading_Attempt_PreviousPrimaryPage::kEntryName[] = "Preloading.Attempt.PreviousPrimaryPage";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kEntryNameHash;

Preloading_Attempt_PreviousPrimaryPage::Preloading_Attempt_PreviousPrimaryPage(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Attempt_PreviousPrimaryPage::Preloading_Attempt_PreviousPrimaryPage(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Attempt_PreviousPrimaryPage::~Preloading_Attempt_PreviousPrimaryPage() = default;
const char Preloading_Attempt_PreviousPrimaryPage::kAccurateTriggeringName[] = "AccurateTriggering";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kAccurateTriggeringNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetAccurateTriggering(int64_t value)
{
    SetMetricInternal(kAccurateTriggeringNameHash, value);
    return *this;
}

const char Preloading_Attempt_PreviousPrimaryPage::kEligibilityName[] = "Eligibility";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kEligibilityNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetEligibility(int64_t value)
{
    SetMetricInternal(kEligibilityNameHash, value);
    return *this;
}

const char Preloading_Attempt_PreviousPrimaryPage::kFailureReasonName[] = "FailureReason";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kFailureReasonNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetFailureReason(int64_t value)
{
    SetMetricInternal(kFailureReasonNameHash, value);
    return *this;
}

const char Preloading_Attempt_PreviousPrimaryPage::kHoldbackStatusName[] = "HoldbackStatus";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kHoldbackStatusNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetHoldbackStatus(int64_t value)
{
    SetMetricInternal(kHoldbackStatusNameHash, value);
    return *this;
}

const char Preloading_Attempt_PreviousPrimaryPage::kPreloadingPredictorName[] = "PreloadingPredictor";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kPreloadingPredictorNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetPreloadingPredictor(int64_t value)
{
    SetMetricInternal(kPreloadingPredictorNameHash, value);
    return *this;
}

const char Preloading_Attempt_PreviousPrimaryPage::kPreloadingTypeName[] = "PreloadingType";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kPreloadingTypeNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetPreloadingType(int64_t value)
{
    SetMetricInternal(kPreloadingTypeNameHash, value);
    return *this;
}

const char Preloading_Attempt_PreviousPrimaryPage::kTriggeringOutcomeName[] = "TriggeringOutcome";
const uint64_t Preloading_Attempt_PreviousPrimaryPage::kTriggeringOutcomeNameHash;

Preloading_Attempt_PreviousPrimaryPage& Preloading_Attempt_PreviousPrimaryPage::SetTriggeringOutcome(int64_t value)
{
    SetMetricInternal(kTriggeringOutcomeNameHash, value);
    return *this;
}
const char Preloading_Prediction::kEntryName[] = "Preloading.Prediction";
const uint64_t Preloading_Prediction::kEntryNameHash;

Preloading_Prediction::Preloading_Prediction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Prediction::Preloading_Prediction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Prediction::~Preloading_Prediction() = default;
const char Preloading_Prediction::kAccuratePredictionName[] = "AccuratePrediction";
const uint64_t Preloading_Prediction::kAccuratePredictionNameHash;

Preloading_Prediction& Preloading_Prediction::SetAccuratePrediction(int64_t value)
{
    SetMetricInternal(kAccuratePredictionNameHash, value);
    return *this;
}

const char Preloading_Prediction::kConfidenceName[] = "Confidence";
const uint64_t Preloading_Prediction::kConfidenceNameHash;

Preloading_Prediction& Preloading_Prediction::SetConfidence(int64_t value)
{
    SetMetricInternal(kConfidenceNameHash, value);
    return *this;
}

const char Preloading_Prediction::kPreloadingPredictorName[] = "PreloadingPredictor";
const uint64_t Preloading_Prediction::kPreloadingPredictorNameHash;

Preloading_Prediction& Preloading_Prediction::SetPreloadingPredictor(int64_t value)
{
    SetMetricInternal(kPreloadingPredictorNameHash, value);
    return *this;
}
const char Preloading_Prediction_PreviousPrimaryPage::kEntryName[] = "Preloading.Prediction.PreviousPrimaryPage";
const uint64_t Preloading_Prediction_PreviousPrimaryPage::kEntryNameHash;

Preloading_Prediction_PreviousPrimaryPage::Preloading_Prediction_PreviousPrimaryPage(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Prediction_PreviousPrimaryPage::Preloading_Prediction_PreviousPrimaryPage(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Preloading_Prediction_PreviousPrimaryPage::~Preloading_Prediction_PreviousPrimaryPage() = default;
const char Preloading_Prediction_PreviousPrimaryPage::kAccuratePredictionName[] = "AccuratePrediction";
const uint64_t Preloading_Prediction_PreviousPrimaryPage::kAccuratePredictionNameHash;

Preloading_Prediction_PreviousPrimaryPage& Preloading_Prediction_PreviousPrimaryPage::SetAccuratePrediction(int64_t value)
{
    SetMetricInternal(kAccuratePredictionNameHash, value);
    return *this;
}

const char Preloading_Prediction_PreviousPrimaryPage::kConfidenceName[] = "Confidence";
const uint64_t Preloading_Prediction_PreviousPrimaryPage::kConfidenceNameHash;

Preloading_Prediction_PreviousPrimaryPage& Preloading_Prediction_PreviousPrimaryPage::SetConfidence(int64_t value)
{
    SetMetricInternal(kConfidenceNameHash, value);
    return *this;
}

const char Preloading_Prediction_PreviousPrimaryPage::kPreloadingPredictorName[] = "PreloadingPredictor";
const uint64_t Preloading_Prediction_PreviousPrimaryPage::kPreloadingPredictorNameHash;

Preloading_Prediction_PreviousPrimaryPage& Preloading_Prediction_PreviousPrimaryPage::SetPreloadingPredictor(int64_t value)
{
    SetMetricInternal(kPreloadingPredictorNameHash, value);
    return *this;
}
const char PrerenderPageLoad::kEntryName[] = "PrerenderPageLoad";
const uint64_t PrerenderPageLoad::kEntryNameHash;

PrerenderPageLoad::PrerenderPageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrerenderPageLoad::PrerenderPageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PrerenderPageLoad::~PrerenderPageLoad() = default;
const char PrerenderPageLoad::kFinalStatusName[] = "FinalStatus";
const uint64_t PrerenderPageLoad::kFinalStatusNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetFinalStatus(int64_t value)
{
    SetMetricInternal(kFinalStatusNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationName[]
    = "InteractiveTiming.AverageUserInteractionLatencyOverBudget.MaxEventDuration";
const uint64_t PrerenderPageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kInteractiveTiming_FirstInputDelay4Name[] = "InteractiveTiming.FirstInputDelay4";
const uint64_t PrerenderPageLoad::kInteractiveTiming_FirstInputDelay4NameHash;

PrerenderPageLoad& PrerenderPageLoad::SetInteractiveTiming_FirstInputDelay4(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_FirstInputDelay4NameHash, value);
    return *this;
}

const char PrerenderPageLoad::kInteractiveTiming_NumInteractionsName[] = "InteractiveTiming.NumInteractions";
const uint64_t PrerenderPageLoad::kInteractiveTiming_NumInteractionsNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetInteractiveTiming_NumInteractions(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_NumInteractionsNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName[]
    = "InteractiveTiming.UserInteractionLatency.HighPercentile2.MaxEventDuration";
const uint64_t PrerenderPageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName[] = "InteractiveTiming.WorstUserInteractionLatency.MaxEventDuration";
const uint64_t PrerenderPageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetInteractiveTiming_WorstUserInteractionLatency_MaxEventDuration(int64_t value)
{
    SetMetricInternal(kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName[]
    = "LayoutInstability.MaxCumulativeShiftScore.SessionWindow.Gap1000ms.Max5000ms";
const uint64_t PrerenderPageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000ms(int64_t value)
{
    SetMetricInternal(kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kTiming_ActivationToFirstContentfulPaintName[] = "Timing.ActivationToFirstContentfulPaint";
const uint64_t PrerenderPageLoad::kTiming_ActivationToFirstContentfulPaintNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetTiming_ActivationToFirstContentfulPaint(int64_t value)
{
    SetMetricInternal(kTiming_ActivationToFirstContentfulPaintNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kTiming_ActivationToLargestContentfulPaintName[] = "Timing.ActivationToLargestContentfulPaint";
const uint64_t PrerenderPageLoad::kTiming_ActivationToLargestContentfulPaintNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetTiming_ActivationToLargestContentfulPaint(int64_t value)
{
    SetMetricInternal(kTiming_ActivationToLargestContentfulPaintNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kTiming_NavigationToActivationName[] = "Timing.NavigationToActivation";
const uint64_t PrerenderPageLoad::kTiming_NavigationToActivationNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetTiming_NavigationToActivation(int64_t value)
{
    SetMetricInternal(kTiming_NavigationToActivationNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kTriggeredPrerenderName[] = "TriggeredPrerender";
const uint64_t PrerenderPageLoad::kTriggeredPrerenderNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetTriggeredPrerender(int64_t value)
{
    SetMetricInternal(kTriggeredPrerenderNameHash, value);
    return *this;
}

const char PrerenderPageLoad::kWasPrerenderedName[] = "WasPrerendered";
const uint64_t PrerenderPageLoad::kWasPrerenderedNameHash;

PrerenderPageLoad& PrerenderPageLoad::SetWasPrerendered(int64_t value)
{
    SetMetricInternal(kWasPrerenderedNameHash, value);
    return *this;
}
const char Presentation_StartResult::kEntryName[] = "Presentation.StartResult";
const uint64_t Presentation_StartResult::kEntryNameHash;

Presentation_StartResult::Presentation_StartResult(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Presentation_StartResult::Presentation_StartResult(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Presentation_StartResult::~Presentation_StartResult() = default;
const char Presentation_StartResult::kPresentationRequestName[] = "PresentationRequest";
const uint64_t Presentation_StartResult::kPresentationRequestNameHash;

Presentation_StartResult& Presentation_StartResult::SetPresentationRequest(int64_t value)
{
    SetMetricInternal(kPresentationRequestNameHash, value);
    return *this;
}

const char Presentation_StartResult::kRemotePlaybackName[] = "RemotePlayback";
const uint64_t Presentation_StartResult::kRemotePlaybackNameHash;

Presentation_StartResult& Presentation_StartResult::SetRemotePlayback(int64_t value)
{
    SetMetricInternal(kRemotePlaybackNameHash, value);
    return *this;
}
const char PWA_Visit::kEntryName[] = "PWA.Visit";
const uint64_t PWA_Visit::kEntryNameHash;

PWA_Visit::PWA_Visit(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PWA_Visit::PWA_Visit(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

PWA_Visit::~PWA_Visit() = default;
const char PWA_Visit::kLaunchSourceName[] = "LaunchSource";
const uint64_t PWA_Visit::kLaunchSourceNameHash;

PWA_Visit& PWA_Visit::SetLaunchSource(int64_t value)
{
    SetMetricInternal(kLaunchSourceNameHash, value);
    return *this;
}

const char PWA_Visit::kWebAPKableSiteVisitName[] = "WebAPKableSiteVisit";
const uint64_t PWA_Visit::kWebAPKableSiteVisitNameHash;

PWA_Visit& PWA_Visit::SetWebAPKableSiteVisit(int64_t value)
{
    SetMetricInternal(kWebAPKableSiteVisitNameHash, value);
    return *this;
}
const char ReaderModeActivated::kEntryName[] = "ReaderModeActivated";
const uint64_t ReaderModeActivated::kEntryNameHash;

ReaderModeActivated::ReaderModeActivated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ReaderModeActivated::ReaderModeActivated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ReaderModeActivated::~ReaderModeActivated() = default;
const char ReaderModeActivated::kActivatedViaOmniboxName[] = "ActivatedViaOmnibox";
const uint64_t ReaderModeActivated::kActivatedViaOmniboxNameHash;

ReaderModeActivated& ReaderModeActivated::SetActivatedViaOmnibox(int64_t value)
{
    SetMetricInternal(kActivatedViaOmniboxNameHash, value);
    return *this;
}
const char ReaderModeReceivedDistillability::kEntryName[] = "ReaderModeReceivedDistillability";
const uint64_t ReaderModeReceivedDistillability::kEntryNameHash;

ReaderModeReceivedDistillability::ReaderModeReceivedDistillability(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ReaderModeReceivedDistillability::ReaderModeReceivedDistillability(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ReaderModeReceivedDistillability::~ReaderModeReceivedDistillability() = default;
const char ReaderModeReceivedDistillability::kIsPageDistillableName[] = "IsPageDistillable";
const uint64_t ReaderModeReceivedDistillability::kIsPageDistillableNameHash;

ReaderModeReceivedDistillability& ReaderModeReceivedDistillability::SetIsPageDistillable(int64_t value)
{
    SetMetricInternal(kIsPageDistillableNameHash, value);
    return *this;
}
const char RendererSchedulerTask::kEntryName[] = "RendererSchedulerTask";
const uint64_t RendererSchedulerTask::kEntryNameHash;

RendererSchedulerTask::RendererSchedulerTask(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

RendererSchedulerTask::RendererSchedulerTask(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

RendererSchedulerTask::~RendererSchedulerTask() = default;
const char RendererSchedulerTask::kFrameStatusName[] = "FrameStatus";
const uint64_t RendererSchedulerTask::kFrameStatusNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetFrameStatus(int64_t value)
{
    SetMetricInternal(kFrameStatusNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kIsOOPIFName[] = "IsOOPIF";
const uint64_t RendererSchedulerTask::kIsOOPIFNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetIsOOPIF(int64_t value)
{
    SetMetricInternal(kIsOOPIFNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kPageSchedulersName[] = "PageSchedulers";
const uint64_t RendererSchedulerTask::kPageSchedulersNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetPageSchedulers(int64_t value)
{
    SetMetricInternal(kPageSchedulersNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kQueueTypeName[] = "QueueType";
const uint64_t RendererSchedulerTask::kQueueTypeNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetQueueType(int64_t value)
{
    SetMetricInternal(kQueueTypeNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kRendererAudibleName[] = "RendererAudible";
const uint64_t RendererSchedulerTask::kRendererAudibleNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetRendererAudible(int64_t value)
{
    SetMetricInternal(kRendererAudibleNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kRendererBackgroundedName[] = "RendererBackgrounded";
const uint64_t RendererSchedulerTask::kRendererBackgroundedNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetRendererBackgrounded(int64_t value)
{
    SetMetricInternal(kRendererBackgroundedNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kRendererHiddenName[] = "RendererHidden";
const uint64_t RendererSchedulerTask::kRendererHiddenNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetRendererHidden(int64_t value)
{
    SetMetricInternal(kRendererHiddenNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kSecondsSinceBackgroundedName[] = "SecondsSinceBackgrounded";
const uint64_t RendererSchedulerTask::kSecondsSinceBackgroundedNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetSecondsSinceBackgrounded(int64_t value)
{
    SetMetricInternal(kSecondsSinceBackgroundedNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kTaskCPUDurationName[] = "TaskCPUDuration";
const uint64_t RendererSchedulerTask::kTaskCPUDurationNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetTaskCPUDuration(int64_t value)
{
    SetMetricInternal(kTaskCPUDurationNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kTaskDurationName[] = "TaskDuration";
const uint64_t RendererSchedulerTask::kTaskDurationNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetTaskDuration(int64_t value)
{
    SetMetricInternal(kTaskDurationNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kTaskTypeName[] = "TaskType";
const uint64_t RendererSchedulerTask::kTaskTypeNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetTaskType(int64_t value)
{
    SetMetricInternal(kTaskTypeNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kThreadTypeName[] = "ThreadType";
const uint64_t RendererSchedulerTask::kThreadTypeNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetThreadType(int64_t value)
{
    SetMetricInternal(kThreadTypeNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kUseCaseName[] = "UseCase";
const uint64_t RendererSchedulerTask::kUseCaseNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetUseCase(int64_t value)
{
    SetMetricInternal(kUseCaseNameHash, value);
    return *this;
}

const char RendererSchedulerTask::kVersionName[] = "Version";
const uint64_t RendererSchedulerTask::kVersionNameHash;

RendererSchedulerTask& RendererSchedulerTask::SetVersion(int64_t value)
{
    SetMetricInternal(kVersionNameHash, value);
    return *this;
}
const char RenderViewContextMenu_Used::kEntryName[] = "RenderViewContextMenu.Used";
const uint64_t RenderViewContextMenu_Used::kEntryNameHash;

RenderViewContextMenu_Used::RenderViewContextMenu_Used(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

RenderViewContextMenu_Used::RenderViewContextMenu_Used(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

RenderViewContextMenu_Used::~RenderViewContextMenu_Used() = default;
const char RenderViewContextMenu_Used::kSelectedMenuItemName[] = "SelectedMenuItem";
const uint64_t RenderViewContextMenu_Used::kSelectedMenuItemNameHash;

RenderViewContextMenu_Used& RenderViewContextMenu_Used::SetSelectedMenuItem(int64_t value)
{
    SetMetricInternal(kSelectedMenuItemNameHash, value);
    return *this;
}
const char Responsiveness_UserInteraction::kEntryName[] = "Responsiveness.UserInteraction";
const uint64_t Responsiveness_UserInteraction::kEntryNameHash;

Responsiveness_UserInteraction::Responsiveness_UserInteraction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Responsiveness_UserInteraction::Responsiveness_UserInteraction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Responsiveness_UserInteraction::~Responsiveness_UserInteraction() = default;
const char Responsiveness_UserInteraction::kInteractionTypeName[] = "InteractionType";
const uint64_t Responsiveness_UserInteraction::kInteractionTypeNameHash;

Responsiveness_UserInteraction& Responsiveness_UserInteraction::SetInteractionType(int64_t value)
{
    SetMetricInternal(kInteractionTypeNameHash, value);
    return *this;
}

const char Responsiveness_UserInteraction::kMaxEventDurationName[] = "MaxEventDuration";
const uint64_t Responsiveness_UserInteraction::kMaxEventDurationNameHash;

Responsiveness_UserInteraction& Responsiveness_UserInteraction::SetMaxEventDuration(int64_t value)
{
    SetMetricInternal(kMaxEventDurationNameHash, value);
    return *this;
}

const char Responsiveness_UserInteraction::kTotalEventDurationName[] = "TotalEventDuration";
const uint64_t Responsiveness_UserInteraction::kTotalEventDurationNameHash;

Responsiveness_UserInteraction& Responsiveness_UserInteraction::SetTotalEventDuration(int64_t value)
{
    SetMetricInternal(kTotalEventDurationNameHash, value);
    return *this;
}
const char ResponsivenessMeasurement::kEntryName[] = "ResponsivenessMeasurement";
const uint64_t ResponsivenessMeasurement::kEntryNameHash;

ResponsivenessMeasurement::ResponsivenessMeasurement(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ResponsivenessMeasurement::ResponsivenessMeasurement(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ResponsivenessMeasurement::~ResponsivenessMeasurement() = default;

const char SalientImageAvailability::kEntryName[] = "SalientImageAvailability";
const uint64_t SalientImageAvailability::kEntryNameHash;

SalientImageAvailability::SalientImageAvailability(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SalientImageAvailability::SalientImageAvailability(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SalientImageAvailability::~SalientImageAvailability() = default;
const char SalientImageAvailability::kImageAvailabilityName[] = "ImageAvailability";
const uint64_t SalientImageAvailability::kImageAvailabilityNameHash;

SalientImageAvailability& SalientImageAvailability::SetImageAvailability(int64_t value)
{
    SetMetricInternal(kImageAvailabilityNameHash, value);
    return *this;
}
const char SameSiteDifferentSchemeRequest::kEntryName[] = "SameSiteDifferentSchemeRequest";
const uint64_t SameSiteDifferentSchemeRequest::kEntryNameHash;

SameSiteDifferentSchemeRequest::SameSiteDifferentSchemeRequest(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SameSiteDifferentSchemeRequest::SameSiteDifferentSchemeRequest(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SameSiteDifferentSchemeRequest::~SameSiteDifferentSchemeRequest() = default;

const char SameSiteDifferentSchemeResponse::kEntryName[] = "SameSiteDifferentSchemeResponse";
const uint64_t SameSiteDifferentSchemeResponse::kEntryNameHash;

SameSiteDifferentSchemeResponse::SameSiteDifferentSchemeResponse(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SameSiteDifferentSchemeResponse::SameSiteDifferentSchemeResponse(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SameSiteDifferentSchemeResponse::~SameSiteDifferentSchemeResponse() = default;

const char SchemefulSameSiteContextDowngrade::kEntryName[] = "SchemefulSameSiteContextDowngrade";
const uint64_t SchemefulSameSiteContextDowngrade::kEntryNameHash;

SchemefulSameSiteContextDowngrade::SchemefulSameSiteContextDowngrade(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SchemefulSameSiteContextDowngrade::SchemefulSameSiteContextDowngrade(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SchemefulSameSiteContextDowngrade::~SchemefulSameSiteContextDowngrade() = default;
const char SchemefulSameSiteContextDowngrade::kRequestPerCookieName[] = "RequestPerCookie";
const uint64_t SchemefulSameSiteContextDowngrade::kRequestPerCookieNameHash;

SchemefulSameSiteContextDowngrade& SchemefulSameSiteContextDowngrade::SetRequestPerCookie(int64_t value)
{
    SetMetricInternal(kRequestPerCookieNameHash, value);
    return *this;
}

const char SchemefulSameSiteContextDowngrade::kResponsePerCookieName[] = "ResponsePerCookie";
const uint64_t SchemefulSameSiteContextDowngrade::kResponsePerCookieNameHash;

SchemefulSameSiteContextDowngrade& SchemefulSameSiteContextDowngrade::SetResponsePerCookie(int64_t value)
{
    SetMetricInternal(kResponsePerCookieNameHash, value);
    return *this;
}
const char ScreenBrightness::kEntryName[] = "ScreenBrightness";
const uint64_t ScreenBrightness::kEntryNameHash;

ScreenBrightness::ScreenBrightness(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ScreenBrightness::ScreenBrightness(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

ScreenBrightness::~ScreenBrightness() = default;
const char ScreenBrightness::kBatteryPercentName[] = "BatteryPercent";
const uint64_t ScreenBrightness::kBatteryPercentNameHash;

ScreenBrightness& ScreenBrightness::SetBatteryPercent(int64_t value)
{
    SetMetricInternal(kBatteryPercentNameHash, value);
    return *this;
}

const char ScreenBrightness::kBrightnessName[] = "Brightness";
const uint64_t ScreenBrightness::kBrightnessNameHash;

ScreenBrightness& ScreenBrightness::SetBrightness(int64_t value)
{
    SetMetricInternal(kBrightnessNameHash, value);
    return *this;
}

const char ScreenBrightness::kDayOfWeekName[] = "DayOfWeek";
const uint64_t ScreenBrightness::kDayOfWeekNameHash;

ScreenBrightness& ScreenBrightness::SetDayOfWeek(int64_t value)
{
    SetMetricInternal(kDayOfWeekNameHash, value);
    return *this;
}

const char ScreenBrightness::kDeviceModeName[] = "DeviceMode";
const uint64_t ScreenBrightness::kDeviceModeNameHash;

ScreenBrightness& ScreenBrightness::SetDeviceMode(int64_t value)
{
    SetMetricInternal(kDeviceModeNameHash, value);
    return *this;
}

const char ScreenBrightness::kHourOfDayName[] = "HourOfDay";
const uint64_t ScreenBrightness::kHourOfDayNameHash;

ScreenBrightness& ScreenBrightness::SetHourOfDay(int64_t value)
{
    SetMetricInternal(kHourOfDayNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsAutoclickEnabledName[] = "IsAutoclickEnabled";
const uint64_t ScreenBrightness::kIsAutoclickEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsAutoclickEnabled(int64_t value)
{
    SetMetricInternal(kIsAutoclickEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsBrailleDisplayConnectedName[] = "IsBrailleDisplayConnected";
const uint64_t ScreenBrightness::kIsBrailleDisplayConnectedNameHash;

ScreenBrightness& ScreenBrightness::SetIsBrailleDisplayConnected(int64_t value)
{
    SetMetricInternal(kIsBrailleDisplayConnectedNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsCaretHighlightEnabledName[] = "IsCaretHighlightEnabled";
const uint64_t ScreenBrightness::kIsCaretHighlightEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsCaretHighlightEnabled(int64_t value)
{
    SetMetricInternal(kIsCaretHighlightEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsCursorHighlightEnabledName[] = "IsCursorHighlightEnabled";
const uint64_t ScreenBrightness::kIsCursorHighlightEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsCursorHighlightEnabled(int64_t value)
{
    SetMetricInternal(kIsCursorHighlightEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsFocusHighlightEnabledName[] = "IsFocusHighlightEnabled";
const uint64_t ScreenBrightness::kIsFocusHighlightEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsFocusHighlightEnabled(int64_t value)
{
    SetMetricInternal(kIsFocusHighlightEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsHighContrastEnabledName[] = "IsHighContrastEnabled";
const uint64_t ScreenBrightness::kIsHighContrastEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsHighContrastEnabled(int64_t value)
{
    SetMetricInternal(kIsHighContrastEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsLargeCursorEnabledName[] = "IsLargeCursorEnabled";
const uint64_t ScreenBrightness::kIsLargeCursorEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsLargeCursorEnabled(int64_t value)
{
    SetMetricInternal(kIsLargeCursorEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsMagnifierEnabledName[] = "IsMagnifierEnabled";
const uint64_t ScreenBrightness::kIsMagnifierEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsMagnifierEnabled(int64_t value)
{
    SetMetricInternal(kIsMagnifierEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsMonoAudioEnabledName[] = "IsMonoAudioEnabled";
const uint64_t ScreenBrightness::kIsMonoAudioEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsMonoAudioEnabled(int64_t value)
{
    SetMetricInternal(kIsMonoAudioEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsSelectToSpeakEnabledName[] = "IsSelectToSpeakEnabled";
const uint64_t ScreenBrightness::kIsSelectToSpeakEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsSelectToSpeakEnabled(int64_t value)
{
    SetMetricInternal(kIsSelectToSpeakEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsSpokenFeedbackEnabledName[] = "IsSpokenFeedbackEnabled";
const uint64_t ScreenBrightness::kIsSpokenFeedbackEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsSpokenFeedbackEnabled(int64_t value)
{
    SetMetricInternal(kIsSpokenFeedbackEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsSwitchAccessEnabledName[] = "IsSwitchAccessEnabled";
const uint64_t ScreenBrightness::kIsSwitchAccessEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsSwitchAccessEnabled(int64_t value)
{
    SetMetricInternal(kIsSwitchAccessEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsVideoPlayingName[] = "IsVideoPlaying";
const uint64_t ScreenBrightness::kIsVideoPlayingNameHash;

ScreenBrightness& ScreenBrightness::SetIsVideoPlaying(int64_t value)
{
    SetMetricInternal(kIsVideoPlayingNameHash, value);
    return *this;
}

const char ScreenBrightness::kIsVirtualKeyboardEnabledName[] = "IsVirtualKeyboardEnabled";
const uint64_t ScreenBrightness::kIsVirtualKeyboardEnabledNameHash;

ScreenBrightness& ScreenBrightness::SetIsVirtualKeyboardEnabled(int64_t value)
{
    SetMetricInternal(kIsVirtualKeyboardEnabledNameHash, value);
    return *this;
}

const char ScreenBrightness::kLastActivityTimeSecName[] = "LastActivityTimeSec";
const uint64_t ScreenBrightness::kLastActivityTimeSecNameHash;

ScreenBrightness& ScreenBrightness::SetLastActivityTimeSec(int64_t value)
{
    SetMetricInternal(kLastActivityTimeSecNameHash, value);
    return *this;
}

const char ScreenBrightness::kNightLightTemperaturePercentName[] = "NightLightTemperaturePercent";
const uint64_t ScreenBrightness::kNightLightTemperaturePercentNameHash;

ScreenBrightness& ScreenBrightness::SetNightLightTemperaturePercent(int64_t value)
{
    SetMetricInternal(kNightLightTemperaturePercentNameHash, value);
    return *this;
}

const char ScreenBrightness::kNumRecentKeyEventsName[] = "NumRecentKeyEvents";
const uint64_t ScreenBrightness::kNumRecentKeyEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentKeyEvents(int64_t value)
{
    SetMetricInternal(kNumRecentKeyEventsNameHash, value);
    return *this;
}

const char ScreenBrightness::kNumRecentMouseEventsName[] = "NumRecentMouseEvents";
const uint64_t ScreenBrightness::kNumRecentMouseEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentMouseEvents(int64_t value)
{
    SetMetricInternal(kNumRecentMouseEventsNameHash, value);
    return *this;
}

const char ScreenBrightness::kNumRecentStylusEventsName[] = "NumRecentStylusEvents";
const uint64_t ScreenBrightness::kNumRecentStylusEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentStylusEvents(int64_t value)
{
    SetMetricInternal(kNumRecentStylusEventsNameHash, value);
    return *this;
}

const char ScreenBrightness::kNumRecentTouchEventsName[] = "NumRecentTouchEvents";
const uint64_t ScreenBrightness::kNumRecentTouchEventsNameHash;

ScreenBrightness& ScreenBrightness::SetNumRecentTouchEvents(int64_t value)
{
    SetMetricInternal(kNumRecentTouchEventsNameHash, value);
    return *this;
}

const char ScreenBrightness::kOnBatteryName[] = "OnBattery";
const uint64_t ScreenBrightness::kOnBatteryNameHash;

ScreenBrightness& ScreenBrightness::SetOnBattery(int64_t value)
{
    SetMetricInternal(kOnBatteryNameHash, value);
    return *this;
}

const char ScreenBrightness::kPreviousBrightnessName[] = "PreviousBrightness";
const uint64_t ScreenBrightness::kPreviousBrightnessNameHash;

ScreenBrightness& ScreenBrightness::SetPreviousBrightness(int64_t value)
{
    SetMetricInternal(kPreviousBrightnessNameHash, value);
    return *this;
}

const char ScreenBrightness::kReasonName[] = "Reason";
const uint64_t ScreenBrightness::kReasonNameHash;

ScreenBrightness& ScreenBrightness::SetReason(int64_t value)
{
    SetMetricInternal(kReasonNameHash, value);
    return *this;
}

const char ScreenBrightness::kRecentTimeActiveSecName[] = "RecentTimeActiveSec";
const uint64_t ScreenBrightness::kRecentTimeActiveSecNameHash;

ScreenBrightness& ScreenBrightness::SetRecentTimeActiveSec(int64_t value)
{
    SetMetricInternal(kRecentTimeActiveSecNameHash, value);
    return *this;
}

const char ScreenBrightness::kSequenceIdName[] = "SequenceId";
const uint64_t ScreenBrightness::kSequenceIdNameHash;

ScreenBrightness& ScreenBrightness::SetSequenceId(int64_t value)
{
    SetMetricInternal(kSequenceIdNameHash, value);
    return *this;
}

const char ScreenBrightness::kTimeSinceLastEventSecName[] = "TimeSinceLastEventSec";
const uint64_t ScreenBrightness::kTimeSinceLastEventSecNameHash;

ScreenBrightness& ScreenBrightness::SetTimeSinceLastEventSec(int64_t value)
{
    SetMetricInternal(kTimeSinceLastEventSecNameHash, value);
    return *this;
}
const char Security_SafetyTip::kEntryName[] = "Security.SafetyTip";
const uint64_t Security_SafetyTip::kEntryNameHash;

Security_SafetyTip::Security_SafetyTip(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Security_SafetyTip::Security_SafetyTip(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Security_SafetyTip::~Security_SafetyTip() = default;
const char Security_SafetyTip::kSafetyTipInteractionName[] = "SafetyTipInteraction";
const uint64_t Security_SafetyTip::kSafetyTipInteractionNameHash;

Security_SafetyTip& Security_SafetyTip::SetSafetyTipInteraction(int64_t value)
{
    SetMetricInternal(kSafetyTipInteractionNameHash, value);
    return *this;
}

const char Security_SafetyTip::kSafetyTipStatusName[] = "SafetyTipStatus";
const uint64_t Security_SafetyTip::kSafetyTipStatusNameHash;

Security_SafetyTip& Security_SafetyTip::SetSafetyTipStatus(int64_t value)
{
    SetMetricInternal(kSafetyTipStatusNameHash, value);
    return *this;
}

const char Security_SafetyTip::kTriggeredKeywordsHeuristicsName[] = "TriggeredKeywordsHeuristics";
const uint64_t Security_SafetyTip::kTriggeredKeywordsHeuristicsNameHash;

Security_SafetyTip& Security_SafetyTip::SetTriggeredKeywordsHeuristics(int64_t value)
{
    SetMetricInternal(kTriggeredKeywordsHeuristicsNameHash, value);
    return *this;
}

const char Security_SafetyTip::kTriggeredLookalikeHeuristicsName[] = "TriggeredLookalikeHeuristics";
const uint64_t Security_SafetyTip::kTriggeredLookalikeHeuristicsNameHash;

Security_SafetyTip& Security_SafetyTip::SetTriggeredLookalikeHeuristics(int64_t value)
{
    SetMetricInternal(kTriggeredLookalikeHeuristicsNameHash, value);
    return *this;
}

const char Security_SafetyTip::kTriggeredServerSideBlocklistName[] = "TriggeredServerSideBlocklist";
const uint64_t Security_SafetyTip::kTriggeredServerSideBlocklistNameHash;

Security_SafetyTip& Security_SafetyTip::SetTriggeredServerSideBlocklist(int64_t value)
{
    SetMetricInternal(kTriggeredServerSideBlocklistNameHash, value);
    return *this;
}

const char Security_SafetyTip::kUserPreviouslyIgnoredName[] = "UserPreviouslyIgnored";
const uint64_t Security_SafetyTip::kUserPreviouslyIgnoredNameHash;

Security_SafetyTip& Security_SafetyTip::SetUserPreviouslyIgnored(int64_t value)
{
    SetMetricInternal(kUserPreviouslyIgnoredNameHash, value);
    return *this;
}
const char Security_SiteEngagement::kEntryName[] = "Security.SiteEngagement";
const uint64_t Security_SiteEngagement::kEntryNameHash;

Security_SiteEngagement::Security_SiteEngagement(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Security_SiteEngagement::Security_SiteEngagement(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Security_SiteEngagement::~Security_SiteEngagement() = default;
const char Security_SiteEngagement::kFinalSecurityLevelName[] = "FinalSecurityLevel";
const uint64_t Security_SiteEngagement::kFinalSecurityLevelNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetFinalSecurityLevel(int64_t value)
{
    SetMetricInternal(kFinalSecurityLevelNameHash, value);
    return *this;
}

const char Security_SiteEngagement::kInitialSecurityLevelName[] = "InitialSecurityLevel";
const uint64_t Security_SiteEngagement::kInitialSecurityLevelNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetInitialSecurityLevel(int64_t value)
{
    SetMetricInternal(kInitialSecurityLevelNameHash, value);
    return *this;
}

const char Security_SiteEngagement::kSafetyTipStatusName[] = "SafetyTipStatus";
const uint64_t Security_SiteEngagement::kSafetyTipStatusNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetSafetyTipStatus(int64_t value)
{
    SetMetricInternal(kSafetyTipStatusNameHash, value);
    return *this;
}

const char Security_SiteEngagement::kScoreDeltaName[] = "ScoreDelta";
const uint64_t Security_SiteEngagement::kScoreDeltaNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetScoreDelta(int64_t value)
{
    SetMetricInternal(kScoreDeltaNameHash, value);
    return *this;
}

const char Security_SiteEngagement::kScoreFinalName[] = "ScoreFinal";
const uint64_t Security_SiteEngagement::kScoreFinalNameHash;

Security_SiteEngagement& Security_SiteEngagement::SetScoreFinal(int64_t value)
{
    SetMetricInternal(kScoreFinalNameHash, value);
    return *this;
}
const char Segmentation_ModelExecution::kEntryName[] = "Segmentation.ModelExecution";
const uint64_t Segmentation_ModelExecution::kEntryNameHash;

Segmentation_ModelExecution::Segmentation_ModelExecution(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Segmentation_ModelExecution::Segmentation_ModelExecution(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Segmentation_ModelExecution::~Segmentation_ModelExecution() = default;
const char Segmentation_ModelExecution::kActualResultName[] = "ActualResult";
const uint64_t Segmentation_ModelExecution::kActualResultNameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetActualResult(int64_t value)
{
    SetMetricInternal(kActualResultNameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kActualResult2Name[] = "ActualResult2";
const uint64_t Segmentation_ModelExecution::kActualResult2NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetActualResult2(int64_t value)
{
    SetMetricInternal(kActualResult2NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kActualResult3Name[] = "ActualResult3";
const uint64_t Segmentation_ModelExecution::kActualResult3NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetActualResult3(int64_t value)
{
    SetMetricInternal(kActualResult3NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kActualResult4Name[] = "ActualResult4";
const uint64_t Segmentation_ModelExecution::kActualResult4NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetActualResult4(int64_t value)
{
    SetMetricInternal(kActualResult4NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kActualResult5Name[] = "ActualResult5";
const uint64_t Segmentation_ModelExecution::kActualResult5NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetActualResult5(int64_t value)
{
    SetMetricInternal(kActualResult5NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kActualResult6Name[] = "ActualResult6";
const uint64_t Segmentation_ModelExecution::kActualResult6NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetActualResult6(int64_t value)
{
    SetMetricInternal(kActualResult6NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput0Name[] = "Input0";
const uint64_t Segmentation_ModelExecution::kInput0NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput0(int64_t value)
{
    SetMetricInternal(kInput0NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput1Name[] = "Input1";
const uint64_t Segmentation_ModelExecution::kInput1NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput1(int64_t value)
{
    SetMetricInternal(kInput1NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput10Name[] = "Input10";
const uint64_t Segmentation_ModelExecution::kInput10NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput10(int64_t value)
{
    SetMetricInternal(kInput10NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput11Name[] = "Input11";
const uint64_t Segmentation_ModelExecution::kInput11NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput11(int64_t value)
{
    SetMetricInternal(kInput11NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput12Name[] = "Input12";
const uint64_t Segmentation_ModelExecution::kInput12NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput12(int64_t value)
{
    SetMetricInternal(kInput12NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput13Name[] = "Input13";
const uint64_t Segmentation_ModelExecution::kInput13NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput13(int64_t value)
{
    SetMetricInternal(kInput13NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput14Name[] = "Input14";
const uint64_t Segmentation_ModelExecution::kInput14NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput14(int64_t value)
{
    SetMetricInternal(kInput14NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput15Name[] = "Input15";
const uint64_t Segmentation_ModelExecution::kInput15NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput15(int64_t value)
{
    SetMetricInternal(kInput15NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput16Name[] = "Input16";
const uint64_t Segmentation_ModelExecution::kInput16NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput16(int64_t value)
{
    SetMetricInternal(kInput16NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput17Name[] = "Input17";
const uint64_t Segmentation_ModelExecution::kInput17NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput17(int64_t value)
{
    SetMetricInternal(kInput17NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput18Name[] = "Input18";
const uint64_t Segmentation_ModelExecution::kInput18NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput18(int64_t value)
{
    SetMetricInternal(kInput18NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput19Name[] = "Input19";
const uint64_t Segmentation_ModelExecution::kInput19NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput19(int64_t value)
{
    SetMetricInternal(kInput19NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput2Name[] = "Input2";
const uint64_t Segmentation_ModelExecution::kInput2NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput2(int64_t value)
{
    SetMetricInternal(kInput2NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput20Name[] = "Input20";
const uint64_t Segmentation_ModelExecution::kInput20NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput20(int64_t value)
{
    SetMetricInternal(kInput20NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput21Name[] = "Input21";
const uint64_t Segmentation_ModelExecution::kInput21NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput21(int64_t value)
{
    SetMetricInternal(kInput21NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput22Name[] = "Input22";
const uint64_t Segmentation_ModelExecution::kInput22NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput22(int64_t value)
{
    SetMetricInternal(kInput22NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput23Name[] = "Input23";
const uint64_t Segmentation_ModelExecution::kInput23NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput23(int64_t value)
{
    SetMetricInternal(kInput23NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput24Name[] = "Input24";
const uint64_t Segmentation_ModelExecution::kInput24NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput24(int64_t value)
{
    SetMetricInternal(kInput24NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput25Name[] = "Input25";
const uint64_t Segmentation_ModelExecution::kInput25NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput25(int64_t value)
{
    SetMetricInternal(kInput25NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput26Name[] = "Input26";
const uint64_t Segmentation_ModelExecution::kInput26NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput26(int64_t value)
{
    SetMetricInternal(kInput26NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput27Name[] = "Input27";
const uint64_t Segmentation_ModelExecution::kInput27NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput27(int64_t value)
{
    SetMetricInternal(kInput27NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput28Name[] = "Input28";
const uint64_t Segmentation_ModelExecution::kInput28NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput28(int64_t value)
{
    SetMetricInternal(kInput28NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput29Name[] = "Input29";
const uint64_t Segmentation_ModelExecution::kInput29NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput29(int64_t value)
{
    SetMetricInternal(kInput29NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput3Name[] = "Input3";
const uint64_t Segmentation_ModelExecution::kInput3NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput3(int64_t value)
{
    SetMetricInternal(kInput3NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput4Name[] = "Input4";
const uint64_t Segmentation_ModelExecution::kInput4NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput4(int64_t value)
{
    SetMetricInternal(kInput4NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput5Name[] = "Input5";
const uint64_t Segmentation_ModelExecution::kInput5NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput5(int64_t value)
{
    SetMetricInternal(kInput5NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput6Name[] = "Input6";
const uint64_t Segmentation_ModelExecution::kInput6NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput6(int64_t value)
{
    SetMetricInternal(kInput6NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput7Name[] = "Input7";
const uint64_t Segmentation_ModelExecution::kInput7NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput7(int64_t value)
{
    SetMetricInternal(kInput7NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput8Name[] = "Input8";
const uint64_t Segmentation_ModelExecution::kInput8NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput8(int64_t value)
{
    SetMetricInternal(kInput8NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kInput9Name[] = "Input9";
const uint64_t Segmentation_ModelExecution::kInput9NameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetInput9(int64_t value)
{
    SetMetricInternal(kInput9NameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kModelVersionName[] = "ModelVersion";
const uint64_t Segmentation_ModelExecution::kModelVersionNameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetModelVersion(int64_t value)
{
    SetMetricInternal(kModelVersionNameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kOptimizationTargetName[] = "OptimizationTarget";
const uint64_t Segmentation_ModelExecution::kOptimizationTargetNameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetOptimizationTarget(int64_t value)
{
    SetMetricInternal(kOptimizationTargetNameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kOutputDelaySecName[] = "OutputDelaySec";
const uint64_t Segmentation_ModelExecution::kOutputDelaySecNameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetOutputDelaySec(int64_t value)
{
    SetMetricInternal(kOutputDelaySecNameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kPredictionResultName[] = "PredictionResult";
const uint64_t Segmentation_ModelExecution::kPredictionResultNameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetPredictionResult(int64_t value)
{
    SetMetricInternal(kPredictionResultNameHash, value);
    return *this;
}

const char Segmentation_ModelExecution::kSelectionResultName[] = "SelectionResult";
const uint64_t Segmentation_ModelExecution::kSelectionResultNameHash;

Segmentation_ModelExecution& Segmentation_ModelExecution::SetSelectionResult(int64_t value)
{
    SetMetricInternal(kSelectionResultNameHash, value);
    return *this;
}
const char SharedHighlights_LinkGenerated::kEntryName[] = "SharedHighlights.LinkGenerated";
const uint64_t SharedHighlights_LinkGenerated::kEntryNameHash;

SharedHighlights_LinkGenerated::SharedHighlights_LinkGenerated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SharedHighlights_LinkGenerated::SharedHighlights_LinkGenerated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SharedHighlights_LinkGenerated::~SharedHighlights_LinkGenerated() = default;
const char SharedHighlights_LinkGenerated::kErrorName[] = "Error";
const uint64_t SharedHighlights_LinkGenerated::kErrorNameHash;

SharedHighlights_LinkGenerated& SharedHighlights_LinkGenerated::SetError(int64_t value)
{
    SetMetricInternal(kErrorNameHash, value);
    return *this;
}

const char SharedHighlights_LinkGenerated::kSuccessName[] = "Success";
const uint64_t SharedHighlights_LinkGenerated::kSuccessNameHash;

SharedHighlights_LinkGenerated& SharedHighlights_LinkGenerated::SetSuccess(int64_t value)
{
    SetMetricInternal(kSuccessNameHash, value);
    return *this;
}
const char SharedHighlights_LinkGenerated_Requested::kEntryName[] = "SharedHighlights.LinkGenerated.Requested";
const uint64_t SharedHighlights_LinkGenerated_Requested::kEntryNameHash;

SharedHighlights_LinkGenerated_Requested::SharedHighlights_LinkGenerated_Requested(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SharedHighlights_LinkGenerated_Requested::SharedHighlights_LinkGenerated_Requested(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SharedHighlights_LinkGenerated_Requested::~SharedHighlights_LinkGenerated_Requested() = default;
const char SharedHighlights_LinkGenerated_Requested::kErrorName[] = "Error";
const uint64_t SharedHighlights_LinkGenerated_Requested::kErrorNameHash;

SharedHighlights_LinkGenerated_Requested& SharedHighlights_LinkGenerated_Requested::SetError(int64_t value)
{
    SetMetricInternal(kErrorNameHash, value);
    return *this;
}

const char SharedHighlights_LinkGenerated_Requested::kSuccessName[] = "Success";
const uint64_t SharedHighlights_LinkGenerated_Requested::kSuccessNameHash;

SharedHighlights_LinkGenerated_Requested& SharedHighlights_LinkGenerated_Requested::SetSuccess(int64_t value)
{
    SetMetricInternal(kSuccessNameHash, value);
    return *this;
}
const char SharedHighlights_LinkOpened::kEntryName[] = "SharedHighlights.LinkOpened";
const uint64_t SharedHighlights_LinkOpened::kEntryNameHash;

SharedHighlights_LinkOpened::SharedHighlights_LinkOpened(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SharedHighlights_LinkOpened::SharedHighlights_LinkOpened(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SharedHighlights_LinkOpened::~SharedHighlights_LinkOpened() = default;
const char SharedHighlights_LinkOpened::kSourceName[] = "Source";
const uint64_t SharedHighlights_LinkOpened::kSourceNameHash;

SharedHighlights_LinkOpened& SharedHighlights_LinkOpened::SetSource(int64_t value)
{
    SetMetricInternal(kSourceNameHash, value);
    return *this;
}

const char SharedHighlights_LinkOpened::kSuccessName[] = "Success";
const uint64_t SharedHighlights_LinkOpened::kSuccessNameHash;

SharedHighlights_LinkOpened& SharedHighlights_LinkOpened::SetSuccess(int64_t value)
{
    SetMetricInternal(kSuccessNameHash, value);
    return *this;
}
const char Sharing_ClickToCall::kEntryName[] = "Sharing.ClickToCall";
const uint64_t Sharing_ClickToCall::kEntryNameHash;

Sharing_ClickToCall::Sharing_ClickToCall(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Sharing_ClickToCall::Sharing_ClickToCall(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Sharing_ClickToCall::~Sharing_ClickToCall() = default;
const char Sharing_ClickToCall::kEntryPointName[] = "EntryPoint";
const uint64_t Sharing_ClickToCall::kEntryPointNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetEntryPoint(int64_t value)
{
    SetMetricInternal(kEntryPointNameHash, value);
    return *this;
}

const char Sharing_ClickToCall::kHasAppsName[] = "HasApps";
const uint64_t Sharing_ClickToCall::kHasAppsNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetHasApps(int64_t value)
{
    SetMetricInternal(kHasAppsNameHash, value);
    return *this;
}

const char Sharing_ClickToCall::kHasDevicesName[] = "HasDevices";
const uint64_t Sharing_ClickToCall::kHasDevicesNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetHasDevices(int64_t value)
{
    SetMetricInternal(kHasDevicesNameHash, value);
    return *this;
}

const char Sharing_ClickToCall::kSelectionName[] = "Selection";
const uint64_t Sharing_ClickToCall::kSelectionNameHash;

Sharing_ClickToCall& Sharing_ClickToCall::SetSelection(int64_t value)
{
    SetMetricInternal(kSelectionNameHash, value);
    return *this;
}
const char Shopping_CartExtraction::kEntryName[] = "Shopping.CartExtraction";
const uint64_t Shopping_CartExtraction::kEntryNameHash;

Shopping_CartExtraction::Shopping_CartExtraction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_CartExtraction::Shopping_CartExtraction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_CartExtraction::~Shopping_CartExtraction() = default;
const char Shopping_CartExtraction::kExtractionElapsedTimeName[] = "ExtractionElapsedTime";
const uint64_t Shopping_CartExtraction::kExtractionElapsedTimeNameHash;

Shopping_CartExtraction& Shopping_CartExtraction::SetExtractionElapsedTime(int64_t value)
{
    SetMetricInternal(kExtractionElapsedTimeNameHash, value);
    return *this;
}

const char Shopping_CartExtraction::kExtractionExecutionTimeName[] = "ExtractionExecutionTime";
const uint64_t Shopping_CartExtraction::kExtractionExecutionTimeNameHash;

Shopping_CartExtraction& Shopping_CartExtraction::SetExtractionExecutionTime(int64_t value)
{
    SetMetricInternal(kExtractionExecutionTimeNameHash, value);
    return *this;
}

const char Shopping_CartExtraction::kExtractionLongestTaskTimeName[] = "ExtractionLongestTaskTime";
const uint64_t Shopping_CartExtraction::kExtractionLongestTaskTimeNameHash;

Shopping_CartExtraction& Shopping_CartExtraction::SetExtractionLongestTaskTime(int64_t value)
{
    SetMetricInternal(kExtractionLongestTaskTimeNameHash, value);
    return *this;
}

const char Shopping_CartExtraction::kExtractionTimedOutName[] = "ExtractionTimedOut";
const uint64_t Shopping_CartExtraction::kExtractionTimedOutNameHash;

Shopping_CartExtraction& Shopping_CartExtraction::SetExtractionTimedOut(int64_t value)
{
    SetMetricInternal(kExtractionTimedOutNameHash, value);
    return *this;
}

const char Shopping_CartExtraction::kExtractionTotalTasksTimeName[] = "ExtractionTotalTasksTime";
const uint64_t Shopping_CartExtraction::kExtractionTotalTasksTimeNameHash;

Shopping_CartExtraction& Shopping_CartExtraction::SetExtractionTotalTasksTime(int64_t value)
{
    SetMetricInternal(kExtractionTotalTasksTimeNameHash, value);
    return *this;
}
const char Shopping_ChromeCart::kEntryName[] = "Shopping.ChromeCart";
const uint64_t Shopping_ChromeCart::kEntryNameHash;

Shopping_ChromeCart::Shopping_ChromeCart(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_ChromeCart::Shopping_ChromeCart(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_ChromeCart::~Shopping_ChromeCart() = default;
const char Shopping_ChromeCart::kVisitCartName[] = "VisitCart";
const uint64_t Shopping_ChromeCart::kVisitCartNameHash;

Shopping_ChromeCart& Shopping_ChromeCart::SetVisitCart(int64_t value)
{
    SetMetricInternal(kVisitCartNameHash, value);
    return *this;
}
const char Shopping_FormSubmitted::kEntryName[] = "Shopping.FormSubmitted";
const uint64_t Shopping_FormSubmitted::kEntryNameHash;

Shopping_FormSubmitted::Shopping_FormSubmitted(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_FormSubmitted::Shopping_FormSubmitted(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_FormSubmitted::~Shopping_FormSubmitted() = default;
const char Shopping_FormSubmitted::kIsTransactionName[] = "IsTransaction";
const uint64_t Shopping_FormSubmitted::kIsTransactionNameHash;

Shopping_FormSubmitted& Shopping_FormSubmitted::SetIsTransaction(int64_t value)
{
    SetMetricInternal(kIsTransactionNameHash, value);
    return *this;
}
const char Shopping_MerchantTrust_DataAvailable::kEntryName[] = "Shopping.MerchantTrust.DataAvailable";
const uint64_t Shopping_MerchantTrust_DataAvailable::kEntryNameHash;

Shopping_MerchantTrust_DataAvailable::Shopping_MerchantTrust_DataAvailable(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_DataAvailable::Shopping_MerchantTrust_DataAvailable(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_DataAvailable::~Shopping_MerchantTrust_DataAvailable() = default;
const char Shopping_MerchantTrust_DataAvailable::kDataAvailableName[] = "DataAvailable";
const uint64_t Shopping_MerchantTrust_DataAvailable::kDataAvailableNameHash;

Shopping_MerchantTrust_DataAvailable& Shopping_MerchantTrust_DataAvailable::SetDataAvailable(int64_t value)
{
    SetMetricInternal(kDataAvailableNameHash, value);
    return *this;
}
const char Shopping_MerchantTrust_MessageClicked::kEntryName[] = "Shopping.MerchantTrust.MessageClicked";
const uint64_t Shopping_MerchantTrust_MessageClicked::kEntryNameHash;

Shopping_MerchantTrust_MessageClicked::Shopping_MerchantTrust_MessageClicked(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_MessageClicked::Shopping_MerchantTrust_MessageClicked(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_MessageClicked::~Shopping_MerchantTrust_MessageClicked() = default;
const char Shopping_MerchantTrust_MessageClicked::kHasOccurredName[] = "HasOccurred";
const uint64_t Shopping_MerchantTrust_MessageClicked::kHasOccurredNameHash;

Shopping_MerchantTrust_MessageClicked& Shopping_MerchantTrust_MessageClicked::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char Shopping_MerchantTrust_MessageSeen::kEntryName[] = "Shopping.MerchantTrust.MessageSeen";
const uint64_t Shopping_MerchantTrust_MessageSeen::kEntryNameHash;

Shopping_MerchantTrust_MessageSeen::Shopping_MerchantTrust_MessageSeen(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_MessageSeen::Shopping_MerchantTrust_MessageSeen(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_MessageSeen::~Shopping_MerchantTrust_MessageSeen() = default;
const char Shopping_MerchantTrust_MessageSeen::kHasOccurredName[] = "HasOccurred";
const uint64_t Shopping_MerchantTrust_MessageSeen::kHasOccurredNameHash;

Shopping_MerchantTrust_MessageSeen& Shopping_MerchantTrust_MessageSeen::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char Shopping_MerchantTrust_RowClicked::kEntryName[] = "Shopping.MerchantTrust.RowClicked";
const uint64_t Shopping_MerchantTrust_RowClicked::kEntryNameHash;

Shopping_MerchantTrust_RowClicked::Shopping_MerchantTrust_RowClicked(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_RowClicked::Shopping_MerchantTrust_RowClicked(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_RowClicked::~Shopping_MerchantTrust_RowClicked() = default;
const char Shopping_MerchantTrust_RowClicked::kHasOccurredName[] = "HasOccurred";
const uint64_t Shopping_MerchantTrust_RowClicked::kHasOccurredNameHash;

Shopping_MerchantTrust_RowClicked& Shopping_MerchantTrust_RowClicked::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char Shopping_MerchantTrust_RowSeen::kEntryName[] = "Shopping.MerchantTrust.RowSeen";
const uint64_t Shopping_MerchantTrust_RowSeen::kEntryNameHash;

Shopping_MerchantTrust_RowSeen::Shopping_MerchantTrust_RowSeen(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_RowSeen::Shopping_MerchantTrust_RowSeen(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_MerchantTrust_RowSeen::~Shopping_MerchantTrust_RowSeen() = default;
const char Shopping_MerchantTrust_RowSeen::kHasOccurredName[] = "HasOccurred";
const uint64_t Shopping_MerchantTrust_RowSeen::kHasOccurredNameHash;

Shopping_MerchantTrust_RowSeen& Shopping_MerchantTrust_RowSeen::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char Shopping_WillSendRequest::kEntryName[] = "Shopping.WillSendRequest";
const uint64_t Shopping_WillSendRequest::kEntryNameHash;

Shopping_WillSendRequest::Shopping_WillSendRequest(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_WillSendRequest::Shopping_WillSendRequest(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Shopping_WillSendRequest::~Shopping_WillSendRequest() = default;
const char Shopping_WillSendRequest::kIsAddToCartName[] = "IsAddToCart";
const uint64_t Shopping_WillSendRequest::kIsAddToCartNameHash;

Shopping_WillSendRequest& Shopping_WillSendRequest::SetIsAddToCart(int64_t value)
{
    SetMetricInternal(kIsAddToCartNameHash, value);
    return *this;
}
const char SmartCharging::kEntryName[] = "SmartCharging";
const uint64_t SmartCharging::kEntryNameHash;

SmartCharging::SmartCharging(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SmartCharging::SmartCharging(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SmartCharging::~SmartCharging() = default;
const char SmartCharging::kBatteryPercentageName[] = "BatteryPercentage";
const uint64_t SmartCharging::kBatteryPercentageNameHash;

SmartCharging& SmartCharging::SetBatteryPercentage(int64_t value)
{
    SetMetricInternal(kBatteryPercentageNameHash, value);
    return *this;
}

const char SmartCharging::kBatteryPercentageBeforeLastChargeName[] = "BatteryPercentageBeforeLastCharge";
const uint64_t SmartCharging::kBatteryPercentageBeforeLastChargeNameHash;

SmartCharging& SmartCharging::SetBatteryPercentageBeforeLastCharge(int64_t value)
{
    SetMetricInternal(kBatteryPercentageBeforeLastChargeNameHash, value);
    return *this;
}

const char SmartCharging::kBatteryPercentageOfLastChargeName[] = "BatteryPercentageOfLastCharge";
const uint64_t SmartCharging::kBatteryPercentageOfLastChargeNameHash;

SmartCharging& SmartCharging::SetBatteryPercentageOfLastCharge(int64_t value)
{
    SetMetricInternal(kBatteryPercentageOfLastChargeNameHash, value);
    return *this;
}

const char SmartCharging::kDayOfMonthName[] = "DayOfMonth";
const uint64_t SmartCharging::kDayOfMonthNameHash;

SmartCharging& SmartCharging::SetDayOfMonth(int64_t value)
{
    SetMetricInternal(kDayOfMonthNameHash, value);
    return *this;
}

const char SmartCharging::kDayOfWeekName[] = "DayOfWeek";
const uint64_t SmartCharging::kDayOfWeekNameHash;

SmartCharging& SmartCharging::SetDayOfWeek(int64_t value)
{
    SetMetricInternal(kDayOfWeekNameHash, value);
    return *this;
}

const char SmartCharging::kDeviceModeName[] = "DeviceMode";
const uint64_t SmartCharging::kDeviceModeNameHash;

SmartCharging& SmartCharging::SetDeviceMode(int64_t value)
{
    SetMetricInternal(kDeviceModeNameHash, value);
    return *this;
}

const char SmartCharging::kDeviceTypeName[] = "DeviceType";
const uint64_t SmartCharging::kDeviceTypeNameHash;

SmartCharging& SmartCharging::SetDeviceType(int64_t value)
{
    SetMetricInternal(kDeviceTypeNameHash, value);
    return *this;
}

const char SmartCharging::kDurationOfLastChargeName[] = "DurationOfLastCharge";
const uint64_t SmartCharging::kDurationOfLastChargeNameHash;

SmartCharging& SmartCharging::SetDurationOfLastCharge(int64_t value)
{
    SetMetricInternal(kDurationOfLastChargeNameHash, value);
    return *this;
}

const char SmartCharging::kDurationRecentAudioPlayingName[] = "DurationRecentAudioPlaying";
const uint64_t SmartCharging::kDurationRecentAudioPlayingNameHash;

SmartCharging& SmartCharging::SetDurationRecentAudioPlaying(int64_t value)
{
    SetMetricInternal(kDurationRecentAudioPlayingNameHash, value);
    return *this;
}

const char SmartCharging::kDurationRecentVideoPlayingName[] = "DurationRecentVideoPlaying";
const uint64_t SmartCharging::kDurationRecentVideoPlayingNameHash;

SmartCharging& SmartCharging::SetDurationRecentVideoPlaying(int64_t value)
{
    SetMetricInternal(kDurationRecentVideoPlayingNameHash, value);
    return *this;
}

const char SmartCharging::kEventIdName[] = "EventId";
const uint64_t SmartCharging::kEventIdNameHash;

SmartCharging& SmartCharging::SetEventId(int64_t value)
{
    SetMetricInternal(kEventIdNameHash, value);
    return *this;
}

const char SmartCharging::kHaltFromLastChargeName[] = "HaltFromLastCharge";
const uint64_t SmartCharging::kHaltFromLastChargeNameHash;

SmartCharging& SmartCharging::SetHaltFromLastCharge(int64_t value)
{
    SetMetricInternal(kHaltFromLastChargeNameHash, value);
    return *this;
}

const char SmartCharging::kIsChargingName[] = "IsCharging";
const uint64_t SmartCharging::kIsChargingNameHash;

SmartCharging& SmartCharging::SetIsCharging(int64_t value)
{
    SetMetricInternal(kIsChargingNameHash, value);
    return *this;
}

const char SmartCharging::kMonthName[] = "Month";
const uint64_t SmartCharging::kMonthNameHash;

SmartCharging& SmartCharging::SetMonth(int64_t value)
{
    SetMetricInternal(kMonthNameHash, value);
    return *this;
}

const char SmartCharging::kNumRecentKeyEventsName[] = "NumRecentKeyEvents";
const uint64_t SmartCharging::kNumRecentKeyEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentKeyEvents(int64_t value)
{
    SetMetricInternal(kNumRecentKeyEventsNameHash, value);
    return *this;
}

const char SmartCharging::kNumRecentMouseEventsName[] = "NumRecentMouseEvents";
const uint64_t SmartCharging::kNumRecentMouseEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentMouseEvents(int64_t value)
{
    SetMetricInternal(kNumRecentMouseEventsNameHash, value);
    return *this;
}

const char SmartCharging::kNumRecentStylusEventsName[] = "NumRecentStylusEvents";
const uint64_t SmartCharging::kNumRecentStylusEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentStylusEvents(int64_t value)
{
    SetMetricInternal(kNumRecentStylusEventsNameHash, value);
    return *this;
}

const char SmartCharging::kNumRecentTouchEventsName[] = "NumRecentTouchEvents";
const uint64_t SmartCharging::kNumRecentTouchEventsNameHash;

SmartCharging& SmartCharging::SetNumRecentTouchEvents(int64_t value)
{
    SetMetricInternal(kNumRecentTouchEventsNameHash, value);
    return *this;
}

const char SmartCharging::kReasonName[] = "Reason";
const uint64_t SmartCharging::kReasonNameHash;

SmartCharging& SmartCharging::SetReason(int64_t value)
{
    SetMetricInternal(kReasonNameHash, value);
    return *this;
}

const char SmartCharging::kScreenBrightnessPercentName[] = "ScreenBrightnessPercent";
const uint64_t SmartCharging::kScreenBrightnessPercentNameHash;

SmartCharging& SmartCharging::SetScreenBrightnessPercent(int64_t value)
{
    SetMetricInternal(kScreenBrightnessPercentNameHash, value);
    return *this;
}

const char SmartCharging::kTimeOfTheDayName[] = "TimeOfTheDay";
const uint64_t SmartCharging::kTimeOfTheDayNameHash;

SmartCharging& SmartCharging::SetTimeOfTheDay(int64_t value)
{
    SetMetricInternal(kTimeOfTheDayNameHash, value);
    return *this;
}

const char SmartCharging::kTimeSinceLastChargeName[] = "TimeSinceLastCharge";
const uint64_t SmartCharging::kTimeSinceLastChargeNameHash;

SmartCharging& SmartCharging::SetTimeSinceLastCharge(int64_t value)
{
    SetMetricInternal(kTimeSinceLastChargeNameHash, value);
    return *this;
}

const char SmartCharging::kTimezoneDifferenceFromLastChargeName[] = "TimezoneDifferenceFromLastCharge";
const uint64_t SmartCharging::kTimezoneDifferenceFromLastChargeNameHash;

SmartCharging& SmartCharging::SetTimezoneDifferenceFromLastCharge(int64_t value)
{
    SetMetricInternal(kTimezoneDifferenceFromLastChargeNameHash, value);
    return *this;
}

const char SmartCharging::kVoltageName[] = "Voltage";
const uint64_t SmartCharging::kVoltageNameHash;

SmartCharging& SmartCharging::SetVoltage(int64_t value)
{
    SetMetricInternal(kVoltageNameHash, value);
    return *this;
}
const char SMSReceiver::kEntryName[] = "SMSReceiver";
const uint64_t SMSReceiver::kEntryNameHash;

SMSReceiver::SMSReceiver(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SMSReceiver::SMSReceiver(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SMSReceiver::~SMSReceiver() = default;
const char SMSReceiver::kIsCrossOriginFrameName[] = "IsCrossOriginFrame";
const uint64_t SMSReceiver::kIsCrossOriginFrameNameHash;

SMSReceiver& SMSReceiver::SetIsCrossOriginFrame(int64_t value)
{
    SetMetricInternal(kIsCrossOriginFrameNameHash, value);
    return *this;
}

const char SMSReceiver::kOutcomeName[] = "Outcome";
const uint64_t SMSReceiver::kOutcomeNameHash;

SMSReceiver& SMSReceiver::SetOutcome(int64_t value)
{
    SetMetricInternal(kOutcomeNameHash, value);
    return *this;
}

const char SMSReceiver::kSmsParsingStatusName[] = "SmsParsingStatus";
const uint64_t SMSReceiver::kSmsParsingStatusNameHash;

SMSReceiver& SMSReceiver::SetSmsParsingStatus(int64_t value)
{
    SetMetricInternal(kSmsParsingStatusNameHash, value);
    return *this;
}

const char SMSReceiver::kTimeSmsReceiveMsName[] = "TimeSmsReceiveMs";
const uint64_t SMSReceiver::kTimeSmsReceiveMsNameHash;

SMSReceiver& SMSReceiver::SetTimeSmsReceiveMs(int64_t value)
{
    SetMetricInternal(kTimeSmsReceiveMsNameHash, value);
    return *this;
}

const char SMSReceiver::kTimeSuccessMsName[] = "TimeSuccessMs";
const uint64_t SMSReceiver::kTimeSuccessMsNameHash;

SMSReceiver& SMSReceiver::SetTimeSuccessMs(int64_t value)
{
    SetMetricInternal(kTimeSuccessMsNameHash, value);
    return *this;
}

const char SMSReceiver::kTimeUserCancelMsName[] = "TimeUserCancelMs";
const uint64_t SMSReceiver::kTimeUserCancelMsNameHash;

SMSReceiver& SMSReceiver::SetTimeUserCancelMs(int64_t value)
{
    SetMetricInternal(kTimeUserCancelMsNameHash, value);
    return *this;
}
const char SSL_MixedContentShown2::kEntryName[] = "SSL.MixedContentShown2";
const uint64_t SSL_MixedContentShown2::kEntryNameHash;

SSL_MixedContentShown2::SSL_MixedContentShown2(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SSL_MixedContentShown2::SSL_MixedContentShown2(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SSL_MixedContentShown2::~SSL_MixedContentShown2() = default;
const char SSL_MixedContentShown2::kTypeName[] = "Type";
const uint64_t SSL_MixedContentShown2::kTypeNameHash;

SSL_MixedContentShown2& SSL_MixedContentShown2::SetType(int64_t value)
{
    SetMetricInternal(kTypeNameHash, value);
    return *this;
}
const char SubresourceFilter::kEntryName[] = "SubresourceFilter";
const uint64_t SubresourceFilter::kEntryNameHash;

SubresourceFilter::SubresourceFilter(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SubresourceFilter::SubresourceFilter(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SubresourceFilter::~SubresourceFilter() = default;
const char SubresourceFilter::kActivationDecisionName[] = "ActivationDecision";
const uint64_t SubresourceFilter::kActivationDecisionNameHash;

SubresourceFilter& SubresourceFilter::SetActivationDecision(int64_t value)
{
    SetMetricInternal(kActivationDecisionNameHash, value);
    return *this;
}

const char SubresourceFilter::kDryRunName[] = "DryRun";
const uint64_t SubresourceFilter::kDryRunNameHash;

SubresourceFilter& SubresourceFilter::SetDryRun(int64_t value)
{
    SetMetricInternal(kDryRunNameHash, value);
    return *this;
}

const char SubresourceFilter::kEnforcementRedirectPositionName[] = "EnforcementRedirectPosition";
const uint64_t SubresourceFilter::kEnforcementRedirectPositionNameHash;

SubresourceFilter& SubresourceFilter::SetEnforcementRedirectPosition(int64_t value)
{
    SetMetricInternal(kEnforcementRedirectPositionNameHash, value);
    return *this;
}
const char SubresourceRedirect_PublicSrcVideoCompression::kEntryName[] = "SubresourceRedirect.PublicSrcVideoCompression";
const uint64_t SubresourceRedirect_PublicSrcVideoCompression::kEntryNameHash;

SubresourceRedirect_PublicSrcVideoCompression::SubresourceRedirect_PublicSrcVideoCompression(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SubresourceRedirect_PublicSrcVideoCompression::SubresourceRedirect_PublicSrcVideoCompression(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

SubresourceRedirect_PublicSrcVideoCompression::~SubresourceRedirect_PublicSrcVideoCompression() = default;
const char SubresourceRedirect_PublicSrcVideoCompression::kFullContentLengthName[] = "FullContentLength";
const uint64_t SubresourceRedirect_PublicSrcVideoCompression::kFullContentLengthNameHash;

SubresourceRedirect_PublicSrcVideoCompression& SubresourceRedirect_PublicSrcVideoCompression::SetFullContentLength(int64_t value)
{
    SetMetricInternal(kFullContentLengthNameHash, value);
    return *this;
}

const char SubresourceRedirect_PublicSrcVideoCompression::kSubresourceRedirectResultName[] = "SubresourceRedirectResult";
const uint64_t SubresourceRedirect_PublicSrcVideoCompression::kSubresourceRedirectResultNameHash;

SubresourceRedirect_PublicSrcVideoCompression& SubresourceRedirect_PublicSrcVideoCompression::SetSubresourceRedirectResult(int64_t value)
{
    SetMetricInternal(kSubresourceRedirectResultNameHash, value);
    return *this;
}
const char Tab_RendererOOM::kEntryName[] = "Tab.RendererOOM";
const uint64_t Tab_RendererOOM::kEntryNameHash;

Tab_RendererOOM::Tab_RendererOOM(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Tab_RendererOOM::Tab_RendererOOM(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Tab_RendererOOM::~Tab_RendererOOM() = default;
const char Tab_RendererOOM::kTimeSinceLastNavigationName[] = "TimeSinceLastNavigation";
const uint64_t Tab_RendererOOM::kTimeSinceLastNavigationNameHash;

Tab_RendererOOM& Tab_RendererOOM::SetTimeSinceLastNavigation(int64_t value)
{
    SetMetricInternal(kTimeSinceLastNavigationNameHash, value);
    return *this;
}
const char Tab_Screenshot::kEntryName[] = "Tab.Screenshot";
const uint64_t Tab_Screenshot::kEntryNameHash;

Tab_Screenshot::Tab_Screenshot(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Tab_Screenshot::Tab_Screenshot(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Tab_Screenshot::~Tab_Screenshot() = default;
const char Tab_Screenshot::kHasOccurredName[] = "HasOccurred";
const uint64_t Tab_Screenshot::kHasOccurredNameHash;

Tab_Screenshot& Tab_Screenshot::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char TabManager_Background_FirstAlertFired::kEntryName[] = "TabManager.Background.FirstAlertFired";
const uint64_t TabManager_Background_FirstAlertFired::kEntryNameHash;

TabManager_Background_FirstAlertFired::TabManager_Background_FirstAlertFired(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstAlertFired::TabManager_Background_FirstAlertFired(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstAlertFired::~TabManager_Background_FirstAlertFired() = default;
const char TabManager_Background_FirstAlertFired::kIsMainFrameName[] = "IsMainFrame";
const uint64_t TabManager_Background_FirstAlertFired::kIsMainFrameNameHash;

TabManager_Background_FirstAlertFired& TabManager_Background_FirstAlertFired::SetIsMainFrame(int64_t value)
{
    SetMetricInternal(kIsMainFrameNameHash, value);
    return *this;
}

const char TabManager_Background_FirstAlertFired::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstAlertFired::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstAlertFired& TabManager_Background_FirstAlertFired::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}
const char TabManager_Background_FirstAudioStarts::kEntryName[] = "TabManager.Background.FirstAudioStarts";
const uint64_t TabManager_Background_FirstAudioStarts::kEntryNameHash;

TabManager_Background_FirstAudioStarts::TabManager_Background_FirstAudioStarts(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstAudioStarts::TabManager_Background_FirstAudioStarts(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstAudioStarts::~TabManager_Background_FirstAudioStarts() = default;
const char TabManager_Background_FirstAudioStarts::kIsMainFrameName[] = "IsMainFrame";
const uint64_t TabManager_Background_FirstAudioStarts::kIsMainFrameNameHash;

TabManager_Background_FirstAudioStarts& TabManager_Background_FirstAudioStarts::SetIsMainFrame(int64_t value)
{
    SetMetricInternal(kIsMainFrameNameHash, value);
    return *this;
}

const char TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstAudioStarts& TabManager_Background_FirstAudioStarts::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}
const char TabManager_Background_FirstFaviconUpdated::kEntryName[] = "TabManager.Background.FirstFaviconUpdated";
const uint64_t TabManager_Background_FirstFaviconUpdated::kEntryNameHash;

TabManager_Background_FirstFaviconUpdated::TabManager_Background_FirstFaviconUpdated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstFaviconUpdated::TabManager_Background_FirstFaviconUpdated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstFaviconUpdated::~TabManager_Background_FirstFaviconUpdated() = default;
const char TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstFaviconUpdated& TabManager_Background_FirstFaviconUpdated::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}
const char TabManager_Background_FirstNonPersistentNotificationCreated::kEntryName[] = "TabManager.Background.FirstNonPersistentNotificationCreated";
const uint64_t TabManager_Background_FirstNonPersistentNotificationCreated::kEntryNameHash;

TabManager_Background_FirstNonPersistentNotificationCreated::TabManager_Background_FirstNonPersistentNotificationCreated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstNonPersistentNotificationCreated::TabManager_Background_FirstNonPersistentNotificationCreated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstNonPersistentNotificationCreated::~TabManager_Background_FirstNonPersistentNotificationCreated() = default;
const char TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameName[] = "IsMainFrame";
const uint64_t TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameNameHash;

TabManager_Background_FirstNonPersistentNotificationCreated& TabManager_Background_FirstNonPersistentNotificationCreated::SetIsMainFrame(int64_t value)
{
    SetMetricInternal(kIsMainFrameNameHash, value);
    return *this;
}

const char TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstNonPersistentNotificationCreated& TabManager_Background_FirstNonPersistentNotificationCreated::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}
const char TabManager_Background_FirstTitleUpdated::kEntryName[] = "TabManager.Background.FirstTitleUpdated";
const uint64_t TabManager_Background_FirstTitleUpdated::kEntryNameHash;

TabManager_Background_FirstTitleUpdated::TabManager_Background_FirstTitleUpdated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstTitleUpdated::TabManager_Background_FirstTitleUpdated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_FirstTitleUpdated::~TabManager_Background_FirstTitleUpdated() = default;
const char TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedNameHash;

TabManager_Background_FirstTitleUpdated& TabManager_Background_FirstTitleUpdated::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}
const char TabManager_Background_ForegroundedOrClosed::kEntryName[] = "TabManager.Background.ForegroundedOrClosed";
const uint64_t TabManager_Background_ForegroundedOrClosed::kEntryNameHash;

TabManager_Background_ForegroundedOrClosed::TabManager_Background_ForegroundedOrClosed(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_ForegroundedOrClosed::TabManager_Background_ForegroundedOrClosed(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Background_ForegroundedOrClosed::~TabManager_Background_ForegroundedOrClosed() = default;
const char TabManager_Background_ForegroundedOrClosed::kIsDiscardedName[] = "IsDiscarded";
const uint64_t TabManager_Background_ForegroundedOrClosed::kIsDiscardedNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetIsDiscarded(int64_t value)
{
    SetMetricInternal(kIsDiscardedNameHash, value);
    return *this;
}

const char TabManager_Background_ForegroundedOrClosed::kIsForegroundedName[] = "IsForegrounded";
const uint64_t TabManager_Background_ForegroundedOrClosed::kIsForegroundedNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetIsForegrounded(int64_t value)
{
    SetMetricInternal(kIsForegroundedNameHash, value);
    return *this;
}

const char TabManager_Background_ForegroundedOrClosed::kLabelIdName[] = "LabelId";
const uint64_t TabManager_Background_ForegroundedOrClosed::kLabelIdNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetLabelId(int64_t value)
{
    SetMetricInternal(kLabelIdNameHash, value);
    return *this;
}

const char TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedNameHash;

TabManager_Background_ForegroundedOrClosed& TabManager_Background_ForegroundedOrClosed::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}
const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kEntryName[] = "TabManager.Experimental.BackgroundTabOpening.TabSwitchLoadStopped";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kEntryNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::~TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped() = default;
const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountName[] = "BackgroundTabLoadingCount";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetBackgroundTabLoadingCount(int64_t value)
{
    SetMetricInternal(kBackgroundTabLoadingCountNameHash, value);
    return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdName[] = "BackgroundTabOpeningSessionId";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetBackgroundTabOpeningSessionId(
    int64_t value)
{
    SetMetricInternal(kBackgroundTabOpeningSessionIdNameHash, value);
    return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountName[] = "BackgroundTabPendingCount";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetBackgroundTabPendingCount(int64_t value)
{
    SetMetricInternal(kBackgroundTabPendingCountNameHash, value);
    return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetSequenceId(int64_t value)
{
    SetMetricInternal(kSequenceIdNameHash, value);
    return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetSystemTabCount(int64_t value)
{
    SetMetricInternal(kSystemTabCountNameHash, value);
    return *this;
}

const char TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeName[] = "TabSwitchLoadTime";
const uint64_t TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash;

TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped& TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::SetTabSwitchLoadTime(int64_t value)
{
    SetMetricInternal(kTabSwitchLoadTimeNameHash, value);
    return *this;
}
const char TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kEntryName[] = "TabManager.Experimental.SessionRestore.ForegroundTab.PageLoad";
const uint64_t TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kEntryNameHash;

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::~TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad() = default;
const char TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountName[] = "SessionRestoreTabCount";
const uint64_t TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountNameHash;

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad& TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::SetSessionRestoreTabCount(int64_t value)
{
    SetMetricInternal(kSessionRestoreTabCountNameHash, value);
    return *this;
}

const char TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountNameHash;

TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad& TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::SetSystemTabCount(int64_t value)
{
    SetMetricInternal(kSystemTabCountNameHash, value);
    return *this;
}
const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryName[] = "TabManager.Experimental.SessionRestore.TabSwitchLoadStopped";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::TabManager_Experimental_SessionRestore_TabSwitchLoadStopped(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::~TabManager_Experimental_SessionRestore_TabSwitchLoadStopped() = default;
const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSequenceId(int64_t value)
{
    SetMetricInternal(kSequenceIdNameHash, value);
    return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdName[] = "SessionRestoreSessionId";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSessionRestoreSessionId(int64_t value)
{
    SetMetricInternal(kSessionRestoreSessionIdNameHash, value);
    return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountName[] = "SessionRestoreTabCount";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSessionRestoreTabCount(int64_t value)
{
    SetMetricInternal(kSessionRestoreTabCountNameHash, value);
    return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetSystemTabCount(int64_t value)
{
    SetMetricInternal(kSystemTabCountNameHash, value);
    return *this;
}

const char TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeName[] = "TabSwitchLoadTime";
const uint64_t TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash;

TabManager_Experimental_SessionRestore_TabSwitchLoadStopped& TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::SetTabSwitchLoadTime(int64_t value)
{
    SetMetricInternal(kTabSwitchLoadTimeNameHash, value);
    return *this;
}
const char TabManager_LifecycleStateChange::kEntryName[] = "TabManager.LifecycleStateChange";
const uint64_t TabManager_LifecycleStateChange::kEntryNameHash;

TabManager_LifecycleStateChange::TabManager_LifecycleStateChange(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_LifecycleStateChange::TabManager_LifecycleStateChange(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_LifecycleStateChange::~TabManager_LifecycleStateChange() = default;
const char TabManager_LifecycleStateChange::kFailureGlobalDisallowlistName[] = "FailureGlobalDisallowlist";
const uint64_t TabManager_LifecycleStateChange::kFailureGlobalDisallowlistNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureGlobalDisallowlist(int64_t value)
{
    SetMetricInternal(kFailureGlobalDisallowlistNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicAudioName[] = "FailureHeuristicAudio";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicAudioNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicAudio(int64_t value)
{
    SetMetricInternal(kFailureHeuristicAudioNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicFaviconName[] = "FailureHeuristicFavicon";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicFaviconNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicFavicon(int64_t value)
{
    SetMetricInternal(kFailureHeuristicFaviconNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationName[] = "FailureHeuristicInsufficientObservation";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicInsufficientObservation(int64_t value)
{
    SetMetricInternal(kFailureHeuristicInsufficientObservationNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicNotificationsName[] = "FailureHeuristicNotifications";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicNotificationsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicNotifications(int64_t value)
{
    SetMetricInternal(kFailureHeuristicNotificationsNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureHeuristicTitleName[] = "FailureHeuristicTitle";
const uint64_t TabManager_LifecycleStateChange::kFailureHeuristicTitleNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureHeuristicTitle(int64_t value)
{
    SetMetricInternal(kFailureHeuristicTitleNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutName[] = "FailureLifecyclesEnterprisePolicyOptOut";
const uint64_t TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLifecyclesEnterprisePolicyOptOut(int64_t value)
{
    SetMetricInternal(kFailureLifecyclesEnterprisePolicyOptOutNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateCapturingName[] = "FailureLiveStateCapturing";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateCapturingNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateCapturing(int64_t value)
{
    SetMetricInternal(kFailureLiveStateCapturingNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureName[] = "FailureLiveStateDesktopCapture";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateDesktopCapture(int64_t value)
{
    SetMetricInternal(kFailureLiveStateDesktopCaptureNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenName[] = "FailureLiveStateDevToolsOpen";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateDevToolsOpen(int64_t value)
{
    SetMetricInternal(kFailureLiveStateDevToolsOpenNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedName[] = "FailureLiveStateExtensionDisallowed";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateExtensionDisallowed(int64_t value)
{
    SetMetricInternal(kFailureLiveStateExtensionDisallowedNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateFormEntryName[] = "FailureLiveStateFormEntry";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateFormEntryNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateFormEntry(int64_t value)
{
    SetMetricInternal(kFailureLiveStateFormEntryNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionName[] = "FailureLiveStateHasNotificationsPermission";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateHasNotificationsPermission(int64_t value)
{
    SetMetricInternal(kFailureLiveStateHasNotificationsPermissionNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateIsPDFName[] = "FailureLiveStateIsPDF";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateIsPDFNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateIsPDF(int64_t value)
{
    SetMetricInternal(kFailureLiveStateIsPDFNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateMirroringName[] = "FailureLiveStateMirroring";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateMirroringNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateMirroring(int64_t value)
{
    SetMetricInternal(kFailureLiveStateMirroringNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioName[] = "FailureLiveStatePlayingAudio";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStatePlayingAudio(int64_t value)
{
    SetMetricInternal(kFailureLiveStatePlayingAudioNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceName[] = "FailureLiveStateSharingBrowsingInstance";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateSharingBrowsingInstance(int64_t value)
{
    SetMetricInternal(kFailureLiveStateSharingBrowsingInstanceNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothName[] = "FailureLiveStateUsingBluetooth";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingBluetooth(int64_t value)
{
    SetMetricInternal(kFailureLiveStateUsingBluetoothNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockName[] = "FailureLiveStateUsingIndexedDBLock";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingIndexedDBLock(int64_t value)
{
    SetMetricInternal(kFailureLiveStateUsingIndexedDBLockNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockName[] = "FailureLiveStateUsingWebLock";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingWebLock(int64_t value)
{
    SetMetricInternal(kFailureLiveStateUsingWebLockNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsName[] = "FailureLiveStateUsingWebSockets";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingWebSockets(int64_t value)
{
    SetMetricInternal(kFailureLiveStateUsingWebSocketsNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBName[] = "FailureLiveStateUsingWebUSB";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateUsingWebUSB(int64_t value)
{
    SetMetricInternal(kFailureLiveStateUsingWebUSBNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveStateVisibleName[] = "FailureLiveStateVisible";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveStateVisibleNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveStateVisible(int64_t value)
{
    SetMetricInternal(kFailureLiveStateVisibleNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureLiveWebAppName[] = "FailureLiveWebApp";
const uint64_t TabManager_LifecycleStateChange::kFailureLiveWebAppNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureLiveWebApp(int64_t value)
{
    SetMetricInternal(kFailureLiveWebAppNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureOriginTrialOptOutName[] = "FailureOriginTrialOptOut";
const uint64_t TabManager_LifecycleStateChange::kFailureOriginTrialOptOutNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureOriginTrialOptOut(int64_t value)
{
    SetMetricInternal(kFailureOriginTrialOptOutNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kFailureOriginTrialUnknownName[] = "FailureOriginTrialUnknown";
const uint64_t TabManager_LifecycleStateChange::kFailureOriginTrialUnknownNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetFailureOriginTrialUnknown(int64_t value)
{
    SetMetricInternal(kFailureOriginTrialUnknownNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kLifecycleStateChangeReasonName[] = "LifecycleStateChangeReason";
const uint64_t TabManager_LifecycleStateChange::kLifecycleStateChangeReasonNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetLifecycleStateChangeReason(int64_t value)
{
    SetMetricInternal(kLifecycleStateChangeReasonNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kNewLifecycleStateName[] = "NewLifecycleState";
const uint64_t TabManager_LifecycleStateChange::kNewLifecycleStateNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetNewLifecycleState(int64_t value)
{
    SetMetricInternal(kNewLifecycleStateNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kOldLifecycleStateName[] = "OldLifecycleState";
const uint64_t TabManager_LifecycleStateChange::kOldLifecycleStateNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetOldLifecycleState(int64_t value)
{
    SetMetricInternal(kOldLifecycleStateNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kOutcomeName[] = "Outcome";
const uint64_t TabManager_LifecycleStateChange::kOutcomeNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetOutcome(int64_t value)
{
    SetMetricInternal(kOutcomeNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kSuccessGlobalAllowlistName[] = "SuccessGlobalAllowlist";
const uint64_t TabManager_LifecycleStateChange::kSuccessGlobalAllowlistNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetSuccessGlobalAllowlist(int64_t value)
{
    SetMetricInternal(kSuccessGlobalAllowlistNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kSuccessHeuristicName[] = "SuccessHeuristic";
const uint64_t TabManager_LifecycleStateChange::kSuccessHeuristicNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetSuccessHeuristic(int64_t value)
{
    SetMetricInternal(kSuccessHeuristicNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kSuccessOriginTrialOptInName[] = "SuccessOriginTrialOptIn";
const uint64_t TabManager_LifecycleStateChange::kSuccessOriginTrialOptInNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetSuccessOriginTrialOptIn(int64_t value)
{
    SetMetricInternal(kSuccessOriginTrialOptInNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kTimeSinceNavigationMsName[] = "TimeSinceNavigationMs";
const uint64_t TabManager_LifecycleStateChange::kTimeSinceNavigationMsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetTimeSinceNavigationMs(int64_t value)
{
    SetMetricInternal(kTimeSinceNavigationMsNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsName[] = "TimeSinceVisibilityStateChangeMs";
const uint64_t TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetTimeSinceVisibilityStateChangeMs(int64_t value)
{
    SetMetricInternal(kTimeSinceVisibilityStateChangeMsNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kTransitionForcedName[] = "TransitionForced";
const uint64_t TabManager_LifecycleStateChange::kTransitionForcedNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetTransitionForced(int64_t value)
{
    SetMetricInternal(kTransitionForcedNameHash, value);
    return *this;
}

const char TabManager_LifecycleStateChange::kVisibilityStateName[] = "VisibilityState";
const uint64_t TabManager_LifecycleStateChange::kVisibilityStateNameHash;

TabManager_LifecycleStateChange& TabManager_LifecycleStateChange::SetVisibilityState(int64_t value)
{
    SetMetricInternal(kVisibilityStateNameHash, value);
    return *this;
}
const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName[] = "TabManager.SessionRestore.ForegroundTab.ExpectedTaskQueueingDurationInfo";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::~TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo() = default;
const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName[] = "ExpectedTaskQueueingDuration";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetExpectedTaskQueueingDuration(
    int64_t value)
{
    SetMetricInternal(kExpectedTaskQueueingDurationNameHash, value);
    return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName[] = "SequenceId";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSequenceId(int64_t value)
{
    SetMetricInternal(kSequenceIdNameHash, value);
    return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdName[] = "SessionRestoreSessionId";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSessionRestoreSessionId(
    int64_t value)
{
    SetMetricInternal(kSessionRestoreSessionIdNameHash, value);
    return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountName[] = "SessionRestoreTabCount";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSessionRestoreTabCount(
    int64_t value)
{
    SetMetricInternal(kSessionRestoreTabCountNameHash, value);
    return *this;
}

const char TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName[] = "SystemTabCount";
const uint64_t TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash;

TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo& TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::SetSystemTabCount(int64_t value)
{
    SetMetricInternal(kSystemTabCountNameHash, value);
    return *this;
}
const char TabManager_TabLifetime::kEntryName[] = "TabManager.TabLifetime";
const uint64_t TabManager_TabLifetime::kEntryNameHash;

TabManager_TabLifetime::TabManager_TabLifetime(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_TabLifetime::TabManager_TabLifetime(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_TabLifetime::~TabManager_TabLifetime() = default;
const char TabManager_TabLifetime::kTimeSinceNavigationName[] = "TimeSinceNavigation";
const uint64_t TabManager_TabLifetime::kTimeSinceNavigationNameHash;

TabManager_TabLifetime& TabManager_TabLifetime::SetTimeSinceNavigation(int64_t value)
{
    SetMetricInternal(kTimeSinceNavigationNameHash, value);
    return *this;
}
const char TabManager_TabMetrics::kEntryName[] = "TabManager.TabMetrics";
const uint64_t TabManager_TabMetrics::kEntryNameHash;

TabManager_TabMetrics::TabManager_TabMetrics(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_TabMetrics::TabManager_TabMetrics(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_TabMetrics::~TabManager_TabMetrics() = default;
const char TabManager_TabMetrics::kContentTypeName[] = "ContentType";
const uint64_t TabManager_TabMetrics::kContentTypeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetContentType(int64_t value)
{
    SetMetricInternal(kContentTypeNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kDefaultProtocolHandlerName[] = "DefaultProtocolHandler";
const uint64_t TabManager_TabMetrics::kDefaultProtocolHandlerNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetDefaultProtocolHandler(int64_t value)
{
    SetMetricInternal(kDefaultProtocolHandlerNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kHasBeforeUnloadHandlerName[] = "HasBeforeUnloadHandler";
const uint64_t TabManager_TabMetrics::kHasBeforeUnloadHandlerNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetHasBeforeUnloadHandler(int64_t value)
{
    SetMetricInternal(kHasBeforeUnloadHandlerNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kHasFormEntryName[] = "HasFormEntry";
const uint64_t TabManager_TabMetrics::kHasFormEntryNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetHasFormEntry(int64_t value)
{
    SetMetricInternal(kHasFormEntryNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kIsExtensionProtectedName[] = "IsExtensionProtected";
const uint64_t TabManager_TabMetrics::kIsExtensionProtectedNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetIsExtensionProtected(int64_t value)
{
    SetMetricInternal(kIsExtensionProtectedNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kIsPinnedName[] = "IsPinned";
const uint64_t TabManager_TabMetrics::kIsPinnedNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetIsPinned(int64_t value)
{
    SetMetricInternal(kIsPinnedNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kKeyEventCountName[] = "KeyEventCount";
const uint64_t TabManager_TabMetrics::kKeyEventCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetKeyEventCount(int64_t value)
{
    SetMetricInternal(kKeyEventCountNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kLabelIdName[] = "LabelId";
const uint64_t TabManager_TabMetrics::kLabelIdNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetLabelId(int64_t value)
{
    SetMetricInternal(kLabelIdNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kMouseEventCountName[] = "MouseEventCount";
const uint64_t TabManager_TabMetrics::kMouseEventCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetMouseEventCount(int64_t value)
{
    SetMetricInternal(kMouseEventCountNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kMRUIndexName[] = "MRUIndex";
const uint64_t TabManager_TabMetrics::kMRUIndexNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetMRUIndex(int64_t value)
{
    SetMetricInternal(kMRUIndexNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kNavigationEntryCountName[] = "NavigationEntryCount";
const uint64_t TabManager_TabMetrics::kNavigationEntryCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetNavigationEntryCount(int64_t value)
{
    SetMetricInternal(kNavigationEntryCountNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kNumReactivationBeforeName[] = "NumReactivationBefore";
const uint64_t TabManager_TabMetrics::kNumReactivationBeforeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetNumReactivationBefore(int64_t value)
{
    SetMetricInternal(kNumReactivationBeforeNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kPageTransitionCoreTypeName[] = "PageTransitionCoreType";
const uint64_t TabManager_TabMetrics::kPageTransitionCoreTypeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetPageTransitionCoreType(int64_t value)
{
    SetMetricInternal(kPageTransitionCoreTypeNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kPageTransitionFromAddressBarName[] = "PageTransitionFromAddressBar";
const uint64_t TabManager_TabMetrics::kPageTransitionFromAddressBarNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetPageTransitionFromAddressBar(int64_t value)
{
    SetMetricInternal(kPageTransitionFromAddressBarNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kPageTransitionIsRedirectName[] = "PageTransitionIsRedirect";
const uint64_t TabManager_TabMetrics::kPageTransitionIsRedirectNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetPageTransitionIsRedirect(int64_t value)
{
    SetMetricInternal(kPageTransitionIsRedirectNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kQueryIdName[] = "QueryId";
const uint64_t TabManager_TabMetrics::kQueryIdNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetQueryId(int64_t value)
{
    SetMetricInternal(kQueryIdNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kSiteEngagementScoreName[] = "SiteEngagementScore";
const uint64_t TabManager_TabMetrics::kSiteEngagementScoreNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetSiteEngagementScore(int64_t value)
{
    SetMetricInternal(kSiteEngagementScoreNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kTimeFromBackgroundedName[] = "TimeFromBackgrounded";
const uint64_t TabManager_TabMetrics::kTimeFromBackgroundedNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetTimeFromBackgrounded(int64_t value)
{
    SetMetricInternal(kTimeFromBackgroundedNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kTotalTabCountName[] = "TotalTabCount";
const uint64_t TabManager_TabMetrics::kTotalTabCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetTotalTabCount(int64_t value)
{
    SetMetricInternal(kTotalTabCountNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kTouchEventCountName[] = "TouchEventCount";
const uint64_t TabManager_TabMetrics::kTouchEventCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetTouchEventCount(int64_t value)
{
    SetMetricInternal(kTouchEventCountNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kWasRecentlyAudibleName[] = "WasRecentlyAudible";
const uint64_t TabManager_TabMetrics::kWasRecentlyAudibleNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWasRecentlyAudible(int64_t value)
{
    SetMetricInternal(kWasRecentlyAudibleNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kWindowIsActiveName[] = "WindowIsActive";
const uint64_t TabManager_TabMetrics::kWindowIsActiveNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowIsActive(int64_t value)
{
    SetMetricInternal(kWindowIsActiveNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kWindowShowStateName[] = "WindowShowState";
const uint64_t TabManager_TabMetrics::kWindowShowStateNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowShowState(int64_t value)
{
    SetMetricInternal(kWindowShowStateNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kWindowTabCountName[] = "WindowTabCount";
const uint64_t TabManager_TabMetrics::kWindowTabCountNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowTabCount(int64_t value)
{
    SetMetricInternal(kWindowTabCountNameHash, value);
    return *this;
}

const char TabManager_TabMetrics::kWindowTypeName[] = "WindowType";
const uint64_t TabManager_TabMetrics::kWindowTypeNameHash;

TabManager_TabMetrics& TabManager_TabMetrics::SetWindowType(int64_t value)
{
    SetMetricInternal(kWindowTypeNameHash, value);
    return *this;
}
const char TabManager_WindowMetrics::kEntryName[] = "TabManager.WindowMetrics";
const uint64_t TabManager_WindowMetrics::kEntryNameHash;

TabManager_WindowMetrics::TabManager_WindowMetrics(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_WindowMetrics::TabManager_WindowMetrics(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TabManager_WindowMetrics::~TabManager_WindowMetrics() = default;
const char TabManager_WindowMetrics::kIsActiveName[] = "IsActive";
const uint64_t TabManager_WindowMetrics::kIsActiveNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetIsActive(int64_t value)
{
    SetMetricInternal(kIsActiveNameHash, value);
    return *this;
}

const char TabManager_WindowMetrics::kShowStateName[] = "ShowState";
const uint64_t TabManager_WindowMetrics::kShowStateNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetShowState(int64_t value)
{
    SetMetricInternal(kShowStateNameHash, value);
    return *this;
}

const char TabManager_WindowMetrics::kTabCountName[] = "TabCount";
const uint64_t TabManager_WindowMetrics::kTabCountNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetTabCount(int64_t value)
{
    SetMetricInternal(kTabCountNameHash, value);
    return *this;
}

const char TabManager_WindowMetrics::kTypeName[] = "Type";
const uint64_t TabManager_WindowMetrics::kTypeNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetType(int64_t value)
{
    SetMetricInternal(kTypeNameHash, value);
    return *this;
}

const char TabManager_WindowMetrics::kWindowIdName[] = "WindowId";
const uint64_t TabManager_WindowMetrics::kWindowIdNameHash;

TabManager_WindowMetrics& TabManager_WindowMetrics::SetWindowId(int64_t value)
{
    SetMetricInternal(kWindowIdNameHash, value);
    return *this;
}
const char TopToolbar_Share::kEntryName[] = "TopToolbar.Share";
const uint64_t TopToolbar_Share::kEntryNameHash;

TopToolbar_Share::TopToolbar_Share(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TopToolbar_Share::TopToolbar_Share(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TopToolbar_Share::~TopToolbar_Share() = default;
const char TopToolbar_Share::kHasOccurredName[] = "HasOccurred";
const uint64_t TopToolbar_Share::kHasOccurredNameHash;

TopToolbar_Share& TopToolbar_Share::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char TouchToFill_Shown::kEntryName[] = "TouchToFill.Shown";
const uint64_t TouchToFill_Shown::kEntryNameHash;

TouchToFill_Shown::TouchToFill_Shown(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TouchToFill_Shown::TouchToFill_Shown(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TouchToFill_Shown::~TouchToFill_Shown() = default;
const char TouchToFill_Shown::kUserActionName[] = "UserAction";
const uint64_t TouchToFill_Shown::kUserActionNameHash;

TouchToFill_Shown& TouchToFill_Shown::SetUserAction(int64_t value)
{
    SetMetricInternal(kUserActionNameHash, value);
    return *this;
}
const char TouchToFill_SubmissionReadiness::kEntryName[] = "TouchToFill.SubmissionReadiness";
const uint64_t TouchToFill_SubmissionReadiness::kEntryNameHash;

TouchToFill_SubmissionReadiness::TouchToFill_SubmissionReadiness(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TouchToFill_SubmissionReadiness::TouchToFill_SubmissionReadiness(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TouchToFill_SubmissionReadiness::~TouchToFill_SubmissionReadiness() = default;
const char TouchToFill_SubmissionReadiness::kSubmissionReadinessName[] = "SubmissionReadiness";
const uint64_t TouchToFill_SubmissionReadiness::kSubmissionReadinessNameHash;

TouchToFill_SubmissionReadiness& TouchToFill_SubmissionReadiness::SetSubmissionReadiness(int64_t value)
{
    SetMetricInternal(kSubmissionReadinessNameHash, value);
    return *this;
}
const char TouchToFill_TimeToSuccessfulLogin::kEntryName[] = "TouchToFill.TimeToSuccessfulLogin";
const uint64_t TouchToFill_TimeToSuccessfulLogin::kEntryNameHash;

TouchToFill_TimeToSuccessfulLogin::TouchToFill_TimeToSuccessfulLogin(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TouchToFill_TimeToSuccessfulLogin::TouchToFill_TimeToSuccessfulLogin(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TouchToFill_TimeToSuccessfulLogin::~TouchToFill_TimeToSuccessfulLogin() = default;
const char TouchToFill_TimeToSuccessfulLogin::kTimeToSuccessfulLoginName[] = "TimeToSuccessfulLogin";
const uint64_t TouchToFill_TimeToSuccessfulLogin::kTimeToSuccessfulLoginNameHash;

TouchToFill_TimeToSuccessfulLogin& TouchToFill_TimeToSuccessfulLogin::SetTimeToSuccessfulLogin(int64_t value)
{
    SetMetricInternal(kTimeToSuccessfulLoginNameHash, value);
    return *this;
}
const char Translate::kEntryName[] = "Translate";
const uint64_t Translate::kEntryNameHash;

Translate::Translate(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Translate::Translate(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Translate::~Translate() = default;
const char Translate::kAcceptCountName[] = "AcceptCount";
const uint64_t Translate::kAcceptCountNameHash;

Translate& Translate::SetAcceptCount(int64_t value)
{
    SetMetricInternal(kAcceptCountNameHash, value);
    return *this;
}

const char Translate::kCountryName[] = "Country";
const uint64_t Translate::kCountryNameHash;

Translate& Translate::SetCountry(int64_t value)
{
    SetMetricInternal(kCountryNameHash, value);
    return *this;
}

const char Translate::kDeclineCountName[] = "DeclineCount";
const uint64_t Translate::kDeclineCountNameHash;

Translate& Translate::SetDeclineCount(int64_t value)
{
    SetMetricInternal(kDeclineCountNameHash, value);
    return *this;
}

const char Translate::kEventTypeName[] = "EventType";
const uint64_t Translate::kEventTypeNameHash;

Translate& Translate::SetEventType(int64_t value)
{
    SetMetricInternal(kEventTypeNameHash, value);
    return *this;
}

const char Translate::kIgnoreCountName[] = "IgnoreCount";
const uint64_t Translate::kIgnoreCountNameHash;

Translate& Translate::SetIgnoreCount(int64_t value)
{
    SetMetricInternal(kIgnoreCountNameHash, value);
    return *this;
}

const char Translate::kRankerResponseName[] = "RankerResponse";
const uint64_t Translate::kRankerResponseNameHash;

Translate& Translate::SetRankerResponse(int64_t value)
{
    SetMetricInternal(kRankerResponseNameHash, value);
    return *this;
}

const char Translate::kRankerVersionName[] = "RankerVersion";
const uint64_t Translate::kRankerVersionNameHash;

Translate& Translate::SetRankerVersion(int64_t value)
{
    SetMetricInternal(kRankerVersionNameHash, value);
    return *this;
}

const char Translate::kSourceLanguageName[] = "SourceLanguage";
const uint64_t Translate::kSourceLanguageNameHash;

Translate& Translate::SetSourceLanguage(int64_t value)
{
    SetMetricInternal(kSourceLanguageNameHash, value);
    return *this;
}

const char Translate::kTargetLanguageName[] = "TargetLanguage";
const uint64_t Translate::kTargetLanguageNameHash;

Translate& Translate::SetTargetLanguage(int64_t value)
{
    SetMetricInternal(kTargetLanguageNameHash, value);
    return *this;
}
const char TranslatePageLoad::kEntryName[] = "TranslatePageLoad";
const uint64_t TranslatePageLoad::kEntryNameHash;

TranslatePageLoad::TranslatePageLoad(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TranslatePageLoad::TranslatePageLoad(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TranslatePageLoad::~TranslatePageLoad() = default;
const char TranslatePageLoad::kFinalSourceLanguageName[] = "FinalSourceLanguage";
const uint64_t TranslatePageLoad::kFinalSourceLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetFinalSourceLanguage(int64_t value)
{
    SetMetricInternal(kFinalSourceLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kFinalStateName[] = "FinalState";
const uint64_t TranslatePageLoad::kFinalStateNameHash;

TranslatePageLoad& TranslatePageLoad::SetFinalState(int64_t value)
{
    SetMetricInternal(kFinalStateNameHash, value);
    return *this;
}

const char TranslatePageLoad::kFinalTargetLanguageName[] = "FinalTargetLanguage";
const uint64_t TranslatePageLoad::kFinalTargetLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetFinalTargetLanguage(int64_t value)
{
    SetMetricInternal(kFinalTargetLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kFirstTranslateErrorName[] = "FirstTranslateError";
const uint64_t TranslatePageLoad::kFirstTranslateErrorNameHash;

TranslatePageLoad& TranslatePageLoad::SetFirstTranslateError(int64_t value)
{
    SetMetricInternal(kFirstTranslateErrorNameHash, value);
    return *this;
}

const char TranslatePageLoad::kFirstUIInteractionName[] = "FirstUIInteraction";
const uint64_t TranslatePageLoad::kFirstUIInteractionNameHash;

TranslatePageLoad& TranslatePageLoad::SetFirstUIInteraction(int64_t value)
{
    SetMetricInternal(kFirstUIInteractionNameHash, value);
    return *this;
}

const char TranslatePageLoad::kHTMLContentLanguageName[] = "HTMLContentLanguage";
const uint64_t TranslatePageLoad::kHTMLContentLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetHTMLContentLanguage(int64_t value)
{
    SetMetricInternal(kHTMLContentLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kHTMLDocumentLanguageName[] = "HTMLDocumentLanguage";
const uint64_t TranslatePageLoad::kHTMLDocumentLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetHTMLDocumentLanguage(int64_t value)
{
    SetMetricInternal(kHTMLDocumentLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kInitialSourceLanguageName[] = "InitialSourceLanguage";
const uint64_t TranslatePageLoad::kInitialSourceLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetInitialSourceLanguage(int64_t value)
{
    SetMetricInternal(kInitialSourceLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kInitialSourceLanguageInContentLanguagesName[] = "InitialSourceLanguageInContentLanguages";
const uint64_t TranslatePageLoad::kInitialSourceLanguageInContentLanguagesNameHash;

TranslatePageLoad& TranslatePageLoad::SetInitialSourceLanguageInContentLanguages(int64_t value)
{
    SetMetricInternal(kInitialSourceLanguageInContentLanguagesNameHash, value);
    return *this;
}

const char TranslatePageLoad::kInitialStateName[] = "InitialState";
const uint64_t TranslatePageLoad::kInitialStateNameHash;

TranslatePageLoad& TranslatePageLoad::SetInitialState(int64_t value)
{
    SetMetricInternal(kInitialStateNameHash, value);
    return *this;
}

const char TranslatePageLoad::kInitialTargetLanguageName[] = "InitialTargetLanguage";
const uint64_t TranslatePageLoad::kInitialTargetLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetInitialTargetLanguage(int64_t value)
{
    SetMetricInternal(kInitialTargetLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kMaxTimeToTranslateName[] = "MaxTimeToTranslate";
const uint64_t TranslatePageLoad::kMaxTimeToTranslateNameHash;

TranslatePageLoad& TranslatePageLoad::SetMaxTimeToTranslate(int64_t value)
{
    SetMetricInternal(kMaxTimeToTranslateNameHash, value);
    return *this;
}

const char TranslatePageLoad::kModelDetectedLanguageName[] = "ModelDetectedLanguage";
const uint64_t TranslatePageLoad::kModelDetectedLanguageNameHash;

TranslatePageLoad& TranslatePageLoad::SetModelDetectedLanguage(int64_t value)
{
    SetMetricInternal(kModelDetectedLanguageNameHash, value);
    return *this;
}

const char TranslatePageLoad::kModelDetectionReliabilityScoreName[] = "ModelDetectionReliabilityScore";
const uint64_t TranslatePageLoad::kModelDetectionReliabilityScoreNameHash;

TranslatePageLoad& TranslatePageLoad::SetModelDetectionReliabilityScore(int64_t value)
{
    SetMetricInternal(kModelDetectionReliabilityScoreNameHash, value);
    return *this;
}

const char TranslatePageLoad::kNumReversionsName[] = "NumReversions";
const uint64_t TranslatePageLoad::kNumReversionsNameHash;

TranslatePageLoad& TranslatePageLoad::SetNumReversions(int64_t value)
{
    SetMetricInternal(kNumReversionsNameHash, value);
    return *this;
}

const char TranslatePageLoad::kNumTargetLanguageChangesName[] = "NumTargetLanguageChanges";
const uint64_t TranslatePageLoad::kNumTargetLanguageChangesNameHash;

TranslatePageLoad& TranslatePageLoad::SetNumTargetLanguageChanges(int64_t value)
{
    SetMetricInternal(kNumTargetLanguageChangesNameHash, value);
    return *this;
}

const char TranslatePageLoad::kNumTranslateErrorsName[] = "NumTranslateErrors";
const uint64_t TranslatePageLoad::kNumTranslateErrorsNameHash;

TranslatePageLoad& TranslatePageLoad::SetNumTranslateErrors(int64_t value)
{
    SetMetricInternal(kNumTranslateErrorsNameHash, value);
    return *this;
}

const char TranslatePageLoad::kNumTranslationsName[] = "NumTranslations";
const uint64_t TranslatePageLoad::kNumTranslationsNameHash;

TranslatePageLoad& TranslatePageLoad::SetNumTranslations(int64_t value)
{
    SetMetricInternal(kNumTranslationsNameHash, value);
    return *this;
}

const char TranslatePageLoad::kNumUIInteractionsName[] = "NumUIInteractions";
const uint64_t TranslatePageLoad::kNumUIInteractionsNameHash;

TranslatePageLoad& TranslatePageLoad::SetNumUIInteractions(int64_t value)
{
    SetMetricInternal(kNumUIInteractionsNameHash, value);
    return *this;
}

const char TranslatePageLoad::kRankerDecisionName[] = "RankerDecision";
const uint64_t TranslatePageLoad::kRankerDecisionNameHash;

TranslatePageLoad& TranslatePageLoad::SetRankerDecision(int64_t value)
{
    SetMetricInternal(kRankerDecisionNameHash, value);
    return *this;
}

const char TranslatePageLoad::kRankerVersionName[] = "RankerVersion";
const uint64_t TranslatePageLoad::kRankerVersionNameHash;

TranslatePageLoad& TranslatePageLoad::SetRankerVersion(int64_t value)
{
    SetMetricInternal(kRankerVersionNameHash, value);
    return *this;
}

const char TranslatePageLoad::kSequenceNumberName[] = "SequenceNumber";
const uint64_t TranslatePageLoad::kSequenceNumberNameHash;

TranslatePageLoad& TranslatePageLoad::SetSequenceNumber(int64_t value)
{
    SetMetricInternal(kSequenceNumberNameHash, value);
    return *this;
}

const char TranslatePageLoad::kTotalTimeNotTranslatedName[] = "TotalTimeNotTranslated";
const uint64_t TranslatePageLoad::kTotalTimeNotTranslatedNameHash;

TranslatePageLoad& TranslatePageLoad::SetTotalTimeNotTranslated(int64_t value)
{
    SetMetricInternal(kTotalTimeNotTranslatedNameHash, value);
    return *this;
}

const char TranslatePageLoad::kTotalTimeTranslatedName[] = "TotalTimeTranslated";
const uint64_t TranslatePageLoad::kTotalTimeTranslatedNameHash;

TranslatePageLoad& TranslatePageLoad::SetTotalTimeTranslated(int64_t value)
{
    SetMetricInternal(kTotalTimeTranslatedNameHash, value);
    return *this;
}

const char TranslatePageLoad::kTriggerDecisionName[] = "TriggerDecision";
const uint64_t TranslatePageLoad::kTriggerDecisionNameHash;

TranslatePageLoad& TranslatePageLoad::SetTriggerDecision(int64_t value)
{
    SetMetricInternal(kTriggerDecisionNameHash, value);
    return *this;
}

const char TranslatePageLoad::kWasContentEmptyName[] = "WasContentEmpty";
const uint64_t TranslatePageLoad::kWasContentEmptyNameHash;

TranslatePageLoad& TranslatePageLoad::SetWasContentEmpty(int64_t value)
{
    SetMetricInternal(kWasContentEmptyNameHash, value);
    return *this;
}
const char TrustedWebActivity_LocationDelegation::kEntryName[] = "TrustedWebActivity.LocationDelegation";
const uint64_t TrustedWebActivity_LocationDelegation::kEntryNameHash;

TrustedWebActivity_LocationDelegation::TrustedWebActivity_LocationDelegation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TrustedWebActivity_LocationDelegation::TrustedWebActivity_LocationDelegation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TrustedWebActivity_LocationDelegation::~TrustedWebActivity_LocationDelegation() = default;
const char TrustedWebActivity_LocationDelegation::kEnrolledName[] = "Enrolled";
const uint64_t TrustedWebActivity_LocationDelegation::kEnrolledNameHash;

TrustedWebActivity_LocationDelegation& TrustedWebActivity_LocationDelegation::SetEnrolled(int64_t value)
{
    SetMetricInternal(kEnrolledNameHash, value);
    return *this;
}
const char TrustedWebActivity_Open::kEntryName[] = "TrustedWebActivity.Open";
const uint64_t TrustedWebActivity_Open::kEntryNameHash;

TrustedWebActivity_Open::TrustedWebActivity_Open(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TrustedWebActivity_Open::TrustedWebActivity_Open(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TrustedWebActivity_Open::~TrustedWebActivity_Open() = default;
const char TrustedWebActivity_Open::kHasOccurredName[] = "HasOccurred";
const uint64_t TrustedWebActivity_Open::kHasOccurredNameHash;

TrustedWebActivity_Open& TrustedWebActivity_Open::SetHasOccurred(int64_t value)
{
    SetMetricInternal(kHasOccurredNameHash, value);
    return *this;
}
const char TrustedWebActivity_QualityEnforcementViolation::kEntryName[] = "TrustedWebActivity.QualityEnforcementViolation";
const uint64_t TrustedWebActivity_QualityEnforcementViolation::kEntryNameHash;

TrustedWebActivity_QualityEnforcementViolation::TrustedWebActivity_QualityEnforcementViolation(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TrustedWebActivity_QualityEnforcementViolation::TrustedWebActivity_QualityEnforcementViolation(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

TrustedWebActivity_QualityEnforcementViolation::~TrustedWebActivity_QualityEnforcementViolation() = default;
const char TrustedWebActivity_QualityEnforcementViolation::kViolationTypeName[] = "ViolationType";
const uint64_t TrustedWebActivity_QualityEnforcementViolation::kViolationTypeNameHash;

TrustedWebActivity_QualityEnforcementViolation& TrustedWebActivity_QualityEnforcementViolation::SetViolationType(int64_t value)
{
    SetMetricInternal(kViolationTypeNameHash, value);
    return *this;
}
const char Unload::kEntryName[] = "Unload";
const uint64_t Unload::kEntryNameHash;

Unload::Unload(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Unload::Unload(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Unload::~Unload() = default;
const char Unload::kBeforeUnloadDurationName[] = "BeforeUnloadDuration";
const uint64_t Unload::kBeforeUnloadDurationNameHash;

Unload& Unload::SetBeforeUnloadDuration(int64_t value)
{
    SetMetricInternal(kBeforeUnloadDurationNameHash, value);
    return *this;
}

const char Unload::kBeforeUnloadQueueingDurationName[] = "BeforeUnloadQueueingDuration";
const uint64_t Unload::kBeforeUnloadQueueingDurationNameHash;

Unload& Unload::SetBeforeUnloadQueueingDuration(int64_t value)
{
    SetMetricInternal(kBeforeUnloadQueueingDurationNameHash, value);
    return *this;
}

const char Unload::kBeforeUnloadToCommit_CrossProcessName[] = "BeforeUnloadToCommit.CrossProcess";
const uint64_t Unload::kBeforeUnloadToCommit_CrossProcessNameHash;

Unload& Unload::SetBeforeUnloadToCommit_CrossProcess(int64_t value)
{
    SetMetricInternal(kBeforeUnloadToCommit_CrossProcessNameHash, value);
    return *this;
}

const char Unload::kBeforeUnloadToCommit_SameProcessName[] = "BeforeUnloadToCommit.SameProcess";
const uint64_t Unload::kBeforeUnloadToCommit_SameProcessNameHash;

Unload& Unload::SetBeforeUnloadToCommit_SameProcess(int64_t value)
{
    SetMetricInternal(kBeforeUnloadToCommit_SameProcessNameHash, value);
    return *this;
}

const char Unload::kUnloadDurationName[] = "UnloadDuration";
const uint64_t Unload::kUnloadDurationNameHash;

Unload& Unload::SetUnloadDuration(int64_t value)
{
    SetMetricInternal(kUnloadDurationNameHash, value);
    return *this;
}

const char Unload::kUnloadQueueingDurationName[] = "UnloadQueueingDuration";
const uint64_t Unload::kUnloadQueueingDurationNameHash;

Unload& Unload::SetUnloadQueueingDuration(int64_t value)
{
    SetMetricInternal(kUnloadQueueingDurationNameHash, value);
    return *this;
}
const char UserActivity::kEntryName[] = "UserActivity";
const uint64_t UserActivity::kEntryNameHash;

UserActivity::UserActivity(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserActivity::UserActivity(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserActivity::~UserActivity() = default;
const char UserActivity::kBatteryPercentName[] = "BatteryPercent";
const uint64_t UserActivity::kBatteryPercentNameHash;

UserActivity& UserActivity::SetBatteryPercent(int64_t value)
{
    SetMetricInternal(kBatteryPercentNameHash, value);
    return *this;
}

const char UserActivity::kDeviceManagementName[] = "DeviceManagement";
const uint64_t UserActivity::kDeviceManagementNameHash;

UserActivity& UserActivity::SetDeviceManagement(int64_t value)
{
    SetMetricInternal(kDeviceManagementNameHash, value);
    return *this;
}

const char UserActivity::kDeviceModeName[] = "DeviceMode";
const uint64_t UserActivity::kDeviceModeNameHash;

UserActivity& UserActivity::SetDeviceMode(int64_t value)
{
    SetMetricInternal(kDeviceModeNameHash, value);
    return *this;
}

const char UserActivity::kDeviceTypeName[] = "DeviceType";
const uint64_t UserActivity::kDeviceTypeNameHash;

UserActivity& UserActivity::SetDeviceType(int64_t value)
{
    SetMetricInternal(kDeviceTypeNameHash, value);
    return *this;
}

const char UserActivity::kEventLogDurationName[] = "EventLogDuration";
const uint64_t UserActivity::kEventLogDurationNameHash;

UserActivity& UserActivity::SetEventLogDuration(int64_t value)
{
    SetMetricInternal(kEventLogDurationNameHash, value);
    return *this;
}

const char UserActivity::kEventReasonName[] = "EventReason";
const uint64_t UserActivity::kEventReasonNameHash;

UserActivity& UserActivity::SetEventReason(int64_t value)
{
    SetMetricInternal(kEventReasonNameHash, value);
    return *this;
}

const char UserActivity::kEventTypeName[] = "EventType";
const uint64_t UserActivity::kEventTypeNameHash;

UserActivity& UserActivity::SetEventType(int64_t value)
{
    SetMetricInternal(kEventTypeNameHash, value);
    return *this;
}

const char UserActivity::kKeyEventsInLastHourName[] = "KeyEventsInLastHour";
const uint64_t UserActivity::kKeyEventsInLastHourNameHash;

UserActivity& UserActivity::SetKeyEventsInLastHour(int64_t value)
{
    SetMetricInternal(kKeyEventsInLastHourNameHash, value);
    return *this;
}

const char UserActivity::kLastActivityDayName[] = "LastActivityDay";
const uint64_t UserActivity::kLastActivityDayNameHash;

UserActivity& UserActivity::SetLastActivityDay(int64_t value)
{
    SetMetricInternal(kLastActivityDayNameHash, value);
    return *this;
}

const char UserActivity::kLastActivityTimeName[] = "LastActivityTime";
const uint64_t UserActivity::kLastActivityTimeNameHash;

UserActivity& UserActivity::SetLastActivityTime(int64_t value)
{
    SetMetricInternal(kLastActivityTimeNameHash, value);
    return *this;
}

const char UserActivity::kLastUserActivityTimeName[] = "LastUserActivityTime";
const uint64_t UserActivity::kLastUserActivityTimeNameHash;

UserActivity& UserActivity::SetLastUserActivityTime(int64_t value)
{
    SetMetricInternal(kLastUserActivityTimeNameHash, value);
    return *this;
}

const char UserActivity::kModelAppliedName[] = "ModelApplied";
const uint64_t UserActivity::kModelAppliedNameHash;

UserActivity& UserActivity::SetModelApplied(int64_t value)
{
    SetMetricInternal(kModelAppliedNameHash, value);
    return *this;
}

const char UserActivity::kModelDecisionThresholdName[] = "ModelDecisionThreshold";
const uint64_t UserActivity::kModelDecisionThresholdNameHash;

UserActivity& UserActivity::SetModelDecisionThreshold(int64_t value)
{
    SetMetricInternal(kModelDecisionThresholdNameHash, value);
    return *this;
}

const char UserActivity::kModelInactivityScoreName[] = "ModelInactivityScore";
const uint64_t UserActivity::kModelInactivityScoreNameHash;

UserActivity& UserActivity::SetModelInactivityScore(int64_t value)
{
    SetMetricInternal(kModelInactivityScoreNameHash, value);
    return *this;
}

const char UserActivity::kModelResponseName[] = "ModelResponse";
const uint64_t UserActivity::kModelResponseNameHash;

UserActivity& UserActivity::SetModelResponse(int64_t value)
{
    SetMetricInternal(kModelResponseNameHash, value);
    return *this;
}

const char UserActivity::kMouseEventsInLastHourName[] = "MouseEventsInLastHour";
const uint64_t UserActivity::kMouseEventsInLastHourNameHash;

UserActivity& UserActivity::SetMouseEventsInLastHour(int64_t value)
{
    SetMetricInternal(kMouseEventsInLastHourNameHash, value);
    return *this;
}

const char UserActivity::kOnBatteryName[] = "OnBattery";
const uint64_t UserActivity::kOnBatteryNameHash;

UserActivity& UserActivity::SetOnBattery(int64_t value)
{
    SetMetricInternal(kOnBatteryNameHash, value);
    return *this;
}

const char UserActivity::kPreviousNegativeActionsCountName[] = "PreviousNegativeActionsCount";
const uint64_t UserActivity::kPreviousNegativeActionsCountNameHash;

UserActivity& UserActivity::SetPreviousNegativeActionsCount(int64_t value)
{
    SetMetricInternal(kPreviousNegativeActionsCountNameHash, value);
    return *this;
}

const char UserActivity::kPreviousPositiveActionsCountName[] = "PreviousPositiveActionsCount";
const uint64_t UserActivity::kPreviousPositiveActionsCountNameHash;

UserActivity& UserActivity::SetPreviousPositiveActionsCount(int64_t value)
{
    SetMetricInternal(kPreviousPositiveActionsCountNameHash, value);
    return *this;
}

const char UserActivity::kRecentTimeActiveName[] = "RecentTimeActive";
const uint64_t UserActivity::kRecentTimeActiveNameHash;

UserActivity& UserActivity::SetRecentTimeActive(int64_t value)
{
    SetMetricInternal(kRecentTimeActiveNameHash, value);
    return *this;
}

const char UserActivity::kRecentVideoPlayingTimeName[] = "RecentVideoPlayingTime";
const uint64_t UserActivity::kRecentVideoPlayingTimeNameHash;

UserActivity& UserActivity::SetRecentVideoPlayingTime(int64_t value)
{
    SetMetricInternal(kRecentVideoPlayingTimeNameHash, value);
    return *this;
}

const char UserActivity::kScreenDimDelayName[] = "ScreenDimDelay";
const uint64_t UserActivity::kScreenDimDelayNameHash;

UserActivity& UserActivity::SetScreenDimDelay(int64_t value)
{
    SetMetricInternal(kScreenDimDelayNameHash, value);
    return *this;
}

const char UserActivity::kScreenDimmedInitiallyName[] = "ScreenDimmedInitially";
const uint64_t UserActivity::kScreenDimmedInitiallyNameHash;

UserActivity& UserActivity::SetScreenDimmedInitially(int64_t value)
{
    SetMetricInternal(kScreenDimmedInitiallyNameHash, value);
    return *this;
}

const char UserActivity::kScreenDimOccurredName[] = "ScreenDimOccurred";
const uint64_t UserActivity::kScreenDimOccurredNameHash;

UserActivity& UserActivity::SetScreenDimOccurred(int64_t value)
{
    SetMetricInternal(kScreenDimOccurredNameHash, value);
    return *this;
}

const char UserActivity::kScreenDimToOffDelayName[] = "ScreenDimToOffDelay";
const uint64_t UserActivity::kScreenDimToOffDelayNameHash;

UserActivity& UserActivity::SetScreenDimToOffDelay(int64_t value)
{
    SetMetricInternal(kScreenDimToOffDelayNameHash, value);
    return *this;
}

const char UserActivity::kScreenLockedInitiallyName[] = "ScreenLockedInitially";
const uint64_t UserActivity::kScreenLockedInitiallyNameHash;

UserActivity& UserActivity::SetScreenLockedInitially(int64_t value)
{
    SetMetricInternal(kScreenLockedInitiallyNameHash, value);
    return *this;
}

const char UserActivity::kScreenLockOccurredName[] = "ScreenLockOccurred";
const uint64_t UserActivity::kScreenLockOccurredNameHash;

UserActivity& UserActivity::SetScreenLockOccurred(int64_t value)
{
    SetMetricInternal(kScreenLockOccurredNameHash, value);
    return *this;
}

const char UserActivity::kScreenOffInitiallyName[] = "ScreenOffInitially";
const uint64_t UserActivity::kScreenOffInitiallyNameHash;

UserActivity& UserActivity::SetScreenOffInitially(int64_t value)
{
    SetMetricInternal(kScreenOffInitiallyNameHash, value);
    return *this;
}

const char UserActivity::kScreenOffOccurredName[] = "ScreenOffOccurred";
const uint64_t UserActivity::kScreenOffOccurredNameHash;

UserActivity& UserActivity::SetScreenOffOccurred(int64_t value)
{
    SetMetricInternal(kScreenOffOccurredNameHash, value);
    return *this;
}

const char UserActivity::kSequenceIdName[] = "SequenceId";
const uint64_t UserActivity::kSequenceIdNameHash;

UserActivity& UserActivity::SetSequenceId(int64_t value)
{
    SetMetricInternal(kSequenceIdNameHash, value);
    return *this;
}

const char UserActivity::kTimeSinceLastKeyName[] = "TimeSinceLastKey";
const uint64_t UserActivity::kTimeSinceLastKeyNameHash;

UserActivity& UserActivity::SetTimeSinceLastKey(int64_t value)
{
    SetMetricInternal(kTimeSinceLastKeyNameHash, value);
    return *this;
}

const char UserActivity::kTimeSinceLastMouseName[] = "TimeSinceLastMouse";
const uint64_t UserActivity::kTimeSinceLastMouseNameHash;

UserActivity& UserActivity::SetTimeSinceLastMouse(int64_t value)
{
    SetMetricInternal(kTimeSinceLastMouseNameHash, value);
    return *this;
}

const char UserActivity::kTimeSinceLastTouchName[] = "TimeSinceLastTouch";
const uint64_t UserActivity::kTimeSinceLastTouchNameHash;

UserActivity& UserActivity::SetTimeSinceLastTouch(int64_t value)
{
    SetMetricInternal(kTimeSinceLastTouchNameHash, value);
    return *this;
}

const char UserActivity::kTimeSinceLastVideoEndedName[] = "TimeSinceLastVideoEnded";
const uint64_t UserActivity::kTimeSinceLastVideoEndedNameHash;

UserActivity& UserActivity::SetTimeSinceLastVideoEnded(int64_t value)
{
    SetMetricInternal(kTimeSinceLastVideoEndedNameHash, value);
    return *this;
}

const char UserActivity::kTouchEventsInLastHourName[] = "TouchEventsInLastHour";
const uint64_t UserActivity::kTouchEventsInLastHourNameHash;

UserActivity& UserActivity::SetTouchEventsInLastHour(int64_t value)
{
    SetMetricInternal(kTouchEventsInLastHourNameHash, value);
    return *this;
}
const char UserActivityId::kEntryName[] = "UserActivityId";
const uint64_t UserActivityId::kEntryNameHash;

UserActivityId::UserActivityId(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserActivityId::UserActivityId(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserActivityId::~UserActivityId() = default;
const char UserActivityId::kActivityIdName[] = "ActivityId";
const uint64_t UserActivityId::kActivityIdNameHash;

UserActivityId& UserActivityId::SetActivityId(int64_t value)
{
    SetMetricInternal(kActivityIdNameHash, value);
    return *this;
}

const char UserActivityId::kContentTypeName[] = "ContentType";
const uint64_t UserActivityId::kContentTypeNameHash;

UserActivityId& UserActivityId::SetContentType(int64_t value)
{
    SetMetricInternal(kContentTypeNameHash, value);
    return *this;
}

const char UserActivityId::kHasFormEntryName[] = "HasFormEntry";
const uint64_t UserActivityId::kHasFormEntryNameHash;

UserActivityId& UserActivityId::SetHasFormEntry(int64_t value)
{
    SetMetricInternal(kHasFormEntryNameHash, value);
    return *this;
}

const char UserActivityId::kIsActiveName[] = "IsActive";
const uint64_t UserActivityId::kIsActiveNameHash;

UserActivityId& UserActivityId::SetIsActive(int64_t value)
{
    SetMetricInternal(kIsActiveNameHash, value);
    return *this;
}

const char UserActivityId::kIsBrowserFocusedName[] = "IsBrowserFocused";
const uint64_t UserActivityId::kIsBrowserFocusedNameHash;

UserActivityId& UserActivityId::SetIsBrowserFocused(int64_t value)
{
    SetMetricInternal(kIsBrowserFocusedNameHash, value);
    return *this;
}

const char UserActivityId::kIsBrowserVisibleName[] = "IsBrowserVisible";
const uint64_t UserActivityId::kIsBrowserVisibleNameHash;

UserActivityId& UserActivityId::SetIsBrowserVisible(int64_t value)
{
    SetMetricInternal(kIsBrowserVisibleNameHash, value);
    return *this;
}

const char UserActivityId::kIsTopmostBrowserName[] = "IsTopmostBrowser";
const uint64_t UserActivityId::kIsTopmostBrowserNameHash;

UserActivityId& UserActivityId::SetIsTopmostBrowser(int64_t value)
{
    SetMetricInternal(kIsTopmostBrowserNameHash, value);
    return *this;
}

const char UserActivityId::kSiteEngagementScoreName[] = "SiteEngagementScore";
const uint64_t UserActivityId::kSiteEngagementScoreNameHash;

UserActivityId& UserActivityId::SetSiteEngagementScore(int64_t value)
{
    SetMetricInternal(kSiteEngagementScoreNameHash, value);
    return *this;
}
const char UserPerceivedPageVisit::kEntryName[] = "UserPerceivedPageVisit";
const uint64_t UserPerceivedPageVisit::kEntryNameHash;

UserPerceivedPageVisit::UserPerceivedPageVisit(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserPerceivedPageVisit::UserPerceivedPageVisit(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserPerceivedPageVisit::~UserPerceivedPageVisit() = default;
const char UserPerceivedPageVisit::kNotCountedForCoreWebVitalsName[] = "NotCountedForCoreWebVitals";
const uint64_t UserPerceivedPageVisit::kNotCountedForCoreWebVitalsNameHash;

UserPerceivedPageVisit& UserPerceivedPageVisit::SetNotCountedForCoreWebVitals(int64_t value)
{
    SetMetricInternal(kNotCountedForCoreWebVitalsNameHash, value);
    return *this;
}

const char UserPerceivedPageVisit::kPageVisitFinalStatusName[] = "PageVisitFinalStatus";
const uint64_t UserPerceivedPageVisit::kPageVisitFinalStatusNameHash;

UserPerceivedPageVisit& UserPerceivedPageVisit::SetPageVisitFinalStatus(int64_t value)
{
    SetMetricInternal(kPageVisitFinalStatusNameHash, value);
    return *this;
}

const char UserPerceivedPageVisit::kUserInitiatedName[] = "UserInitiated";
const uint64_t UserPerceivedPageVisit::kUserInitiatedNameHash;

UserPerceivedPageVisit& UserPerceivedPageVisit::SetUserInitiated(int64_t value)
{
    SetMetricInternal(kUserInitiatedNameHash, value);
    return *this;
}
const char UserSettingsEvent::kEntryName[] = "UserSettingsEvent";
const uint64_t UserSettingsEvent::kEntryNameHash;

UserSettingsEvent::UserSettingsEvent(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserSettingsEvent::UserSettingsEvent(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

UserSettingsEvent::~UserSettingsEvent() = default;
const char UserSettingsEvent::kAccessibilityIdName[] = "AccessibilityId";
const uint64_t UserSettingsEvent::kAccessibilityIdNameHash;

UserSettingsEvent& UserSettingsEvent::SetAccessibilityId(int64_t value)
{
    SetMetricInternal(kAccessibilityIdNameHash, value);
    return *this;
}

const char UserSettingsEvent::kBatteryPercentageName[] = "BatteryPercentage";
const uint64_t UserSettingsEvent::kBatteryPercentageNameHash;

UserSettingsEvent& UserSettingsEvent::SetBatteryPercentage(int64_t value)
{
    SetMetricInternal(kBatteryPercentageNameHash, value);
    return *this;
}

const char UserSettingsEvent::kCountryName[] = "Country";
const uint64_t UserSettingsEvent::kCountryNameHash;

UserSettingsEvent& UserSettingsEvent::SetCountry(int64_t value)
{
    SetMetricInternal(kCountryNameHash, value);
    return *this;
}

const char UserSettingsEvent::kCurrentValueName[] = "CurrentValue";
const uint64_t UserSettingsEvent::kCurrentValueNameHash;

UserSettingsEvent& UserSettingsEvent::SetCurrentValue(int64_t value)
{
    SetMetricInternal(kCurrentValueNameHash, value);
    return *this;
}

const char UserSettingsEvent::kDayOfWeekName[] = "DayOfWeek";
const uint64_t UserSettingsEvent::kDayOfWeekNameHash;

UserSettingsEvent& UserSettingsEvent::SetDayOfWeek(int64_t value)
{
    SetMetricInternal(kDayOfWeekNameHash, value);
    return *this;
}

const char UserSettingsEvent::kDeviceModeName[] = "DeviceMode";
const uint64_t UserSettingsEvent::kDeviceModeNameHash;

UserSettingsEvent& UserSettingsEvent::SetDeviceMode(int64_t value)
{
    SetMetricInternal(kDeviceModeNameHash, value);
    return *this;
}

const char UserSettingsEvent::kDeviceOrientationName[] = "DeviceOrientation";
const uint64_t UserSettingsEvent::kDeviceOrientationNameHash;

UserSettingsEvent& UserSettingsEvent::SetDeviceOrientation(int64_t value)
{
    SetMetricInternal(kDeviceOrientationNameHash, value);
    return *this;
}

const char UserSettingsEvent::kEventIdName[] = "EventId";
const uint64_t UserSettingsEvent::kEventIdNameHash;

UserSettingsEvent& UserSettingsEvent::SetEventId(int64_t value)
{
    SetMetricInternal(kEventIdNameHash, value);
    return *this;
}

const char UserSettingsEvent::kHasNightLightScheduleName[] = "HasNightLightSchedule";
const uint64_t UserSettingsEvent::kHasNightLightScheduleNameHash;

UserSettingsEvent& UserSettingsEvent::SetHasNightLightSchedule(int64_t value)
{
    SetMetricInternal(kHasNightLightScheduleNameHash, value);
    return *this;
}

const char UserSettingsEvent::kHasWifiSecurityName[] = "HasWifiSecurity";
const uint64_t UserSettingsEvent::kHasWifiSecurityNameHash;

UserSettingsEvent& UserSettingsEvent::SetHasWifiSecurity(int64_t value)
{
    SetMetricInternal(kHasWifiSecurityNameHash, value);
    return *this;
}

const char UserSettingsEvent::kHourOfDayName[] = "HourOfDay";
const uint64_t UserSettingsEvent::kHourOfDayNameHash;

UserSettingsEvent& UserSettingsEvent::SetHourOfDay(int64_t value)
{
    SetMetricInternal(kHourOfDayNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsAfterSunsetName[] = "IsAfterSunset";
const uint64_t UserSettingsEvent::kIsAfterSunsetNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsAfterSunset(int64_t value)
{
    SetMetricInternal(kIsAfterSunsetNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsChargingName[] = "IsCharging";
const uint64_t UserSettingsEvent::kIsChargingNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsCharging(int64_t value)
{
    SetMetricInternal(kIsChargingNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsFromSearchName[] = "IsFromSearch";
const uint64_t UserSettingsEvent::kIsFromSearchNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsFromSearch(int64_t value)
{
    SetMetricInternal(kIsFromSearchNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsPairedBluetoothDeviceName[] = "IsPairedBluetoothDevice";
const uint64_t UserSettingsEvent::kIsPairedBluetoothDeviceNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsPairedBluetoothDevice(int64_t value)
{
    SetMetricInternal(kIsPairedBluetoothDeviceNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsPlayingAudioName[] = "IsPlayingAudio";
const uint64_t UserSettingsEvent::kIsPlayingAudioNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsPlayingAudio(int64_t value)
{
    SetMetricInternal(kIsPlayingAudioNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsPlayingVideoName[] = "IsPlayingVideo";
const uint64_t UserSettingsEvent::kIsPlayingVideoNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsPlayingVideo(int64_t value)
{
    SetMetricInternal(kIsPlayingVideoNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsRecentlyFullscreenName[] = "IsRecentlyFullscreen";
const uint64_t UserSettingsEvent::kIsRecentlyFullscreenNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsRecentlyFullscreen(int64_t value)
{
    SetMetricInternal(kIsRecentlyFullscreenNameHash, value);
    return *this;
}

const char UserSettingsEvent::kIsRecentlyPresentingName[] = "IsRecentlyPresenting";
const uint64_t UserSettingsEvent::kIsRecentlyPresentingNameHash;

UserSettingsEvent& UserSettingsEvent::SetIsRecentlyPresenting(int64_t value)
{
    SetMetricInternal(kIsRecentlyPresentingNameHash, value);
    return *this;
}

const char UserSettingsEvent::kNetworkStatusName[] = "NetworkStatus";
const uint64_t UserSettingsEvent::kNetworkStatusNameHash;

UserSettingsEvent& UserSettingsEvent::SetNetworkStatus(int64_t value)
{
    SetMetricInternal(kNetworkStatusNameHash, value);
    return *this;
}

const char UserSettingsEvent::kPreviousValueName[] = "PreviousValue";
const uint64_t UserSettingsEvent::kPreviousValueNameHash;

UserSettingsEvent& UserSettingsEvent::SetPreviousValue(int64_t value)
{
    SetMetricInternal(kPreviousValueNameHash, value);
    return *this;
}

const char UserSettingsEvent::kSettingIdName[] = "SettingId";
const uint64_t UserSettingsEvent::kSettingIdNameHash;

UserSettingsEvent& UserSettingsEvent::SetSettingId(int64_t value)
{
    SetMetricInternal(kSettingIdNameHash, value);
    return *this;
}

const char UserSettingsEvent::kSettingTypeName[] = "SettingType";
const uint64_t UserSettingsEvent::kSettingTypeNameHash;

UserSettingsEvent& UserSettingsEvent::SetSettingType(int64_t value)
{
    SetMetricInternal(kSettingTypeNameHash, value);
    return *this;
}

const char UserSettingsEvent::kSignalStrengthName[] = "SignalStrength";
const uint64_t UserSettingsEvent::kSignalStrengthNameHash;

UserSettingsEvent& UserSettingsEvent::SetSignalStrength(int64_t value)
{
    SetMetricInternal(kSignalStrengthNameHash, value);
    return *this;
}

const char UserSettingsEvent::kTimeSinceLastSettingsChangeName[] = "TimeSinceLastSettingsChange";
const uint64_t UserSettingsEvent::kTimeSinceLastSettingsChangeNameHash;

UserSettingsEvent& UserSettingsEvent::SetTimeSinceLastSettingsChange(int64_t value)
{
    SetMetricInternal(kTimeSinceLastSettingsChangeNameHash, value);
    return *this;
}

const char UserSettingsEvent::kUsedCellularInSessionName[] = "UsedCellularInSession";
const uint64_t UserSettingsEvent::kUsedCellularInSessionNameHash;

UserSettingsEvent& UserSettingsEvent::SetUsedCellularInSession(int64_t value)
{
    SetMetricInternal(kUsedCellularInSessionNameHash, value);
    return *this;
}
const char V8_Wasm_ModuleCompiled::kEntryName[] = "V8.Wasm.ModuleCompiled";
const uint64_t V8_Wasm_ModuleCompiled::kEntryNameHash;

V8_Wasm_ModuleCompiled::V8_Wasm_ModuleCompiled(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleCompiled::V8_Wasm_ModuleCompiled(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleCompiled::~V8_Wasm_ModuleCompiled() = default;
const char V8_Wasm_ModuleCompiled::kAsyncName[] = "Async";
const uint64_t V8_Wasm_ModuleCompiled::kAsyncNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetAsync(int64_t value)
{
    SetMetricInternal(kAsyncNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kCachedName[] = "Cached";
const uint64_t V8_Wasm_ModuleCompiled::kCachedNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetCached(int64_t value)
{
    SetMetricInternal(kCachedNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kCodeSizeName[] = "CodeSize";
const uint64_t V8_Wasm_ModuleCompiled::kCodeSizeNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetCodeSize(int64_t value)
{
    SetMetricInternal(kCodeSizeNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kDeserializedName[] = "Deserialized";
const uint64_t V8_Wasm_ModuleCompiled::kDeserializedNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetDeserialized(int64_t value)
{
    SetMetricInternal(kDeserializedNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kLazyName[] = "Lazy";
const uint64_t V8_Wasm_ModuleCompiled::kLazyNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetLazy(int64_t value)
{
    SetMetricInternal(kLazyNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kLiftoffBailoutCountName[] = "LiftoffBailoutCount";
const uint64_t V8_Wasm_ModuleCompiled::kLiftoffBailoutCountNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetLiftoffBailoutCount(int64_t value)
{
    SetMetricInternal(kLiftoffBailoutCountNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kStreamedName[] = "Streamed";
const uint64_t V8_Wasm_ModuleCompiled::kStreamedNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetStreamed(int64_t value)
{
    SetMetricInternal(kStreamedNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kSuccessName[] = "Success";
const uint64_t V8_Wasm_ModuleCompiled::kSuccessNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetSuccess(int64_t value)
{
    SetMetricInternal(kSuccessNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleCompiled::kWallClockDurationName[] = "WallClockDuration";
const uint64_t V8_Wasm_ModuleCompiled::kWallClockDurationNameHash;

V8_Wasm_ModuleCompiled& V8_Wasm_ModuleCompiled::SetWallClockDuration(int64_t value)
{
    SetMetricInternal(kWallClockDurationNameHash, value);
    return *this;
}
const char V8_Wasm_ModuleDecoded::kEntryName[] = "V8.Wasm.ModuleDecoded";
const uint64_t V8_Wasm_ModuleDecoded::kEntryNameHash;

V8_Wasm_ModuleDecoded::V8_Wasm_ModuleDecoded(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleDecoded::V8_Wasm_ModuleDecoded(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleDecoded::~V8_Wasm_ModuleDecoded() = default;
const char V8_Wasm_ModuleDecoded::kFunctionCountName[] = "FunctionCount";
const uint64_t V8_Wasm_ModuleDecoded::kFunctionCountNameHash;

V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetFunctionCount(int64_t value)
{
    SetMetricInternal(kFunctionCountNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleDecoded::kModuleSizeName[] = "ModuleSize";
const uint64_t V8_Wasm_ModuleDecoded::kModuleSizeNameHash;

V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetModuleSize(int64_t value)
{
    SetMetricInternal(kModuleSizeNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleDecoded::kStreamedName[] = "Streamed";
const uint64_t V8_Wasm_ModuleDecoded::kStreamedNameHash;

V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetStreamed(int64_t value)
{
    SetMetricInternal(kStreamedNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleDecoded::kSuccessName[] = "Success";
const uint64_t V8_Wasm_ModuleDecoded::kSuccessNameHash;

V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetSuccess(int64_t value)
{
    SetMetricInternal(kSuccessNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleDecoded::kWallClockDurationName[] = "WallClockDuration";
const uint64_t V8_Wasm_ModuleDecoded::kWallClockDurationNameHash;

V8_Wasm_ModuleDecoded& V8_Wasm_ModuleDecoded::SetWallClockDuration(int64_t value)
{
    SetMetricInternal(kWallClockDurationNameHash, value);
    return *this;
}
const char V8_Wasm_ModuleInstantiated::kEntryName[] = "V8.Wasm.ModuleInstantiated";
const uint64_t V8_Wasm_ModuleInstantiated::kEntryNameHash;

V8_Wasm_ModuleInstantiated::V8_Wasm_ModuleInstantiated(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleInstantiated::V8_Wasm_ModuleInstantiated(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleInstantiated::~V8_Wasm_ModuleInstantiated() = default;
const char V8_Wasm_ModuleInstantiated::kImportedFunctionCountName[] = "ImportedFunctionCount";
const uint64_t V8_Wasm_ModuleInstantiated::kImportedFunctionCountNameHash;

V8_Wasm_ModuleInstantiated& V8_Wasm_ModuleInstantiated::SetImportedFunctionCount(int64_t value)
{
    SetMetricInternal(kImportedFunctionCountNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleInstantiated::kSuccessName[] = "Success";
const uint64_t V8_Wasm_ModuleInstantiated::kSuccessNameHash;

V8_Wasm_ModuleInstantiated& V8_Wasm_ModuleInstantiated::SetSuccess(int64_t value)
{
    SetMetricInternal(kSuccessNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleInstantiated::kWallClockDurationName[] = "WallClockDuration";
const uint64_t V8_Wasm_ModuleInstantiated::kWallClockDurationNameHash;

V8_Wasm_ModuleInstantiated& V8_Wasm_ModuleInstantiated::SetWallClockDuration(int64_t value)
{
    SetMetricInternal(kWallClockDurationNameHash, value);
    return *this;
}
const char V8_Wasm_ModuleTieredUp::kEntryName[] = "V8.Wasm.ModuleTieredUp";
const uint64_t V8_Wasm_ModuleTieredUp::kEntryNameHash;

V8_Wasm_ModuleTieredUp::V8_Wasm_ModuleTieredUp(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleTieredUp::V8_Wasm_ModuleTieredUp(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

V8_Wasm_ModuleTieredUp::~V8_Wasm_ModuleTieredUp() = default;
const char V8_Wasm_ModuleTieredUp::kCodeSizeName[] = "CodeSize";
const uint64_t V8_Wasm_ModuleTieredUp::kCodeSizeNameHash;

V8_Wasm_ModuleTieredUp& V8_Wasm_ModuleTieredUp::SetCodeSize(int64_t value)
{
    SetMetricInternal(kCodeSizeNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleTieredUp::kLazyName[] = "Lazy";
const uint64_t V8_Wasm_ModuleTieredUp::kLazyNameHash;

V8_Wasm_ModuleTieredUp& V8_Wasm_ModuleTieredUp::SetLazy(int64_t value)
{
    SetMetricInternal(kLazyNameHash, value);
    return *this;
}

const char V8_Wasm_ModuleTieredUp::kWallClockDurationName[] = "WallClockDuration";
const uint64_t V8_Wasm_ModuleTieredUp::kWallClockDurationNameHash;

V8_Wasm_ModuleTieredUp& V8_Wasm_ModuleTieredUp::SetWallClockDuration(int64_t value)
{
    SetMetricInternal(kWallClockDurationNameHash, value);
    return *this;
}
const char VirtualKeyboard_Open::kEntryName[] = "VirtualKeyboard.Open";
const uint64_t VirtualKeyboard_Open::kEntryNameHash;

VirtualKeyboard_Open::VirtualKeyboard_Open(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

VirtualKeyboard_Open::VirtualKeyboard_Open(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

VirtualKeyboard_Open::~VirtualKeyboard_Open() = default;
const char VirtualKeyboard_Open::kTextInputTypeName[] = "TextInputType";
const uint64_t VirtualKeyboard_Open::kTextInputTypeNameHash;

VirtualKeyboard_Open& VirtualKeyboard_Open::SetTextInputType(int64_t value)
{
    SetMetricInternal(kTextInputTypeNameHash, value);
    return *this;
}
const char WebAPK_Install::kEntryName[] = "WebAPK.Install";
const uint64_t WebAPK_Install::kEntryNameHash;

WebAPK_Install::WebAPK_Install(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_Install::WebAPK_Install(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_Install::~WebAPK_Install() = default;
const char WebAPK_Install::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_Install::kAppVersionNameHash;

WebAPK_Install& WebAPK_Install::SetAppVersion(int64_t value)
{
    SetMetricInternal(kAppVersionNameHash, value);
    return *this;
}

const char WebAPK_Install::kDistributorName[] = "Distributor";
const uint64_t WebAPK_Install::kDistributorNameHash;

WebAPK_Install& WebAPK_Install::SetDistributor(int64_t value)
{
    SetMetricInternal(kDistributorNameHash, value);
    return *this;
}

const char WebAPK_Install::kInstallName[] = "Install";
const uint64_t WebAPK_Install::kInstallNameHash;

WebAPK_Install& WebAPK_Install::SetInstall(int64_t value)
{
    SetMetricInternal(kInstallNameHash, value);
    return *this;
}
const char WebAPK_SessionEnd::kEntryName[] = "WebAPK.SessionEnd";
const uint64_t WebAPK_SessionEnd::kEntryNameHash;

WebAPK_SessionEnd::WebAPK_SessionEnd(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_SessionEnd::WebAPK_SessionEnd(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_SessionEnd::~WebAPK_SessionEnd() = default;
const char WebAPK_SessionEnd::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_SessionEnd::kAppVersionNameHash;

WebAPK_SessionEnd& WebAPK_SessionEnd::SetAppVersion(int64_t value)
{
    SetMetricInternal(kAppVersionNameHash, value);
    return *this;
}

const char WebAPK_SessionEnd::kDistributorName[] = "Distributor";
const uint64_t WebAPK_SessionEnd::kDistributorNameHash;

WebAPK_SessionEnd& WebAPK_SessionEnd::SetDistributor(int64_t value)
{
    SetMetricInternal(kDistributorNameHash, value);
    return *this;
}

const char WebAPK_SessionEnd::kSessionDurationName[] = "SessionDuration";
const uint64_t WebAPK_SessionEnd::kSessionDurationNameHash;

WebAPK_SessionEnd& WebAPK_SessionEnd::SetSessionDuration(int64_t value)
{
    SetMetricInternal(kSessionDurationNameHash, value);
    return *this;
}
const char WebAPK_Uninstall::kEntryName[] = "WebAPK.Uninstall";
const uint64_t WebAPK_Uninstall::kEntryNameHash;

WebAPK_Uninstall::WebAPK_Uninstall(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_Uninstall::WebAPK_Uninstall(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_Uninstall::~WebAPK_Uninstall() = default;
const char WebAPK_Uninstall::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_Uninstall::kAppVersionNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetAppVersion(int64_t value)
{
    SetMetricInternal(kAppVersionNameHash, value);
    return *this;
}

const char WebAPK_Uninstall::kDistributorName[] = "Distributor";
const uint64_t WebAPK_Uninstall::kDistributorNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetDistributor(int64_t value)
{
    SetMetricInternal(kDistributorNameHash, value);
    return *this;
}

const char WebAPK_Uninstall::kInstalledDurationName[] = "InstalledDuration";
const uint64_t WebAPK_Uninstall::kInstalledDurationNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetInstalledDuration(int64_t value)
{
    SetMetricInternal(kInstalledDurationNameHash, value);
    return *this;
}

const char WebAPK_Uninstall::kLifetimeLaunchesName[] = "LifetimeLaunches";
const uint64_t WebAPK_Uninstall::kLifetimeLaunchesNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetLifetimeLaunches(int64_t value)
{
    SetMetricInternal(kLifetimeLaunchesNameHash, value);
    return *this;
}

const char WebAPK_Uninstall::kUninstallName[] = "Uninstall";
const uint64_t WebAPK_Uninstall::kUninstallNameHash;

WebAPK_Uninstall& WebAPK_Uninstall::SetUninstall(int64_t value)
{
    SetMetricInternal(kUninstallNameHash, value);
    return *this;
}
const char WebAPK_Visit::kEntryName[] = "WebAPK.Visit";
const uint64_t WebAPK_Visit::kEntryNameHash;

WebAPK_Visit::WebAPK_Visit(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_Visit::WebAPK_Visit(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebAPK_Visit::~WebAPK_Visit() = default;
const char WebAPK_Visit::kAppVersionName[] = "AppVersion";
const uint64_t WebAPK_Visit::kAppVersionNameHash;

WebAPK_Visit& WebAPK_Visit::SetAppVersion(int64_t value)
{
    SetMetricInternal(kAppVersionNameHash, value);
    return *this;
}

const char WebAPK_Visit::kDistributorName[] = "Distributor";
const uint64_t WebAPK_Visit::kDistributorNameHash;

WebAPK_Visit& WebAPK_Visit::SetDistributor(int64_t value)
{
    SetMetricInternal(kDistributorNameHash, value);
    return *this;
}

const char WebAPK_Visit::kLaunchName[] = "Launch";
const uint64_t WebAPK_Visit::kLaunchNameHash;

WebAPK_Visit& WebAPK_Visit::SetLaunch(int64_t value)
{
    SetMetricInternal(kLaunchNameHash, value);
    return *this;
}

const char WebAPK_Visit::kLaunchSourceName[] = "LaunchSource";
const uint64_t WebAPK_Visit::kLaunchSourceNameHash;

WebAPK_Visit& WebAPK_Visit::SetLaunchSource(int64_t value)
{
    SetMetricInternal(kLaunchSourceNameHash, value);
    return *this;
}
const char Webapp_AddToHomeScreen::kEntryName[] = "Webapp.AddToHomeScreen";
const uint64_t Webapp_AddToHomeScreen::kEntryNameHash;

Webapp_AddToHomeScreen::Webapp_AddToHomeScreen(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Webapp_AddToHomeScreen::Webapp_AddToHomeScreen(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Webapp_AddToHomeScreen::~Webapp_AddToHomeScreen() = default;
const char Webapp_AddToHomeScreen::kDisplayModeName[] = "DisplayMode";
const uint64_t Webapp_AddToHomeScreen::kDisplayModeNameHash;

Webapp_AddToHomeScreen& Webapp_AddToHomeScreen::SetDisplayMode(int64_t value)
{
    SetMetricInternal(kDisplayModeNameHash, value);
    return *this;
}

const char Webapp_AddToHomeScreen::kSameAsManifestStartUrlName[] = "SameAsManifestStartUrl";
const uint64_t Webapp_AddToHomeScreen::kSameAsManifestStartUrlNameHash;

Webapp_AddToHomeScreen& Webapp_AddToHomeScreen::SetSameAsManifestStartUrl(int64_t value)
{
    SetMetricInternal(kSameAsManifestStartUrlNameHash, value);
    return *this;
}

const char Webapp_AddToHomeScreen::kShortcutReasonName[] = "ShortcutReason";
const uint64_t Webapp_AddToHomeScreen::kShortcutReasonNameHash;

Webapp_AddToHomeScreen& Webapp_AddToHomeScreen::SetShortcutReason(int64_t value)
{
    SetMetricInternal(kShortcutReasonNameHash, value);
    return *this;
}
const char WebApp_DailyInteraction::kEntryName[] = "WebApp.DailyInteraction";
const uint64_t WebApp_DailyInteraction::kEntryNameHash;

WebApp_DailyInteraction::WebApp_DailyInteraction(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebApp_DailyInteraction::WebApp_DailyInteraction(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebApp_DailyInteraction::~WebApp_DailyInteraction() = default;
const char WebApp_DailyInteraction::kBackgroundDurationName[] = "BackgroundDuration";
const uint64_t WebApp_DailyInteraction::kBackgroundDurationNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetBackgroundDuration(int64_t value)
{
    SetMetricInternal(kBackgroundDurationNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kDisplayModeName[] = "DisplayMode";
const uint64_t WebApp_DailyInteraction::kDisplayModeNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetDisplayMode(int64_t value)
{
    SetMetricInternal(kDisplayModeNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kForegroundDurationName[] = "ForegroundDuration";
const uint64_t WebApp_DailyInteraction::kForegroundDurationNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetForegroundDuration(int64_t value)
{
    SetMetricInternal(kForegroundDurationNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kInstalledName[] = "Installed";
const uint64_t WebApp_DailyInteraction::kInstalledNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetInstalled(int64_t value)
{
    SetMetricInternal(kInstalledNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kInstallSourceName[] = "InstallSource";
const uint64_t WebApp_DailyInteraction::kInstallSourceNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetInstallSource(int64_t value)
{
    SetMetricInternal(kInstallSourceNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kNumSessionsName[] = "NumSessions";
const uint64_t WebApp_DailyInteraction::kNumSessionsNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetNumSessions(int64_t value)
{
    SetMetricInternal(kNumSessionsNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kPromotableName[] = "Promotable";
const uint64_t WebApp_DailyInteraction::kPromotableNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetPromotable(int64_t value)
{
    SetMetricInternal(kPromotableNameHash, value);
    return *this;
}

const char WebApp_DailyInteraction::kUsedName[] = "Used";
const uint64_t WebApp_DailyInteraction::kUsedNameHash;

WebApp_DailyInteraction& WebApp_DailyInteraction::SetUsed(int64_t value)
{
    SetMetricInternal(kUsedNameHash, value);
    return *this;
}
const char WebOTPImpact::kEntryName[] = "WebOTPImpact";
const uint64_t WebOTPImpact::kEntryNameHash;

WebOTPImpact::WebOTPImpact(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebOTPImpact::WebOTPImpact(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebOTPImpact::~WebOTPImpact() = default;
const char WebOTPImpact::kPhoneCollectionName[] = "PhoneCollection";
const uint64_t WebOTPImpact::kPhoneCollectionNameHash;

WebOTPImpact& WebOTPImpact::SetPhoneCollection(int64_t value)
{
    SetMetricInternal(kPhoneCollectionNameHash, value);
    return *this;
}
const char WebRTC_AddressHarvesting::kEntryName[] = "WebRTC.AddressHarvesting";
const uint64_t WebRTC_AddressHarvesting::kEntryNameHash;

WebRTC_AddressHarvesting::WebRTC_AddressHarvesting(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebRTC_AddressHarvesting::WebRTC_AddressHarvesting(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebRTC_AddressHarvesting::~WebRTC_AddressHarvesting() = default;
const char WebRTC_AddressHarvesting::kUsagePatternName[] = "UsagePattern";
const uint64_t WebRTC_AddressHarvesting::kUsagePatternNameHash;

WebRTC_AddressHarvesting& WebRTC_AddressHarvesting::SetUsagePattern(int64_t value)
{
    SetMetricInternal(kUsagePatternNameHash, value);
    return *this;
}
const char WebRTC_ComplexSdp::kEntryName[] = "WebRTC.ComplexSdp";
const uint64_t WebRTC_ComplexSdp::kEntryNameHash;

WebRTC_ComplexSdp::WebRTC_ComplexSdp(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebRTC_ComplexSdp::WebRTC_ComplexSdp(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

WebRTC_ComplexSdp::~WebRTC_ComplexSdp() = default;
const char WebRTC_ComplexSdp::kCategoryName[] = "Category";
const uint64_t WebRTC_ComplexSdp::kCategoryNameHash;

WebRTC_ComplexSdp& WebRTC_ComplexSdp::SetCategory(int64_t value)
{
    SetMetricInternal(kCategoryNameHash, value);
    return *this;
}
const char Worker_ClientAdded::kEntryName[] = "Worker.ClientAdded";
const uint64_t Worker_ClientAdded::kEntryNameHash;

Worker_ClientAdded::Worker_ClientAdded(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Worker_ClientAdded::Worker_ClientAdded(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

Worker_ClientAdded::~Worker_ClientAdded() = default;
const char Worker_ClientAdded::kClientSourceIdName[] = "ClientSourceId";
const uint64_t Worker_ClientAdded::kClientSourceIdNameHash;

Worker_ClientAdded& Worker_ClientAdded::SetClientSourceId(int64_t value)
{
    SetMetricInternal(kClientSourceIdNameHash, value);
    return *this;
}

const char Worker_ClientAdded::kWorkerTypeName[] = "WorkerType";
const uint64_t Worker_ClientAdded::kWorkerTypeNameHash;

Worker_ClientAdded& Worker_ClientAdded::SetWorkerType(int64_t value)
{
    SetMetricInternal(kWorkerTypeNameHash, value);
    return *this;
}
const char XR_WebXR::kEntryName[] = "XR.WebXR";
const uint64_t XR_WebXR::kEntryNameHash;

XR_WebXR::XR_WebXR(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

XR_WebXR::XR_WebXR(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

XR_WebXR::~XR_WebXR() = default;
const char XR_WebXR::kDidGetXRInputSourcesName[] = "DidGetXRInputSources";
const uint64_t XR_WebXR::kDidGetXRInputSourcesNameHash;

XR_WebXR& XR_WebXR::SetDidGetXRInputSources(int64_t value)
{
    SetMetricInternal(kDidGetXRInputSourcesNameHash, value);
    return *this;
}

const char XR_WebXR::kDidRequestAvailableDevicesName[] = "DidRequestAvailableDevices";
const uint64_t XR_WebXR::kDidRequestAvailableDevicesNameHash;

XR_WebXR& XR_WebXR::SetDidRequestAvailableDevices(int64_t value)
{
    SetMetricInternal(kDidRequestAvailableDevicesNameHash, value);
    return *this;
}

const char XR_WebXR::kDidRequestPoseName[] = "DidRequestPose";
const uint64_t XR_WebXR::kDidRequestPoseNameHash;

XR_WebXR& XR_WebXR::SetDidRequestPose(int64_t value)
{
    SetMetricInternal(kDidRequestPoseNameHash, value);
    return *this;
}

const char XR_WebXR::kDidRequestPresentationName[] = "DidRequestPresentation";
const uint64_t XR_WebXR::kDidRequestPresentationNameHash;

XR_WebXR& XR_WebXR::SetDidRequestPresentation(int64_t value)
{
    SetMetricInternal(kDidRequestPresentationNameHash, value);
    return *this;
}

const char XR_WebXR::kDidUseNavigatorXRName[] = "DidUseNavigatorXR";
const uint64_t XR_WebXR::kDidUseNavigatorXRNameHash;

XR_WebXR& XR_WebXR::SetDidUseNavigatorXR(int64_t value)
{
    SetMetricInternal(kDidUseNavigatorXRNameHash, value);
    return *this;
}

const char XR_WebXR::kReturnedDeviceName[] = "ReturnedDevice";
const uint64_t XR_WebXR::kReturnedDeviceNameHash;

XR_WebXR& XR_WebXR::SetReturnedDevice(int64_t value)
{
    SetMetricInternal(kReturnedDeviceNameHash, value);
    return *this;
}

const char XR_WebXR::kReturnedPresentationCapableDeviceName[] = "ReturnedPresentationCapableDevice";
const uint64_t XR_WebXR::kReturnedPresentationCapableDeviceNameHash;

XR_WebXR& XR_WebXR::SetReturnedPresentationCapableDevice(int64_t value)
{
    SetMetricInternal(kReturnedPresentationCapableDeviceNameHash, value);
    return *this;
}
const char XR_WebXR_Session::kEntryName[] = "XR.WebXR.Session";
const uint64_t XR_WebXR_Session::kEntryNameHash;

XR_WebXR_Session::XR_WebXR_Session(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

XR_WebXR_Session::XR_WebXR_Session(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

XR_WebXR_Session::~XR_WebXR_Session() = default;
const char XR_WebXR_Session::kDurationName[] = "Duration";
const uint64_t XR_WebXR_Session::kDurationNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetDuration(int64_t value)
{
    SetMetricInternal(kDurationNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureRequest_BoundedFloorName[] = "FeatureRequest.BoundedFloor";
const uint64_t XR_WebXR_Session::kFeatureRequest_BoundedFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_BoundedFloor(int64_t value)
{
    SetMetricInternal(kFeatureRequest_BoundedFloorNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureRequest_LocalName[] = "FeatureRequest.Local";
const uint64_t XR_WebXR_Session::kFeatureRequest_LocalNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_Local(int64_t value)
{
    SetMetricInternal(kFeatureRequest_LocalNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureRequest_LocalFloorName[] = "FeatureRequest.LocalFloor";
const uint64_t XR_WebXR_Session::kFeatureRequest_LocalFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_LocalFloor(int64_t value)
{
    SetMetricInternal(kFeatureRequest_LocalFloorNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureRequest_UnboundedName[] = "FeatureRequest.Unbounded";
const uint64_t XR_WebXR_Session::kFeatureRequest_UnboundedNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_Unbounded(int64_t value)
{
    SetMetricInternal(kFeatureRequest_UnboundedNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureRequest_ViewerName[] = "FeatureRequest.Viewer";
const uint64_t XR_WebXR_Session::kFeatureRequest_ViewerNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureRequest_Viewer(int64_t value)
{
    SetMetricInternal(kFeatureRequest_ViewerNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureUse_BoundedFloorName[] = "FeatureUse.BoundedFloor";
const uint64_t XR_WebXR_Session::kFeatureUse_BoundedFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_BoundedFloor(int64_t value)
{
    SetMetricInternal(kFeatureUse_BoundedFloorNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureUse_LocalName[] = "FeatureUse.Local";
const uint64_t XR_WebXR_Session::kFeatureUse_LocalNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_Local(int64_t value)
{
    SetMetricInternal(kFeatureUse_LocalNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureUse_LocalFloorName[] = "FeatureUse.LocalFloor";
const uint64_t XR_WebXR_Session::kFeatureUse_LocalFloorNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_LocalFloor(int64_t value)
{
    SetMetricInternal(kFeatureUse_LocalFloorNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureUse_UnboundedName[] = "FeatureUse.Unbounded";
const uint64_t XR_WebXR_Session::kFeatureUse_UnboundedNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_Unbounded(int64_t value)
{
    SetMetricInternal(kFeatureUse_UnboundedNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kFeatureUse_ViewerName[] = "FeatureUse.Viewer";
const uint64_t XR_WebXR_Session::kFeatureUse_ViewerNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetFeatureUse_Viewer(int64_t value)
{
    SetMetricInternal(kFeatureUse_ViewerNameHash, value);
    return *this;
}

const char XR_WebXR_Session::kModeName[] = "Mode";
const uint64_t XR_WebXR_Session::kModeNameHash;

XR_WebXR_Session& XR_WebXR_Session::SetMode(int64_t value)
{
    SetMetricInternal(kModeNameHash, value);
    return *this;
}
const char XR_WebXR_SessionRequest::kEntryName[] = "XR.WebXR.SessionRequest";
const uint64_t XR_WebXR_SessionRequest::kEntryNameHash;

XR_WebXR_SessionRequest::XR_WebXR_SessionRequest(ukm::SourceId source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

XR_WebXR_SessionRequest::XR_WebXR_SessionRequest(ukm::SourceIdObj source_id)
    : ::ukm::internal::UkmEntryBuilderBase(source_id, kEntryNameHash)
{
}

XR_WebXR_SessionRequest::~XR_WebXR_SessionRequest() = default;
const char XR_WebXR_SessionRequest::kFeature_BoundedFloorName[] = "Feature.BoundedFloor";
const uint64_t XR_WebXR_SessionRequest::kFeature_BoundedFloorNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_BoundedFloor(int64_t value)
{
    SetMetricInternal(kFeature_BoundedFloorNameHash, value);
    return *this;
}

const char XR_WebXR_SessionRequest::kFeature_LocalName[] = "Feature.Local";
const uint64_t XR_WebXR_SessionRequest::kFeature_LocalNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_Local(int64_t value)
{
    SetMetricInternal(kFeature_LocalNameHash, value);
    return *this;
}

const char XR_WebXR_SessionRequest::kFeature_LocalFloorName[] = "Feature.LocalFloor";
const uint64_t XR_WebXR_SessionRequest::kFeature_LocalFloorNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_LocalFloor(int64_t value)
{
    SetMetricInternal(kFeature_LocalFloorNameHash, value);
    return *this;
}

const char XR_WebXR_SessionRequest::kFeature_UnboundedName[] = "Feature.Unbounded";
const uint64_t XR_WebXR_SessionRequest::kFeature_UnboundedNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_Unbounded(int64_t value)
{
    SetMetricInternal(kFeature_UnboundedNameHash, value);
    return *this;
}

const char XR_WebXR_SessionRequest::kFeature_ViewerName[] = "Feature.Viewer";
const uint64_t XR_WebXR_SessionRequest::kFeature_ViewerNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetFeature_Viewer(int64_t value)
{
    SetMetricInternal(kFeature_ViewerNameHash, value);
    return *this;
}

const char XR_WebXR_SessionRequest::kModeName[] = "Mode";
const uint64_t XR_WebXR_SessionRequest::kModeNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetMode(int64_t value)
{
    SetMetricInternal(kModeNameHash, value);
    return *this;
}

const char XR_WebXR_SessionRequest::kStatusName[] = "Status";
const uint64_t XR_WebXR_SessionRequest::kStatusNameHash;

XR_WebXR_SessionRequest& XR_WebXR_SessionRequest::SetStatus(int64_t value)
{
    SetMetricInternal(kStatusNameHash, value);
    return *this;
}

} // namespace builders
} // namespace ukm
