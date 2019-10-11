// AddCourseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "AddCourseDlg.h"
#include "afxdialogex.h"


// AddCourseDlg 对话框

IMPLEMENT_DYNAMIC(AddCourseDlg, CDialogEx)

AddCourseDlg::AddCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

AddCourseDlg::~AddCourseDlg()
{
}

void AddCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_no);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_credit);
	DDX_Control(pDX, IDC_EDIT4, m_teacher);
}


BEGIN_MESSAGE_MAP(AddCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddCourseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AddCourseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// AddCourseDlg 消息处理程序


void AddCourseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString c_no, c_name, c_credit, c_teacher;
	m_no.GetWindowTextW(c_no);
	m_name.GetWindowTextW(c_name);
	m_credit.GetWindowTextW(c_credit);
	m_teacher.GetWindowTextW(c_teacher);
	char buf0[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_no.GetBuffer(0), c_no.GetLength(), buf0, 20, 0, 0);
	string no = buf0;
	char buf1[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_name.GetBuffer(0), c_name.GetLength(), buf1, 20, 0, 0);
	string name = buf1;
	char buf2[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_credit.GetBuffer(0), c_credit.GetLength(), buf2, 20, 0, 0);
	string credit = buf2;
	char buf3[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_teacher.GetBuffer(0), c_teacher.GetLength(), buf3, 20, 0, 0);
	string teacher = buf3;


	if (no == "") {
		MessageBox(_T("课程编号不能为空！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddCourseDlg a;
		a.DoModal();
	}
	else if (name == "") {
		MessageBox(_T("课程名不能为空！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddCourseDlg a;
		a.DoModal();
	}
	else if (credit == "") {
		MessageBox(_T("学分不能为空"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddCourseDlg a;
		a.DoModal();
	}
	else if (teacher == "") {
		MessageBox(_T("教师不能为空"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddCourseDlg a;
		a.DoModal();
	}
	else {
		int find = 0;
		for (int i = 0; i < courseList.size(); i++) {
			if (courseList[i]->getNo() == no || courseList[i]->getName() == name) {
				MessageBox(_T("该门课程已存在，请勿重复添加！"), _T("reminder"), MB_OK | MB_ICONERROR);
				find = 1;
				break;
			}
		}
		if (find == 0) {
			Course *c = new Course(no, name, credit, teacher);
			courseList.push_back(c);
			MessageBox(_T("   添加成功！"), _T("reminder"), MB_OK);
		}
		else {
			AddCourseDlg a;
			a.DoModal();
		}

	}
}


void AddCourseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
