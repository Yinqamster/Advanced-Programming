// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	m_no = _T("");
	m_name = _T("");
	m_sex = "";
	m_grade = "";
	m_department = "";
	m_birthday = _T("");
	m_telNo = _T("");
	m_address = _T("");

	radio = -1;

	m_gra.SetDropDownMenu(IDR_MENU2, 2);
	m_depart.SetDropDownMenu(IDR_MENU2, 1);
}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_no);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_DATETIMEPICKER1, m_birthday);
	DDX_Text(pDX, IDC_EDIT3, m_telNo);
	DDX_Text(pDX, IDC_EDIT4, m_address);
	DDX_Control(pDX, IDC_SPLIT2, m_depart);
	DDX_Control(pDX, IDC_SPLIT3, m_gra);

}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &AddDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &AddDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, &AddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SPLIT3, &AddDlg::OnBnClickedSplit3)
	ON_COMMAND(ID_32784, &AddDlg::OnAddCS)
	ON_BN_CLICKED(IDC_SPLIT2, &AddDlg::OnBnClickedSplit2)
	ON_COMMAND(ID_32785, &AddDlg::OnCommercial)
	ON_COMMAND(ID_32786, &AddDlg::OnSoftware)
	ON_COMMAND(ID_32787, &AddDlg::OnElectronic)
	ON_COMMAND(ID_32788, &AddDlg::OnLiterature)
	ON_COMMAND(ID_32789, &AddDlg::OnHistory)
	ON_COMMAND(ID_32790, &AddDlg::OnPhysics)
	ON_COMMAND(ID_32791, &AddDlg::OnBiology)
	ON_COMMAND(ID_32797, &AddDlg::On32797)
	ON_COMMAND(ID_32798, &AddDlg::On32798)
	ON_COMMAND(ID_32799, &AddDlg::On32799)
	ON_COMMAND(ID_32800, &AddDlg::On32800)
	ON_COMMAND(ID_32801, &AddDlg::On32801)
END_MESSAGE_MAP()


// AddDlg 消息处理程序


void AddDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	radio = 0;
}


void AddDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	radio = 1;
}


void AddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	char buf[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_no.GetBuffer(0), m_no.GetLength(), buf, 20, 0, 0);
	string no = buf;
	char buf1[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_name.GetBuffer(0), m_name.GetLength(), buf1, 20, 0, 0);
	string name = buf1;
	char buf2[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_birthday.GetBuffer(0), m_birthday.GetLength(), buf2, 20, 0, 0);
	string birthday = buf2;
	char buf3[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_telNo.GetBuffer(0), m_telNo.GetLength(), buf3, 20, 0, 0);
	string telNo = buf3;
	char buf4[20] = { '\0' };
	WideCharToMultiByte(CP_ACP, 0, m_address.GetBuffer(0), m_address.GetLength(), buf4, 20, 0, 0);
	string address = buf4;

	if (radio == 0) {
		m_sex = "女";
	}
	else if (radio == 1) {
		m_sex = "男";
	}

	//Todo:判断信息是否全了，判断学生是否存在，添加不成功循环
	if (no == "") {
		MessageBox(_T("学号不能为空！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else if (name == "") {
		MessageBox(_T("姓名不能为空！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else if (radio == -1) {
		MessageBox(_T("请选择性别！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else if (m_grade == "") {
		MessageBox(_T("请选择年级！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else if (m_department == "") {
		MessageBox(_T("请选择专业！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else if (telNo == "") {
		MessageBox(_T("联系方式不能为空！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else if (address == "") {
		MessageBox(_T("地址不能为空！"), _T("reminder"), MB_OK | MB_ICONERROR);
		AddDlg a;
		a.DoModal();
	}
	else {
		int find = 0;
		for (int i = 0; i < stuList.size(); i++) {
			if (stuList[i]->getNo() == no) {
				string str = "学号" + no + "已存在，请勿重复添加！";
				CString str1;
				str1 = str.c_str();
				MessageBox(str1, _T("reminder"), MB_OK | MB_ICONERROR);
				find = 1;
				break;
			}
		}
		if (find == 0) {
			Stu *s = new Stu(no, name, m_sex, m_grade, m_department, birthday, telNo, address);
			stuList.push_back(s);
			MessageBox(_T("   添加成功！"), _T("reminder"), MB_OK);
		}
		else {
			AddDlg a;
			a.DoModal();
		}
		
	}
	
}


void AddDlg::OnBnClickedSplit3()
{
	// TODO: 在此添加控件通知处理程序代码
}

void AddDlg::OnBnClickedSplit2()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


void AddDlg::OnAddCS()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "计算机系";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}

void AddDlg::OnCommercial()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "商学院";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}


void AddDlg::OnSoftware()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "软件学院";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}


void AddDlg::OnElectronic()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "电子系";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}


void AddDlg::OnLiterature()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "文学院";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}


void AddDlg::OnHistory()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "历史系";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}


void AddDlg::OnPhysics()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "物理系";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}


void AddDlg::OnBiology()
{
	// TODO: 在此添加命令处理程序代码
	m_department = "生命科学学院";
	CString str;
	str = m_department.c_str();
	SetDlgItemText(IDC_SPLIT2, str);
}

void AddDlg::On32797()
{
	// TODO: 在此添加命令处理程序代码
	m_grade = "2016";
	CString str;
	str = m_grade.c_str();
	SetDlgItemText(IDC_SPLIT3, str);
}


void AddDlg::On32798()
{
	// TODO: 在此添加命令处理程序代码
	m_grade = "2015";
	CString str;
	str = m_grade.c_str();
	SetDlgItemText(IDC_SPLIT3, str);
}


void AddDlg::On32799()
{
	// TODO: 在此添加命令处理程序代码
	m_grade = "2014";
	CString str;
	str = m_grade.c_str();
	SetDlgItemText(IDC_SPLIT3, str);
}


void AddDlg::On32800()
{
	// TODO: 在此添加命令处理程序代码
	m_grade = "2013"; 
	CString str;
	str = m_grade.c_str();
	SetDlgItemText(IDC_SPLIT3, str);
}


void AddDlg::On32801()
{
	// TODO: 在此添加命令处理程序代码
	m_grade = "2012";
	CString str;
	str = m_grade.c_str();
	SetDlgItemText(IDC_SPLIT3, str);
}

