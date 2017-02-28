#pragma once

#include "ProcesoBase.h"

class CProcesoUser : public CProcesoBase
{
private:
	DWORD procesoID;
	HANDLE hProceso;
	PROCESS_MEMORY_COUNTERS pMemoria;
	IO_COUNTERS pESConteos;
	//---------- Objetos de las librerias dinamicas para todos los miembros ---------

public:

	CProcesoUser(DWORD _procesoID);
	~CProcesoUser(void);
	//----------------------- Actualizacion ------------------------------
	VOID Actualizar();
	//-----------------------Informacion del proceso ---------------------
	wstring NombreImagen();
	DWORD GetIdentificador();
	wstring GetClasePrioridad();
	BOOL TerminarProceso();
	//----------------------- Tiempos y Uso de CPU -----------------
	int GetUsoCPU(); //Not implemented yet
	wstring GetTiempoCPU();
	//----------------------- Memoria ----------------
	DWORD GetUsoMemoria();
	DWORD GetPicoUsoMemoria();
	DWORD GetTamanoVM();
	//----------------------- Paginas -----------------
	DWORD GetErroresPaginas();
	DWORD GetBloquePaginado(); //Paged Pool
	DWORD GetBloqueNoPaginado(); //NP Pool
	//----------------------- Objetos GUI & Usr --------
	DWORD GetCantObjetosUsr();
	DWORD GetCantObjetosGUI();
	//---------------------- Operacioes E/S ------------
	ULONGLONG GetCantESLecturas();
	ULONGLONG GetCantESBytesLeidos();
	ULONGLONG GetCantESEscrituras();
	ULONGLONG GetCantESBytesEscritos();
	ULONGLONG GetCantESOtros();
	ULONGLONG GetCantESBytesOtros();
	//--------------------- Sesion ID & Usr -------------
	wstring GetNombreUsuarioPropietario();
	DWORD GetSesionID();
	//--------------------- Prioridad, Manipuladores & Supprocesos ---------
	DWORD GetCantManipuladores(); // Handles
	DWORD GetCantSubprocesos(); // Threads
};
