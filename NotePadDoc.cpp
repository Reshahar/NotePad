// NotePadDoc.cpp : implementation of the CNotePadDoc class
//

#include "stdafx.h"
#include "NotePad.h"

#include "NotePadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotePadDoc

IMPLEMENT_DYNCREATE(CNotePadDoc, CDocument)

BEGIN_MESSAGE_MAP(CNotePadDoc, CDocument)
	//{{AFX_MSG_MAP(CNotePadDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotePadDoc construction/destruction

CNotePadDoc::CNotePadDoc()
{
	// TODO: add one-time construction code here

}

CNotePadDoc::~CNotePadDoc()
{
}

BOOL CNotePadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNotePadDoc serialization

void CNotePadDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CNotePadDoc diagnostics

#ifdef _DEBUG
void CNotePadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNotePadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNotePadDoc commands
