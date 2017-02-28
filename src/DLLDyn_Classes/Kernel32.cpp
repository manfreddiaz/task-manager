#include "StdAfx.h"
#include "Kernel32.h"

CKernel32::CKernel32()
{
	hKernel32 = LoadLibrary(L"kernel32.dll");
	*(FARPROC*)&(CKernel32::GetProcessTimes) = GetProcAddress(hKernel32, "GetProcessTimes");
	*(FARPROC*)&(CKernel32::GetProcessHandleCount) = GetProcAddress(hKernel32, "GetProcessHandleCount");
	*(FARPROC*)&(CKernel32::GetProcessIoCounters) = GetProcAddress(hKernel32, "GetProcessIoCounters");
	*(FARPROC*)&(CKernel32::Process32FirstW) = GetProcAddress(hKernel32, "Process32FirstW");
	*(FARPROC*)&(CKernel32::CreateToolhelp32Snapshot) = GetProcAddress(hKernel32, "CreateToolhelp32Snapshot");
	*(FARPROC*)&(CKernel32::FileTimeToSystemTime) = GetProcAddress(hKernel32, "FileTimeToSystemTime"); 
	*(FARPROC*)&(CKernel32::ProcessIdToSessionId) = GetProcAddress(hKernel32, "ProcessIdToSessionId");
	*(FARPROC*)&(CKernel32::OpenProcess) = GetProcAddress(hKernel32, "OpenProcess");
}


CKernel32::~CKernel32()
{

}
