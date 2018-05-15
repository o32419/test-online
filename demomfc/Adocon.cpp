#include "stdafx.h"
#include "Adocon.h"


Adocon::Adocon()
{
}


Adocon::~Adocon()
{
}

void Adocon::initadocon()
{
	try
	{

		m_connection.CreateInstance(__uuidof(Connection));
		m_connection->Open("Provider=Microsoft.ACE.OLEDB.12.0; Data Source=student.accdb", "", "", adModeUnknown);

	}
	catch (_com_error e)
	{
		AfxMessageBox(_T("数据库连接失败"));
		return;
	}

}

void Adocon::exitcon()
{
	m_record->Close();
	m_record = NULL;
	m_connection->Close();
	m_connection = NULL;

}

void Adocon::executesql(CString sql)  //写数据库
{
	_variant_t RecordsAffected;
	try
	{
		m_connection->Execute((_bstr_t)sql, &RecordsAffected, adCmdText);

	}
	catch (_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

_RecordsetPtr Adocon::record(CString sql)   //读数据库
{
	m_record.CreateInstance(__uuidof(Recordset));
	try
	{
		m_record->Open((_bstr_t)sql, m_connection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);


	}
	catch (_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return m_record;
}
