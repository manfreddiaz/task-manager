// Administrador_Tareas.h: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales


// CAdministrador_TareasApp:
// Consulte la secci�n Administrador_Tareas.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CAdministrador_TareasApp : public CWinApp
{
public:
	CAdministrador_TareasApp();

// Reemplazos
	public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern CAdministrador_TareasApp theApp;