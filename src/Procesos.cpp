// Procesos.cpp : implementation file
//

#include "stdafx.h"
#include "Administrador_Tareas.h"
#include "Procesos.h"




// CProcesos dialog

IMPLEMENT_DYNAMIC(CProcesos, CPropertyPage)

	CProcesos::CProcesos()
	: CPropertyPage(CProcesos::IDD)
{

}

CProcesos::~CProcesos()
{
}

void CProcesos::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listaProcesos);
	this->RedrawWindow();
}


BEGIN_MESSAGE_MAP(CProcesos, CPropertyPage)

	ON_BN_CLICKED(IDC_BUTTON1, &CProcesos::OnBnClickedButton1)
END_MESSAGE_MAP()


// CProcesos message handlers

BOOL CProcesos::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here
	CString columna;
	LVCOLUMNW column;
	column.mask = LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH;
	column.fmt = LVCFMT_RIGHT;
	column.cx = 100;
	for (int i = 102; i <= 124; i++)
	{
		columna.LoadStringW(i);
		column.pszText = (LPWSTR)columna.GetString();
		column.iSubItem = i - 102;
		listaProcesos.InsertColumn(i-102,&column);
	}
	DibujarComponentes();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
void CProcesos::DibujarComponentes()
{
	managerProcesos.Actualizar();
	listaProcesos.DeleteAllItems();
	int nProcesos = managerProcesos.GetNProcesos();
	CProcesoBase* proceso;
	LVITEM subItem;
	subItem.pszText = LPSTR_TEXTCALLBACK;
	TCHAR buffer[260];
	for (int i = 0; i < nProcesos; i++)
	{
		proceso = managerProcesos.ObtenerProceso(i);

		CW2WEX<260> convert(proceso->NombreImagen().c_str());
		int nItem = listaProcesos.InsertItem(i, convert.m_psz);
		if (typeid(*proceso) == typeid(CProcesosSys))
		{

			for (int j = 1; j < 23; j++)
			{
				switch(j)
				{

				case 1: subItem.pszText = _itow( ((CProcesosSys*)proceso)->GetIdentificador(), buffer, 10);break;
				case 2: subItem.pszText = _T("SYSTEM");break;
				case 3: subItem.pszText = (LPWSTR)proceso->GetClasePrioridad().c_str();break;
				case 4: subItem.pszText = _T("N/A");break;
				case 5: subItem.pszText = _T("N/A");break;
				case 6: subItem.pszText = _T("N/A");break;
				case 7: subItem.pszText = _T("N/A");break;
				case 8: subItem.pszText = _itow( proceso->GetSesionID(),buffer, 10);break;
				case 9: subItem.pszText = _T("N/A");break;
				case 10:subItem.pszText = _T("N/A");break;
				case 11:subItem.pszText = _T("N/A");break;
				case 12:subItem.pszText = _T("N/A");break;
				case 13:  subItem.pszText = _T("N/A");break;
				case 14: subItem.pszText = _T("N/A");break;
				case 15: subItem.pszText = _T("N/A");break;
				case 16: subItem.pszText = _T("N/A");break;
				case 17: subItem.pszText = _T("N/A");break;
				case 18: subItem.pszText = _T("N/A");break;
				case 19: subItem.pszText = _T("N/A");break;
				case 20: subItem.pszText = _T("N/A");break;
				case 21: subItem.pszText = _T("N/A");break;
				case 22: subItem.pszText = _T("N/A");break;
				}
				listaProcesos.SetItemText(nItem, j, subItem.pszText);
			}
		}
		else
		{
			for (int j = 1; j < 23; j++)
			{

				subItem.iSubItem = j;
				CW2WEX<260> nombreUsuario(((CProcesoUser*)proceso)->GetNombreUsuarioPropietario().c_str());
				CW2WEX<260> clasePrioridad(((CProcesoUser*)proceso)->GetClasePrioridad().c_str());
				CW2WEX<260> tiempoCPU(((CProcesoUser*)proceso)->GetTiempoCPU().c_str());
				switch(j)
				{

				case 1: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetIdentificador(), buffer, 10);break;
				case 2: subItem.pszText = nombreUsuario.m_psz;break;
				case 3: subItem.pszText = clasePrioridad.m_psz;break;
				case 4: subItem.pszText = tiempoCPU.m_psz;break;
				case 5: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetUsoCPU(), buffer, 10);break;
				case 6: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetUsoMemoria(), buffer, 10);break;
				case 7: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetPicoUsoMemoria(), buffer, 10);break;
				case 8: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetSesionID(),buffer, 10);break;
				case 9: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetCantManipuladores(),buffer, 10);break;
				case 10:  subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetCantSubprocesos(),buffer, 10);break;
				case 11: subItem.pszText = _T("No definido"); break;// No definido por el momento
				case 12: subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetErroresPaginas(),buffer, 10);break;
				case 13:  subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetBloquePaginado(),buffer, 10);break;
				case 14:  subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetBloqueNoPaginado(),buffer, 10);break;
				case 15:  subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetCantObjetosUsr(),buffer, 10);break;
				case 16:  subItem.pszText = _itow( ((CProcesoUser*)proceso)->GetCantObjetosGUI(),buffer, 10);break;
				case 17:  subItem.pszText =_i64tow( ((CProcesoUser*)proceso)->GetCantESLecturas(),buffer, 10);break;
				case 18: subItem.pszText =_i64tow( ((CProcesoUser*)proceso)->GetCantESEscrituras(),buffer, 10);break;
				case 19: subItem.pszText =_i64tow( ((CProcesoUser*)proceso)->GetCantESOtros(),buffer, 10);break;
				case 20: subItem.pszText =_i64tow( ((CProcesoUser*)proceso)->GetCantESBytesLeidos(),buffer, 10);break;
				case 21: subItem.pszText =_i64tow( ((CProcesoUser*)proceso)->GetCantESBytesEscritos(),buffer, 10);break;
				case 22: subItem.pszText =_i64tow( ((CProcesoUser*)proceso)->GetCantESBytesOtros(),buffer, 10);break;
				}
				listaProcesos.SetItemText(nItem, j, subItem.pszText);
			}
		}
	}
}


void CProcesos::OnBnClickedButton1()
{
	int seleccion = listaProcesos.GetSelectionMark();

	if (seleccion != -1)
	{
		if (managerProcesos.TerminarProceso(seleccion))
			listaProcesos.DeleteItem(seleccion);
		else
		{
			//AfxMessageBox(L"La operación no se pudo terminar. Accesso denegado",MB_OK|MB_ICONEXCLAMATION);
		}

	}
}
