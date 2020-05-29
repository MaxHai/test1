
#pragma once

#include <iostream>
#include <string>

/* 访问者模式：核心叫做双重分发，两个多态：Accept，Visit*/

class XiaoMi;
class Huawei;
class Oppo;

class CellPhoneVisitor
{
protected:
	CellPhoneVisitor();
	~CellPhoneVisitor();

public:
	virtual void Visit(XiaoMi* p) = 0;
	virtual void Visit(Huawei* p) = 0;
	virtual void Visit(Oppo* p) = 0;

private:

};

CellPhoneVisitor::CellPhoneVisitor()
{
}

CellPhoneVisitor::~CellPhoneVisitor()
{
}

class CellPhone
{
protected:
	CellPhone();
	~CellPhone();

public:
	virtual void Dial() = 0;
	virtual void SendMsg() = 0;
	virtual void Hang() = 0;
	virtual void RecvMsg() = 0;
	virtual void Accept(CellPhoneVisitor* p) = 0;

private:

};

CellPhone::CellPhone()
{
}

CellPhone::~CellPhone()
{
}

class XiaoMi : CellPhone
{
public:
	XiaoMi();
	~XiaoMi();

public:
	virtual void Dial()
	{
		std::cout << "XiaoMi Dial" << std::endl;
	}
	virtual void SendMsg()
	{
		std::cout << "XiaoMi SendMsg" << std::endl;
	}
	virtual void Hang()
	{
		std::cout << "XiaoMi Hang" << std::endl;
	}
	virtual void RecvMsg()
	{
		std::cout << "XiaoMi RecvMsg" << std::endl;
	}

	void Accept(CellPhoneVisitor* p)
	{
		p->Visit(this);
	}

private:

};

XiaoMi::XiaoMi()
{
}

XiaoMi::~XiaoMi()
{
}


class Huawei : CellPhone
{
public:
	Huawei();
	~Huawei();

public:
	virtual void Dial()
	{
		std::cout << "Huawei Dial" << std::endl;
	}
	virtual void SendMsg()
	{
		std::cout << "Huawei SendMsg" << std::endl;
	}
	virtual void Hang()
	{
		std::cout << "Huawei Hang" << std::endl;
	}
	virtual void RecvMsg()
	{
		std::cout << "Huawei RecvMsg" << std::endl;
	}

	void Accept(CellPhoneVisitor* p)
	{
		p->Visit(this);
	}

private:

};

Huawei::Huawei()
{
}

Huawei::~Huawei()
{
}

class Oppo : CellPhone
{
public:
	Oppo();
	~Oppo();

public:
	virtual void Dial()
	{
		std::cout << "Oppo Dial" << std::endl;
	}
	virtual void SendMsg()
	{
		std::cout << "Oppo SendMsg" << std::endl;
	}
	virtual void Hang()
	{
		std::cout << "Oppo Hang" << std::endl;
	}
	virtual void RecvMsg()
	{
		std::cout << "Oppo RecvMsg" << std::endl;
	}

	void Accept(CellPhoneVisitor* p)
	{
		p->Visit(this);
	}

private:

};

Oppo::Oppo()
{
}

Oppo::~Oppo()
{
}

class SolarisConfigure : public CellPhoneVisitor
{
public:
	SolarisConfigure();
	~SolarisConfigure();

public:
	void Visit(XiaoMi* p)
	{
		p->Dial();
		p->Hang();
		p->SendMsg();
		p->RecvMsg();
	}

	void Visit(Huawei* p)
	{
		p->Dial();
		p->Hang();
		p->SendMsg();
		p->RecvMsg();
	}

	void Visit(Oppo* p)
	{
		p->Dial();
		p->Hang();
		p->SendMsg();
		p->RecvMsg();
	}

private:

};

SolarisConfigure::SolarisConfigure()
{
}

SolarisConfigure::~SolarisConfigure()
{
}

void VisitorModeTest()
{
	CellPhoneVisitor* pVisitor = new SolarisConfigure();
	XiaoMi* pXiaoMi = new XiaoMi();
	Huawei* pHuawei = new Huawei();
	Oppo* pOppo = new Oppo();
	std::cout << "将Solairs环境配置给XiaoMi" << std::endl;
	pXiaoMi->Accept(pVisitor);
	std::cout << "将Solairs环境配置给Huawei" << std::endl;
	pHuawei->Accept(pVisitor);
	std::cout << "将Solairs环境配置给Oppo" << std::endl;
	pOppo->Accept(pVisitor);
}
