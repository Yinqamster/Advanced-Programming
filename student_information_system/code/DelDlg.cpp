// DelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "DelDlg.h"
#include "afxdialogex.h"


// DelDlg �Ի���

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


// DelDlg ��Ϣ�������


void DelDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox(_T("��ѧ�������ڣ�"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		MessageBox(_T("      ɾ���ɹ���"), _T("reminder"), MB_OK);
	}
}
