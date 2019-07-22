// Wincode.h : main header file for the WINCODE application
//

#if !defined(AFX_WINCODE_H__46748353_CBCB_4DF6_A3F4_FDC4FA46222E__INCLUDED_)
#define AFX_WINCODE_H__46748353_CBCB_4DF6_A3F4_FDC4FA46222E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWincodeApp:
// See Wincode.cpp for the implementation of this class
//

class CWincodeApp : public CWinApp
{
public:
	CWincodeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWincodeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWincodeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINCODE_H__46748353_CBCB_4DF6_A3F4_FDC4FA46222E__INCLUDED_)
