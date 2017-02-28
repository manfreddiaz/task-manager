#pragma once

#include <windows.h>

class CUser32
{
private:
	HMODULE hUser32;
public:
	CUser32(void);
	~CUser32(void);
	//-------------------- Funciones importadas -----------------
	DWORD (WINAPI* GetGuiResources)(HANDLE, DWORD);
	BOOL (WINAPI* EnumWindows)(WNDENUMPROC,LPARAM);
	BOOL (WINAPI* EndTask)(HWND,BOOL,BOOL);
	BOOL (WINAPI* IsHungAppWindow)(HWND);
};
