#pragma once


// AllSelectionDlg �Ի���

class AllSelectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AllSelectionDlg)

public:
	AllSelectionDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AllSelectionDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
