// stuInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "stuInfoDlg.h"
#include "afxdialogex.h"


// stuInfoDlg 对话框

IMPLEMENT_DYNAMIC(stuInfoDlg, CDialogEx)

stuInfoDlg::stuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{
//	OnEnChangeEdit1();
}

stuInfoDlg::~stuInfoDlg()
{
}

void stuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_info);
	DDX_Text(pDX, IDC_EDIT1, m_result);
}


BEGIN_MESSAGE_MAP(stuInfoDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &stuInfoDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &stuInfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &stuInfoDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// stuInfoDlg 消息处理程序

void stuInfoDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
/*

	string no;
	string name;
	string sex;
	string grade;
	string department;
	string birthday;
	string telNo;
	string address;
	int find = 0;
	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i]->getNo() == stuNo) {
			//打出学生信息
			no = stuList[i]->getNo();
			name = stuList[i]->getName();
			sex = stuList[i]->getSex();
			grade = stuList[i]->getGrade();
			department = stuList[i]->getDepartment();
			birthday = stuList[i]->getBirthday();
			telNo = stuList[i]->getTelNo();
			address = stuList[i]->getAddress();

			string res = "学号：" + no + "\r\n" + "姓名：" + name + "\r\n" + "性别：" + sex + "\r\n" + "年级：" + grade + "\r\n" + "系别：" + department + "\r\n" + "出生日期：" + birthday + "\r\n" + "联系方式：" + telNo + "\r\n" + "住址：" + address + "\r\n";
			CString m_result;
			m_result = res.c_str();
			SetDlgItemText(IDC_EDIT2, m_result);
			find = 1;
			break;
		}
	}

	if (find == 0) {
		string str = "不存在学号为" + stuNo + "的学生！";
		CString str1;
		str1 = str.c_str();
		MessageBox(str1, _T("reminder"), MB_OK | MB_ICONERROR);
	}*/
}

void stuInfoDlg::setNo(string no)
{
	stuNo = no;
}


void stuInfoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream in("student.txt");
	string temp, str;
	int find = 0;
	string no;
	string name;
	string sex;
	string grade;
	string department;
	string birthday;
	string telNo;
	string address;
	while (in >> no) {
		if (no == stuNo) {
			in >> name;
			in >> sex;
			in >> grade;
			in >> department;
			in >> birthday;
			in >> telNo;
			in >> address;
			string res = "学号：" + no + "\r\n" + "姓名：" + name + "\r\n" + "性别：" + sex + "\r\n" + "年级：" + grade + "\r\n" + "系别：" + department + "\r\n" + "出生日期：" + birthday + "\r\n" + "联系方式：" + telNo + "\r\n" + "住址：" + address + "\r\n";
			//		CString m_result;
			m_result = res.c_str();
			SetDlgItemText(IDC_EDIT1, m_result);
			find = 1;
			break;
		}
	}

	if (find == 0) {
		string str = "不存在学号为" + stuNo + "的学生！";
		CString str1;
		str1 = str.c_str();
		MessageBox(str1, _T("reminder"), MB_OK | MB_ICONERROR);
	}
	in.close();
}


void stuInfoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream in("select.txt");
	int find = 0;
	string line;
	string no;
	string name;
	string credit;
	string curName;
	string str = "";
	CString c_str;
	str += "学分\t课程名\r\n";
	while (!in.eof()) {
		getline(in, line);
		std::string::size_type begin = line.find_first_of(" ", 0);
		no = line.substr(0, begin);
		if (stuNo != no) {
			break;
		}
		else {
			find = 1;
			std::string::size_type end = line.find_first_of(" ", begin + 1);
			name = line.substr(begin + 1, end - begin - 1);
			begin = end + 1;
			while (begin != line.length()) {
				end = line.find_first_of(" ", begin);
				credit = line.substr(begin, end - begin);
				begin = end + 1;
				end = line.find_first_of(" ", begin);
				curName = line.substr(begin, end - begin);
				begin = end + 1;
				str += credit + "\t" + curName + "\r\n";
			}
		}
	}
	if (find == 0) {
		str += "无\r\n";
	}
	c_str = str.c_str();
	SetDlgItemText(IDC_EDIT1, c_str);
	in.close();
}
