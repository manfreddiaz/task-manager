#include "StdAfx.h"
#include "User32.h"

CUser32::CUser32()
{
	hUser32 = LoadLibrary(L"user32.dll");
	*(FARPROC*)&(CUser32::GetGuiResources) = GetProcAddress(hUser32, "GetGuiResources");
	*(FARPROC*)&(CUser32::EnumWindows) = GetProcAddress(hUser32, "EnumWindows");
	*(FARPROC*)&(CUser32::EndTask) = GetProcAddress(hUser32, "EndTask");
	*(FARPROC*)&(CUser32::IsHungAppWindow) = GetProcAddress(hUser32, "IsHungAppWindow");
}

CUser32::~CUser32()
{
}
