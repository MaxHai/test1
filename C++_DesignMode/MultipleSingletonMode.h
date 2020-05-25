
#ifndef __MULTIPLE_SINGLETON_MODE_H__
#define __MULTIPLE_SINGLETON_MODE_H__

#include <string>
#include <map>
#include <iostream>

//number
const static int NUM_MAX = 5;
class MultipleSingleton;

static std::map<int, MultipleSingleton*> myMap = std::map<int, MultipleSingleton*>();

class MultipleSingleton
{
private:
	MultipleSingleton()
	{
		m_singer = NULL;
		std::cout << "Make a single" << std::endl;
	}

public:
	static MultipleSingleton* GetInstance()
	{
		m_singer = myMap[m_InstanceCount];
		if (m_singer == NULL)
		{
			m_singer = new MultipleSingleton;
			myMap[m_InstanceCount] = m_singer;
			m_InstanceCount++;
		}
		if (m_InstanceCount > NUM_MAX)
		{
			/* object number is enough, not more is created */
			/* and return first object */
			m_InstanceCount = 0;
		}
		return m_singer;
	}

private:
	static MultipleSingleton* m_singer;
	static int m_InstanceCount;
};

MultipleSingleton* MultipleSingleton::m_singer = NULL;
int MultipleSingleton::m_InstanceCount = 0;

void MultipleSingletonModeTest()
{
	MultipleSingleton* p1 = MultipleSingleton::GetInstance();
	MultipleSingleton* p2 = MultipleSingleton::GetInstance();
	MultipleSingleton* p3 = MultipleSingleton::GetInstance();
	MultipleSingleton* p4 = MultipleSingleton::GetInstance();
	MultipleSingleton* p5 = MultipleSingleton::GetInstance();
	MultipleSingleton* p6 = MultipleSingleton::GetInstance();
	MultipleSingleton* p7 = MultipleSingleton::GetInstance();
	MultipleSingleton* p8 = MultipleSingleton::GetInstance();
	MultipleSingleton* p9 = MultipleSingleton::GetInstance();
	MultipleSingleton* p10 = MultipleSingleton::GetInstance();
	printf("p1 = %x, p2 = %x, p3 = %x, p4 = %x, p5 = %x\n", p1, p2, p3, p4, p5);
	printf("p6 = %x, p7 = %x, p8 = %x, p9 = %x, p10 = %x\n", p6, p7, p8, p9, p10);
}

#endif // !__MULTIPLE_SINGLETON_MODE_H__

