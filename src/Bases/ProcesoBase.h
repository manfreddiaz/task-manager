#pragma once

#include ".\..\DLLDyn_Classes\PsapiM.h"
#include ".\..\DLLDyn_Classes\AdvApi32.h"
#include ".\..\DLLDyn_Classes\Kernel32.h"
#include ".\..\DLLDyn_Classes\User32.h"

#include <string>
using namespace std;

class CProcesoBase
{
protected:
	DWORD procesoID;
	//-------------------------------------------------------
	static CKernel32* kernel32_Link;
	static CPsapiM* psapi_Link;
	static CAdvApi32* advapi32_Link;
	static CUser32* user32_Link;
	//-------------------------------------------------------
public:
	CProcesoBase(DWORD _procesoID);
	~CProcesoBase(void);
	//----------------------- Actualizacion ------------------------------
	virtual VOID Actualizar() = 0;
	//-----------------------Informacion del proceso ---------------------
	virtual wstring NombreImagen() = 0;
	virtual DWORD GetIdentificador() = 0;
	virtual wstring GetClasePrioridad() = 0;
	//---------------------------Sesion ID ---------------------------
	virtual DWORD GetSesionID() = 0;
};

