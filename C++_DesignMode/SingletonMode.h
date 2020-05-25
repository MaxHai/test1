
#ifndef __SINGLETON_MODE_H__
#define __SINGLETON_MODE_H__

//#include <afxwin.h>
#include <iostream>
#include <windows.h>

CRITICAL_SECTION g_cs;

class Singleton
{
private:
	Singleton()
	{
		m_singer = NULL;
		std::cout << "make a Singleton object" << std::endl;
	}

public:
	static Singleton* GetInstance()
	{
		if (m_singer == NULL)
		{
			/* lock */
			::TryEnterCriticalSection(&g_cs);
			if (m_singer == NULL)
			{
				m_singer = new Singleton;
			}
			/* unlock */
			::LeaveCriticalSection(&g_cs);
		}
		return m_singer;
	}

private:
	static Singleton* m_singer;

};

//C++ construction is not thread security;
Singleton* Singleton::m_singer = NULL;

void SingletonTest()
{
	//Process init;
	::InitializeCriticalSection(&g_cs);

	Singleton* p1 = Singleton::GetInstance();
	Singleton* p2 = Singleton::GetInstance();
	
	//Process exit
	::DeleteCriticalSection(&g_cs);
	printf("p1 = %x, p2 = %x\n", p1, p2);
}

#endif // !__SINGLETON_MODE_H__

