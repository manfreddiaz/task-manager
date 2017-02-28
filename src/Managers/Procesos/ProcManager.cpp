#include "StdAfx.h"
#include "ProcManager.h"

CPsapiM* CProcManager::psapi_Link = new CPsapiM();

CProcManager::CProcManager(void)
{

}

CProcManager::~CProcManager(void)
{
}

void CProcManager::Actualizar()
{
	DWORD procesos[256], tamano = sizeof(procesos);
	
	psapi_Link->EnumProcesses(procesos, tamano, &tamano);
	
	nProcesos = tamano / sizeof(DWORD);
	listaProcesos.clear();
	
	//---- Aqui aplico el polimorfismo, separo SYSTEM de USER -------------

	for (int i = 0; i < nProcesos; i++)
	{
		try
		{
			CProcesoBase* nuevoProceso = new CProcesoUser(procesos[i]);
			listaProcesos.push_back(nuevoProceso);
		}
		catch(DWORD)
		{
			CProcesoBase* nuevoProceso = new CProcesosSys(procesos[i]);
			listaProcesos.push_back(nuevoProceso);
		}
	}

}

CProcesoBase* CProcManager::ObtenerProceso(int nProceso)
{
	return listaProcesos[nProceso];
}
DWORD CProcManager::GetNProcesos()
{
	return nProcesos;
}
BOOL CProcManager::TerminarProceso(int i)
{
	CProcesoBase* proc = listaProcesos[i];

	if (typeid(*proc) != typeid(CProcesoUser))
		return FALSE;

	if (((CProcesoUser*)proc)->TerminarProceso())
	{
		listaProcesos.erase(listaProcesos.begin()+i);
		return TRUE;
	}

	return FALSE;
}

