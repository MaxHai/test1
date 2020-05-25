
#pragma once

#include <iostream>

template <class T>
class Auto_Ptr;

//智能指针和引用计数
template <class T>
class Ref_Ptr
{
	friend class Auto_Ptr<T>;

private:
	T* m_pTtr;
	size_t m_RefCount;
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template <class T>
Ref_Ptr<T>::Ref_Ptr(T* p)
{
	m_pTtr = p;
	m_RefCount = 1;
	std::cout << "Call Ref_Ptr() function" << std::endl;
}

template <class T>
Ref_Ptr<T>::~Ref_Ptr()
{
	if (m_pTtr)
	{
		std::cout << "Call ~Ref_Ptr() function" << std::endl;
		delete m_pTtr;
		m_pTtr = nullptr;
		m_RefCount = 0;
	}
	m_pTtr = nullptr;
}

template<class T>
class Auto_Ptr
{
public:
	Auto_Ptr();
	Auto_Ptr(T* p);
	~Auto_Ptr();

public:
	Auto_Ptr(Auto_Ptr<T>& other);
	Auto_Ptr<T>& operator=(Auto_Ptr& other);
	T& operator*();
	T* operator->();

private:
	Ref_Ptr<T>* m_pRef;
};

template<class T>
Auto_Ptr<T>::Auto_Ptr()
{
	m_pRef = nullptr;
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(T* p)
{
	m_pRef = new Ref_Ptr<T>(p);
	std::cout << "Call Ref_Ptr<T>(p) instruction function" << std::endl;
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other)
{
	m_pRef = other.m_pRef;
	++(m_pRef->m_RefCount);
	std::cout << "Call Auto_ptr(Auto_ptr<T>& other) function" << std::endl;
}

template<class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr<T>& other)
{
	//将右操作数对应应用+1
	++(other.m_pRef->m_RefCount);
	//由于左操作数指向了新对象，所以将操作数-1，防止自赋值
	if (m_pRef)
	{
		if (--(m_pRef->m_RefCount) == 0)
		{
			delete m_pRef;
		}
	}
	m_pRef = other.m_pRef;
	std::cout << "Call Auto_Ptr<T>::operator=(Auto_Ptr<T>& other), current RefCount = %d" << m_pRef->m_RefCount << std::endl;
	return other;
}

template<class T>
T& Auto_Ptr<T>::operator*()
{
	return *(m_pRef->m_pTtr);
}

template<class T>
T* Auto_Ptr<T>::operator->()
{
	return m_pRef->m_pTtr;
}

template<class T>
Auto_Ptr<T>::~Auto_Ptr()
{
	std::cout << "Call ~Auto_Ptr() function" << std::endl;
	if (--(m_pRef->m_RefCount) == 0)
	{
		std::cout << "delete" << std::endl;
		delete m_pRef;
		m_pRef = nullptr;
	}
}

void SmartPointerModeTest()
{
	Auto_Ptr<int>* pPtr = nullptr;
	{
		Auto_Ptr<int> g_ptr;
		{
			Auto_Ptr<int> ptr1(new int(4));
			std::cout << *ptr1 << std::endl;
			g_ptr = ptr1;
		}
		Auto_Ptr<int> ptr2(new int(3));
		g_ptr = ptr2;
		Auto_Ptr<int>* pPtr = &ptr2;
		std::cout << *(*pPtr) << std::endl;
	}
}