#pragma once


// Admin 对话框

class Admin : public CDialogEx
{
	DECLARE_DYNAMIC(Admin)

public:
	Admin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Admin();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Admin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	BOOL OnInitDialog();
	afx_msg void OnTcnSelchangingTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
