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


#include <windows.h>

#if defined(_M_IX86) || defined(__i386__)
extern "C" __declspec(naked) void PushAllRegistersAndIterateStack(void*, void*, void*)
{
    // Push all callee - saves registers to get them
    // on the stack for conservative stack scanning.
    // We maintain 16 - byte alignment at calls(required on
    // Mac).There is a 4 - byte return address on the stack
    // and we push 28 bytes which maintains 16 - byte alignment
    //; at the call.
    __asm {
        push ebp
        mov ebp, esp
        push ebx
        push esi
        push edi
        ;;// Save 3rd parameter(IterateStackCallback).
        mov ecx, [esp + 28]
        ;;// Pass 3rd parameter as esp(stack pointer).
        push esp
        ;;// Pass 2nd parameter(StackVisitor*).
        push[esp + 28]
        ;;// Pass 1st parameter(Stack*).
        push[esp + 28]
        call ecx
        ;;// Pop the callee - saved registers.
        add esp, 24
        ;;// Restore rbp as it was used as frame pointer.
        pop ebp
        ret
    }
}

#elif defined(_M_X64) || defined(__x86_64__)

const unsigned char kPushAllRegistersShellCode[] = {
    0x55,                                                 // push    rbp
    0x48, 0x89, 0xE5,                                     // mov     rbp, rsp
    0x68, 0xCD, 0xCD, 0xCD, 0x00,                         // push    0CDCDCDh
    0x56,                                                 // push    rsi
    0x57,                                                 // push    rdi
    0x53,                                                 // push    rbx
    0x41, 0x54,                                           // push    r12
    0x41, 0x55,                                           // push    r13
    0x41, 0x56,                                           // push    r14
    0x41, 0x57,                                           // push    r15
    0x48, 0x81, 0xEC, 0xA0, 0x00, 0x00, 0x00,             // sub     rsp, 0A0h
    0x66, 0x0F, 0x7F, 0xB4, 0x24, 0x90, 0x00, 0x00, 0x00, // movdqa  xmmword ptr [rsp+90h], xmm6
    0x66, 0x0F, 0x7F, 0xBC, 0x24, 0x80, 0x00, 0x00, 0x00, // movdqa  xmmword ptr [rsp+80h], xmm7
    0x66, 0x44, 0x0F, 0x7F, 0x44, 0x24, 0x70,             // movdqa  xmmword ptr [rsp+70h], xmm8
    0x66, 0x44, 0x0F, 0x7F, 0x4C, 0x24, 0x60,             // movdqa  xmmword ptr [rsp+60h], xmm9
    0x66, 0x44, 0x0F, 0x7F, 0x54, 0x24, 0x50,             // movdqa  xmmword ptr [rsp+50h], xmm10
    0x66, 0x44, 0x0F, 0x7F, 0x5C, 0x24, 0x40,             // movdqa  xmmword ptr [rsp+40h], xmm11
    0x66, 0x44, 0x0F, 0x7F, 0x64, 0x24, 0x30,             // movdqa  xmmword ptr [rsp+30h], xmm12
    0x66, 0x44, 0x0F, 0x7F, 0x6C, 0x24, 0x20,             // movdqa  xmmword ptr [rsp+20h], xmm13
    0x66, 0x44, 0x0F, 0x7F, 0x74, 0x24, 0x10,             // movdqa  xmmword ptr [rsp+10h], xmm14
    0x66, 0x44, 0x0F, 0x7F, 0x3C, 0x24,                   // movdqa  xmmword ptr [rsp], xmm15
    0x4D, 0x89, 0xC1,                                     // mov     r9, r8
    0x49, 0x89, 0xE0,                                     // mov     r8, rsp
    0x41, 0xFF, 0xD1,                                     // call    r9
    //
    0x48, 0x81, 0xC4, 0xE0, 0x00, 0x00, 0x00,             // add     rsp, 0E0h
    0x5D,                                                 // pop     rbp
    0xC3,                                                 // retn
};

using PushAllRegistersCallback = void(*)(void*, void*, void*);
static PushAllRegistersCallback s_PushAllRegistersCallback = nullptr;

void InitPushAllRegistersShellcode()
{
    if (s_PushAllRegistersCallback)
        return;

    void* pushAllRegistersPtr = (void*)kPushAllRegistersShellCode;

    s_PushAllRegistersCallback = (PushAllRegistersCallback)(pushAllRegistersPtr);

    DWORD oldProtect = 0;
    ::VirtualProtect(pushAllRegistersPtr, sizeof(kPushAllRegistersShellCode), PAGE_EXECUTE_READWRITE, &oldProtect);
}

extern "C" void PushAllRegistersAndIterateStack(void* p1, void* p2, void* p3)
{
    InitPushAllRegistersShellcode();
    s_PushAllRegistersCallback(p1, p2, p3);
}
#endif
