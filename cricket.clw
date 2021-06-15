; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=cNewDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "cricket.h"
LastPage=0

ClassCount=6
Class1=CCricketApp
Class2=CCricketDoc
Class3=CCricketView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=cNewDlg
Resource3=IDD_NEWDLG

[CLS:CCricketApp]
Type=0
HeaderFile=cricket.h
ImplementationFile=cricket.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CCricketDoc]
Type=0
HeaderFile=cricketDoc.h
ImplementationFile=cricketDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CCricketView]
Type=0
HeaderFile=cricketView.h
ImplementationFile=cricketView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CCricketView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CAboutDlg]
Type=0
HeaderFile=cricket.cpp
ImplementationFile=cricket.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_APP_ABOUT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_APP_ABOUT
CommandCount=4

[CLS:cNewDlg]
Type=0
HeaderFile=cNewDlg.h
ImplementationFile=cNewDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=cNewDlg

[DLG:IDD_NEWDLG]
Type=1
Class=cNewDlg
ControlCount=6
Control1=IDC_PLAYER1,edit,1350631552
Control2=IDC_PLAYER2,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308866
Control6=IDC_STATIC,static,1342308866

