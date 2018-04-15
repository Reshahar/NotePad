// NotePadView.cpp : implementation of the CNotePadView class
//

#include "stdafx.h"
#include "NotePad.h"


#include "NotePadDoc.h"
#include "NotePadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
bool flag = false;
int count = 0;
/////////////////////////////////////////////////////////////////////////////
// CNotePadView

IMPLEMENT_DYNCREATE(CNotePadView, CEditView)

BEGIN_MESSAGE_MAP(CNotePadView, CEditView)
	//{{AFX_MSG_MAP(CNotePadView)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(IDC_FONT, OnFont)
	ON_WM_CREATE()
	ON_COMMAND(IDC_FIND, OnFind)
	ON_COMMAND(IDC_REPLACE, OnReplace)
	ON_COMMAND(IDC_SELALL, OnSelall)
	ON_CONTROL_REFLECT(EN_CHANGE, OnChange)
	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, OnFindReplace)
	ON_WM_LBUTTONUP()
	ON_WM_KEYUP()
	ON_COMMAND(IDC_COUNT, OnCount)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotePadView construction/destruction

CNotePadView::CNotePadView()
{
	// TODO: add construction code here
	pMain =NULL;
	LOGFONT lf;
	memset(&lf,0,sizeof(LOGFONT));
	strcpy(lf.lfFaceName, "宋体");
	lf.lfHeight = 20;
	m_font.CreateFontIndirect(&lf);
}

CNotePadView::~CNotePadView()
{
}

BOOL CNotePadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping
	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CNotePadView drawing

void CNotePadView::OnDraw(CDC* pDC)
{
	CNotePadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNotePadView diagnostics

#ifdef _DEBUG
void CNotePadView::AssertValid() const
{
	CEditView::AssertValid();
}

void CNotePadView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CNotePadDoc* CNotePadView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNotePadDoc)));
	return (CNotePadDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNotePadView message handlers

void CNotePadView::OnFileNew() 
{
	// TODO: Add your command handler code here
	
	CString title;
	int re;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->GetWindowText(m_title);
	if((m_title.Compare(CTITLE)!=0)&&(m_title.Compare(CDEFTITLE)!=0))
	{
		if(m_title[m_title.GetLength()-1]=='*')
		{
			re = MessageBox(_T("是否保存"),NULL,MB_YESNOCANCEL);
			if(re==IDYES)
			{
				Save(1);
				m_title = DEFTITLE;
				m_link.EmptyLink();
				SetWindowText(_T(""));
				pMain->SetWindowText(m_title);
			}else if(re==IDNO)
			{
				m_title = DEFTITLE;
				m_link.EmptyLink();
				SetWindowText(_T(""));
				pMain->SetWindowText(m_title);
			}else
			{
				return;
			}
		}else
		{
			m_title = DEFTITLE;
			m_link.EmptyLink();
			SetWindowText(_T(""));
			pMain->SetWindowText(m_title);
		}
	}else
	{
		Save(0);
		m_title = DEFTITLE;
		m_link.EmptyLink();
		SetWindowText(m_title);
	}
}

void CNotePadView::OnFileSave() 
{
	// TODO: Add your command handler code here
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->GetWindowText(m_title);
	if((m_title.Compare(CTITLE)!=0)&&(m_title.Compare(CDEFTITLE)!=0)&&(m_title.Compare(DEFTITLE)!=0)&&(m_title.Compare(TITLE)!=0))
	{
		Save(1);//直接保存
	}else
	{
		Save(0);//弹框
	}
}

void CNotePadView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	Save(0);
}

void CNotePadView::OnFileOpen() //文件打开函数
{
	int re;
	CString File = _T("文本文件(*.txt)|*.txt");
	CString FilePathName;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->GetWindowText(m_title);
	if(m_title[m_title.GetLength()-1]=='*')
	{
		re = MessageBox(_T("是否保存"),NULL,MB_YESNOCANCEL);
		if(re==IDYES)
		{
			OnFileSave();
		}else if(re==IDNO)
		{
			m_title = DEFTITLE;
			m_link.EmptyLink();
			SetWindowText(_T(""));
			pMain->SetWindowText(m_title);
		}else
		{
			return;
		}
	}
	CFileDialog MyFile(TRUE,_T("txt"),NULL,0,File,this);
	if(MyFile.DoModal()==IDOK)
	{
		FilePathName = MyFile.GetPathName();
		m_title = FilePathName;
		m_link.EmptyLink();
		m_FileOper.ReadFile(m_link,FilePathName);
		Show();							//将链表中的数据显示显示到视图中
		pMain->SetWindowText(m_title);
		m_FilePathName = FilePathName;
	}
}

