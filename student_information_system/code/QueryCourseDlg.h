#pragma once

#include <sstream>
// QueryCourseDlg �Ի���

class QueryCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryCourseDlg)

public:
	QueryCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~QueryCourseDlg();
	CEdit m_cur;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
