// WincodeDlg.h : header file
//

#if !defined(AFX_WINCODEDLG_H__BD2CAC4E_DFCF_4436_83BA_B65A550337FA__INCLUDED_)
#define AFX_WINCODEDLG_H__BD2CAC4E_DFCF_4436_83BA_B65A550337FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWincodeDlg dialog

class CWincodeDlg : public CDialog
{
// Construction
public:
	CWincodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWincodeDlg)
	enum { IDD = IDD_WINCODE_DIALOG };
	CProgressCtrl	m_Progress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWincodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWincodeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton5();
	afx_msg void OnButton4();
	//}}AFX_MSG
	afx_msg void OnInitProgress();
	DECLARE_MESSAGE_MAP()

private:
	CString strFilePath;
    DWORD myFileLen;
	CFileFind fFind;
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINCODEDLG_H__BD2CAC4E_DFCF_4436_83BA_B65A550337FA__INCLUDED_)
