// ShowCourseInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "ShowCourseDlg.h"
#include "afxdialogex.h"


// ShowCourseInfo 对话框

IMPLEMENT_DYNAMIC(ShowCourseDlg, CDialogEx)

ShowCourseDlg::ShowCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG9, pParent)
{

}

ShowCourseDlg::~ShowCourseDlg()
{
}

void ShowCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ShowCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShowCourseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ShowCourseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// ShowCourseInfo 消息处理程序


void ShowCourseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
	string res = "课程编号\t课程名\t学分\t任课教师\r\n";
	CString m_result;
	for (int i = 0; i < courseList.size(); i++) {
		res += courseList[i]->getNo() + "\t" + courseList[i]->getName() + "\t" + courseList[i]->getCredit() + "\t" + courseList[i]->getTeacher() + "\r\n";
	}
	m_result = res.c_str();
	SetDlgItemText(IDC_EDIT1, m_result);
}


void ShowCourseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
