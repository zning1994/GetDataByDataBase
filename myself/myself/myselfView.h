
// myselfView.h : CmyselfView 类的接口
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

class CmyselfSet;

class CmyselfView : public CRecordView
{
protected: // 仅从序列化创建
	CmyselfView();
	DECLARE_DYNCREATE(CmyselfView)

public:
	enum{ IDD = IDD_MYSELF_FORM };
	CmyselfSet* m_pSet;

// 特性
public:
	CmyselfDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CmyselfView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

//作者设置的
public:
	CDatabase DB;		//数据库操作变量
	CRecordset *record;//  记录集指针
	CString ID;	//用来存储数据的变量
	CString name;
	CString money;
	CListCtrl list;	//列表控件变量
	afx_msg void OnBnClickedButtontakedata();
	afx_msg void OnBnClickedButtoncontext();
};

#ifndef _DEBUG  // myselfView.cpp 中的调试版本
inline CmyselfDoc* CmyselfView::GetDocument() const
   { return reinterpret_cast<CmyselfDoc*>(m_pDocument); }
#endif

