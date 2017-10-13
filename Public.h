// Public.h: interface for the CPublic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUBLIC_H__D41FA39A_8727_4CCF_AB55_80073213D8EA__INCLUDED_)
#define AFX_PUBLIC_H__D41FA39A_8727_4CCF_AB55_80073213D8EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UserList.h"
#include "QuesList.h"
#include "Music.h"

class CPublic  
{
public:
	static int UserStatus;
	static CUserList list;
	static CQuesList qlist;
	static CMusic mus;
	CPublic();
	virtual ~CPublic();
};

#endif // !defined(AFX_PUBLIC_H__D41FA39A_8727_4CCF_AB55_80073213D8EA__INCLUDED_)
