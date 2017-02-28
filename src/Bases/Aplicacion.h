#pragma once

#include <windows.h>
#include ".\..\DLLDyn_Classes\User32.h"

#include <string>
using namespace std;

class CAplicacion
{
private:
	HWND hVentana;
	wstring titulo;
	static CUser32* user32_Link;
public:
	CAplicacion(HWND);
	~CAplicacion();
	wstring NombreAplicacion();
	VOID FinalizarTarea();
	BOOL Estado();
	BOOL EsVisible();

};
