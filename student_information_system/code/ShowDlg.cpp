// ShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// ShowDlg �Ի���

IMPLEMENT_DYNAMIC(ShowDlg, CDialogEx)

ShowDlg::ShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

ShowDlg::~ShowDlg()
{
}

void ShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ShowDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &ShowDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &ShowDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ShowDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// ShowDlg ��Ϣ�������


void ShowDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}

bool cmpName(Stu *A, Stu *B) {
	return A->getName() < B->getName();
}
bool cmpNo(Stu *A, Stu *B) {
	return A->getNo() < B->getNo();
}

void ShowDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sort(stuList.begin(), stuList.end(), cmpNo);
	string res = "ѧ��\t����\t�Ա�\t�꼶\tϵ��\t��������\t��ϵ��ʽ\tסַ\r\n";
	CString m_result;
	for (int i = 0; i < stuList.size(); i++) {
		res +=stuList[i]->getNo() + "\t" + stuList[i]->getName() + "\t" + stuList[i]->getSex() + "\t" + stuList[i]->getGrade() + "\t" + stuList[i]->getDepartment() + "\t" + stuList[i]->getBirthday() + "\t" + stuList[i]->getTelNo() + "\t" + stuList[i]->getAddress() + "\r\n";		
	}
	m_result = res.c_str();
	SetDlgItemText(IDC_EDIT1, m_result);
}


void ShowDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sort(stuList.begin(), stuList.end(), cmpName);
	string res = "ѧ��\t����\t�Ա�\t�꼶\tϵ��\t��������\t��ϵ��ʽ\tסַ\r\n";
	CString m_result;
	for (int i = 0; i < stuList.size(); i++) {
		res += stuList[i]->getNo() + "\t" + stuList[i]->getName() + "\t" + stuList[i]->getSex() + "\t" + stuList[i]->getGrade() + "\t" + stuList[i]->getDepartment() + "\t" + stuList[i]->getBirthday() + "\t" + stuList[i]->getTelNo() + "\t" + stuList[i]->getAddress() + "\r\n";
	}
	m_result = res.c_str();
	SetDlgItemText(IDC_EDIT1, m_result);
}
