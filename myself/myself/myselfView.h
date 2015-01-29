
// myselfView.h : CmyselfView ��Ľӿ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

class CmyselfSet;

class CmyselfView : public CRecordView
{
protected: // �������л�����
	CmyselfView();
	DECLARE_DYNCREATE(CmyselfView)

public:
	enum{ IDD = IDD_MYSELF_FORM };
	CmyselfSet* m_pSet;

// ����
public:
	CmyselfDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CmyselfView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

//�������õ�
public:
	CDatabase DB;		//���ݿ��������
	CRecordset *record;//  ��¼��ָ��
	CString ID;	//�����洢���ݵı���
	CString name;
	CString money;
	CListCtrl list;	//�б�ؼ�����
	afx_msg void OnBnClickedButtontakedata();
	afx_msg void OnBnClickedButtoncontext();
};

#ifndef _DEBUG  // myselfView.cpp �еĵ��԰汾
inline CmyselfDoc* CmyselfView::GetDocument() const
   { return reinterpret_cast<CmyselfDoc*>(m_pDocument); }
#endif

