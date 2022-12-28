#if !defined(AFX_HOVERBUTTON_H__16C6D980_BD45_11D3_BDA3_00104B133581__INCLUDED_)
#define AFX_HOVERBUTTON_H__16C6D980_BD45_11D3_BDA3_00104B133581__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HoverButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHoverButton by Niek Albers
// Thanks to some people for the tooltip.
// A cool CBitmapButton derived class with 3 states,
// Up/Down/Hover.
class CHoverButton : public CBitmapButton
{
	DECLARE_DYNAMIC(CHoverButton);

	// Construction
public:
	CHoverButton();
	void SetToolTipText(CString* spText, BOOL bActivate = TRUE);
	void SetToolTipText(int nId, BOOL bActivate = TRUE);
	BOOL IsChecked() const { return m_bChecked; }
	void SetChecked(BOOL bChecked) { m_bChecked = bChecked; }
	void SetCheckBtn(BOOL bCheckBtn) { m_bCheckBtn = bCheckBtn; }

// Attributes
protected:
	void ActivateTooltip(BOOL bActivate = TRUE);
	BOOL m_bHover;						// indicates if mouse is over the button
	CSize m_ButtonSize;					// width and height of the button
	CBitmap mybitmap;
	BOOL m_bTracking;
	BOOL m_bChecked;
	BOOL m_bCheckBtn;
	BOOL m_bDisableImg;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHoverButton)
	protected:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL LoadBitmap(UINT bitmapid, BOOL bDisableImg = FALSE );
	virtual ~CHoverButton();

	// Generated message map functions
protected:
	CToolTipCtrl m_ToolTip;
	void InitToolTip();
	//{{AFX_MSG(CHoverButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnMouseHover(WPARAM wparam, LPARAM lparam) ;
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOVERBUTTON_H__16C6D980_BD45_11D3_BDA3_00104B133581__INCLUDED_)
