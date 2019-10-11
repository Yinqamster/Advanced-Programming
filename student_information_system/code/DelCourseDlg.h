#pragma once


// DelCourseDlg 对话框

class DelCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DelCourseDlg)

public:
	DelCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DelCourseDlg();
	CEdit m_del;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
