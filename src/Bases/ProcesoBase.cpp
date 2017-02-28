#include "StdAfx.h"
#include "ProcesoBase.h"

CKernel32* CProcesoBase::kernel32_Link = new CKernel32();
CAdvApi32* CProcesoBase::advapi32_Link = new CAdvApi32();
CPsapiM* CProcesoBase::psapi_Link = new CPsapiM();
CUser32* CProcesoBase::user32_Link = new CUser32();

CProcesoBase::CProcesoBase(DWORD _procesoID)
{
	procesoID = _procesoID;
}


CProcesoBase::~CProcesoBase(void)
{
}
