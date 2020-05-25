
#ifndef __DYN_FACTORY_MODE_H__
#define __DYN_FACTORY_MODE_H__

#include <string>
#include <map>
#include "SimpleFactoryMode.h"

typedef void* (*Constructor)();

class CObjectFactory 
{
public:
	static void RegisterClass(std::string className, Constructor constructor)
	{
		constructors()[className] = constructor;
	}

	static void* CreateObject(const std::string& className)
	{
		Constructor constructor = nullptr;
		if (constructors().find(className) != constructors().end())
		{
			constructor = constructors().find(className)->second;
		}
		if (constructor == NULL)
		{
			return NULL;
		}
		return (*constructor)();
	}
private:
	//string->key:class name, value: construction
	inline static std::map<std::string, Constructor>& constructors() 
	{
		static std::map<std::string, Constructor> instance;
		return instance;
	}
};

#define REG_CLASS(class_name) \
class class_name##Helper \
{ \
public: \
	class_name##Helper() \
	{ \
		CObjectFactory::RegisterClass(#class_name, class_name##Helper::CreateObjFunc); \
	} \
	static void* CreateObjFunc() \
	{ \
		return new class_name; \
	} \
}; \
class_name##Helper class_name##helper;

class AutoFactory
{
public:
	static Api* CreateApi()
	{
		Api* pApi = nullptr;
		pApi = static_cast<Api*>(CObjectFactory::CreateObject("ImplOne"));
		return pApi;
	}
};

REG_CLASS(ImplOne)
REG_CLASS(ImplTwo)
void DynFactoryModeTest()
{
	Api* pApi = AutoFactory::CreateApi();
	pApi->test("Can nothing to knoew about you: ");
	return;
}

#endif // !__DYN_FACTORY_MODE_H__

