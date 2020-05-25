
#pragma once

#include <iostream>

/* ���Ǹ�����������һ����չ�Ĺ�ϵ�� �ǲ��Ǻ��ʵ� */
/* ���ϴ���ԭ����������Ӧ����ȫ����������Ϊ */
/* ���ڼ̳���������ƣ��ر���Ϣ����ϴ��ڼ̳� */
/* ��quack��fly�����Ϊһ��������ô�����������˽������ */

class Duck
{
public:
	Duck();
	~Duck();

public:
	virtual void Quack() = 0;
	virtual void Display() = 0;
	virtual void fly() = 0;

protected:

private:

};

Duck::Duck()
{
}

Duck::~Duck()
{
}

class DonaladDuck : public Duck
{
public:
	DonaladDuck();
	~DonaladDuck();

public:
	void Quack()
	{
		std::cout << "��������Ѽ" << std::endl;
	}

	void Display()
	{
		Quack();
	}

	void fly()
	{
		std::cout << "��������Ѽ����Ȼ������ɣ������ҿ������ɻ���������" << std::endl;
	}

private:

};

DonaladDuck::DonaladDuck()
{
}

DonaladDuck::~DonaladDuck()
{
}

//��һ�������������ƺ���̫��ô���ࡣ
class RuberDuck : public Duck
{
public:
	RuberDuck();
	~RuberDuck();

public:
	void Quack()
	{

	}

	void Display()
	{
		Quack();
	}

private:

};

RuberDuck::RuberDuck()
{
}

RuberDuck::~RuberDuck()
{
}

class WigeonDuck : public Duck
{
public:
	WigeonDuck();
	~WigeonDuck();

public:
	void Quack()
	{
		std::cout << "����СҰѼ" << std::endl;
	}
	
	void Display()
	{
		Quack();
	}

	void fly()
	{
		std::cout << "�һ��" << std::endl;
	}

private:

};

WigeonDuck::WigeonDuck()
{
}

WigeonDuck::~WigeonDuck()
{
}