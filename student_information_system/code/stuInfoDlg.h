#pragma once

#include <fstream>
#include <iostream>
#include <string>
// stuInfoDlg �Ի���

class stuInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(stuInfoDlg)

public:
	stuInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~stuInfoDlg();
	CEdit m_info;
	string stuNo;
	CString m_result;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void setNo(string no);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
