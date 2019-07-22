; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CHelpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Wincode.h"

ClassCount=4
Class1=CWincodeApp
Class2=CWincodeDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_WINCODE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CHelpDlg
Resource4=IDD_HELP

[CLS:CWincodeApp]
Type=0
HeaderFile=Wincode.h
ImplementationFile=Wincode.cpp
Filter=N

[CLS:CWincodeDlg]
Type=0
HeaderFile=WincodeDlg.h
ImplementationFile=WincodeDlg.cpp
Filter=D
LastObject=CWincodeDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=WincodeDlg.h
ImplementationFile=WincodeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342406657
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_WINCODE_DIALOG]
Type=1
Class=CWincodeDlg
ControlCount=9
Control1=IDC_BUTTON1,button,1342275584
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PROGRESS1,msctls_progress32,1073741825
Control5=IDC_BUTTON2,button,1342275584
Control6=IDC_BUTTON3,button,1342275584
Control7=IDC_STATIC1,static,1342308865
Control8=IDC_BUTTON4,button,1342275584
Control9=IDC_BUTTON5,button,1342275584

[DLG:IDD_HELP]
Type=1
Class=CHelpDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CHelpDlg]
Type=0
HeaderFile=HelpDlg.h
ImplementationFile=HelpDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CHelpDlg

