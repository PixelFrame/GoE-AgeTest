// QuesSet.h: interface for the CQuesSet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUESSET_H__9EAA306B_4496_406E_BAAB_B02A54C619A6__INCLUDED_)
#define AFX_QUESSET_H__9EAA306B_4496_406E_BAAB_B02A54C619A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

class CQuesSet  
{
public:
	int m_iScore[3];
	std::string m_strChoice[3];
	std::string m_strQues;
	CQuesSet();
	virtual ~CQuesSet();

};

#endif // !defined(AFX_QUESSET_H__9EAA306B_4496_406E_BAAB_B02A54C619A6__INCLUDED_)
