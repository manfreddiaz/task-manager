#pragma once

#include "ProcesoBase.h"

class CProcesosSys : public CProcesoBase
{
private:
	PROCESSENTRY32 peSys;
public:
	CProcesosSys(DWORD _procesoID):CProcesoBase(_procesoID){this->Actualizar();};
	~CProcesosSys(void);
	//----------------------- Actualizacion ------------------------------
	VOID Actualizar();
	//-----------------------Informacion del proceso ---------------------
	wstring NombreImagen();
	DWORD GetIdentificador();
	wstring GetClasePrioridad();
	//---------------------------Sesion ID ---------------------------
	DWORD GetSesionID();
};
