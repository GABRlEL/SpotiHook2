#pragma once
#include "includes.h"
#include "MinHook.h"

using namespace SDK::Functions;

void __cdecl CmdAddText_hk(int a1, int a2, int a3, int a4, int a5, const char* fmt, const char* dummy0, int dummy1, int dummy2, int dummy3, int dummy4, int dummy5)
{
	if (fmt[8] == char(116) && fmt[9] == char(114) && fmt[10] == char(97) && fmt[11] == char(99) && fmt[12] == char(107) && fmt[13] == char(95) && fmt[14] == char(117) && fmt[15] == char(114) && fmt[16] == char(105))
	{
		if (dummy0[8] == char(97) && dummy0[9] == char(100)) //ad
		{
			std::string str(dummy0); //ghetto workaround for access violations
			printf("[ad] %s\n", str);
			__position = 29000;
		}
		else if (dummy0[8] == char(116) && dummy0[9] == char(114)) //tr
		{
			std::string str(dummy0);
			printf("%s\n", str);
			__position = 0;
		}
	}
	CmdAddText_o(a1, a2, a3, a4, a5, fmt, dummy0, dummy1, dummy2, dummy3, dummy4, dummy5);
}

void __fastcall OpenTrack_hk(void* _this, void* edx, int a2, int a3, DWORD a4, __int64 position, char a6, DWORD a7)
{
	return OpenTrack_o(_this, edx, a2, a3, a4, __position, a6, a7);
}

void __fastcall EnableSkips_hk(void* _this, void* edx)
{
	__asm
	{
		mov     ecx, 1
		retn
	}
}

void GetFileID_hk(int* a1, int a2)
{
	GetFileID_o(a1, a2);
}

void DoHooks() {
	if (MH_Initialize() != MH_OK)
	{
		std::cout << "Failed to initialize MH!" << std::endl;		
	}
	if (MH_CreateHook(CmdAddText, &CmdAddText_hk,
		reinterpret_cast<LPVOID*>(&CmdAddText_o)) != MH_OK)
	{
		std::cout << "Failed to hook CmdAddText..." << std::endl;
	}
	if (MH_CreateHook(OpenTrack, &OpenTrack_hk,
		reinterpret_cast<LPVOID*>(&OpenTrack_o)) != MH_OK)
	{
		std::cout << "Failed to hook OpenTrack..." << std::endl;
	}
	if (MH_CreateHook(EnableSkips, &EnableSkips_hk,
		reinterpret_cast<LPVOID*>(&EnableSkips_o)) != MH_OK)
	{
		std::cout << "Failed to hook EnableSkips..." << std::endl;
	}
	/*if (MH_CreateHook(GetFileID, &GetFileID_hk,
		reinterpret_cast<LPVOID*>(&GetFileID_o)) != MH_OK)
	{
		std::cout << "Please wait for an update..." << std::endl;
	} */
	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
	{
		std::cout << "Fatal Error!" << std::endl;
	}
}