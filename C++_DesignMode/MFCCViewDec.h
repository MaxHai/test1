
#pragma once

#include <iostream>
#include <Windows.h>

class CView
{
public:
	virtual void Draw() = 0;

};

class CDecorate : public CView
{
public:
	CDecorate(CView* pView):m_pView(pView){}

public:
	virtual void Draw()
	{
		m_pView->Draw();
	}

private:
	CView* m_pView;
};

class CScrollBars : public CDecorate
{
public:
	CScrollBars(CView* pView):CDecorate(pView){}

protected:
	void DrawScrollBars()
	{
		std::cout << "DrawScrollBars" << std::endl;
	}

public:
	virtual void Draw()
	{
		CDecorate::Draw();
		DrawScrollBars();
	}

};


class CBorder : public CDecorate
{
public:
	CBorder(CView* pView) :CDecorate(pView) {}

protected:
	void DrawBorder()
	{
		std::cout << "DrawScrollBars" << std::endl;
	}

public:
	virtual void Draw()
	{
		CDecorate::Draw();
		DrawBorder();
	}

};

class CTextView : public CView
{
public:
	CTextView(const char* s)
	{
		SetWindowText(s);
	}

public:
	void SetWindowText(const char* s)
	{
		strcpy_s(m_Text, _countof(m_Text), s);
	}

	char* GetWindowText()
	{
		return m_Text;
	}

	virtual void Draw()
	{
		//CView::Draw();
		DrawTextView();
	}
	
protected:
	virtual void DrawTextView()
	{
		std::cout << "DrawTextView: " << m_Text << std::endl;
	}

protected:
	char m_Text[MAX_PATH];

};

class CWindows
{
public:
	CWindows()
	{
		ZeroMemory(m_arrWindow, sizeof(CView) * 10);
	}

public:
	void Draw()
	{
		for (int i = 0; i < 10; i++)
		{
			if (m_arrWindow[i] != NULL)
			{
				m_arrWindow[i]->Draw();
			}
		}
	}

	void AddControl(CView* pView)
	{
		for (int i = 0; i < 10; i++)
		{
			if (m_arrWindow[i] != NULL)
			{
				m_arrWindow[i] = pView;
				break;
			}
		}
	}
	
	void RemoveControl(CView* pView)
	{
		for (int i = 0; i < 10; i++)
		{
			if (m_arrWindow[i] == pView)
			{
				m_arrWindow[i] = NULL;
				break;
			}
		}
	}

protected:
	CView* m_arrWindow[10];

};

void MFCCViewDecModeTest()
{

	CWindows windowsObj;
	CTextView TextView("TextView");

	windowsObj.AddControl(&TextView);
	windowsObj.Draw();

	windowsObj.RemoveControl(&TextView);
	CScrollBars* pScroll = new CScrollBars(&TextView);
	windowsObj.AddControl(pScroll);
	windowsObj.Draw();
}