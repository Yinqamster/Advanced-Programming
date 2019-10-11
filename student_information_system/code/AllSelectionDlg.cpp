// AllSelectionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "AllSelectionDlg.h"
#include "afxdialogex.h"


// AllSelectionDlg 对话框

IMPLEMENT_DYNAMIC(AllSelectionDlg, CDialogEx)

AllSelectionDlg::AllSelectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG14, pParent)
{

}

AllSelectionDlg::~AllSelectionDlg()
{
}

void AllSelectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AllSelectionDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AllSelectionDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AllSelectionDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// AllSelectionDlg 消息处理程序


void AllSelectionDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
	string str = "学号\t姓名\t选修的课程\r\n";
	CString m_result;
	for (int i = 0; i < seleInfo.size(); i++) {
		str += seleInfo[i]->getNo() + "\t" + seleInfo[i]->getName() + "\t";
		for (int j = 0; j < seleInfo[i]->getCurInfoSize(); j++) {
			str += seleInfo[i]->getCurInfo(j)->getName() + " ";
		}
		str += "\r\n";
	}
	m_result = str.c_str();
	SetDlgItemText(IDC_EDIT1, m_result);
}


void AllSelectionDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
