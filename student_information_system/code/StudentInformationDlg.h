
// StudentInformationDlg.h : ͷ�ļ�
//

#pragma once
#include "MenuDlg.h"
#include "stuInfoDlg.h"

// CStudentInformationDlg �Ի���
class CStudentInformationDlg : public CDialogEx
{
// ����
public:
	CStudentInformationDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CString	m_username;
	CString	m_password;
	int radio = -1;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENTINFORMATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
