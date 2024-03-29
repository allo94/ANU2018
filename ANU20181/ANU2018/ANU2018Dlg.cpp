
// ANU2018Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ANU2018.h"
#include "ANU2018Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CANU2018Dlg 대화 상자



CANU2018Dlg::CANU2018Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ANU2018_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CANU2018Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CANU2018Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CANU2018Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CANU2018Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CANU2018Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CANU2018Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CANU2018Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CANU2018Dlg 메시지 처리기

BOOL CANU2018Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetWindowText(L"펜 기반의 숫자 인식 프로그램");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CANU2018Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CANU2018Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CANU2018Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/* 도움말 출력 */
void CANU2018Dlg::OnBnClickedButton1()
{
	MessageBox(L"0~9까지의 숫자를 펜으로 그리고 인식하는 프로그램입니다.\n\n마우스 왼쪽 버튼 : 그리기\n마우스 오른쪽 버튼 : 인식하기\n키보드 c 버튼 : 초기화\n\n=========================\n작게 그리면 제대로 인식되지 않습니다.\n화면 크기에 맞게 그려 주세요.\n=========================\n\n[숫자 인식 실행] 버튼을 눌러 시작합니다.");
}

/* 자식 다이얼로그 불러오기 */
#include "CSon.h"
void CANU2018Dlg::OnBnClickedButton2()
{
	CSon *pDlg = new CSon(this);
	pDlg->Create(IDD_DIALOG1);
	pDlg->ShowWindow(SW_SHOW);
}

/* 프로그램 평가하기 다이얼로그 불러오기 */
#include "Evaluate.h"
void CANU2018Dlg::OnBnClickedButton3()
{
	Evaluate *pDlg = new Evaluate(this);
	pDlg->Create(IDD_DIALOG2);
	pDlg->ShowWindow(SW_SHOW);
}


void CANU2018Dlg::OnBnClickedButton4()
{
	MessageBox(L"안동대 컴퓨터공학과\n\n[3학년] 손상길\n[3학년] 이승현\n[3학년] 이현영\n[3학년] 최은호");
}


void CANU2018Dlg::OnBnClickedButton5()
{
	MessageBox(L"신한\n110-394-...");
}
