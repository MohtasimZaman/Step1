// ClineDlg.cpp : implementation file
//

#include "pch.h"
#include "Step1.h"
#include "afxdialogex.h"
#include "CLineDlg.h"
#include <math.h>


#define _USE_MATH_DEFINES


// ClineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LINEDLG, pParent)
	, m_fmx(0)
	, m_fmy(0)
	, m_tox(0)
	, m_toy(0)
{
	/*m_starCenterX = 0.5;
	m_starCenterY = 0.5;
	m_starRadius = 0.2;
	m_starRotationAngle = 0.0;*/


}

CLineDlg::~CLineDlg()
{
}



void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FMX, m_fmx);
	DDX_Text(pDX, IDC_FMY, m_fmy);
	DDX_Text(pDX, IDC_TOX, m_tox);
	DDX_Text(pDX, IDC_TOY, m_toy);
	
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
END_MESSAGE_MAP()


// ClineDlg message handlers


