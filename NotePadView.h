// NotePadView.h : interface of the CNotePadView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTEPADVIEW_H__19B9CD8F_4B43_4112_ABBD_5250419E1D5B__INCLUDED_)
#define AFX_NOTEPADVIEW_H__19B9CD8F_4B43_4112_ABBD_5250419E1D5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
const int WM_FINDREPLACE = ::RegisterWindowMessage(FINDMSGSTRING);
#endif // _MSC_VER > 1000
#include "MainFrm.h"
#include "FileOper.h"

const CString TITLE = "NotePad++";
const CString DEFTITLE = "Note";
const CString CTITLE = "NotePad++*";
const CString CDEFTITLE = "Note*";

class CNotePadDoc;
class CNotePadView : public CEditView
{
protected: // create from serialization only
	CNotePadView();
	DECLARE_DYNCREATE(CNotePadView)

// Attributes
public:
	CNotePadDoc* GetDocument();

// Operations
public:
	void Close();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNotePadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNotePadView)
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileOpen();
	afx_msg void OnFont();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnFind();
	afx_msg void OnReplace();
	afx_msg void OnSelall();
	afx_msg void OnChange();
	afx_msg LONG OnFindReplace(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnCount();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void GetPos(int &l,int &r);
	void FindReplace(bool IsFind);
	void ReplaceAll(CString ss, CString dest);
	int Replace(CString ss,CString dest,int IsShow);
	void FindUp(CString s);
	int FindDown(CString s,int IsShow);
	void Show();
	void MakeStrToNode();
	void Save(int c);
	CMainFrame * pMain;
	CFileOper m_FileOper;
	CMyLink m_link;
	CString m_title;
//	CRect m_rect;
	CString m_FilePathName;
	CFont m_font;
	int point;
};

#ifndef _DEBUG  // debug version in NotePadView.cpp
inline CNotePadDoc* CNotePadView::GetDocument()
   { return (CNotePadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPADVIEW_H__19B9CD8F_4B43_4112_ABBD_5250419E1D5B__INCLUDED_)
