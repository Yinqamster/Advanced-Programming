#pragma once


// DelDlg 对话框

class DelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DelDlg)

public:
	DelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DelDlg();
	CString m_delNo;
//	CFont m_font;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
