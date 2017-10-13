// UserList.h: interface for the CUserList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERLIST_H__22A177E9_F588_4697_81AA_704AB9778122__INCLUDED_)
#define AFX_USERLIST_H__22A177E9_F588_4697_81AA_704AB9778122__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UserSet.h"

class CUserList  
{
public:
	CUserSet userList[256];
	CUserSet m_currentUser;
	int userNum;

	CUserList();
	virtual ~CUserList();
	void updateCurrData();
	BOOL Search(CString& name, CString& pass);
	BOOL loadUser();
	void saveList();
	void deleteUser(int num);
	BOOL searchUsername(CString& name);

private:
	int m_iActualAge;
	char m_cNameBuf[50];
	char m_cPassBuf[50];
	int m_iTestRes;
	BOOL m_bIsAdmin;
	void addUser(CUserSet&);
};

#endif // !defined(AFX_USERLIST_H__22A177E9_F588_4697_81AA_704AB9778122__INCLUDED_)
