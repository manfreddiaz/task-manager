// Administrador_TareasDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Administrador_Tareas.h"
#include "Administrador_TareasDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cuadro de diálogo de CAdministrador_TareasDlg

CAdministrador_TareasDlg::CAdministrador_TareasDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdministrador_TareasDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);

}

void CAdministrador_TareasDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAdministrador_TareasDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_COMMAND(ID_VELOCIDADDEACTUALIZACI32779, &CAdministrador_TareasDlg::OnVelocidadAlta)
	ON_COMMAND(ID_VELOCIDADDEACTUALIZACI32780, &CAdministrador_TareasDlg::OnVelocidadNormal)
	ON_COMMAND(ID_VELOCIDADDEACTUALIZACI32781, &CAdministrador_TareasDlg::OnVelocidadBaja)
	ON_COMMAND(ID_VELOCIDADDEACTUALIZACI32782, &CAdministrador_TareasDlg::OnVelocidadPausar)
END_MESSAGE_MAP()


// Controladores de mensaje de CAdministrador_TareasDlg

BOOL CAdministrador_TareasDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo. El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño
	
	//----------------------------- Inicializar PropertySheet -----
	propiedadesTab.Create(this,WS_CHILD|WS_VISIBLE);
	RECT rect;
	propiedadesTab.GetWindowRect(&rect);
	propiedadesTab.CalcWindowRect(&rect, propiedadesTab.adjustBorder);
	rect.top = 5;
	rect.left = 10;
	propiedadesTab.MoveWindow(&rect);
	//------------------------------------------------------------
	timer = SetTimer(1, 2000, 0);
	//-----------------------------------------------------------
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CAdministrador_TareasDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono. Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CAdministrador_TareasDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CAdministrador_TareasDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
afx_msg void CAdministrador_TareasDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
	if (nState == WA_ACTIVE || nState == WA_CLICKACTIVE)
		this->RedrawWindow();
}

void CAdministrador_TareasDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default


	switch(propiedadesTab.GetActiveIndex())
	{
	case 0:	propiedadesTab.aplicacionesTab.DibujarComponentes();break;
	case 1: propiedadesTab.procesosTab.DibujarComponentes(); break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CAdministrador_TareasDlg::OnVelocidadAlta()
{
	// TODO: Add your command handler code here
	timer = SetTimer(1, 1000, 0);
}

void CAdministrador_TareasDlg::OnVelocidadNormal()
{
	// TODO: Add your command handler code here
	timer = SetTimer(1, 2000, 0);
}

void CAdministrador_TareasDlg::OnVelocidadBaja()
{
	timer = SetTimer(1, 4000, 0);
}

void CAdministrador_TareasDlg::OnVelocidadPausar()
{
	KillTimer(timer);
}
