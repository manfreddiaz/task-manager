#pragma once
#include "afxcmn.h"

#include ".\Managers\Procesos\ProcManager.h"
// CProcesos dialog

class CProcesos : public CPropertyPage
{
	DECLARE_DYNAMIC(CProcesos)
private:
	CProcManager managerProcesos;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()
public:
	CProcesos();
	virtual ~CProcesos();

	enum { IDD = IDD_PROCESO };
	CListCtrl listaProcesos;
	virtual BOOL OnInitDialog();
	void DibujarComponentes();
public:
//	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton1();
};
