
// myselfView.cpp : CmyselfView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CmyselfView::OnLbnSelchangeList1)
ON_BN_CLICKED(IDC_BUTTON_context, &CmyselfView::OnBnClickedButtoncontext)
ON_BN_CLICKED(IDC_BUTTON_takedata, &CmyselfView::OnBnClickedButtontakedata)
END_MESSAGE_MAP()

// CmyselfView 构造/析构

CmyselfView::CmyselfView()
	: CRecordView(CmyselfView::IDD)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CmyselfView::~CmyselfView()
{
}

void CmyselfView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Control(pDX, IDC_LIST, list);
	
}

BOOL CmyselfView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CmyselfView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_myselfSet;
	CRecordView::OnInitialUpdate();
	//开发者添加
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

// CmyselfView 打印
BOOL CmyselfView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmyselfView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmyselfView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmyselfView 诊断

#ifdef _DEBUG
void CmyselfView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CmyselfView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CmyselfDoc* CmyselfView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmyselfDoc)));
	return (CmyselfDoc*)m_pDocument;
}
#endif //_DEBUG


// CmyselfView 数据库支持
CRecordset* CmyselfView::OnGetRecordset()
{
	return m_pSet;
}



// CmyselfView 消息处理程序


void CmyselfView::OnBnClickedButtoncontext()
{
	CString DSCNname="DSN=myself source";
	record=new CRecordset(&DB);
	
	if(!DB.OpenEx(DSCNname,0))
	{
		MessageBox("数据库没能连接！");
	}
	else
	{
		MessageBox("已经连接数据库");
	}
	if(!record->IsOpen())
	{
		MessageBox("记录没能打开,即将手动设置");
		record->Open(CRecordset::dynaset,"SELECT * FROM PayInfo");
	}
	else
	{
		MessageBox("记录已经打开");
	}
	if(record->IsEOF())
	{
		MessageBox("记录为空");
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
		record->GetFieldValue((short)0,ID);//GetFieldValue可以获得当前记录中字段的值并将字段值传给第二个参数,
		record->GetFieldValue((short)1,name);//从数据通道获取数据
		record->GetFieldValue((short)2,money);

		index=list.GetItemCount();//对标题进行初始化
		LV_ITEM lvitem;
		lvitem.iItem=index;
		lvitem.mask=LVFIF_TEXT;
		lvitem.iSubItem=0;
		lvitem.pszText=(char *)(LPCTSTR)ID;
		
		list.InsertItem(&lvitem);		//插入一行
		list.SetItemText(index,0,ID);
		list.SetItemText(index,1,name);
		list.SetItemText(index,2,money);
		
		ID="";		//对数据进行清空
		name="";
		money="";
		index=0;

		record->MoveNext();
	}


	MessageBox("数据提取完毕");

	UpdateData(false);
}