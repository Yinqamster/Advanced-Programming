
// StudentInformationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentInformation.h"
#include "StudentInformationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CStudentInformationDlg �Ի���



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


// CStudentInformationDlg ��Ϣ�������

BOOL CStudentInformationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStudentInformationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CStudentInformationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentInformationDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//����Ա
	radio = 0;
}

void CStudentInformationDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ѧ��
	radio = 1;
}


void CStudentInformationDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();

	if (m_password.Compare(m_username) != 0) {
		MessageBox( _T("�û������������"),_T("reminder"), MB_OK | MB_ICONERROR);
		CStudentInformationDlg c;
		c.DoModal();
		//��ʾ���� 
	}
	else if (radio == -1) {
		//��ѡ�����
		MessageBox(_T("��ѡ���¼���"), _T("reminder"), MB_OK | MB_ICONERROR);
		CStudentInformationDlg c;
		c.DoModal();
	}
	else if (radio == 0 && m_username.Compare(_T("admin")) != 0){
		//�ǹ���Ա
		MessageBox(_T("�ǹ���Ա��ݣ�������ѡ��"), _T("reminder"), MB_OK | MB_ICONERROR);
		CStudentInformationDlg c;
		c.DoModal();
	}
	else if (radio == 0){
		//admin����ѧ����Ϣ����ϵͳ		
		MenuDlg m;
		m.DoModal();
	}
	else if (radio == 1) {
		//student����ѧ����Ϣ����ϵͳ
		//�½��Ի��򣬶��ļ�����ӡ��ѧ��������Ϣ
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
			string str = "������ѧ��Ϊ" + stuNo + "��ѧ����";
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
	// TODO: �ڴ���������������
}
