#pragma once


// CRed dialog

class CRed : public CPropertyPage
{
	DECLARE_DYNAMIC(CRed)

public:
	CRed();
	virtual ~CRed();

// Dialog Data
	enum { IDD = IDD_RED };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
