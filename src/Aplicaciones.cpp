// Aplicaciones.cpp : implementation file
//

#include "stdafx.h"
#include "Administrador_Tareas.h"
#include "Aplicaciones.h"


// CAplicaciones dialog

IMPLEMENT_DYNAMIC(CAplicaciones, CPropertyPage)

CAplicaciones::CAplicaciones()
	: CPropertyPage(CAplicaciones::IDD)
{

}

CAplicaciones::~CAplicaciones()
{
}

void CAplicaciones::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listaAplicaciones);
	this->RedrawWindow();
}


BEGIN_MESSAGE_MAP(CAplicaciones, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &CAplicaciones::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAplicaciones message handlers

BOOL CAplicaciones::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here
	CString columna;
	LVCOLUMNW column;
	column.mask = LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;
	column.fmt = LVCFMT_LEFT;
	column.cx = 100;
	for (int i = 125; i <= 126; i++)
	{
		columna.LoadStringW(i);
		column.pszText = (LPWSTR)columna.GetString();
		column.iSubItem = i - 102;
		listaAplicaciones.InsertColumn(i-102,&column);
	}
	this->DibujarComponentes();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CAplicaciones::DibujarComponentes()
{
	listaAplicaciones.DeleteAllItems();
	managerAplicaciones.Actualizar();
	int nAplicaciones = managerAplicaciones.NumeroAplicaciones();
	CAplicacion* aplicacion;
	LVITEM item;

	for (int i = 0; i < nAplicaciones; i++)
	{
		aplicacion = managerAplicaciones.ObtenerAplicacion(i);
		int nIndex = listaAplicaciones.InsertItem(i,aplicacion->NombreAplicacion().c_str(),-1);
		if (aplicacion->Estado())
			listaAplicaciones.SetItemText(nIndex, 1, L"No responde");
		else
			listaAplicaciones.SetItemText(nIndex,1, L"Activo");

	}
	
}

void CAplicaciones::OnBnClickedButton1()
{
	int seleccion = listaAplicaciones.GetSelectionMark();
	if (seleccion != -1)
	{
		managerAplicaciones.TermininarAplicacion(seleccion);
		listaAplicaciones.DeleteItem(seleccion);
	}
}
