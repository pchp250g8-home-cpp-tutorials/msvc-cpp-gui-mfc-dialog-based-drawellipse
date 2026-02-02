
// DrawEllipseDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "DrawEllipse.h"
#include "DrawEllipseDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CDrawEllipseDlg



CDrawEllipseDlg::CDrawEllipseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAWELLIPSE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDrawEllipseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDrawEllipseDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// Обработчики сообщений CDrawEllipseDlg

BOOL CDrawEllipseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CDrawEllipseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rcPaint;
		CPaintDC g(this);
		CPen oRedPen(0, 5, RGB(255, 0, 0)), * oDefaultPen;
		CBrush oYelowBrush(RGB(255, 255, 0)), * oDefaultBrush;
		GetClientRect(&rcPaint);
		g.FillRect(&rcPaint, &CBrush(RGB(0, 0, 0)));
		oDefaultPen = g.SelectObject(&oRedPen);
		oDefaultBrush = g.SelectObject(&oYelowBrush);
		g.Ellipse(&rcPaint);
		g.SelectObject(oDefaultPen);
		g.SelectObject(oDefaultBrush);
		oRedPen.DeleteObject();
		oDefaultPen->DeleteObject();
		oYelowBrush.DeleteObject();
		oDefaultBrush->DeleteObject();
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CDrawEllipseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDrawEllipseDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	Invalidate();
	// TODO: добавьте свой код обработчика сообщений
}
