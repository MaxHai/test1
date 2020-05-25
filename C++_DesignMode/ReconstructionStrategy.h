
#pragma once

#include <iostream>

/* ���Ǹ�����������һ����չ�Ĺ�ϵ�� �ǲ��Ǻ��ʵ� */
/* ���ϴ���ԭ����������Ӧ����ȫ����������Ϊ */
/* ���ڼ̳���������ƣ��ر���Ϣ����ϴ��ڼ̳� */
/* ��quack��fly�����Ϊһ��������ô�����������˽������ */


//����˽���������������ˡ�����
class QuackBehavior
{
protected:
	QuackBehavior();
	~QuackBehavior();

public:
	virtual void Quack() = 0;

private:

};

QuackBehavior::QuackBehavior()
{
}

QuackBehavior::~QuackBehavior()
{
}

class FlyBehavior
{
protected:
	FlyBehavior();
	~FlyBehavior();

public:
	virtual void Fly() = 0;

private:

};

FlyBehavior::FlyBehavior()
{
}

FlyBehavior::~FlyBehavior()
{
}

class FlyWithRocket : public FlyBehavior
{
public:
	FlyWithRocket();
	~FlyWithRocket();

public:
	void Fly()
	{
		std::cout << "���Ż����" << std::endl;
	}

private:

};

FlyWithRocket::FlyWithRocket()
{
}

FlyWithRocket::~FlyWithRocket()
{
}

class FlyWithWings : public FlyBehavior
{
public:
	FlyWithWings();
	~FlyWithWings();

public:
	void Fly()
	{
		std::cout << "���г���Լ���" << std::endl;
	}

private:

};

FlyWithWings::FlyWithWings()
{
}

FlyWithWings::~FlyWithWings()
{
}

class FlyWithNoWay : public FlyBehavior
{
public:
	FlyWithNoWay();
	~FlyWithNoWay();

public:
	void Fly()
	{
		std::cout << "�Ҹ����Ͳ����" << std::endl;
	}

private:

};

FlyWithNoWay::FlyWithNoWay()
{
}

FlyWithNoWay::~FlyWithNoWay()
{
}

class ZhiZhiQuack : public QuackBehavior
{
public:
	ZhiZhiQuack();
	~ZhiZhiQuack();

public:
	void Quack()
	{
		std::cout << "֨֨" << std::endl;
	}

private:

};

ZhiZhiQuack::ZhiZhiQuack()
{
}

ZhiZhiQuack::~ZhiZhiQuack()
{
}

class PersonQuack : public QuackBehavior
{
public:
	PersonQuack();
	~PersonQuack();

public:
	void Quack()
	{
		std::cout << "������������" << std::endl;
	}

private:

};

PersonQuack::PersonQuack()
{
}

PersonQuack::~PersonQuack()
{
}

class WigeonQuack : public QuackBehavior
{
public:
	WigeonQuack();
	~WigeonQuack();

public:
	void Quack()
	{
		std::cout << "��СѼ�����" << std::endl;
	}

private:

};

WigeonQuack::WigeonQuack()
{
}

WigeonQuack::~WigeonQuack()
{
}

/////////////////////////////////////
//Duck has a Quack
//		has a Fly
class Duck
{
public:
	Duck();
	~Duck();

public:
	virtual void Display() = 0;
	void SetFlyBehavior(FlyBehavior* fb)
	{
		m_pFly = fb;
	}

	void SetQuackBehavior(QuackBehavior* qb)
	{
		m_pQuack = qb;
	}

	virtual void PerFormFly()
	{
		m_pFly->Fly();
	}

	virtual void PerformQuack()
	{
		m_pQuack->Quack();
	}

protected:
	QuackBehavior* m_pQuack;
	FlyBehavior* m_pFly;
private:

};

Duck::Duck()
{
}

Duck::~Duck()
{
}

//DonaladDuck is Duck
class DonaladDuck : public Duck
{
public:
	DonaladDuck();
	~DonaladDuck();

public:

	void Display()
	{
		PerFormFly();
		PerformQuack();
	}

private:

};

DonaladDuck::DonaladDuck()
{
	m_pFly = new FlyWithRocket();
	m_pQuack = new PersonQuack();
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
	void Display()
	{
		PerFormFly();
		PerformQuack();
	}

private:

};

RuberDuck::RuberDuck()
{
	m_pFly = new FlyWithNoWay();
	m_pQuack = new ZhiZhiQuack();
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

	void Display()
	{
		PerFormFly();
		PerformQuack();
	}

private:

};

WigeonDuck::WigeonDuck()
{
	m_pFly = new FlyWithWings();
	m_pQuack = new WigeonQuack();
}

WigeonDuck::~WigeonDuck()
{
}

void ReconstructionStrategyModeTest()
{
	DonaladDuck* pDonlad = new DonaladDuck();
	pDonlad->Display();
}