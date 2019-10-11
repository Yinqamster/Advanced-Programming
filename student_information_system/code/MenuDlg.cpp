// MenuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "MenuDlg.h"
#include "afxdialogex.h"


// MenuDlg 对话框

IMPLEMENT_DYNAMIC(MenuDlg, CDialogEx)

MenuDlg::MenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

	ifstream in("select.txt");
	int flag = 0;
	string line;
	string no;
	string name;
	string credit;
	string curName;

	while (!in.eof()) {
		getline(in, line);
		if (line.length() != 0) {
			std::string::size_type begin = line.find_first_of(" ", 0);
			no = line.substr(0, begin);
			std::string::size_type end = line.find_first_of(" ", begin + 1);
			name = line.substr(begin + 1, end - begin - 1);
			begin = end + 1;
			SelectCourse * s = new SelectCourse(no, name);
			while (begin != line.length()) {
				end = line.find_first_of(" ", begin);
				credit = line.substr(begin, end - begin);
				begin = end + 1;
				end = line.find_first_of(" ", begin);
				curName = line.substr(begin, end - begin);
				begin = end + 1;
				Course *c = new Course("", curName, credit, "");
				s->setCurInfo(c);
			}
			seleInfo.push_back(s);
		}	
	}
	in.close();
}

MenuDlg::~MenuDlg()
{
}

void MenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MenuDlg, CDialogEx)
	ON_COMMAND(ID_32771, &MenuDlg::OnImportStuInfo)
	ON_COMMAND(ID_32772, &MenuDlg::OnExportStuInfo)
	ON_COMMAND(ID_32774, &MenuDlg::OnAddStuInfo)
	ON_COMMAND(ID_32775, &MenuDlg::OnDeleteStuInfo)
	ON_COMMAND(ID_32777, &MenuDlg::OnSearchStuInfo)
	ON_COMMAND(ID_32803, &MenuDlg::OnShowInfo)
	ON_COMMAND(ID_32802, &MenuDlg::OnShowInfo)
	ON_COMMAND(ID_32778, &MenuDlg::OnImportCourse)
	ON_COMMAND(ID_32779, &MenuDlg::OnExportCourse)
	ON_COMMAND(ID_32806, &MenuDlg::OnShowCourse)
	ON_COMMAND(ID_32781, &MenuDlg::OnAddCourse)
	ON_COMMAND(ID_32782, &MenuDlg::OnDelCourse)
	ON_COMMAND(ID_32807, &MenuDlg::OnSelectCourse)
	ON_COMMAND(ID_32808, &MenuDlg::OnDropCourse)
	ON_COMMAND(ID_32809, &MenuDlg::OnQueryStudent)
	ON_COMMAND(ID_32810, &MenuDlg::OnQueryCourse)
	ON_COMMAND(ID_32811, &MenuDlg::OnAllSelection)
END_MESSAGE_MAP()


// MenuDlg 消息处理程序

void MenuDlg::OnImportStuInfo()
{
	// TODO: 在此添加命令处理程序代码
	//信息导入
	ifstream in("student.txt");
	string temp, str;
	int flag = 0;
	string no;
	string name;
	string sex;
	string grade;
	string department;
	string birthday;
	string telNo;
	string address;
	while (in >> no) {
		in >> name;
		in >> sex;
		in >> grade;
		in >> department;
		in >> birthday;
		in >> telNo;
		in >> address;

		Stu *s = new Stu(no, name, sex, grade, department, birthday, telNo, address);
		stuList.push_back(s);
	//	break;
	}
	in.close();

	MessageBox(_T("      导入成功"), _T("reminder"), MB_OK);

	
}


void MenuDlg::OnExportStuInfo()
{
	// TODO: 在此添加命令处理程序代码
	//信息导出
	ofstream ou;
	ou.open("student.txt");	
	for (int i = 0; i < stuList.size(); i++) {
		ou << stuList[i]->getNo() << " ";
		ou << stuList[i]->getName() << " ";
		ou << stuList[i]->getSex() << " ";
		ou << stuList[i]->getGrade() << " ";
		ou << stuList[i]->getDepartment() << " ";
		ou << stuList[i]->getBirthday() << " ";
		ou << stuList[i]->getTelNo() << " ";
		ou << stuList[i]->getAddress() << endl;
	}
	ou.close();
	MessageBox(_T("      导出成功"), _T("reminder"), MB_OK);
}


void MenuDlg::OnAddStuInfo()
{
	// TODO: 在此添加命令处理程序代码
	AddDlg a;
	a.DoModal();
}


void MenuDlg::OnDeleteStuInfo()
{
	// TODO: 在此添加命令处理程序代码
	DelDlg d;
	d.DoModal();
}


void MenuDlg::OnSearchStuInfo()
{
	// TODO: 在此添加命令处理程序代码
	SearchDlg sd;
	sd.DoModal();
}




void MenuDlg::OnShowInfo()
{
	// TODO: 在此添加命令处理程序代码
	ShowDlg s;
	s.DoModal();
}


void MenuDlg::OnImportCourse()
{
	// TODO: 在此添加命令处理程序代码
	ifstream in("course.txt");
	int flag = 0;
	string no;
	string name;
	string credit;
	string teacher;

	while (in >> no) {
		in >> name;
		in >> credit;
		in >> teacher;

		Course *c = new Course(no, name, credit, teacher);
		courseList.push_back(c);
		//	break;
	}
	in.close();

	MessageBox(_T("      导入成功"), _T("reminder"), MB_OK);
}


void MenuDlg::OnExportCourse()
{
	// TODO: 在此添加命令处理程序代码
	ofstream ou;
	ou.open("course.txt");
	for (int i = 0; i < courseList.size(); i++) {
		ou << courseList[i]->getNo() << " ";
		ou << courseList[i]->getName() << " ";
		ou << courseList[i]->getCredit() << " ";
		ou << courseList[i]->getTeacher() <<endl;
	}
	ou.close();
	MessageBox(_T("      导出成功"), _T("reminder"), MB_OK);
}


void MenuDlg::OnShowCourse()
{
	// TODO: 在此添加命令处理程序代码
	ShowCourseDlg s;
	s.DoModal();
}


void MenuDlg::OnAddCourse()
{
	// TODO: 在此添加命令处理程序代码
	AddCourseDlg a;
	a.DoModal();
}


void MenuDlg::OnDelCourse()
{
	// TODO: 在此添加命令处理程序代码
	DelCourseDlg d;
	d.DoModal();
}


void MenuDlg::OnSelectCourse()
{
	// TODO: 在此添加命令处理程序代码
	SelectCourseDlg s;
	s.DoModal();
}


void MenuDlg::OnDropCourse()
{
	// TODO: 在此添加命令处理程序代码
	DropCourseDlg d;
	d.DoModal();
}


void MenuDlg::OnQueryStudent()
{
	// TODO: 在此添加命令处理程序代码
	QueryStudentDlg q;
	q.DoModal();
}


void MenuDlg::OnQueryCourse()
{
	// TODO: 在此添加命令处理程序代码
	QueryCourseDlg q;
	q.DoModal();
}


void MenuDlg::OnAllSelection()
{
	// TODO: 在此添加命令处理程序代码
	AllSelectionDlg a;
	a.DoModal();
}
