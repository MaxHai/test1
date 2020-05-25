
#pragma once

#include <iostream>
#include <string>
#include <sstream>

template<class T>
std::string MyConvertToString(T value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

/* 顶层的抽象类，规范了击鼓传花的组合能力 */
class Handle
{
public:
	Handle();
	~Handle();

public:
	void SetSuccessor(Handle* pSuccessor)
	{
		this->m_pHandle = pSuccessor;
	}

	virtual std::string HandleFeeRequest(double fee) = 0;

protected:
	Handle* m_pHandle;

private:

};

Handle::Handle()
{
}

Handle::~Handle()
{
}

class PrjManager : public Handle
{
public:
	PrjManager();
	~PrjManager();

public:
	virtual std::string HandleFeeRequest(double fee)
	{
		std::string strTemp = "";
		if (fee < 500)
		{
			strTemp = "项目经理同意" + MyConvertToString(fee) + "费用";
			return strTemp;
		}
		else
		{
			if (this->m_pHandle != nullptr)
			{
				return m_pHandle->HandleFeeRequest(fee);
			}
		}
		return strTemp;
	}

private:

};

PrjManager::PrjManager()
{
}

PrjManager::~PrjManager()
{
}

class DepManager : public Handle
{
public:
	DepManager();
	~DepManager();

public:
	virtual std::string HandleFeeRequest(double fee)
	{
		std::string strTemp = "";
		if (fee < 1000 && fee >= 500)
		{
			strTemp = "部门经理同意" + MyConvertToString(fee) + "费用";
			return strTemp;
		}
		else
		{
			if (this->m_pHandle != nullptr)
			{
				return m_pHandle->HandleFeeRequest(fee);
			}
		}
		return strTemp;
	}

private:

};

DepManager::DepManager()
{
}

DepManager::~DepManager()
{
}

class CEOManager : public Handle
{
public:
	CEOManager();
	~CEOManager();

public:
	virtual std::string HandleFeeRequest(double fee)
	{
		std::string strTemp = "";
		if (fee >= 1000)
		{
			strTemp = "CEO经理同意" + MyConvertToString(fee) + "费用";
			return strTemp;
		}
		else
		{
			if (this->m_pHandle != nullptr)
			{
				return m_pHandle->HandleFeeRequest(fee);
			}
		}
		return strTemp;
	}

private:

};

CEOManager::CEOManager()
{
}

CEOManager::~CEOManager()
{
}


void ChainOfResponseModeTest()
{
	Handle* pH1 = new PrjManager();
	Handle* pH2 = new DepManager();
	Handle* pH3 = new CEOManager();

	pH1->SetSuccessor(pH2);
	pH2->SetSuccessor(pH3);

	std::cout << pH1->HandleFeeRequest(128) << std::endl;
	std::cout << pH1->HandleFeeRequest(512) << std::endl;
	std::cout << pH1->HandleFeeRequest(1024) << std::endl;
}