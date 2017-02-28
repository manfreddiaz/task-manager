#pragma once

#include <windows.h>

class CAdvApi32
{
private:
	HMODULE hAdvApi32;
public:
	CAdvApi32();
	~CAdvApi32();
	//---- Funciones importadas --------
	BOOL (WINAPI* OpenProcessToken)(HANDLE,DWORD,PHANDLE);
	BOOL (WINAPI* GetTokenInformation)(HANDLE,TOKEN_INFORMATION_CLASS,LPVOID,DWORD,PDWORD);
	BOOL (WINAPI* LookupAccountSid)(LPCTSTR,PSID,LPTSTR,LPDWORD,LPTSTR,LPDWORD,PSID_NAME_USE);
};
