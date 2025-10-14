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

#include "services/metrics/public/cpp//ukm_decode.h"
#include "services/metrics/public/cpp//ukm_builders.h"

namespace ukm {
namespace builders {

std::map<uint64_t, EntryDecoder> CreateDecodeMap()
{
    return {

        { UINT64_C(3328190265939661657),
            { AboutThisSiteStatus::kEntryName,
                {

                    { AboutThisSiteStatus::kStatusNameHash, AboutThisSiteStatus::kStatusName },

                } } },

        { UINT64_C(4325886147604803651),
            { AbusiveExperienceHeuristic::kEntryName,
                {

                    { AbusiveExperienceHeuristic::kDidTabUnderNameHash, AbusiveExperienceHeuristic::kDidTabUnderName },

                    { AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptNameHash, AbusiveExperienceHeuristic::kDidWindowOpenFromAdScriptName },

                    { AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeNameHash, AbusiveExperienceHeuristic::kDidWindowOpenFromAdSubframeName },

                } } },

        { UINT64_C(2140536877907621174),
            { AbusiveExperienceHeuristic_JavaScriptDialog::kEntryName,
                {

                    { AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseNameHash, AbusiveExperienceHeuristic_JavaScriptDialog::kDismissalCauseName },

                } } },

        { UINT64_C(14027824048938333848),
            { AbusiveExperienceHeuristic_TabUnder::kEntryName,
                {

                    { AbusiveExperienceHeuristic_TabUnder::kDidTabUnderNameHash, AbusiveExperienceHeuristic_TabUnder::kDidTabUnderName },

                } } },

        { UINT64_C(9914911288513336680),
            { AbusiveExperienceHeuristic_WindowOpen::kEntryName,
                {

                    { AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptNameHash, AbusiveExperienceHeuristic_WindowOpen::kFromAdScriptName },

                    { AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeNameHash, AbusiveExperienceHeuristic_WindowOpen::kFromAdSubframeName },

                } } },

        { UINT64_C(17643400000419784912),
            { Accessibility_ImageDescriptions::kEntryName,
                {

                    { Accessibility_ImageDescriptions::kDescriptionNameHash, Accessibility_ImageDescriptions::kDescriptionName },

                    { Accessibility_ImageDescriptions::kImageAlreadyHasLabelNameHash, Accessibility_ImageDescriptions::kImageAlreadyHasLabelName },

                    { Accessibility_ImageDescriptions::kOCRNameHash, Accessibility_ImageDescriptions::kOCRName },

                } } },

        { UINT64_C(11928696798041860883),
            { Accessibility_Renderer::kEntryName,
                {

                    { Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsNameHash, Accessibility_Renderer::kCpuTime_SendPendingAccessibilityEventsName },

                } } },

        { UINT64_C(8594052878389691856),
            { AccuracyTipDialog::kEntryName,
                {

                    { AccuracyTipDialog::kInteractionNameHash, AccuracyTipDialog::kInteractionName },

                    { AccuracyTipDialog::kTimeSpentNameHash, AccuracyTipDialog::kTimeSpentName },

                } } },

        { UINT64_C(18226600721692375193),
            { AccuracyTipStatus::kEntryName,
                {

                    { AccuracyTipStatus::kStatusNameHash, AccuracyTipStatus::kStatusName },

                } } },

        { UINT64_C(9171478480016060997),
            { AdFrameLoad::kEntryName,
                {

                    { AdFrameLoad::kCpuTime_PeakWindowedPercentNameHash, AdFrameLoad::kCpuTime_PeakWindowedPercentName },

                    { AdFrameLoad::kCpuTime_PreActivationNameHash, AdFrameLoad::kCpuTime_PreActivationName },

                    { AdFrameLoad::kCpuTime_TotalNameHash, AdFrameLoad::kCpuTime_TotalName },

                    { AdFrameLoad::kFrameDepthNameHash, AdFrameLoad::kFrameDepthName },

                    { AdFrameLoad::kLoading_CacheBytes2NameHash, AdFrameLoad::kLoading_CacheBytes2Name },

                    { AdFrameLoad::kLoading_ImageBytesNameHash, AdFrameLoad::kLoading_ImageBytesName },

                    { AdFrameLoad::kLoading_JavascriptBytesNameHash, AdFrameLoad::kLoading_JavascriptBytesName },

                    { AdFrameLoad::kLoading_NetworkBytesNameHash, AdFrameLoad::kLoading_NetworkBytesName },

                    { AdFrameLoad::kLoading_NumResourcesNameHash, AdFrameLoad::kLoading_NumResourcesName },

                    { AdFrameLoad::kLoading_VideoBytesNameHash, AdFrameLoad::kLoading_VideoBytesName },

                    { AdFrameLoad::kStatus_CrossOriginNameHash, AdFrameLoad::kStatus_CrossOriginName },

                    { AdFrameLoad::kStatus_MediaNameHash, AdFrameLoad::kStatus_MediaName },

                    { AdFrameLoad::kStatus_UserActivationNameHash, AdFrameLoad::kStatus_UserActivationName },

                    { AdFrameLoad::kTiming_FirstContentfulPaintNameHash, AdFrameLoad::kTiming_FirstContentfulPaintName },

                    { AdFrameLoad::kTiming_InteractiveNameHash, AdFrameLoad::kTiming_InteractiveName },

                    { AdFrameLoad::kVisibility_FrameHeightNameHash, AdFrameLoad::kVisibility_FrameHeightName },

                    { AdFrameLoad::kVisibility_FrameWidthNameHash, AdFrameLoad::kVisibility_FrameWidthName },

                    { AdFrameLoad::kVisibility_HiddenNameHash, AdFrameLoad::kVisibility_HiddenName },

                } } },

        { UINT64_C(897698866892786861),
            { AdPageLoad::kEntryName,
                {

                    { AdPageLoad::kAdBytesNameHash, AdPageLoad::kAdBytesName },

                    { AdPageLoad::kAdCpuTimeNameHash, AdPageLoad::kAdCpuTimeName },

                    { AdPageLoad::kAdJavascriptBytesNameHash, AdPageLoad::kAdJavascriptBytesName },

                    { AdPageLoad::kAdVideoBytesNameHash, AdPageLoad::kAdVideoBytesName },

                    { AdPageLoad::kMainframeAdBytesNameHash, AdPageLoad::kMainframeAdBytesName },

                    { AdPageLoad::kMaxAdDensityByAreaNameHash, AdPageLoad::kMaxAdDensityByAreaName },

                    { AdPageLoad::kMaxAdDensityByHeightNameHash, AdPageLoad::kMaxAdDensityByHeightName },

                    { AdPageLoad::kTotalBytesNameHash, AdPageLoad::kTotalBytesName },

                } } },

        { UINT64_C(13452305451857451624),
            { AdPageLoadCustomSampling2::kEntryName,
                {

                    { AdPageLoadCustomSampling2::kAverageViewportAdDensityNameHash, AdPageLoadCustomSampling2::kAverageViewportAdDensityName },

                    { AdPageLoadCustomSampling2::kKurtosisViewportAdDensityNameHash, AdPageLoadCustomSampling2::kKurtosisViewportAdDensityName },

                    { AdPageLoadCustomSampling2::kSkewnessViewportAdDensityNameHash, AdPageLoadCustomSampling2::kSkewnessViewportAdDensityName },

                    { AdPageLoadCustomSampling2::kVarianceViewportAdDensityNameHash, AdPageLoadCustomSampling2::kVarianceViewportAdDensityName },

                } } },

        { UINT64_C(2556877997165288079),
            { AdsIntervention_LastIntervention::kEntryName,
                {

                    { AdsIntervention_LastIntervention::kInterventionStatusNameHash, AdsIntervention_LastIntervention::kInterventionStatusName },

                    { AdsIntervention_LastIntervention::kInterventionTypeNameHash, AdsIntervention_LastIntervention::kInterventionTypeName },

                } } },

        { UINT64_C(15288827799554694614),
            { AmpPageLoad::kEntryName,
                {

                    { AmpPageLoad::kMainFrameAmpPageLoadNameHash, AmpPageLoad::kMainFrameAmpPageLoadName },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration2NameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDuration2Name },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4NameHash, AmpPageLoad::kSubFrame_InteractiveTiming_FirstInputDelay4Name },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_NumInteractionsNameHash, AmpPageLoad::kSubFrame_InteractiveTiming_NumInteractionsName },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration2NameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDuration2Name },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration2NameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDuration2Name },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { AmpPageLoad::kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2NameHash,
                        AmpPageLoad::kSubFrame_InteractiveTiming_WorstUserInteractionLatency_MaxEventDuration2Name },

                    { AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreNameHash, AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScoreName },

                    { AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash,
                        AmpPageLoad::kSubFrame_LayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName },

                    { AmpPageLoad::kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        AmpPageLoad::kSubFrame_LayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaNameHash, AmpPageLoad::kSubFrame_MainFrameToSubFrameNavigationDeltaName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_AllowUserZoomNameHash, AmpPageLoad::kSubFrame_MobileFriendliness_AllowUserZoomName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_BadTapTargetsRatioNameHash, AmpPageLoad::kSubFrame_MobileFriendliness_BadTapTargetsRatioName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_SmallTextRatioNameHash, AmpPageLoad::kSubFrame_MobileFriendliness_SmallTextRatioName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_TextContentOutsideViewportPercentageNameHash,
                        AmpPageLoad::kSubFrame_MobileFriendliness_TextContentOutsideViewportPercentageName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_ViewportDeviceWidthNameHash, AmpPageLoad::kSubFrame_MobileFriendliness_ViewportDeviceWidthName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_ViewportHardcodedWidthNameHash, AmpPageLoad::kSubFrame_MobileFriendliness_ViewportHardcodedWidthName },

                    { AmpPageLoad::kSubFrame_MobileFriendliness_ViewportInitialScaleX10NameHash, AmpPageLoad::kSubFrame_MobileFriendliness_ViewportInitialScaleX10Name },

                    { AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintNameHash, AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstContentfulPaintName },

                    { AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstPaintNameHash, AmpPageLoad::kSubFrame_PaintTiming_NavigationToFirstPaintName },

                    { AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2NameHash, AmpPageLoad::kSubFrame_PaintTiming_NavigationToLargestContentfulPaint2Name },

