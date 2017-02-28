#pragma once
#include "afxcmn.h"

#include ".\Managers\Aplicacion\AppManager.h"
// CAplicaciones dialog

class CAplicaciones : public CPropertyPage
{
	DECLARE_DYNAMIC(CAplicaciones)
private:
	CAppManager managerAplicaciones;
public:
	CListCtrl listaAplicaciones;
	CAplicaciones();
	virtual ~CAplicaciones();
	virtual BOOL OnInitDialog();
	void DibujarComponentes();
// Dialog Data
	enum { IDD = IDD_APLICACIONES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
