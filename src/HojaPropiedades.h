#pragma once


// CHojaPropiedades
#include "Aplicaciones.h"
#include "Procesos.h"
#include "Rendimiento.h"
#include "Red.h"

class CHojaPropiedades : public CPropertySheet
{
	DECLARE_DYNAMIC(CHojaPropiedades)

public:
	CHojaPropiedades(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CHojaPropiedades(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CHojaPropiedades();
	void AdicionarPaginas();
	virtual ~CHojaPropiedades();
	//-------------------------------------------------------
	CAplicaciones aplicacionesTab;
	CProcesos procesosTab;
	CRendimiento rendimientoTab;
	CRed redTab;
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
public:
	virtual BOOL OnInitDialog();
};


