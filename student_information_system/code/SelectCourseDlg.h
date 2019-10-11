#pragma once

#include <fstream>
#include <iostream>
#include <string>
// SelectCourseDlg 对话框

class SelectCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectCourseDlg)

public:
	SelectCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~SelectCourseDlg();
	CEdit m_stu;
	CEdit m_cur;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
