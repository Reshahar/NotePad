// NotePadDoc.h : interface of the CNotePadDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOTEPADDOC_H__8802B242_D2B2_41EC_995C_C9A5651A20E4__INCLUDED_)
#define AFX_NOTEPADDOC_H__8802B242_D2B2_41EC_995C_C9A5651A20E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNotePadDoc : public CDocument
{
protected: // create from serialization only
	CNotePadDoc();
	DECLARE_DYNCREATE(CNotePadDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNotePadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNotePadDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPADDOC_H__8802B242_D2B2_41EC_995C_C9A5651A20E4__INCLUDED_)
