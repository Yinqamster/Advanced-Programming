#pragma once


// AddCourseDlg �Ի���

class AddCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCourseDlg)

public:
	AddCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddCourseDlg();
	CEdit m_no;
	CEdit m_name;
	CEdit m_credit;
	CEdit m_teacher;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
