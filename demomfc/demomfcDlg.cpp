
// demomfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "demomfcDlg.h"
#include "afxdialogex.h"
#include "Adocon.h"
#include "Testype.h"
#include "Admin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdemomfcDlg 对话框



CdemomfcDlg::CdemomfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DEMOMFC_DIALOG, pParent)
	, user_name(_T(""))
	, user_password()

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdemomfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, user_name);
	DDX_Text(pDX, IDC_EDIT3, user_password);
}

BEGIN_MESSAGE_MAP(CdemomfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_login, &CdemomfcDlg::OnBnClickedButtonlogin)
	ON_BN_CLICKED(IDC_BUTTON_exit, &CdemomfcDlg::OnBnClickedButtonexit)
	ON_BN_CLICKED(IDC_RADIO_stu, &CdemomfcDlg::OnBnClickedRadiostu)
	ON_BN_CLICKED(IDC_RADIO_admin, &CdemomfcDlg::OnBnClickedRadioadmin)
END_MESSAGE_MAP()


// CdemomfcDlg 消息处理程序

BOOL CdemomfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

									// TODO: 在此添加额外的初始化代码

	SetDlgItemText(IDC_EDIT1, _T(""));  //设置密码框的初始值
	SetDlgItemText(IDC_EDIT3,_T(""));


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CdemomfcDlg::OnPaint()
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
HCURSOR CdemomfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int m_radioflag = 0;

void CdemomfcDlg::OnBnClickedButtonlogin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Adocon dbcon;
	_RecordsetPtr mrecord;
	CString sql;
	sql.Format(_T("select * from stuinfo where sno=%d and name='%s'"), user_password, user_name);
	dbcon.initadocon();
	mrecord = dbcon.record(sql);

	if (m_radioflag == 1)
	{
		if (!mrecord->adoEOF)
		{
			SendMessage(WM_CLOSE);
			dbcon.exitcon();
			Testype t;
			t.m_id = user_password;
			t.DoModal();
			// mrecord = NULL;
		}
		else
		{
			INT_PTR res;
			res = MessageBox(_T("用户名或密码错误"), _T(""), MB_OK | MB_ICONERROR);
		}



	}


	if (m_radioflag == 2)
	{
		if (!mrecord->adoEOF)
		{
			SendMessage(WM_CLOSE);
			dbcon.exitcon();
			Admin a;
			a.DoModal();

		}
		else
		{
			INT_PTR res;
			res = MessageBox(_T("用户名或密码错误"), _T(""), MB_OK | MB_ICONERROR);
		}

	}







}


void CdemomfcDlg::OnBnClickedButtonexit()
{
	// TODO: 在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE);
}


void CdemomfcDlg::OnBnClickedRadiostu()
{
	// TODO: 在此添加控件通知处理程序代码
	m_radioflag = 1;
}




void CdemomfcDlg::OnBnClickedRadioadmin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_radioflag = 2;
}
