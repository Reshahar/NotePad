// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "NotePad.h"

#include "MainFrm.h"
#include  "NotePadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_LINE,
	ID_INDICATOR_ROW,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	CRect rect;
	GetClientRect(&rect);
	m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,SBPS_NORMAL,(rect.Width()/4)*3);
	m_wndStatusBar.SetPaneInfo(1,ID_INDICATOR_LINE,SBPS_NORMAL,(rect.Width()/8));
	m_wndStatusBar.SetPaneInfo(2,ID_INDICATOR_ROW,SBPS_NORMAL,(rect.Width()/8));
	m_wndStatusBar.SetPaneText(1,"ÐÐºÅ 1");
	m_wndStatusBar.SetPaneText(2,"ÁÐºÅ 1");
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszName = "NotePad++";
	cs.style &= ~FWS_ADDTOTITLE;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers



void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	((CNotePadView *)GetActiveView())->Close();
	this->DestroyWindow();
}

void CMainFrame::OnAppExit() 
{
	// TODO: Add your command handler code here
	OnClose();
}

void CMainFrame::SetLineRow(CString sl, CString sr)
{
	m_wndStatusBar.SetPaneText(1,sl);
	m_wndStatusBar.SetPaneText(2,sr);
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CFrameWnd::OnSize(nType, cx, cy);
	CRect rect;
	GetClientRect(&rect);
	if(m_wndStatusBar)
	{
		m_wndStatusBar.SetPaneInfo(0,ID_SEPARATOR,SBPS_NORMAL,(rect.Width()/4)*3);
		m_wndStatusBar.SetPaneInfo(1,ID_INDICATOR_LINE,SBPS_NORMAL,(rect.Width()/8));
		m_wndStatusBar.SetPaneInfo(2,ID_INDICATOR_ROW,SBPS_NORMAL,(rect.Width()/8));
	}
	
}
