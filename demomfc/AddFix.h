#pragma once


// AddFix 对话框

class AddFix : public CDialogEx
{
	DECLARE_DYNAMIC(AddFix)

public:
	AddFix(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AddFix();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddFix };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString t;
	CString num;
	int subid;
	int qnum;
	CString question;
	CString ans;
	int sc;
	CString a;
	CString b;
	CString c;
	CString d;
};
