
// CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include<cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CString temp;
CString num1;
CString num2;

int op = 0;
double result;

bool input1;
bool input2;



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


// CCalculatorDlg 대화 상자



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_num1, &CCalculatorDlg::OnBnClickednum1)
	ON_BN_CLICKED(btn_num2, &CCalculatorDlg::OnBnClickednum2)
	ON_BN_CLICKED(btn_num3, &CCalculatorDlg::OnBnClickednum3)
	ON_BN_CLICKED(btn_num4, &CCalculatorDlg::OnBnClickednum4)
	ON_BN_CLICKED(btn_num5, &CCalculatorDlg::OnBnClickednum5)
	ON_BN_CLICKED(btn_num6, &CCalculatorDlg::OnBnClickednum6)
	ON_BN_CLICKED(btn_num7, &CCalculatorDlg::OnBnClickednum7)
	ON_BN_CLICKED(btn_num8, &CCalculatorDlg::OnBnClickednum8)
	ON_BN_CLICKED(btn_num9, &CCalculatorDlg::OnBnClickednum9)
	ON_BN_CLICKED(btn_num0, &CCalculatorDlg::OnBnClickednum0)
	ON_BN_CLICKED(btn_div, &CCalculatorDlg::OnBnClickeddiv)
	ON_BN_CLICKED(btn_mul, &CCalculatorDlg::OnBnClickedmul)
	ON_BN_CLICKED(btn_plus, &CCalculatorDlg::OnBnClickedplus)
	ON_BN_CLICKED(btn_min, &CCalculatorDlg::OnBnClickedmin)
	ON_BN_CLICKED(btn_eual, &CCalculatorDlg::OnBnClickedeual)
	ON_BN_CLICKED(btn_clear, &CCalculatorDlg::OnBnClickedclear)
	ON_BN_CLICKED(btn_rmd, &CCalculatorDlg::OnBnClickedrmd)
	ON_BN_CLICKED(btn_frc, &CCalculatorDlg::OnBnClickedfrc)
	ON_BN_CLICKED(btn_pow, &CCalculatorDlg::OnBnClickedpow)
	ON_BN_CLICKED(btn_abs, &CCalculatorDlg::OnBnClickedabs)
	ON_BN_CLICKED(btn_dot, &CCalculatorDlg::OnBnClickeddot)
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 해결방법
// 1.인자로 대화상자 넘김
// 2.함수를 추가
void CCalculatorDlg::EventClick(CString number) {
	CString c;
	if (op == 0)
	{
		input1 = true;
		num1 += number;
		c.Format(_T("%f"), num1);
	}
	else
	{
		input2 = true;
		num2 += number;
		c.Format(_T("%f"), num2);
	}
	SetDlgItemText(edt_input, c);
	temp = "";
	//*c
}
//eedit
void CCalculatorDlg::OnBnClickednum1()
{
	temp += "1";
	//temp.Format(_T("%f"), "1");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum2()
{
	temp.Format(_T("%f"), "2");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum3()
{
	temp.Format(_T("%f"), "3");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum4()
{
	temp.Format(_T("%f"), "4");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum5()
{
	temp.Format(_T("%f"), "5");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum6()
{
	temp.Format(_T("%f"), "6");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum7()
{
	temp.Format(_T("%f"), "7");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum8()
{
	temp.Format(_T("%f"), "8");
	EventClick(temp);
}


void CCalculatorDlg::OnBnClickednum9()
{
	temp.Format(_T("%f"), "9");
	EventClick(temp);
}

void CCalculatorDlg::OnBnClickednum0()
{
	temp.Format(_T("%f"), "0");
	EventClick(temp);
}


void Oper(int param)
{
	if (input1)
	{
		op = param;
	}
	else
	{
		AfxMessageBox(_T("숫자 입력 필요."));
	}
}


void CCalculatorDlg::OnBnClickedplus()
{
	Oper(1);
}

void CCalculatorDlg::OnBnClickedmin()
{
	Oper(2);
}
void CCalculatorDlg::OnBnClickedmul()
{
	Oper(3);
}
void CCalculatorDlg::OnBnClickeddiv()
{
	Oper(4);
}
void CCalculatorDlg::OnBnClickedrmd() //나머지
{
	Oper(5);
}

void CCalculatorDlg::OnBnClickedfrc() //역수
{
	Oper(5);
}
void CCalculatorDlg::OnBnClickedpow() //제곱
{
	Oper(6);
}


void CCalculatorDlg::OnBnClickedabs() //절대값
{
	Oper(7);
}

void CCalculatorDlg::OnBnClickeddot()
{
	
}

void CCalculatorDlg::OnBnClickedeual()
{
	if (op)
	{
		switch (op)
		{
		case 1:
			result = _wtof(num1) + _wtof(num2);
			break;
		case 2:
			result = _wtof(num1) - _wtof(num2);
			break;
		case 3:
			result = _wtof(num1) * _wtof(num2);
			break;
		case 4:
			result = _wtof(num1) / _wtof(num2);
			break;
		case 5:
			result = _wtof(num2) / _wtof(num1);
			break;
		case 6:
			result = pow(_wtof(num1) , _wtof(num2));
			break;
		case 7:
			result = abs(_wtof(num1));
			break;
		default:
			break;
		}
		CString sResult;
		//sResult.TrimRight(L"0");
		sResult.Format(_T("%f"), result);
		SetDlgItemText(edt_input, sResult);
		result = 0;
		num1 = sResult;
		num2 = "";
		input1 = false;
		input2 = false;
		op = 0;
	}
}

void CCalculatorDlg::OnBnClickedclear()
{
	SetDlgItemText(edt_input, NULL);
	result = 0;
	num1 = "";
	num2 = "";
	input1 = false;
	input2 = false;
	op = 0;
}