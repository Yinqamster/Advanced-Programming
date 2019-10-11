#pragma once


// AddCourseDlg 对话框

class AddCourseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCourseDlg)

public:
	AddCourseDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddCourseDlg();
	CEdit m_no;
	CEdit m_name;
	CEdit m_credit;
	CEdit m_teacher;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
