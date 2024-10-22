// Admin.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "Admin.h"
#include "afxdialogex.h"
#include "Studentinfo.h"
#include "StudentScore.h"
#include "Sexam.h"
// Admin 对话框

IMPLEMENT_DYNAMIC(Admin, CDialogEx)

Admin::Admin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Admin, pParent)
{

}

Admin::~Admin()
{
}

void Admin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(Admin, CDialogEx)
	//ON_NOTIFY(TCN_SELCHANGING, IDC_TAB1, &Admin::OnTcnSelchangingTab1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Admin::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// Admin 消息处理程序
Studentinfo stuinfo;
StudentScore stusco;
Sexam exam;
BOOL Admin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect tabrect;
	m_tab.InsertItem(0, _T("学生信息"));
	m_tab.InsertItem(1, _T("学生成绩"));
	m_tab.InsertItem(2, _T("试题管理"));
	stuinfo.Create(IDD_Stuinfo, &m_tab);
	stusco.Create(IDD_StuScore, &m_tab);
	exam.Create(IDD_Exam, &m_tab);
	m_tab.GetClientRect(&tabrect);
	tabrect.left += 4;
	tabrect.right -= 4;
	tabrect.top += 23;
	tabrect.bottom -= 4;

	stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
	// 根据调整好的tabRect放置m_androidDlg子对话框，并设置为隐藏   
	stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
	exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);




	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
/*
void Admin::OnTcnSelchangingTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CRect tabrect;


	m_tab.GetClientRect(&tabrect);
	tabrect.left += 4;
	tabrect.right -= 4;
	tabrect.top += 23;
	tabrect.bottom -= 4;
	
	CString s;
	s.Format(_T("%d"),m_tab.GetCurSel());
	AfxMessageBox(s);
	
	switch (m_tab.GetCurSel())
	{
		  
	case 2:
		stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
		stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		break;

	case 0:
		stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
		exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		break;
	case 1:
		stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
		break;

	default:  break;
	}

	
}
*/

void Admin::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CRect tabrect;


	m_tab.GetClientRect(&tabrect);
	tabrect.left += 4;
	tabrect.right -= 4;
	tabrect.top += 23;
	tabrect.bottom -= 4;


	switch (m_tab.GetCurSel())
	{

	case 0:
		stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
		stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		break;

	case 1:
		stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
		exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		break;
	case 2:
		stuinfo.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		stusco.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_HIDEWINDOW);
		exam.SetWindowPos(NULL, tabrect.left, tabrect.top, tabrect.Width(), tabrect.Height(), SWP_SHOWWINDOW);
		break;

	default:  break;
	}


}
