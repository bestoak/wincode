// WincodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Wincode.h"
#include "WincodeDlg.h"

#include "HelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWincodeDlg dialog

CWincodeDlg::CWincodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWincodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWincodeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWincodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWincodeDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWincodeDlg, CDialog)
	//{{AFX_MSG_MAP(CWincodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CWincodeDlg::OnNMCustomdrawProgress1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWincodeDlg message handlers

BOOL CWincodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWincodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWincodeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
        UpdateData(IDC_PROGRESS1);
		UpdateWindow();
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWincodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWincodeDlg::OnButton1() 
{
        CFileDialog Filedlg(TRUE,               
		NULL,
		NULL,
        OFN_HIDEREADONLY   |OFN_OVERWRITEPROMPT   |OFN_EXPLORER,                       
		"All Files (*.*)|*.*||",
        NULL);                       
                
        if(Filedlg.DoModal()==IDOK)               
        {               
			strFilePath=Filedlg.GetPathName();         
			::SetWindowText(*GetDlgItem(IDC_EDIT1),strFilePath);
			::SetWindowText(*GetDlgItem(IDC_STATIC1),"ready.");
			OnInitProgress();
        }                   

	
}


void CWincodeDlg::OnButton2() 
{

    if(!fFind.FindFile(strFilePath,0))
    {
        AfxMessageBox("Choose an existing file.",0,0);
    }
	else
	{
		CFile myFile(strFilePath,CFile::modeRead);
		myFileLen = myFile.GetLength();
		BYTE* fileBuffer = new BYTE[myFileLen+1];
		myFile.Read(fileBuffer,myFileLen);
		myFile.Close();
		if(fileBuffer[myFileLen-1]=='|')
		{
			MessageBox("already encrypted.");
		}
		else
		{
			m_Progress.SetPos(0);
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
			m_Progress.ShowWindow(SW_SHOW);
			
			for(unsigned int i=0;i<myFileLen;i++)
			{
				fileBuffer[i] = fileBuffer[i]+3;
				if(myFileLen<65536)
				{
					m_Progress.SetPos(i);
				}
				else
				{
					m_Progress.SetPos(i/1024);
				}
				UpdateData(IDC_PROGRESS1);
			}
			fileBuffer[myFileLen]='|';
			CFile deFile(strFilePath,CFile::modeWrite);
			deFile.Write(fileBuffer,myFileLen+1);
			deFile.Close();
			::SetWindowText(*GetDlgItem(IDC_STATIC1),"successfully encrypted.");
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
			m_Progress.ShowWindow(SW_HIDE);
		}
	}
}

void CWincodeDlg::OnButton3() 
{
    
    if(!fFind.FindFile(strFilePath,0))
    {
        AfxMessageBox("Choose an existing file.",0,0);
    }
	else
	{
		CFile myFile(strFilePath,CFile::modeReadWrite);
		myFileLen = myFile.GetLength();
		BYTE* fileBuffer = new BYTE[myFileLen];
		myFile.Read(fileBuffer,myFileLen);
		myFile.Close();
		if(fileBuffer[myFileLen-1]=='|')
		{
			m_Progress.SetPos(0);
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
			m_Progress.ShowWindow(SW_SHOW);
			
			for(unsigned int i=0;i<myFileLen;i++)
			{
				fileBuffer[i] = fileBuffer[i]-3;
				if(myFileLen<65536)
				{
					m_Progress.SetPos(i);
				}
				else
				{
					m_Progress.SetPos(i/1024);
				}
				UpdateData(IDC_PROGRESS1);
			}
			CFile deFile(strFilePath,CFile::modeCreate | CFile::modeWrite);			
			deFile.Write(fileBuffer,myFileLen-1);
			deFile.Close();
			::SetWindowText(*GetDlgItem(IDC_STATIC1),"successfully decrypted.");
			GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
			m_Progress.ShowWindow(SW_HIDE);
		}
		else
		{
			MessageBox("already decrypted.");
		}
	}
}
void CWincodeDlg::OnInitProgress()
{

    if(!fFind.FindFile(strFilePath,0))
    {
        AfxMessageBox("file not found.",0,0);
    }
	else
	{
		
		CFile myFile(strFilePath,CFile::modeRead);
		myFileLen = myFile.GetLength();
		myFile.Close();
		if(myFileLen<65536)
		{
			m_Progress.SetRange32(0,myFileLen);
			m_Progress.SetPos(0);
		}
		else
		{
			m_Progress.SetRange32(0,myFileLen/1024);
			m_Progress.SetPos(0);
		}
	}
	
}

void CWincodeDlg::OnButton5() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CWincodeDlg::OnButton4() 
{
	CHelpDlg dlg;
	dlg.DoModal();
	
}


void CWincodeDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;
}
