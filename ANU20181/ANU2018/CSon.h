#pragma once


// CSon 대화 상자

class CSon : public CDialogEx
{
	DECLARE_DYNAMIC(CSon)

public:
	CSon(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSon();
	CPoint p1, p2, pnt; // p1, p2는 시작과 끝 지점을 담기 위한 포인터.
	int dist, text1, text2; // dist는 시작 지점과 끝 지점의 거리를 계산하기 위한 변수.
							// text1 : 시작/끝이 매우 근접한 숫자 판별, text2 : 시작/끝이 매우 먼 숫자 판별.
	int text3; // 7과 9를 구분하기 위한 거리 판별.
	int dist1, dist2;	// 각각 x, y 좌표가 통과한 지점(필드)을 판별하는 데 쓰이는 변수.
	int cnt1, cnt2, cnt3, cnt4, cnt5, cnt6, cnt7, cnt8, cnt9; // 각 필드(1~9)를 통과함을 카운트하는 변수.
	int cnt; // 클릭 회수(총 획의 수)를 판별하기 위한 변수.
	CString msg; // 숫자 인식 결과를 담은 메시지.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
