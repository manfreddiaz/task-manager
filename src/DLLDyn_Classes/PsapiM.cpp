#include "StdAfx.h"
#include "PsapiM.h"

CPsapiM::CPsapiM()
{
	hPsapi = LoadLibrary(L"psapi.dll");
	*(FARPROC*)&(CPsapiM::GetProcessMemoryInfo) = GetProcAddress(hPsapi, "GetProcessMemoryInfo");
	*(FARPROC*)&(CPsapiM::GetProcessImageFileNameW) = GetProcAddress(hPsapi, "GetProcessImageFileNameW");
	*(FARPROC*)&(CPsapiM::EnumProcesses) = GetProcAddress(hPsapi, "EnumProcesses");
}

CPsapiM::~CPsapiM()
{
}
