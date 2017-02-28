// Rendimiento.cpp : implementation file
//

#include "stdafx.h"
#include "Administrador_Tareas.h"
#include "Rendimiento.h"


// CRendimiento dialog

IMPLEMENT_DYNAMIC(CRendimiento, CPropertyPage)

CRendimiento::CRendimiento()
	: CPropertyPage(CRendimiento::IDD)
{

}

CRendimiento::~CRendimiento()
{
}

void CRendimiento::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRendimiento, CPropertyPage)
END_MESSAGE_MAP()


// CRendimiento message handlers
