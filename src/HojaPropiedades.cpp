// HojaPropiedades.cpp : implementation file
//

#include "stdafx.h"
#include "Administrador_Tareas.h"
#include "HojaPropiedades.h"


// CHojaPropiedades

IMPLEMENT_DYNAMIC(CHojaPropiedades, CPropertySheet)

CHojaPropiedades::CHojaPropiedades(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}
CHojaPropiedades::CHojaPropiedades():CPropertySheet()
{
	AdicionarPaginas();
}

CHojaPropiedades::CHojaPropiedades(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AdicionarPaginas();
}

CHojaPropiedades::~CHojaPropiedades()
{
}


BEGIN_MESSAGE_MAP(CHojaPropiedades, CPropertySheet)
END_MESSAGE_MAP()


void CHojaPropiedades::AdicionarPaginas()
{
	AddPage(&aplicacionesTab);
	AddPage(&procesosTab);
	AddPage(&rendimientoTab);
	AddPage(&redTab);
}

BOOL CHojaPropiedades::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	return bResult;
}
