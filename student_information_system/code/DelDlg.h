#pragma once


// DelDlg �Ի���

class DelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DelDlg)

public:
	DelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DelDlg();
	CString m_delNo;
//	CFont m_font;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
