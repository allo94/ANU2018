#pragma once


// Evaluate 대화 상자

class Evaluate : public CDialogEx
{
	DECLARE_DYNAMIC(Evaluate)

public:
	Evaluate(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Evaluate();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	virtual BOOL OnInitDialog();
};
