#pragma once

#include <windows.h>
#include <psapi.h>

class CPsapiM
{
private:
	HMODULE hPsapi;
public:
	CPsapiM();
	~CPsapiM();
	//------  Funciones Importadas
	DWORD (WINAPI* GetProcessImageFileName)(HANDLE,LPTSTR,DWORD);
	BOOL (WINAPI* GetProcessMemoryInfo)(HANDLE,PPROCESS_MEMORY_COUNTERS,DWORD);
	BOOL (WINAPI* EnumProcesses)(DWORD*, DWORD,DWORD*);
};
