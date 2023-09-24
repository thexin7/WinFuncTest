// CFileTestDlg.cpp: 实现文件
//

#include "pch.h"
#include "WinFuncTest.h"
#include "FileTestDlg.h"
#include "afxdialogex.h"


// CFileTestDlg 对话框

IMPLEMENT_DYNAMIC(CFileTestDlg, CDialogEx)

CFileTestDlg::CFileTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FILE, pParent),
	m_hFile(INVALID_HANDLE_VALUE)
	, m_nErrorCode(0)
	, m_nReturnCode(0)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CFileTestDlg::~CFileTestDlg()
{
}

void CFileTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_strFileName);
	DDX_Text(pDX, IDC_EDIT_ERRCODE, m_nErrorCode);
	DDX_Text(pDX, IDC_EDIT_RETCODE, m_nReturnCode);
}


BEGIN_MESSAGE_MAP(CFileTestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_GETFILETYPE, &CFileTestDlg::OnBnClickedButtonGetfiletype)
	ON_BN_CLICKED(IDC_BUTTON_CFW, &CFileTestDlg::OnBnClickedButtonCfw)
END_MESSAGE_MAP()


// CFileTestDlg 消息处理程序


void CFileTestDlg::OnBnClickedButtonCfw()
{
	UpdateData(TRUE);
	if (m_hFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}
	m_hFile = CreateFileW(m_strFileName, //文件名
		FILE_READ_ATTRIBUTES, // 读写权限
		FILE_SHARE_WRITE | FILE_SHARE_READ | FILE_SHARE_DELETE,           // 共享权限
		NULL,        //
		OPEN_EXISTING,  // 打开方式
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_BACKUP_SEMANTICS,
		NULL
	);
	m_nReturnCode = int(m_hFile);
	m_nErrorCode = GetLastError();
	
	UpdateData(FALSE);
}


void CFileTestDlg::OnBnClickedButtonGetfiletype()
{
	UpdateData(TRUE);
	DWORD dwFileType = 0;
	if(m_hFile != INVALID_HANDLE_VALUE)
		dwFileType = GetFileType(m_hFile);

	m_nReturnCode = dwFileType;
	m_nErrorCode = GetLastError();
	UpdateData(FALSE);
}