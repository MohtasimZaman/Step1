
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Step1.h"
#include "ChildView.h"
#include "CLineDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() //Constructor
{
    m_linefmx = 0.5;
    m_linefmy = 0.5;
    m_linetox = 0.2;
    m_linetoy = 0.55;

    m_starCenterX = 0.5;
    m_starCenterY = 0.5;
    m_starRadius = 0.2;
    m_starRotationAngle = 0.0;
}

CChildView::~CChildView() //Destructor
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
    ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
    ON_COMMAND(ID_STEPSTUFF_ROTATESTAR, &CChildView::OnRotateStar)
   
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
    int width, height;
    GetSize(width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, // left
        GLdouble(width) / GLdouble(height), // right
        0.0, // bottom
        1.0, // top
        1.0, // near
        -1.0); // far

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(1., 0., 0.); // red rectangle

    //glBegin(GL_POLYGON);        //draws a polygon, vertices in counter-clockwise order. 
    //glVertex2d(0.25, 0.25);
    //glVertex2d(0.75, 0.25);
    //glVertex2d(0.75, 0.75);
    //glVertex2d(0.25, 0.75);
    //glEnd();

    //// Draw the line
    //glColor3d(0., 1., 0.); // Change the color to green
    //glBegin(GL_LINES);
    //glVertex2d(m_linefmx, m_linefmy);
    //glVertex2d(m_linetox, m_linetoy);
    //glEnd();

    // Draw the rectangle
    glColor3d(1., 0., 0.); // Change the color to red
    glBegin(GL_LINE_LOOP);
    double rectangleRadius = sqrt(2) * m_starRadius; // Radius of the rectangle
    for (int i = 0; i < 4; ++i) {
        double angle = m_starRotationAngle + 2 * acos(-1.0) * i / 4; // Calculate the angle for each vertex
        double x = m_starCenterX + rectangleRadius * cos(angle);
        double y = m_starCenterY + rectangleRadius * sin(angle);
        glVertex2d(x, y);
    }
    glEnd();


    // Draw the hendecagram
    glColor3d(0., 1., 0.); // Change the color to green
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= 10; ++i) {
        double angle = m_starRotationAngle + 2 * acos(-1.0) * i / 11; // Calculate the angle for each vertex
        double x = m_starCenterX + m_starRadius * cos(angle);
        double y = m_starCenterY + m_starRadius * sin(angle);
        glVertex2d(x, y);
    }
    glEnd();
}



void CChildView::OnStepstuffLineendto0()
{
    ////TODO: Add your command handler code here
    CLineDlg dlg;
    

    dlg.m_fmx = m_linefmx;
    dlg.m_fmy = m_linefmy;
    dlg.m_tox = m_linetox;
    dlg.m_toy = m_linetoy;

    dlg.m_starCenterX = m_starCenterX;
    dlg.m_starCenterY = m_starCenterY;
    dlg.m_starRadius = m_starRadius;
    dlg.m_starRotationAngle = m_starRotationAngle;

    if (dlg.DoModal() == IDOK)
    {
        m_linefmx = dlg.m_fmx;
        m_linefmy = dlg.m_fmy;
        m_linetox = dlg.m_tox;
        m_linetoy = dlg.m_toy;

        m_starCenterX = dlg.m_starCenterX;
        m_starCenterY = dlg.m_starCenterY;
        m_starRadius = dlg.m_starRadius;
        m_starRotationAngle = dlg.m_starRotationAngle;

       Invalidate();
    }
}

void CChildView::OnRotateStar()
{
    m_starRotationAngle += 25 * acos(-1.0) / 180; // Rotate the star by 25 degrees
    Invalidate();
}



