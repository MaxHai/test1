
#ifndef __CLONE_MODE_H__
#define __CLONE_MODE_H__

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
	OrderApi() {}

public:
	virtual int GetOrderProductNum() = 0;
	virtual void SetOrderProductNum(int num) = 0;
	virtual std::string GetOrderContent() = 0;
	virtual OrderApi* CloneOrder() = 0;

};

class HomeOrder : public OrderApi
{
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

	OrderApi* CloneOrder()
	{
		HomeOrder* pHomeOrder = new HomeOrder;
		pHomeOrder->SetCustomerName(m_strCustomerName);
		pHomeOrder->SetProductId(m_strProductId);
		pHomeOrder->SetOrderProductNum(m_orderProductNum);
		return pHomeOrder;
	}

private:
	std::string m_strCustomerName;
	std::string m_strProductId;
	int m_orderProductNum;
};

class AboardOrder : public OrderApi
{
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

	OrderApi* CloneOrder()
	{
		AboardOrder* pAboardOrder = new AboardOrder;
		pAboardOrder->SetCustomerName(m_strCustomerName);
		pAboardOrder->SetProductId(m_strProductId);
		pAboardOrder->SetOrderProductNum(m_orderProductNum);
		return pAboardOrder;
	}

private:
	std::string m_strCustomerName;
	std::string m_strProductId;
	int m_orderProductNum;
};

class OrderBusiness
{

public:
	void SaveOrder(OrderApi* pOrder);

};


void OrderBusiness::SaveOrder(OrderApi* pOrder)
{
	while (pOrder->GetOrderProductNum() > 200)
	{
		OrderApi* pNewOrder = pOrder->CloneOrder();
		pNewOrder->SetOrderProductNum(200);
		pOrder->SetOrderProductNum(pOrder->GetOrderProductNum() - 200);
		std::cout << "new order: " << pNewOrder->GetOrderContent() << std::endl;
	}
	std::cout << "result order: " << pOrder->GetOrderContent() << std::endl;
}

void CloneModeTest()
{
	HomeOrder* pHome = new HomeOrder;
	pHome->SetOrderProductNum(512);
	pHome->SetCustomerName("xcj&dst");
	pHome->SetProductId("XiaoHG");
	OrderBusiness* pOb = new OrderBusiness();
	pOb->SaveOrder(pHome);
}

#endif // !__CLONE_MODE_H__

