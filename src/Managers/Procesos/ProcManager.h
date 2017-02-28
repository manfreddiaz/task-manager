#pragma once

#include <vector>


#include "..\..\Bases\Procesos.h"
#include "..\..\Bases\ProcesosSys.h"

class CProcManager
{
private:
	vector<CProcesoBase*> listaProcesos;
	static CPsapiM* psapi_Link;
	int nProcesos;
public:
	CProcManager();
	~CProcManager();
	//---------------------------------
	void Actualizar();
	CProcesoBase* ObtenerProceso(int);
	DWORD GetNProcesos();
	BOOL TerminarProceso(int);
};
