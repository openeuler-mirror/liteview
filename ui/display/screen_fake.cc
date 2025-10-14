// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/display/screen_fake.h"

#include "ui/display/display_finder.h"
#include <windows.h>

namespace display {

ScreenFake::ScreenFake()
{
    display_list_.AddOrUpdateDisplay(Display::GetDefaultDisplay(), DisplayList::Type::PRIMARY);
}

ScreenFake::~ScreenFake() { }

gfx::Point ScreenFake::GetCursorScreenPoint()
{
    DebugBreak();
    return gfx::Point();
}

bool ScreenFake::IsWindowUnderCursor(gfx::NativeWindow window)
{
    DebugBreak();
    return false;
}

gfx::NativeWindow ScreenFake::GetWindowAtScreenPoint(const gfx::Point& point)
{
    DebugBreak();
    return nullptr;
}

gfx::NativeWindow ScreenFake::GetLocalProcessWindowAtPoint(const gfx::Point& screen_point, const std::set<gfx::NativeWindow>& ignore)
{
    DebugBreak();
    return nullptr;
}

Display ScreenFake::GetPrimaryDisplay() const
{
    auto iter = display_list_.GetPrimaryDisplayIterator();
    if (iter == display_list_.displays().end())
        return Display::GetDefaultDisplay();
    return *iter;
}

Display ScreenFake::GetDisplayNearestWindow(gfx::NativeWindow window) const
{
    return GetPrimaryDisplay();
}

Display ScreenFake::GetDisplayNearestPoint(const gfx::Point& point) const
{
    DebugBreak();
    return GetPrimaryDisplay();
    //return *FindDisplayNearestPoint(display_list_.displays(), point);
}

int ScreenFake::GetNumDisplays() const
{
    return static_cast<int>(display_list_.displays().size());
}

const std::vector<Display>& ScreenFake::GetAllDisplays() const
{
    return display_list_.displays();
}

Display ScreenFake::GetDisplayMatching(const gfx::Rect& match_rect) const
{
    DebugBreak();
    return GetPrimaryDisplay();
//     if (match_rect.IsEmpty())
//         return GetDisplayNearestPoint(match_rect.origin());
// 
//     const Display* match = FindDisplayWithBiggestIntersection(display_list_.displays(), match_rect);
//     return match ? *match : GetPrimaryDisplay();
}

void ScreenFake::AddObserver(DisplayObserver* observer) 
{ 
    display_list_.AddObserver(observer);
}

void ScreenFake::RemoveObserver(DisplayObserver* observer) 
{ 
    display_list_.RemoveObserver(observer);
}

bool ScreenFake::HasDisplayObservers() const
{
    return !display_list_.observers()->empty();
}

void ScreenFake::SetPanelRotationForTesting(int64_t display_id, Display::Rotation rotation)
{
    Display display = *display_list_.FindDisplayById(display_id);
    display.set_panel_rotation(rotation);
    ProcessDisplayChanged(display, true);
}

void ScreenFake::ProcessDisplayChanged(const Display& changed_display, bool is_primary)
{
    DebugBreak();
//     if (display_list_.FindDisplayById(changed_display.id()) == display_list_.displays().end()) {
//         display_list_.AddDisplay(changed_display, is_primary ? DisplayList::Type::PRIMARY : DisplayList::Type::NOT_PRIMARY);
//         return;
//     }
//     display_list_.UpdateDisplay(changed_display, is_primary ? DisplayList::Type::PRIMARY : DisplayList::Type::NOT_PRIMARY);
}

} // namespace display
