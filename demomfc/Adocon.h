#pragma once
//#include "stdafx.h"
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "adoEOF") 
class Adocon
{
public:
	Adocon();
	~Adocon();
public:
	void initadocon();
	void exitcon();
	_RecordsetPtr record(CString);
	_ConnectionPtr  m_connection;
	_RecordsetPtr m_record;
	void executesql(CString);
};

