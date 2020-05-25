
#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

#include <iostream>

class FrameApi
{
protected:
	FrameApi() {}

public:
	virtual void Draw() = 0;

};

class LayoutApi
{
protected:
	LayoutApi() {}

public:
	virtual void InstallFrame() = 0;

};

class ComputerFrame : public FrameApi
{
public:
	ComputerFrame(int pins):m_pins(pins) {}

	void Draw()
	{
		std::cout << "this is pc frame : " << m_pins << std::endl;
	}

private:
	int m_pins;
};

class MobileFrame : public FrameApi
{
public:
	MobileFrame(int pins):m_pins(pins) {}

	void Draw()
	{
		std::cout << "this is mobile frame : " << m_pins << std::endl;
	}

private:
	int m_pins;
};

class HighLayout: public LayoutApi
{
public:
	HighLayout(int FrameAdpaterPins):m_FrameAdpaterPins(FrameAdpaterPins) {}

	void InstallFrame()
	{
		std::cout << "this is pc's high layout frame : " << m_FrameAdpaterPins << std::endl;
	}

private:
	int m_FrameAdpaterPins;
};

class LowLayout : public LayoutApi
{
public:
	LowLayout(int FrameAdpaterPins):m_FrameAdpaterPins(FrameAdpaterPins) {}

	void InstallFrame()
	{
		std::cout << "this is mobile's low layout frame : " << m_FrameAdpaterPins << std::endl;
	}

private:
	int m_FrameAdpaterPins;
};

#if 0

//创建产品的简单工厂
class FrameFactory
{
public:
	FrameFactory() {}
	static FrameApi* CreateFreame(int type)
	{
		if (type == 1)
		{
			return new ComputerFrame(1024);
		}
		if (type == 2)
		{
			return new MobileFrame(800);
		}
		return nullptr;
	}

};

class LayoutFactory
{
public:
	LayoutFactory() {}
	static LayoutApi* CreateFreame(int type)
	{
		if (type == 1)
		{
			return new HighLayout(1024);
		}
		if (type == 2)
		{
			return new LowLayout(800);
		}
		return nullptr;
	}

};

class GUIEngineer
{
public:
	GUIEngineer(){}
	/* 
	 * FrameType:是用来标识选择Frame控件的类型
	 * LayoutType:使用来标识选择布局管理器的类型
	 */
	void PrepareDraw(int frameType, int layoutType)
	{
		this->pFrame = FrameFactory::CreateFreame(frameType);
		this->pLayout = LayoutFactory::CreateFreame(layoutType);
		pFrame->Draw();
		pLayout->InstallFrame();
	}
private:
	FrameApi* pFrame;
	LayoutApi* pLayout;
};

#endif // 0

//抽象工厂用来定义产品簇
class AbstractFactory
{
protected:
	AbstractFactory() {}

public:
	virtual FrameApi* CreateFrameApi() = 0;
	virtual LayoutApi* CreateLayoutApi() = 0;

};

class Schemal1 : public AbstractFactory
{
public:
	FrameApi* CreateFrameApi()
	{
		return new ComputerFrame(1024);
	}
	LayoutApi* CreateLayoutApi()
	{
		return new HighLayout(1024);
	}

};

class Schemal2 : public AbstractFactory
{
public:
	FrameApi* CreateFrameApi()
	{
		return new MobileFrame(800);
	}
	LayoutApi* CreateLayoutApi()
	{
		return new LowLayout(800);
	}

};

class AdvanceGuiEngineer
{
public:
	void PrepareMaterials(AbstractFactory* pSchema)
	{
		this->pFrame = pSchema->CreateFrameApi();
		this->pLayout = pSchema->CreateLayoutApi();
		pFrame->Draw();
		pLayout->InstallFrame();
	}
private:
	FrameApi* pFrame;
	LayoutApi* pLayout;
};

void AbstractFactoryModeTest()
{
	/* GUIEngineer* pEng = new GUIEngineer(); 
	pEng->PrepareDraw(2, 2);*/
	AdvanceGuiEngineer* pEng = new AdvanceGuiEngineer();
	pEng->PrepareMaterials(new Schemal2);
}


#endif // !__ABSTRACT_FACTORY_H__

