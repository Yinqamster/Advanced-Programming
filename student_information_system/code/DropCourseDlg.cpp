// DropCourseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "DropCourseDlg.h"
#include "afxdialogex.h"


// DropCourseDlg 对话框

IMPLEMENT_DYNAMIC(DropCourseDlg, CDialogEx)

DropCourseDlg::DropCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG11, pParent)
{

}

DropCourseDlg::~DropCourseDlg()
{
}

void DropCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_stu);
	DDX_Control(pDX, IDC_EDIT2, m_dropCur);
}


BEGIN_MESSAGE_MAP(DropCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DropCourseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DropCourseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// DropCourseDlg 消息处理程序


void DropCourseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString c_stu, c_dropCur;
	m_stu.GetWindowTextW(c_stu);
	m_dropCur.GetWindowTextW(c_dropCur);
	char buf0[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_stu.GetBuffer(0), c_stu.GetLength(), buf0, 20, 0, 0);
	string stu = buf0;
	char buf1[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_dropCur.GetBuffer(0), c_dropCur.GetLength(), buf1, 20, 0, 0);
	string dropCur = buf1;
	
	int find = 0;
	for (int i = 0; i < seleInfo.size(); i++) {
		if (seleInfo[i]->getNo() == stu) {
			seleInfo[i]->delCourse(dropCur);
			find = 1;
		}
		break;
	}
	if (find == 0) {
		MessageBox(_T("该学生不存在，请先添加学生信息！"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		ofstream ou;
		ou.open("select.txt");
		for (int i = 0; i < seleInfo.size(); i++) {
			ou << seleInfo[i]->getNo() << " ";
			ou << seleInfo[i]->getName() << " ";
			for (int j = 0; j < seleInfo[i]->getCurInfoSize(); j++) {
				ou << seleInfo[i]->getCurInfo(j)->getCredit() << " ";
				ou << seleInfo[i]->getCurInfo(j)->getName() << " ";
			}
			ou << endl;
		}
		ou.close();
	}
}


void DropCourseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
