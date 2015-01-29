
// myselfSet.cpp : CmyselfSet ���ʵ��
//

#include "stdafx.h"
#include "myself.h"
#include "myselfSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyselfSet ʵ��

// ���������� 2015��1�� ���ڶ�, 17:41

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
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Double(pFX, _T("[money]"), m_money);

}
/////////////////////////////////////////////////////////////////////////////
// CmyselfSet ���

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

