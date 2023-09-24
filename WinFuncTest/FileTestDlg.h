#pragma once


// CFileTestDlg 对话框

class CFileTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFileTestDlg)

public:
	CFileTestDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFileTestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FILE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonGetfiletype();
	afx_msg void OnBnClickedButtonCfw();
	CStringW m_strFileName;
	HANDLE m_hFile;
	int m_nErrorCode;
	int m_nReturnCode;
};
