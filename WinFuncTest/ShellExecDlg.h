#pragma once


// CShellExecDlg 对话框

class CShellExecDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShellExecDlg)

public:
	CShellExecDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShellExecDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHELLEXEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	CStringW m_strFileName;
	CStringW m_strVerb;
	CStringW m_strParam;
	CStringW m_strDir;

	int m_nReturnCode;
	int m_nErrorCode;


	BOOL m_bFile;
	BOOL m_bParam;
	BOOL m_bVerb;
	BOOL m_bDir;

	afx_msg void OnBnClickedButtonShellexew();
	int m_nShow;
};
