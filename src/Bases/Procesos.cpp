#include "StdAfx.h"
#include "Procesos.h"



CProcesoUser::CProcesoUser(DWORD _procesoID):CProcesoBase(_procesoID)
{
	procesoID = _procesoID;
	hProceso = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, procesoID);
	if (hProceso == NULL)
	{
		throw GetLastError();
	}
	Actualizar();
}

CProcesoUser::~CProcesoUser(void)
{
	CloseHandle(hProceso);
}
//------------------------ Actualizacion -------------
VOID CProcesoUser::Actualizar()
{
	//------- Estado en Memoria --------
	ZeroMemory(&pMemoria,sizeof(pMemoria));
	pMemoria.cb = sizeof(pMemoria);
	psapi_Link->GetProcessMemoryInfo(hProceso, &pMemoria, pMemoria.cb);
	//------------Operaciones E/S ---------------------- 
	ZeroMemory(&pESConteos, sizeof(pESConteos));
	kernel32_Link->GetProcessIoCounters(hProceso, &pESConteos);
}
//------------------ Informacion del proceso ---------
wstring CProcesoUser::NombreImagen()
{
	TCHAR nombreImagen[256];
	psapi_Link->GetProcessImageFileNameW(hProceso,nombreImagen, sizeof(nombreImagen));
	wstring wNombre = (wchar_t*)nombreImagen;
	if(wNombre.length())
		wNombre.erase(wNombre.find_first_of(L"\\"), wNombre.find_last_of(L"\\")+1);
	else
		wNombre = L"System";

	return wNombre;
}
DWORD CProcesoUser :: GetIdentificador()
{
	return procesoID;
}
//----------------------- Tiempos y Usos de CPU -----------------
int CProcesoUser :: GetUsoCPU()
{
	FILETIME Creacion, Terminacion, mKernel, mUsuario, tiempoActual;
	double porCiento;
	kernel32_Link->GetProcessTimes(hProceso, &Creacion, &Terminacion, &mKernel, &mUsuario);
	
	SYSTEMTIME tiempoSistema;
	GetSystemTime(&tiempoSistema);
	
	SystemTimeToFileTime(&tiempoSistema, &tiempoActual);
	__int64 dTiempoAct = Int32x32To64(tiempoActual.dwHighDateTime, 1000000000) + tiempoActual.dwLowDateTime;
	__int64 dTiempoCrea = Int32x32To64(Creacion.dwHighDateTime, 1000000000) + Creacion.dwLowDateTime;
	__int64 tiempoVida = _abs64(dTiempoAct - dTiempoCrea);

	__int64 dTiempoK = 	Int32x32To64(mKernel.dwHighDateTime, 1000000000) + mKernel.dwLowDateTime;
	__int64 dTiempoU = 	Int32x32To64(mUsuario.dwHighDateTime, 1000000000) + mUsuario.dwLowDateTime;
	__int64 dTiempoUso = dTiempoK + dTiempoU;

	porCiento = dTiempoUso*100/tiempoVida;
	return porCiento;
}
wstring CProcesoUser :: GetTiempoCPU()
{
	FILETIME Creacion, Terminacion, mKernel, mUsuario;

	kernel32_Link->GetProcessTimes(hProceso, &Creacion, &Terminacion, &mKernel, &mUsuario);
	SYSTEMTIME _mKernel, _mUsuario, tiempoCPU;
	//------------------------------- Convierto para sumar -----------
	kernel32_Link->FileTimeToSystemTime(&mKernel,&_mKernel);
	kernel32_Link->FileTimeToSystemTime(&mUsuario,&_mUsuario);

	tiempoCPU.wSecond = (_mKernel.wSecond + _mUsuario.wSecond) % 60;

	WORD incSecond = (_mKernel.wSecond + _mUsuario.wSecond) / 60;
	tiempoCPU.wMinute = (_mKernel.wMinute + _mUsuario.wMinute + incSecond) % 60;

	WORD incMinute = (_mKernel.wMinute + _mUsuario.wMinute + incSecond) / 60;
	tiempoCPU.wHour = _mKernel.wHour + _mUsuario.wHour + incMinute;

	TCHAR buffer[256] = {0};
	_snwprintf(buffer, 256, L"%.2hu:%.2hu:%.2hu\0", tiempoCPU.wHour, tiempoCPU.wMinute, tiempoCPU.wSecond);
	
	wstring strTime = buffer;

	return strTime;
}
//----------------------- Memoria ----------------
DWORD CProcesoUser :: GetUsoMemoria()
{
	return pMemoria.WorkingSetSize / 1024;
}
DWORD CProcesoUser :: GetPicoUsoMemoria()
{
	return pMemoria.PeakWorkingSetSize / 1024;
}
/*DWORD CProcesoUser :: GetTamanoVM()
{
	
}*/
//----------------------- Paginas -----------------
DWORD CProcesoUser::GetBloquePaginado()
{
	return pMemoria.QuotaPagedPoolUsage;
}
DWORD CProcesoUser::GetBloqueNoPaginado()
{
	return pMemoria.QuotaNonPagedPoolUsage;
}
DWORD CProcesoUser :: GetErroresPaginas()
{
	return pMemoria.PageFaultCount;
}

