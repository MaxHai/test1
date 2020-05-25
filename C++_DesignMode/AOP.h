
/*
 * AOP�������棨���棩���
 * �����ǵ��ճ������У����Ǿ���������������һ����ҵ���߼��޹صĿ�����������
 * ��log����log֯�����ǵ�ҵ�񳡾�
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
		std::cout << "����" << std::endl;
		m_ptr->Output(str);
		std::cout << "֮������" << std::endl;
	}

private:
	IHello* m_ptr;
};


void AOPModeTest()
{
	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
	hello->Output("AOP test");
}