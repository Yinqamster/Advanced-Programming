
// StudentInformationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "StudentInformationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentInformationDlg 对话框



CStudentInformationDlg::CStudentInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STUDENTINFORMATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_password);
}

BEGIN_MESSAGE_MAP(CStudentInformationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CStudentInformationDlg::OnBnClickedRadio1)
//	ON_EN_CHANGE(IDC_EDIT1, &CStudentInformationDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CStudentInformationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &CStudentInformationDlg::OnBnClickedRadio2)
	ON_COMMAND(ID_32771, &CStudentInformationDlg::On32771)
END_MESSAGE_MAP()


// CStudentInformationDlg 消息处理程序

BOOL CStudentInformationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CStudentInformationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CStudentInformationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CStudentInformationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentInformationDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	//管理员
	radio = 0;
}

void CStudentInformationDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	//学生
	radio = 1;
}


void CStudentInformationDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	if (m_password.Compare(m_username) != 0) {
		MessageBox( _T("用户名或密码错误"),_T("reminder"), MB_OK | MB_ICONERROR);
		CStudentInformationDlg c;
		c.DoModal();
		//提示错误 
	}
	else if (radio == -1) {
		//请选择身份
		MessageBox(_T("请选择登录身份"), _T("reminder"), MB_OK | MB_ICONERROR);
		CStudentInformationDlg c;
		c.DoModal();
	}
	else if (radio == 0 && m_username.Compare(_T("admin")) != 0){
		//非管理员
		MessageBox(_T("非管理员身份，请重新选择"), _T("reminder"), MB_OK | MB_ICONERROR);
		CStudentInformationDlg c;
		c.DoModal();
	}
	else if (radio == 0){
		//admin进入学生信息管理系统		
		MenuDlg m;
		m.DoModal();
	}
	else if (radio == 1) {
		//student进入学生信息管理系统
		//新建对话框，读文件，打印出学生所有信息
		char buf[20] = { '\0' };
		WideCharToMultiByte(CP_ACP, 0, m_username.GetBuffer(0), m_username.GetLength(), buf, 20, 0, 0);
		string stuNo = buf;

		ifstream in("student.txt");
		int find = 0;
		string no;
		while (in >> no) {
			if (no == stuNo) {
				find = 1;
				break;
			}
		}
		

		if (find == 0) {
			string str = "不存在学号为" + stuNo + "的学生！";
			CString str1;
			str1 = str.c_str();
			MessageBox(str1, _T("reminder"), MB_OK | MB_ICONERROR);
			CStudentInformationDlg c;
			c.DoModal();
		}
		else if (find == 1) {			
			stuInfoDlg s;
			s.setNo(no);
			s.DoModal();
		}
		in.close();

		
	}

}





void CStudentInformationDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
}
