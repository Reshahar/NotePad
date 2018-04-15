// MyLink.h: interface for the CMyLink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLINK_H__63D38410_FAB6_466B_9E20_F96CE83CC26B__INCLUDED_)
#define AFX_MYLINK_H__63D38410_FAB6_466B_9E20_F96CE83CC26B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct node
{
	CString data;
	node * pre; 
	node * next;
}NODE,*PNODE;
class CMyLink  
{
public:
	void EmptyLink();
	CMyLink();
	int Find(CString str,CString dest,int nStart);//字符串匹配
	void AddNode(CString x);
	void DelNode(int x);
	CString GetData(int n);
	int GetLen(){return len;}
	int FindUp(int x,int y,CString dest);
	int FindDown(int x,int y,CString dest);//x 行  y 列  dest 查找的字符串
	int FindString(CString dest,int line,int start,int IsDown);  //查找算法
	int GetPreCharNumber(int i);
	void SetData(CString str,int n);
	void Replace(CString dest,int x,int y,int s,int e);
	int  CountChar();
	int GetCharPos(int x,int y);
	virtual ~CMyLink();
private:
	PNODE pHead;
	int len;
};

#endif // !defined(AFX_MYLINK_H__63D38410_FAB6_466B_9E20_F96CE83CC26B__INCLUDED_)
