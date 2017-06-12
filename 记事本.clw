; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "记事本.h"

ClassCount=3
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MY_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CMyApp]
Type=0
HeaderFile=记事本.h
ImplementationFile=记事本.cpp
Filter=N
LastObject=CMyApp

[CLS:CMyDlg]
Type=0
HeaderFile=记事本Dlg.h
ImplementationFile=记事本Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT2

[CLS:CAboutDlg]
Type=0
HeaderFile=记事本Dlg.h
ImplementationFile=记事本Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=7
Control1=IDC_EDIT,edit,1344340100
Control2=IDC_EDIT3,edit,1350631552
Control3=IDC_EDIT4,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC_TIME,static,1342312961

[MNU:IDR_MENU1]
Type=1
Class=CMyDlg
Command1=ID_FILE_OPEN
Command2=ID_FILE_SAVE
Command3=ID_SELECT_ALL
Command4=ID_COPY
Command5=ID_CUT
Command6=ID_PASTE
Command7=ID_UNDO
Command8=ID_FRONT
Command9=ID_COLOR
Command10=ID_ABOUT
CommandCount=10