void CNotePadView::Save(int c)
{	
	CString File = _T("文本文件(*.txt)|*.txt");
	CString FilePathName;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	if(c==1) 
	{
		m_link.EmptyLink();
		MakeStrToNode();
		m_FileOper.WriteFile(m_link,m_FilePathName);
		pMain->SetWindowText(m_FilePathName);
	}else
	{
		CFileDialog MyFile(FALSE,_T("txt"),NULL,0,File,this);
		m_link.EmptyLink();
		MakeStrToNode();
		if(MyFile.DoModal()==IDOK)
		{
			FilePathName = MyFile.GetPathName();
			m_FileOper.WriteFile(m_link,FilePathName);
			m_FilePathName = FilePathName;
			pMain->SetWindowText(m_FilePathName);
		}
	}

}

void CNotePadView::MakeStrToNode()
{
	
	int i;
	CString str,line;
	int len = GetEditCtrl().GetLineCount();
	GetWindowText(str);
	for(i=0;i<len;i++)
	{
		AfxExtractSubString(line,str,i);
		line.TrimRight("\r\n"); 
		line+="\r\n";
		m_link.AddNode(line);
	}
}

void CNotePadView::Show()
{
	int i,len = m_link.GetLen();
	CString str;
	for(i=0;i<len;i++)
	{
		str+=m_link.GetData(i);
	}
	SetWindowText(str);
}

void CNotePadView::OnFont() 
{
	// TODO: Add your command handler code here
	LOGFONT PreLF;
	CFont *pFont = CEditView::GetEditCtrl().GetFont();
	if(pFont)
	{
		pFont->GetLogFont(&PreLF);
		CFontDialog myFont(&PreLF,CF_INITTOLOGFONTSTRUCT|CF_SCREENFONTS);	
		if(myFont.DoModal()==IDOK)
		{
			if(m_font.m_hObject)
			{
				m_font.DeleteObject();
			}
			m_font.CreateFontIndirect(myFont.m_cf.lpLogFont);
			GetEditCtrl().SetFont(&m_font);
			Show();
		}
	}
}

int CNotePadView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CEditView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetFont(&m_font);
	return 0;
}

void CNotePadView::OnFind() 
{
	// TODO: Add your command handler code here
	FindReplace(true);
}

void CNotePadView::OnReplace() 
{
	// TODO: Add your command handler code here
	FindReplace(false);
}

void CNotePadView::OnSelall() 
{
	// TODO: Add your command handler code here
	GetEditCtrl().SetSel(0,-1);
}

void CNotePadView::Close()
{
	int re;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->GetWindowText(m_title);
	if(m_title[m_title.GetLength()-1]=='*')
	{
		re = MessageBox(_T("是否保存"),NULL,MB_YESNOCANCEL);
		if(re==IDYES)
		{
			OnFileSave();
		}else if(re==IDNO)
		{
			m_title = DEFTITLE;
			m_link.EmptyLink();
			SetWindowText(_T(""));
			pMain->SetWindowText(m_title);
		}else
		{
			return;
		}
	}
	//AfxGetMainWnd()->SendMessage(WM_CLOSE);
}


void CNotePadView::OnChange() 
{
	// TODO: Add your control notification handler code here
	CString New_title;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->GetWindowText(m_title);
	if(m_title[m_title.GetLength()-1]!='*')
	{
		New_title = m_title + "*";
		pMain->SetWindowText(New_title);
		m_title = New_title;
	}
}
LONG CNotePadView::OnFindReplace(WPARAM wParam, LPARAM lParam)
{
	CFindReplaceDialog* pDlg = CFindReplaceDialog::GetNotifier(lParam);
	if(pDlg)
	{
		if (pDlg->IsTerminating()) 
		{
			point = 0;
			count = 0;
			flag = false;
		}
		if(pDlg->FindNext())
		{
			if(pDlg->SearchDown())
				FindDown(pDlg->GetFindString(),1);
			else
				FindUp(pDlg->GetFindString());	
		}else if(pDlg->ReplaceCurrent())
		{	
			Replace(pDlg->GetFindString(),pDlg->GetReplaceString(),1);
			Show();
		}else if(pDlg->ReplaceAll())
		{
			ReplaceAll(pDlg->GetFindString(),pDlg->GetReplaceString());
		}
	}
	return 1;
}

