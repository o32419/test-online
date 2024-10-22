// SiAdd.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "SiAdd.h"
#include "afxdialogex.h"
#include "Adocon.h"

// SiAdd 对话框

IMPLEMENT_DYNAMIC(SiAdd, CDialogEx)

SiAdd::SiAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DAdd, pParent)
	, s_sno(0)
	, s_name(_T(""))
	, s_dep(_T(""))
{

}

SiAdd::~SiAdd()
{
}

void SiAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s_sno);
	DDX_Text(pDX, IDC_EDIT4, s_name);
	DDX_Text(pDX, IDC_EDIT2, s_dep);
}


BEGIN_MESSAGE_MAP(SiAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &SiAdd::OnBnClickedButton1)
END_MESSAGE_MAP()


// SiAdd 消息处理程序


void SiAdd::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	Adocon con;
	_RecordsetPtr record;
	CString sql;
	UpdateData(true);

	if (type == "fix")
	{
		int s_no = _ttoi(stno);
		sql.Format(_T("select * from stuinfo where sno=%d"), s_no);
		con.initadocon();
		record = con.record(sql);
		record->PutCollect("sno", s_sno);
		record->PutCollect("name", _variant_t(s_name));
		record->PutCollect("major", _variant_t(s_dep));
		record->Update();



	}
	else
	{
		sql = "select * from stuinfo";
		con.initadocon();
		record = con.record(sql);

		record->AddNew();
		record->PutCollect("sno", s_sno);
		record->PutCollect("name", _variant_t(s_name));
		record->PutCollect("major", _variant_t(s_dep));

		record->Update();


		con.exitcon();

	}

}
