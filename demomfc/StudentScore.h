#pragma once


// StudentScore 对话框

class StudentScore : public CDialogEx
{
	DECLARE_DYNAMIC(StudentScore)

public:
	StudentScore(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StudentScore();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_StuScore };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	void refresh(int);
	virtual BOOL OnInitDialog();
	int sc;
};
