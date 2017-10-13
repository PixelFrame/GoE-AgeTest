// UserSet.cpp: implementation of the CUserSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GoE AgeTest.h"
#include "UserSet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUserSet::CUserSet(CString& name, CString& pass, BOOL isAdmin)
{
	m_strUsername = name;
	m_strPassword = pass;
	m_bIsAdmin = isAdmin;
	m_iTestResult = 0;
	m_iActualAge = 0;
}

CUserSet::~CUserSet()
{

}

void CUserSet::editUser(char* name, char* pass, BOOL isAdmin, int testRes, int actualAge)
{
	m_strUsername.Format("%s",name);
	m_strPassword.Format("%s",pass);
	m_bIsAdmin = isAdmin;
	m_iTestResult = testRes;
	m_iActualAge = actualAge;
}

