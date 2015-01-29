
// myselfView.cpp : CmyselfView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "myself.h"
#endif

#include "myselfSet.h"
#include "myselfDoc.h"
#include "myselfView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmyselfView

IMPLEMENT_DYNCREATE(CmyselfView, CRecordView)

BEGIN_MESSAGE_MAP(CmyselfView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CmyselfView::OnLbnSelchangeList1)
ON_BN_CLICKED(IDC_BUTTON_context, &CmyselfView::OnBnClickedButtoncontext)
ON_BN_CLICKED(IDC_BUTTON_takedata, &CmyselfView::OnBnClickedButtontakedata)
END_MESSAGE_MAP()

// CmyselfView ����/����

CmyselfView::CmyselfView()
	: CRecordView(CmyselfView::IDD)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CmyselfView::~CmyselfView()
{
}

void CmyselfView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Control(pDX, IDC_LIST, list);
	
}

BOOL CmyselfView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CmyselfView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_myselfSet;
	CRecordView::OnInitialUpdate();
	//���������
	list.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	list.SetTextColor(RGB(0,0,0));
	list.SetBkColor(RGB(255,255,255));
	list.InsertColumn(0,"ID",LVCFMT_CENTER,100,0);
	list.InsertColumn(1,"name",LVCFMT_CENTER,100,0);
	list.InsertColumn(2,"money",LVCFMT_CENTER,200,0);
	ID="";
	name="";
	money="";
}

// CmyselfView ��ӡ
BOOL CmyselfView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmyselfView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmyselfView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CmyselfView ���

#ifdef _DEBUG
void CmyselfView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CmyselfView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CmyselfDoc* CmyselfView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyselfDoc)));
	return (CmyselfDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyselfView ���ݿ�֧��
CRecordset* CmyselfView::OnGetRecordset()
{
	return m_pSet;
}



// CmyselfView ��Ϣ�������


void CmyselfView::OnBnClickedButtoncontext()
{
	CString DSCNname="DSN=myself source";
	record=new CRecordset(&DB);
	
	if(!DB.OpenEx(DSCNname,0))
	{
		MessageBox("���ݿ�û�����ӣ�");
	}
	else
	{
		MessageBox("�Ѿ��������ݿ�");
	}
	if(!record->IsOpen())
	{
		MessageBox("��¼û�ܴ�,�����ֶ�����");
		record->Open(CRecordset::dynaset,"SELECT * FROM PayInfo");
	}
	else
	{
		MessageBox("��¼�Ѿ���");
	}
	if(record->IsEOF())
	{
		MessageBox("��¼Ϊ��");
		return;
	}

/*	
	1. if (!m_pRecSet->IsOpen())  
	2.         m_pRecSet->Open(CRecordset::dynaset,   
	3.             _T("SELECT * FROM BasicInfo")); 

*/


}

void CmyselfView::OnBnClickedButtontakedata()
{
	UpdateData();

	record->MoveFirst();
	int index;
	for(;!(record->IsEOF());)
	{
		record->GetFieldValue((short)0,ID);//GetFieldValue���Ի�õ�ǰ��¼���ֶε�ֵ�����ֶ�ֵ�����ڶ�������,
		record->GetFieldValue((short)1,name);//������ͨ����ȡ����
		record->GetFieldValue((short)2,money);

		index=list.GetItemCount();//�Ա�����г�ʼ��
		LV_ITEM lvitem;
		lvitem.iItem=index;
		lvitem.mask=LVFIF_TEXT;
		lvitem.iSubItem=0;
		lvitem.pszText=(char *)(LPCTSTR)ID;
		
		list.InsertItem(&lvitem);		//����һ��
		list.SetItemText(index,0,ID);
		list.SetItemText(index,1,name);
		list.SetItemText(index,2,money);
		
		ID="";		//�����ݽ������
		name="";
		money="";
		index=0;

		record->MoveNext();
	}


	MessageBox("������ȡ���");

	UpdateData(false);
}