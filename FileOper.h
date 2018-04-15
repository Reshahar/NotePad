// FileOper.h: interface for the CFileOper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEOPER_H__10CC5B6C_12C4_42AA_A71F_9178D5F4007D__INCLUDED_)
#define AFX_FILEOPER_H__10CC5B6C_12C4_42AA_A71F_9178D5F4007D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyLink.h"

class CFileOper  
{
public:
	CFileOper();
	void ReadFile(CMyLink &m_link,CString FilePathName);
	void WriteFile(CMyLink &m_link,CString FilePathName);
	virtual ~CFileOper();

};

#endif // !defined(AFX_FILEOPER_H__10CC5B6C_12C4_42AA_A71F_9178D5F4007D__INCLUDED_)
