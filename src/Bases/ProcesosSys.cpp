#include "StdAfx.h"
#include "ProcesosSys.h"

CProcesosSys::~CProcesosSys(void)
{
}
VOID CProcesosSys::Actualizar()
{
	peSys.dwSize = sizeof(peSys);
	HANDLE hProcSnap = kernel32_Link->CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, procesoID);
	kernel32_Link->Process32FirstW(hProcSnap, &peSys);

	CloseHandle(hProcSnap);
}
//-----------------------Informacion del proceso ---------------------
wstring CProcesosSys::NombreImagen()
{
	wstring nombre;
	
	if (procesoID == 0)
		nombre = L"[Proceso Inactivo del Sistema]";
	else
		nombre = peSys.szExeFile;

	return nombre;
}
DWORD CProcesosSys::GetIdentificador()
{
	return procesoID;
}
wstring CProcesosSys::GetClasePrioridad()
{
	wstring prioridadBase;

	switch(peSys.pcPriClassBase)
	{
	case ABOVE_NORMAL_PRIORITY_CLASS: prioridadBase = L"Encima de Normal";break;
	case BELOW_NORMAL_PRIORITY_CLASS: prioridadBase = L"Debajo de Normal";break;
	case HIGH_PRIORITY_CLASS: prioridadBase = L"Alta"; break;
	case IDLE_PRIORITY_CLASS: prioridadBase = L"Inactivo"; break;
	case NORMAL_PRIORITY_CLASS: prioridadBase = L"Normal"; break;
	case REALTIME_PRIORITY_CLASS: prioridadBase = L"Tiempo Real"; break;
	default: prioridadBase = L"N\\A";
	}
	return prioridadBase;
}
	//---------------------------Sesion ID ---------------------------
DWORD CProcesosSys :: GetSesionID()
{
	return 0;
}
