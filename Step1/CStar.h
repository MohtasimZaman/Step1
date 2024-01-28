#pragma once
#include "afxdialogex.h"


// CStar dialog

class CStar : public CDialog
{
	DECLARE_DYNAMIC(CStar)

public:
	CStar(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStar();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PARAM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_centerx;
	double m_centery;
	double m_edgelength;
	double m_rotationd;
	double m_starRotationAngle;
public:
	afx_msg void OnStepstuffParameters();
	afx_msg void OnRotateStar();



};
