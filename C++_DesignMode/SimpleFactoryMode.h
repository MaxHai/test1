
#ifndef __SIMPLE_FACTORY_MODE_H__
#define __SIMPLE_FACTORY_MODE_H__

#include <iostream>
#include <string>

class Api
{
public:
	virtual void test(std::string s) = 0;
protected:
	Api(){}
};

class ImplOne : public Api
{
public:
	void test(std::string s)
	{
		std::cout << s << ": now is Impl one class" << std::endl;
	}
};

class ImplTwo : public Api
{
public:
	void test(std::string s)
	{
		std::cout << s << ": now is Impl two class" << std::endl;
	}
};

class Factory
{
public:
	static Api* CreateApi(int type)
	{
		Api* pApi = nullptr;
		switch (type)
		{
		case 1:
			pApi = new ImplOne;
			break;
		case 2:
			pApi = new ImplTwo;
			break;
		default:
			break;
		}
		return pApi;
	}
private:
};

void SimpleFactoryModeTest()
{
	//1:ImpiOne, 2:ImpiTwo ...
	Api* pApi = Factory::CreateApi(2);
	pApi->test("now is factory");
	return;
}

#endif // __SIMPLE_FACTORY_MODE_H__

