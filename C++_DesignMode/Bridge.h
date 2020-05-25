
#pragma once

#include <iostream>

class IOS
{
public:
	IOS();
	virtual ~IOS();

public:
	virtual void Run() = 0;

private:

};

IOS::IOS()
{
}

IOS::~IOS()
{
}

class CWindows : public IOS
{
public:
	CWindows();
	~CWindows();

public:
	virtual void Run()
	{
		std::cout << "Windows is runing" << std::endl;
	}

private:

};

CWindows::CWindows()
{
}

CWindows::~CWindows()
{
}

class CLinux : public IOS
{
public:
	CLinux();
	~CLinux();

public:
	virtual void Run()
	{
		std::cout << "Linux is runing" << std::endl;
	}

private:

};

CLinux::CLinux()
{
}

CLinux::~CLinux()
{
}

class IComputer
{
public:
	IComputer();
	~IComputer();

public:
	virtual void Install(IOS* pOS) = 0;

private:

};

IComputer::IComputer()
{
}

IComputer::~IComputer()
{
}

class CLenvo : public IComputer
{
public:
	CLenvo();
	~CLenvo();

public:
	virtual void Install(IOS* pOS)
	{
		std::cout << "Lenvo Install" << std::endl;
		pOS->Run();
	}

private:

};

CLenvo::CLenvo()
{
}

CLenvo::~CLenvo()
{
}

class CDell : public IComputer
{
public:
	CDell();
	~CDell();

public:
	virtual void Install(IOS* pOS)
	{
		std::cout << "CDell Install" << std::endl;
		pOS->Run();
	}

private:

};

CDell::CDell()
{
}

CDell::~CDell()
{
}

void DridgeModeTest()
{
	IOS* pWindows = new CWindows();
	IOS* pLinux = new CLinux();

	IComputer* pLenvo = new CLenvo();
	pLenvo->Install(pWindows);

	IComputer* pDell = new CDell();
	pDell->Install(pLinux);
}