#pragma once
#include "stdafx.h"

#include "Aplicacion.h"

CUser32* CAplicacion::user32_Link = new CUser32();

CAplicacion::CAplicacion(HWND _hVentana)
{
	hVentana = _hVentana;
	TCHAR buffer[256];
	GetWindowText(hVentana, buffer, 256);

	titulo = buffer;
}
CAplicacion::~CAplicacion()
{
	delete user32_Link;
}
wstring CAplicacion::NombreAplicacion()
{
	return titulo;
}
VOID CAplicacion::FinalizarTarea()
{
	DWORD pId;
	GetWindowThreadProcessId(hVentana, &pId);
	HANDLE hProceso = OpenProcess(PROCESS_TERMINATE, FALSE, pId);
	TerminateProcess(hProceso,S_OK);
	//user32_Link->EndTask(hVentana, TRUE, TRUE);	
}
BOOL CAplicacion::Estado()
{
	return user32_Link->IsHungAppWindow(hVentana);
}
BOOL CAplicacion::EsVisible()
{
	return IsWindowVisible(hVentana);
}

