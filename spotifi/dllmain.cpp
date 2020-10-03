#include "includes.h"

void Setup() {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    g.hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "SpotiHook2 -- by Lyut" << std::endl << "Original reversal by meik97, pr8x and fortender" << std::endl;
    DoHooks();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CloseHandle(CreateThread(0,0,(PTHREAD_START_ROUTINE)Setup,0,0,0));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

