#pragma once

#include <fstream>
#include <iostream>
#include <string>
// stuInfoDlg 对话框

class stuInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(stuInfoDlg)

public:
	stuInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~stuInfoDlg();
	CEdit m_info;
	string stuNo;
	CString m_result;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void setNo(string no);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
