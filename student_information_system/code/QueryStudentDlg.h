#pragma once


// QueryStudentDlg 对话框

class QueryStudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryStudentDlg)

public:
	QueryStudentDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~QueryStudentDlg();
	CEdit m_stu;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