//----------------------- Objetos GUI & Usr --------
DWORD CProcesoUser :: GetCantObjetosUsr()
{
	return user32_Link->GetGuiResources(hProceso, GR_USEROBJECTS);
}
DWORD CProcesoUser :: GetCantObjetosGUI()
{
	return user32_Link->GetGuiResources(hProceso, GR_GDIOBJECTS);
}
//---------------------- Operacioes E/S ------------
ULONGLONG CProcesoUser :: GetCantESLecturas()
{
	return pESConteos.ReadOperationCount;
}
ULONGLONG CProcesoUser :: GetCantESBytesLeidos()
{
	return pESConteos.ReadTransferCount;
}
ULONGLONG CProcesoUser :: GetCantESEscrituras()
{
	return pESConteos.WriteOperationCount;
}
ULONGLONG CProcesoUser :: GetCantESBytesEscritos()
{
	return pESConteos.WriteTransferCount;
}
ULONGLONG CProcesoUser :: GetCantESOtros()
{
	return pESConteos.OtherOperationCount;
}
ULONGLONG CProcesoUser :: GetCantESBytesOtros()
{
	return pESConteos.OtherTransferCount;
}
//--------------------- Sesion ID & Usr -------------
DWORD CProcesoUser :: GetSesionID()
{
	DWORD sesionId;
	kernel32_Link->ProcessIdToSessionId(procesoID, &sesionId);
	return sesionId;
}
wstring CProcesoUser :: GetNombreUsuarioPropietario()
{
	HANDLE hToken;
	PTOKEN_USER userInfo = NULL;
	SID_NAME_USE userUso;

	TCHAR nombreUsuario[256];
	TCHAR dominioUsuario[256];

	DWORD domLong = 256, userLong = 256;
	DWORD retValue;

	if (advapi32_Link->OpenProcessToken(hProceso, TOKEN_READ, &hToken))
	{
		advapi32_Link->GetTokenInformation(hToken, TokenUser, NULL, 0, &retValue);

		userInfo = (PTOKEN_USER)malloc(retValue);
	
		if (advapi32_Link->GetTokenInformation(hToken, TokenUser, userInfo, retValue, &retValue))
		{
			advapi32_Link->LookupAccountSidW(NULL, userInfo->User.Sid, nombreUsuario, &userLong, dominioUsuario, &domLong, &userUso);
			wstring wNombreUsuario = nombreUsuario;
			return wNombreUsuario;
		}
	}
	wstring wNombreUsuario = L"[Protegido]";

	return wNombreUsuario;
}
//--------------------- Prioridad, Manipuladores & Supprocesos ---------
wstring CProcesoUser::GetClasePrioridad()
{
	DWORD prioridad = GetPriorityClass(hProceso);
	wstring prioridadBase;

	switch(prioridad)
	{
	
	case ABOVE_NORMAL_PRIORITY_CLASS: prioridadBase = L"Encima de Normal";break;
	case BELOW_NORMAL_PRIORITY_CLASS: prioridadBase = L"Debajo de Normal";break;
	case HIGH_PRIORITY_CLASS: prioridadBase = L"Alta"; break;
	case IDLE_PRIORITY_CLASS: prioridadBase = L"Inactivo"; break;
	case NORMAL_PRIORITY_CLASS: prioridadBase = L"Normal"; break;
	case REALTIME_PRIORITY_CLASS: prioridadBase = L"Tiempo Real"; break;
	default: prioridadBase = L"N\\A";
	}

	return prioridadBase;
}
DWORD CProcesoUser :: GetCantManipuladores()
{
	DWORD nManipuladores;
	kernel32_Link->GetProcessHandleCount(hProceso, &nManipuladores);

	return nManipuladores;
}
DWORD CProcesoUser :: GetCantSubprocesos() //No es eso...
{
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);

	HANDLE hProcesoSnap = kernel32_Link->CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, procesoID); 

	kernel32_Link->Process32FirstW(hProcesoSnap, &pe32);

	return pe32.cntThreads;
}
BOOL CProcesoUser :: TerminarProceso()
{
	HANDLE nuevoHandle = OpenProcess(PROCESS_TERMINATE, FALSE, procesoID);
	if (nuevoHandle == NULL || nuevoHandle == INVALID_HANDLE_VALUE)
		return FALSE;
	TerminateProcess(nuevoHandle, S_OK);
	CloseHandle(nuevoHandle);
	return TRUE;
}