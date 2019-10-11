#pragma once


// AddDlg 对话框

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddDlg();
	CString m_no;
	CString m_name;
	string m_sex;
	string m_grade;
	string m_department;
	CString m_birthday;
	CString m_telNo;
	CString m_address;

	CSplitButton m_depart;
	CSplitButton m_gra;
	int radio;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSplit3();
	afx_msg void OnAddCS();
	afx_msg void OnBnClickedSplit2();
	afx_msg void OnCommercial();
	afx_msg void OnSoftware();
	afx_msg void OnElectronic();
	afx_msg void OnLiterature();
	afx_msg void OnHistory();
	afx_msg void OnPhysics();
	afx_msg void OnBiology();
	afx_msg void On32797();
	afx_msg void On32798();
	afx_msg void On32799();
	afx_msg void On32800();
	afx_msg void On32801();
};
