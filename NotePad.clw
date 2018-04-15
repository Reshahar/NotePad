; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNotePadView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NotePad.h"
LastPage=0

ClassCount=5
Class1=CNotePadApp
Class2=CNotePadDoc
Class3=CNotePadView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CNotePadApp]
Type=0
HeaderFile=NotePad.h
ImplementationFile=NotePad.cpp
Filter=N

[CLS:CNotePadDoc]
Type=0
HeaderFile=NotePadDoc.h
ImplementationFile=NotePadDoc.cpp
Filter=N

[CLS:CNotePadView]
Type=0
HeaderFile=NotePadView.h
ImplementationFile=NotePadView.cpp
Filter=C
BaseClass=CEditView
VirtualFilter=VWC
LastObject=IDC_COUNT


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=NotePad.cpp
ImplementationFile=NotePad.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDOK,button,1342373889
Control3=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=IDC_FIND
Command7=IDC_REPLACE
Command8=IDC_SELALL
Command9=IDC_COUNT
Command10=ID_VIEW_STATUS_BAR
Command11=IDC_FONT
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDC_SELALL
Command2=ID_EDIT_COPY
Command3=IDC_FIND
Command4=ID_ACCEL32776
Command5=IDC_REPLACE
Command6=ID_FILE_NEW
Command7=ID_FILE_OPEN
Command8=ID_FILE_SAVE
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_EDIT_CUT
Command17=ID_EDIT_UNDO
CommandCount=17

