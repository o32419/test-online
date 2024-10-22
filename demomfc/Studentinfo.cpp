// Studentinfo.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "Studentinfo.h"
#include "afxdialogex.h"
#include "Adocon.h"
#include "SiAdd.h"
// Studentinfo 对话框

IMPLEMENT_DYNAMIC(Studentinfo, CDialogEx)

Studentinfo::Studentinfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Stuinfo, pParent)
{

}

Studentinfo::~Studentinfo()
{
}

void Studentinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}


BEGIN_MESSAGE_MAP(Studentinfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Studentinfo::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Studentinfo::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Studentinfo::OnBnClickedButton3)
END_MESSAGE_MAP()


// Studentinfo 消息处理程序
void Studentinfo::refresh()
{
	CRect rect;
	CString sql, test, name, dep, sno;
	Adocon con;
	_RecordsetPtr rec, rec_info;
	_variant_t vt, vt_name, vt_sno, vt_dep;
	con.initadocon();
	sql = "select count(*) as[c] from stuinfo";
	rec = con.record(sql);
	vt = rec->GetCollect("c");
	test = (LPCSTR)_bstr_t(vt);
	int num = _ttoi(test);
	sql = "select * from stuinfo";
	rec_info = con.record(sql);


	//AfxMessageBox(test);
	//

	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("学号"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_list.InsertColumn(2, _T("系别"), LVCFMT_CENTER, rect.Width() / 3, 2);





	for (auto i = 0; i < num; i++)
	{
		//rec->MoveFirst();
		vt_sno = rec_info->GetCollect("sno");
		vt_name = rec_info->GetCollect("name");
		vt_dep = rec_info->GetCollect("major");
		sno = (LPCSTR)_bstr_t(vt_sno);
		name = (LPCSTR)_bstr_t(vt_name);
		dep = (LPCSTR)_bstr_t(vt_dep);

		m_list.InsertItem(i, sno);

		m_list.SetItemText(i, 1, name);
		m_list.SetItemText(i, 2, dep);

		rec_info->MoveNext();
	}

	con.exitcon();


}

BOOL Studentinfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	/*
	CRect rect;
	CString sql,test,name,dep,sno;
	Adocon con;
	_RecordsetPtr rec,rec_info;
	_variant_t vt,vt_name,vt_sno,vt_dep;
	con.initadocon();
	sql = "select count(*) as[c] from stuinfo";
	rec = con.record(sql);
	vt = rec->GetCollect("c");
	test = (LPCSTR)_bstr_t(vt);
	int num = _ttoi(test);
	sql = "select * from stuinfo";
	rec_info = con.record(sql);


	//AfxMessageBox(test);
	//
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("学号"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_list.InsertColumn(2, _T("系别"), LVCFMT_CENTER, rect.Width() / 3, 2);





	for (auto i=0;i < num;i++)
	{
	//rec->MoveFirst();
	vt_sno=rec_info->GetCollect("sno");
	vt_name = rec_info->GetCollect("name");
	vt_dep = rec_info->GetCollect("major");
	sno= (LPCSTR)_bstr_t(vt_sno);
	name = (LPCSTR)_bstr_t(vt_name);
	dep = (LPCSTR)_bstr_t(vt_dep);

	m_list.InsertItem(i, sno);

	m_list.SetItemText(i, 1, name);
	m_list.SetItemText(i, 2, dep);

	if(!rec_info->adoEOF)
	rec_info->MoveNext();
	}

	*/
	refresh();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void Studentinfo::OnBnClickedButton1()  //add
{
	// TODO: 在此添加控件通知处理程序代码
	/*
	m_examrecord->AddNew();
	m_examrecord->PutCollect("sno", m_id);
	m_examrecord->PutCollect("question_id", qid);
	m_examrecord->PutCollect("answer", _variant_t(answer));
	m_examrecord->PutCollect("acscore", score);
	m_examrecord->Update();
	*/
	SiAdd sadd;
	sadd.DoModal();
	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);
	//m_list.dele
	refresh();
}



void Studentinfo::OnBnClickedButton2()  //fix
{
	// TODO: 在此添加控件通知处理程序代码
	int a;
	CString s_sno;

	a = m_list.GetSelectionMark();
	s_sno = m_list.GetItemText(a, 0);

	SiAdd fix;
	fix.type = "fix";
	fix.stno = s_sno;
	fix.DoModal();
	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);
	//m_list.dele
	refresh();

}




void Studentinfo::OnBnClickedButton3()  //del
{
	// TODO: 在此添加控件通知处理程序代码
	Adocon con;
	_RecordsetPtr record;
	CString sql, s_sno;
	int a;
	a = m_list.GetSelectionMark();
	s_sno = m_list.GetItemText(a, 0);

	int s_no = _ttoi(s_sno);
	sql.Format(_T("select * from stuinfo where sno=%d"), s_no);
	con.initadocon();


	record = con.record(sql);
	record->Delete(adAffectCurrent);
	record->Update();
	con.exitcon();
	/*
	sql.Format(_T("delete from stuinfo where sno=%d"), s_no);
	con.initadocon();
	con.executesql(sql);
	con.exitcon();
	*/
	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);

	//m_list.dele
	refresh();
}
