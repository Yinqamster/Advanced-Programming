// DelCourseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "DelCourseDlg.h"
#include "afxdialogex.h"


// DelCourseDlg �Ի���

IMPLEMENT_DYNAMIC(DelCourseDlg, CDialogEx)

DelCourseDlg::DelCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

DelCourseDlg::~DelCourseDlg()
{
}

void DelCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_del);
}


BEGIN_MESSAGE_MAP(DelCourseDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DelCourseDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DelCourseDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// DelCourseDlg ��Ϣ�������


void DelCourseDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CString c_del;
	m_del.GetWindowTextW(c_del);
	int find = 0;
	char buf[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, c_del.GetBuffer(0), c_del.GetLength(), buf, 20, 0, 0);
	string del = buf;

	for (int i = 0; i < courseList.size(); i++) {
		if (courseList[i]->getNo() == del) {
			courseList.erase(courseList.begin() + i);
			find = 1;
			break;
		}
		else if (courseList[i]->getName() == del) {
			courseList.erase(courseList.begin() + i);
			find = 1;
			break;
		}
	}

	if (find == 0) {
		MessageBox(_T("�ÿγ̲����ڣ�"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
	else {
		for (int i = 0; i < seleInfo.size(); i++) {
			for (int j = 0; j < seleInfo[i]->getCurInfoSize(); j++) {
				if (seleInfo[i]->getCurInfo(j)->getName() == del || seleInfo[i]->getCurInfo(j)->getNo() == del) {
					seleInfo[i]->eraseCourse(j);
				}
			}
		}
		MessageBox(_T("      ɾ���ɹ���"), _T("reminder"), MB_OK);
	}
}


void DelCourseDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
