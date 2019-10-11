#pragma once

#include "AddDlg.h"
#include "DelDlg.h"
#include "SearchDlg.h"
#include "ShowDlg.h"
#include "AddCourseDlg.h"
#include "DelCourseDlg.h"
#include "ShowCourseDlg.h"
#include "SelectCourseDlg.h"
#include "AllSelectionDlg.h"
#include "DropCourseDlg.h"
#include "QueryCourseDlg.h"
#include "QueryStudentDlg.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
// MenuDlg 对话框

class MenuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MenuDlg)

public:
	MenuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MenuDlg();
	CMenu m_Menu;
	CStatic m_gifpicture;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnImportStuInfo();
	afx_msg void OnExportStuInfo();
	afx_msg void OnAddStuInfo();
	afx_msg void OnDeleteStuInfo();
	afx_msg void OnSearchStuInfo();
	afx_msg void OnShowInfo();
	afx_msg void OnImportCourse();
	afx_msg void OnExportCourse();
	afx_msg void OnShowCourse();
	afx_msg void OnAddCourse();
	afx_msg void OnDelCourse();
	afx_msg void OnSelectCourse();
	afx_msg void OnDropCourse();
	afx_msg void OnQueryStudent();
	afx_msg void OnQueryCourse();
	afx_msg void OnAllSelection();
};
