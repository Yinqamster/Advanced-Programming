#pragma once
#include <fstream>
#include <iostream>
#include <string>

// DropCourseDlg 对话框

class DropCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DropCourseDlg)

public:
	DropCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DropCourseDlg();
	CEdit m_stu;
	CEdit m_dropCur;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
