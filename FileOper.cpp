// FileOper.cpp: implementation of the CFileOper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NotePad.h"
#include "FileOper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileOper::CFileOper()
{

}

CFileOper::~CFileOper()
{

}
void CFileOper::ReadFile(CMyLink &m_link,CString FilePathName)//读文件
{
	CString line;
	CStdioFile myFile;
	if(myFile.Open(FilePathName,CStdioFile::modeRead))
	{
		while(myFile.ReadString(line))
		{
			line+="\r\n";
			m_link.AddNode(line);
		}

	}else
	{
		AfxMessageBox(_T("文件打开错误!"));
	}
	myFile.Close();

}
void CFileOper::WriteFile(CMyLink &m_link,CString FilePathName)//写文件
{
	int i;
	CString line;
	CStdioFile myFile;
	if(myFile.Open(FilePathName,CStdioFile::modeCreate|CStdioFile::modeWrite))
	{
		for(i=0;i<m_link.GetLen();i++)
		{
			line = m_link.GetData(i);
			myFile.WriteString(line);
		}
		myFile.Close();
	}else
	{
		AfxMessageBox(_T("文件打开错误!"));
	}	
}