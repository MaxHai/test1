
/*
 * AOP：面向方面（切面）编程
 * 在我们的日常开发中，我们经常会遇到这样的一类与业务逻辑无关的开发，正交化
 * 打log，将log织入我们的业务场景
*/

#pragma once

#include <iostream>
#include <string>
#include <memory>

class IHello
{
public:
	IHello();
	virtual ~IHello();

public:
	virtual void Output(const std::string& str){}

private:

};

IHello::IHello()
{
}

IHello::~IHello()
{
}

class Hello : public IHello
{
public:
	Hello();
	~Hello();

public:
	void Output(const std::string& str) override
	{
		std::cout << str << std::endl;
	}

private:

};

Hello::Hello()
{
}

Hello::~Hello()
{
}

class HelloProxy : public IHello
{
public:
	HelloProxy(IHello* p):m_ptr(p){}
	~HelloProxy()
	{
		delete m_ptr;
		m_ptr = nullptr;
	}

public:
	void Output(const std::string& str) final
	{
		std::cout << "拦截" << std::endl;
		m_ptr->Output(str);
		std::cout << "之后，拦截" << std::endl;
	}

private:
	IHello* m_ptr;
};


void AOPModeTest()
{
	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
	hello->Output("AOP test");
}