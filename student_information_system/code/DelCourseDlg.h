#pragma once


// DelCourseDlg �Ի���

class DelCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DelCourseDlg)

public:
	DelCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DelCourseDlg();
	CEdit m_del;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