int CNotePadView::FindDown(CString s, int IsShow)//向下查找
{
	int re,l,tmp=0;
	CString str;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->SetActiveWindow();			//激活窗口
	CPoint cp = GetEditCtrl().GetCaretPos();
	tmp = GetEditCtrl().CharFromPos(cp);
	if(tmp!=point)
		point = tmp;
	re = m_link.FindDown(HIWORD(point),LOWORD(point),s);
	l = s.GetLength();
	if(re!=-1)
	{
		GetEditCtrl().SetSel(re,re+l);
		pMain->SetActiveWindow();
		return 1;
	}else
	{
		if(IsShow)
		{
			str.Format("%s\"%s\"",_T("找不到"),s);
			MessageBox(str);
		}
		return 0;
   	} 
}

void CNotePadView::FindUp(CString s)	//向上查找
{	
	int re,l,tmp;
	CString str;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->SetActiveWindow();			//激活窗口
	CPoint cp = GetEditCtrl().GetCaretPos();
	point = GetEditCtrl().CharFromPos(cp);
	if(count!=0)
	{
		tmp = LOWORD(point);
		if(s[s.GetLength()-1]<0)
			tmp -= 2;
		else
			tmp -= 1;
	}else
	{
		tmp = LOWORD(point);
	}
	count++;
	re = m_link.FindUp(HIWORD(point),tmp,s);
	l = s.GetLength();
	if(re!=-1)
	{
		GetEditCtrl().SetSel(re,re+l);
		pMain->SetActiveWindow();
	}else
	{
		str.Format("%s\"%s\"",_T("找不到"),s);
		MessageBox(str);
   	}

}


int CNotePadView::Replace(CString ss, CString dest, int IsShow)
{
	CPoint cp;
	CString str;
	int s,e;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->SetActiveWindow();			//设置活动窗口
	cp = GetEditCtrl().GetCaretPos();
	point = GetEditCtrl().CharFromPos(cp);
	GetEditCtrl().GetSel(s,e);
	if(s!=e)
	{
		m_link.Replace(dest,HIWORD(point),LOWORD(point),s,e);
		return 1;
	}else 
	{
		if(FindDown(ss,IsShow))
		{
			cp = GetEditCtrl().GetCaretPos();
			point = GetEditCtrl().CharFromPos(cp);
			GetEditCtrl().GetSel(s,e);
			m_link.Replace(dest,HIWORD(point),LOWORD(point),s,e);
			return 2;	
		}
	}
	return 0;
}

void CNotePadView::ReplaceAll(CString ss, CString dest)
{
	CPoint cp;
	while(1)
	{
		if(Replace(ss,dest,0))
			Show();
		else
			break;
	}
}

void CNotePadView::FindReplace(bool IsFind) //查找菜单
{
	if(!flag)
	{
		CFindReplaceDialog * my = new CFindReplaceDialog;
		flag = true;
		if(!my->Create(IsFind,NULL,NULL,FR_HIDEWHOLEWORD|FR_DOWN|FR_HIDEMATCHCASE,this))
			return ;
	}
}


void CNotePadView::GetPos(int &l, int &r)
{
	CPoint cp;
	int tmp;
	if(pMain==NULL)
		pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pMain->SetActiveWindow();
	cp = GetEditCtrl().GetCaretPos();
	tmp = GetEditCtrl().CharFromPos(cp);
	l = HIWORD(tmp);
	r = m_link.GetCharPos(HIWORD(tmp),LOWORD(tmp));
}

void CNotePadView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int l=0,r=0;
	CString sl,sr;
	GetPos(l,r);
	sl.Format("行号 %d",l+1);
	sr.Format("列号 %d",r+1);
	pMain->SetLineRow(sl,sr);
	CEditView::OnLButtonUp(nFlags, point);
}

void CNotePadView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar)
	{
		int l=0,r=0;
		CString sl,sr;
		GetPos(l,r);
		sl.Format("行号 %d",l+1);
		sr.Format("列号 %d",r+1);
		pMain->SetLineRow(sl,sr);
	}
	CEditView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CNotePadView::OnCount() 
{
	// TODO: Add your command handler code here
	CString str;
	str.Format("字符数为%d个",m_link.CountChar());
	MessageBox(str);
}
