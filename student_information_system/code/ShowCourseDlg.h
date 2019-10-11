#pragma once


// ShowCourseInfo 对话框

class ShowCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowCourseDlg)

public:
	ShowCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShowCourseDlg();
	CEdit m_cInfo;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
