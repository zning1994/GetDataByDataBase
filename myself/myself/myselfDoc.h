
// myselfDoc.h : CmyselfDoc ��Ľӿ�
//


#pragma once
#include "myselfSet.h"


class CmyselfDoc : public CDocument
{
protected: // �������л�����
	CmyselfDoc();
	DECLARE_DYNCREATE(CmyselfDoc)

// ����
public:
	CmyselfSet m_myselfSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CmyselfDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
