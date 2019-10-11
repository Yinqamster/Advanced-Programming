// ShowCourseInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "ShowCourseDlg.h"
#include "afxdialogex.h"


// ShowCourseInfo �Ի���

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


// ShowCourseInfo ��Ϣ�������


void ShowCourseDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CDialogEx::OnOK();
	string res = "�γ̱��\t�γ���\tѧ��\t�ον�ʦ\r\n";
	CString m_result;
	for (int i = 0; i < courseList.size(); i++) {
		res += courseList[i]->getNo() + "\t" + courseList[i]->getName() + "\t" + courseList[i]->getCredit() + "\t" + courseList[i]->getTeacher() + "\r\n";
	}
	m_result = res.c_str();
	SetDlgItemText(IDC_EDIT1, m_result);
}


void ShowCourseDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
