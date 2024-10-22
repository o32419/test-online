// StudentScore.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "StudentScore.h"
#include "afxdialogex.h"
#include "Adocon.h"

// StudentScore 对话框

IMPLEMENT_DYNAMIC(StudentScore, CDialogEx)

StudentScore::StudentScore(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_StuScore, pParent)
	, sc(0)
{

}

StudentScore::~StudentScore()
{
}

void StudentScore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, sc);
}


BEGIN_MESSAGE_MAP(StudentScore, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &StudentScore::OnBnClickedButton1)
END_MESSAGE_MAP()


// StudentScore 消息处理程序
void StudentScore::refresh(int sco)
{
	CRect rect;
	CString sql, test, name, dep, sno;
	Adocon con;
	_RecordsetPtr rec, rec_info;
	_variant_t vt, vt_name, vt_sno, vt_dep;
	con.initadocon();
	sql = "select count(*) as[c] from stuscore";
	rec = con.record(sql);
	vt = rec->GetCollect("c");
	test = (LPCSTR)_bstr_t(vt);
	int num = _ttoi(test);
	sql = "select * from stuscore";
	rec_info = con.record(sql);


	//AfxMessageBox(test);
	//

	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_list.InsertColumn(1, _T("课程"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_list.InsertColumn(2, _T("分数"), LVCFMT_CENTER, rect.Width() / 3, 2);





	for (auto i = 0; i < num; i++)
	{
		//rec->MoveFirst();
		vt_sno = rec_info->GetCollect("stu_name");
		vt_name = rec_info->GetCollect("sub_name");
		vt_dep = rec_info->GetCollect("stu_score");
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


void StudentScore::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_list.DeleteAllItems();
	int n = m_list.GetHeaderCtrl()->GetItemCount();
	for (auto i = 0; i < n; i++)
		m_list.DeleteColumn(0);
	//m_list.dele
	CRect rect;
	CString sql, test, name, dep, sno;
	Adocon con;
	_RecordsetPtr rec, rec_info;
	_variant_t vt, vt_name, vt_sno, vt_dep;
	con.initadocon();
	sql.Format(_T("select count(*) as[c] from stuscore where stu_score>=%d"), sc);

	rec = con.record(sql);
	vt = rec->GetCollect("c");
	test = (LPCSTR)_bstr_t(vt);
	int num = _ttoi(test);
	sql.Format(_T("select * from stuscore where stu_score >= %d"), sc);

	rec_info = con.record(sql);


	//AfxMessageBox(test);
	//

	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("姓名"), LVCFMT_CENTER, rect.Width() / 3, 0);
	m_list.InsertColumn(1, _T("课程"), LVCFMT_CENTER, rect.Width() / 3, 1);
	m_list.InsertColumn(2, _T("分数"), LVCFMT_CENTER, rect.Width() / 3, 2);



	//AfxMessageBox(test);

	for (auto i = 0; i < num; i++)
	{
		//rec->MoveFirst();
		vt_sno = rec_info->GetCollect("stu_name");
		vt_name = rec_info->GetCollect("sub_name");
		vt_dep = rec_info->GetCollect("stu_score");
		sno = (LPCSTR)_bstr_t(vt_sno);
		name = (LPCSTR)_bstr_t(vt_name);
		dep = (LPCSTR)_bstr_t(vt_dep);

		m_list.InsertItem(i, sno);

		m_list.SetItemText(i, 1, name);
		m_list.SetItemText(i, 2, dep);
		//
		if (!rec_info->adoEOF)
			rec_info->MoveNext();

	}

	con.exitcon();

}


BOOL StudentScore::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	refresh(1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
