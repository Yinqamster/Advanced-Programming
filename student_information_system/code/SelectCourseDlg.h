#pragma once

#include <fstream>
#include <iostream>
#include <string>
// SelectCourseDlg �Ի���

class SelectCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectCourseDlg)

public:
	SelectCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SelectCourseDlg();
	CEdit m_stu;
	CEdit m_cur;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
