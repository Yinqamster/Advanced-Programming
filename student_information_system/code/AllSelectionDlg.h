#pragma once


// AllSelectionDlg 对话框

class AllSelectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AllSelectionDlg)

public:
	AllSelectionDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AllSelectionDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
