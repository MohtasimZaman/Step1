
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "graphics/OpenGLWnd.h"


// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;

	double m_starCenterX;
	double m_starCenterY;
	double m_starRadius;
	double m_starRotationAngle;

	double m_centerx;
	double m_centery;
	double m_edgelength;
	double m_rotationd;



// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	virtual void OnGLDraw(CDC* pDC);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnRotateStar();
	afx_msg void OnStepstuffParameters();
};

