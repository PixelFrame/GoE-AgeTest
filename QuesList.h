// QuesList.h: interface for the CQuesList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUESLIST_H__53F6034F_70FC_41F8_BDAF_943903A9B687__INCLUDED_)
#define AFX_QUESLIST_H__53F6034F_70FC_41F8_BDAF_943903A9B687__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "QuesSet.h"

class CQuesList  
{
public:
	int num;
	CQuesList();
	virtual ~CQuesList();
	
	CQuesSet quesList[256];
private:
	BOOL loadQues();
};

#endif // !defined(AFX_QUESLIST_H__53F6034F_70FC_41F8_BDAF_943903A9B687__INCLUDED_)
