// Red.cpp : implementation file
//

#include "stdafx.h"
#include "Administrador_Tareas.h"
#include "Red.h"


// CRed dialog

IMPLEMENT_DYNAMIC(CRed, CPropertyPage)

CRed::CRed()
	: CPropertyPage(CRed::IDD)
{

}

CRed::~CRed()
{
}

void CRed::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRed, CPropertyPage)
END_MESSAGE_MAP()


// CRed message handlers
