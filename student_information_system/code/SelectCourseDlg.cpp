// SelectCourseDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "SelectCourseDlg.h"
#include "afxdialogex.h"


// SelectCourseDlg 对话框

IMPLEMENT_DYNAMIC(SelectCourseDlg, CDialogEx)

SelectCourseDlg::SelectCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG10, pParent)
{

}

SelectCourseDlg::~SelectCourseDlg()
{
}

void SelectCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_stu);
	DDX_Control(pDX, IDC_EDIT2, m_cur);
}


BEGIN_MESSAGE_MAP(SelectCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SelectCourseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SelectCourseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// SelectCourseDlg 消息处理程序


void SelectCourseDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString c_stu, c_cur;
	m_stu.GetWindowTextW(c_stu);
	m_cur.GetWindowTextW(c_cur);
	char buf0[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_stu.GetBuffer(0), c_stu.GetLength(), buf0, 20, 0, 0);
	string stu = buf0;
	char buf1[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_cur.GetBuffer(0), c_cur.GetLength(), buf1, 20, 0, 0);
	string cur = buf1;
	string name = "";

	int find = 0;
	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i]->getNo() == stu) {
			name = stuList[i]->getName();
			find = 1;
			break;
		}
	}
	if (find == 0) {
		MessageBox(_T("该学生不存在，请先添加学生信息！"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		int findStu = 0;
		SelectCourse *SC;
		for (int i = 0; i < seleInfo.size(); i++) {
			if (seleInfo[i]->getNo() == stu) {
				SC = seleInfo[i];
				findStu = 1;
				break;
			}
		}
		if (findStu == 0) {
			SC = new SelectCourse(stu, name);
		}

		int findCur = 0;
		if (SC->getCurInfoSize() != 0) {
			for (int i = 0; i < SC->getCurInfoSize(); i++) {
				if (SC->getCurInfo(i)->getName() == cur || SC->getCurInfo(i) ->getNo() == cur ) {
					MessageBox(_T("已添加过该课程！"), _T("reminder"), MB_OK | MB_ICONERROR);
			//		cout << "已添加过该课程！" << endl;
					findCur = 1;
					break;
				}
			}
			if (findCur == 0) {
				SC->addCourse(cur);
			}
		}
		else {
			SC->addCourse(cur);
		}

		if (SC->getCurInfoSize() != 0) {
			for (int i = 0; i < seleInfo.size(); i++) {
				if (seleInfo[i]->getNo() == stu) {
					seleInfo.erase(seleInfo.begin() + i);
					break;
				}
			}
			seleInfo.push_back(SC);
		}
	}

	ofstream ou;
	ou.open("select.txt");
	for (int i = 0; i < seleInfo.size(); i++) {
		ou << seleInfo[i]->getNo() << " ";
		ou << seleInfo[i]->getName() << " ";
		for (int j = 0; j < seleInfo[i]->getCurInfoSize(); j++) {
			ou << seleInfo[i]->getCurInfo(j)->getCredit()<<" ";
			ou << seleInfo[i]->getCurInfo(j)->getName()<<" ";
		}
		ou << endl;
	}
	ou.close();
}


void SelectCourseDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
