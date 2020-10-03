#pragma once
#include <Windows.h>
#include <stdio.h>
#include <iostream>

#include "globals.h"
#include "sdk.h"
#include "hooks.h"
#include "utils.h"

#if defined _M_X64
#pragma comment(lib, "libMinHook.x64.lib")
#elif defined _M_IX86
#pragma comment(lib, "libMinHook-x86-v141-mtd.lib")
#endif