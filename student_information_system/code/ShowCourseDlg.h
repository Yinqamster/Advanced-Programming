#pragma once


// ShowCourseInfo �Ի���

class ShowCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowCourseDlg)

public:
	ShowCourseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowCourseDlg();
	CEdit m_cInfo;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
