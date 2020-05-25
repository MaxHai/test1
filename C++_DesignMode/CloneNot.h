
#ifndef __CLONE_NOT_H__
#define __CLONE_NOT_H__

#include <iostream>
#include <string>
#include <sstream>

template <class T>
std::string iToStr(T value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

class OrderApi
{
protected:
	OrderApi(){}

public:
	virtual int GetOrderProductNum() = 0;
	virtual void SetOrderProductNum(int num) = 0;
	virtual std::string GetOrderContent() = 0;

};

class HomeOrder : public OrderApi
{
public:
	HomeOrder(){}
	~HomeOrder(){}
public:
	int GetOrderProductNum()
	{
		return m_orderProductNum;
	}
	
	void SetOrderProductNum(int num)
	{
		m_orderProductNum = num;
	}
	std::string GetOrderContent()
	{
		return "XiaoHG: " + m_strCustomerName + "\nID: " + m_strProductId + "\nNum: " + iToStr(m_orderProductNum);
	}

	void SetCustomerName(std::string strCustomerName)
	{
		m_strCustomerName = strCustomerName;
	}

	std::string GetCustomerName()
	{
		return m_strCustomerName;
	}

	void SetProductId(std::string strProductId)
	{
		m_strProductId = m_strProductId;
	}

	std::string GetProductId()
	{
		return m_strProductId;
	}

private:
	std::string m_strCustomerName;
	std::string m_strProductId;
	int m_orderProductNum;
};

class AboardOrder : public OrderApi
{
public:
	AboardOrder() {}
	~AboardOrder() {}
public:
	int GetOrderProductNum()
	{
		return m_orderProductNum;
	}

	void SetOrderProductNum(int num)
	{
		m_orderProductNum = num;
	}
	std::string GetOrderContent()
	{
		return "XiaoHG: " + m_strCustomerName + "\nID: " + m_strProductId + "\nNum: " + iToStr(m_orderProductNum);
	}

	void SetCustomerName(std::string strCustomerName)
	{
		m_strCustomerName = strCustomerName;
	}

	std::string GetCustomerName()
	{
		return m_strCustomerName;
	}

	void SetProductId(std::string strProductId)
	{
		m_strProductId = m_strProductId;
	}

	std::string GetProductId()
	{
		return m_strProductId;
	}

private:
	std::string m_strCustomerName;
	std::string m_strProductId;
	int m_orderProductNum;
};

class OrderBusiness
{
public:
	OrderBusiness();
	~OrderBusiness();

public:
	void SaveOrder(OrderApi* pOrder);

private:

};

OrderBusiness::OrderBusiness()
{
}

OrderBusiness::~OrderBusiness()
{
}

void OrderBusiness::SaveOrder(OrderApi* pOrder)
{
	while (pOrder->GetOrderProductNum() > 200)
	{
		OrderApi* pNewOrder = nullptr;
		if (dynamic_cast<HomeOrder*>(pOrder) != nullptr)
		{
			HomeOrder* p2 = new HomeOrder;
			HomeOrder* p1 = static_cast<HomeOrder*>(pOrder);
			p2->SetOrderProductNum(200);
			p2->SetCustomerName(p1->GetCustomerName());
			p2->SetProductId(p1->GetProductId());
			pNewOrder = p2;
		}

		if (dynamic_cast<AboardOrder*>(pOrder) != nullptr)
		{
			AboardOrder* p2 = new AboardOrder;
			AboardOrder* p1 = static_cast<AboardOrder*>(pOrder);
			p2->SetOrderProductNum(200);
			p2->SetCustomerName(p1->GetCustomerName());
			p2->SetProductId(p1->GetProductId());
			pNewOrder = p2;
		}

		pOrder->SetOrderProductNum(pOrder->GetOrderProductNum() - 200);
		std::cout << "new order: " << pNewOrder->GetOrderContent() << std::endl;
	}
	std::cout << "result order: " << pOrder->GetOrderContent() << std::endl;
}

void CloneNotModeTest()
{
	HomeOrder* pHome = new HomeOrder;
	pHome->SetOrderProductNum(512);
	pHome->SetCustomerName("xcj&dst");
	pHome->SetProductId("XiaoHG");
	OrderBusiness* pOb = new OrderBusiness();
	pOb->SaveOrder(pHome);
}

#endif // !__CLONE_NOT_H__
