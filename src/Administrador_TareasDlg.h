// Administrador_TareasDlg.h: archivo de encabezado
//

#pragma once
#include "HojaPropiedades.h"
#include "afxwin.h"


// Cuadro de di�logo de CAdministrador_TareasDlg
class CAdministrador_TareasDlg : public CDialog
{
// Construcci�n
public:
	CAdministrador_TareasDlg(CWnd* pParent = NULL);	// Constructor est�ndar

// Datos del cuadro de di�logo
	enum { IDD = IDD_ADMINISTRADOR_TAREAS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV
	CHojaPropiedades propiedadesTab;

// Implementaci�n
protected:
	HICON m_hIcon;

	// Funciones de asignaci�n de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	UINT_PTR timer;
	afx_msg void OnVelocidadAlta();
	afx_msg void OnVelocidadNormal();
	afx_msg void OnVelocidadBaja();
	afx_msg void OnVelocidadPausar();
};
