// Examing.cpp: 实现文件
//

#include "stdafx.h"
#include "demomfc.h"
#include "Examing.h"
#include "afxdialogex.h"
#include "Adocon.h"

// Examing 对话框

IMPLEMENT_DYNAMIC(Examing, CDialogEx)

Examing::Examing(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_examing, pParent)
	, m_question(_T(""))
	, m_ansa(_T(""))
	, m_ansb(_T(""))
	, m_ansc(_T(""))
	, m_ansd(_T(""))
	, m_testnum(0)
	, m_timer()
	, m_checked(-1)
{

}

Examing::~Examing()
{
}

void Examing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_question);
	DDX_Text(pDX, IDC_EDIT6, m_ansa);
	DDX_Text(pDX, IDC_EDIT8, m_ansb);
	DDX_Text(pDX, IDC_EDIT7, m_ansc);
	DDX_Text(pDX, IDC_EDIT9, m_ansd);
	DDX_Text(pDX, IDC_EDIT2, m_testnum);
	DDX_Radio(pDX, IDC_RADIO_A, m_checked);
	DDX_Control(pDX, IDC_EDIT5, m_timer);
}


BEGIN_MESSAGE_MAP(Examing, CDialogEx)
	//ON_BN_CLICKED(IDC_RADIO1, &Examing::OnBnClickedRadio1)
	ON_EN_CHANGE(IDC_EDIT9, &Examing::OnEnChangeEdit9)
	ON_BN_CLICKED(IDC_next, &Examing::OnBnClickednext)
	ON_BN_CLICKED(IDC_prev, &Examing::OnBnClickedprev)
	ON_BN_CLICKED(IDC_sub, &Examing::OnBnClickedsub)
	ON_BN_CLICKED(IDC_RADIO_A, &Examing::OnBnClickedRadioA)
	ON_BN_CLICKED(IDC_RADIO_B, &Examing::OnBnClickedRadioA)
	ON_BN_CLICKED(IDC_RADIO_C, &Examing::OnBnClickedRadioA)
	ON_BN_CLICKED(IDC_RADIO_D, &Examing::OnBnClickedRadioA)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Examing 消息处理程序

Adocon dbc, dbw;
_RecordsetPtr m_record, m_examrecord;
CString sql, sql_update;
_variant_t vt, vt_ansa, vt_ansb, vt_ansc, vt_ansd;

BOOL Examing::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	dbw.initadocon();
	dbc.initadocon();
	sql = "select * from examinginfo";
	m_examrecord = dbc.record(sql);
	if (m_type == 0)     //数据库
	{
		sql = "select * from testanswer,testquestion where testanswer.que_id= testquestion.question_id and subject_id =3001";
		m_record = dbc.record(sql);
		showtest();
		m_testnum = 1;
		UpdateData(false);
		//m_record->raw_MoveNext();
	}
	else
	{
		sql = "select * from testanswer,testquestion where testanswer.que_id= testquestion.question_id and subject_id =3000";
		m_record = dbc.record(sql);
		showtest();
		m_testnum = 1;
		UpdateData(false);
		//	m_record->raw_MoveNext();

	}
	//设置定时器
	SetTimer(1, 1000, NULL);
	m_timer.SetWindowTextW(_T("30：00"));

	return TRUE;  

}

void Examing::showtest()
{
	vt = m_record->GetCollect("question");
	m_question = (LPCSTR)_bstr_t(vt);
	vt_ansa = m_record->GetCollect("ans_a");
	m_ansa = (LPCSTR)_bstr_t(vt_ansa);
	vt_ansb = m_record->GetCollect("ans_b");
	m_ansb = (LPCSTR)_bstr_t(vt_ansb);
	vt_ansc = m_record->GetCollect("ans_c");
	m_ansc = (LPCSTR)_bstr_t(vt_ansc);
	vt_ansd = m_record->GetCollect("ans_d");
	m_ansd = (LPCSTR)_bstr_t(vt_ansd);

}

CString answer = NULL;
CString  q_ans, q_score;
_variant_t t;
CString q_id;
long qid, score, sco;   //数据类型