                    { AmpPageLoad::kSubFrameAmpPageLoadNameHash, AmpPageLoad::kSubFrameAmpPageLoadName },

                } } },

        { UINT64_C(16711907311792517361),
            { Android_DarkTheme_AutoDarkMode::kEntryName,
                {

                    { Android_DarkTheme_AutoDarkMode::kDisabledByUserNameHash, Android_DarkTheme_AutoDarkMode::kDisabledByUserName },

                } } },

        { UINT64_C(4355485518635673093),
            { Android_MultiWindowChangeActivity::kEntryName,
                {

                    { Android_MultiWindowChangeActivity::kActivityTypeNameHash, Android_MultiWindowChangeActivity::kActivityTypeName },

                } } },

        { UINT64_C(10096673379731574014),
            { Android_MultiWindowState::kEntryName,
                {

                    { Android_MultiWindowState::kWindowStateNameHash, Android_MultiWindowState::kWindowStateName },

                } } },

        { UINT64_C(8962487173277472783),
            { Android_ScreenRotation::kEntryName,
                {

                    { Android_ScreenRotation::kTargetDeviceOrientationNameHash, Android_ScreenRotation::kTargetDeviceOrientationName },

                } } },

        { UINT64_C(11570336803537235206),
            { Android_UserRequestedUserAgentChange::kEntryName,
                {

                    { Android_UserRequestedUserAgentChange::kUserAgentTypeNameHash, Android_UserRequestedUserAgentChange::kUserAgentTypeName },

                } } },

        { UINT64_C(4589718692267131532),
            { AppListAppClickData::kEntryName,
                {

                    { AppListAppClickData::kAppLaunchIdNameHash, AppListAppClickData::kAppLaunchIdName },

                    { AppListAppClickData::kAppTypeNameHash, AppListAppClickData::kAppTypeName },

                    { AppListAppClickData::kClickRankNameHash, AppListAppClickData::kClickRankName },

                    { AppListAppClickData::kClicksEachHour00NameHash, AppListAppClickData::kClicksEachHour00Name },

                    { AppListAppClickData::kClicksEachHour01NameHash, AppListAppClickData::kClicksEachHour01Name },

                    { AppListAppClickData::kClicksEachHour02NameHash, AppListAppClickData::kClicksEachHour02Name },

                    { AppListAppClickData::kClicksEachHour03NameHash, AppListAppClickData::kClicksEachHour03Name },

                    { AppListAppClickData::kClicksEachHour04NameHash, AppListAppClickData::kClicksEachHour04Name },

                    { AppListAppClickData::kClicksEachHour05NameHash, AppListAppClickData::kClicksEachHour05Name },

                    { AppListAppClickData::kClicksEachHour06NameHash, AppListAppClickData::kClicksEachHour06Name },

                    { AppListAppClickData::kClicksEachHour07NameHash, AppListAppClickData::kClicksEachHour07Name },

                    { AppListAppClickData::kClicksEachHour08NameHash, AppListAppClickData::kClicksEachHour08Name },

                    { AppListAppClickData::kClicksEachHour09NameHash, AppListAppClickData::kClicksEachHour09Name },

                    { AppListAppClickData::kClicksEachHour10NameHash, AppListAppClickData::kClicksEachHour10Name },

                    { AppListAppClickData::kClicksEachHour11NameHash, AppListAppClickData::kClicksEachHour11Name },

                    { AppListAppClickData::kClicksEachHour12NameHash, AppListAppClickData::kClicksEachHour12Name },

                    { AppListAppClickData::kClicksEachHour13NameHash, AppListAppClickData::kClicksEachHour13Name },

                    { AppListAppClickData::kClicksEachHour14NameHash, AppListAppClickData::kClicksEachHour14Name },

                    { AppListAppClickData::kClicksEachHour15NameHash, AppListAppClickData::kClicksEachHour15Name },

                    { AppListAppClickData::kClicksEachHour16NameHash, AppListAppClickData::kClicksEachHour16Name },

                    { AppListAppClickData::kClicksEachHour17NameHash, AppListAppClickData::kClicksEachHour17Name },

                    { AppListAppClickData::kClicksEachHour18NameHash, AppListAppClickData::kClicksEachHour18Name },

                    { AppListAppClickData::kClicksEachHour19NameHash, AppListAppClickData::kClicksEachHour19Name },

                    { AppListAppClickData::kClicksEachHour20NameHash, AppListAppClickData::kClicksEachHour20Name },

                    { AppListAppClickData::kClicksEachHour21NameHash, AppListAppClickData::kClicksEachHour21Name },

                    { AppListAppClickData::kClicksEachHour22NameHash, AppListAppClickData::kClicksEachHour22Name },

                    { AppListAppClickData::kClicksEachHour23NameHash, AppListAppClickData::kClicksEachHour23Name },

                    { AppListAppClickData::kClicksLast24HoursNameHash, AppListAppClickData::kClicksLast24HoursName },

                    { AppListAppClickData::kClicksLastHourNameHash, AppListAppClickData::kClicksLastHourName },

                    { AppListAppClickData::kLastLaunchedFromNameHash, AppListAppClickData::kLastLaunchedFromName },

                    { AppListAppClickData::kMostRecentlyUsedIndexNameHash, AppListAppClickData::kMostRecentlyUsedIndexName },

                    { AppListAppClickData::kSequenceNumberNameHash, AppListAppClickData::kSequenceNumberName },

                    { AppListAppClickData::kTimeSinceLastClickNameHash, AppListAppClickData::kTimeSinceLastClickName },

                    { AppListAppClickData::kTotalClicksNameHash, AppListAppClickData::kTotalClicksName },

                } } },

        { UINT64_C(16635456347627451827),
            { AppListAppLaunch::kEntryName,
                {

                    { AppListAppLaunch::kAllClicksLast24HoursNameHash, AppListAppLaunch::kAllClicksLast24HoursName },

                    { AppListAppLaunch::kAllClicksLastHourNameHash, AppListAppLaunch::kAllClicksLastHourName },

                    { AppListAppLaunch::kAppTypeNameHash, AppListAppLaunch::kAppTypeName },

                    { AppListAppLaunch::kClickMethodNameHash, AppListAppLaunch::kClickMethodName },

                    { AppListAppLaunch::kDayOfWeekNameHash, AppListAppLaunch::kDayOfWeekName },

                    { AppListAppLaunch::kDeviceModeNameHash, AppListAppLaunch::kDeviceModeName },

                    { AppListAppLaunch::kDeviceTypeNameHash, AppListAppLaunch::kDeviceTypeName },

                    { AppListAppLaunch::kHourOfDayNameHash, AppListAppLaunch::kHourOfDayName },

                    { AppListAppLaunch::kLaunchedFromNameHash, AppListAppLaunch::kLaunchedFromName },

                    { AppListAppLaunch::kPositionIndexNameHash, AppListAppLaunch::kPositionIndexName },

                    { AppListAppLaunch::kTotalHoursNameHash, AppListAppLaunch::kTotalHoursName },

                } } },

        { UINT64_C(8354832962101675983),
            { Autofill_AddressProfileImport::kEntryName,
                {

                    { Autofill_AddressProfileImport::kAutocompleteUnrecognizedImportNameHash, Autofill_AddressProfileImport::kAutocompleteUnrecognizedImportName },

                    { Autofill_AddressProfileImport::kImportTypeNameHash, Autofill_AddressProfileImport::kImportTypeName },

                    { Autofill_AddressProfileImport::kNumberOfEditedFieldsNameHash, Autofill_AddressProfileImport::kNumberOfEditedFieldsName },

                    { Autofill_AddressProfileImport::kPhoneNumberStatusNameHash, Autofill_AddressProfileImport::kPhoneNumberStatusName },

                    { Autofill_AddressProfileImport::kUserDecisionNameHash, Autofill_AddressProfileImport::kUserDecisionName },

                } } },

        { UINT64_C(3597047501124112026),
            { Autofill_CardUploadDecision::kEntryName,
                {

                    { Autofill_CardUploadDecision::kUploadDecisionNameHash, Autofill_CardUploadDecision::kUploadDecisionName },

                } } },

        { UINT64_C(1996892304603525762),
            { Autofill_CreditCardFill::kEntryName,
                {

                    { Autofill_CreditCardFill::kFillable_AfterSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFillable_AfterSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFillable_AfterSecurity_QualitativeNameHash, Autofill_CreditCardFill::kFillable_AfterSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_BitmaskNameHash, Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_QualitativeNameHash, Autofill_CreditCardFill::kFillable_AfterSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFillable_BeforeSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_QualitativeNameHash, Autofill_CreditCardFill::kFillable_BeforeSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_BitmaskNameHash, Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_QualitativeNameHash, Autofill_CreditCardFill::kFillable_BeforeSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFilled_AfterSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_QualitativeNameHash, Autofill_CreditCardFill::kFilled_AfterSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_BitmaskNameHash, Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_QualitativeNameHash, Autofill_CreditCardFill::kFilled_AfterSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_BitmaskNameHash, Autofill_CreditCardFill::kFilled_BeforeSecurity_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_QualitativeNameHash, Autofill_CreditCardFill::kFilled_BeforeSecurity_QualitativeName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_BitmaskNameHash, Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_BitmaskName },

                    { Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_QualitativeNameHash, Autofill_CreditCardFill::kFilled_BeforeSecurity_Visible_QualitativeName },

                    { Autofill_CreditCardFill::kFormSignatureNameHash, Autofill_CreditCardFill::kFormSignatureName },

                    { Autofill_CreditCardFill::kSharedAutofillNameHash, Autofill_CreditCardFill::kSharedAutofillName },

                } } },

        { UINT64_C(14550063303370974566),
            { Autofill_DeveloperEngagement::kEntryName,
                {

                    { Autofill_DeveloperEngagement::kDeveloperEngagementNameHash, Autofill_DeveloperEngagement::kDeveloperEngagementName },

                    { Autofill_DeveloperEngagement::kFormSignatureNameHash, Autofill_DeveloperEngagement::kFormSignatureName },

                    { Autofill_DeveloperEngagement::kFormTypesNameHash, Autofill_DeveloperEngagement::kFormTypesName },

                    { Autofill_DeveloperEngagement::kIsForCreditCardNameHash, Autofill_DeveloperEngagement::kIsForCreditCardName },

                } } },

        { UINT64_C(15069365949047700716),
            { Autofill_EditedAutofilledFieldAtSubmission::kEntryName,
                {

                    { Autofill_EditedAutofilledFieldAtSubmission::kFieldSignatureNameHash, Autofill_EditedAutofilledFieldAtSubmission::kFieldSignatureName },

                    { Autofill_EditedAutofilledFieldAtSubmission::kFormSignatureNameHash, Autofill_EditedAutofilledFieldAtSubmission::kFormSignatureName },

                    { Autofill_EditedAutofilledFieldAtSubmission::kOverallTypeNameHash, Autofill_EditedAutofilledFieldAtSubmission::kOverallTypeName },

                } } },

        { UINT64_C(11456448948041474991),
            { Autofill_FieldFillStatus::kEntryName,
                {

                    { Autofill_FieldFillStatus::kFieldSignatureNameHash, Autofill_FieldFillStatus::kFieldSignatureName },

                    { Autofill_FieldFillStatus::kFormSignatureNameHash, Autofill_FieldFillStatus::kFormSignatureName },

                    { Autofill_FieldFillStatus::kIsAutofilledNameHash, Autofill_FieldFillStatus::kIsAutofilledName },

                    { Autofill_FieldFillStatus::kMillisecondsSinceFormParsedNameHash, Autofill_FieldFillStatus::kMillisecondsSinceFormParsedName },

                    { Autofill_FieldFillStatus::kPredictionSourceNameHash, Autofill_FieldFillStatus::kPredictionSourceName },

                    { Autofill_FieldFillStatus::kValidationEventNameHash, Autofill_FieldFillStatus::kValidationEventName },

                    { Autofill_FieldFillStatus::kWasPreviouslyAutofilledNameHash, Autofill_FieldFillStatus::kWasPreviouslyAutofilledName },

                } } },

        { UINT64_C(1290380890049589579),
            { Autofill_FieldTypeValidation::kEntryName,
                {

                    { Autofill_FieldTypeValidation::kActualTypeNameHash, Autofill_FieldTypeValidation::kActualTypeName },

                    { Autofill_FieldTypeValidation::kFieldSignatureNameHash, Autofill_FieldTypeValidation::kFieldSignatureName },

                    { Autofill_FieldTypeValidation::kFormSignatureNameHash, Autofill_FieldTypeValidation::kFormSignatureName },

                    { Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedNameHash, Autofill_FieldTypeValidation::kMillisecondsSinceFormParsedName },

                    { Autofill_FieldTypeValidation::kPredictedTypeNameHash, Autofill_FieldTypeValidation::kPredictedTypeName },

                    { Autofill_FieldTypeValidation::kPredictionSourceNameHash, Autofill_FieldTypeValidation::kPredictionSourceName },

                    { Autofill_FieldTypeValidation::kValidationEventNameHash, Autofill_FieldTypeValidation::kValidationEventName },

                } } },

        { UINT64_C(16631655786524489525),
            { Autofill_FormEvent::kEntryName,
                {

                    { Autofill_FormEvent::kAutofillFormEventNameHash, Autofill_FormEvent::kAutofillFormEventName },

                    { Autofill_FormEvent::kFormTypesNameHash, Autofill_FormEvent::kFormTypesName },

                    { Autofill_FormEvent::kMillisecondsSinceFormParsedNameHash, Autofill_FormEvent::kMillisecondsSinceFormParsedName },

                } } },

        { UINT64_C(409508311075101037),
            { Autofill_FormFillSuccessIOS::kEntryName,
                {

                    { Autofill_FormFillSuccessIOS::kFormFillSuccessNameHash, Autofill_FormFillSuccessIOS::kFormFillSuccessName },

                } } },

        { UINT64_C(12791011001011085363),
            { Autofill_FormSubmitted::kEntryName,
                {

                    { Autofill_FormSubmitted::kAutocompleteFillsNameHash, Autofill_FormSubmitted::kAutocompleteFillsName },

                    { Autofill_FormSubmitted::kAutofillAssistantIntentNameHash, Autofill_FormSubmitted::kAutofillAssistantIntentName },

                    { Autofill_FormSubmitted::kAutofillFillsNameHash, Autofill_FormSubmitted::kAutofillFillsName },

                    { Autofill_FormSubmitted::kAutofillFormSubmittedStateNameHash, Autofill_FormSubmitted::kAutofillFormSubmittedStateName },

                    { Autofill_FormSubmitted::kFormElementUserModificationsNameHash, Autofill_FormSubmitted::kFormElementUserModificationsName },

                    { Autofill_FormSubmitted::kFormSignatureNameHash, Autofill_FormSubmitted::kFormSignatureName },

                    { Autofill_FormSubmitted::kFormTypesNameHash, Autofill_FormSubmitted::kFormTypesName },

                    { Autofill_FormSubmitted::kHasUpiVpaFieldNameHash, Autofill_FormSubmitted::kHasUpiVpaFieldName },

                    { Autofill_FormSubmitted::kIsForCreditCardNameHash, Autofill_FormSubmitted::kIsForCreditCardName },

                    { Autofill_FormSubmitted::kMillisecondsSinceFormParsedNameHash, Autofill_FormSubmitted::kMillisecondsSinceFormParsedName },

                } } },

        { UINT64_C(14481214823422924028),
            { Autofill_HiddenRepresentationalFieldSkipDecision::kEntryName,
                {

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFieldOverallTypeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFieldSignatureName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFieldTypeGroupName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kFormSignatureName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kHeuristicTypeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldModeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kHtmlFieldTypeName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kIsSkippedName },

                    { Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeNameHash, Autofill_HiddenRepresentationalFieldSkipDecision::kServerTypeName },

                } } },

        { UINT64_C(12943113565528625214),
            { Autofill_InteractedWithForm::kEntryName,
                {

                    { Autofill_InteractedWithForm::kFormSignatureNameHash, Autofill_InteractedWithForm::kFormSignatureName },

                    { Autofill_InteractedWithForm::kFormTypesNameHash, Autofill_InteractedWithForm::kFormTypesName },

                    { Autofill_InteractedWithForm::kIsForCreditCardNameHash, Autofill_InteractedWithForm::kIsForCreditCardName },

                    { Autofill_InteractedWithForm::kLocalRecordTypeCountNameHash, Autofill_InteractedWithForm::kLocalRecordTypeCountName },

                    { Autofill_InteractedWithForm::kServerRecordTypeCountNameHash, Autofill_InteractedWithForm::kServerRecordTypeCountName },

                } } },

        { UINT64_C(4026604158724844667),
            { Autofill_KeyMetrics::kEntryName,
                {

                    { Autofill_KeyMetrics::kAutofillAssistantIntentNameHash, Autofill_KeyMetrics::kAutofillAssistantIntentName },

                    { Autofill_KeyMetrics::kFillingAcceptanceNameHash, Autofill_KeyMetrics::kFillingAcceptanceName },

                    { Autofill_KeyMetrics::kFillingAssistanceNameHash, Autofill_KeyMetrics::kFillingAssistanceName },

                    { Autofill_KeyMetrics::kFillingCorrectnessNameHash, Autofill_KeyMetrics::kFillingCorrectnessName },

                    { Autofill_KeyMetrics::kFillingReadinessNameHash, Autofill_KeyMetrics::kFillingReadinessName },

                    { Autofill_KeyMetrics::kFormTypesNameHash, Autofill_KeyMetrics::kFormTypesName },

                } } },

        { UINT64_C(10421158139944624501),
            { Autofill_RepeatedServerTypePredictionRationalized::kEntryName,
                {

                    { Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeNameHash,
                        Autofill_RepeatedServerTypePredictionRationalized::kFieldNewOverallTypeName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeNameHash,
                        Autofill_RepeatedServerTypePredictionRationalized::kFieldOldOverallTypeName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFieldSignatureName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFieldTypeGroupName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureNameHash, Autofill_RepeatedServerTypePredictionRationalized::kFormSignatureName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kHeuristicTypeName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldModeName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kHtmlFieldTypeName },

                    { Autofill_RepeatedServerTypePredictionRationalized::kServerTypeNameHash, Autofill_RepeatedServerTypePredictionRationalized::kServerTypeName },

                } } },

        { UINT64_C(17703268464688884622),
            { Autofill_SuggestionFilled::kEntryName,
                {

                    { Autofill_SuggestionFilled::kFieldSignatureNameHash, Autofill_SuggestionFilled::kFieldSignatureName },

                    { Autofill_SuggestionFilled::kFormSignatureNameHash, Autofill_SuggestionFilled::kFormSignatureName },

                    { Autofill_SuggestionFilled::kIsForCreditCardNameHash, Autofill_SuggestionFilled::kIsForCreditCardName },

                    { Autofill_SuggestionFilled::kMillisecondsSinceFormParsedNameHash, Autofill_SuggestionFilled::kMillisecondsSinceFormParsedName },

                    { Autofill_SuggestionFilled::kRecordTypeNameHash, Autofill_SuggestionFilled::kRecordTypeName },

                } } },

        { UINT64_C(7579660929739851736),
            { Autofill_SuggestionsShown::kEntryName,
                {

                    { Autofill_SuggestionsShown::kFieldSignatureNameHash, Autofill_SuggestionsShown::kFieldSignatureName },

                    { Autofill_SuggestionsShown::kFormSignatureNameHash, Autofill_SuggestionsShown::kFormSignatureName },

                    { Autofill_SuggestionsShown::kHeuristicTypeNameHash, Autofill_SuggestionsShown::kHeuristicTypeName },

                    { Autofill_SuggestionsShown::kHtmlFieldTypeNameHash, Autofill_SuggestionsShown::kHtmlFieldTypeName },

                    { Autofill_SuggestionsShown::kMillisecondsSinceFormParsedNameHash, Autofill_SuggestionsShown::kMillisecondsSinceFormParsedName },

                    { Autofill_SuggestionsShown::kServerTypeNameHash, Autofill_SuggestionsShown::kServerTypeName },

                } } },

        { UINT64_C(8376184896509210883),
            { Autofill_TextFieldDidChange::kEntryName,
                {

                    { Autofill_TextFieldDidChange::kFieldSignatureNameHash, Autofill_TextFieldDidChange::kFieldSignatureName },

                    { Autofill_TextFieldDidChange::kFieldTypeGroupNameHash, Autofill_TextFieldDidChange::kFieldTypeGroupName },

                    { Autofill_TextFieldDidChange::kFormSignatureNameHash, Autofill_TextFieldDidChange::kFormSignatureName },

                    { Autofill_TextFieldDidChange::kHeuristicTypeNameHash, Autofill_TextFieldDidChange::kHeuristicTypeName },

                    { Autofill_TextFieldDidChange::kHtmlFieldModeNameHash, Autofill_TextFieldDidChange::kHtmlFieldModeName },

                    { Autofill_TextFieldDidChange::kHtmlFieldTypeNameHash, Autofill_TextFieldDidChange::kHtmlFieldTypeName },

                    { Autofill_TextFieldDidChange::kIsAutofilledNameHash, Autofill_TextFieldDidChange::kIsAutofilledName },

                    { Autofill_TextFieldDidChange::kIsEmptyNameHash, Autofill_TextFieldDidChange::kIsEmptyName },

                    { Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedNameHash, Autofill_TextFieldDidChange::kMillisecondsSinceFormParsedName },

                    { Autofill_TextFieldDidChange::kServerTypeNameHash, Autofill_TextFieldDidChange::kServerTypeName },

                } } },

        { UINT64_C(12436728227263097278),
            { AutofillAssistant_CollectContact::kEntryName,
                {

                    { AutofillAssistant_CollectContact::kCompleteContactProfilesCountNameHash, AutofillAssistant_CollectContact::kCompleteContactProfilesCountName },

                    { AutofillAssistant_CollectContact::kContactModifiedNameHash, AutofillAssistant_CollectContact::kContactModifiedName },

                    { AutofillAssistant_CollectContact::kIncompleteContactProfilesCountNameHash, AutofillAssistant_CollectContact::kIncompleteContactProfilesCountName },

                    { AutofillAssistant_CollectContact::kInitialContactFieldsStatusNameHash, AutofillAssistant_CollectContact::kInitialContactFieldsStatusName },

                } } },

        { UINT64_C(9397794528456561196),
            { AutofillAssistant_CollectPayment::kEntryName,
                {

                    { AutofillAssistant_CollectPayment::kCompleteCreditCardsCountNameHash, AutofillAssistant_CollectPayment::kCompleteCreditCardsCountName },

                    { AutofillAssistant_CollectPayment::kCreditCardModifiedNameHash, AutofillAssistant_CollectPayment::kCreditCardModifiedName },

                    { AutofillAssistant_CollectPayment::kIncompleteCreditCardsCountNameHash, AutofillAssistant_CollectPayment::kIncompleteCreditCardsCountName },

                    { AutofillAssistant_CollectPayment::kInitialBillingAddressFieldsStatusNameHash, AutofillAssistant_CollectPayment::kInitialBillingAddressFieldsStatusName },

                    { AutofillAssistant_CollectPayment::kInitialCreditCardFieldsStatusNameHash, AutofillAssistant_CollectPayment::kInitialCreditCardFieldsStatusName },

                } } },

        { UINT64_C(491342474386869009),
            { AutofillAssistant_CollectShippingAddress::kEntryName,
                {

                    { AutofillAssistant_CollectShippingAddress::kCompleteShippingProfilesCountNameHash,
                        AutofillAssistant_CollectShippingAddress::kCompleteShippingProfilesCountName },

                    { AutofillAssistant_CollectShippingAddress::kIncompleteShippingProfilesCountNameHash,
                        AutofillAssistant_CollectShippingAddress::kIncompleteShippingProfilesCountName },

                    { AutofillAssistant_CollectShippingAddress::kInitialShippingFieldsStatusNameHash, AutofillAssistant_CollectShippingAddress::kInitialShippingFieldsStatusName },

                    { AutofillAssistant_CollectShippingAddress::kShippingModifiedNameHash, AutofillAssistant_CollectShippingAddress::kShippingModifiedName },

                } } },

        { UINT64_C(17812491040949705840),
            { AutofillAssistant_CollectUserDataResult::kEntryName,
                {

                    { AutofillAssistant_CollectUserDataResult::kResultNameHash, AutofillAssistant_CollectUserDataResult::kResultName },

                    { AutofillAssistant_CollectUserDataResult::kTimeTakenMsNameHash, AutofillAssistant_CollectUserDataResult::kTimeTakenMsName },

                    { AutofillAssistant_CollectUserDataResult::kUserDataSourceNameHash, AutofillAssistant_CollectUserDataResult::kUserDataSourceName },

                } } },

        { UINT64_C(6141021362130406840),
            { AutofillAssistant_FlowFinished::kEntryName,
                {

                    { AutofillAssistant_FlowFinished::kFlowFinishedStateNameHash, AutofillAssistant_FlowFinished::kFlowFinishedStateName },

                    { AutofillAssistant_FlowFinished::kNumActionsNameHash, AutofillAssistant_FlowFinished::kNumActionsName },

                    { AutofillAssistant_FlowFinished::kNumJsFlowActionsNameHash, AutofillAssistant_FlowFinished::kNumJsFlowActionsName },

                    { AutofillAssistant_FlowFinished::kNumRoundtripsNameHash, AutofillAssistant_FlowFinished::kNumRoundtripsName },

                    { AutofillAssistant_FlowFinished::kTotalDecodedGetActionsSizeInBytesNameHash, AutofillAssistant_FlowFinished::kTotalDecodedGetActionsSizeInBytesName },

                    { AutofillAssistant_FlowFinished::kTotalDecodedJsFlowSizeInBytesNameHash, AutofillAssistant_FlowFinished::kTotalDecodedJsFlowSizeInBytesName },

                    { AutofillAssistant_FlowFinished::kTotalEncodedGetActionsSizeInBytesNameHash, AutofillAssistant_FlowFinished::kTotalEncodedGetActionsSizeInBytesName },

                } } },

        { UINT64_C(11581054125933997496),
            { AutofillAssistant_InChromeTriggering::kEntryName,
                {

                    { AutofillAssistant_InChromeTriggering::kInChromeTriggerActionNameHash, AutofillAssistant_InChromeTriggering::kInChromeTriggerActionName },

                } } },

        { UINT64_C(2310564600423055465),
            { AutofillAssistant_LiteScriptFinished::kEntryName,
                {

                    { AutofillAssistant_LiteScriptFinished::kLiteScriptFinishedNameHash, AutofillAssistant_LiteScriptFinished::kLiteScriptFinishedName },

                    { AutofillAssistant_LiteScriptFinished::kTriggerUITypeNameHash, AutofillAssistant_LiteScriptFinished::kTriggerUITypeName },

                } } },

        { UINT64_C(5594888896079082193),
            { AutofillAssistant_LiteScriptOnboarding::kEntryName,
                {

                    { AutofillAssistant_LiteScriptOnboarding::kLiteScriptOnboardingNameHash, AutofillAssistant_LiteScriptOnboarding::kLiteScriptOnboardingName },

                    { AutofillAssistant_LiteScriptOnboarding::kTriggerUITypeNameHash, AutofillAssistant_LiteScriptOnboarding::kTriggerUITypeName },

                } } },

        { UINT64_C(2839413550083166052),
            { AutofillAssistant_LiteScriptShownToUser::kEntryName,
                {

                    { AutofillAssistant_LiteScriptShownToUser::kLiteScriptShownToUserNameHash, AutofillAssistant_LiteScriptShownToUser::kLiteScriptShownToUserName },

                    { AutofillAssistant_LiteScriptShownToUser::kTriggerUITypeNameHash, AutofillAssistant_LiteScriptShownToUser::kTriggerUITypeName },

                } } },

        { UINT64_C(6546378162427464679),
            { AutofillAssistant_LiteScriptStarted::kEntryName,
                {

                    { AutofillAssistant_LiteScriptStarted::kLiteScriptStartedNameHash, AutofillAssistant_LiteScriptStarted::kLiteScriptStartedName },

                    { AutofillAssistant_LiteScriptStarted::kTriggerUITypeNameHash, AutofillAssistant_LiteScriptStarted::kTriggerUITypeName },

                } } },

        { UINT64_C(8317827912063605658),
            { AutofillAssistant_RegularScriptOnboarding::kEntryName,
                {

                    { AutofillAssistant_RegularScriptOnboarding::kOnboardingNameHash, AutofillAssistant_RegularScriptOnboarding::kOnboardingName },

                } } },

        { UINT64_C(7203365221275520000),
            { AutofillAssistant_StartRequest::kEntryName,
                {

                    { AutofillAssistant_StartRequest::kCallerNameHash, AutofillAssistant_StartRequest::kCallerName },

                    { AutofillAssistant_StartRequest::kExperimentsNameHash, AutofillAssistant_StartRequest::kExperimentsName },

                    { AutofillAssistant_StartRequest::kIntentNameHash, AutofillAssistant_StartRequest::kIntentName },

                    { AutofillAssistant_StartRequest::kSourceNameHash, AutofillAssistant_StartRequest::kSourceName },

                    { AutofillAssistant_StartRequest::kStartedNameHash, AutofillAssistant_StartRequest::kStartedName },

                } } },

        { UINT64_C(18275646174622213435),
            { AutofillAssistant_Timing::kEntryName,
                {

                    { AutofillAssistant_Timing::kTriggerConditionEvaluationMsNameHash, AutofillAssistant_Timing::kTriggerConditionEvaluationMsName },

                } } },

        { UINT64_C(2667461721042691467),
            { BackForwardCacheDisabledForRenderFrameHostReason::kEntryName,
                {

                    { BackForwardCacheDisabledForRenderFrameHostReason::kReason2NameHash, BackForwardCacheDisabledForRenderFrameHostReason::kReason2Name },

                } } },

        { UINT64_C(17791611243479825042),
            { BackForwardCacheDisallowActivationReason::kEntryName,
                {

                    { BackForwardCacheDisallowActivationReason::kReasonNameHash, BackForwardCacheDisallowActivationReason::kReasonName },

                } } },

        { UINT64_C(15260645490069405494),
            { BackgroundFetch::kEntryName,
                {

                    { BackgroundFetch::kDeniedDueToPermissionsNameHash, BackgroundFetch::kDeniedDueToPermissionsName },

                    { BackgroundFetch::kDownloadTotalNameHash, BackgroundFetch::kDownloadTotalName },

                    { BackgroundFetch::kHasTitleNameHash, BackgroundFetch::kHasTitleName },

                    { BackgroundFetch::kNumIconsNameHash, BackgroundFetch::kNumIconsName },

                    { BackgroundFetch::kNumRequestsInFetchNameHash, BackgroundFetch::kNumRequestsInFetchName },

                    { BackgroundFetch::kRatioOfIdealToChosenIconSizeNameHash, BackgroundFetch::kRatioOfIdealToChosenIconSizeName },

                } } },

        { UINT64_C(2765600174500981245),
            { BackgroundFetchDeletingRegistration::kEntryName,
                {

                    { BackgroundFetchDeletingRegistration::kUserInitiatedAbortNameHash, BackgroundFetchDeletingRegistration::kUserInitiatedAbortName },

                } } },

        { UINT64_C(7109245137155486527),
            { BackgroundSyncCompleted::kEntryName,
                {

                    { BackgroundSyncCompleted::kMaxAttemptsNameHash, BackgroundSyncCompleted::kMaxAttemptsName },

                    { BackgroundSyncCompleted::kNumAttemptsNameHash, BackgroundSyncCompleted::kNumAttemptsName },

                    { BackgroundSyncCompleted::kStatusNameHash, BackgroundSyncCompleted::kStatusName },

                } } },

        { UINT64_C(3511425855963568724),
            { BackgroundSyncRegistered::kEntryName,
                {

                    { BackgroundSyncRegistered::kCanFireNameHash, BackgroundSyncRegistered::kCanFireName },

                    { BackgroundSyncRegistered::kIsReregisteredNameHash, BackgroundSyncRegistered::kIsReregisteredName },

                } } },

        { UINT64_C(12678664205992465342),
            { Badging::kEntryName,
                {

                    { Badging::kUpdateAppBadgeNameHash, Badging::kUpdateAppBadgeName },

                } } },

        { UINT64_C(5133941075635792608),
            { Blink_AutomaticLazyLoadFrame::kEntryName,
                {

                    { Blink_AutomaticLazyLoadFrame::kLazyAdsFrameCountNameHash, Blink_AutomaticLazyLoadFrame::kLazyAdsFrameCountName },

                    { Blink_AutomaticLazyLoadFrame::kLazyEmbedsFrameCountNameHash, Blink_AutomaticLazyLoadFrame::kLazyEmbedsFrameCountName },

                } } },

        { UINT64_C(14754961313036509949),
            { Blink_ContextMenu_ImageSelection::kEntryName,
                {

                    { Blink_ContextMenu_ImageSelection::kOutcomeNameHash, Blink_ContextMenu_ImageSelection::kOutcomeName },

                } } },

        { UINT64_C(17402744508281089121),
            { Blink_DeveloperMetricsRare::kEntryName,
                {

                    { Blink_DeveloperMetricsRare::kFeatureNameHash, Blink_DeveloperMetricsRare::kFeatureName },

                    { Blink_DeveloperMetricsRare::kIsMainFrameFeatureNameHash, Blink_DeveloperMetricsRare::kIsMainFrameFeatureName },

                } } },

        { UINT64_C(6601472140741101491),
            { Blink_FedCm::kEntryName,
                {

                    { Blink_FedCm::kFedCmSessionIDNameHash, Blink_FedCm::kFedCmSessionIDName },

                    { Blink_FedCm::kStatus_RequestIdTokenNameHash, Blink_FedCm::kStatus_RequestIdTokenName },

                    { Blink_FedCm::kTiming_CancelOnDialogNameHash, Blink_FedCm::kTiming_CancelOnDialogName },

                    { Blink_FedCm::kTiming_ContinueOnDialogNameHash, Blink_FedCm::kTiming_ContinueOnDialogName },

                    { Blink_FedCm::kTiming_IdTokenResponseNameHash, Blink_FedCm::kTiming_IdTokenResponseName },

                    { Blink_FedCm::kTiming_ShowAccountsDialogNameHash, Blink_FedCm::kTiming_ShowAccountsDialogName },

                    { Blink_FedCm::kTiming_TurnaroundTimeNameHash, Blink_FedCm::kTiming_TurnaroundTimeName },

                } } },

        { UINT64_C(14393930834880879921),
            { Blink_FedCmIdp::kEntryName,
                {

                    { Blink_FedCmIdp::kFedCmSessionIDNameHash, Blink_FedCmIdp::kFedCmSessionIDName },

                    { Blink_FedCmIdp::kStatus_RequestIdTokenNameHash, Blink_FedCmIdp::kStatus_RequestIdTokenName },

                    { Blink_FedCmIdp::kStatus_SignInStateMatchNameHash, Blink_FedCmIdp::kStatus_SignInStateMatchName },

                    { Blink_FedCmIdp::kTiming_CancelOnDialogNameHash, Blink_FedCmIdp::kTiming_CancelOnDialogName },

                    { Blink_FedCmIdp::kTiming_ContinueOnDialogNameHash, Blink_FedCmIdp::kTiming_ContinueOnDialogName },

                    { Blink_FedCmIdp::kTiming_IdTokenResponseNameHash, Blink_FedCmIdp::kTiming_IdTokenResponseName },

                    { Blink_FedCmIdp::kTiming_ShowAccountsDialogNameHash, Blink_FedCmIdp::kTiming_ShowAccountsDialogName },

                    { Blink_FedCmIdp::kTiming_TurnaroundTimeNameHash, Blink_FedCmIdp::kTiming_TurnaroundTimeName },

                } } },

        { UINT64_C(14503116569381719800),
            { Blink_FindInPage::kEntryName,
                {

                    { Blink_FindInPage::kBeforematchExpandedHiddenMatchableNameHash, Blink_FindInPage::kBeforematchExpandedHiddenMatchableName },

                    { Blink_FindInPage::kDidHaveRenderSubtreeMatchNameHash, Blink_FindInPage::kDidHaveRenderSubtreeMatchName },

                    { Blink_FindInPage::kDidSearchNameHash, Blink_FindInPage::kDidSearchName },

                } } },

        { UINT64_C(11969773594143228030),
            { Blink_HTMLParsing::kEntryName,
                {

                    { Blink_HTMLParsing::kChunkCountNameHash, Blink_HTMLParsing::kChunkCountName },

                    { Blink_HTMLParsing::kParsingTimeMaxNameHash, Blink_HTMLParsing::kParsingTimeMaxName },

                    { Blink_HTMLParsing::kParsingTimeMinNameHash, Blink_HTMLParsing::kParsingTimeMinName },

                    { Blink_HTMLParsing::kParsingTimeTotalNameHash, Blink_HTMLParsing::kParsingTimeTotalName },

                    { Blink_HTMLParsing::kTokensParsedAverageNameHash, Blink_HTMLParsing::kTokensParsedAverageName },

                    { Blink_HTMLParsing::kTokensParsedMaxNameHash, Blink_HTMLParsing::kTokensParsedMaxName },

                    { Blink_HTMLParsing::kTokensParsedMinNameHash, Blink_HTMLParsing::kTokensParsedMinName },

                    { Blink_HTMLParsing::kTokensParsedTotalNameHash, Blink_HTMLParsing::kTokensParsedTotalName },

                    { Blink_HTMLParsing::kYieldedTimeAverageNameHash, Blink_HTMLParsing::kYieldedTimeAverageName },

                    { Blink_HTMLParsing::kYieldedTimeMaxNameHash, Blink_HTMLParsing::kYieldedTimeMaxName },

                    { Blink_HTMLParsing::kYieldedTimeMinNameHash, Blink_HTMLParsing::kYieldedTimeMinName },

                } } },

        { UINT64_C(11315426756825559974),
            { Blink_PageLoad::kEntryName,
                {

                    { Blink_PageLoad::kAccessibilityNameHash, Blink_PageLoad::kAccessibilityName },

                    { Blink_PageLoad::kAnchorElementMetricsIntersectionObserverNameHash, Blink_PageLoad::kAnchorElementMetricsIntersectionObserverName },

                    { Blink_PageLoad::kAnimateNameHash, Blink_PageLoad::kAnimateName },

                    { Blink_PageLoad::kCompositingCommitNameHash, Blink_PageLoad::kCompositingCommitName },

                    { Blink_PageLoad::kCompositingInputsNameHash, Blink_PageLoad::kCompositingInputsName },

                    { Blink_PageLoad::kContentDocumentUpdateNameHash, Blink_PageLoad::kContentDocumentUpdateName },

                    { Blink_PageLoad::kDisplayLockIntersectionObserverNameHash, Blink_PageLoad::kDisplayLockIntersectionObserverName },

                    { Blink_PageLoad::kForcedStyleAndLayoutNameHash, Blink_PageLoad::kForcedStyleAndLayoutName },

                    { Blink_PageLoad::kHandleInputEventsNameHash, Blink_PageLoad::kHandleInputEventsName },

                    { Blink_PageLoad::kHitTestDocumentUpdateNameHash, Blink_PageLoad::kHitTestDocumentUpdateName },

                    { Blink_PageLoad::kImplCompositorCommitNameHash, Blink_PageLoad::kImplCompositorCommitName },

                    { Blink_PageLoad::kIntersectionObservationNameHash, Blink_PageLoad::kIntersectionObservationName },

                    { Blink_PageLoad::kIntersectionObservationInternalCountNameHash, Blink_PageLoad::kIntersectionObservationInternalCountName },

                    { Blink_PageLoad::kIntersectionObservationJavascriptCountNameHash, Blink_PageLoad::kIntersectionObservationJavascriptCountName },

                    { Blink_PageLoad::kJavascriptDocumentUpdateNameHash, Blink_PageLoad::kJavascriptDocumentUpdateName },

                    { Blink_PageLoad::kJavascriptIntersectionObserverNameHash, Blink_PageLoad::kJavascriptIntersectionObserverName },

                    { Blink_PageLoad::kLayoutNameHash, Blink_PageLoad::kLayoutName },

                    { Blink_PageLoad::kLazyLoadIntersectionObserverNameHash, Blink_PageLoad::kLazyLoadIntersectionObserverName },

                    { Blink_PageLoad::kMainFrameNameHash, Blink_PageLoad::kMainFrameName },

                    { Blink_PageLoad::kMediaIntersectionObserverNameHash, Blink_PageLoad::kMediaIntersectionObserverName },

                    { Blink_PageLoad::kPaintNameHash, Blink_PageLoad::kPaintName },

                    { Blink_PageLoad::kParseStyleSheetNameHash, Blink_PageLoad::kParseStyleSheetName },

                    { Blink_PageLoad::kPrePaintNameHash, Blink_PageLoad::kPrePaintName },

                    { Blink_PageLoad::kScrollDocumentUpdateNameHash, Blink_PageLoad::kScrollDocumentUpdateName },

                    { Blink_PageLoad::kServiceDocumentUpdateNameHash, Blink_PageLoad::kServiceDocumentUpdateName },

                    { Blink_PageLoad::kStyleNameHash, Blink_PageLoad::kStyleName },

                    { Blink_PageLoad::kUpdateLayersNameHash, Blink_PageLoad::kUpdateLayersName },

                    { Blink_PageLoad::kUpdateViewportIntersectionNameHash, Blink_PageLoad::kUpdateViewportIntersectionName },

                    { Blink_PageLoad::kUserDrivenDocumentUpdateNameHash, Blink_PageLoad::kUserDrivenDocumentUpdateName },

                    { Blink_PageLoad::kWaitForCommitNameHash, Blink_PageLoad::kWaitForCommitName },

                } } },

        { UINT64_C(14091970027896417477),
            { Blink_PaintTiming::kEntryName,
                {

                    { Blink_PaintTiming::kLCPDebugging_HasViewportImageNameHash, Blink_PaintTiming::kLCPDebugging_HasViewportImageName },

                } } },

        { UINT64_C(16907734789798036504),
            { Blink_Script_AsyncScripts::kEntryName,
                {

                } } },

        { UINT64_C(397568092790313676),
            { Blink_UpdateTime::kEntryName,
                {

                    { Blink_UpdateTime::kAccessibilityNameHash, Blink_UpdateTime::kAccessibilityName },

                    { Blink_UpdateTime::kAccessibilityBeginMainFrameNameHash, Blink_UpdateTime::kAccessibilityBeginMainFrameName },

                    { Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverNameHash, Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverName },

                    { Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverBeginMainFrameNameHash,
                        Blink_UpdateTime::kAnchorElementMetricsIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kAnimateNameHash, Blink_UpdateTime::kAnimateName },

                    { Blink_UpdateTime::kAnimateBeginMainFrameNameHash, Blink_UpdateTime::kAnimateBeginMainFrameName },

                    { Blink_UpdateTime::kCompositingCommitNameHash, Blink_UpdateTime::kCompositingCommitName },

                    { Blink_UpdateTime::kCompositingCommitBeginMainFrameNameHash, Blink_UpdateTime::kCompositingCommitBeginMainFrameName },

                    { Blink_UpdateTime::kCompositingInputsNameHash, Blink_UpdateTime::kCompositingInputsName },

                    { Blink_UpdateTime::kCompositingInputsBeginMainFrameNameHash, Blink_UpdateTime::kCompositingInputsBeginMainFrameName },

                    { Blink_UpdateTime::kContentDocumentUpdateNameHash, Blink_UpdateTime::kContentDocumentUpdateName },

                    { Blink_UpdateTime::kContentDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kContentDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kDisplayLockIntersectionObserverNameHash, Blink_UpdateTime::kDisplayLockIntersectionObserverName },

                    { Blink_UpdateTime::kDisplayLockIntersectionObserverBeginMainFrameNameHash, Blink_UpdateTime::kDisplayLockIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kForcedStyleAndLayoutNameHash, Blink_UpdateTime::kForcedStyleAndLayoutName },

                    { Blink_UpdateTime::kForcedStyleAndLayoutBeginMainFrameNameHash, Blink_UpdateTime::kForcedStyleAndLayoutBeginMainFrameName },

                    { Blink_UpdateTime::kHandleInputEventsNameHash, Blink_UpdateTime::kHandleInputEventsName },

                    { Blink_UpdateTime::kHandleInputEventsBeginMainFrameNameHash, Blink_UpdateTime::kHandleInputEventsBeginMainFrameName },

                    { Blink_UpdateTime::kHitTestDocumentUpdateNameHash, Blink_UpdateTime::kHitTestDocumentUpdateName },

                    { Blink_UpdateTime::kHitTestDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kHitTestDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kImplCompositorCommitNameHash, Blink_UpdateTime::kImplCompositorCommitName },

                    { Blink_UpdateTime::kImplCompositorCommitBeginMainFrameNameHash, Blink_UpdateTime::kImplCompositorCommitBeginMainFrameName },

                    { Blink_UpdateTime::kIntersectionObservationNameHash, Blink_UpdateTime::kIntersectionObservationName },

                    { Blink_UpdateTime::kIntersectionObservationBeginMainFrameNameHash, Blink_UpdateTime::kIntersectionObservationBeginMainFrameName },

                    { Blink_UpdateTime::kIntersectionObservationInternalCountNameHash, Blink_UpdateTime::kIntersectionObservationInternalCountName },

                    { Blink_UpdateTime::kIntersectionObservationInternalCountBeginMainFrameNameHash, Blink_UpdateTime::kIntersectionObservationInternalCountBeginMainFrameName },

                    { Blink_UpdateTime::kIntersectionObservationJavascriptCountNameHash, Blink_UpdateTime::kIntersectionObservationJavascriptCountName },

                    { Blink_UpdateTime::kIntersectionObservationJavascriptCountBeginMainFrameNameHash,
                        Blink_UpdateTime::kIntersectionObservationJavascriptCountBeginMainFrameName },

                    { Blink_UpdateTime::kJavascriptDocumentUpdateNameHash, Blink_UpdateTime::kJavascriptDocumentUpdateName },

                    { Blink_UpdateTime::kJavascriptDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kJavascriptDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kJavascriptIntersectionObserverNameHash, Blink_UpdateTime::kJavascriptIntersectionObserverName },

                    { Blink_UpdateTime::kJavascriptIntersectionObserverBeginMainFrameNameHash, Blink_UpdateTime::kJavascriptIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kLayoutNameHash, Blink_UpdateTime::kLayoutName },

                    { Blink_UpdateTime::kLayoutBeginMainFrameNameHash, Blink_UpdateTime::kLayoutBeginMainFrameName },

                    { Blink_UpdateTime::kLazyLoadIntersectionObserverNameHash, Blink_UpdateTime::kLazyLoadIntersectionObserverName },

                    { Blink_UpdateTime::kLazyLoadIntersectionObserverBeginMainFrameNameHash, Blink_UpdateTime::kLazyLoadIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kMainFrameNameHash, Blink_UpdateTime::kMainFrameName },

                    { Blink_UpdateTime::kMainFrameIsBeforeFCPNameHash, Blink_UpdateTime::kMainFrameIsBeforeFCPName },

                    { Blink_UpdateTime::kMainFrameReasonsNameHash, Blink_UpdateTime::kMainFrameReasonsName },

                    { Blink_UpdateTime::kMediaIntersectionObserverNameHash, Blink_UpdateTime::kMediaIntersectionObserverName },

                    { Blink_UpdateTime::kMediaIntersectionObserverBeginMainFrameNameHash, Blink_UpdateTime::kMediaIntersectionObserverBeginMainFrameName },

                    { Blink_UpdateTime::kPaintNameHash, Blink_UpdateTime::kPaintName },

                    { Blink_UpdateTime::kPaintBeginMainFrameNameHash, Blink_UpdateTime::kPaintBeginMainFrameName },

                    { Blink_UpdateTime::kParseStyleSheetNameHash, Blink_UpdateTime::kParseStyleSheetName },

                    { Blink_UpdateTime::kParseStyleSheetBeginMainFrameNameHash, Blink_UpdateTime::kParseStyleSheetBeginMainFrameName },

                    { Blink_UpdateTime::kPrePaintNameHash, Blink_UpdateTime::kPrePaintName },

                    { Blink_UpdateTime::kPrePaintBeginMainFrameNameHash, Blink_UpdateTime::kPrePaintBeginMainFrameName },

                    { Blink_UpdateTime::kScrollDocumentUpdateNameHash, Blink_UpdateTime::kScrollDocumentUpdateName },

                    { Blink_UpdateTime::kScrollDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kScrollDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kServiceDocumentUpdateNameHash, Blink_UpdateTime::kServiceDocumentUpdateName },

                    { Blink_UpdateTime::kServiceDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kServiceDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kStyleNameHash, Blink_UpdateTime::kStyleName },

                    { Blink_UpdateTime::kStyleBeginMainFrameNameHash, Blink_UpdateTime::kStyleBeginMainFrameName },

                    { Blink_UpdateTime::kStylePercentageNameHash, Blink_UpdateTime::kStylePercentageName },

                    { Blink_UpdateTime::kUpdateLayersNameHash, Blink_UpdateTime::kUpdateLayersName },

                    { Blink_UpdateTime::kUpdateLayersBeginMainFrameNameHash, Blink_UpdateTime::kUpdateLayersBeginMainFrameName },

                    { Blink_UpdateTime::kUpdateViewportIntersectionNameHash, Blink_UpdateTime::kUpdateViewportIntersectionName },

                    { Blink_UpdateTime::kUpdateViewportIntersectionBeginMainFrameNameHash, Blink_UpdateTime::kUpdateViewportIntersectionBeginMainFrameName },

                    { Blink_UpdateTime::kUserDrivenDocumentUpdateNameHash, Blink_UpdateTime::kUserDrivenDocumentUpdateName },

                    { Blink_UpdateTime::kUserDrivenDocumentUpdateBeginMainFrameNameHash, Blink_UpdateTime::kUserDrivenDocumentUpdateBeginMainFrameName },

                    { Blink_UpdateTime::kWaitForCommitNameHash, Blink_UpdateTime::kWaitForCommitName },

                    { Blink_UpdateTime::kWaitForCommitBeginMainFrameNameHash, Blink_UpdateTime::kWaitForCommitBeginMainFrameName },

                } } },

        { UINT64_C(16486120572686381376),
            { Blink_UseCounter::kEntryName,
                {

                    { Blink_UseCounter::kFeatureNameHash, Blink_UseCounter::kFeatureName },

                    { Blink_UseCounter::kIsMainFrameFeatureNameHash, Blink_UseCounter::kIsMainFrameFeatureName },

                } } },

        { UINT64_C(13731258013507976931),
            { BrowsingTopics_DocumentBrowsingTopicsApiResult::kEntryName,
                {

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kEmptyReasonNameHash, BrowsingTopics_DocumentBrowsingTopicsApiResult::kEmptyReasonName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0NameHash, BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0Name },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0IsTrueTopTopicNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0IsTrueTopTopicName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0ModelVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0ModelVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0TaxonomyVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic0TaxonomyVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1NameHash, BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1Name },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1IsTrueTopTopicNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1IsTrueTopTopicName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1ModelVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1ModelVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1TaxonomyVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic1TaxonomyVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2NameHash, BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2Name },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2IsTrueTopTopicNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2IsTrueTopTopicName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2ModelVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2ModelVersionName },

                    { BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2TaxonomyVersionNameHash,
                        BrowsingTopics_DocumentBrowsingTopicsApiResult::kReturnedTopic2TaxonomyVersionName },

                } } },

        { UINT64_C(3733375777248285534),
            { BrowsingTopics_EpochTopicsCalculationResult::kEntryName,
                {

                    { BrowsingTopics_EpochTopicsCalculationResult::kModelVersionNameHash, BrowsingTopics_EpochTopicsCalculationResult::kModelVersionName },

                    { BrowsingTopics_EpochTopicsCalculationResult::kPaddedTopicsStartIndexNameHash, BrowsingTopics_EpochTopicsCalculationResult::kPaddedTopicsStartIndexName },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTaxonomyVersionNameHash, BrowsingTopics_EpochTopicsCalculationResult::kTaxonomyVersionName },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic0NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic0Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic1NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic1Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic2NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic2Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic3NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic3Name },

                    { BrowsingTopics_EpochTopicsCalculationResult::kTopTopic4NameHash, BrowsingTopics_EpochTopicsCalculationResult::kTopTopic4Name },

                } } },

        { UINT64_C(514082468828822420),
            { BrowsingTopics_PageLoad::kEntryName,
                {

                    { BrowsingTopics_PageLoad::kTopicsRequestingContextDomainsCountNameHash, BrowsingTopics_PageLoad::kTopicsRequestingContextDomainsCountName },

                } } },

        { UINT64_C(17021732261447222699),
            { ChargeEventHistory::kEntryName,
                {

                    { ChargeEventHistory::kChargeEventHistoryDurationNameHash, ChargeEventHistory::kChargeEventHistoryDurationName },

                    { ChargeEventHistory::kChargeEventHistoryIndexNameHash, ChargeEventHistory::kChargeEventHistoryIndexName },

                    { ChargeEventHistory::kChargeEventHistorySizeNameHash, ChargeEventHistory::kChargeEventHistorySizeName },

                    { ChargeEventHistory::kChargeEventHistoryStartTimeNameHash, ChargeEventHistory::kChargeEventHistoryStartTimeName },

                    { ChargeEventHistory::kEventIdNameHash, ChargeEventHistory::kEventIdName },

                } } },

        { UINT64_C(4043047938625792161),
            { ChromeOS_WebsiteUsageTime::kEntryName,
                {

                    { ChromeOS_WebsiteUsageTime::kDurationNameHash, ChromeOS_WebsiteUsageTime::kDurationName },

                    { ChromeOS_WebsiteUsageTime::kIsFromLastLoginNameHash, ChromeOS_WebsiteUsageTime::kIsFromLastLoginName },

                    { ChromeOS_WebsiteUsageTime::kPromotableNameHash, ChromeOS_WebsiteUsageTime::kPromotableName },

                    { ChromeOS_WebsiteUsageTime::kUrlContentNameHash, ChromeOS_WebsiteUsageTime::kUrlContentName },

                    { ChromeOS_WebsiteUsageTime::kUserDeviceMatrixNameHash, ChromeOS_WebsiteUsageTime::kUserDeviceMatrixName },

                } } },

        { UINT64_C(16604269996013569427),
            { ChromeOSApp_InputEvent::kEntryName,
                {

                    { ChromeOSApp_InputEvent::kAppInputEventCountNameHash, ChromeOSApp_InputEvent::kAppInputEventCountName },

                    { ChromeOSApp_InputEvent::kAppInputEventSourceNameHash, ChromeOSApp_InputEvent::kAppInputEventSourceName },

                    { ChromeOSApp_InputEvent::kAppTypeNameHash, ChromeOSApp_InputEvent::kAppTypeName },

                    { ChromeOSApp_InputEvent::kUserDeviceMatrixNameHash, ChromeOSApp_InputEvent::kUserDeviceMatrixName },

                } } },

        { UINT64_C(13143522973299484729),
            { ChromeOSApp_InstalledApp::kEntryName,
                {

                    { ChromeOSApp_InstalledApp::kAppTypeNameHash, ChromeOSApp_InstalledApp::kAppTypeName },

                    { ChromeOSApp_InstalledApp::kInstallReasonNameHash, ChromeOSApp_InstalledApp::kInstallReasonName },

                    { ChromeOSApp_InstalledApp::kInstallSource2NameHash, ChromeOSApp_InstalledApp::kInstallSource2Name },

                    { ChromeOSApp_InstalledApp::kInstallTimeNameHash, ChromeOSApp_InstalledApp::kInstallTimeName },

                    { ChromeOSApp_InstalledApp::kUserDeviceMatrixNameHash, ChromeOSApp_InstalledApp::kUserDeviceMatrixName },

                } } },

        { UINT64_C(16690478234560038417),
            { ChromeOSApp_Launch::kEntryName,
                {

                    { ChromeOSApp_Launch::kAppTypeNameHash, ChromeOSApp_Launch::kAppTypeName },

                    { ChromeOSApp_Launch::kLaunchSourceNameHash, ChromeOSApp_Launch::kLaunchSourceName },

                    { ChromeOSApp_Launch::kUserDeviceMatrixNameHash, ChromeOSApp_Launch::kUserDeviceMatrixName },

                } } },

        { UINT64_C(7097858366631929652),
            { ChromeOSApp_UninstallApp::kEntryName,
                {

                    { ChromeOSApp_UninstallApp::kAppTypeNameHash, ChromeOSApp_UninstallApp::kAppTypeName },

                    { ChromeOSApp_UninstallApp::kUninstallSourceNameHash, ChromeOSApp_UninstallApp::kUninstallSourceName },

                    { ChromeOSApp_UninstallApp::kUserDeviceMatrixNameHash, ChromeOSApp_UninstallApp::kUserDeviceMatrixName },

                } } },

        { UINT64_C(2647010623881481336),
            { ChromeOSApp_UsageTime::kEntryName,
                {

                    { ChromeOSApp_UsageTime::kAppTypeNameHash, ChromeOSApp_UsageTime::kAppTypeName },

                    { ChromeOSApp_UsageTime::kDurationNameHash, ChromeOSApp_UsageTime::kDurationName },

                    { ChromeOSApp_UsageTime::kUserDeviceMatrixNameHash, ChromeOSApp_UsageTime::kUserDeviceMatrixName },

                } } },

        { UINT64_C(72420250988622518),
            { ChromeOSApp_UsageTimeReusedSourceId::kEntryName,
                {

                    { ChromeOSApp_UsageTimeReusedSourceId::kAppTypeNameHash, ChromeOSApp_UsageTimeReusedSourceId::kAppTypeName },

                    { ChromeOSApp_UsageTimeReusedSourceId::kDurationNameHash, ChromeOSApp_UsageTimeReusedSourceId::kDurationName },

                    { ChromeOSApp_UsageTimeReusedSourceId::kUserDeviceMatrixNameHash, ChromeOSApp_UsageTimeReusedSourceId::kUserDeviceMatrixName },

                } } },

        { UINT64_C(18270520290100355082),
            { ClickInput::kEntryName,
                {

                    { ClickInput::kExperimental_ClickInputBurstNameHash, ClickInput::kExperimental_ClickInputBurstName },

                } } },

        { UINT64_C(528939567029470806),
            { ClientRenderingAPI::kEntryName,
                {

                    { ClientRenderingAPI::kCanvas_RenderingContextNameHash, ClientRenderingAPI::kCanvas_RenderingContextName },

                    { ClientRenderingAPI::kCanvas_RenderingContextDrawnToNameHash, ClientRenderingAPI::kCanvas_RenderingContextDrawnToName },

                    { ClientRenderingAPI::kGPUDeviceNameHash, ClientRenderingAPI::kGPUDeviceName },

                    { ClientRenderingAPI::kOffscreenCanvas_RenderingContextNameHash, ClientRenderingAPI::kOffscreenCanvas_RenderingContextName },

                    { ClientRenderingAPI::kOffscreenCanvas_RenderingContextDrawnToNameHash, ClientRenderingAPI::kOffscreenCanvas_RenderingContextDrawnToName },

                } } },

        { UINT64_C(18003859069234917647),
            { Compositor_Rendering::kEntryName,
                {

                    { Compositor_Rendering::kCheckerboardedImagesCountNameHash, Compositor_Rendering::kCheckerboardedImagesCountName },

                } } },

        { UINT64_C(3378172330402895005),
            { Compositor_UserInteraction::kEntryName,
                {

                    { Compositor_UserInteraction::kCheckerboardedContentAreaNameHash, Compositor_UserInteraction::kCheckerboardedContentAreaName },

                    { Compositor_UserInteraction::kCheckerboardedContentAreaRatioNameHash, Compositor_UserInteraction::kCheckerboardedContentAreaRatioName },

                    { Compositor_UserInteraction::kCheckerboardedImagesCountNameHash, Compositor_UserInteraction::kCheckerboardedImagesCountName },

                    { Compositor_UserInteraction::kNumMissingTilesNameHash, Compositor_UserInteraction::kNumMissingTilesName },

                } } },

        { UINT64_C(11375675958515902207),
            { ContactsPicker_ShareStatistics::kEntryName,
                {

                    { ContactsPicker_ShareStatistics::kPropertiesRequestedNameHash, ContactsPicker_ShareStatistics::kPropertiesRequestedName },

                    { ContactsPicker_ShareStatistics::kSelectCountNameHash, ContactsPicker_ShareStatistics::kSelectCountName },

                    { ContactsPicker_ShareStatistics::kSelectPercentageNameHash, ContactsPicker_ShareStatistics::kSelectPercentageName },

                } } },

        { UINT64_C(7195670717417274603),
            { ContentIndex_Added::kEntryName,
                {

                    { ContentIndex_Added::kCategoryNameHash, ContentIndex_Added::kCategoryName },

                } } },

        { UINT64_C(8302809238691294596),
            { ContentIndex_DeletedByUser::kEntryName,
                {

                    { ContentIndex_DeletedByUser::kDeletedNameHash, ContentIndex_DeletedByUser::kDeletedName },

                } } },

        { UINT64_C(4039427715416584382),
            { ContentIndex_Opened::kEntryName,
                {

                    { ContentIndex_Opened::kIsOfflineNameHash, ContentIndex_Opened::kIsOfflineName },

                } } },

        { UINT64_C(1205887675013444985),
            { ContextMenuAndroid_Selected::kEntryName,
                {

                    { ContextMenuAndroid_Selected::kActionNameHash, ContextMenuAndroid_Selected::kActionName },

                } } },

        { UINT64_C(12646817710005836743),
            { ContextMenuAndroid_Shown::kEntryName,
                {

                    { ContextMenuAndroid_Shown::kSearchByImageNameHash, ContextMenuAndroid_Shown::kSearchByImageName },

                    { ContextMenuAndroid_Shown::kSearchWithGoogleLensNameHash, ContextMenuAndroid_Shown::kSearchWithGoogleLensName },

                    { ContextMenuAndroid_Shown::kShopWithGoogleLensNameHash, ContextMenuAndroid_Shown::kShopWithGoogleLensName },

                    { ContextMenuAndroid_Shown::kShopWithGoogleLensChipNameHash, ContextMenuAndroid_Shown::kShopWithGoogleLensChipName },

                    { ContextMenuAndroid_Shown::kTranslateWithGoogleLensChipNameHash, ContextMenuAndroid_Shown::kTranslateWithGoogleLensChipName },

                } } },

        { UINT64_C(988984496812825435),
            { CPUUsageMeasurement::kEntryName,
                {

                    { CPUUsageMeasurement::kCPUUsageNameHash, CPUUsageMeasurement::kCPUUsageName },

                    { CPUUsageMeasurement::kEventTypeNameHash, CPUUsageMeasurement::kEventTypeName },

                    { CPUUsageMeasurement::kIsVisibleNameHash, CPUUsageMeasurement::kIsVisibleName },

                    { CPUUsageMeasurement::kNumberOfCoresidentTabsNameHash, CPUUsageMeasurement::kNumberOfCoresidentTabsName },

                    { CPUUsageMeasurement::kObservationWindowSizeMsNameHash, CPUUsageMeasurement::kObservationWindowSizeMsName },

                    { CPUUsageMeasurement::kProcessUptimeMsNameHash, CPUUsageMeasurement::kProcessUptimeMsName },

                } } },

        { UINT64_C(15054308220608486353),
            { CrossOriginSubframeWithoutEmbeddingControl::kEntryName,
                {

                    { CrossOriginSubframeWithoutEmbeddingControl::kSubframeEmbeddedNameHash, CrossOriginSubframeWithoutEmbeddingControl::kSubframeEmbeddedName },

                } } },

        { UINT64_C(16118191348399710349),
            { DailyChargeSummary::kEntryName,
                {

                    { DailyChargeSummary::kDailySummaryHoldTimeOnAcNameHash, DailyChargeSummary::kDailySummaryHoldTimeOnAcName },

                    { DailyChargeSummary::kDailySummaryIndexNameHash, DailyChargeSummary::kDailySummaryIndexName },

                    { DailyChargeSummary::kDailySummaryNumDaysDistanceNameHash, DailyChargeSummary::kDailySummaryNumDaysDistanceName },

                    { DailyChargeSummary::kDailySummarySizeNameHash, DailyChargeSummary::kDailySummarySizeName },

                    { DailyChargeSummary::kDailySummaryTimeFullOnAcNameHash, DailyChargeSummary::kDailySummaryTimeFullOnAcName },

                    { DailyChargeSummary::kDailySummaryTimeOnAcNameHash, DailyChargeSummary::kDailySummaryTimeOnAcName },

                    { DailyChargeSummary::kEventIdNameHash, DailyChargeSummary::kEventIdName },

                } } },

        { UINT64_C(26394013458683718),
            { DataReductionProxy::kEntryName,
                {

                    { DataReductionProxy::kDataSaverPageUUIDNameHash, DataReductionProxy::kDataSaverPageUUIDName },

                    { DataReductionProxy::kEstimatedOriginalNetworkBytesNameHash, DataReductionProxy::kEstimatedOriginalNetworkBytesName },

                } } },

        { UINT64_C(15719730292389568123),
            { DIPS_Redirect::kEntryName,
                {

                    { DIPS_Redirect::kClientBounceDelayNameHash, DIPS_Redirect::kClientBounceDelayName },

                    { DIPS_Redirect::kCookieAccessTypeNameHash, DIPS_Redirect::kCookieAccessTypeName },

                    { DIPS_Redirect::kHasStickyActivationNameHash, DIPS_Redirect::kHasStickyActivationName },

                    { DIPS_Redirect::kInitialAndFinalSitesSameNameHash, DIPS_Redirect::kInitialAndFinalSitesSameName },

                    { DIPS_Redirect::kRedirectAndFinalSiteSameNameHash, DIPS_Redirect::kRedirectAndFinalSiteSameName },

                    { DIPS_Redirect::kRedirectAndInitialSiteSameNameHash, DIPS_Redirect::kRedirectAndInitialSiteSameName },

                    { DIPS_Redirect::kRedirectChainIndexNameHash, DIPS_Redirect::kRedirectChainIndexName },

                    { DIPS_Redirect::kRedirectChainLengthNameHash, DIPS_Redirect::kRedirectChainLengthName },

                    { DIPS_Redirect::kRedirectTypeNameHash, DIPS_Redirect::kRedirectTypeName },

                    { DIPS_Redirect::kSiteEngagementLevelNameHash, DIPS_Redirect::kSiteEngagementLevelName },

                } } },

        { UINT64_C(2704655726834470033),
            { DocumentCreated::kEntryName,
                {

                    { DocumentCreated::kIsCrossOriginFrameNameHash, DocumentCreated::kIsCrossOriginFrameName },

                    { DocumentCreated::kIsCrossSiteFrameNameHash, DocumentCreated::kIsCrossSiteFrameName },

                    { DocumentCreated::kIsMainFrameNameHash, DocumentCreated::kIsMainFrameName },

                    { DocumentCreated::kNavigationSourceIdNameHash, DocumentCreated::kNavigationSourceIdName },

                } } },

        { UINT64_C(9818692869640581957),
            { Download_Completed::kEntryName,
                {

                    { Download_Completed::kBytesWastedNameHash, Download_Completed::kBytesWastedName },

                    { Download_Completed::kDownloadIdNameHash, Download_Completed::kDownloadIdName },

                    { Download_Completed::kResultingFileSizeNameHash, Download_Completed::kResultingFileSizeName },

                    { Download_Completed::kTimeSinceStartNameHash, Download_Completed::kTimeSinceStartName },

                } } },

        { UINT64_C(9706055097174303),
            { Download_Interrupted::kEntryName,
                {

                    { Download_Interrupted::kBytesWastedNameHash, Download_Interrupted::kBytesWastedName },

                    { Download_Interrupted::kChangeInFileSizeNameHash, Download_Interrupted::kChangeInFileSizeName },

                    { Download_Interrupted::kDownloadIdNameHash, Download_Interrupted::kDownloadIdName },

                    { Download_Interrupted::kReasonNameHash, Download_Interrupted::kReasonName },

                    { Download_Interrupted::kResultingFileSizeNameHash, Download_Interrupted::kResultingFileSizeName },

                    { Download_Interrupted::kTimeSinceStartNameHash, Download_Interrupted::kTimeSinceStartName },

                } } },

        { UINT64_C(9188207819461355990),
            { Download_Resumed::kEntryName,
                {

                    { Download_Resumed::kDownloadIdNameHash, Download_Resumed::kDownloadIdName },

                    { Download_Resumed::kModeNameHash, Download_Resumed::kModeName },

                    { Download_Resumed::kTimeSinceStartNameHash, Download_Resumed::kTimeSinceStartName },

                } } },

        { UINT64_C(2153997617158303225),
            { Download_Started::kEntryName,
                {

                    { Download_Started::kDownloadConnectionSecurityNameHash, Download_Started::kDownloadConnectionSecurityName },

                    { Download_Started::kDownloadIdNameHash, Download_Started::kDownloadIdName },

                    { Download_Started::kDownloadSourceNameHash, Download_Started::kDownloadSourceName },

                    { Download_Started::kFileTypeNameHash, Download_Started::kFileTypeName },

                    { Download_Started::kIsSameHostDownloadNameHash, Download_Started::kIsSameHostDownloadName },

                } } },

        { UINT64_C(12255255036748617486),
            { Event_ScrollBegin_Touch::kEntryName,
                {

                    { Event_ScrollBegin_Touch::kIsMainThreadNameHash, Event_ScrollBegin_Touch::kIsMainThreadName },

                    { Event_ScrollBegin_Touch::kTimeToHandledNameHash, Event_ScrollBegin_Touch::kTimeToHandledName },

                    { Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollBegin_Touch::kTimeToScrollUpdateSwapBeginName },

                } } },

        { UINT64_C(15188233126885586509),
            { Event_ScrollBegin_Wheel::kEntryName,
                {

                    { Event_ScrollBegin_Wheel::kIsMainThreadNameHash, Event_ScrollBegin_Wheel::kIsMainThreadName },

                    { Event_ScrollBegin_Wheel::kTimeToHandledNameHash, Event_ScrollBegin_Wheel::kTimeToHandledName },

                    { Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollBegin_Wheel::kTimeToScrollUpdateSwapBeginName },

                } } },

        { UINT64_C(7257623327097011244),
            { Event_ScrollUpdate_Touch::kEntryName,
                {

                    { Event_ScrollUpdate_Touch::kIsMainThreadNameHash, Event_ScrollUpdate_Touch::kIsMainThreadName },

                    { Event_ScrollUpdate_Touch::kTimeToHandledNameHash, Event_ScrollUpdate_Touch::kTimeToHandledName },

                    { Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollUpdate_Touch::kTimeToScrollUpdateSwapBeginName },

                } } },

        { UINT64_C(12963707033129547010),
            { Event_ScrollUpdate_Wheel::kEntryName,
                {

                    { Event_ScrollUpdate_Wheel::kIsMainThreadNameHash, Event_ScrollUpdate_Wheel::kIsMainThreadName },

                    { Event_ScrollUpdate_Wheel::kTimeToHandledNameHash, Event_ScrollUpdate_Wheel::kTimeToHandledName },

                    { Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginNameHash, Event_ScrollUpdate_Wheel::kTimeToScrollUpdateSwapBeginName },

                } } },

        { UINT64_C(12524558333720971544),
            { Extensions_WebRequest_KeepaliveRequestFinished::kEntryName,
                {

                    { Extensions_WebRequest_KeepaliveRequestFinished::kNumRedirectsNameHash, Extensions_WebRequest_KeepaliveRequestFinished::kNumRedirectsName },

                    { Extensions_WebRequest_KeepaliveRequestFinished::kStateNameHash, Extensions_WebRequest_KeepaliveRequestFinished::kStateName },

                } } },

        { UINT64_C(15744625327213391071),
            { FileSystemAPI_WebRequest::kEntryName,
                {

                    { FileSystemAPI_WebRequest::kPersistentNameHash, FileSystemAPI_WebRequest::kPersistentName },

                    { FileSystemAPI_WebRequest::kTemporaryNameHash, FileSystemAPI_WebRequest::kTemporaryName },

                } } },

        { UINT64_C(6247082832829199138),
            { FlocPageLoad::kEntryName,
                {

                    { FlocPageLoad::kFlocIdNameHash, FlocPageLoad::kFlocIdName },

                } } },

        { UINT64_C(14096131912271921055),
            { FontMatchAttempts::kEntryName,
                {

                    { FontMatchAttempts::kLoadContextNameHash, FontMatchAttempts::kLoadContextName },

                    { FontMatchAttempts::kLocalFontFailuresNameHash, FontMatchAttempts::kLocalFontFailuresName },

                    { FontMatchAttempts::kLocalFontSuccessesNameHash, FontMatchAttempts::kLocalFontSuccessesName },

                    { FontMatchAttempts::kLocalFontTotalNameHash, FontMatchAttempts::kLocalFontTotalName },

                    { FontMatchAttempts::kSystemFontFamilyFailuresNameHash, FontMatchAttempts::kSystemFontFamilyFailuresName },

                    { FontMatchAttempts::kSystemFontFamilySuccessesNameHash, FontMatchAttempts::kSystemFontFamilySuccessesName },

                    { FontMatchAttempts::kSystemFontFamilyTotalNameHash, FontMatchAttempts::kSystemFontFamilyTotalName },

                    { FontMatchAttempts::kWebFontFamilyFailuresNameHash, FontMatchAttempts::kWebFontFamilyFailuresName },

                    { FontMatchAttempts::kWebFontFamilySuccessesNameHash, FontMatchAttempts::kWebFontFamilySuccessesName },

                    { FontMatchAttempts::kWebFontFamilyTotalNameHash, FontMatchAttempts::kWebFontFamilyTotalName },

                } } },

        { UINT64_C(15868125188758034185),
            { GamingInputOverlay_Customization::kEntryName,
                {

                    { GamingInputOverlay_Customization::kCustomizationUsedNameHash, GamingInputOverlay_Customization::kCustomizationUsedName },

                } } },

        { UINT64_C(8325704071122675056),
            { GamingInputOverlay_Feature::kEntryName,
                {

                    { GamingInputOverlay_Feature::kFeatureStateOnNameHash, GamingInputOverlay_Feature::kFeatureStateOnName },

                } } },

        { UINT64_C(10738302011954418259),
            { GamingInputOverlay_MappingHint::kEntryName,
                {

                    { GamingInputOverlay_MappingHint::kMappingHintStateOnNameHash, GamingInputOverlay_MappingHint::kMappingHintStateOnName },

                } } },

        { UINT64_C(17713702562453741093),
            { GeneratedNavigation::kEntryName,
                {

                    { GeneratedNavigation::kFinalURLIsDefaultSearchEngineNameHash, GeneratedNavigation::kFinalURLIsDefaultSearchEngineName },

                    { GeneratedNavigation::kFinalURLIsHomePageNameHash, GeneratedNavigation::kFinalURLIsHomePageName },

                    { GeneratedNavigation::kFirstURLIsDefaultSearchEngineNameHash, GeneratedNavigation::kFirstURLIsDefaultSearchEngineName },

                    { GeneratedNavigation::kFirstURLIsHomePageNameHash, GeneratedNavigation::kFirstURLIsHomePageName },

                } } },

        { UINT64_C(3420244295988015024),
            { GoogleDocsOfflineExtension::kEntryName,
                {

                    { GoogleDocsOfflineExtension::kResourceRequestedNameHash, GoogleDocsOfflineExtension::kResourceRequestedName },

                } } },

        { UINT64_C(11577416923418681607),
            { Graphics_Smoothness_EventLatency::kEntryName,
                {

                    { Graphics_Smoothness_EventLatency::kActivationNameHash, Graphics_Smoothness_EventLatency::kActivationName },

                    { Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameNameHash, Graphics_Smoothness_EventLatency::kBeginImplFrameToSendBeginMainFrameName },

                    { Graphics_Smoothness_EventLatency::kCommitNameHash, Graphics_Smoothness_EventLatency::kCommitName },

                    { Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameNameHash, Graphics_Smoothness_EventLatency::kEndActivateToSubmitCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kEndCommitToActivationNameHash, Graphics_Smoothness_EventLatency::kEndCommitToActivationName },

                    { Graphics_Smoothness_EventLatency::kEventTypeNameHash, Graphics_Smoothness_EventLatency::kEventTypeName },

                    { Graphics_Smoothness_EventLatency::kGenerationToRendererCompositorNameHash, Graphics_Smoothness_EventLatency::kGenerationToRendererCompositorName },

                    { Graphics_Smoothness_EventLatency::kPinchInputTypeNameHash, Graphics_Smoothness_EventLatency::kPinchInputTypeName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToActivationNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToActivationName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToBeginImplFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToBeginImplFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToCommitNameHash, Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndActivateNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndActivateName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndCommitNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToEndCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSendBeginMainFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSendBeginMainFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSubmitCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererCompositorFinishedToSubmitCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorProcessingNameHash, Graphics_Smoothness_EventLatency::kRendererCompositorProcessingName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorQueueingDelayNameHash, Graphics_Smoothness_EventLatency::kRendererCompositorQueueingDelayName },

                    { Graphics_Smoothness_EventLatency::kRendererCompositorToMainNameHash, Graphics_Smoothness_EventLatency::kRendererCompositorToMainName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToActivationNameHash, Graphics_Smoothness_EventLatency::kRendererMainFinishedToActivationName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToBeginImplFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToBeginImplFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToCommitNameHash, Graphics_Smoothness_EventLatency::kRendererMainFinishedToCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndActivateNameHash, Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndActivateName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndCommitNameHash, Graphics_Smoothness_EventLatency::kRendererMainFinishedToEndCommitName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToSendBeginMainFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToSendBeginMainFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererMainFinishedToSubmitCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kRendererMainFinishedToSubmitCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kRendererMainProcessingNameHash, Graphics_Smoothness_EventLatency::kRendererMainProcessingName },

                    { Graphics_Smoothness_EventLatency::kScrollInputTypeNameHash, Graphics_Smoothness_EventLatency::kScrollInputTypeName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitNameHash, Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommitName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AccessibilityNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AccessibilityName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AnimateNameHash, Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_AnimateName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_BeginMainSentToStartedName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositeCommitNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositeCommitName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositingInputsNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_CompositingInputsName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_HandleInputEventsNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_HandleInputEventsName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_LayoutUpdateNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_LayoutUpdateName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PaintNameHash, Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PaintName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PrepaintNameHash, Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_PrepaintName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_StyleUpdateNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_StyleUpdateName },

                    { Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_UpdateLayersNameHash,
                        Graphics_Smoothness_EventLatency::kSendBeginMainFrameToCommit_UpdateLayersName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName },

                    { Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash,
                        Graphics_Smoothness_EventLatency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName },

                    { Graphics_Smoothness_EventLatency::kTotalLatencyNameHash, Graphics_Smoothness_EventLatency::kTotalLatencyName },

                } } },

        { UINT64_C(4259890394998283936),
            { Graphics_Smoothness_Latency::kEntryName,
                {

                    { Graphics_Smoothness_Latency::kActivationNameHash, Graphics_Smoothness_Latency::kActivationName },

                    { Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameNameHash, Graphics_Smoothness_Latency::kBeginImplFrameToSendBeginMainFrameName },

                    { Graphics_Smoothness_Latency::kCanvasAnimationNameHash, Graphics_Smoothness_Latency::kCanvasAnimationName },

                    { Graphics_Smoothness_Latency::kCommitNameHash, Graphics_Smoothness_Latency::kCommitName },

                    { Graphics_Smoothness_Latency::kCompositorAnimationNameHash, Graphics_Smoothness_Latency::kCompositorAnimationName },

                    { Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameNameHash, Graphics_Smoothness_Latency::kEndActivateToSubmitCompositorFrameName },

                    { Graphics_Smoothness_Latency::kEndCommitToActivationNameHash, Graphics_Smoothness_Latency::kEndCommitToActivationName },

                    { Graphics_Smoothness_Latency::kJSAnimationNameHash, Graphics_Smoothness_Latency::kJSAnimationName },

                    { Graphics_Smoothness_Latency::kMainThreadAnimationNameHash, Graphics_Smoothness_Latency::kMainThreadAnimationName },

                    { Graphics_Smoothness_Latency::kMissedFrameNameHash, Graphics_Smoothness_Latency::kMissedFrameName },

                    { Graphics_Smoothness_Latency::kPinchZoomNameHash, Graphics_Smoothness_Latency::kPinchZoomName },

                    { Graphics_Smoothness_Latency::kRAFNameHash, Graphics_Smoothness_Latency::kRAFName },

                    { Graphics_Smoothness_Latency::kScrollbarScrollNameHash, Graphics_Smoothness_Latency::kScrollbarScrollName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommitName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AccessibilityNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AccessibilityName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AnimateNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_AnimateName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_BeginMainSentToStartedNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_BeginMainSentToStartedName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositeCommitNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositeCommitName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositingInputsNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_CompositingInputsName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_HandleInputEventsNameHash,
                        Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_HandleInputEventsName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_LayoutUpdateNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_LayoutUpdateName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PaintNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PaintName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PrepaintNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_PrepaintName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_StyleUpdateNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_StyleUpdateName },

                    { Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_UpdateLayersNameHash, Graphics_Smoothness_Latency::kSendBeginMainFrameToCommit_UpdateLayersName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrameName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferAvailableToBufferReadyName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_BufferReadyToLatchName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_LatchToSwapEndName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_ReceivedCompositorFrameToStartDrawName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_StartDrawToSwapStartName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SubmitToReceiveCompositorFrameName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapEndToPresentationCompositorFrameName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToBufferAvailableName },

                    { Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndNameHash,
                        Graphics_Smoothness_Latency::kSubmitCompositorFrameToPresentationCompositorFrame_SwapStartToSwapEndName },

                    { Graphics_Smoothness_Latency::kTotalLatencyNameHash, Graphics_Smoothness_Latency::kTotalLatencyName },

                    { Graphics_Smoothness_Latency::kTouchScrollNameHash, Graphics_Smoothness_Latency::kTouchScrollName },

                    { Graphics_Smoothness_Latency::kUnknownNameHash, Graphics_Smoothness_Latency::kUnknownName },

                    { Graphics_Smoothness_Latency::kVideoNameHash, Graphics_Smoothness_Latency::kVideoName },

                    { Graphics_Smoothness_Latency::kWheelScrollNameHash, Graphics_Smoothness_Latency::kWheelScrollName },

                } } },

        { UINT64_C(5416874090953909475),
            { Graphics_Smoothness_NormalizedPercentDroppedFrames::kEntryName,
                {

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kAboveThresholdNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kAboveThresholdName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kAverageNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kAverageName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedMedianNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kCompositorFocusedVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedMedianNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kMainFocusedVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kMedianNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kPercentile95NameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedMedianNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedMedianName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedPercentile95NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedPercentile95Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedVarianceNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kScrollFocusedVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessBadNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessBadName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessGoodNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessGoodName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessOkayNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessOkayName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad25to50NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad25to50Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad50to75NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad50to75Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad75to100NameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryBad75to100Name },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryGoodNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kSmoothnessVeryGoodName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kVarianceNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kVarianceName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseNameHash, Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter1SecNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter1SecName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter2SecNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter2SecName },

                    { Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter5SecNameHash,
                        Graphics_Smoothness_NormalizedPercentDroppedFrames::kWorstCaseAfter5SecName },

                } } },

        { UINT64_C(6831778698353217167),
            { Graphics_Smoothness_PercentDroppedFrames::kEntryName,
                {

                    { Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsNameHash, Graphics_Smoothness_PercentDroppedFrames::kAllAnimationsName },

                    { Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsNameHash, Graphics_Smoothness_PercentDroppedFrames::kAllInteractionsName },

                    { Graphics_Smoothness_PercentDroppedFrames::kAllSequencesNameHash, Graphics_Smoothness_PercentDroppedFrames::kAllSequencesName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_CompositorAnimationName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_MainThreadAnimationName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_PinchZoomName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_RAFName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_ScrollbarScrollNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_ScrollbarScrollName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_TouchScrollName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoNameHash, Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_VideoName },

                    { Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kCompositorThread_WheelScrollName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_CanvasAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_CanvasAnimationName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kMainThread_CompositorAnimationName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_JSAnimationNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_JSAnimationName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationNameHash,
                        Graphics_Smoothness_PercentDroppedFrames::kMainThread_MainThreadAnimationName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_PinchZoomName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_RAFName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_ScrollbarScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_ScrollbarScrollName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_TouchScrollName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_VideoName },

                    { Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollNameHash, Graphics_Smoothness_PercentDroppedFrames::kMainThread_WheelScrollName },

                    { Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomNameHash, Graphics_Smoothness_PercentDroppedFrames::kSlowerThread_PinchZoomName },

                } } },

        { UINT64_C(13892688012376547748),
            { HistoryClusters::kEntryName,
                {

                    { HistoryClusters::kFinalStateNameHash, HistoryClusters::kFinalStateName },

                    { HistoryClusters::kInitialStateNameHash, HistoryClusters::kInitialStateName },

                    { HistoryClusters::kNumQueriesNameHash, HistoryClusters::kNumQueriesName },

                    { HistoryClusters::kNumTogglesToBasicHistoryNameHash, HistoryClusters::kNumTogglesToBasicHistoryName },

                } } },

        { UINT64_C(17985071802125984440),
            { HistoryManipulationIntervention::kEntryName,
                {

                } } },

        { UINT64_C(6390056345493314213),
            { HistoryNavigation::kEntryName,
                {

                    { HistoryNavigation::kAverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2NameHash,
                        HistoryNavigation::kAverageUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2Name },

                    { HistoryNavigation::kBackForwardCache_BlocklistedFeaturesNameHash, HistoryNavigation::kBackForwardCache_BlocklistedFeaturesName },

                    { HistoryNavigation::kBackForwardCache_BrowsingInstanceNotSwappedReasonNameHash, HistoryNavigation::kBackForwardCache_BrowsingInstanceNotSwappedReasonName },

                    { HistoryNavigation::kBackForwardCache_DisabledForRenderFrameHostReasonCountNameHash,
                        HistoryNavigation::kBackForwardCache_DisabledForRenderFrameHostReasonCountName },

                    { HistoryNavigation::kBackForwardCache_IsAmpPageNameHash, HistoryNavigation::kBackForwardCache_IsAmpPageName },

                    { HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheNameHash, HistoryNavigation::kBackForwardCache_IsServedFromBackForwardCacheName },

                    { HistoryNavigation::kBackForwardCache_NotRestoredReasonsNameHash, HistoryNavigation::kBackForwardCache_NotRestoredReasonsName },

                    { HistoryNavigation::kCrossOriginSubframesFeaturesNameHash, HistoryNavigation::kCrossOriginSubframesFeaturesName },

                    { HistoryNavigation::kCumulativeShiftScoreAfterBackForwardCacheRestoreNameHash, HistoryNavigation::kCumulativeShiftScoreAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kFirstInputDelayAfterBackForwardCacheRestoreNameHash, HistoryNavigation::kFirstInputDelayAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kFirstRequestAnimationFrameAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kFirstRequestAnimationFrameAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kForegroundDurationAfterBackForwardCacheRestoreNameHash, HistoryNavigation::kForegroundDurationAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentNameHash,
                        HistoryNavigation::kLastCommittedCrossDocumentNavigationSourceIdForTheSameDocumentName },

                    { HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentNameHash, HistoryNavigation::kLastCommittedSourceIdForTheSameDocumentName },

                    { HistoryNavigation::kMainFrameFeaturesNameHash, HistoryNavigation::kMainFrameFeaturesName },

                    { HistoryNavigation::kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        HistoryNavigation::kMaxCumulativeShiftScoreAfterBackForwardCacheRestore_SessionWindow_Gap1000ms_Max5000msName },

                    { HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentNameHash, HistoryNavigation::kNavigatedToTheMostRecentEntryForDocumentName },

                    { HistoryNavigation::kNavigationToFirstPaintAfterBackForwardCacheRestoreNameHash, HistoryNavigation::kNavigationToFirstPaintAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kNumInteractionsAfterBackForwardCacheRestoreNameHash, HistoryNavigation::kNumInteractionsAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kPageEndReasonAfterBackForwardCacheRestoreNameHash, HistoryNavigation::kPageEndReasonAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kSameOriginSubframesFeaturesNameHash, HistoryNavigation::kSameOriginSubframesFeaturesName },

                    { HistoryNavigation::kSecondRequestAnimationFrameAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kSecondRequestAnimationFrameAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kSlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration2NameHash,
                        HistoryNavigation::kSlowUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_HighPercentile2_MaxEventDuration2Name },

                    { HistoryNavigation::kSumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2NameHash,
                        HistoryNavigation::kSumOfUserInteractionLatencyOverBudgetAfterBackForwardCacheRestore_MaxEventDuration2Name },

                    { HistoryNavigation::kThirdRequestAnimationFrameAfterBackForwardCacheRestoreNameHash,
                        HistoryNavigation::kThirdRequestAnimationFrameAfterBackForwardCacheRestoreName },

                    { HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentNameHash, HistoryNavigation::kTimeSinceNavigatedAwayFromDocumentName },

                    { HistoryNavigation::kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationNameHash,
                        HistoryNavigation::kUserInteractionLatencyAfterBackForwardCacheRestore_HighPercentile2_MaxEventDurationName },

                    { HistoryNavigation::kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2NameHash,
                        HistoryNavigation::kWorstUserInteractionLatencyAfterBackForwardCacheRestore_MaxEventDuration2Name },

                } } },

        { UINT64_C(287024497009309687),
            { Identifiability::kEntryName,
                {

                    { Identifiability::kGeneratorVersion_926NameHash, Identifiability::kGeneratorVersion_926Name },

                    { Identifiability::kStudyGeneration_626NameHash, Identifiability::kStudyGeneration_626Name },

                } } },

        { UINT64_C(2784102704372436909),
            { InputEvent::kEntryName,
                {

                    { InputEvent::kEventTypeNameHash, InputEvent::kEventTypeName },

                    { InputEvent::kInteractiveTiming_InputDelayNameHash, InputEvent::kInteractiveTiming_InputDelayName },

                    { InputEvent::kInteractiveTiming_ProcessingFinishedToNextPaintNameHash, InputEvent::kInteractiveTiming_ProcessingFinishedToNextPaintName },

                    { InputEvent::kInteractiveTiming_ProcessingTimeNameHash, InputEvent::kInteractiveTiming_ProcessingTimeName },

                } } },

        { UINT64_C(16471533519799856378),
            { InputMethod_Assistive_Match::kEntryName,
                {

                    { InputMethod_Assistive_Match::kTypeNameHash, InputMethod_Assistive_Match::kTypeName },

                } } },

        { UINT64_C(16790499697963531667),
            { InputMethod_NonCompliantApi::kEntryName,
                {

                    { InputMethod_NonCompliantApi::kNonCompliantOperationNameHash, InputMethod_NonCompliantApi::kNonCompliantOperationName },

                } } },

        { UINT64_C(1640774753589741944),
            { InstalledRelatedApps::kEntryName,
                {

                    { InstalledRelatedApps::kCalledNameHash, InstalledRelatedApps::kCalledName },

                } } },

        { UINT64_C(3999691266874322037),
            { IOS_FindInPageSearchMatches::kEntryName,
                {

                    { IOS_FindInPageSearchMatches::kHasMatchesNameHash, IOS_FindInPageSearchMatches::kHasMatchesName },

                } } },

        { UINT64_C(9401651119910784407),
            { IOS_IsDefaultBrowser::kEntryName,
                {

                    { IOS_IsDefaultBrowser::kIsDefaultBrowserNameHash, IOS_IsDefaultBrowser::kIsDefaultBrowserName },

                } } },

        { UINT64_C(11840518206463876002),
            { IOS_PageAddedToReadingList::kEntryName,
                {

                    { IOS_PageAddedToReadingList::kAddedFromMessagesNameHash, IOS_PageAddedToReadingList::kAddedFromMessagesName },

                } } },

        { UINT64_C(3910969266183986451),
            { IOS_PageReadability::kEntryName,
                {

                    { IOS_PageReadability::kDidAcceptNameHash, IOS_PageReadability::kDidAcceptName },

                    { IOS_PageReadability::kDistilibilityLongScoreNameHash, IOS_PageReadability::kDistilibilityLongScoreName },

                    { IOS_PageReadability::kDistilibilityScoreNameHash, IOS_PageReadability::kDistilibilityScoreName },

                } } },

        { UINT64_C(4631281682778806273),
            { IOS_PageZoomChanged::kEntryName,
                {

                    { IOS_PageZoomChanged::kContentSizeCategoryNameHash, IOS_PageZoomChanged::kContentSizeCategoryName },

                    { IOS_PageZoomChanged::kOverallZoomLevelNameHash, IOS_PageZoomChanged::kOverallZoomLevelName },

                    { IOS_PageZoomChanged::kUserZoomLevelNameHash, IOS_PageZoomChanged::kUserZoomLevelName },

                } } },

        { UINT64_C(10713578431670288986),
            { IOS_RendererGone::kEntryName,
                {

                    { IOS_RendererGone::kAliveRecentlyRendererCountNameHash, IOS_RendererGone::kAliveRecentlyRendererCountName },

                    { IOS_RendererGone::kAliveRendererCountNameHash, IOS_RendererGone::kAliveRendererCountName },

                    { IOS_RendererGone::kInForegroundNameHash, IOS_RendererGone::kInForegroundName },

                    { IOS_RendererGone::kSawMemoryWarningNameHash, IOS_RendererGone::kSawMemoryWarningName },

                } } },

        { UINT64_C(18173210514398479989),
            { IOS_URLMismatchInLegacyAndSlimNavigationManager::kEntryName,
                {

                    { IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchNameHash, IOS_URLMismatchInLegacyAndSlimNavigationManager::kHasMismatchName },

                } } },

        { UINT64_C(7566859152267022983),
            { JavascriptFrameworkPageLoad::kEntryName,
                {

                    { JavascriptFrameworkPageLoad::kAngularPageLoadNameHash, JavascriptFrameworkPageLoad::kAngularPageLoadName },

                    { JavascriptFrameworkPageLoad::kGatsbyPageLoadNameHash, JavascriptFrameworkPageLoad::kGatsbyPageLoadName },

                    { JavascriptFrameworkPageLoad::kNextJSPageLoadNameHash, JavascriptFrameworkPageLoad::kNextJSPageLoadName },

                    { JavascriptFrameworkPageLoad::kNuxtJSPageLoadNameHash, JavascriptFrameworkPageLoad::kNuxtJSPageLoadName },

                    { JavascriptFrameworkPageLoad::kPreactPageLoadNameHash, JavascriptFrameworkPageLoad::kPreactPageLoadName },

                    { JavascriptFrameworkPageLoad::kReactPageLoadNameHash, JavascriptFrameworkPageLoad::kReactPageLoadName },

                    { JavascriptFrameworkPageLoad::kSapperPageLoadNameHash, JavascriptFrameworkPageLoad::kSapperPageLoadName },

                    { JavascriptFrameworkPageLoad::kSveltePageLoadNameHash, JavascriptFrameworkPageLoad::kSveltePageLoadName },

                    { JavascriptFrameworkPageLoad::kVuePageLoadNameHash, JavascriptFrameworkPageLoad::kVuePageLoadName },

                    { JavascriptFrameworkPageLoad::kVuePressPageLoadNameHash, JavascriptFrameworkPageLoad::kVuePressPageLoadName },

                } } },

        { UINT64_C(2459509573580782733),
            { LoadCountsPerTopLevelDocument::kEntryName,
                {

                    { LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_HiddenNameHash, LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_HiddenName },

                    { LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_VisibleNameHash, LoadCountsPerTopLevelDocument::kNumMainFrameSameDocumentLoads_VisibleName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_HiddenNameHash,
                        LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_HiddenName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_VisibleNameHash,
                        LoadCountsPerTopLevelDocument::kNumSubFrameDifferentDocumentLoads_VisibleName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_HiddenNameHash, LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_HiddenName },

                    { LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_VisibleNameHash, LoadCountsPerTopLevelDocument::kNumSubFrameSameDocumentLoads_VisibleName },

                } } },

        { UINT64_C(17180165945688341623),
            { LoadingPredictor::kEntryName,
                {

                    { LoadingPredictor::kCorrectSubresourceOriginPreconnectsInitiatedNameHash, LoadingPredictor::kCorrectSubresourceOriginPreconnectsInitiatedName },

                    { LoadingPredictor::kCorrectSubresourcePrefetchesInitiatedNameHash, LoadingPredictor::kCorrectSubresourcePrefetchesInitiatedName },

                    { LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsNameHash, LoadingPredictor::kLocalPredictionCorrectlyPredictedOriginsName },

                    { LoadingPredictor::kLocalPredictionOriginsNameHash, LoadingPredictor::kLocalPredictionOriginsName },

                    { LoadingPredictor::kNavigationStartToFirstSubresourcePrefetchInitiatedNameHash, LoadingPredictor::kNavigationStartToFirstSubresourcePrefetchInitiatedName },

                    { LoadingPredictor::kNavigationStartToNavigationCommitNameHash, LoadingPredictor::kNavigationStartToNavigationCommitName },

                    { LoadingPredictor::kNavigationStartToOptimizationGuidePredictionArrivedNameHash, LoadingPredictor::kNavigationStartToOptimizationGuidePredictionArrivedName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedOriginsName },

                    { LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesNameHash,
                        LoadingPredictor::kOptimizationGuidePredictionCorrectlyPredictedSubresourcesName },

                    { LoadingPredictor::kOptimizationGuidePredictionDecisionNameHash, LoadingPredictor::kOptimizationGuidePredictionDecisionName },

                    { LoadingPredictor::kOptimizationGuidePredictionOriginsNameHash, LoadingPredictor::kOptimizationGuidePredictionOriginsName },

                    { LoadingPredictor::kOptimizationGuidePredictionSubresourcesNameHash, LoadingPredictor::kOptimizationGuidePredictionSubresourcesName },

                    { LoadingPredictor::kSubresourceOriginPreconnectsInitiatedNameHash, LoadingPredictor::kSubresourceOriginPreconnectsInitiatedName },

                    { LoadingPredictor::kSubresourcePrefetchesInitiatedNameHash, LoadingPredictor::kSubresourcePrefetchesInitiatedName },

                } } },

        { UINT64_C(5563841616204153427),
            { LocalNetworkRequests::kEntryName,
                {

                    { LocalNetworkRequests::kCount_FailedNameHash, LocalNetworkRequests::kCount_FailedName },

                    { LocalNetworkRequests::kCount_SuccessfulNameHash, LocalNetworkRequests::kCount_SuccessfulName },

                    { LocalNetworkRequests::kPortTypeNameHash, LocalNetworkRequests::kPortTypeName },

                    { LocalNetworkRequests::kResourceTypeNameHash, LocalNetworkRequests::kResourceTypeName },

                } } },

        { UINT64_C(9534779089019635133),
            { LoginDetection::kEntryName,
                {

                    { LoginDetection::kPage_LoginTypeNameHash, LoginDetection::kPage_LoginTypeName },

                } } },

        { UINT64_C(6455694443766360259),
            { LookalikeUrl_NavigationSuggestion::kEntryName,
                {

                    { LookalikeUrl_NavigationSuggestion::kMatchTypeNameHash, LookalikeUrl_NavigationSuggestion::kMatchTypeName },

                    { LookalikeUrl_NavigationSuggestion::kTriggeredByInitialUrlNameHash, LookalikeUrl_NavigationSuggestion::kTriggeredByInitialUrlName },

                    { LookalikeUrl_NavigationSuggestion::kUserActionNameHash, LookalikeUrl_NavigationSuggestion::kUserActionName },

                } } },

        { UINT64_C(17528121675680665933),
            { MainFrameNavigation::kEntryName,
                {

                    { MainFrameNavigation::kDidCommitNameHash, MainFrameNavigation::kDidCommitName },

                } } },

        { UINT64_C(15357501003006382777),
            { Media_Autoplay_Attempt::kEntryName,
                {

                    { Media_Autoplay_Attempt::kAudioTrackNameHash, Media_Autoplay_Attempt::kAudioTrackName },

                    { Media_Autoplay_Attempt::kHighMediaEngagementNameHash, Media_Autoplay_Attempt::kHighMediaEngagementName },

                    { Media_Autoplay_Attempt::kMutedNameHash, Media_Autoplay_Attempt::kMutedName },

                    { Media_Autoplay_Attempt::kSourceNameHash, Media_Autoplay_Attempt::kSourceName },

                    { Media_Autoplay_Attempt::kUserGestureRequiredNameHash, Media_Autoplay_Attempt::kUserGestureRequiredName },

                    { Media_Autoplay_Attempt::kUserGestureStatusNameHash, Media_Autoplay_Attempt::kUserGestureStatusName },

                    { Media_Autoplay_Attempt::kVideoTrackNameHash, Media_Autoplay_Attempt::kVideoTrackName },

                } } },

        { UINT64_C(2039378813737092278),
            { Media_Autoplay_AudioContext::kEntryName,
                {

                    { Media_Autoplay_AudioContext::kSourceNodeStartedNameHash, Media_Autoplay_AudioContext::kSourceNodeStartedName },

                    { Media_Autoplay_AudioContext::kStatusNameHash, Media_Autoplay_AudioContext::kStatusName },

                    { Media_Autoplay_AudioContext::kUnlockTypeNameHash, Media_Autoplay_AudioContext::kUnlockTypeName },

                } } },

        { UINT64_C(3015822386723746523),
            { Media_Autoplay_Muted_UnmuteAction::kEntryName,
                {

                    { Media_Autoplay_Muted_UnmuteAction::kResultNameHash, Media_Autoplay_Muted_UnmuteAction::kResultName },

                    { Media_Autoplay_Muted_UnmuteAction::kSourceNameHash, Media_Autoplay_Muted_UnmuteAction::kSourceName },

                } } },

        { UINT64_C(8416658001170131658),
            { Media_BasicPlayback::kEntryName,
                {

                    { Media_BasicPlayback::kAudioCodecNameHash, Media_BasicPlayback::kAudioCodecName },

                    { Media_BasicPlayback::kAudioCodecProfileNameHash, Media_BasicPlayback::kAudioCodecProfileName },

                    { Media_BasicPlayback::kAudioDecoderNameNameHash, Media_BasicPlayback::kAudioDecoderNameName },

                    { Media_BasicPlayback::kAudioEncryptionSchemeNameHash, Media_BasicPlayback::kAudioEncryptionSchemeName },

                    { Media_BasicPlayback::kAutoplayInitiatedNameHash, Media_BasicPlayback::kAutoplayInitiatedName },

                    { Media_BasicPlayback::kCompletedRebuffersCountNameHash, Media_BasicPlayback::kCompletedRebuffersCountName },

                    { Media_BasicPlayback::kCompletedRebuffersDurationNameHash, Media_BasicPlayback::kCompletedRebuffersDurationName },

                    { Media_BasicPlayback::kDurationNameHash, Media_BasicPlayback::kDurationName },

                    { Media_BasicPlayback::kHasAudioNameHash, Media_BasicPlayback::kHasAudioName },

                    { Media_BasicPlayback::kHasVideoNameHash, Media_BasicPlayback::kHasVideoName },

                    { Media_BasicPlayback::kIsBackgroundNameHash, Media_BasicPlayback::kIsBackgroundName },

                    { Media_BasicPlayback::kIsEMENameHash, Media_BasicPlayback::kIsEMEName },

                    { Media_BasicPlayback::kIsMSENameHash, Media_BasicPlayback::kIsMSEName },

                    { Media_BasicPlayback::kIsMutedNameHash, Media_BasicPlayback::kIsMutedName },

                    { Media_BasicPlayback::kIsTopFrameNameHash, Media_BasicPlayback::kIsTopFrameName },

                    { Media_BasicPlayback::kLastPipelineStatusNameHash, Media_BasicPlayback::kLastPipelineStatusName },

                    { Media_BasicPlayback::kMeanTimeBetweenRebuffersNameHash, Media_BasicPlayback::kMeanTimeBetweenRebuffersName },

                    { Media_BasicPlayback::kMediaStreamTypeNameHash, Media_BasicPlayback::kMediaStreamTypeName },

                    { Media_BasicPlayback::kPlayerIDNameHash, Media_BasicPlayback::kPlayerIDName },

                    { Media_BasicPlayback::kRebuffersCountNameHash, Media_BasicPlayback::kRebuffersCountName },

                    { Media_BasicPlayback::kVideoCodecNameHash, Media_BasicPlayback::kVideoCodecName },

                    { Media_BasicPlayback::kVideoCodecProfileNameHash, Media_BasicPlayback::kVideoCodecProfileName },

                    { Media_BasicPlayback::kVideoDecoderNameNameHash, Media_BasicPlayback::kVideoDecoderNameName },

                    { Media_BasicPlayback::kVideoEncryptionSchemeNameHash, Media_BasicPlayback::kVideoEncryptionSchemeName },

                    { Media_BasicPlayback::kVideoFramesDecodedNameHash, Media_BasicPlayback::kVideoFramesDecodedName },

                    { Media_BasicPlayback::kVideoFramesDroppedNameHash, Media_BasicPlayback::kVideoFramesDroppedName },

                    { Media_BasicPlayback::kVideoNaturalHeightNameHash, Media_BasicPlayback::kVideoNaturalHeightName },

                    { Media_BasicPlayback::kVideoNaturalWidthNameHash, Media_BasicPlayback::kVideoNaturalWidthName },

                    { Media_BasicPlayback::kWatchTimeNameHash, Media_BasicPlayback::kWatchTimeName },

                    { Media_BasicPlayback::kWatchTime_ACNameHash, Media_BasicPlayback::kWatchTime_ACName },

                    { Media_BasicPlayback::kWatchTime_BatteryNameHash, Media_BasicPlayback::kWatchTime_BatteryName },

                    { Media_BasicPlayback::kWatchTime_DisplayFullscreenNameHash, Media_BasicPlayback::kWatchTime_DisplayFullscreenName },

                    { Media_BasicPlayback::kWatchTime_DisplayInlineNameHash, Media_BasicPlayback::kWatchTime_DisplayInlineName },

                    { Media_BasicPlayback::kWatchTime_DisplayPictureInPictureNameHash, Media_BasicPlayback::kWatchTime_DisplayPictureInPictureName },

                    { Media_BasicPlayback::kWatchTime_NativeControlsOffNameHash, Media_BasicPlayback::kWatchTime_NativeControlsOffName },

                    { Media_BasicPlayback::kWatchTime_NativeControlsOnNameHash, Media_BasicPlayback::kWatchTime_NativeControlsOnName },

                } } },

        { UINT64_C(7968428823878627316),
            { Media_EME_ApiPromiseRejection::kEntryName,
                {

                    { Media_EME_ApiPromiseRejection::kApiNameHash, Media_EME_ApiPromiseRejection::kApiName },

                    { Media_EME_ApiPromiseRejection::kKeySystemNameHash, Media_EME_ApiPromiseRejection::kKeySystemName },

                    { Media_EME_ApiPromiseRejection::kSystemCodeNameHash, Media_EME_ApiPromiseRejection::kSystemCodeName },

                    { Media_EME_ApiPromiseRejection::kUseHardwareSecureCodecsNameHash, Media_EME_ApiPromiseRejection::kUseHardwareSecureCodecsName },

                } } },

        { UINT64_C(16664479587726188526),
            { Media_EME_CreateMediaKeys::kEntryName,
                {

                    { Media_EME_CreateMediaKeys::kIsAdFrameNameHash, Media_EME_CreateMediaKeys::kIsAdFrameName },

                    { Media_EME_CreateMediaKeys::kIsCrossOriginNameHash, Media_EME_CreateMediaKeys::kIsCrossOriginName },

                    { Media_EME_CreateMediaKeys::kIsTopFrameNameHash, Media_EME_CreateMediaKeys::kIsTopFrameName },

                    { Media_EME_CreateMediaKeys::kKeySystemNameHash, Media_EME_CreateMediaKeys::kKeySystemName },

                } } },

        { UINT64_C(6913636598201291698),
            { Media_EME_GetStatusForPolicy::kEntryName,
                {

                    { Media_EME_GetStatusForPolicy::kIsAdFrameNameHash, Media_EME_GetStatusForPolicy::kIsAdFrameName },

                    { Media_EME_GetStatusForPolicy::kKeySystemNameHash, Media_EME_GetStatusForPolicy::kKeySystemName },

                    { Media_EME_GetStatusForPolicy::kMinHdcpVersionNameHash, Media_EME_GetStatusForPolicy::kMinHdcpVersionName },

                    { Media_EME_GetStatusForPolicy::kUseHardwareSecureCodecsNameHash, Media_EME_GetStatusForPolicy::kUseHardwareSecureCodecsName },

                } } },

        { UINT64_C(14018069268047764723),
            { Media_EME_RequestMediaKeySystemAccess::kEntryName,
                {

                    { Media_EME_RequestMediaKeySystemAccess::kIsAdFrameNameHash, Media_EME_RequestMediaKeySystemAccess::kIsAdFrameName },

                    { Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginNameHash, Media_EME_RequestMediaKeySystemAccess::kIsCrossOriginName },

                    { Media_EME_RequestMediaKeySystemAccess::kIsTopFrameNameHash, Media_EME_RequestMediaKeySystemAccess::kIsTopFrameName },

                    { Media_EME_RequestMediaKeySystemAccess::kKeySystemNameHash, Media_EME_RequestMediaKeySystemAccess::kKeySystemName },

                    { Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesNameHash, Media_EME_RequestMediaKeySystemAccess::kVideoCapabilitiesName },

                    { Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessNameHash,
                        Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasEmptyRobustnessName },

                    { Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessNameHash,
                        Media_EME_RequestMediaKeySystemAccess::kVideoCapabilities_HasHwSecureAllRobustnessName },

                } } },

        { UINT64_C(886585293387977076),
            { Media_Engagement_SessionFinished::kEntryName,
                {

                    { Media_Engagement_SessionFinished::kEngagement_IsHighNameHash, Media_Engagement_SessionFinished::kEngagement_IsHighName },

                    { Media_Engagement_SessionFinished::kEngagement_ScoreNameHash, Media_Engagement_SessionFinished::kEngagement_ScoreName },

                    { Media_Engagement_SessionFinished::kPlaybacks_TotalNameHash, Media_Engagement_SessionFinished::kPlaybacks_TotalName },

                    { Media_Engagement_SessionFinished::kPlayer_Audible_DeltaNameHash, Media_Engagement_SessionFinished::kPlayer_Audible_DeltaName },

                    { Media_Engagement_SessionFinished::kPlayer_Significant_DeltaNameHash, Media_Engagement_SessionFinished::kPlayer_Significant_DeltaName },

                    { Media_Engagement_SessionFinished::kVisits_TotalNameHash, Media_Engagement_SessionFinished::kVisits_TotalName },

                } } },

        { UINT64_C(13016590436839167921),
            { Media_Engagement_ShortPlaybackIgnored::kEntryName,
                {

                    { Media_Engagement_ShortPlaybackIgnored::kLengthNameHash, Media_Engagement_ShortPlaybackIgnored::kLengthName },

                } } },

        { UINT64_C(9905764244590677619),
            { Media_Feed_Discover::kEntryName,
                {

                    { Media_Feed_Discover::kHasMediaFeedNameHash, Media_Feed_Discover::kHasMediaFeedName },

                } } },

        { UINT64_C(14701475071317937048),
            { Media_GlobalMediaControls_ActionButtonPressed::kEntryName,
                {

                    { Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionNameHash, Media_GlobalMediaControls_ActionButtonPressed::kMediaSessionActionName },

                } } },

        { UINT64_C(5140299263436558885),
            { Media_Learning_PredictionRecord::kEntryName,
                {

                    { Media_Learning_PredictionRecord::kLearningTaskNameHash, Media_Learning_PredictionRecord::kLearningTaskName },

                    { Media_Learning_PredictionRecord::kObservedValueNameHash, Media_Learning_PredictionRecord::kObservedValueName },

                    { Media_Learning_PredictionRecord::kPredictedValueNameHash, Media_Learning_PredictionRecord::kPredictedValueName },

                    { Media_Learning_PredictionRecord::kTrainingDataSizeNameHash, Media_Learning_PredictionRecord::kTrainingDataSizeName },

                    { Media_Learning_PredictionRecord::kTrainingDataTotalWeightNameHash, Media_Learning_PredictionRecord::kTrainingDataTotalWeightName },

                } } },

        { UINT64_C(9485702385711484844),
            { Media_SiteMuted::kEntryName,
                {

                    { Media_SiteMuted::kMuteReasonNameHash, Media_SiteMuted::kMuteReasonName },

                } } },

        { UINT64_C(4207699002180294249),
            { Media_VideoDecodePerfRecord::kEntryName,
                {

                    { Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothNameHash, Media_VideoDecodePerfRecord::kPerf_ApiWouldClaimIsSmoothName },

                    { Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDecodedName },

                    { Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesDroppedName },

                    { Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_PastVideoFramesPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_RecordIsPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothNameHash, Media_VideoDecodePerfRecord::kPerf_RecordIsSmoothName },

                    { Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesDecodedName },

                    { Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesDroppedName },

                    { Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientNameHash, Media_VideoDecodePerfRecord::kPerf_VideoFramesPowerEfficientName },

                    { Media_VideoDecodePerfRecord::kVideo_CodecProfileNameHash, Media_VideoDecodePerfRecord::kVideo_CodecProfileName },

                    { Media_VideoDecodePerfRecord::kVideo_EME_KeySystemNameHash, Media_VideoDecodePerfRecord::kVideo_EME_KeySystemName },

                    { Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsNameHash, Media_VideoDecodePerfRecord::kVideo_EME_UseHwSecureCodecsName },

                    { Media_VideoDecodePerfRecord::kVideo_FramesPerSecondNameHash, Media_VideoDecodePerfRecord::kVideo_FramesPerSecondName },

                    { Media_VideoDecodePerfRecord::kVideo_InTopFrameNameHash, Media_VideoDecodePerfRecord::kVideo_InTopFrameName },

                    { Media_VideoDecodePerfRecord::kVideo_NaturalHeightNameHash, Media_VideoDecodePerfRecord::kVideo_NaturalHeightName },

                    { Media_VideoDecodePerfRecord::kVideo_NaturalWidthNameHash, Media_VideoDecodePerfRecord::kVideo_NaturalWidthName },

                    { Media_VideoDecodePerfRecord::kVideo_PlayerIDNameHash, Media_VideoDecodePerfRecord::kVideo_PlayerIDName },

                } } },

        { UINT64_C(17314038096102597390),
            { Media_WebAudio_AudioContext_AudibleTime::kEntryName,
                {

                    { Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeNameHash, Media_WebAudio_AudioContext_AudibleTime::kAudibleTimeName },

                    { Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameNameHash, Media_WebAudio_AudioContext_AudibleTime::kIsMainFrameName },

                } } },

        { UINT64_C(14428460888229388079),
            { Media_WebMediaPlayerState::kEntryName,
                {

                    { Media_WebMediaPlayerState::kAudioEncryptionTypeNameHash, Media_WebMediaPlayerState::kAudioEncryptionTypeName },

                    { Media_WebMediaPlayerState::kContainerNameNameHash, Media_WebMediaPlayerState::kContainerNameName },

                    { Media_WebMediaPlayerState::kFinalPipelineStatusNameHash, Media_WebMediaPlayerState::kFinalPipelineStatusName },

                    { Media_WebMediaPlayerState::kIsEMENameHash, Media_WebMediaPlayerState::kIsEMEName },

                    { Media_WebMediaPlayerState::kIsHardwareSecureNameHash, Media_WebMediaPlayerState::kIsHardwareSecureName },

                    { Media_WebMediaPlayerState::kIsMSENameHash, Media_WebMediaPlayerState::kIsMSEName },

                    { Media_WebMediaPlayerState::kIsTopFrameNameHash, Media_WebMediaPlayerState::kIsTopFrameName },

                    { Media_WebMediaPlayerState::kKeySystemNameHash, Media_WebMediaPlayerState::kKeySystemName },

                    { Media_WebMediaPlayerState::kPlayerIDNameHash, Media_WebMediaPlayerState::kPlayerIDName },

                    { Media_WebMediaPlayerState::kRendererTypeNameHash, Media_WebMediaPlayerState::kRendererTypeName },

                    { Media_WebMediaPlayerState::kTimeToFirstFrameNameHash, Media_WebMediaPlayerState::kTimeToFirstFrameName },

                    { Media_WebMediaPlayerState::kTimeToMetadataNameHash, Media_WebMediaPlayerState::kTimeToMetadataName },

                    { Media_WebMediaPlayerState::kTimeToPlayReadyNameHash, Media_WebMediaPlayerState::kTimeToPlayReadyName },

                    { Media_WebMediaPlayerState::kURLSchemeNameHash, Media_WebMediaPlayerState::kURLSchemeName },

                    { Media_WebMediaPlayerState::kVideoEncryptionTypeNameHash, Media_WebMediaPlayerState::kVideoEncryptionTypeName },

                } } },

        { UINT64_C(3512705025017023804),
            { MediaRouter_CastWebSenderExtensionLoadUrl::kEntryName,
                {

                    { MediaRouter_CastWebSenderExtensionLoadUrl::kHasOccurredNameHash, MediaRouter_CastWebSenderExtensionLoadUrl::kHasOccurredName },

                } } },

        { UINT64_C(16497635965856919352),
            { MediaRouter_SiteInitiatedMirroringStarted::kEntryName,
                {

                    { MediaRouter_SiteInitiatedMirroringStarted::kAllowAudioCaptureNameHash, MediaRouter_SiteInitiatedMirroringStarted::kAllowAudioCaptureName },

                } } },

        { UINT64_C(2088599620296425553),
            { MediaRouter_TabMirroringStarted::kEntryName,
                {

                    { MediaRouter_TabMirroringStarted::kAudioStateNameHash, MediaRouter_TabMirroringStarted::kAudioStateName },

                } } },

        { UINT64_C(2958711939369432145),
            { Memory_Experimental::kEntryName,
                {

                    { Memory_Experimental::kArrayBufferNameHash, Memory_Experimental::kArrayBufferName },

                    { Memory_Experimental::kBlinkGCNameHash, Memory_Experimental::kBlinkGCName },

                    { Memory_Experimental::kBlinkGC_AllocatedObjectsNameHash, Memory_Experimental::kBlinkGC_AllocatedObjectsName },

                    { Memory_Experimental::kCanvasResourceProvider_SkSurfaceNameHash, Memory_Experimental::kCanvasResourceProvider_SkSurfaceName },

                    { Memory_Experimental::kCommandBufferNameHash, Memory_Experimental::kCommandBufferName },

                    { Memory_Experimental::kDiscardableNameHash, Memory_Experimental::kDiscardableName },

                    { Memory_Experimental::kDownloadServiceNameHash, Memory_Experimental::kDownloadServiceName },

                    { Memory_Experimental::kExtensions_ValueStoreNameHash, Memory_Experimental::kExtensions_ValueStoreName },

                    { Memory_Experimental::kFontCachesNameHash, Memory_Experimental::kFontCachesName },

                    { Memory_Experimental::kGpuMemoryNameHash, Memory_Experimental::kGpuMemoryName },

                    { Memory_Experimental::kHistoryNameHash, Memory_Experimental::kHistoryName },

                    { Memory_Experimental::kIsVisibleNameHash, Memory_Experimental::kIsVisibleName },

                    { Memory_Experimental::kJavaHeapNameHash, Memory_Experimental::kJavaHeapName },

                    { Memory_Experimental::kLevelDatabaseNameHash, Memory_Experimental::kLevelDatabaseName },

                    { Memory_Experimental::kMallocNameHash, Memory_Experimental::kMallocName },

                    { Memory_Experimental::kMalloc_AllocatedObjectsNameHash, Memory_Experimental::kMalloc_AllocatedObjectsName },

                    { Memory_Experimental::kNumberOfAdSubframesNameHash, Memory_Experimental::kNumberOfAdSubframesName },

                    { Memory_Experimental::kNumberOfArrayBufferContentsNameHash, Memory_Experimental::kNumberOfArrayBufferContentsName },

                    { Memory_Experimental::kNumberOfDetachedScriptStatesNameHash, Memory_Experimental::kNumberOfDetachedScriptStatesName },

                    { Memory_Experimental::kNumberOfDocumentsNameHash, Memory_Experimental::kNumberOfDocumentsName },

                    { Memory_Experimental::kNumberOfExtensionsNameHash, Memory_Experimental::kNumberOfExtensionsName },

                    { Memory_Experimental::kNumberOfFramesNameHash, Memory_Experimental::kNumberOfFramesName },

                    { Memory_Experimental::kNumberOfLayoutObjectsNameHash, Memory_Experimental::kNumberOfLayoutObjectsName },

                    { Memory_Experimental::kNumberOfMojoHandlesNameHash, Memory_Experimental::kNumberOfMojoHandlesName },

                    { Memory_Experimental::kNumberOfNodesNameHash, Memory_Experimental::kNumberOfNodesName },

                    { Memory_Experimental::kNumberOfWebMediaPlayersNameHash, Memory_Experimental::kNumberOfWebMediaPlayersName },

                    { Memory_Experimental::kOmniboxSuggestionsNameHash, Memory_Experimental::kOmniboxSuggestionsName },

                    { Memory_Experimental::kPartitionAllocNameHash, Memory_Experimental::kPartitionAllocName },

                    { Memory_Experimental::kPartitionAlloc_AllocatedObjectsNameHash, Memory_Experimental::kPartitionAlloc_AllocatedObjectsName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferNameHash, Memory_Experimental::kPartitionAlloc_Partitions_ArrayBufferName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_BufferNameHash, Memory_Experimental::kPartitionAlloc_Partitions_BufferName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_FastMallocNameHash, Memory_Experimental::kPartitionAlloc_Partitions_FastMallocName },

                    { Memory_Experimental::kPartitionAlloc_Partitions_LayoutNameHash, Memory_Experimental::kPartitionAlloc_Partitions_LayoutName },

                    { Memory_Experimental::kPrivateMemoryFootprintNameHash, Memory_Experimental::kPrivateMemoryFootprintName },

                    { Memory_Experimental::kPrivateSwapFootprintNameHash, Memory_Experimental::kPrivateSwapFootprintName },

                    { Memory_Experimental::kProcessTypeNameHash, Memory_Experimental::kProcessTypeName },

                    { Memory_Experimental::kResidentNameHash, Memory_Experimental::kResidentName },

                    { Memory_Experimental::kSharedMemoryFootprintNameHash, Memory_Experimental::kSharedMemoryFootprintName },

                    { Memory_Experimental::kSiteStorageNameHash, Memory_Experimental::kSiteStorageName },

                    { Memory_Experimental::kSiteStorage_BlobStorageNameHash, Memory_Experimental::kSiteStorage_BlobStorageName },

                    { Memory_Experimental::kSiteStorage_IndexDBNameHash, Memory_Experimental::kSiteStorage_IndexDBName },

                    { Memory_Experimental::kSiteStorage_LocalStorageNameHash, Memory_Experimental::kSiteStorage_LocalStorageName },

                    { Memory_Experimental::kSiteStorage_SessionStorageNameHash, Memory_Experimental::kSiteStorage_SessionStorageName },

                    { Memory_Experimental::kSkiaNameHash, Memory_Experimental::kSkiaName },

                    { Memory_Experimental::kSkia_SkGlyphCacheNameHash, Memory_Experimental::kSkia_SkGlyphCacheName },

                    { Memory_Experimental::kSkia_SkResourceCacheNameHash, Memory_Experimental::kSkia_SkResourceCacheName },

                    { Memory_Experimental::kSqliteNameHash, Memory_Experimental::kSqliteName },

                    { Memory_Experimental::kSyncNameHash, Memory_Experimental::kSyncName },

                    { Memory_Experimental::kTabRestoreNameHash, Memory_Experimental::kTabRestoreName },

                    { Memory_Experimental::kTimeSinceLastNavigationNameHash, Memory_Experimental::kTimeSinceLastNavigationName },

                    { Memory_Experimental::kTimeSinceLastVisibilityChangeNameHash, Memory_Experimental::kTimeSinceLastVisibilityChangeName },

                    { Memory_Experimental::kTotal2_PrivateMemoryFootprintNameHash, Memory_Experimental::kTotal2_PrivateMemoryFootprintName },

                    { Memory_Experimental::kTotal2_SharedMemoryFootprintNameHash, Memory_Experimental::kTotal2_SharedMemoryFootprintName },

                    { Memory_Experimental::kUINameHash, Memory_Experimental::kUIName },

                    { Memory_Experimental::kUptimeNameHash, Memory_Experimental::kUptimeName },

                    { Memory_Experimental::kV8NameHash, Memory_Experimental::kV8Name },

                    { Memory_Experimental::kV8_AllocatedObjectsNameHash, Memory_Experimental::kV8_AllocatedObjectsName },

                    { Memory_Experimental::kV8_MainNameHash, Memory_Experimental::kV8_MainName },

                    { Memory_Experimental::kV8_Main_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_GlobalHandlesNameHash, Memory_Experimental::kV8_Main_GlobalHandlesName },

                    { Memory_Experimental::kV8_Main_GlobalHandles_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_GlobalHandles_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_HeapNameHash, Memory_Experimental::kV8_Main_HeapName },

                    { Memory_Experimental::kV8_Main_Heap_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_CodeLargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_CodeSpaceNameHash, Memory_Experimental::kV8_Main_Heap_CodeSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_CodeSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_LargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_LargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_MapSpaceNameHash, Memory_Experimental::kV8_Main_Heap_MapSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_MapSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceNameHash, Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsNameHash,
                        Memory_Experimental::kV8_Main_Heap_NewLargeObjectSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_NewSpaceNameHash, Memory_Experimental::kV8_Main_Heap_NewSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_NewSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_OldSpaceNameHash, Memory_Experimental::kV8_Main_Heap_OldSpaceName },

                    { Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_OldSpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceNameHash, Memory_Experimental::kV8_Main_Heap_ReadOnlySpaceName },

                    { Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsNameHash, Memory_Experimental::kV8_Main_Heap_ReadOnlySpace_AllocatedObjectsName },

                    { Memory_Experimental::kV8_Main_MallocNameHash, Memory_Experimental::kV8_Main_MallocName },

                    { Memory_Experimental::kV8_WorkersNameHash, Memory_Experimental::kV8_WorkersName },

                    { Memory_Experimental::kV8_Workers_AllocatedObjectsNameHash, Memory_Experimental::kV8_Workers_AllocatedObjectsName },

                    { Memory_Experimental::kWebCacheNameHash, Memory_Experimental::kWebCacheName },

                    { Memory_Experimental::kWebCache_CSSStylesheetResourcesNameHash, Memory_Experimental::kWebCache_CSSStylesheetResourcesName },

                    { Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsNameHash, Memory_Experimental::kWebCache_EncodedSizeDuplicatedInDataUrlsName },

                    { Memory_Experimental::kWebCache_FontResourcesNameHash, Memory_Experimental::kWebCache_FontResourcesName },

                    { Memory_Experimental::kWebCache_ImageResourcesNameHash, Memory_Experimental::kWebCache_ImageResourcesName },

                    { Memory_Experimental::kWebCache_OtherResourcesNameHash, Memory_Experimental::kWebCache_OtherResourcesName },

                    { Memory_Experimental::kWebCache_ScriptResourcesNameHash, Memory_Experimental::kWebCache_ScriptResourcesName },

                    { Memory_Experimental::kWebCache_V8CodeCacheNameHash, Memory_Experimental::kWebCache_V8CodeCacheName },

                    { Memory_Experimental::kWebCache_XSLStylesheetResourcesNameHash, Memory_Experimental::kWebCache_XSLStylesheetResourcesName },

                    { Memory_Experimental::kWebMediaPlayer_AudioNameHash, Memory_Experimental::kWebMediaPlayer_AudioName },

                    { Memory_Experimental::kWebMediaPlayer_DataSourceNameHash, Memory_Experimental::kWebMediaPlayer_DataSourceName },

                    { Memory_Experimental::kWebMediaPlayer_DemuxerNameHash, Memory_Experimental::kWebMediaPlayer_DemuxerName },

                    { Memory_Experimental::kWebMediaPlayer_VideoNameHash, Memory_Experimental::kWebMediaPlayer_VideoName },

                } } },

        { UINT64_C(12430751894188593646),
            { Memory_TabFootprint::kEntryName,
                {

                    { Memory_TabFootprint::kMainFrameProcessPMFNameHash, Memory_TabFootprint::kMainFrameProcessPMFName },

                    { Memory_TabFootprint::kSubFrameProcessPMF_ExcludedNameHash, Memory_TabFootprint::kSubFrameProcessPMF_ExcludedName },

                    { Memory_TabFootprint::kSubFrameProcessPMF_IncludedNameHash, Memory_TabFootprint::kSubFrameProcessPMF_IncludedName },

                    { Memory_TabFootprint::kSubFrameProcessPMF_TotalNameHash, Memory_TabFootprint::kSubFrameProcessPMF_TotalName },

                    { Memory_TabFootprint::kTabPMFNameHash, Memory_TabFootprint::kTabPMFName },

                } } },

        { UINT64_C(9946364510678884885),
            { MixedContentAutoupgrade_ResourceRequest::kEntryName,
                {

                    { MixedContentAutoupgrade_ResourceRequest::kCodeNameHash, MixedContentAutoupgrade_ResourceRequest::kCodeName },

                    { MixedContentAutoupgrade_ResourceRequest::kStatusNameHash, MixedContentAutoupgrade_ResourceRequest::kStatusName },

                } } },

        { UINT64_C(2031262019788538998),
            { MobileFriendliness::kEntryName,
                {

                    { MobileFriendliness::kAllowUserZoomNameHash, MobileFriendliness::kAllowUserZoomName },

                    { MobileFriendliness::kBadTapTargetsRatioNameHash, MobileFriendliness::kBadTapTargetsRatioName },

                    { MobileFriendliness::kSmallTextRatioNameHash, MobileFriendliness::kSmallTextRatioName },

                    { MobileFriendliness::kTextContentOutsideViewportPercentageNameHash, MobileFriendliness::kTextContentOutsideViewportPercentageName },

                    { MobileFriendliness::kViewportDeviceWidthNameHash, MobileFriendliness::kViewportDeviceWidthName },

                    { MobileFriendliness::kViewportHardcodedWidthNameHash, MobileFriendliness::kViewportHardcodedWidthName },

                    { MobileFriendliness::kViewportInitialScaleX10NameHash, MobileFriendliness::kViewportInitialScaleX10Name },

                } } },

        { UINT64_C(10323656781780570903),
            { MobileMenu_DirectShare::kEntryName,
                {

                    { MobileMenu_DirectShare::kHasOccurredNameHash, MobileMenu_DirectShare::kHasOccurredName },

                } } },

        { UINT64_C(317096594738729330),
            { MobileMenu_FindInPage::kEntryName,
                {

                    { MobileMenu_FindInPage::kHasOccurredNameHash, MobileMenu_FindInPage::kHasOccurredName },

                } } },

        { UINT64_C(16632756802456473210),
            { MobileMenu_Share::kEntryName,
                {

                    { MobileMenu_Share::kHasOccurredNameHash, MobileMenu_Share::kHasOccurredName },

                } } },

        { UINT64_C(12118541746267936631),
            { Navigation_IDNA2008Transition::kEntryName,
                {

                    { Navigation_IDNA2008Transition::kCharacterNameHash, Navigation_IDNA2008Transition::kCharacterName },

                } } },

        { UINT64_C(8202605063367714792),
            { Navigation_ReceivedResponse::kEntryName,
                {

                    { Navigation_ReceivedResponse::kHasAcceptCHFrameNameHash, Navigation_ReceivedResponse::kHasAcceptCHFrameName },

                    { Navigation_ReceivedResponse::kNavigationFirstResponseLatencyNameHash, Navigation_ReceivedResponse::kNavigationFirstResponseLatencyName },

                } } },

        { UINT64_C(4064735116116070675),
            { NavigationPredictorAnchorElementMetrics::kEntryName,
                {

                    { NavigationPredictorAnchorElementMetrics::kAnchorIndexNameHash, NavigationPredictorAnchorElementMetrics::kAnchorIndexName },

                    { NavigationPredictorAnchorElementMetrics::kBucketedPathHashNameHash, NavigationPredictorAnchorElementMetrics::kBucketedPathHashName },

                    { NavigationPredictorAnchorElementMetrics::kContainsImageNameHash, NavigationPredictorAnchorElementMetrics::kContainsImageName },

                    { NavigationPredictorAnchorElementMetrics::kFontSizeNameHash, NavigationPredictorAnchorElementMetrics::kFontSizeName },

                    { NavigationPredictorAnchorElementMetrics::kHasTextSiblingNameHash, NavigationPredictorAnchorElementMetrics::kHasTextSiblingName },

                    { NavigationPredictorAnchorElementMetrics::kIsBoldNameHash, NavigationPredictorAnchorElementMetrics::kIsBoldName },

                    { NavigationPredictorAnchorElementMetrics::kIsInIframeNameHash, NavigationPredictorAnchorElementMetrics::kIsInIframeName },

                    { NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneNameHash, NavigationPredictorAnchorElementMetrics::kIsURLIncrementedByOneName },

                    { NavigationPredictorAnchorElementMetrics::kNavigationStartToLinkLoggedMsNameHash,
                        NavigationPredictorAnchorElementMetrics::kNavigationStartToLinkLoggedMsName },

                    { NavigationPredictorAnchorElementMetrics::kPathDepthNameHash, NavigationPredictorAnchorElementMetrics::kPathDepthName },

                    { NavigationPredictorAnchorElementMetrics::kPathLengthNameHash, NavigationPredictorAnchorElementMetrics::kPathLengthName },

                    { NavigationPredictorAnchorElementMetrics::kPercentClickableAreaNameHash, NavigationPredictorAnchorElementMetrics::kPercentClickableAreaName },

                    { NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceNameHash, NavigationPredictorAnchorElementMetrics::kPercentVerticalDistanceName },

                    { NavigationPredictorAnchorElementMetrics::kSameOriginNameHash, NavigationPredictorAnchorElementMetrics::kSameOriginName },

                } } },

        { UINT64_C(10775915644707889889),
            { NavigationPredictorPageLinkClick::kEntryName,
                {

                    { NavigationPredictorPageLinkClick::kAnchorElementIndexNameHash, NavigationPredictorPageLinkClick::kAnchorElementIndexName },

                    { NavigationPredictorPageLinkClick::kHrefUnchangedNameHash, NavigationPredictorPageLinkClick::kHrefUnchangedName },

                } } },

        { UINT64_C(367468233168747720),
            { NavigationPredictorPageLinkMetrics::kEntryName,
                {

                    { NavigationPredictorPageLinkMetrics::kMedianLinkLocationNameHash, NavigationPredictorPageLinkMetrics::kMedianLinkLocationName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_ContainsImageName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_InIframeName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_SameHostName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_TotalName },

                    { NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedNameHash, NavigationPredictorPageLinkMetrics::kNumberOfAnchors_URLIncrementedName },

                    { NavigationPredictorPageLinkMetrics::kTotalClickableSpaceNameHash, NavigationPredictorPageLinkMetrics::kTotalClickableSpaceName },

                    { NavigationPredictorPageLinkMetrics::kViewport_HeightNameHash, NavigationPredictorPageLinkMetrics::kViewport_HeightName },

                    { NavigationPredictorPageLinkMetrics::kViewport_WidthNameHash, NavigationPredictorPageLinkMetrics::kViewport_WidthName },

                } } },

        { UINT64_C(11162965141345650317),
            { NavigationThrottleDeferredTime::kEntryName,
                {

                    { NavigationThrottleDeferredTime::kDurationOfNavigationDeferralMsNameHash, NavigationThrottleDeferredTime::kDurationOfNavigationDeferralMsName },

                    { NavigationThrottleDeferredTime::kNavigationThrottleEventTypeNameHash, NavigationThrottleDeferredTime::kNavigationThrottleEventTypeName },

                    { NavigationThrottleDeferredTime::kNavigationThrottleNameHashNameHash, NavigationThrottleDeferredTime::kNavigationThrottleNameHashName },

                } } },

        { UINT64_C(10253825785463205218),
            { NavigationTiming::kEntryName,
                {

                    { NavigationTiming::kFinalLoaderCallbackNameHash, NavigationTiming::kFinalLoaderCallbackName },

                    { NavigationTiming::kFinalRequestStartNameHash, NavigationTiming::kFinalRequestStartName },

                    { NavigationTiming::kFinalResponseStartNameHash, NavigationTiming::kFinalResponseStartName },

                    { NavigationTiming::kFirstLoaderCallbackNameHash, NavigationTiming::kFirstLoaderCallbackName },

                    { NavigationTiming::kFirstRequestStartNameHash, NavigationTiming::kFirstRequestStartName },

                    { NavigationTiming::kFirstResponseStartNameHash, NavigationTiming::kFirstResponseStartName },

                    { NavigationTiming::kNavigationCommitSentNameHash, NavigationTiming::kNavigationCommitSentName },

                } } },

        { UINT64_C(83722319975286136),
            { Net_LegacyTLSVersion::kEntryName,
                {

                    { Net_LegacyTLSVersion::kIsAdResourceNameHash, Net_LegacyTLSVersion::kIsAdResourceName },

                    { Net_LegacyTLSVersion::kIsMainFrameNameHash, Net_LegacyTLSVersion::kIsMainFrameName },

                    { Net_LegacyTLSVersion::kIsSubresourceNameHash, Net_LegacyTLSVersion::kIsSubresourceName },

                } } },

        { UINT64_C(3632945013237863528),
            { Network_CacheTransparency::kEntryName,
                {

                    { Network_CacheTransparency::kFoundPervasivePayloadNameHash, Network_CacheTransparency::kFoundPervasivePayloadName },

                    { Network_CacheTransparency::kTotalBytesFetchedNameHash, Network_CacheTransparency::kTotalBytesFetchedName },

                } } },

        { UINT64_C(5007192410804132260),
            { NoStatePrefetch::kEntryName,
                {

                    { NoStatePrefetch::kPrefetchedRecently_FinalStatusNameHash, NoStatePrefetch::kPrefetchedRecently_FinalStatusName },

                    { NoStatePrefetch::kPrefetchedRecently_OriginNameHash, NoStatePrefetch::kPrefetchedRecently_OriginName },

                    { NoStatePrefetch::kPrefetchedRecently_PrefetchAgeNameHash, NoStatePrefetch::kPrefetchedRecently_PrefetchAgeName },

                } } },

        { UINT64_C(10867195639280438101),
            { Notification::kEntryName,
                {

                    { Notification::kClosedReasonNameHash, Notification::kClosedReasonName },

                    { Notification::kDidReplaceAnotherNotificationNameHash, Notification::kDidReplaceAnotherNotificationName },

                    { Notification::kDidUserOpenSettingsNameHash, Notification::kDidUserOpenSettingsName },

                    { Notification::kHasBadgeNameHash, Notification::kHasBadgeName },

                    { Notification::kHasIconNameHash, Notification::kHasIconName },

                    { Notification::kHasImageNameHash, Notification::kHasImageName },

                    { Notification::kHasRenotifyNameHash, Notification::kHasRenotifyName },

                    { Notification::kHasTagNameHash, Notification::kHasTagName },

                    { Notification::kIsSilentNameHash, Notification::kIsSilentName },

                    { Notification::kNumActionButtonClicksNameHash, Notification::kNumActionButtonClicksName },

                    { Notification::kNumActionsNameHash, Notification::kNumActionsName },

                    { Notification::kNumClicksNameHash, Notification::kNumClicksName },

                    { Notification::kRequireInteractionNameHash, Notification::kRequireInteractionName },

                    { Notification::kTimeUntilCloseNameHash, Notification::kTimeUntilCloseName },

                    { Notification::kTimeUntilFirstClickNameHash, Notification::kTimeUntilFirstClickName },

                    { Notification::kTimeUntilLastClickNameHash, Notification::kTimeUntilLastClickName },

                } } },

        { UINT64_C(4133441977341793352),
            { Omnibox_EditUrlSuggestion_Share::kEntryName,
                {

                    { Omnibox_EditUrlSuggestion_Share::kHasOccurredNameHash, Omnibox_EditUrlSuggestion_Share::kHasOccurredName },

                } } },

        { UINT64_C(2638435285752584045),
            { OmniboxSecurityIndicator_FormSubmission::kEntryName,
                {

                    { OmniboxSecurityIndicator_FormSubmission::kSubmittedNameHash, OmniboxSecurityIndicator_FormSubmission::kSubmittedName },

                } } },

        { UINT64_C(2087579403365801585),
            { OptimizationGuide::kEntryName,
                {

                    { OptimizationGuide::kNavigationHintsFetchAttemptStatusNameHash, OptimizationGuide::kNavigationHintsFetchAttemptStatusName },

                    { OptimizationGuide::kNavigationHintsFetchRequestLatencyNameHash, OptimizationGuide::kNavigationHintsFetchRequestLatencyName },

                    { OptimizationGuide::kRegisteredOptimizationTargetsNameHash, OptimizationGuide::kRegisteredOptimizationTargetsName },

                    { OptimizationGuide::kRegisteredOptimizationTypesNameHash, OptimizationGuide::kRegisteredOptimizationTypesName },

                } } },

        { UINT64_C(12853622770478513093),
            { PageDomainInfo::kEntryName,
                {

                    { PageDomainInfo::kDomainTypeNameHash, PageDomainInfo::kDomainTypeName },

                } } },

        { UINT64_C(14423022965050986312),
            { PageForegroundSession::kEntryName,
                {

                    { PageForegroundSession::kForegroundDurationNameHash, PageForegroundSession::kForegroundDurationName },

                    { PageForegroundSession::kForegroundNumInputEventsNameHash, PageForegroundSession::kForegroundNumInputEventsName },

                    { PageForegroundSession::kForegroundTotalAdjustedInputDelayNameHash, PageForegroundSession::kForegroundTotalAdjustedInputDelayName },

                    { PageForegroundSession::kForegroundTotalInputDelayNameHash, PageForegroundSession::kForegroundTotalInputDelayName },

                } } },

        { UINT64_C(10171644723325805171),
            { PageInfoBubble::kEntryName,
                {

                    { PageInfoBubble::kActionTakenNameHash, PageInfoBubble::kActionTakenName },

                } } },

        { UINT64_C(12426032810838168341),
            { PageLoad::kEntryName,
                {

                    { PageLoad::kCpuTimeNameHash, PageLoad::kCpuTimeName },

                    { PageLoad::kDayOfWeekNameHash, PageLoad::kDayOfWeekName },

                    { PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredNameHash, PageLoad::kDocumentTiming_NavigationToDOMContentLoadedEventFiredName },

                    { PageLoad::kDocumentTiming_NavigationToLoadEventFiredNameHash, PageLoad::kDocumentTiming_NavigationToLoadEventFiredName },

                    { PageLoad::kDurationSinceLastVisitSecondsNameHash, PageLoad::kDurationSinceLastVisitSecondsName },

                    { PageLoad::kExperimental_InputToNavigationStartNameHash, PageLoad::kExperimental_InputToNavigationStartName },

                    { PageLoad::kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenNameHash,
                        PageLoad::kExperimental_LayoutInstability_CumulativeShiftScoreAtFirstOnHiddenName },

                    { PageLoad::kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PageLoad::kExperimental_LayoutInstability_MaxCumulativeShiftScoreAtFirstOnHidden_SessionWindow_Gap1000ms_Max5000msName },

                    { PageLoad::kExperimental_Navigation_UserInitiatedNameHash, PageLoad::kExperimental_Navigation_UserInitiatedName },

                    { PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintNameHash, PageLoad::kExperimental_PaintTiming_NavigationToFirstMeaningfulPaintName },

                    { PageLoad::kHourOfDayNameHash, PageLoad::kHourOfDayName },

                    { PageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_FirstInputDelay4NameHash, PageLoad::kInteractiveTiming_FirstInputDelay4Name },

                    { PageLoad::kInteractiveTiming_FirstInputProcessingTimesNameHash, PageLoad::kInteractiveTiming_FirstInputProcessingTimesName },

                    { PageLoad::kInteractiveTiming_FirstInputTimestamp4NameHash, PageLoad::kInteractiveTiming_FirstInputTimestamp4Name },

                    { PageLoad::kInteractiveTiming_FirstScrollDelayNameHash, PageLoad::kInteractiveTiming_FirstScrollDelayName },

                    { PageLoad::kInteractiveTiming_FirstScrollTimestampNameHash, PageLoad::kInteractiveTiming_FirstScrollTimestampName },

                    { PageLoad::kInteractiveTiming_LongestInputDelay4NameHash, PageLoad::kInteractiveTiming_LongestInputDelay4Name },

                    { PageLoad::kInteractiveTiming_LongestInputTimestamp4NameHash, PageLoad::kInteractiveTiming_LongestInputTimestamp4Name },

                    { PageLoad::kInteractiveTiming_NumInputEventsNameHash, PageLoad::kInteractiveTiming_NumInputEventsName },

                    { PageLoad::kInteractiveTiming_NumInteractionsNameHash, PageLoad::kInteractiveTiming_NumInteractionsName },

                    { PageLoad::kInteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_SlowUserInteractionLatencyOverBudget_HighPercentile2_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_SumOfUserInteractionLatencyOverBudget_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_TotalAdjustedInputDelayNameHash, PageLoad::kInteractiveTiming_TotalAdjustedInputDelayName },

                    { PageLoad::kInteractiveTiming_TotalInputDelayNameHash, PageLoad::kInteractiveTiming_TotalInputDelayName },

                    { PageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_UserInteractionLatencyAtFirstOnHidden_HighPercentile2_MaxEventDurationName },

                    { PageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash,
                        PageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName },

                    { PageLoad::kIsCrossProcessNavigationNameHash, PageLoad::kIsCrossProcessNavigationName },

                    { PageLoad::kIsExistingBookmarkNameHash, PageLoad::kIsExistingBookmarkName },

                    { PageLoad::kIsExistingPartOfTabGroupNameHash, PageLoad::kIsExistingPartOfTabGroupName },

                    { PageLoad::kIsNewBookmarkNameHash, PageLoad::kIsNewBookmarkName },

                    { PageLoad::kIsNTPCustomLinkNameHash, PageLoad::kIsNTPCustomLinkName },

                    { PageLoad::kIsPlacedInTabGroupNameHash, PageLoad::kIsPlacedInTabGroupName },

                    { PageLoad::kIsScopedSearchLikeNavigationNameHash, PageLoad::kIsScopedSearchLikeNavigationName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScoreNameHash, PageLoad::kLayoutInstability_CumulativeShiftScoreName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollNameHash, PageLoad::kLayoutInstability_CumulativeShiftScore_BeforeInputOrScrollName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameNameHash, PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrameName },

                    { PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollNameHash,
                        PageLoad::kLayoutInstability_CumulativeShiftScore_MainFrame_BeforeInputOrScrollName },

                    { PageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { PageLoad::kMainDocumentSequenceNumberNameHash, PageLoad::kMainDocumentSequenceNumberName },

                    { PageLoad::kMainFrameResource_ConnectDelayNameHash, PageLoad::kMainFrameResource_ConnectDelayName },

                    { PageLoad::kMainFrameResource_DNSDelayNameHash, PageLoad::kMainFrameResource_DNSDelayName },

                    { PageLoad::kMainFrameResource_HttpProtocolSchemeNameHash, PageLoad::kMainFrameResource_HttpProtocolSchemeName },

                    { PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartNameHash, PageLoad::kMainFrameResource_NavigationStartToReceiveHeadersStartName },

                    { PageLoad::kMainFrameResource_NavigationStartToRequestStartNameHash, PageLoad::kMainFrameResource_NavigationStartToRequestStartName },

                    { PageLoad::kMainFrameResource_RedirectCountNameHash, PageLoad::kMainFrameResource_RedirectCountName },

                    { PageLoad::kMainFrameResource_RequestHadCookiesNameHash, PageLoad::kMainFrameResource_RequestHadCookiesName },

                    { PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndNameHash, PageLoad::kMainFrameResource_RequestStartToReceiveHeadersEndName },

                    { PageLoad::kMainFrameResource_RequestStartToSendStartNameHash, PageLoad::kMainFrameResource_RequestStartToSendStartName },

                    { PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndNameHash, PageLoad::kMainFrameResource_SendStartToReceiveHeadersEndName },

                    { PageLoad::kMainFrameResource_SocketReusedNameHash, PageLoad::kMainFrameResource_SocketReusedName },

                    { PageLoad::kNavigation_PageEndReason3NameHash, PageLoad::kNavigation_PageEndReason3Name },

                    { PageLoad::kNavigation_PageTransitionNameHash, PageLoad::kNavigation_PageTransitionName },

                    { PageLoad::kNavigationEntryOffsetNameHash, PageLoad::kNavigationEntryOffsetName },

                    { PageLoad::kNet_CacheBytes2NameHash, PageLoad::kNet_CacheBytes2Name },

                    { PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartNameHash, PageLoad::kNet_DownstreamKbpsEstimate_OnNavigationStartName },

                    { PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartNameHash, PageLoad::kNet_EffectiveConnectionType2_OnNavigationStartName },

                    { PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadNameHash, PageLoad::kNet_ErrorCode_OnFailedProvisionalLoadName },

                    { PageLoad::kNet_HttpResponseCodeNameHash, PageLoad::kNet_HttpResponseCodeName },

                    { PageLoad::kNet_HttpRttEstimate_OnNavigationStartNameHash, PageLoad::kNet_HttpRttEstimate_OnNavigationStartName },

                    { PageLoad::kNet_ImageBytes2NameHash, PageLoad::kNet_ImageBytes2Name },

                    { PageLoad::kNet_ImageSubframeBytes2NameHash, PageLoad::kNet_ImageSubframeBytes2Name },

                    { PageLoad::kNet_JavaScriptBytes2NameHash, PageLoad::kNet_JavaScriptBytes2Name },

                    { PageLoad::kNet_JavaScriptMaxBytes2NameHash, PageLoad::kNet_JavaScriptMaxBytes2Name },

                    { PageLoad::kNet_MediaBytes2NameHash, PageLoad::kNet_MediaBytes2Name },

                    { PageLoad::kNet_NetworkBytes2NameHash, PageLoad::kNet_NetworkBytes2Name },

                    { PageLoad::kNet_TransportRttEstimate_OnNavigationStartNameHash, PageLoad::kNet_TransportRttEstimate_OnNavigationStartName },

                    { PageLoad::kOmniboxUrlCopiedNameHash, PageLoad::kOmniboxUrlCopiedName },

                    { PageLoad::kPageTiming_ForegroundDurationNameHash, PageLoad::kPageTiming_ForegroundDurationName },

                    { PageLoad::kPageTiming_NavigationToFailedProvisionalLoadNameHash, PageLoad::kPageTiming_NavigationToFailedProvisionalLoadName },

                    { PageLoad::kPageTiming_TotalForegroundDurationNameHash, PageLoad::kPageTiming_TotalForegroundDurationName },

                    { PageLoad::kPageTiming_UserTimingMarkFullyLoadedNameHash, PageLoad::kPageTiming_UserTimingMarkFullyLoadedName },

                    { PageLoad::kPageTiming_UserTimingMarkFullyVisibleNameHash, PageLoad::kPageTiming_UserTimingMarkFullyVisibleName },

                    { PageLoad::kPageTiming_UserTimingMarkInteractiveNameHash, PageLoad::kPageTiming_UserTimingMarkInteractiveName },

                    { PageLoad::kPageVisitFinalStatusNameHash, PageLoad::kPageVisitFinalStatusName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintBPPNameHash, PageLoad::kPaintTiming_LargestContentfulPaintBPPName },

                    { PageLoad::kPaintTiming_LargestContentfulPaintTypeNameHash, PageLoad::kPaintTiming_LargestContentfulPaintTypeName },

                    { PageLoad::kPaintTiming_NavigationToFirstContentfulPaintNameHash, PageLoad::kPaintTiming_NavigationToFirstContentfulPaintName },

                    { PageLoad::kPaintTiming_NavigationToFirstPaintNameHash, PageLoad::kPaintTiming_NavigationToFirstPaintName },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2NameHash, PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2Name },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameNameHash,
                        PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_CrossSiteSubFrameName },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameNameHash, PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2_MainFrameName },

                    { PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenNameHash,
                        PageLoad::kPaintTiming_NavigationToLargestContentfulPaint2AtFirstOnHiddenName },

                    { PageLoad::kParseTiming_NavigationToParseStartNameHash, PageLoad::kParseTiming_NavigationToParseStartName },

                    { PageLoad::kRefreshRateThrottledNameHash, PageLoad::kRefreshRateThrottledName },

                    { PageLoad::kSiteEngagementScoreNameHash, PageLoad::kSiteEngagementScoreName },

                    { PageLoad::kSiteInstanceRenderProcessAssignmentNameHash, PageLoad::kSiteInstanceRenderProcessAssignmentName },

                    { PageLoad::kSoftNavigationCountNameHash, PageLoad::kSoftNavigationCountName },

                    { PageLoad::kThirdPartyCookieBlockingEnabledForSiteNameHash, PageLoad::kThirdPartyCookieBlockingEnabledForSiteName },

                    { PageLoad::kWasCachedNameHash, PageLoad::kWasCachedName },

                    { PageLoad::kWasDiscardedNameHash, PageLoad::kWasDiscardedName },

                } } },

        { UINT64_C(8384138607730558665),
            { PageLoad_FromGoogleSearch::kEntryName,
                {

                    { PageLoad_FromGoogleSearch::kGoogleSearchModeNameHash, PageLoad_FromGoogleSearch::kGoogleSearchModeName },

                } } },

        { UINT64_C(5441732143890651748),
            { PageLoad_Internal::kEntryName,
                {

                    { PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeNameHash, PageLoad_Internal::kPaintTiming_LargestContentfulPaint_ContentTypeName },

                    { PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateNameHash,
                        PageLoad_Internal::kPaintTiming_LargestContentfulPaint_TerminationStateName },

                } } },

        { UINT64_C(18067304287773255026),
            { PageLoad_ServiceWorkerControlled::kEntryName,
                {

                } } },

        { UINT64_C(14566014450078110818),
            { PageLoad_SignedExchange::kEntryName,
                {

                    { PageLoad_SignedExchange::kServedFromGoogleCacheNameHash, PageLoad_SignedExchange::kServedFromGoogleCacheName },

                } } },

        { UINT64_C(2493630448790526384),
            { PageWithPassword::kEntryName,
                {

                    { PageWithPassword::kFormManagerAvailableNameHash, PageWithPassword::kFormManagerAvailableName },

                    { PageWithPassword::kPageLevelUserActionNameHash, PageWithPassword::kPageLevelUserActionName },

                    { PageWithPassword::kProvisionalSaveFailureNameHash, PageWithPassword::kProvisionalSaveFailureName },

                    { PageWithPassword::kUserModifiedPasswordFieldNameHash, PageWithPassword::kUserModifiedPasswordFieldName },

                } } },

        { UINT64_C(1595630084981618121),
            { PaintPreviewCapture::kEntryName,
                {

                    { PaintPreviewCapture::kBlinkCaptureTimeNameHash, PaintPreviewCapture::kBlinkCaptureTimeName },

                    { PaintPreviewCapture::kCompressedOnDiskSizeNameHash, PaintPreviewCapture::kCompressedOnDiskSizeName },

                } } },

        { UINT64_C(8060270586115376858),
            { PasswordForm::kEntryName,
                {

                    { PasswordForm::kContext_FormSignatureNameHash, PasswordForm::kContext_FormSignatureName },

                    { PasswordForm::kDynamicFormChangesNameHash, PasswordForm::kDynamicFormChangesName },

                    { PasswordForm::kFill_FirstFillingResultInRendererNameHash, PasswordForm::kFill_FirstFillingResultInRendererName },

                    { PasswordForm::kFill_FirstWaitForUsernameReasonNameHash, PasswordForm::kFill_FirstWaitForUsernameReasonName },

                    { PasswordForm::kFillOnLoadNameHash, PasswordForm::kFillOnLoadName },

                    { PasswordForm::kGeneration_GeneratedPasswordNameHash, PasswordForm::kGeneration_GeneratedPasswordName },

                    { PasswordForm::kGeneration_GeneratedPasswordModifiedNameHash, PasswordForm::kGeneration_GeneratedPasswordModifiedName },

                    { PasswordForm::kGeneration_PopupShownNameHash, PasswordForm::kGeneration_PopupShownName },

                    { PasswordForm::kManagerFill_ActionNameHash, PasswordForm::kManagerFill_ActionName },

                    { PasswordForm::kManagerFill_AssistanceNameHash, PasswordForm::kManagerFill_AssistanceName },

                    { PasswordForm::kReadonlyWhenFillingNameHash, PasswordForm::kReadonlyWhenFillingName },

                    { PasswordForm::kReadonlyWhenSavingNameHash, PasswordForm::kReadonlyWhenSavingName },

                    { PasswordForm::kSaving_Prompt_InteractionNameHash, PasswordForm::kSaving_Prompt_InteractionName },

                    { PasswordForm::kSaving_Prompt_ShownNameHash, PasswordForm::kSaving_Prompt_ShownName },

                    { PasswordForm::kSaving_Prompt_TriggerNameHash, PasswordForm::kSaving_Prompt_TriggerName },

                    { PasswordForm::kSaving_ShowedManualFallbackForSavingNameHash, PasswordForm::kSaving_ShowedManualFallbackForSavingName },

                    { PasswordForm::kSubmission_IndicatorNameHash, PasswordForm::kSubmission_IndicatorName },

                    { PasswordForm::kSubmission_ObservedNameHash, PasswordForm::kSubmission_ObservedName },

                    { PasswordForm::kSubmission_SubmissionResultNameHash, PasswordForm::kSubmission_SubmissionResultName },

                    { PasswordForm::kSubmission_SubmittedFormTypeNameHash, PasswordForm::kSubmission_SubmittedFormTypeName },

                    { PasswordForm::kUpdating_Prompt_InteractionNameHash, PasswordForm::kUpdating_Prompt_InteractionName },

                    { PasswordForm::kUpdating_Prompt_ShownNameHash, PasswordForm::kUpdating_Prompt_ShownName },

                    { PasswordForm::kUpdating_Prompt_TriggerNameHash, PasswordForm::kUpdating_Prompt_TriggerName },

                    { PasswordForm::kUser_Action_CorrectedUsernameInFormNameHash, PasswordForm::kUser_Action_CorrectedUsernameInFormName },

                    { PasswordForm::kUser_Action_EditedUsernameInBubbleNameHash, PasswordForm::kUser_Action_EditedUsernameInBubbleName },

                    { PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleNameHash, PasswordForm::kUser_Action_SelectedDifferentPasswordInBubbleName },

                    { PasswordForm::kUser_Action_TriggeredManualFallbackForSavingNameHash, PasswordForm::kUser_Action_TriggeredManualFallbackForSavingName },

                } } },

        { UINT64_C(12997918245497021702),
            { PasswordManager_LeakWarningDialog::kEntryName,
                {

                    { PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogDismissalReasonNameHash,
                        PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogDismissalReasonName },

                    { PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogTypeNameHash, PasswordManager_LeakWarningDialog::kPasswordLeakDetectionDialogTypeName },

                } } },

        { UINT64_C(13449954988418736908),
            { PasswordManager_PasswordChangeFlowDuration::kEntryName,
                {

                    { PasswordManager_PasswordChangeFlowDuration::kDurationNameHash, PasswordManager_PasswordChangeFlowDuration::kDurationName },

                    { PasswordManager_PasswordChangeFlowDuration::kEndEventNameHash, PasswordManager_PasswordChangeFlowDuration::kEndEventName },

                    { PasswordManager_PasswordChangeFlowDuration::kEntryPointNameHash, PasswordManager_PasswordChangeFlowDuration::kEntryPointName },

                    { PasswordManager_PasswordChangeFlowDuration::kStartEventNameHash, PasswordManager_PasswordChangeFlowDuration::kStartEventName },

                } } },

        { UINT64_C(16550471355748170236),
            { PasswordManager_PasswordChangeTriggered::kEntryName,
                {

                    { PasswordManager_PasswordChangeTriggered::kPasswordChangeTypeNameHash, PasswordManager_PasswordChangeTriggered::kPasswordChangeTypeName },

                } } },

        { UINT64_C(5726428427092735799),
            { PasswordManager_PasswordFillingIOS::kEntryName,
                {

                    { PasswordManager_PasswordFillingIOS::kFillingSuccessNameHash, PasswordManager_PasswordFillingIOS::kFillingSuccessName },

                } } },

        { UINT64_C(8595641688177899640),
            { PasswordManager_WellKnownChangePasswordResult::kEntryName,
                {

                    { PasswordManager_WellKnownChangePasswordResult::kWellKnownChangePasswordResultNameHash,
                        PasswordManager_WellKnownChangePasswordResult::kWellKnownChangePasswordResultName },

                } } },

        { UINT64_C(702207440764833882),
            { PaymentApp_CheckoutEvents::kEntryName,
                {

                    { PaymentApp_CheckoutEvents::kCompletionStatusNameHash, PaymentApp_CheckoutEvents::kCompletionStatusName },

                    { PaymentApp_CheckoutEvents::kEventsNameHash, PaymentApp_CheckoutEvents::kEventsName },

                    { PaymentApp_CheckoutEvents::kEvents2NameHash, PaymentApp_CheckoutEvents::kEvents2Name },

                } } },

        { UINT64_C(9066413457122162526),
            { PaymentRequest_CheckoutEvents::kEntryName,
                {

                    { PaymentRequest_CheckoutEvents::kCompletionStatusNameHash, PaymentRequest_CheckoutEvents::kCompletionStatusName },

                    { PaymentRequest_CheckoutEvents::kEventsNameHash, PaymentRequest_CheckoutEvents::kEventsName },

                    { PaymentRequest_CheckoutEvents::kEvents2NameHash, PaymentRequest_CheckoutEvents::kEvents2Name },

                } } },

        { UINT64_C(4090736682116197688),
            { PaymentRequest_TransactionAmount::kEntryName,
                {

                    { PaymentRequest_TransactionAmount::kCategoryNameHash, PaymentRequest_TransactionAmount::kCategoryName },

                    { PaymentRequest_TransactionAmount::kCompletionStatusNameHash, PaymentRequest_TransactionAmount::kCompletionStatusName },

                } } },

        { UINT64_C(4863880088883807024),
            { Pepper_Broker::kEntryName,
                {

                } } },

        { UINT64_C(8942554384206766435),
            { PerformanceAPI_LongTask::kEntryName,
                {

                    { PerformanceAPI_LongTask::kDurationNameHash, PerformanceAPI_LongTask::kDurationName },

                    { PerformanceAPI_LongTask::kDuration_V8_ExecuteNameHash, PerformanceAPI_LongTask::kDuration_V8_ExecuteName },

                    { PerformanceAPI_LongTask::kDuration_V8_GCNameHash, PerformanceAPI_LongTask::kDuration_V8_GCName },

                    { PerformanceAPI_LongTask::kDuration_V8_GC_Full_AtomicNameHash, PerformanceAPI_LongTask::kDuration_V8_GC_Full_AtomicName },

                    { PerformanceAPI_LongTask::kDuration_V8_GC_Full_IncrementalNameHash, PerformanceAPI_LongTask::kDuration_V8_GC_Full_IncrementalName },

                    { PerformanceAPI_LongTask::kDuration_V8_GC_YoungNameHash, PerformanceAPI_LongTask::kDuration_V8_GC_YoungName },

                    { PerformanceAPI_LongTask::kStartTimeNameHash, PerformanceAPI_LongTask::kStartTimeName },

                } } },

        { UINT64_C(11822404190090982098),
            { PerformanceAPI_Memory::kEntryName,
                {

                    { PerformanceAPI_Memory::kDomNameHash, PerformanceAPI_Memory::kDomName },

                    { PerformanceAPI_Memory::kJavaScriptNameHash, PerformanceAPI_Memory::kJavaScriptName },

                    { PerformanceAPI_Memory::kJavaScript_DedicatedWorkerNameHash, PerformanceAPI_Memory::kJavaScript_DedicatedWorkerName },

                    { PerformanceAPI_Memory::kSharedNameHash, PerformanceAPI_Memory::kSharedName },

                } } },

        { UINT64_C(2959950180700461082),
            { PerformanceAPI_Memory_Legacy::kEntryName,
                {

                    { PerformanceAPI_Memory_Legacy::kJavaScriptNameHash, PerformanceAPI_Memory_Legacy::kJavaScriptName },

                } } },

        { UINT64_C(10815494830717278009),
            { PerformanceManager_PageTimelineState::kEntryName,
                {

                    { PerformanceManager_PageTimelineState::kBatterySaverModeNameHash, PerformanceManager_PageTimelineState::kBatterySaverModeName },

                    { PerformanceManager_PageTimelineState::kChangedFaviconOrTitleInBackgroundNameHash,
                        PerformanceManager_PageTimelineState::kChangedFaviconOrTitleInBackgroundName },

                    { PerformanceManager_PageTimelineState::kCurrentStateNameHash, PerformanceManager_PageTimelineState::kCurrentStateName },

                    { PerformanceManager_PageTimelineState::kHasNotificationPermissionNameHash, PerformanceManager_PageTimelineState::kHasNotificationPermissionName },

                    { PerformanceManager_PageTimelineState::kHighEfficiencyModeNameHash, PerformanceManager_PageTimelineState::kHighEfficiencyModeName },

                    { PerformanceManager_PageTimelineState::kIsActiveTabNameHash, PerformanceManager_PageTimelineState::kIsActiveTabName },

                    { PerformanceManager_PageTimelineState::kIsCapturingMediaNameHash, PerformanceManager_PageTimelineState::kIsCapturingMediaName },

                    { PerformanceManager_PageTimelineState::kIsConnectedToDeviceNameHash, PerformanceManager_PageTimelineState::kIsConnectedToDeviceName },

                    { PerformanceManager_PageTimelineState::kIsPlayingAudioNameHash, PerformanceManager_PageTimelineState::kIsPlayingAudioName },

                    { PerformanceManager_PageTimelineState::kResidentSetSizeNameHash, PerformanceManager_PageTimelineState::kResidentSetSizeName },

                    { PerformanceManager_PageTimelineState::kSliceIdNameHash, PerformanceManager_PageTimelineState::kSliceIdName },

                    { PerformanceManager_PageTimelineState::kTabIdNameHash, PerformanceManager_PageTimelineState::kTabIdName },

                    { PerformanceManager_PageTimelineState::kTimeInCurrentStateNameHash, PerformanceManager_PageTimelineState::kTimeInCurrentStateName },

                    { PerformanceManager_PageTimelineState::kTimeSinceCreationNameHash, PerformanceManager_PageTimelineState::kTimeSinceCreationName },

                    { PerformanceManager_PageTimelineState::kTimeSinceLastSliceNameHash, PerformanceManager_PageTimelineState::kTimeSinceLastSliceName },

                    { PerformanceManager_PageTimelineState::kTotalForegroundTimeNameHash, PerformanceManager_PageTimelineState::kTotalForegroundTimeName },

                } } },

        { UINT64_C(10863131082725230381),
            { PeriodicBackgroundSyncEventCompleted::kEntryName,
                {

                    { PeriodicBackgroundSyncEventCompleted::kMaxAttemptsNameHash, PeriodicBackgroundSyncEventCompleted::kMaxAttemptsName },

                    { PeriodicBackgroundSyncEventCompleted::kNumAttemptsNameHash, PeriodicBackgroundSyncEventCompleted::kNumAttemptsName },

                    { PeriodicBackgroundSyncEventCompleted::kStatusNameHash, PeriodicBackgroundSyncEventCompleted::kStatusName },

                } } },

        { UINT64_C(8211654418406942912),
            { PeriodicBackgroundSyncRegistered::kEntryName,
                {

                    { PeriodicBackgroundSyncRegistered::kIsReregisteredNameHash, PeriodicBackgroundSyncRegistered::kIsReregisteredName },

                    { PeriodicBackgroundSyncRegistered::kMinIntervalMsNameHash, PeriodicBackgroundSyncRegistered::kMinIntervalMsName },

                } } },

        { UINT64_C(17104084284355864347),
            { Permission::kEntryName,
                {

                    { Permission::kActionNameHash, Permission::kActionName },

                    { Permission::kGestureNameHash, Permission::kGestureName },

                    { Permission::kPermissionAutoRevocationHistoryNameHash, Permission::kPermissionAutoRevocationHistoryName },

                    { Permission::kPermissionTypeNameHash, Permission::kPermissionTypeName },

                    { Permission::kPredictionsApiResponse_GrantLikelihoodNameHash, Permission::kPredictionsApiResponse_GrantLikelihoodName },

                    { Permission::kPredictionsApiResponse_HeldbackNameHash, Permission::kPredictionsApiResponse_HeldbackName },

                    { Permission::kPriorDismissalsNameHash, Permission::kPriorDismissalsName },

                    { Permission::kPriorIgnoresNameHash, Permission::kPriorIgnoresName },

                    { Permission::kPromptDispositionNameHash, Permission::kPromptDispositionName },

                    { Permission::kPromptDispositionReasonNameHash, Permission::kPromptDispositionReasonName },

                    { Permission::kSatisfiedAdaptiveTriggersNameHash, Permission::kSatisfiedAdaptiveTriggersName },

                    { Permission::kSourceNameHash, Permission::kSourceName },

                    { Permission::kStats_AllPrompts_CountNameHash, Permission::kStats_AllPrompts_CountName },

                    { Permission::kStats_AllPrompts_DenyRateNameHash, Permission::kStats_AllPrompts_DenyRateName },

                    { Permission::kStats_AllPrompts_DismissRateNameHash, Permission::kStats_AllPrompts_DismissRateName },

                    { Permission::kStats_AllPrompts_GrantRateNameHash, Permission::kStats_AllPrompts_GrantRateName },

                    { Permission::kStats_AllPrompts_IgnoreRateNameHash, Permission::kStats_AllPrompts_IgnoreRateName },

                    { Permission::kStats_AllPromptsOfType_CountNameHash, Permission::kStats_AllPromptsOfType_CountName },

                    { Permission::kStats_AllPromptsOfType_DenyRateNameHash, Permission::kStats_AllPromptsOfType_DenyRateName },

                    { Permission::kStats_AllPromptsOfType_DismissRateNameHash, Permission::kStats_AllPromptsOfType_DismissRateName },

                    { Permission::kStats_AllPromptsOfType_GrantRateNameHash, Permission::kStats_AllPromptsOfType_GrantRateName },

                    { Permission::kStats_AllPromptsOfType_IgnoreRateNameHash, Permission::kStats_AllPromptsOfType_IgnoreRateName },

                    { Permission::kStats_LoudPrompts_CountNameHash, Permission::kStats_LoudPrompts_CountName },

                    { Permission::kStats_LoudPrompts_DenyRateNameHash, Permission::kStats_LoudPrompts_DenyRateName },

                    { Permission::kStats_LoudPrompts_DismissRateNameHash, Permission::kStats_LoudPrompts_DismissRateName },

                    { Permission::kStats_LoudPrompts_GrantRateNameHash, Permission::kStats_LoudPrompts_GrantRateName },

                    { Permission::kStats_LoudPrompts_IgnoreRateNameHash, Permission::kStats_LoudPrompts_IgnoreRateName },

                    { Permission::kStats_LoudPromptsOfType_CountNameHash, Permission::kStats_LoudPromptsOfType_CountName },

                    { Permission::kStats_LoudPromptsOfType_DenyRateNameHash, Permission::kStats_LoudPromptsOfType_DenyRateName },

                    { Permission::kStats_LoudPromptsOfType_DismissRateNameHash, Permission::kStats_LoudPromptsOfType_DismissRateName },

                    { Permission::kStats_LoudPromptsOfType_GrantRateNameHash, Permission::kStats_LoudPromptsOfType_GrantRateName },

                    { Permission::kStats_LoudPromptsOfType_IgnoreRateNameHash, Permission::kStats_LoudPromptsOfType_IgnoreRateName },

                    { Permission::kTimeToDecisionNameHash, Permission::kTimeToDecisionName },

                } } },

        { UINT64_C(15070635187011991637),
            { PermissionUsage::kEntryName,
                {

                    { PermissionUsage::kPermissionTypeNameHash, PermissionUsage::kPermissionTypeName },

                } } },

        { UINT64_C(2851782918499658607),
            { Plugins_FlashInstance::kEntryName,
                {

                } } },

        { UINT64_C(5373577291340314501),
            { Popup_Closed::kEntryName,
                {

                    { Popup_Closed::kEngagementTimeNameHash, Popup_Closed::kEngagementTimeName },

                    { Popup_Closed::kNumActivationInteractionsNameHash, Popup_Closed::kNumActivationInteractionsName },

                    { Popup_Closed::kNumGestureScrollBeginInteractionsNameHash, Popup_Closed::kNumGestureScrollBeginInteractionsName },

                    { Popup_Closed::kNumInteractionsNameHash, Popup_Closed::kNumInteractionsName },

                    { Popup_Closed::kRedirectCountNameHash, Popup_Closed::kRedirectCountName },

                    { Popup_Closed::kSafeBrowsingStatusNameHash, Popup_Closed::kSafeBrowsingStatusName },

                    { Popup_Closed::kTrustedNameHash, Popup_Closed::kTrustedName },

                    { Popup_Closed::kUserInitiatedCloseNameHash, Popup_Closed::kUserInitiatedCloseName },

                    { Popup_Closed::kWindowOpenDispositionNameHash, Popup_Closed::kWindowOpenDispositionName },

                } } },

        { UINT64_C(9277003375443527515),
            { Popup_Page::kEntryName,
                {

                    { Popup_Page::kAllowedNameHash, Popup_Page::kAllowedName },

                } } },

        { UINT64_C(570650911258459707),
            { Portal_Activate::kEntryName,
                {

                    { Portal_Activate::kPaintTiming_PortalActivationToFirstPaintNameHash, Portal_Activate::kPaintTiming_PortalActivationToFirstPaintName },

                    { Portal_Activate::kPortalActivationNameHash, Portal_Activate::kPortalActivationName },

                    { Portal_Activate::kPortalActivationBeforeLCPNameHash, Portal_Activate::kPortalActivationBeforeLCPName },

                } } },

        { UINT64_C(946156007913851639),
            { PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kEntryName,
                {

                    { PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_FirstPartyToFirstParty_DifferentBucket::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(12008026445921582786),
            { PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kEntryName,
                {

                    { PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_FirstPartyToFirstParty_SameBucket::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(3023430001139017401),
            { PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kEntryName,
                {

                    { PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(18233691177423472176),
            { PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kEntryName,
                {

                    { PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_FirstPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(10043508855074261617),
            { PostMessage_Incoming_Frame::kEntryName,
                {

                    { PostMessage_Incoming_Frame::kSourceFrameSourceIdNameHash, PostMessage_Incoming_Frame::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(10269125776340795214),
            { PostMessage_Incoming_Opaque::kEntryName,
                {

                    { PostMessage_Incoming_Opaque::kSourceFrameSourceIdNameHash, PostMessage_Incoming_Opaque::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(2379299131482791346),
            { PostMessage_Incoming_Page::kEntryName,
                {

                    { PostMessage_Incoming_Page::kSourcePageSourceIdNameHash, PostMessage_Incoming_Page::kSourcePageSourceIdName },

                } } },

        { UINT64_C(4659478743156900308),
            { PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kEntryName,
                {

                    { PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(12103353836620805890),
            { PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kEntryName,
                {

                    { PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_ThirdPartyToFirstParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(11794178105382495697),
            { PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kEntryName,
                {

                    { PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_DifferentOrigin::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(5984440603720566390),
            { PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kEntryName,
                {

                    { PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_ThirdPartyToThirdParty_DifferentBucket_SameOrigin::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(6183747664454783425),
            { PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kEntryName,
                {

                    { PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kSourceFrameSourceIdNameHash,
                        PostMessage_Incoming_ThirdPartyToThirdParty_SameBucket::kSourceFrameSourceIdName },

                } } },

        { UINT64_C(1484103205961568756),
            { PowerUsageScenariosIntervalData::kEntryName,
                {

                    { PowerUsageScenariosIntervalData::kBatteryDischargeModeNameHash, PowerUsageScenariosIntervalData::kBatteryDischargeModeName },

                    { PowerUsageScenariosIntervalData::kBatteryDischargeRateNameHash, PowerUsageScenariosIntervalData::kBatteryDischargeRateName },

                    { PowerUsageScenariosIntervalData::kBrowserShuttingDownNameHash, PowerUsageScenariosIntervalData::kBrowserShuttingDownName },

                    { PowerUsageScenariosIntervalData::kCPUTimeMsNameHash, PowerUsageScenariosIntervalData::kCPUTimeMsName },

                    { PowerUsageScenariosIntervalData::kDeviceSleptDuringIntervalNameHash, PowerUsageScenariosIntervalData::kDeviceSleptDuringIntervalName },

                    { PowerUsageScenariosIntervalData::kEnergyImpactScoreNameHash, PowerUsageScenariosIntervalData::kEnergyImpactScoreName },

                    { PowerUsageScenariosIntervalData::kFullscreenVideoSingleMonitorSecondsNameHash, PowerUsageScenariosIntervalData::kFullscreenVideoSingleMonitorSecondsName },

                    { PowerUsageScenariosIntervalData::kIdleWakeUpsNameHash, PowerUsageScenariosIntervalData::kIdleWakeUpsName },

                    { PowerUsageScenariosIntervalData::kIntervalDurationSecondsNameHash, PowerUsageScenariosIntervalData::kIntervalDurationSecondsName },

                    { PowerUsageScenariosIntervalData::kMaxTabCountNameHash, PowerUsageScenariosIntervalData::kMaxTabCountName },

                    { PowerUsageScenariosIntervalData::kMaxVisibleWindowCountNameHash, PowerUsageScenariosIntervalData::kMaxVisibleWindowCountName },

                    { PowerUsageScenariosIntervalData::kOriginVisibilityTimeSecondsNameHash, PowerUsageScenariosIntervalData::kOriginVisibilityTimeSecondsName },

                    { PowerUsageScenariosIntervalData::kPackageExitsNameHash, PowerUsageScenariosIntervalData::kPackageExitsName },

                    { PowerUsageScenariosIntervalData::kPlayingAudioSecondsNameHash, PowerUsageScenariosIntervalData::kPlayingAudioSecondsName },

                    { PowerUsageScenariosIntervalData::kTabClosedNameHash, PowerUsageScenariosIntervalData::kTabClosedName },

                    { PowerUsageScenariosIntervalData::kTimePlayingVideoInVisibleTabNameHash, PowerUsageScenariosIntervalData::kTimePlayingVideoInVisibleTabName },

                    { PowerUsageScenariosIntervalData::kTimeSinceInteractionWithBrowserSecondsNameHash,
                        PowerUsageScenariosIntervalData::kTimeSinceInteractionWithBrowserSecondsName },

                    { PowerUsageScenariosIntervalData::kTimeSinceInteractionWithSystemSecondsNameHash,
                        PowerUsageScenariosIntervalData::kTimeSinceInteractionWithSystemSecondsName },

                    { PowerUsageScenariosIntervalData::kTimeWithOpenWebRTCConnectionSecondsNameHash, PowerUsageScenariosIntervalData::kTimeWithOpenWebRTCConnectionSecondsName },

                    { PowerUsageScenariosIntervalData::kTopLevelNavigationEventsNameHash, PowerUsageScenariosIntervalData::kTopLevelNavigationEventsName },

                    { PowerUsageScenariosIntervalData::kUptimeSecondsNameHash, PowerUsageScenariosIntervalData::kUptimeSecondsName },

                    { PowerUsageScenariosIntervalData::kURLVisibilityTimeSecondsNameHash, PowerUsageScenariosIntervalData::kURLVisibilityTimeSecondsName },

                    { PowerUsageScenariosIntervalData::kUserInteractionCountNameHash, PowerUsageScenariosIntervalData::kUserInteractionCountName },

                    { PowerUsageScenariosIntervalData::kVideoCaptureSecondsNameHash, PowerUsageScenariosIntervalData::kVideoCaptureSecondsName },

                } } },

        { UINT64_C(11352241752715206016),
            { PrefetchProxy::kEntryName,
                {

                    { PrefetchProxy::kdays_since_last_visit_to_originNameHash, PrefetchProxy::kdays_since_last_visit_to_originName },

                    { PrefetchProxy::kprefetch_attempted_countNameHash, PrefetchProxy::kprefetch_attempted_countName },

                    { PrefetchProxy::kprefetch_eligible_countNameHash, PrefetchProxy::kprefetch_eligible_countName },

                    { PrefetchProxy::kprefetch_successful_countNameHash, PrefetchProxy::kprefetch_successful_countName },

                } } },

        { UINT64_C(6674705951757661648),
            { PrefetchProxy_AfterSRPClick::kEntryName,
                {

                    { PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionNameHash, PrefetchProxy_AfterSRPClick::kClickedLinkSRPPositionName },

                    { PrefetchProxy_AfterSRPClick::kPrefetchHeaderLatencyMsNameHash, PrefetchProxy_AfterSRPClick::kPrefetchHeaderLatencyMsName },

                    { PrefetchProxy_AfterSRPClick::kPrivatePrefetchNameHash, PrefetchProxy_AfterSRPClick::kPrivatePrefetchName },

                    { PrefetchProxy_AfterSRPClick::kProbeLatencyMsNameHash, PrefetchProxy_AfterSRPClick::kProbeLatencyMsName },

                    { PrefetchProxy_AfterSRPClick::kSameTabAsPrefetchingTabNameHash, PrefetchProxy_AfterSRPClick::kSameTabAsPrefetchingTabName },

                    { PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusNameHash, PrefetchProxy_AfterSRPClick::kSRPClickPrefetchStatusName },

                    { PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountNameHash, PrefetchProxy_AfterSRPClick::kSRPPrefetchEligibleCountName },

                } } },

        { UINT64_C(4145272093809115535),
            { PrefetchProxy_PrefetchedResource::kEntryName,
                {

                    { PrefetchProxy_PrefetchedResource::kDataLengthNameHash, PrefetchProxy_PrefetchedResource::kDataLengthName },

                    { PrefetchProxy_PrefetchedResource::kFetchDurationMSNameHash, PrefetchProxy_PrefetchedResource::kFetchDurationMSName },

                    { PrefetchProxy_PrefetchedResource::kISPFilteringStatusNameHash, PrefetchProxy_PrefetchedResource::kISPFilteringStatusName },

                    { PrefetchProxy_PrefetchedResource::kLinkClickedNameHash, PrefetchProxy_PrefetchedResource::kLinkClickedName },

                    { PrefetchProxy_PrefetchedResource::kLinkPositionNameHash, PrefetchProxy_PrefetchedResource::kLinkPositionName },

                    { PrefetchProxy_PrefetchedResource::kNavigationStartToFetchStartMSNameHash, PrefetchProxy_PrefetchedResource::kNavigationStartToFetchStartMSName },

                    { PrefetchProxy_PrefetchedResource::kResourceTypeNameHash, PrefetchProxy_PrefetchedResource::kResourceTypeName },

                    { PrefetchProxy_PrefetchedResource::kStatusNameHash, PrefetchProxy_PrefetchedResource::kStatusName },

                } } },

        { UINT64_C(13946160855775187618),
            { Preloading_AnchorInteraction::kEntryName,
                {

                    { Preloading_AnchorInteraction::kAnchorElementPreloaderTypeNameHash, Preloading_AnchorInteraction::kAnchorElementPreloaderTypeName },

                } } },

        { UINT64_C(8746692042487350705),
            { Preloading_Attempt::kEntryName,
                {

                    { Preloading_Attempt::kAccurateTriggeringNameHash, Preloading_Attempt::kAccurateTriggeringName },

                    { Preloading_Attempt::kEligibilityNameHash, Preloading_Attempt::kEligibilityName },

                    { Preloading_Attempt::kFailureReasonNameHash, Preloading_Attempt::kFailureReasonName },

                    { Preloading_Attempt::kHoldbackStatusNameHash, Preloading_Attempt::kHoldbackStatusName },

                    { Preloading_Attempt::kPreloadingPredictorNameHash, Preloading_Attempt::kPreloadingPredictorName },

                    { Preloading_Attempt::kPreloadingTypeNameHash, Preloading_Attempt::kPreloadingTypeName },

                    { Preloading_Attempt::kTriggeringOutcomeNameHash, Preloading_Attempt::kTriggeringOutcomeName },

                } } },

        { UINT64_C(16426521927935131349),
            { Preloading_Attempt_PreviousPrimaryPage::kEntryName,
                {

                    { Preloading_Attempt_PreviousPrimaryPage::kAccurateTriggeringNameHash, Preloading_Attempt_PreviousPrimaryPage::kAccurateTriggeringName },

                    { Preloading_Attempt_PreviousPrimaryPage::kEligibilityNameHash, Preloading_Attempt_PreviousPrimaryPage::kEligibilityName },

                    { Preloading_Attempt_PreviousPrimaryPage::kFailureReasonNameHash, Preloading_Attempt_PreviousPrimaryPage::kFailureReasonName },

                    { Preloading_Attempt_PreviousPrimaryPage::kHoldbackStatusNameHash, Preloading_Attempt_PreviousPrimaryPage::kHoldbackStatusName },

                    { Preloading_Attempt_PreviousPrimaryPage::kPreloadingPredictorNameHash, Preloading_Attempt_PreviousPrimaryPage::kPreloadingPredictorName },

                    { Preloading_Attempt_PreviousPrimaryPage::kPreloadingTypeNameHash, Preloading_Attempt_PreviousPrimaryPage::kPreloadingTypeName },

                    { Preloading_Attempt_PreviousPrimaryPage::kTriggeringOutcomeNameHash, Preloading_Attempt_PreviousPrimaryPage::kTriggeringOutcomeName },

                } } },

        { UINT64_C(7178389144071274549),
            { Preloading_Prediction::kEntryName,
                {

                    { Preloading_Prediction::kAccuratePredictionNameHash, Preloading_Prediction::kAccuratePredictionName },

                    { Preloading_Prediction::kConfidenceNameHash, Preloading_Prediction::kConfidenceName },

                    { Preloading_Prediction::kPreloadingPredictorNameHash, Preloading_Prediction::kPreloadingPredictorName },

                } } },

        { UINT64_C(5667944672124880130),
            { Preloading_Prediction_PreviousPrimaryPage::kEntryName,
                {

                    { Preloading_Prediction_PreviousPrimaryPage::kAccuratePredictionNameHash, Preloading_Prediction_PreviousPrimaryPage::kAccuratePredictionName },

                    { Preloading_Prediction_PreviousPrimaryPage::kConfidenceNameHash, Preloading_Prediction_PreviousPrimaryPage::kConfidenceName },

                    { Preloading_Prediction_PreviousPrimaryPage::kPreloadingPredictorNameHash, Preloading_Prediction_PreviousPrimaryPage::kPreloadingPredictorName },

                } } },

        { UINT64_C(14500319117729505239),
            { PrerenderPageLoad::kEntryName,
                {

                    { PrerenderPageLoad::kFinalStatusNameHash, PrerenderPageLoad::kFinalStatusName },

                    { PrerenderPageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationNameHash,
                        PrerenderPageLoad::kInteractiveTiming_AverageUserInteractionLatencyOverBudget_MaxEventDurationName },

                    { PrerenderPageLoad::kInteractiveTiming_FirstInputDelay4NameHash, PrerenderPageLoad::kInteractiveTiming_FirstInputDelay4Name },

                    { PrerenderPageLoad::kInteractiveTiming_NumInteractionsNameHash, PrerenderPageLoad::kInteractiveTiming_NumInteractionsName },

                    { PrerenderPageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationNameHash,
                        PrerenderPageLoad::kInteractiveTiming_UserInteractionLatency_HighPercentile2_MaxEventDurationName },

                    { PrerenderPageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationNameHash,
                        PrerenderPageLoad::kInteractiveTiming_WorstUserInteractionLatency_MaxEventDurationName },

                    { PrerenderPageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msNameHash,
                        PrerenderPageLoad::kLayoutInstability_MaxCumulativeShiftScore_SessionWindow_Gap1000ms_Max5000msName },

                    { PrerenderPageLoad::kTiming_ActivationToFirstContentfulPaintNameHash, PrerenderPageLoad::kTiming_ActivationToFirstContentfulPaintName },

                    { PrerenderPageLoad::kTiming_ActivationToLargestContentfulPaintNameHash, PrerenderPageLoad::kTiming_ActivationToLargestContentfulPaintName },

                    { PrerenderPageLoad::kTiming_NavigationToActivationNameHash, PrerenderPageLoad::kTiming_NavigationToActivationName },

                    { PrerenderPageLoad::kTriggeredPrerenderNameHash, PrerenderPageLoad::kTriggeredPrerenderName },

                    { PrerenderPageLoad::kWasPrerenderedNameHash, PrerenderPageLoad::kWasPrerenderedName },

                } } },

        { UINT64_C(2441679537758985212),
            { Presentation_StartResult::kEntryName,
                {

                    { Presentation_StartResult::kPresentationRequestNameHash, Presentation_StartResult::kPresentationRequestName },

                    { Presentation_StartResult::kRemotePlaybackNameHash, Presentation_StartResult::kRemotePlaybackName },

                } } },

        { UINT64_C(4791378639615025150),
            { PWA_Visit::kEntryName,
                {

                    { PWA_Visit::kLaunchSourceNameHash, PWA_Visit::kLaunchSourceName },

                    { PWA_Visit::kWebAPKableSiteVisitNameHash, PWA_Visit::kWebAPKableSiteVisitName },

                } } },

        { UINT64_C(15014052365473894052),
            { ReaderModeActivated::kEntryName,
                {

                    { ReaderModeActivated::kActivatedViaOmniboxNameHash, ReaderModeActivated::kActivatedViaOmniboxName },

                } } },

        { UINT64_C(3308537368968335608),
            { ReaderModeReceivedDistillability::kEntryName,
                {

                    { ReaderModeReceivedDistillability::kIsPageDistillableNameHash, ReaderModeReceivedDistillability::kIsPageDistillableName },

                } } },

        { UINT64_C(18249372845339521807),
            { RendererSchedulerTask::kEntryName,
                {

                    { RendererSchedulerTask::kFrameStatusNameHash, RendererSchedulerTask::kFrameStatusName },

                    { RendererSchedulerTask::kIsOOPIFNameHash, RendererSchedulerTask::kIsOOPIFName },

                    { RendererSchedulerTask::kPageSchedulersNameHash, RendererSchedulerTask::kPageSchedulersName },

                    { RendererSchedulerTask::kQueueTypeNameHash, RendererSchedulerTask::kQueueTypeName },

                    { RendererSchedulerTask::kRendererAudibleNameHash, RendererSchedulerTask::kRendererAudibleName },

                    { RendererSchedulerTask::kRendererBackgroundedNameHash, RendererSchedulerTask::kRendererBackgroundedName },

                    { RendererSchedulerTask::kRendererHiddenNameHash, RendererSchedulerTask::kRendererHiddenName },

                    { RendererSchedulerTask::kSecondsSinceBackgroundedNameHash, RendererSchedulerTask::kSecondsSinceBackgroundedName },

                    { RendererSchedulerTask::kTaskCPUDurationNameHash, RendererSchedulerTask::kTaskCPUDurationName },

                    { RendererSchedulerTask::kTaskDurationNameHash, RendererSchedulerTask::kTaskDurationName },

                    { RendererSchedulerTask::kTaskTypeNameHash, RendererSchedulerTask::kTaskTypeName },

                    { RendererSchedulerTask::kThreadTypeNameHash, RendererSchedulerTask::kThreadTypeName },

                    { RendererSchedulerTask::kUseCaseNameHash, RendererSchedulerTask::kUseCaseName },

                    { RendererSchedulerTask::kVersionNameHash, RendererSchedulerTask::kVersionName },

                } } },

        { UINT64_C(14554281962363859401),
            { RenderViewContextMenu_Used::kEntryName,
                {

                    { RenderViewContextMenu_Used::kSelectedMenuItemNameHash, RenderViewContextMenu_Used::kSelectedMenuItemName },

                } } },

        { UINT64_C(8390839146308016474),
            { Responsiveness_UserInteraction::kEntryName,
                {

                    { Responsiveness_UserInteraction::kInteractionTypeNameHash, Responsiveness_UserInteraction::kInteractionTypeName },

                    { Responsiveness_UserInteraction::kMaxEventDurationNameHash, Responsiveness_UserInteraction::kMaxEventDurationName },

                    { Responsiveness_UserInteraction::kTotalEventDurationNameHash, Responsiveness_UserInteraction::kTotalEventDurationName },

                } } },

        { UINT64_C(6628044799783508745),
            { ResponsivenessMeasurement::kEntryName,
                {

                } } },

        { UINT64_C(8255360323456312283),
            { SalientImageAvailability::kEntryName,
                {

                    { SalientImageAvailability::kImageAvailabilityNameHash, SalientImageAvailability::kImageAvailabilityName },

                } } },

        { UINT64_C(14016795862258924641),
            { SameSiteDifferentSchemeRequest::kEntryName,
                {

                } } },

        { UINT64_C(6057282574508536454),
            { SameSiteDifferentSchemeResponse::kEntryName,
                {

                } } },

        { UINT64_C(16392896102401488447),
            { SchemefulSameSiteContextDowngrade::kEntryName,
                {

                    { SchemefulSameSiteContextDowngrade::kRequestPerCookieNameHash, SchemefulSameSiteContextDowngrade::kRequestPerCookieName },

                    { SchemefulSameSiteContextDowngrade::kResponsePerCookieNameHash, SchemefulSameSiteContextDowngrade::kResponsePerCookieName },

                } } },

        { UINT64_C(17111718181803892778),
            { ScreenBrightness::kEntryName,
                {

                    { ScreenBrightness::kBatteryPercentNameHash, ScreenBrightness::kBatteryPercentName },

                    { ScreenBrightness::kBrightnessNameHash, ScreenBrightness::kBrightnessName },

                    { ScreenBrightness::kDayOfWeekNameHash, ScreenBrightness::kDayOfWeekName },

                    { ScreenBrightness::kDeviceModeNameHash, ScreenBrightness::kDeviceModeName },

                    { ScreenBrightness::kHourOfDayNameHash, ScreenBrightness::kHourOfDayName },

                    { ScreenBrightness::kIsAutoclickEnabledNameHash, ScreenBrightness::kIsAutoclickEnabledName },

                    { ScreenBrightness::kIsBrailleDisplayConnectedNameHash, ScreenBrightness::kIsBrailleDisplayConnectedName },

                    { ScreenBrightness::kIsCaretHighlightEnabledNameHash, ScreenBrightness::kIsCaretHighlightEnabledName },

                    { ScreenBrightness::kIsCursorHighlightEnabledNameHash, ScreenBrightness::kIsCursorHighlightEnabledName },

                    { ScreenBrightness::kIsFocusHighlightEnabledNameHash, ScreenBrightness::kIsFocusHighlightEnabledName },

                    { ScreenBrightness::kIsHighContrastEnabledNameHash, ScreenBrightness::kIsHighContrastEnabledName },

                    { ScreenBrightness::kIsLargeCursorEnabledNameHash, ScreenBrightness::kIsLargeCursorEnabledName },

                    { ScreenBrightness::kIsMagnifierEnabledNameHash, ScreenBrightness::kIsMagnifierEnabledName },

                    { ScreenBrightness::kIsMonoAudioEnabledNameHash, ScreenBrightness::kIsMonoAudioEnabledName },

                    { ScreenBrightness::kIsSelectToSpeakEnabledNameHash, ScreenBrightness::kIsSelectToSpeakEnabledName },

                    { ScreenBrightness::kIsSpokenFeedbackEnabledNameHash, ScreenBrightness::kIsSpokenFeedbackEnabledName },

                    { ScreenBrightness::kIsSwitchAccessEnabledNameHash, ScreenBrightness::kIsSwitchAccessEnabledName },

                    { ScreenBrightness::kIsVideoPlayingNameHash, ScreenBrightness::kIsVideoPlayingName },

                    { ScreenBrightness::kIsVirtualKeyboardEnabledNameHash, ScreenBrightness::kIsVirtualKeyboardEnabledName },

                    { ScreenBrightness::kLastActivityTimeSecNameHash, ScreenBrightness::kLastActivityTimeSecName },

                    { ScreenBrightness::kNightLightTemperaturePercentNameHash, ScreenBrightness::kNightLightTemperaturePercentName },

                    { ScreenBrightness::kNumRecentKeyEventsNameHash, ScreenBrightness::kNumRecentKeyEventsName },

                    { ScreenBrightness::kNumRecentMouseEventsNameHash, ScreenBrightness::kNumRecentMouseEventsName },

                    { ScreenBrightness::kNumRecentStylusEventsNameHash, ScreenBrightness::kNumRecentStylusEventsName },

                    { ScreenBrightness::kNumRecentTouchEventsNameHash, ScreenBrightness::kNumRecentTouchEventsName },

                    { ScreenBrightness::kOnBatteryNameHash, ScreenBrightness::kOnBatteryName },

                    { ScreenBrightness::kPreviousBrightnessNameHash, ScreenBrightness::kPreviousBrightnessName },

                    { ScreenBrightness::kReasonNameHash, ScreenBrightness::kReasonName },

                    { ScreenBrightness::kRecentTimeActiveSecNameHash, ScreenBrightness::kRecentTimeActiveSecName },

                    { ScreenBrightness::kSequenceIdNameHash, ScreenBrightness::kSequenceIdName },

                    { ScreenBrightness::kTimeSinceLastEventSecNameHash, ScreenBrightness::kTimeSinceLastEventSecName },

                } } },

        { UINT64_C(345243929458665883),
            { Security_SafetyTip::kEntryName,
                {

                    { Security_SafetyTip::kSafetyTipInteractionNameHash, Security_SafetyTip::kSafetyTipInteractionName },

                    { Security_SafetyTip::kSafetyTipStatusNameHash, Security_SafetyTip::kSafetyTipStatusName },

                    { Security_SafetyTip::kTriggeredKeywordsHeuristicsNameHash, Security_SafetyTip::kTriggeredKeywordsHeuristicsName },

                    { Security_SafetyTip::kTriggeredLookalikeHeuristicsNameHash, Security_SafetyTip::kTriggeredLookalikeHeuristicsName },

                    { Security_SafetyTip::kTriggeredServerSideBlocklistNameHash, Security_SafetyTip::kTriggeredServerSideBlocklistName },

                    { Security_SafetyTip::kUserPreviouslyIgnoredNameHash, Security_SafetyTip::kUserPreviouslyIgnoredName },

                } } },

        { UINT64_C(10614135803401894002),
            { Security_SiteEngagement::kEntryName,
                {

                    { Security_SiteEngagement::kFinalSecurityLevelNameHash, Security_SiteEngagement::kFinalSecurityLevelName },

                    { Security_SiteEngagement::kInitialSecurityLevelNameHash, Security_SiteEngagement::kInitialSecurityLevelName },

                    { Security_SiteEngagement::kSafetyTipStatusNameHash, Security_SiteEngagement::kSafetyTipStatusName },

                    { Security_SiteEngagement::kScoreDeltaNameHash, Security_SiteEngagement::kScoreDeltaName },

                    { Security_SiteEngagement::kScoreFinalNameHash, Security_SiteEngagement::kScoreFinalName },

                } } },

        { UINT64_C(9156952078430180947),
            { Segmentation_ModelExecution::kEntryName,
                {

                    { Segmentation_ModelExecution::kActualResultNameHash, Segmentation_ModelExecution::kActualResultName },

                    { Segmentation_ModelExecution::kActualResult2NameHash, Segmentation_ModelExecution::kActualResult2Name },

                    { Segmentation_ModelExecution::kActualResult3NameHash, Segmentation_ModelExecution::kActualResult3Name },

                    { Segmentation_ModelExecution::kActualResult4NameHash, Segmentation_ModelExecution::kActualResult4Name },

                    { Segmentation_ModelExecution::kActualResult5NameHash, Segmentation_ModelExecution::kActualResult5Name },

                    { Segmentation_ModelExecution::kActualResult6NameHash, Segmentation_ModelExecution::kActualResult6Name },

                    { Segmentation_ModelExecution::kInput0NameHash, Segmentation_ModelExecution::kInput0Name },

                    { Segmentation_ModelExecution::kInput1NameHash, Segmentation_ModelExecution::kInput1Name },

                    { Segmentation_ModelExecution::kInput10NameHash, Segmentation_ModelExecution::kInput10Name },

                    { Segmentation_ModelExecution::kInput11NameHash, Segmentation_ModelExecution::kInput11Name },

                    { Segmentation_ModelExecution::kInput12NameHash, Segmentation_ModelExecution::kInput12Name },

                    { Segmentation_ModelExecution::kInput13NameHash, Segmentation_ModelExecution::kInput13Name },

                    { Segmentation_ModelExecution::kInput14NameHash, Segmentation_ModelExecution::kInput14Name },

                    { Segmentation_ModelExecution::kInput15NameHash, Segmentation_ModelExecution::kInput15Name },

                    { Segmentation_ModelExecution::kInput16NameHash, Segmentation_ModelExecution::kInput16Name },

                    { Segmentation_ModelExecution::kInput17NameHash, Segmentation_ModelExecution::kInput17Name },

                    { Segmentation_ModelExecution::kInput18NameHash, Segmentation_ModelExecution::kInput18Name },

                    { Segmentation_ModelExecution::kInput19NameHash, Segmentation_ModelExecution::kInput19Name },

                    { Segmentation_ModelExecution::kInput2NameHash, Segmentation_ModelExecution::kInput2Name },

                    { Segmentation_ModelExecution::kInput20NameHash, Segmentation_ModelExecution::kInput20Name },

                    { Segmentation_ModelExecution::kInput21NameHash, Segmentation_ModelExecution::kInput21Name },

                    { Segmentation_ModelExecution::kInput22NameHash, Segmentation_ModelExecution::kInput22Name },

                    { Segmentation_ModelExecution::kInput23NameHash, Segmentation_ModelExecution::kInput23Name },

                    { Segmentation_ModelExecution::kInput24NameHash, Segmentation_ModelExecution::kInput24Name },

                    { Segmentation_ModelExecution::kInput25NameHash, Segmentation_ModelExecution::kInput25Name },

                    { Segmentation_ModelExecution::kInput26NameHash, Segmentation_ModelExecution::kInput26Name },

                    { Segmentation_ModelExecution::kInput27NameHash, Segmentation_ModelExecution::kInput27Name },

                    { Segmentation_ModelExecution::kInput28NameHash, Segmentation_ModelExecution::kInput28Name },

                    { Segmentation_ModelExecution::kInput29NameHash, Segmentation_ModelExecution::kInput29Name },

                    { Segmentation_ModelExecution::kInput3NameHash, Segmentation_ModelExecution::kInput3Name },

                    { Segmentation_ModelExecution::kInput4NameHash, Segmentation_ModelExecution::kInput4Name },

                    { Segmentation_ModelExecution::kInput5NameHash, Segmentation_ModelExecution::kInput5Name },

                    { Segmentation_ModelExecution::kInput6NameHash, Segmentation_ModelExecution::kInput6Name },

                    { Segmentation_ModelExecution::kInput7NameHash, Segmentation_ModelExecution::kInput7Name },

                    { Segmentation_ModelExecution::kInput8NameHash, Segmentation_ModelExecution::kInput8Name },

                    { Segmentation_ModelExecution::kInput9NameHash, Segmentation_ModelExecution::kInput9Name },

                    { Segmentation_ModelExecution::kModelVersionNameHash, Segmentation_ModelExecution::kModelVersionName },

                    { Segmentation_ModelExecution::kOptimizationTargetNameHash, Segmentation_ModelExecution::kOptimizationTargetName },

                    { Segmentation_ModelExecution::kOutputDelaySecNameHash, Segmentation_ModelExecution::kOutputDelaySecName },

                    { Segmentation_ModelExecution::kPredictionResultNameHash, Segmentation_ModelExecution::kPredictionResultName },

                    { Segmentation_ModelExecution::kSelectionResultNameHash, Segmentation_ModelExecution::kSelectionResultName },

                } } },

        { UINT64_C(9684160219705289407),
            { SharedHighlights_LinkGenerated::kEntryName,
                {

                    { SharedHighlights_LinkGenerated::kErrorNameHash, SharedHighlights_LinkGenerated::kErrorName },

                    { SharedHighlights_LinkGenerated::kSuccessNameHash, SharedHighlights_LinkGenerated::kSuccessName },

                } } },

        { UINT64_C(386901924898439243),
            { SharedHighlights_LinkGenerated_Requested::kEntryName,
                {

                    { SharedHighlights_LinkGenerated_Requested::kErrorNameHash, SharedHighlights_LinkGenerated_Requested::kErrorName },

                    { SharedHighlights_LinkGenerated_Requested::kSuccessNameHash, SharedHighlights_LinkGenerated_Requested::kSuccessName },

                } } },

        { UINT64_C(11756915687522041272),
            { SharedHighlights_LinkOpened::kEntryName,
                {

                    { SharedHighlights_LinkOpened::kSourceNameHash, SharedHighlights_LinkOpened::kSourceName },

                    { SharedHighlights_LinkOpened::kSuccessNameHash, SharedHighlights_LinkOpened::kSuccessName },

                } } },

        { UINT64_C(13674128907128689363),
            { Sharing_ClickToCall::kEntryName,
                {

                    { Sharing_ClickToCall::kEntryPointNameHash, Sharing_ClickToCall::kEntryPointName },

                    { Sharing_ClickToCall::kHasAppsNameHash, Sharing_ClickToCall::kHasAppsName },

                    { Sharing_ClickToCall::kHasDevicesNameHash, Sharing_ClickToCall::kHasDevicesName },

                    { Sharing_ClickToCall::kSelectionNameHash, Sharing_ClickToCall::kSelectionName },

                } } },

        { UINT64_C(3949460549124608133),
            { Shopping_CartExtraction::kEntryName,
                {

                    { Shopping_CartExtraction::kExtractionElapsedTimeNameHash, Shopping_CartExtraction::kExtractionElapsedTimeName },

                    { Shopping_CartExtraction::kExtractionExecutionTimeNameHash, Shopping_CartExtraction::kExtractionExecutionTimeName },

                    { Shopping_CartExtraction::kExtractionLongestTaskTimeNameHash, Shopping_CartExtraction::kExtractionLongestTaskTimeName },

                    { Shopping_CartExtraction::kExtractionTimedOutNameHash, Shopping_CartExtraction::kExtractionTimedOutName },

                    { Shopping_CartExtraction::kExtractionTotalTasksTimeNameHash, Shopping_CartExtraction::kExtractionTotalTasksTimeName },

                } } },

        { UINT64_C(15978989974993672382),
            { Shopping_ChromeCart::kEntryName,
                {

                    { Shopping_ChromeCart::kVisitCartNameHash, Shopping_ChromeCart::kVisitCartName },

                } } },

        { UINT64_C(3010088505008297297),
            { Shopping_FormSubmitted::kEntryName,
                {

                    { Shopping_FormSubmitted::kIsTransactionNameHash, Shopping_FormSubmitted::kIsTransactionName },

                } } },

        { UINT64_C(5357508630854566377),
            { Shopping_MerchantTrust_DataAvailable::kEntryName,
                {

                    { Shopping_MerchantTrust_DataAvailable::kDataAvailableNameHash, Shopping_MerchantTrust_DataAvailable::kDataAvailableName },

                } } },

        { UINT64_C(14995105157617764468),
            { Shopping_MerchantTrust_MessageClicked::kEntryName,
                {

                    { Shopping_MerchantTrust_MessageClicked::kHasOccurredNameHash, Shopping_MerchantTrust_MessageClicked::kHasOccurredName },

                } } },

        { UINT64_C(16840045675093743647),
            { Shopping_MerchantTrust_MessageSeen::kEntryName,
                {

                    { Shopping_MerchantTrust_MessageSeen::kHasOccurredNameHash, Shopping_MerchantTrust_MessageSeen::kHasOccurredName },

                } } },

        { UINT64_C(10655844918945147363),
            { Shopping_MerchantTrust_RowClicked::kEntryName,
                {

                    { Shopping_MerchantTrust_RowClicked::kHasOccurredNameHash, Shopping_MerchantTrust_RowClicked::kHasOccurredName },

                } } },

        { UINT64_C(4482961312405396574),
            { Shopping_MerchantTrust_RowSeen::kEntryName,
                {

                    { Shopping_MerchantTrust_RowSeen::kHasOccurredNameHash, Shopping_MerchantTrust_RowSeen::kHasOccurredName },

                } } },

        { UINT64_C(16734271994830574968),
            { Shopping_WillSendRequest::kEntryName,
                {

                    { Shopping_WillSendRequest::kIsAddToCartNameHash, Shopping_WillSendRequest::kIsAddToCartName },

                } } },

        { UINT64_C(18163040957371490481),
            { SmartCharging::kEntryName,
                {

                    { SmartCharging::kBatteryPercentageNameHash, SmartCharging::kBatteryPercentageName },

                    { SmartCharging::kBatteryPercentageBeforeLastChargeNameHash, SmartCharging::kBatteryPercentageBeforeLastChargeName },

                    { SmartCharging::kBatteryPercentageOfLastChargeNameHash, SmartCharging::kBatteryPercentageOfLastChargeName },

                    { SmartCharging::kDayOfMonthNameHash, SmartCharging::kDayOfMonthName },

                    { SmartCharging::kDayOfWeekNameHash, SmartCharging::kDayOfWeekName },

                    { SmartCharging::kDeviceModeNameHash, SmartCharging::kDeviceModeName },

                    { SmartCharging::kDeviceTypeNameHash, SmartCharging::kDeviceTypeName },

                    { SmartCharging::kDurationOfLastChargeNameHash, SmartCharging::kDurationOfLastChargeName },

                    { SmartCharging::kDurationRecentAudioPlayingNameHash, SmartCharging::kDurationRecentAudioPlayingName },

                    { SmartCharging::kDurationRecentVideoPlayingNameHash, SmartCharging::kDurationRecentVideoPlayingName },

                    { SmartCharging::kEventIdNameHash, SmartCharging::kEventIdName },

                    { SmartCharging::kHaltFromLastChargeNameHash, SmartCharging::kHaltFromLastChargeName },

                    { SmartCharging::kIsChargingNameHash, SmartCharging::kIsChargingName },

                    { SmartCharging::kMonthNameHash, SmartCharging::kMonthName },

                    { SmartCharging::kNumRecentKeyEventsNameHash, SmartCharging::kNumRecentKeyEventsName },

                    { SmartCharging::kNumRecentMouseEventsNameHash, SmartCharging::kNumRecentMouseEventsName },

                    { SmartCharging::kNumRecentStylusEventsNameHash, SmartCharging::kNumRecentStylusEventsName },

                    { SmartCharging::kNumRecentTouchEventsNameHash, SmartCharging::kNumRecentTouchEventsName },

                    { SmartCharging::kReasonNameHash, SmartCharging::kReasonName },

                    { SmartCharging::kScreenBrightnessPercentNameHash, SmartCharging::kScreenBrightnessPercentName },

                    { SmartCharging::kTimeOfTheDayNameHash, SmartCharging::kTimeOfTheDayName },

                    { SmartCharging::kTimeSinceLastChargeNameHash, SmartCharging::kTimeSinceLastChargeName },

                    { SmartCharging::kTimezoneDifferenceFromLastChargeNameHash, SmartCharging::kTimezoneDifferenceFromLastChargeName },

                    { SmartCharging::kVoltageNameHash, SmartCharging::kVoltageName },

                } } },

        { UINT64_C(16019904587509461311),
            { SMSReceiver::kEntryName,
                {

                    { SMSReceiver::kIsCrossOriginFrameNameHash, SMSReceiver::kIsCrossOriginFrameName },

                    { SMSReceiver::kOutcomeNameHash, SMSReceiver::kOutcomeName },

                    { SMSReceiver::kSmsParsingStatusNameHash, SMSReceiver::kSmsParsingStatusName },

                    { SMSReceiver::kTimeSmsReceiveMsNameHash, SMSReceiver::kTimeSmsReceiveMsName },

                    { SMSReceiver::kTimeSuccessMsNameHash, SMSReceiver::kTimeSuccessMsName },

                    { SMSReceiver::kTimeUserCancelMsNameHash, SMSReceiver::kTimeUserCancelMsName },

                } } },

        { UINT64_C(15265502850009039364),
            { SSL_MixedContentShown2::kEntryName,
                {

                    { SSL_MixedContentShown2::kTypeNameHash, SSL_MixedContentShown2::kTypeName },

                } } },

        { UINT64_C(16234573202714536926),
            { SubresourceFilter::kEntryName,
                {

                    { SubresourceFilter::kActivationDecisionNameHash, SubresourceFilter::kActivationDecisionName },

                    { SubresourceFilter::kDryRunNameHash, SubresourceFilter::kDryRunName },

                    { SubresourceFilter::kEnforcementRedirectPositionNameHash, SubresourceFilter::kEnforcementRedirectPositionName },

                } } },

        { UINT64_C(7915254855590561221),
            { SubresourceRedirect_PublicSrcVideoCompression::kEntryName,
                {

                    { SubresourceRedirect_PublicSrcVideoCompression::kFullContentLengthNameHash, SubresourceRedirect_PublicSrcVideoCompression::kFullContentLengthName },

                    { SubresourceRedirect_PublicSrcVideoCompression::kSubresourceRedirectResultNameHash,
                        SubresourceRedirect_PublicSrcVideoCompression::kSubresourceRedirectResultName },

                } } },

        { UINT64_C(18395820288494961196),
            { Tab_RendererOOM::kEntryName,
                {

                    { Tab_RendererOOM::kTimeSinceLastNavigationNameHash, Tab_RendererOOM::kTimeSinceLastNavigationName },

                } } },

        { UINT64_C(4107587426159302168),
            { Tab_Screenshot::kEntryName,
                {

                    { Tab_Screenshot::kHasOccurredNameHash, Tab_Screenshot::kHasOccurredName },

                } } },

        { UINT64_C(6962158576008124011),
            { TabManager_Background_FirstAlertFired::kEntryName,
                {

                    { TabManager_Background_FirstAlertFired::kIsMainFrameNameHash, TabManager_Background_FirstAlertFired::kIsMainFrameName },

                    { TabManager_Background_FirstAlertFired::kTimeFromBackgroundedNameHash, TabManager_Background_FirstAlertFired::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(6253115585121265178),
            { TabManager_Background_FirstAudioStarts::kEntryName,
                {

                    { TabManager_Background_FirstAudioStarts::kIsMainFrameNameHash, TabManager_Background_FirstAudioStarts::kIsMainFrameName },

                    { TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedNameHash, TabManager_Background_FirstAudioStarts::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(7684352713481018374),
            { TabManager_Background_FirstFaviconUpdated::kEntryName,
                {

                    { TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedNameHash, TabManager_Background_FirstFaviconUpdated::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(5800172692978642430),
            { TabManager_Background_FirstNonPersistentNotificationCreated::kEntryName,
                {

                    { TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameNameHash,
                        TabManager_Background_FirstNonPersistentNotificationCreated::kIsMainFrameName },

                    { TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedNameHash,
                        TabManager_Background_FirstNonPersistentNotificationCreated::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(13224923626166210718),
            { TabManager_Background_FirstTitleUpdated::kEntryName,
                {

                    { TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedNameHash, TabManager_Background_FirstTitleUpdated::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(11823633373787678555),
            { TabManager_Background_ForegroundedOrClosed::kEntryName,
                {

                    { TabManager_Background_ForegroundedOrClosed::kIsDiscardedNameHash, TabManager_Background_ForegroundedOrClosed::kIsDiscardedName },

                    { TabManager_Background_ForegroundedOrClosed::kIsForegroundedNameHash, TabManager_Background_ForegroundedOrClosed::kIsForegroundedName },

                    { TabManager_Background_ForegroundedOrClosed::kLabelIdNameHash, TabManager_Background_ForegroundedOrClosed::kLabelIdName },

                    { TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedNameHash, TabManager_Background_ForegroundedOrClosed::kTimeFromBackgroundedName },

                } } },

        { UINT64_C(5089020187687107285),
            { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kEntryName,
                {

                    { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountNameHash,
                        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabLoadingCountName },

                    { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdNameHash,
                        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabOpeningSessionIdName },

                    { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountNameHash,
                        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kBackgroundTabPendingCountName },

                    { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdNameHash,
                        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSequenceIdName },

                    { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountNameHash,
                        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kSystemTabCountName },

                    { TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash,
                        TabManager_Experimental_BackgroundTabOpening_TabSwitchLoadStopped::kTabSwitchLoadTimeName },

                } } },

        { UINT64_C(5185149670019600507),
            { TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kEntryName,
                {

                    { TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountNameHash,
                        TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSessionRestoreTabCountName },

                    { TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountNameHash,
                        TabManager_Experimental_SessionRestore_ForegroundTab_PageLoad::kSystemTabCountName },

                } } },

        { UINT64_C(10989149245696867796),
            { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kEntryName,
                {

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSequenceIdName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreSessionIdName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSessionRestoreTabCountName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kSystemTabCountName },

                    { TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeNameHash,
                        TabManager_Experimental_SessionRestore_TabSwitchLoadStopped::kTabSwitchLoadTimeName },

                } } },

        { UINT64_C(15361214325300303131),
            { TabManager_LifecycleStateChange::kEntryName,
                {

                    { TabManager_LifecycleStateChange::kFailureGlobalDisallowlistNameHash, TabManager_LifecycleStateChange::kFailureGlobalDisallowlistName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicAudioNameHash, TabManager_LifecycleStateChange::kFailureHeuristicAudioName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicFaviconNameHash, TabManager_LifecycleStateChange::kFailureHeuristicFaviconName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationNameHash,
                        TabManager_LifecycleStateChange::kFailureHeuristicInsufficientObservationName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicNotificationsNameHash, TabManager_LifecycleStateChange::kFailureHeuristicNotificationsName },

                    { TabManager_LifecycleStateChange::kFailureHeuristicTitleNameHash, TabManager_LifecycleStateChange::kFailureHeuristicTitleName },

                    { TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutNameHash,
                        TabManager_LifecycleStateChange::kFailureLifecyclesEnterprisePolicyOptOutName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateCapturingNameHash, TabManager_LifecycleStateChange::kFailureLiveStateCapturingName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureNameHash, TabManager_LifecycleStateChange::kFailureLiveStateDesktopCaptureName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenNameHash, TabManager_LifecycleStateChange::kFailureLiveStateDevToolsOpenName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedNameHash, TabManager_LifecycleStateChange::kFailureLiveStateExtensionDisallowedName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateFormEntryNameHash, TabManager_LifecycleStateChange::kFailureLiveStateFormEntryName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateHasNotificationsPermissionName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateIsPDFNameHash, TabManager_LifecycleStateChange::kFailureLiveStateIsPDFName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateMirroringNameHash, TabManager_LifecycleStateChange::kFailureLiveStateMirroringName },

                    { TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioNameHash, TabManager_LifecycleStateChange::kFailureLiveStatePlayingAudioName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceNameHash,
                        TabManager_LifecycleStateChange::kFailureLiveStateSharingBrowsingInstanceName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingBluetoothName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingIndexedDBLockName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingWebLockName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingWebSocketsName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBNameHash, TabManager_LifecycleStateChange::kFailureLiveStateUsingWebUSBName },

                    { TabManager_LifecycleStateChange::kFailureLiveStateVisibleNameHash, TabManager_LifecycleStateChange::kFailureLiveStateVisibleName },

                    { TabManager_LifecycleStateChange::kFailureLiveWebAppNameHash, TabManager_LifecycleStateChange::kFailureLiveWebAppName },

                    { TabManager_LifecycleStateChange::kFailureOriginTrialOptOutNameHash, TabManager_LifecycleStateChange::kFailureOriginTrialOptOutName },

                    { TabManager_LifecycleStateChange::kFailureOriginTrialUnknownNameHash, TabManager_LifecycleStateChange::kFailureOriginTrialUnknownName },

                    { TabManager_LifecycleStateChange::kLifecycleStateChangeReasonNameHash, TabManager_LifecycleStateChange::kLifecycleStateChangeReasonName },

                    { TabManager_LifecycleStateChange::kNewLifecycleStateNameHash, TabManager_LifecycleStateChange::kNewLifecycleStateName },

                    { TabManager_LifecycleStateChange::kOldLifecycleStateNameHash, TabManager_LifecycleStateChange::kOldLifecycleStateName },

                    { TabManager_LifecycleStateChange::kOutcomeNameHash, TabManager_LifecycleStateChange::kOutcomeName },

                    { TabManager_LifecycleStateChange::kSuccessGlobalAllowlistNameHash, TabManager_LifecycleStateChange::kSuccessGlobalAllowlistName },

                    { TabManager_LifecycleStateChange::kSuccessHeuristicNameHash, TabManager_LifecycleStateChange::kSuccessHeuristicName },

                    { TabManager_LifecycleStateChange::kSuccessOriginTrialOptInNameHash, TabManager_LifecycleStateChange::kSuccessOriginTrialOptInName },

                    { TabManager_LifecycleStateChange::kTimeSinceNavigationMsNameHash, TabManager_LifecycleStateChange::kTimeSinceNavigationMsName },

                    { TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsNameHash, TabManager_LifecycleStateChange::kTimeSinceVisibilityStateChangeMsName },

                    { TabManager_LifecycleStateChange::kTransitionForcedNameHash, TabManager_LifecycleStateChange::kTransitionForcedName },

                    { TabManager_LifecycleStateChange::kVisibilityStateNameHash, TabManager_LifecycleStateChange::kVisibilityStateName },

                } } },

        { UINT64_C(8999972273877232390),
            { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kEntryName,
                {

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kExpectedTaskQueueingDurationName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSequenceIdName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreSessionIdName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSessionRestoreTabCountName },

                    { TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountNameHash,
                        TabManager_SessionRestore_ForegroundTab_ExpectedTaskQueueingDurationInfo::kSystemTabCountName },

                } } },

        { UINT64_C(16307465990132225428),
            { TabManager_TabLifetime::kEntryName,
                {

                    { TabManager_TabLifetime::kTimeSinceNavigationNameHash, TabManager_TabLifetime::kTimeSinceNavigationName },

                } } },

        { UINT64_C(16400979786435208530),
            { TabManager_TabMetrics::kEntryName,
                {

                    { TabManager_TabMetrics::kContentTypeNameHash, TabManager_TabMetrics::kContentTypeName },

                    { TabManager_TabMetrics::kDefaultProtocolHandlerNameHash, TabManager_TabMetrics::kDefaultProtocolHandlerName },

                    { TabManager_TabMetrics::kHasBeforeUnloadHandlerNameHash, TabManager_TabMetrics::kHasBeforeUnloadHandlerName },

                    { TabManager_TabMetrics::kHasFormEntryNameHash, TabManager_TabMetrics::kHasFormEntryName },

                    { TabManager_TabMetrics::kIsExtensionProtectedNameHash, TabManager_TabMetrics::kIsExtensionProtectedName },

                    { TabManager_TabMetrics::kIsPinnedNameHash, TabManager_TabMetrics::kIsPinnedName },

                    { TabManager_TabMetrics::kKeyEventCountNameHash, TabManager_TabMetrics::kKeyEventCountName },

                    { TabManager_TabMetrics::kLabelIdNameHash, TabManager_TabMetrics::kLabelIdName },

                    { TabManager_TabMetrics::kMouseEventCountNameHash, TabManager_TabMetrics::kMouseEventCountName },

                    { TabManager_TabMetrics::kMRUIndexNameHash, TabManager_TabMetrics::kMRUIndexName },

                    { TabManager_TabMetrics::kNavigationEntryCountNameHash, TabManager_TabMetrics::kNavigationEntryCountName },

                    { TabManager_TabMetrics::kNumReactivationBeforeNameHash, TabManager_TabMetrics::kNumReactivationBeforeName },

                    { TabManager_TabMetrics::kPageTransitionCoreTypeNameHash, TabManager_TabMetrics::kPageTransitionCoreTypeName },

                    { TabManager_TabMetrics::kPageTransitionFromAddressBarNameHash, TabManager_TabMetrics::kPageTransitionFromAddressBarName },

                    { TabManager_TabMetrics::kPageTransitionIsRedirectNameHash, TabManager_TabMetrics::kPageTransitionIsRedirectName },

                    { TabManager_TabMetrics::kQueryIdNameHash, TabManager_TabMetrics::kQueryIdName },

                    { TabManager_TabMetrics::kSiteEngagementScoreNameHash, TabManager_TabMetrics::kSiteEngagementScoreName },

                    { TabManager_TabMetrics::kTimeFromBackgroundedNameHash, TabManager_TabMetrics::kTimeFromBackgroundedName },

                    { TabManager_TabMetrics::kTotalTabCountNameHash, TabManager_TabMetrics::kTotalTabCountName },

                    { TabManager_TabMetrics::kTouchEventCountNameHash, TabManager_TabMetrics::kTouchEventCountName },

                    { TabManager_TabMetrics::kWasRecentlyAudibleNameHash, TabManager_TabMetrics::kWasRecentlyAudibleName },

                    { TabManager_TabMetrics::kWindowIsActiveNameHash, TabManager_TabMetrics::kWindowIsActiveName },

                    { TabManager_TabMetrics::kWindowShowStateNameHash, TabManager_TabMetrics::kWindowShowStateName },

                    { TabManager_TabMetrics::kWindowTabCountNameHash, TabManager_TabMetrics::kWindowTabCountName },

                    { TabManager_TabMetrics::kWindowTypeNameHash, TabManager_TabMetrics::kWindowTypeName },

                } } },

        { UINT64_C(12562637272871338124),
            { TabManager_WindowMetrics::kEntryName,
                {

                    { TabManager_WindowMetrics::kIsActiveNameHash, TabManager_WindowMetrics::kIsActiveName },

                    { TabManager_WindowMetrics::kShowStateNameHash, TabManager_WindowMetrics::kShowStateName },

                    { TabManager_WindowMetrics::kTabCountNameHash, TabManager_WindowMetrics::kTabCountName },

                    { TabManager_WindowMetrics::kTypeNameHash, TabManager_WindowMetrics::kTypeName },

                    { TabManager_WindowMetrics::kWindowIdNameHash, TabManager_WindowMetrics::kWindowIdName },

                } } },

        { UINT64_C(4093974732248698099),
            { TopToolbar_Share::kEntryName,
                {

                    { TopToolbar_Share::kHasOccurredNameHash, TopToolbar_Share::kHasOccurredName },

                } } },

        { UINT64_C(833305494688204602),
            { TouchToFill_Shown::kEntryName,
                {

                    { TouchToFill_Shown::kUserActionNameHash, TouchToFill_Shown::kUserActionName },

                } } },

        { UINT64_C(11228777951422985451),
            { TouchToFill_SubmissionReadiness::kEntryName,
                {

                    { TouchToFill_SubmissionReadiness::kSubmissionReadinessNameHash, TouchToFill_SubmissionReadiness::kSubmissionReadinessName },

                } } },

        { UINT64_C(5045482485607039969),
            { TouchToFill_TimeToSuccessfulLogin::kEntryName,
                {

                    { TouchToFill_TimeToSuccessfulLogin::kTimeToSuccessfulLoginNameHash, TouchToFill_TimeToSuccessfulLogin::kTimeToSuccessfulLoginName },

                } } },

        { UINT64_C(16054416016310256565),
            { Translate::kEntryName,
                {

                    { Translate::kAcceptCountNameHash, Translate::kAcceptCountName },

                    { Translate::kCountryNameHash, Translate::kCountryName },

                    { Translate::kDeclineCountNameHash, Translate::kDeclineCountName },

                    { Translate::kEventTypeNameHash, Translate::kEventTypeName },

                    { Translate::kIgnoreCountNameHash, Translate::kIgnoreCountName },

                    { Translate::kRankerResponseNameHash, Translate::kRankerResponseName },

                    { Translate::kRankerVersionNameHash, Translate::kRankerVersionName },

                    { Translate::kSourceLanguageNameHash, Translate::kSourceLanguageName },

                    { Translate::kTargetLanguageNameHash, Translate::kTargetLanguageName },

                } } },

        { UINT64_C(5132773550783566872),
            { TranslatePageLoad::kEntryName,
                {

                    { TranslatePageLoad::kFinalSourceLanguageNameHash, TranslatePageLoad::kFinalSourceLanguageName },

                    { TranslatePageLoad::kFinalStateNameHash, TranslatePageLoad::kFinalStateName },

                    { TranslatePageLoad::kFinalTargetLanguageNameHash, TranslatePageLoad::kFinalTargetLanguageName },

                    { TranslatePageLoad::kFirstTranslateErrorNameHash, TranslatePageLoad::kFirstTranslateErrorName },

                    { TranslatePageLoad::kFirstUIInteractionNameHash, TranslatePageLoad::kFirstUIInteractionName },

                    { TranslatePageLoad::kHTMLContentLanguageNameHash, TranslatePageLoad::kHTMLContentLanguageName },

                    { TranslatePageLoad::kHTMLDocumentLanguageNameHash, TranslatePageLoad::kHTMLDocumentLanguageName },

                    { TranslatePageLoad::kInitialSourceLanguageNameHash, TranslatePageLoad::kInitialSourceLanguageName },

                    { TranslatePageLoad::kInitialSourceLanguageInContentLanguagesNameHash, TranslatePageLoad::kInitialSourceLanguageInContentLanguagesName },

                    { TranslatePageLoad::kInitialStateNameHash, TranslatePageLoad::kInitialStateName },

                    { TranslatePageLoad::kInitialTargetLanguageNameHash, TranslatePageLoad::kInitialTargetLanguageName },

                    { TranslatePageLoad::kMaxTimeToTranslateNameHash, TranslatePageLoad::kMaxTimeToTranslateName },

                    { TranslatePageLoad::kModelDetectedLanguageNameHash, TranslatePageLoad::kModelDetectedLanguageName },

                    { TranslatePageLoad::kModelDetectionReliabilityScoreNameHash, TranslatePageLoad::kModelDetectionReliabilityScoreName },

                    { TranslatePageLoad::kNumReversionsNameHash, TranslatePageLoad::kNumReversionsName },

                    { TranslatePageLoad::kNumTargetLanguageChangesNameHash, TranslatePageLoad::kNumTargetLanguageChangesName },

                    { TranslatePageLoad::kNumTranslateErrorsNameHash, TranslatePageLoad::kNumTranslateErrorsName },

                    { TranslatePageLoad::kNumTranslationsNameHash, TranslatePageLoad::kNumTranslationsName },

                    { TranslatePageLoad::kNumUIInteractionsNameHash, TranslatePageLoad::kNumUIInteractionsName },

                    { TranslatePageLoad::kRankerDecisionNameHash, TranslatePageLoad::kRankerDecisionName },

                    { TranslatePageLoad::kRankerVersionNameHash, TranslatePageLoad::kRankerVersionName },

                    { TranslatePageLoad::kSequenceNumberNameHash, TranslatePageLoad::kSequenceNumberName },

                    { TranslatePageLoad::kTotalTimeNotTranslatedNameHash, TranslatePageLoad::kTotalTimeNotTranslatedName },

                    { TranslatePageLoad::kTotalTimeTranslatedNameHash, TranslatePageLoad::kTotalTimeTranslatedName },

                    { TranslatePageLoad::kTriggerDecisionNameHash, TranslatePageLoad::kTriggerDecisionName },

                    { TranslatePageLoad::kWasContentEmptyNameHash, TranslatePageLoad::kWasContentEmptyName },

                } } },

        { UINT64_C(7060301545121378834),
            { TrustedWebActivity_LocationDelegation::kEntryName,
                {

                    { TrustedWebActivity_LocationDelegation::kEnrolledNameHash, TrustedWebActivity_LocationDelegation::kEnrolledName },

                } } },

        { UINT64_C(15381255782093849665),
            { TrustedWebActivity_Open::kEntryName,
                {

                    { TrustedWebActivity_Open::kHasOccurredNameHash, TrustedWebActivity_Open::kHasOccurredName },

                } } },

        { UINT64_C(11436344642124934410),
            { TrustedWebActivity_QualityEnforcementViolation::kEntryName,
                {

                    { TrustedWebActivity_QualityEnforcementViolation::kViolationTypeNameHash, TrustedWebActivity_QualityEnforcementViolation::kViolationTypeName },

                } } },

        { UINT64_C(12543039456478655125),
            { Unload::kEntryName,
                {

                    { Unload::kBeforeUnloadDurationNameHash, Unload::kBeforeUnloadDurationName },

                    { Unload::kBeforeUnloadQueueingDurationNameHash, Unload::kBeforeUnloadQueueingDurationName },

                    { Unload::kBeforeUnloadToCommit_CrossProcessNameHash, Unload::kBeforeUnloadToCommit_CrossProcessName },

                    { Unload::kBeforeUnloadToCommit_SameProcessNameHash, Unload::kBeforeUnloadToCommit_SameProcessName },

                    { Unload::kUnloadDurationNameHash, Unload::kUnloadDurationName },

                    { Unload::kUnloadQueueingDurationNameHash, Unload::kUnloadQueueingDurationName },

                } } },

        { UINT64_C(2395897864454822590),
            { UserActivity::kEntryName,
                {

                    { UserActivity::kBatteryPercentNameHash, UserActivity::kBatteryPercentName },

                    { UserActivity::kDeviceManagementNameHash, UserActivity::kDeviceManagementName },

                    { UserActivity::kDeviceModeNameHash, UserActivity::kDeviceModeName },

                    { UserActivity::kDeviceTypeNameHash, UserActivity::kDeviceTypeName },

                    { UserActivity::kEventLogDurationNameHash, UserActivity::kEventLogDurationName },

                    { UserActivity::kEventReasonNameHash, UserActivity::kEventReasonName },

                    { UserActivity::kEventTypeNameHash, UserActivity::kEventTypeName },

                    { UserActivity::kKeyEventsInLastHourNameHash, UserActivity::kKeyEventsInLastHourName },

                    { UserActivity::kLastActivityDayNameHash, UserActivity::kLastActivityDayName },

                    { UserActivity::kLastActivityTimeNameHash, UserActivity::kLastActivityTimeName },

                    { UserActivity::kLastUserActivityTimeNameHash, UserActivity::kLastUserActivityTimeName },

                    { UserActivity::kModelAppliedNameHash, UserActivity::kModelAppliedName },

                    { UserActivity::kModelDecisionThresholdNameHash, UserActivity::kModelDecisionThresholdName },

                    { UserActivity::kModelInactivityScoreNameHash, UserActivity::kModelInactivityScoreName },

                    { UserActivity::kModelResponseNameHash, UserActivity::kModelResponseName },

                    { UserActivity::kMouseEventsInLastHourNameHash, UserActivity::kMouseEventsInLastHourName },

                    { UserActivity::kOnBatteryNameHash, UserActivity::kOnBatteryName },

                    { UserActivity::kPreviousNegativeActionsCountNameHash, UserActivity::kPreviousNegativeActionsCountName },

                    { UserActivity::kPreviousPositiveActionsCountNameHash, UserActivity::kPreviousPositiveActionsCountName },

                    { UserActivity::kRecentTimeActiveNameHash, UserActivity::kRecentTimeActiveName },

                    { UserActivity::kRecentVideoPlayingTimeNameHash, UserActivity::kRecentVideoPlayingTimeName },

                    { UserActivity::kScreenDimDelayNameHash, UserActivity::kScreenDimDelayName },

                    { UserActivity::kScreenDimmedInitiallyNameHash, UserActivity::kScreenDimmedInitiallyName },

                    { UserActivity::kScreenDimOccurredNameHash, UserActivity::kScreenDimOccurredName },

                    { UserActivity::kScreenDimToOffDelayNameHash, UserActivity::kScreenDimToOffDelayName },

                    { UserActivity::kScreenLockedInitiallyNameHash, UserActivity::kScreenLockedInitiallyName },

                    { UserActivity::kScreenLockOccurredNameHash, UserActivity::kScreenLockOccurredName },

                    { UserActivity::kScreenOffInitiallyNameHash, UserActivity::kScreenOffInitiallyName },

                    { UserActivity::kScreenOffOccurredNameHash, UserActivity::kScreenOffOccurredName },

                    { UserActivity::kSequenceIdNameHash, UserActivity::kSequenceIdName },

                    { UserActivity::kTimeSinceLastKeyNameHash, UserActivity::kTimeSinceLastKeyName },

                    { UserActivity::kTimeSinceLastMouseNameHash, UserActivity::kTimeSinceLastMouseName },

                    { UserActivity::kTimeSinceLastTouchNameHash, UserActivity::kTimeSinceLastTouchName },

                    { UserActivity::kTimeSinceLastVideoEndedNameHash, UserActivity::kTimeSinceLastVideoEndedName },

                    { UserActivity::kTouchEventsInLastHourNameHash, UserActivity::kTouchEventsInLastHourName },

                } } },

        { UINT64_C(13821826834442202003),
            { UserActivityId::kEntryName,
                {

                    { UserActivityId::kActivityIdNameHash, UserActivityId::kActivityIdName },

                    { UserActivityId::kContentTypeNameHash, UserActivityId::kContentTypeName },

                    { UserActivityId::kHasFormEntryNameHash, UserActivityId::kHasFormEntryName },

                    { UserActivityId::kIsActiveNameHash, UserActivityId::kIsActiveName },

                    { UserActivityId::kIsBrowserFocusedNameHash, UserActivityId::kIsBrowserFocusedName },

                    { UserActivityId::kIsBrowserVisibleNameHash, UserActivityId::kIsBrowserVisibleName },

                    { UserActivityId::kIsTopmostBrowserNameHash, UserActivityId::kIsTopmostBrowserName },

                    { UserActivityId::kSiteEngagementScoreNameHash, UserActivityId::kSiteEngagementScoreName },

                } } },

        { UINT64_C(4221731235635910179),
            { UserPerceivedPageVisit::kEntryName,
                {

                    { UserPerceivedPageVisit::kNotCountedForCoreWebVitalsNameHash, UserPerceivedPageVisit::kNotCountedForCoreWebVitalsName },

                    { UserPerceivedPageVisit::kPageVisitFinalStatusNameHash, UserPerceivedPageVisit::kPageVisitFinalStatusName },

                    { UserPerceivedPageVisit::kUserInitiatedNameHash, UserPerceivedPageVisit::kUserInitiatedName },

                } } },

        { UINT64_C(12666214553193795663),
            { UserSettingsEvent::kEntryName,
                {

                    { UserSettingsEvent::kAccessibilityIdNameHash, UserSettingsEvent::kAccessibilityIdName },

                    { UserSettingsEvent::kBatteryPercentageNameHash, UserSettingsEvent::kBatteryPercentageName },

                    { UserSettingsEvent::kCountryNameHash, UserSettingsEvent::kCountryName },

                    { UserSettingsEvent::kCurrentValueNameHash, UserSettingsEvent::kCurrentValueName },

                    { UserSettingsEvent::kDayOfWeekNameHash, UserSettingsEvent::kDayOfWeekName },

                    { UserSettingsEvent::kDeviceModeNameHash, UserSettingsEvent::kDeviceModeName },

                    { UserSettingsEvent::kDeviceOrientationNameHash, UserSettingsEvent::kDeviceOrientationName },

                    { UserSettingsEvent::kEventIdNameHash, UserSettingsEvent::kEventIdName },

                    { UserSettingsEvent::kHasNightLightScheduleNameHash, UserSettingsEvent::kHasNightLightScheduleName },

                    { UserSettingsEvent::kHasWifiSecurityNameHash, UserSettingsEvent::kHasWifiSecurityName },

                    { UserSettingsEvent::kHourOfDayNameHash, UserSettingsEvent::kHourOfDayName },

                    { UserSettingsEvent::kIsAfterSunsetNameHash, UserSettingsEvent::kIsAfterSunsetName },

                    { UserSettingsEvent::kIsChargingNameHash, UserSettingsEvent::kIsChargingName },

                    { UserSettingsEvent::kIsFromSearchNameHash, UserSettingsEvent::kIsFromSearchName },

                    { UserSettingsEvent::kIsPairedBluetoothDeviceNameHash, UserSettingsEvent::kIsPairedBluetoothDeviceName },

                    { UserSettingsEvent::kIsPlayingAudioNameHash, UserSettingsEvent::kIsPlayingAudioName },

                    { UserSettingsEvent::kIsPlayingVideoNameHash, UserSettingsEvent::kIsPlayingVideoName },

                    { UserSettingsEvent::kIsRecentlyFullscreenNameHash, UserSettingsEvent::kIsRecentlyFullscreenName },

                    { UserSettingsEvent::kIsRecentlyPresentingNameHash, UserSettingsEvent::kIsRecentlyPresentingName },

                    { UserSettingsEvent::kNetworkStatusNameHash, UserSettingsEvent::kNetworkStatusName },

                    { UserSettingsEvent::kPreviousValueNameHash, UserSettingsEvent::kPreviousValueName },

                    { UserSettingsEvent::kSettingIdNameHash, UserSettingsEvent::kSettingIdName },

                    { UserSettingsEvent::kSettingTypeNameHash, UserSettingsEvent::kSettingTypeName },

                    { UserSettingsEvent::kSignalStrengthNameHash, UserSettingsEvent::kSignalStrengthName },

                    { UserSettingsEvent::kTimeSinceLastSettingsChangeNameHash, UserSettingsEvent::kTimeSinceLastSettingsChangeName },

                    { UserSettingsEvent::kUsedCellularInSessionNameHash, UserSettingsEvent::kUsedCellularInSessionName },

                } } },

        { UINT64_C(12143286159580552989),
            { V8_Wasm_ModuleCompiled::kEntryName,
                {

                    { V8_Wasm_ModuleCompiled::kAsyncNameHash, V8_Wasm_ModuleCompiled::kAsyncName },

                    { V8_Wasm_ModuleCompiled::kCachedNameHash, V8_Wasm_ModuleCompiled::kCachedName },

                    { V8_Wasm_ModuleCompiled::kCodeSizeNameHash, V8_Wasm_ModuleCompiled::kCodeSizeName },

                    { V8_Wasm_ModuleCompiled::kDeserializedNameHash, V8_Wasm_ModuleCompiled::kDeserializedName },

                    { V8_Wasm_ModuleCompiled::kLazyNameHash, V8_Wasm_ModuleCompiled::kLazyName },

                    { V8_Wasm_ModuleCompiled::kLiftoffBailoutCountNameHash, V8_Wasm_ModuleCompiled::kLiftoffBailoutCountName },

                    { V8_Wasm_ModuleCompiled::kStreamedNameHash, V8_Wasm_ModuleCompiled::kStreamedName },

                    { V8_Wasm_ModuleCompiled::kSuccessNameHash, V8_Wasm_ModuleCompiled::kSuccessName },

                    { V8_Wasm_ModuleCompiled::kWallClockDurationNameHash, V8_Wasm_ModuleCompiled::kWallClockDurationName },

                } } },

        { UINT64_C(5663155407937554096),
            { V8_Wasm_ModuleDecoded::kEntryName,
                {

                    { V8_Wasm_ModuleDecoded::kFunctionCountNameHash, V8_Wasm_ModuleDecoded::kFunctionCountName },

                    { V8_Wasm_ModuleDecoded::kModuleSizeNameHash, V8_Wasm_ModuleDecoded::kModuleSizeName },

                    { V8_Wasm_ModuleDecoded::kStreamedNameHash, V8_Wasm_ModuleDecoded::kStreamedName },

                    { V8_Wasm_ModuleDecoded::kSuccessNameHash, V8_Wasm_ModuleDecoded::kSuccessName },

                    { V8_Wasm_ModuleDecoded::kWallClockDurationNameHash, V8_Wasm_ModuleDecoded::kWallClockDurationName },

                } } },

        { UINT64_C(15295210720868142566),
            { V8_Wasm_ModuleInstantiated::kEntryName,
                {

                    { V8_Wasm_ModuleInstantiated::kImportedFunctionCountNameHash, V8_Wasm_ModuleInstantiated::kImportedFunctionCountName },

                    { V8_Wasm_ModuleInstantiated::kSuccessNameHash, V8_Wasm_ModuleInstantiated::kSuccessName },

                    { V8_Wasm_ModuleInstantiated::kWallClockDurationNameHash, V8_Wasm_ModuleInstantiated::kWallClockDurationName },

                } } },

        { UINT64_C(2833187735774133395),
            { V8_Wasm_ModuleTieredUp::kEntryName,
                {

                    { V8_Wasm_ModuleTieredUp::kCodeSizeNameHash, V8_Wasm_ModuleTieredUp::kCodeSizeName },

                    { V8_Wasm_ModuleTieredUp::kLazyNameHash, V8_Wasm_ModuleTieredUp::kLazyName },

                    { V8_Wasm_ModuleTieredUp::kWallClockDurationNameHash, V8_Wasm_ModuleTieredUp::kWallClockDurationName },

                } } },

        { UINT64_C(3904325154478962694),
            { VirtualKeyboard_Open::kEntryName,
                {

                    { VirtualKeyboard_Open::kTextInputTypeNameHash, VirtualKeyboard_Open::kTextInputTypeName },

                } } },

        { UINT64_C(12193435703081602033),
            { WebAPK_Install::kEntryName,
                {

                    { WebAPK_Install::kAppVersionNameHash, WebAPK_Install::kAppVersionName },

                    { WebAPK_Install::kDistributorNameHash, WebAPK_Install::kDistributorName },

                    { WebAPK_Install::kInstallNameHash, WebAPK_Install::kInstallName },

                } } },

        { UINT64_C(304278077624055651),
            { WebAPK_SessionEnd::kEntryName,
                {

                    { WebAPK_SessionEnd::kAppVersionNameHash, WebAPK_SessionEnd::kAppVersionName },

                    { WebAPK_SessionEnd::kDistributorNameHash, WebAPK_SessionEnd::kDistributorName },

                    { WebAPK_SessionEnd::kSessionDurationNameHash, WebAPK_SessionEnd::kSessionDurationName },

                } } },

        { UINT64_C(15147671640732652143),
            { WebAPK_Uninstall::kEntryName,
                {

                    { WebAPK_Uninstall::kAppVersionNameHash, WebAPK_Uninstall::kAppVersionName },

                    { WebAPK_Uninstall::kDistributorNameHash, WebAPK_Uninstall::kDistributorName },

                    { WebAPK_Uninstall::kInstalledDurationNameHash, WebAPK_Uninstall::kInstalledDurationName },

                    { WebAPK_Uninstall::kLifetimeLaunchesNameHash, WebAPK_Uninstall::kLifetimeLaunchesName },

                    { WebAPK_Uninstall::kUninstallNameHash, WebAPK_Uninstall::kUninstallName },

                } } },

        { UINT64_C(7419239618516179300),
            { WebAPK_Visit::kEntryName,
                {

                    { WebAPK_Visit::kAppVersionNameHash, WebAPK_Visit::kAppVersionName },

                    { WebAPK_Visit::kDistributorNameHash, WebAPK_Visit::kDistributorName },

                    { WebAPK_Visit::kLaunchNameHash, WebAPK_Visit::kLaunchName },

                    { WebAPK_Visit::kLaunchSourceNameHash, WebAPK_Visit::kLaunchSourceName },

                } } },

        { UINT64_C(17489292060937518703),
            { Webapp_AddToHomeScreen::kEntryName,
                {

                    { Webapp_AddToHomeScreen::kDisplayModeNameHash, Webapp_AddToHomeScreen::kDisplayModeName },

                    { Webapp_AddToHomeScreen::kSameAsManifestStartUrlNameHash, Webapp_AddToHomeScreen::kSameAsManifestStartUrlName },

                    { Webapp_AddToHomeScreen::kShortcutReasonNameHash, Webapp_AddToHomeScreen::kShortcutReasonName },

                } } },

        { UINT64_C(10823086981545979708),
            { WebApp_DailyInteraction::kEntryName,
                {

                    { WebApp_DailyInteraction::kBackgroundDurationNameHash, WebApp_DailyInteraction::kBackgroundDurationName },

                    { WebApp_DailyInteraction::kDisplayModeNameHash, WebApp_DailyInteraction::kDisplayModeName },

                    { WebApp_DailyInteraction::kForegroundDurationNameHash, WebApp_DailyInteraction::kForegroundDurationName },

                    { WebApp_DailyInteraction::kInstalledNameHash, WebApp_DailyInteraction::kInstalledName },

                    { WebApp_DailyInteraction::kInstallSourceNameHash, WebApp_DailyInteraction::kInstallSourceName },

                    { WebApp_DailyInteraction::kNumSessionsNameHash, WebApp_DailyInteraction::kNumSessionsName },

                    { WebApp_DailyInteraction::kPromotableNameHash, WebApp_DailyInteraction::kPromotableName },

                    { WebApp_DailyInteraction::kUsedNameHash, WebApp_DailyInteraction::kUsedName },

                } } },

        { UINT64_C(17612510707700865831),
            { WebOTPImpact::kEntryName,
                {

                    { WebOTPImpact::kPhoneCollectionNameHash, WebOTPImpact::kPhoneCollectionName },

                } } },

        { UINT64_C(6759459948386423184),
            { WebRTC_AddressHarvesting::kEntryName,
                {

                    { WebRTC_AddressHarvesting::kUsagePatternNameHash, WebRTC_AddressHarvesting::kUsagePatternName },

                } } },

        { UINT64_C(7456919696038345904),
            { WebRTC_ComplexSdp::kEntryName,
                {

                    { WebRTC_ComplexSdp::kCategoryNameHash, WebRTC_ComplexSdp::kCategoryName },

                } } },

        { UINT64_C(11030368718596656137),
            { Worker_ClientAdded::kEntryName,
                {

                    { Worker_ClientAdded::kClientSourceIdNameHash, Worker_ClientAdded::kClientSourceIdName },

                    { Worker_ClientAdded::kWorkerTypeNameHash, Worker_ClientAdded::kWorkerTypeName },

                } } },

        { UINT64_C(2966287978545946180),
            { XR_WebXR::kEntryName,
                {

                    { XR_WebXR::kDidGetXRInputSourcesNameHash, XR_WebXR::kDidGetXRInputSourcesName },

                    { XR_WebXR::kDidRequestAvailableDevicesNameHash, XR_WebXR::kDidRequestAvailableDevicesName },

                    { XR_WebXR::kDidRequestPoseNameHash, XR_WebXR::kDidRequestPoseName },

                    { XR_WebXR::kDidRequestPresentationNameHash, XR_WebXR::kDidRequestPresentationName },

                    { XR_WebXR::kDidUseNavigatorXRNameHash, XR_WebXR::kDidUseNavigatorXRName },

                    { XR_WebXR::kReturnedDeviceNameHash, XR_WebXR::kReturnedDeviceName },

                    { XR_WebXR::kReturnedPresentationCapableDeviceNameHash, XR_WebXR::kReturnedPresentationCapableDeviceName },

                } } },

        { UINT64_C(4113953897099533496),
            { XR_WebXR_Session::kEntryName,
                {

                    { XR_WebXR_Session::kDurationNameHash, XR_WebXR_Session::kDurationName },

                    { XR_WebXR_Session::kFeatureRequest_BoundedFloorNameHash, XR_WebXR_Session::kFeatureRequest_BoundedFloorName },

                    { XR_WebXR_Session::kFeatureRequest_LocalNameHash, XR_WebXR_Session::kFeatureRequest_LocalName },

                    { XR_WebXR_Session::kFeatureRequest_LocalFloorNameHash, XR_WebXR_Session::kFeatureRequest_LocalFloorName },

                    { XR_WebXR_Session::kFeatureRequest_UnboundedNameHash, XR_WebXR_Session::kFeatureRequest_UnboundedName },

                    { XR_WebXR_Session::kFeatureRequest_ViewerNameHash, XR_WebXR_Session::kFeatureRequest_ViewerName },

                    { XR_WebXR_Session::kFeatureUse_BoundedFloorNameHash, XR_WebXR_Session::kFeatureUse_BoundedFloorName },

                    { XR_WebXR_Session::kFeatureUse_LocalNameHash, XR_WebXR_Session::kFeatureUse_LocalName },

                    { XR_WebXR_Session::kFeatureUse_LocalFloorNameHash, XR_WebXR_Session::kFeatureUse_LocalFloorName },

                    { XR_WebXR_Session::kFeatureUse_UnboundedNameHash, XR_WebXR_Session::kFeatureUse_UnboundedName },

                    { XR_WebXR_Session::kFeatureUse_ViewerNameHash, XR_WebXR_Session::kFeatureUse_ViewerName },

                    { XR_WebXR_Session::kModeNameHash, XR_WebXR_Session::kModeName },

                } } },

        { UINT64_C(15349576264204541813),
            { XR_WebXR_SessionRequest::kEntryName,
                {

                    { XR_WebXR_SessionRequest::kFeature_BoundedFloorNameHash, XR_WebXR_SessionRequest::kFeature_BoundedFloorName },

                    { XR_WebXR_SessionRequest::kFeature_LocalNameHash, XR_WebXR_SessionRequest::kFeature_LocalName },

                    { XR_WebXR_SessionRequest::kFeature_LocalFloorNameHash, XR_WebXR_SessionRequest::kFeature_LocalFloorName },

                    { XR_WebXR_SessionRequest::kFeature_UnboundedNameHash, XR_WebXR_SessionRequest::kFeature_UnboundedName },

                    { XR_WebXR_SessionRequest::kFeature_ViewerNameHash, XR_WebXR_SessionRequest::kFeature_ViewerName },

                    { XR_WebXR_SessionRequest::kModeNameHash, XR_WebXR_SessionRequest::kModeName },

                    { XR_WebXR_SessionRequest::kStatusNameHash, XR_WebXR_SessionRequest::kStatusName },

                } } },

    };
}

} // namespace builders
} // namespace ukm
