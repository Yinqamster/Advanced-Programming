#pragma once


// QueryStudentDlg �Ի���

class QueryStudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryStudentDlg)

public:
	QueryStudentDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~QueryStudentDlg();
	CEdit m_stu;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
