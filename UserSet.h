// UserSet.h: interface for the CUserSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERSET_H__BE4F312B_C8A3_40E1_BD4C_8B56334547FB__INCLUDED_)
#define AFX_USERSET_H__BE4F312B_C8A3_40E1_BD4C_8B56334547FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUserSet  
{
public:
	int m_iActualAge;
	void editUser(char* name, char* pass, BOOL isAdmin, int testRes, int actualAge);
	CString m_strUsername;	
	BOOL m_bIsAdmin;
	CString m_strPassword;
	int m_iTestResult;
	CUserSet(CString& name=CString("Guest"), CString& pass=CString(""), BOOL isAdmin=FALSE);
	virtual ~CUserSet();

protected:

private:
	
};

#endif // !defined(AFX_USERSET_H__BE4F312B_C8A3_40E1_BD4C_8B56334547FB__INCLUDED_)
