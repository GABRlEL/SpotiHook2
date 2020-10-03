#pragma once
#include "includes.h"
DWORD CMDADDTEXT = 0x10FAC00;
DWORD OPENTRACK = 0xCAAC60;
DWORD ENABLESKIPS = 0xE4F5A0;
DWORD GETFILEID = 0x9D7120; // wrong

namespace SDK
{
	namespace Functions {

		typedef void(__cdecl* CmdAddText_t)(int a1, int a2, int a3, int a4, int a5, const char* a7, const char* dummy0, int dummy1, int dummy2, int dummy3, int dummy4, int dummy5);
		extern CmdAddText_t CmdAddText;
		CmdAddText_t CmdAddText = (CmdAddText_t)CMDADDTEXT;
		CmdAddText_t CmdAddText_o = NULL;

		__int64 __position;
		typedef void(__fastcall* OpenTrack_t)(void* _this, void* edx, int a2, int a3, DWORD a4, __int64 position, char a6, DWORD a7);
		extern OpenTrack_t OpenTrack;
		OpenTrack_t OpenTrack = (OpenTrack_t)OPENTRACK;
		OpenTrack_t OpenTrack_o = NULL;

		typedef void(__fastcall* EnableSkips_t)(void* _this, void* edx);
		extern EnableSkips_t EnableSkips;
		EnableSkips_t EnableSkips = (EnableSkips_t)ENABLESKIPS;
		EnableSkips_t EnableSkips_o = NULL;

		typedef void(__cdecl* GetFileID_t)(int* a1, int a2);
		extern GetFileID_t GetFileID;
		GetFileID_t GetFileID = (GetFileID_t)GETFILEID;
		GetFileID_t GetFileID_o = NULL;
	}
}