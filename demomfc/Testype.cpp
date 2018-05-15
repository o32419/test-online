// Testype.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "Testype.h"
#include "afxdialogex.h"
#include "Examing.h"

// Testype 对话框

IMPLEMENT_DYNAMIC(Testype, CDialogEx)

Testype::Testype(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_select_paper, pParent)
{

}

Testype::~Testype()
{
}

void Testype::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
}


BEGIN_MESSAGE_MAP(Testype, CDialogEx)
	ON_BN_CLICKED(IDC_ok, &Testype::OnBnClickedok)
END_MESSAGE_MAP()


// Testype 消息处理程序


BOOL Testype::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_combox.AddString(_T("数据库"));
	m_combox.AddString(_T("数据结构"));
	m_combox.AddString(_T("操作系统"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Testype::OnBnClickedok()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	SendMessage(WM_CLOSE);
	CComboBox *box;
	box = (CComboBox*)GetDlgItem(IDC_COMBO1);
	
	Examing ex;
	ex.m_id = m_id;
	ex.m_type = box->GetCurSel();
	ex.DoModal();
	
}

