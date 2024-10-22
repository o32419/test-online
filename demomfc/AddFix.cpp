// AddFix.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "AddFix.h"
#include "afxdialogex.h"
#include "Adocon.h"

// AddFix 对话框

IMPLEMENT_DYNAMIC(AddFix, CDialogEx)

AddFix::AddFix(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddFix, pParent)
	, qnum(0)
	, question(_T(""))
	, ans(_T(""))
	, sc(0)
	, a(_T(""))
	, b(_T(""))
	, c(_T(""))
	, d(_T(""))
{

}

AddFix::~AddFix()
{
}

void AddFix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT10, qnum);
	DDX_Text(pDX, IDC_EDIT1, question);
	DDX_Text(pDX, IDC_EDIT7, ans);
	DDX_Text(pDX, IDC_EDIT8, sc);
	DDX_Text(pDX, IDC_EDIT2, a);
	DDX_Text(pDX, IDC_EDIT4, b);
	DDX_Text(pDX, IDC_EDIT5, c);
	DDX_Text(pDX, IDC_EDIT6, d);
}


BEGIN_MESSAGE_MAP(AddFix, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddFix::OnBnClickedOk)
END_MESSAGE_MAP()


// AddFix 消息处理程序


void AddFix::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();

	Adocon con;
	_RecordsetPtr record;
	
	UpdateData(true);

	if (t == "fix")
	{
		//int s_no = _ttoi(num);
		CString sqa, sqb,q_id;
		_variant_t t;
		long qid;
	//testquestion
	sqa.Format(_T("select * from testquestion where question='%s'"), num);
	con.initadocon();
	record = con.record(sqa);
	t = record->GetCollect("question_id");
	q_id = (LPCSTR)_bstr_t(t);
	qid = _ttoi(q_id);
	record->PutCollect("question_id", qnum);
	record->PutCollect("question", _variant_t(question));
	record->PutCollect("ans", _variant_t(ans));
	record->PutCollect("score", sc);
	record->PutCollect("subject_id", subid);
	record->Update();
	//testanswer
	sqb.Format(_T("select * from testanswer where que_id=%d"), qid);
	con.initadocon();
	record = con.record(sqb);
	record->PutCollect("que_id", qnum);
		record->PutCollect("ans_a", _variant_t(a));
		record->PutCollect("ans_b", _variant_t(b));
		record->PutCollect("ans_c", _variant_t(c));
		record->PutCollect("ans_d", _variant_t(d));
		
		record->Update();
		
	}
	else
	{
		CString sql;
		sql="select * from testquestion,testanswer where testquestion.question_id=testanswer.que_id";

		con.initadocon();
		record = con.record(sql);
		record->AddNew();
		record->PutCollect("question_id", qnum);
		record->PutCollect("que_id",qnum);
		record->PutCollect("question", _variant_t(question));
		record->PutCollect("ans", _variant_t(ans));
		record->PutCollect("score", sc);
		record->PutCollect("subject_id", subid);
		record->PutCollect("ans_a", _variant_t(a));
		record->PutCollect("ans_b", _variant_t(b));
		record->PutCollect("ans_c", _variant_t(c));
		record->PutCollect("ans_d", _variant_t(d));
		record->Update();
		con.exitcon();

	}



}
