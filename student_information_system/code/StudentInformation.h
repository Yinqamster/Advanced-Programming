
// StudentInformation.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <vector>
#include <string.h>
using namespace std;

class Stu {
private:
	string no;
	string name;
	string sex;
	string grade;
	string department;
	string birthday;
	string telNo;
	string address;
public:
	Stu(string no, string name,string sex,string grade,string department,string birthday,string telNo,string address) {
		this->no = no;
		this->name = name;
		this->sex = sex;
		this->grade = grade;
		this->department = department;
		this->birthday = birthday;
		this->telNo = telNo;
		this->address = address;
	}
	string getNo() { return no; }
	string getName() { return name; }
	string getSex() { return sex; }
	string getGrade() { return grade; }
	string getDepartment() { return department; }
	string getBirthday() { return birthday; }
	string getTelNo() { return telNo; }
	string getAddress() { return address; }
};
extern vector<Stu*> stuList;

class Course {
private:
	string no;
	string name;
	string credit;
	string teacher;
public:
	Course(string no, string name, string credit, string teacher) {
		this->no = no;
		this->name = name;
		this->credit = credit;
		this->teacher = teacher;
	}
	string getNo() { return no; }
	string getName() { return name; }
	string getCredit() { return credit; }
	string getTeacher() { return teacher; }
};
extern vector<Course*> courseList;

class SelectCourse: public CDialogEx {
private:
	vector<Course*> curInfo;
	string stuNo;
	string stuName;
public:
	SelectCourse(string no, string name) {
		stuNo = no;
		stuName = name;
	}
	void addCourse(string cur);
	void delCourse(string cur);
	string getNo() { return stuNo; }
	string getName() { return stuName; }
	int getCurInfoSize() { return curInfo.size(); }
	Course* getCurInfo(int i) { return curInfo[i]; }
	void setCurInfo(Course* c) { curInfo.push_back(c); }
	void eraseCourse(int i) { curInfo.erase(curInfo.begin() + i); }
};
extern vector<SelectCourse*> seleInfo;











// CStudentInformationApp: 
// �йش����ʵ�֣������ StudentInformation.cpp
//

class CStudentInformationApp : public CWinApp
{
public:
	CStudentInformationApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStudentInformationApp theApp;