// MyLink.cpp: implementation of the CMyLink class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyLink.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyLink::CMyLink()
{
	pHead = new NODE;
	pHead->next = NULL;
	pHead->pre = NULL;
	len = 0;
}

CMyLink::~CMyLink()
{
	PNODE p;
	while(pHead!=NULL)
	{
		p = pHead;
		pHead = pHead->next;
		delete p;
	}		
}
void CMyLink::AddNode(CString x)//在最后加入
{
	PNODE p,q;
	p = new NODE;
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	q = pHead;
	while(q->next!=NULL)
		q = q->next;
	q->next = p;
	p->pre = q;
	len++;
}
void CMyLink::DelNode(int x)   //删除结点
{
	int count = 0;
	PNODE p,q;
	p = pHead;
	while(p->next!=NULL)
	{
		if(x==count)
			break;
		count++;
		p = p->next;
	}
	q = p->next;
	p->next->pre = p;
	p->next = q->next;
	len--;
	delete q;
}
CString CMyLink::GetData(int n)
{
	int count = 0;
	PNODE p;
	p = pHead->next;
	while(p!=NULL)
	{
		if(n==count)
			break;
		count++;
		p = p->next;
	}
	return p->data;
}


void CMyLink::EmptyLink()
{
	while(len)
		DelNode(0);
}
int CMyLink::FindDown(int x,int y,CString dest)
{
	int c,i,tmp,re;
	CString str("");
	if(x<len)	
	{
		y = y - GetPreCharNumber(x);	
		c = FindString(dest,x,y,1);  //  c相对光标那一行头的位置
		if(c!=-1)
		{
			re = c+GetPreCharNumber(x);			
			return re;//相对开始的位置
		}else
			return -1;//没查找到
	}
	return -1;
}
int CMyLink::GetPreCharNumber(int n)
{
	int num=0,i;
	for(i=0;i<n;i++)
	{
		num+=GetData(i).GetLength();
	}
	return num;
}
int CMyLink::FindString(CString dest,int line,int start,int IsDown)
{
	CString str(""),tmp;
	int i;
	if(IsDown==1)//finddown
	{
		while(line<len)
		{
			str+=GetData(line);
			line++;
		}
		//return str.Find(dest,start);
		return Find(str,dest,start);
	}else
	{
		i = 0;
		while(i<=line)
		{
			str+=GetData(i);
			i++;
		}
		str.MakeReverse();
		dest.MakeReverse();
		//return str.Find(dest,start);
		return Find(str,dest,start);
	}
}
void CMyLink::SetData(CString str,int n)
{
	int count = 0;
	PNODE p;
	p = pHead->next;
	while(p!=NULL)
	{
		if(n==count)
			break;
		count++;
		p = p->next;
	}
	p->data = str;
}
int CMyLink::FindUp(int x,int y,CString dest)
{
	int c;
	if(x<=len)
	{
		y = GetPreCharNumber(x+1) - y; 
		c = FindString(dest,x,y,0);
		if(c!=-1)
		{
			return GetPreCharNumber(x+1)-(c+dest.GetLength());
		}else
		{
			return -1;
		}
	}
}
void CMyLink::Replace(CString dest,int x,int y,int s,int e)
{
	CString str;
	str = GetData(x);
	s = s - GetPreCharNumber(x);
	e = e - GetPreCharNumber(x);
	str.Delete(s,(e-s));
	str.Insert(s,dest);
	SetData(str,x);
}
int CMyLink::Find(CString str,CString dest,int nStart)//字符串匹配算法
{
	int i,j=0;
	for(i=nStart;(i<str.GetLength())&&(j<dest.GetLength());)
	{
		if(str[i]==dest[j])
		{
			i++;
			j++;
		}else
		{
			i = i-j+1;
			j = 0;
		}
	}
	if(dest.GetLength()==j)
		return i-j;
	else
		return -1;
}
int CMyLink::CountChar()
{
	CString s,tmp;
	int i;
	for(i=0;i<len;i++)
	{
		tmp=GetData(i);
		tmp.TrimRight("\r\n");
		s+=tmp;
	}
	return s.GetLength();
}
int CMyLink::GetCharPos(int x,int y)
{
	CString str;
	int i;
	if(x>=len)
		return 0;
	else
	{
		str = GetData(x);
		y = y - GetPreCharNumber(x);
		for(i=0;i<(str.GetLength())&&(i<y);i++)
		{
			if(str[i]<0)
			{
				y--;
				i++;
			}
		}
		return y;
	}
}
