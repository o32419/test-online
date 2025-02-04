#pragma once


// SiAdd 对话框

class SiAdd : public CDialogEx
{
	DECLARE_DYNAMIC(SiAdd)

public:
	SiAdd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SiAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DAdd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int s_sno;
	CString s_name;
	CString s_dep;
	CString type;
	CString stno;
	afx_msg void OnBnClickedButton1();
};