void Examing::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Examing::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Examing::OnBnClickednext()
{


	
	//AfxMessageBox(answer);
	
	// TODO: 在此添加控件通知处理程序代码
	CString f_id_sql, f_cs;
	_RecordsetPtr f_id_rec;
	_variant_t f_vt;
	if (!m_record->adoEOF)
	{

		switch (m_checked)
	{
	case 0: answer = "A"; break;
	case 1:answer = "B"; break;
	case 2:answer = "C"; break;
	case 3:answer = "D"; break;
	default:answer = "E";

	}

		t = m_record->GetCollect("question_id");
		q_id = (LPCSTR)_bstr_t(t);
		qid = _ttoi(q_id);

		q_score = (LPCSTR)_bstr_t(m_record->GetCollect("score"));
		sco = _ttoi(q_score);

		q_ans = (LPCSTR)_bstr_t(m_record->GetCollect("ans"));

		
		if (answer == q_ans)
		{
			score = sco;
		}
		else
		{
			score = 0;
		}
		//	sql_update.Format(_T("INSERT INTO examinginfo(sno,question_id,answer,acscore) values(%d,%d,'%s',%d)"),m_id,qid,answer,score) ;
		//	sql_update.Format(_T("INSERT INTO examinginfo(sno,question_id,answer,acscore) VALUES(3,3,'a',0)")) ;
		//	sql_update.Format(_T("INSERT INTO examinginfo(sno,question_id,answer,acscore) VALUES(%d,%d,'%s',%d)"), m_id, qid, answer, score);

		//	sql_update.Format(_T("insert into stuinfo(name) values('%s')"), a);
		//	int a = 90;
		//sql_update.Format(_T("insert into examinginfo values(2,3,'a',30)"));
		//	dbw.executesql(sql_update);
		//	m_examrecord->MoveLast();

		
		f_id_sql.Format(_T("select * from examinginfo where question_id=%d"), qid);
		f_id_rec = dbc.record(f_id_sql);

		//examinginfo，如果有记录，修改记录；若没有记录，增加新记录。
		if (f_id_rec->adoEOF)  //数据库去掉主键约束
		{
			
			//m_examrecord->MoveLast();
			m_examrecord->AddNew();
			m_examrecord->PutCollect("sno", m_id);
			m_examrecord->PutCollect("question_id", qid);
			m_examrecord->PutCollect("answer", _variant_t(answer));
			m_examrecord->PutCollect("acscore", score);
			m_examrecord->Update();

		}
		
		else
		{
			f_id_rec->PutCollect("answer", _variant_t(answer));
			f_id_rec->Update();
		}
		
		m_record->raw_MoveNext();

		if (m_record->adoEOF)
		{
			AfxMessageBox(_T("答题结束，请交卷！"));
			m_record->Close();
		}

		else
		{
			showtest();
			m_testnum++;
			m_checked = -1;
			UpdateData(false);
		}
		

	}
	

}


void Examing::OnBnClickedprev()
{
	// TODO: 在此添加控件通知处理程序代码
	_variant_t sv_id, sv_ans;
	CString ss_id, f_sql, ss_ans;
	_RecordsetPtr f_record;
	_RecordsetPtr m;
	int qans_id;
	if (!m_record->adoEOF)
	{
		m_record->MovePrevious();
		m = m_record;   //分成两步
						//获取问题的id，在examinginfo 中查找该问题，并显示答案。
		sv_id = m->GetCollect("que_id");

		ss_id = (LPCSTR)_bstr_t(sv_id);

		qans_id = _ttoi(ss_id);
		f_sql.Format(_T("select answer from examinginfo where question_id=%d"), qans_id);
		//	sql.Format(_T("select * from stuinfo where sno=%d and name='%s'"), user_password, user_name);

		f_record = dbc.record(f_sql);

		sv_ans = f_record->GetCollect("answer");

		f_record->Close();

		ss_ans = (LPCSTR)_bstr_t(sv_ans);


		if (ss_ans == "A") m_checked = 0;
		else if (ss_ans == "B") m_checked = 2;
		else if (ss_ans == "C") m_checked = 1;
		else  m_checked = 3;



		showtest();
		m_testnum--;
		//	m_checked = -1;
		UpdateData(false);

	}
	else
	{
		m_record->Close();
		return;
	}
}


void Examing::OnBnClickedsub()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sql, sum_cs, cshow;
	_variant_t t, t_stuname, t_subname;
	_RecordsetPtr rec, rec_stuname, rec_stusco, rec_subname;
	int subnum;

	sql.Format(_T("select SUM(acscore) as [sc] from examinginfo where sno=%d"), m_id);
	rec = dbc.record(sql);
	t = rec->GetCollect("sc");

	sum_cs = (LPCSTR)_bstr_t(t);
	cshow.Format(_T("你的得分：%s"), sum_cs);

	AfxMessageBox(cshow);
	//m_id、m_type==0 数据库、t(_variant_t)
	sql.Format(_T("select * from stuinfo where sno=%d"), m_id);
	rec_stuname = dbc.record(sql);
	t_stuname = rec_stuname->GetCollect("name");

	if (m_type == 0) subnum = 3001;
	else subnum = 3000;
	sql.Format(_T("select * from subject where subject_id=%d"), subnum);
	rec_subname = dbc.record(sql);
	t_subname = rec_subname->GetCollect("subject_name");

	sql.Format(_T("select * from stuscore"));
	rec_stusco = dbc.record(sql);
	rec_stusco->AddNew();
	rec_stusco->PutCollect("stu_name", t_stuname);
	rec_stusco->PutCollect("sub_name", t_subname);
	rec_stusco->PutCollect("stu_score", _ttoi(sum_cs));
	rec_stusco->Update();


	//
	sql.Format(_T("delete from examinginfo"));
	dbc.executesql(sql);

	dbc.exitcon();
}


void Examing::OnBnClickedRadioA()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

}





void Examing::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
	static UINT m = 30;
	static UINT s = 0;

	CString str;
	switch (nIDEvent)
	{
	case 1:

		if (s == 0)
		{
			s = 60; m--;
		}
		s--;
		if (m == 0)
		{
			KillTimer(1);
			AfxMessageBox(_T("时间到，请交卷！"));
		}

		str.Format(_T("%02d：%02d"), m, s);
		m_timer.SetWindowTextW(str);
		//UpdateData(false);
		break;

	}

}
