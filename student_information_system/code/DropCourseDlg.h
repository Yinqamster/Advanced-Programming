#pragma once
#include <fstream>
#include <iostream>
#include <string>

// DropCourseDlg �Ի���

class DropCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DropCourseDlg)

public:
	DropCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DropCourseDlg();
	CEdit m_stu;
	CEdit m_dropCur;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
