
// myselfSet.cpp : CmyselfSet 类的实现
//

#include "stdafx.h"
#include "myself.h"
#include "myselfSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyselfSet 实现

// 代码生成在 2015年1月 星期二, 17:41

IMPLEMENT_DYNAMIC(CmyselfSet, CRecordset)

CmyselfSet::CmyselfSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_name = L"";
	m_money = 0.0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CmyselfSet::GetDefaultConnect()
{
	return _T("DSN=myself source;DBQ=C:\\USERS\\ADMINISTRATOR\\DOCUMENTS\\MICROSOFT ACCESS\\meself.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CmyselfSet::GetDefaultSQL()
{
	return _T("[PayInfo]");
}

void CmyselfSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Double(pFX, _T("[money]"), m_money);

}
/////////////////////////////////////////////////////////////////////////////
// CmyselfSet 诊断

#ifdef _DEBUG
void CmyselfSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CmyselfSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

