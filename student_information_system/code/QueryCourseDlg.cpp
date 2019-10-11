// QueryCourseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "QueryCourseDlg.h"
#include "afxdialogex.h"


// QueryCourseDlg 对话框

IMPLEMENT_DYNAMIC(QueryCourseDlg, CDialogEx)

QueryCourseDlg::QueryCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG13, pParent)
{

}

QueryCourseDlg::~QueryCourseDlg()
{
}

void QueryCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cur);
}


BEGIN_MESSAGE_MAP(QueryCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &QueryCourseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &QueryCourseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// QueryCourseDlg 消息处理程序


void QueryCourseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
	CString c_cur;
	m_cur.GetWindowTextW(c_cur);
	char buf[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_cur.GetBuffer(0), c_cur.GetLength(), buf, 20, 0, 0);
	string cur = buf;
	
	if (cur == "") {
		MessageBox(_T("请输入课程信息！"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		string str = "";
		int find = 0;
		for (int i = 0; i < courseList.size(); i++) {
			if (courseList[i]->getName() == cur || courseList[i]->getNo() == cur) {
				find = 1;
				str += "课程编号：" + courseList[i]->getNo() + "\r\n课程名：" + courseList[i]->getName() + "\r\n课程学分：" + courseList[i]->getCredit() + "\r\n任课教师：" + courseList[i]->getTeacher() + "\r\n";
				break;
			}
		}

		if (find = 0) {
			MessageBox(_T("该课程不存在！"), _T("reminder"), MB_OK | MB_ICONERROR);
		}
		else {
			vector<SelectCourse*> temp;
			for (int i = 0; i < seleInfo.size(); i++) {
				for (int j = 0; j < seleInfo[i]->getCurInfoSize(); j++) {
					if (seleInfo[i]->getCurInfo(j)->getName() == cur || seleInfo[i]->getCurInfo(j)->getNo() == cur) {
						SelectCourse * t = new SelectCourse(seleInfo[i]->getNo(), seleInfo[i]->getName());
						temp.push_back(t);
					}
				}
			}

			if (temp.size() == 0) {
				str += "选课人数：0\r\n";
			}
			else {
				std::stringstream ss;
				std::string no;
				ss << temp.size();
				ss >> no;
				str += "选课人数：" + no + "\r\n学号\t姓名\r\n";
				for (int i = 0; i < temp.size(); i++) {
					str += temp[i]->getNo() + "\t" + temp[i]->getName() + "\r\n";
				}
			}
			CString m_res;
			m_res = str.c_str();
			SetDlgItemText(IDC_EDIT2, m_res);
		}
	}
}


void QueryCourseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
