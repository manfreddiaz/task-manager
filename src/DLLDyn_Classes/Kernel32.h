#pragma once

#include <windows.h>
#include <tlhelp32.h>

class CKernel32
{
private:
	HMODULE hKernel32;
public:
	CKernel32();
	~CKernel32();
	//---- Funciones Importadas -----
	BOOL (WINAPI* GetProcessTimes)(HANDLE,LPFILETIME,LPFILETIME,LPFILETIME,LPFILETIME);
	BOOL (WINAPI* GetProcessIoCounters)(HANDLE,PIO_COUNTERS);
	BOOL (WINAPI* GetProcessHandleCount)(HANDLE,PDWORD);
	HANDLE (WINAPI* CreateToolhelp32Snapshot)(DWORD,DWORD);
	BOOL (WINAPI* Process32First)(HANDLE, LPPROCESSENTRY32);
	BOOL (WINAPI* FileTimeToSystemTime)(FILETIME*,LPSYSTEMTIME);
	BOOL (WINAPI* ProcessIdToSessionId)(DWORD,DWORD*);
	HANDLE (WINAPI* OpenProcess)(DWORD,BOOL,DWORD);
};
