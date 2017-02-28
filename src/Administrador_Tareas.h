// Administrador_Tareas.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CAdministrador_TareasApp:
// Consulte la sección Administrador_Tareas.cpp para obtener información sobre la implementación de esta clase
//

class CAdministrador_TareasApp : public CWinApp
{
public:
	CAdministrador_TareasApp();

// Reemplazos
	public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CAdministrador_TareasApp theApp;