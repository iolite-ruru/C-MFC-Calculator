
// CalculatorDlg.h: 헤더 파일
//

#pragma once


// CCalculatorDlg 대화 상자
class CCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	void EventClick(CString number);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickednum1();
	afx_msg void OnBnClickednum2();
	afx_msg void OnBnClickednum3();
	afx_msg void OnBnClickednum4();
	afx_msg void OnBnClickednum5();
	afx_msg void OnBnClickednum6();
	afx_msg void OnBnClickednum7();
	afx_msg void OnBnClickednum8();
	afx_msg void OnBnClickednum9();
	afx_msg void OnBnClickednum0();
	afx_msg void OnBnClickeddiv();
	afx_msg void OnBnClickedmul();
	afx_msg void OnBnClickedplus();
	afx_msg void OnBnClickedmin();
	afx_msg void OnBnClickedeual();
	afx_msg void OnBnClickedclear();
	afx_msg void OnBnClickedrmd();
	afx_msg void OnBnClickedfrc();
	afx_msg void OnBnClickedpow();
	afx_msg void OnBnClickedabs();
	afx_msg void OnBnClickeddot();
};
