#pragma once


// Examing 对话框

class Examing : public CDialogEx
{
	DECLARE_DYNAMIC(Examing)

public:
	Examing(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Examing();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_examing };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	void showtest();
	DECLARE_MESSAGE_MAP()
public:
	int m_id;
	int m_type;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnEnChangeEdit9();
	CString m_question;
	CString m_ansa;
	CString m_ansb;
	CString m_ansc;
	CString m_ansd;
	int m_testnum;
	//CEdit m_t;
	afx_msg void OnBnClickednext();
	afx_msg void OnBnClickedprev();
	afx_msg void OnBnClickedsub();
	int m_checked;
	afx_msg void OnBnClickedRadioA();
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_timer;
};
