// Evaluate.cpp: 구현 파일
//

#include "stdafx.h"
#include "ANU2018.h"
#include "Evaluate.h"
#include "afxdialogex.h"


// Evaluate 대화 상자

IMPLEMENT_DYNAMIC(Evaluate, CDialogEx)

Evaluate::Evaluate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Evaluate::~Evaluate()
{
}

void Evaluate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Evaluate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &Evaluate::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Evaluate::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Evaluate::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &Evaluate::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Evaluate::OnBnClickedButton8)
END_MESSAGE_MAP()


BOOL Evaluate::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowText(L"프로그램 평가");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



// Evaluate 메시지 처리기


void Evaluate::OnBnClickedButton3()
{
	MessageBox(L"감사합니다!");
}


void Evaluate::OnBnClickedButton4()
{
	MessageBox(L"대단히 감사합니다!");
}


void Evaluate::OnBnClickedButton5()
{
	MessageBox(L"조금 더 노력하겠습니다.");
}


void Evaluate::OnBnClickedButton7()
{
	MessageBox(L"반드시 개선하도록 노력하겠습니다.");
}


void Evaluate::OnBnClickedButton8()
{
	MessageBox(L"이용 불편 사항과 문제점을 제보해 주세요.\nferrero94@naver.com");
}