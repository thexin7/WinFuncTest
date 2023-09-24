// ShellExecDlg.cpp: 实现文件
//

#include "pch.h"
#include "WinFuncTest.h"
#include "ShellExecDlg.h"
#include "afxdialogex.h"
#include <shellapi.h>

// CShellExecDlg 对话框

IMPLEMENT_DYNAMIC(CShellExecDlg, CDialogEx)

CShellExecDlg::CShellExecDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SHELLEXEC, pParent)
	, m_strFileName(_T(""))
	, m_strVerb(_T(""))
	, m_nReturnCode(0)
	, m_nErrorCode(0)
	, m_bFile(FALSE)
	, m_bParam(FALSE)
	, m_bVerb(FALSE)
	, m_bDir(FALSE)
	, m_nShow(0)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CShellExecDlg::~CShellExecDlg()
{
}

void CShellExecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE, m_strFileName);
	DDX_Text(pDX, IDC_EDIT_VERB, m_strVerb);
	DDX_Text(pDX, IDC_EDIT_PARAMES, m_strParam);
	DDX_Text(pDX, IDC_EDIT_DIR, m_strDir);
	DDX_Text(pDX, IDC_EDIT_RETCODE, m_nReturnCode);
	DDX_Text(pDX, IDC_EDIT_ERRCODE, m_nErrorCode);
	DDX_Check(pDX, IDC_CHECK_FILE, m_bFile);
	DDX_Check(pDX, IDC_CHECK_PARAM, m_bParam);
	DDX_Check(pDX, IDC_CHECK_VERB, m_bVerb);
	DDX_Check(pDX, IDC_CHECK_DIR, m_bDir);
	DDX_Text(pDX, IDC_EDIT_SHOW, m_nShow);
}


BEGIN_MESSAGE_MAP(CShellExecDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SHELLEXEW, &CShellExecDlg::OnBnClickedButtonShellexew)
END_MESSAGE_MAP()


// CShellExecDlg 消息处理程序
void CShellExecDlg::OnBnClickedButtonShellexew()
{
	UpdateData(TRUE);
	SHELLEXECUTEINFOW info = {0};
	info.cbSize = sizeof(SHELLEXECUTEINFO);
	if (!m_bFile)
	{
		info.lpFile = m_strFileName;
	}
	if (!m_bParam)
	{
		info.lpParameters = m_strParam;
	}
	if (!m_bVerb)
	{

		info.lpVerb = m_strVerb;
	}
	if (!m_bDir)
	{
		info.lpDirectory = m_strDir;
	}
	info.nShow = m_nShow;

	m_nReturnCode = ShellExecuteExW(&info);
	m_nErrorCode = GetLastError();

	UpdateData(FALSE);
}
