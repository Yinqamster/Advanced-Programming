// SearchDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "SearchDlg.h"
#include "afxdialogex.h"


// SearchDlg 对话框

IMPLEMENT_DYNAMIC(SearchDlg, CDialogEx)

SearchDlg::SearchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
/*	LONG styles;
	styles = GetWindowLong(m_list.m_hWnd, GWL_STYLE);
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, styles | LVS_REPORT);*/

}

SearchDlg::~SearchDlg()
{
}

void SearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_searchNo);
	DDX_Control(pDX, IDC_EDIT1, m_getNo);
//	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT2, m_result);
}


BEGIN_MESSAGE_MAP(SearchDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SearchDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &SearchDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &SearchDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &SearchDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// SearchDlg 消息处理程序



void SearchDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	CDialog::OnInitDialog();
//	CDialogEx::OnOK();
/*	m_list.InsertColumn(1, _T("No"), LVCFMT_LEFT, 10);
	m_list.InsertColumn(2, _T("Name"), LVCFMT_LEFT, 10);
	m_list.InsertColumn(3, _T("Sex"), LVCFMT_LEFT, 5);
	m_list.InsertColumn(4, _T("Grade"), LVCFMT_LEFT, 10);
	m_list.InsertColumn(5, _T("Department"), LVCFMT_LEFT, 30);
	m_list.InsertColumn(6, _T("Birthday"), LVCFMT_LEFT, 15);
	m_list.InsertColumn(7, _T("TelNo"), LVCFMT_LEFT, 15);
	m_list.InsertColumn(8, _T("Address"), LVCFMT_LEFT, 100);*/
	m_getNo.GetWindowTextW(m_searchNo);
	int find = 0;
	char buf[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_searchNo.GetBuffer(0), m_searchNo.GetLength(), buf, 20, 0, 0);
	string searchNo = buf;

	string no;
	string name;
	string sex;
	string grade;
	string department;
	string birthday;
	string telNo;
	string address;

	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i]->getNo() == searchNo) {
			//打出学生信息
	/*		no = stuList[i]->getNo().c_str();
			name = stuList[i]->getName().c_str();
			sex = stuList[i]->getSex().c_str();
			grade = stuList[i]->getGrade().c_str();
			department = stuList[i]->getDepartment().c_str();
			birthday = stuList[i]->getBirthday().c_str();
			telNo = stuList[i]->getTelNo().c_str();
			address = stuList[i]->getAddress().c_str();*/

			no = stuList[i]->getNo();
			name = stuList[i]->getName();
			sex = stuList[i]->getSex();
			grade = stuList[i]->getGrade();
			department = stuList[i]->getDepartment();
			birthday = stuList[i]->getBirthday();
			telNo = stuList[i]->getTelNo();
			address = stuList[i]->getAddress();

			string res = "学号：" + no + "\r\n" + "姓名：" + name + "\r\n" + "性别：" + sex + "\r\n" + "年级：" + grade + "\r\n" + "系别：" + department + "\r\n" + "出生日期：" + birthday + "\r\n" + "联系方式：" + telNo + "\r\n" + "住址：" + address + "\r\n";
			m_result = res.c_str();
			SetDlgItemText(IDC_EDIT2, m_result);
/*			m_list.InsertItem(0, no);
			m_list.SetItemText(1, 2, name);//SetItemText设置本行后续列数据;
			m_list.SetItemText(1, 3, sex);
			m_list.SetItemText(1, 4, grade);
			m_list.SetItemText(1, 5, department);
			m_list.SetItemText(1, 6, birthday);
			m_list.SetItemText(1, 7, telNo);
			m_list.SetItemText(1, 8, address);

			m_list.SetRedraw(TRUE);*/
			find = 1;
			break;
		}
	}

	if (find == 0) {
		MessageBox(_T("该学生不存在！"), _T("reminder"), MB_OK | MB_ICONERROR);
	}
}

void SearchDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void SearchDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void SearchDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
