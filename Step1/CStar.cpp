// CStar.cpp : implementation file
//

#include "pch.h"
#include "Step1.h"
#include "afxdialogex.h"
#include "CStar.h"


// CStar dialog

IMPLEMENT_DYNAMIC(CStar, CDialog)

CStar::CStar(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PARAM, pParent)
	, m_centerx(0)
	, m_centery(0)
	, m_edgelength(0)
	, m_rotationd(0)
{
	m_starRotationAngle = 0.0;
}

CStar::~CStar()
{
}

void CStar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CENTERX, m_centerx);
	DDX_Text(pDX, IDC_CENTERY, m_centery);
	DDX_Text(pDX, IDC_EDGELEN, m_edgelength);
	DDX_Text(pDX, IDC_ROTDEG, m_rotationd);
}


BEGIN_MESSAGE_MAP(CStar, CDialog)
END_MESSAGE_MAP()


// CStar message handlers

void CStar::OnRotateStar()
{
	m_starRotationAngle += (25+90) * (acos(-1.0) / 180.0); 
	Invalidate();
}


//void CStar::OnStepstuffParameters()
//{
	//CStar dlg;

	//dlg.m_centerx = m_centerx;
	//dlg.m_centery = m_centery;
	//dlg.m_edgelength = m_edgelength;
	//dlg.m_rotationd = m_rotationd;

	//if (dlg.DoModal() == IDOK)
	//{
	//	m_centerx = dlg.m_centerx;
	//	m_centery = dlg.m_centery;
	//	m_edgelength = dlg.m_edgelength;
	//	m_rotationd = dlg.m_rotationd;

	//	m_starRotationAngle = m_rotationd * (acos(-1.0) / 180.0); 

	//	Invalidate();
	//}
//}

