#pragma once


#include ".\..\..\.\Bases\Aplicacion.h"

#include <vector>
using namespace std;

class CAppManager
{
private:
	static vector<CAplicacion*> listaAplicaciones;
	static int nAplicaciones;
	static CUser32* user32_Link;

	//------------------------------------- CALLBACKs --------------------------
	
public:
	CAppManager(void);
	~CAppManager(void);
	int NumeroAplicaciones();
	VOID Actualizar();
	CAplicacion* ObtenerAplicacion(int);
	static BOOL MyEnumWindowsProc(HWND, LPARAM);
	BOOL TermininarAplicacion(int);
	
};
