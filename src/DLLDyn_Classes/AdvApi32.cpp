#include "StdAfx.h"
#include "AdvApi32.h"

CAdvApi32::CAdvApi32()
{
	hAdvApi32 = LoadLibrary(L"advapi32.dll");
	*(FARPROC*)&(CAdvApi32::OpenProcessToken) = GetProcAddress(hAdvApi32, "OpenProcessToken");
	*(FARPROC*)&(CAdvApi32::GetTokenInformation) = GetProcAddress(hAdvApi32, "GetTokenInformation");
	*(FARPROC*)&(CAdvApi32::LookupAccountSidW) = GetProcAddress(hAdvApi32, "LookupAccountSidW");
}

CAdvApi32::~CAdvApi32()
{

}
