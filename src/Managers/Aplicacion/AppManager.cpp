#include "StdAfx.h"
#include "AppManager.h"

CUser32* CAppManager::user32_Link = new CUser32();
int CAppManager::nAplicaciones = 0;
vector<CAplicacion*> CAppManager::listaAplicaciones;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	return CAppManager::MyEnumWindowsProc(hWnd,lParam);
}
CAppManager::CAppManager(void)
{

}

CAppManager::~CAppManager(void)
{
}
BOOL CAppManager::MyEnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	if (hWnd == NULL || hWnd == INVALID_HANDLE_VALUE)
		return FALSE;

	CAplicacion* aplicacion = new CAplicacion(hWnd);
	if (aplicacion->EsVisible() && aplicacion->NombreAplicacion().length())
	{
		listaAplicaciones.push_back(aplicacion);
		nAplicaciones++;
	}


	return TRUE;

}
void CAppManager::Actualizar()
{
	listaAplicaciones.clear();
	nAplicaciones = 0;
	user32_Link->EnumWindows(EnumWindowsProc, NULL);
}
CAplicacion* CAppManager::ObtenerAplicacion(int i)
{
	return listaAplicaciones[i];
}
int CAppManager::NumeroAplicaciones()
{
	return nAplicaciones;
}
BOOL CAppManager::TermininarAplicacion(int i)
{
	CAplicacion* aplicacion = listaAplicaciones[i];
	aplicacion->FinalizarTarea();
	return true;
}