
#pragma once

#include <iostream>

/* 我们父类和子类就是一个扩展的关系？ 是不是合适的 */
/* 里氏代换原则：子类对象就应该完全替代父类的行为 */
/* 对于继承这样的设计，特别信息，组合大于继承 */
/* 把quack和fly抽象成为一个对象，那么这个问题就有了解决方案 */


//完成了将“动作”抽象成了“对象”
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
		std::cout << "坐着火箭飞" << std::endl;
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
		std::cout << "我有翅膀，自己飞" << std::endl;
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
		std::cout << "我根本就不会飞" << std::endl;
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
		std::cout << "吱吱" << std::endl;
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
		std::cout << "我是唐唐姥姥" << std::endl;
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
		std::cout << "丑小鸭变天鹅" << std::endl;
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

//第一个困境：子类似乎不太那么像父类。
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