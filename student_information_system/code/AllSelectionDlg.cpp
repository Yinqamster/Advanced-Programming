// AllSelectionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "AllSelectionDlg.h"
#include "afxdialogex.h"


// AllSelectionDlg �Ի���

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


// AllSelectionDlg ��Ϣ�������


void AllSelectionDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
//	CDialogEx::OnOK();
	string str = "ѧ��\t����\tѡ�޵Ŀγ�\r\n";
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
