// QueryStudentDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "QueryStudentDlg.h"
#include "afxdialogex.h"


// QueryStudentDlg 对话框

IMPLEMENT_DYNAMIC(QueryStudentDlg, CDialogEx)

QueryStudentDlg::QueryStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG12, pParent)
{

}

QueryStudentDlg::~QueryStudentDlg()
{
}

void QueryStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_stu);
}


BEGIN_MESSAGE_MAP(QueryStudentDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &QueryStudentDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &QueryStudentDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// QueryStudentDlg 消息处理程序


void QueryStudentDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	CString c_stu;
	m_stu.GetWindowTextW(c_stu);
	char buf[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_stu.GetBuffer(0), c_stu.GetLength(), buf, 20, 0, 0);
	string stu = buf;

	string str = ""; 
	CString m_result;

	if (stu == "") {
		MessageBox(_T("请输入学生信息！"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		int find = 0;
		for (int i = 0; i < seleInfo.size(); i++) {
			if (seleInfo[i]->getNo() == stu) {
				if (seleInfo[i]->getCurInfoSize() == 0) {
					MessageBox(_T("该学生未选修课程！"), _T("reminder"), MB_OK | MB_ICONERROR);
				}
				else {
					str += "学号：" + stu + "\r\n" + "姓名：" + seleInfo[i]->getName() + "\r\n";
					str += "选课信息：\r\n课程学分\t课程名\t任课教师\r\n";
					for (int j = 0; j < seleInfo[i]->getCurInfoSize(); j++) {
						str += seleInfo[i]->getCurInfo(j)->getCredit() + "\t" + seleInfo[i]->getCurInfo(j)->getName() + "\t" + seleInfo[i]->getCurInfo(j)->getTeacher() + "\r\n";
					}
				}
				find = 1;
				break;
			}
		}
		m_result = str.c_str();
		SetDlgItemText(IDC_EDIT2, m_result);

		if (find == 0) {
			MessageBox(_T("该学生未选修课程！"), _T("reminder"), MB_OK | MB_ICONERROR);
		}
	}
}


void QueryStudentDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
