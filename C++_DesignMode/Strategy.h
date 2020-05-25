
#pragma once

#include <iostream>

/* 我们父类和子类就是一个扩展的关系？ 是不是合适的 */
/* 里氏代换原则：子类对象就应该完全替代父类的行为 */
/* 对于继承这样的设计，特别信息，组合大于继承 */
/* 把quack和fly抽象成为一个对象，那么这个问题就有了解决方案 */

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
		std::cout << "我是唐老鸭" << std::endl;
	}

	void Display()
	{
		Quack();
	}

	void fly()
	{
		std::cout << "我是唐老鸭，虽然自身不会飞，但是我可以坐飞机，热气球" << std::endl;
	}

private:

};

DonaladDuck::DonaladDuck()
{
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
		std::cout << "我是小野鸭" << std::endl;
	}
	
	void Display()
	{
		Quack();
	}

	void fly()
	{
		std::cout << "我会飞" << std::endl;
	}

private:

};

WigeonDuck::WigeonDuck()
{
}

WigeonDuck::~WigeonDuck()
{
}