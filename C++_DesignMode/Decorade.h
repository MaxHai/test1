
#pragma once

#include <iostream>
#include <sstream>

template<class T>
std::string MyConverToStr(T obj)
{
	std::stringstream ss;
	ss << obj;
	return ss.str();
}

class Beverage
{
public:
	Beverage();
	~Beverage();

public:
	virtual std::string GetDescription() = 0;
	virtual double cost() = 0;

protected:
	std::string m_Description;

};

Beverage::Beverage()
{
}

Beverage::~Beverage()
{
}

class CondimentDecorate : public Beverage
{
protected:
	CondimentDecorate();
	~CondimentDecorate();

public:
	virtual std::string GetDescription() = 0;

private:

};

CondimentDecorate::CondimentDecorate()
{
}

CondimentDecorate::~CondimentDecorate()
{
}

class Soy : public CondimentDecorate
{
public:
	Soy(Beverage* pBeverge) :m_pBeverage(pBeverge)
	{

	}
	~Soy();

public:
	std::string GetDescription()
	{
		return m_pBeverage->GetDescription() + ", add 1";
	}

	double cost()
	{
		return 0.1 + m_pBeverage->cost();
	}

private:
	Beverage* m_pBeverage;
};

Soy::~Soy()
{
}

class Milk : public CondimentDecorate
{
public:
	Milk(Beverage* pBeverge) :m_pBeverage(pBeverge)
	{

	}
	~Milk();

public:
	std::string GetDescription()
	{
		return m_pBeverage->GetDescription() + ", add 2";
	}

	double cost()
	{
		return 5 + m_pBeverage->cost();
	}

private:
	Beverage* m_pBeverage;
};

Milk::~Milk()
{
}


class Lattee : public Beverage
{
public:
	Lattee()
	{
		m_Description = "Lattee";
	}

	std::string GetDescription()
	{
		return m_Description;
	}

	double cost()
	{
		return 15;
	}

};

class Expresso : public Beverage
{
public:
	Expresso()
	{
		m_Description = "Expresso";
	}

	std::string GetDescription()
	{
		return m_Description;
	}

	double cost()
	{
		return 20;
	}

};

class Mocha : public Beverage
{
public:
	Mocha()
	{
		m_Description = "Mocha";
	}

	std::string GetDescription()
	{
		return m_Description;
	}

	double cost()
	{
		return 18;
	}

};


void DecoradeModeTest()
{
	Beverage* pBeverage = new Expresso();
	pBeverage = new Milk(pBeverage);
	std::cout << pBeverage->GetDescription() << " price is : " << MyConverToStr(pBeverage->cost()) << std::endl;

	Beverage* pBeverage2 = new Mocha();
	pBeverage2 = new Soy(pBeverage2);
	std::cout << pBeverage2->GetDescription() << " price is : " << MyConverToStr(pBeverage2->cost()) << std::endl;
}