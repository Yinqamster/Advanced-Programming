#pragma once

#include <sstream>
// QueryCourseDlg 对话框

class QueryCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryCourseDlg)

public:
	QueryCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~QueryCourseDlg();
	CEdit m_cur;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
