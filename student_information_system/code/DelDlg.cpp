// DelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "DelDlg.h"
#include "afxdialogex.h"


// DelDlg 对话框

IMPLEMENT_DYNAMIC(DelDlg, CDialogEx)

DelDlg::DelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

DelDlg::~DelDlg()
{
}

void DelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_delNo);
}


BEGIN_MESSAGE_MAP(DelDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DelDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// DelDlg 消息处理程序


void DelDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	int find = 0;
	char buf[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_delNo.GetBuffer(0), m_delNo.GetLength(), buf, 20, 0, 0);
	string delNo = buf;

	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i]->getNo() == delNo) {
			stuList.erase(stuList.begin() + i);
			find = 1;
			for (int j = 0; j < seleInfo.size(); j++) {
				if (seleInfo[j]->getNo() == delNo) {
					seleInfo.erase(seleInfo.begin() + j);
				}
			}
			break;
		}
	}

	if (find == 0) {
		MessageBox(_T("该学生不存在！"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		MessageBox(_T("      删除成功！"), _T("reminder"), MB_OK);
	}
}
