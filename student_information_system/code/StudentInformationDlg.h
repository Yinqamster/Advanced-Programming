
// StudentInformationDlg.h : 头文件
//

#pragma once
#include "MenuDlg.h"
#include "stuInfoDlg.h"

// CStudentInformationDlg 对话框
class CStudentInformationDlg : public CDialogEx
{
// 构造
public:
	CStudentInformationDlg(CWnd* pParent = NULL);	// 标准构造函数
	CString	m_username;
	CString	m_password;
	int radio = -1;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTINFORMATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio2();
	afx_msg void On32771();
};
