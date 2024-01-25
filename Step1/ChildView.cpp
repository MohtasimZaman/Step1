
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Step1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnGLDraw(CDC* pDC)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Simple rectangle example
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,   // left
        1.0,   // right
        0.0,   // bottom
        1.0,   // top
        -1.0,  // near
        1.0);  // far

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(1., 0., 0.);

    glBegin(GL_POLYGON);        //draws a polygon, vertices in counter-clockwise order. 
    glVertex2d(0.25, 0.25);
    glVertex2d(0.75, 0.25);
    glVertex2d(0.75, 0.75);
    glVertex2d(0.25, 0.75);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(0.1, 0.1);
    glVertex2d(0.8, 0.22);
    glVertex2d(0.78, 0.9);
    glVertex2d(0.2, 0.9);
    glEnd();
}

