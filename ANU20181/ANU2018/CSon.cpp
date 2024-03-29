// CSon.cpp: 구현 파일
//

#include "stdafx.h"
#include "ANU2018.h"
#include "CSon.h"
#include "afxdialogex.h"


/* 클래스 뷰 - CSon - 재정의(오버라이드) - OnInitDialog */
BOOL CSon::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	cnt1 = cnt2 = cnt3 = cnt4 = cnt5 = cnt6 = cnt7 = cnt8 = cnt9 = 0;
	cnt = 0;
	msg = "입력된 숫자 : ";
	text1 = text2 = text3 = 0;
	SetWindowText(L"숫자 인식 프로그램");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


// CSon 대화 상자

IMPLEMENT_DYNAMIC(CSon, CDialogEx)

CSon::CSon(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CSon::~CSon()
{
}

void CSon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSon, CDialogEx)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CSon 메시지 처리기


void CSon::OnLButtonDown(UINT nFlags, CPoint point)
{
	p1 = point; // 마우스 왼쪽 버튼을 누를 때의 위치를 p1에 저장.
	cnt++; // 클릭 횟수(획 수)에 따라 글자를 판별하기 위해 만든 변수.
		   // 대부분의 숫자가 1획. 4, 5은 2획. 7은 예외적으로 사람에 따라 1이나 그 이상.

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSon::OnLButtonUp(UINT nFlags, CPoint point)
{
	p2 = point; // 마우스 왼쪽 버튼을 뗐을 때의 위치를 p2에 저장.

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CSon::OnMouseMove(UINT nFlags, CPoint point)
{
	dist1 = point.x; // 마우스 포인터의 x좌표
	dist2 = point.y; // 마우스 포인터의 y좌표

	if (nFlags == MK_LBUTTON) { // 마우스 왼쪽 버튼을 눌렀을 때.
		CPen pen(PS_SOLID, 12, RGB(0, 0, 0)); // 펜의 종류, 굵기, 색상 지정.
		CClientDC dc(this);
		dc.SelectObject(&pen);
		dc.MoveTo(pnt);
		dc.LineTo(point);

		if (dist1 <= 80) { // x 좌표가 0~80인 경우.
			if (dist2 <= 80) { // x 좌표는 0~80, y 좌표도 0~80. 필드1.
				cnt1 = cnt1 + 1; // cnt1 = 1;로 써도 무방.
			}
			else if (dist2 > 80 && dist2 <= 160) { // x 좌표는 0~80, y 좌표가 81~160인 경우. 필드4.
				cnt4 = cnt4 + 1;
			}
			else { // x 좌표는 0~80, y 좌표는 161 이상. 필드7.
				cnt7 = cnt7 + 1;
			}
		}

		else if (dist1 > 80 && dist1 <= 160) { // x 좌표가 81~160인 경우.
			if (dist2 <= 80) { // x 좌표는 81~160, y 좌표는 0~80. 필드2.
				cnt2 = cnt2 + 1;
			}
			else if (dist2 > 80 && dist2 <= 160) { // x 좌표는 81~160, y 좌표도 81~160. 필드5.
				cnt5 = cnt5 + 1;
			}
			else { // x 좌표는 81~160, y 좌표는 161이상. 필드8.
				cnt8 = cnt8 + 1;
			}
		}

		else { // x 좌표가 161 이상인 경우.
			if (dist2 <= 80) { // x 좌표는 161 이상, y 좌표는 0~80. 필드3.
				cnt3 = cnt3 + 1;
			}
			else if (dist2 > 80 && dist2 <= 160) { // x 좌표는 161 이상, y 좌표는 81~160. 필드6.
				cnt6 = cnt6 + 1;
			}
			else { // x 좌표는 161 이상, y 좌표도 161 이상. 필드9.
				cnt9 = cnt9 + 1;
			}
		}
	}
	pnt = point;

	CDialogEx::OnMouseMove(nFlags, point);
}

void CSon::OnRButtonDown(UINT nFlags, CPoint point)
{
	dist = abs(p1.x - p2.x) + abs(p1.y - p2.y); // 선의 시작 지점과 끝 지점 간의 거리 차이.
	if (dist < 40) { // 시작 지점과 끝 지점이 근접할 경우. 8, 0을 분별하기 위함.
		text1 = 1;
	}
	if (dist > 200) { // 시작 지점과 끝 지점이 먼 경우. 2와 3을 구분하기 위함.
		text2 = 1;
	}
	if (dist < 150) { // 7과 9를 구분해 주기 위함.
		text3 = 1;
	}

	/* 될 수 있는 대로 많은 케이스를 고려하여 조건 작성. 단, 정자체를 권고함. */

	if (cnt1 == 0 && cnt2 > 0 && cnt3 == 0 && cnt4 == 0 && cnt5 > 0 && cnt6 == 0 && cnt7 == 0 && cnt8 > 0 && cnt9 == 0 && cnt >= 1 && text1 >= 0) {
		msg = "입력된 숫자 : 1";
	}

	if (cnt1 > 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 == 0 && cnt5 > 0 && cnt6 >= 0 && cnt7 > 0 && cnt8 > 0 && cnt9 > 0 && cnt == 1 && text1 == 0 && text2 == 1) {
		msg = "입력된 숫자 : 2";
	}

	if (cnt1 > 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 == 0 && cnt5 > 0 && cnt6 > 0 && cnt7 > 0 && cnt8 > 0 && cnt9 > 0 && cnt == 1 && text1 == 0 && text2 == 0) {
		msg = "입력된 숫자 : 3";
	}

	if (cnt1 >= 0 && cnt2 > 0 && cnt3 == 0 && cnt4 > 0 && cnt5 > 0 && cnt6 > 0 && cnt7 == 0 && cnt8 > 0 && cnt9 == 0 && cnt == 2 && text1 == 0) {
		msg = "입력된 숫자 : 4";
	}

	if (cnt1 >= 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 >= 0 && cnt5 > 0 && cnt6 > 0 && cnt7 >= 0 && cnt8 > 0 && cnt9 > 0 && cnt == 2 && text1 == 0) {
		msg = "입력된 숫자 : 5";
	}

	if (cnt1 >= 0 && cnt2 > 0 && cnt3 == 0 && cnt4 > 0 && cnt5 > 0 && cnt6 >= 0 && cnt7 > 0 && cnt8 > 0 && cnt9 >= 0 && cnt == 1 && text1 == 0) {
		msg = "입력된 숫자 : 6";
	}

	if (cnt1 > 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 >= 0 && cnt5 > 0 && cnt6 == 0 && cnt7 == 0 && cnt8 > 0 && cnt9 == 0 && cnt >= 1 && text1 == 0 && text3 == 0) {
		msg = "입력된 숫자 : 7";
	}

	if (cnt1 >= 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 >= 0 && cnt5 > 10 && cnt6 >= 0 && cnt7 >= 0 && cnt8 > 0 && cnt9 >= 0 && cnt == 1 && text1 == 1) {
		msg = "입력된 숫자 : 8";
	}

	if (cnt1 >= 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 >= 0 && cnt5 > 0 && cnt6 >= 0 && cnt7 == 0 && cnt8 >= 0 && cnt9 >= 0 && cnt == 1 && text1 == 0 && text3 == 1) {
		msg = "입력된 숫자 : 9";
	}

	if (cnt1 >= 0 && cnt2 > 0 && cnt3 >= 0 && cnt4 >= 0 && cnt5 < 10 && cnt6 >= 0 && cnt7 >= 0 && cnt8 > 0 && cnt9 >= 0 && cnt == 1 && text1 == 1) {
		msg = "입력된 숫자 : 0";
	}

	MessageBox(msg); // 메시지 박스로 인식한 숫자를 출력함.

	CDialogEx::OnRButtonDown(nFlags, point);
}


/* 키보드의 c 버튼을 눌렀을 때 화면과 각 변수를 모두 초기화해 주는 기능. */
/* 클래스 뷰 - CSon - 재정의(오버라이드) - PreTranslateMessage */
BOOL CSon::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->wParam == 'c') {
		cnt1 = cnt2 = cnt3 = cnt4 = cnt5 = cnt6 = cnt7 = cnt8 = cnt9 = 0;
		cnt = 0;
		msg = "입력된 숫자 : ";
		text1 = text2 = text3 = 0;
		Invalidate(true);
		MessageBox(L"초기화하였습니다.");
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
