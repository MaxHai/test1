
#ifndef __IOC_H__
#define __IOC_H__

#include <string>
#include <map>
#include <memory>
#include <functional>
#include <iostream>

template <class T>
class IocContainer
{
public:
	IocContainer() {}
	~IocContainer() {}

	//注册需要创建对象的构造函数，通过一个唯一的表示，以便于以后查找。
	template <class Drived>
	void Register(std::string strKey)
	{
		std::function<T * ()> function = [] {return new Drived(); };
		RegisterType(strKey, function);
	}

	//根据唯一标识去查找对应的构造函数
	T* Resolve(std::string strKey)
	{
		if (m_createMap.find(strKey) == m_createMap.end())
		{
			return nullptr;
		}
		std::function<T * ()> function = m_createMap[strKey];
		return function();
	}

	//创建智能指针
	std::shared_ptr<T> ResolveShared(std::string strKey)
	{
		T* ptr = Resolve(strKey);
		return std::shared_ptr<T>(ptr);
	}

private:
	void RegisterType(std::string strKey, std::function<T * ()> creator)
	{
		if(m_createMap.find(strKey) != m_createMap.end())
		{
			throw std::invalid_argument("This key is already exist");
		}
		m_createMap.emplace(strKey, creator);
	}

private:
	std::map<std::string, std::function<T * ()>> m_createMap;
};

struct ICar
{
	virtual ~ICar() {}
	virtual void test() const = 0;
};

struct Bus : ICar
{
	Bus() {}
	void test() const { std::cout << "Bus::test()" << std::endl; }
};

struct Track : ICar
{
	Track() {}
	void test() const { std::cout << "Track::test()" << std::endl; }
};

void IOCTest()
{
	IocContainer<ICar> carIOC;
	carIOC.Register<Bus>("bus");
	carIOC.Register<Track>("track");

	std::shared_ptr<ICar> bus = carIOC.ResolveShared("bus");
	bus->test();

	std::shared_ptr<ICar> track = carIOC.ResolveShared("track");
	track->test();
}

#endif // !__IOC_H__
