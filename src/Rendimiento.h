#pragma once


// CRendimiento dialog

class CRendimiento : public CPropertyPage
{
	DECLARE_DYNAMIC(CRendimiento)

public:
	CRendimiento();
	virtual ~CRendimiento();

// Dialog Data
	enum { IDD = IDD_RENDIMIENTO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
