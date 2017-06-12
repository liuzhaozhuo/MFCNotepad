// 记事本Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "记事本.h"
#include "记事本Dlg.h"

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
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_strTime = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDC_EDIT, m_Edit);
	DDX_Text(pDX, IDC_STATIC_TIME, m_strTime);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_COPY, OnCopy)
	ON_COMMAND(ID_CUT, OnCut)
	ON_COMMAND(ID_PASTE, OnPaste)
	ON_COMMAND(ID_UNDO, OnUndo)
	ON_COMMAND(ID_SELECT_ALL, OnSelectAll)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	//清空EDIT的内容
	CEdit* pe = (CEdit*) this->GetDlgItem(IDC_EDIT);
	pe->SetWindowText("");
	
	//获取系统时间
	CTime time = CTime::GetCurrentTime();    
	m_strTime.Format(time.Format("%Y-%m-%d %H:%M:%S"));
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();

	
}

void CMyDlg::OnCopy() 
{
	// TODO: Add your command handler code here
	CEdit * pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
    pEdit->Copy();
	
}

void CMyDlg::OnCut() 
{
	// TODO: Add your command handler code here
	CEdit * pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
    pEdit->Cut();
}

void CMyDlg::OnPaste() 
{
	// TODO: Add your command handler code here
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit ->Paste();

}

void CMyDlg::OnUndo() 
{
	// TODO: Add your command handler code here
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit ->Undo();

}

void CMyDlg::OnSelectAll() 
{
	// TODO: Add your command handler code here
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
	pEdit ->SetSel(0,-1);

}

void CMyDlg::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CString filter;
	
	//定义m_strContent;
	CString m_strContent;

	filter = "文本文件(*.txt)|*.txt|C++文件(*.h,*.cpp)|*.h;*.cpp||";
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	if(dlg.DoModal()!=IDOK) return;
	CString strFileName=dlg.GetPathName();
	CFileStatus status;
	if(!CFile::GetStatus(strFileName,status))
	{
		MessageBox("该文件不存在！"); return;
	}


	m_strContent.Empty();
	CFile theFile;
	if(!theFile.Open(strFileName,CFile::modeRead))
	{
		MessageBox("该文件无法打开！"); return;
	}
	char szBuffer[80];
	UINT nActual=0;
	while(nActual=theFile.Read(szBuffer,sizeof(szBuffer)))
	{
		CString str(szBuffer,nActual);
		m_strContent=m_strContent+str;
	}
	theFile.Close();
	//设置IDC_EDIT的内容
	CEdit* e = (CEdit*) this->GetDlgItem(IDC_EDIT);
	e->SetWindowText(m_strContent);
	UpdateData(FALSE);
}

void CMyDlg::OnFileSave() 
{
	// TODO: Add your command handler code here
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
	"All Files(*.txt)|*.txt|",AfxGetMainWnd());//创建保存文件对话框
	CString file_path,file_text;
	if(IDOK==dlg.DoModal())
	{
		file_path=dlg.GetPathName();//获取文件路径和名称
		if(file_path.Right(4)!=".txt")//若文件名没有加后缀，则给文件名加上后缀
		{
			file_path+=".txt";
		}
		CFile file;
		if(!file.Open(file_path,CFile::modeCreate|CFile::modeWrite))
		{
			MessageBox("创建文件失败");
			return;
		}
		m_Edit.GetWindowTextA(file_text);//获取编辑框中的内容
		CArchive ar(&file,CArchive::store);
		ar<<file_text;//将编辑框内容保存到文件中
		MessageBox("文件保存成功！");
		m_Edit.SetWindowTextA("");//清空编辑框
		ar.Close();
		file.Close();
	}
}
