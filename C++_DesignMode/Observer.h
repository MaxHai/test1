
#pragma once

#include <iostream>
#include <string>
#include <vector>

class Observer
{
public:
	Observer();
	~Observer();

public:
	virtual void Update(std::string temp, std::string humi) = 0;

private:

};

Observer::Observer()
{
}

Observer::~Observer()
{
}

class Subject
{
protected:
	Subject();
	~Subject();
	
public:
	virtual void RegisterObserver(Observer* pObj) = 0;
	virtual void RemoveObserver(Observer* pObj) = 0;
	virtual void NotifyObserver() = 0;

private:

};

Subject::Subject()
{
}

Subject::~Subject()
{
}

class WeatherData : public Subject
{
public:
	WeatherData(std::string temp, std::string humi):m_Temp(temp), m_Humi(humi){}
	~WeatherData();

public:
	void RegisterObserver(Observer* pObj)
	{
		m_observers.push_back(pObj);
	}

	void RemoveObserver(Observer* pObj)
	{
		auto iter = std::find(m_observers.begin(), m_observers.end(), pObj);
		if (iter != m_observers.end())
		{
			m_observers.erase(iter);
		}
	}

	void NotifyObserver()
	{
		for (std::vector<Observer*>::iterator iter = m_observers.begin(); iter != m_observers.end(); iter++)
		{
			(*iter)->Update(m_Temp, m_Humi);
		}
	}

	void SetData(std::string temp, std::string humi)
	{
		m_Temp = temp;
		m_Humi = humi;
		NotifyObserver();
	}

private:
	std::vector<Observer*> m_observers;
	std::string m_Temp;
	std::string m_Humi;
};

WeatherData::~WeatherData()
{
}

class PCDisplay : Observer
{
public:
	PCDisplay(WeatherData* pWeatherdata);
	~PCDisplay();

public:
	virtual void Update(std::string temp, std::string humi)
	{
		std::cout << "我是PC端的显示GUI，当前的温度为：" << temp << "，湿度为：" << humi << std::endl;
	}

private:
	WeatherData* m_pWeatherData;
};

PCDisplay::PCDisplay(WeatherData* pWeatherdata)
{
	m_pWeatherData = pWeatherdata;
	m_pWeatherData->RegisterObserver(this);
}

PCDisplay::~PCDisplay()
{
}

class MobileDisplay : public Observer
{
public:
	MobileDisplay(WeatherData* pWeatherdata);
	~MobileDisplay();

public:
	virtual void Update(std::string temp, std::string humi)
	{
		std::cout << "我是Mobile端的显示GUI，当前的温度为：" << temp << "，湿度为：" << humi << std::endl;
	}

private:
	WeatherData* m_pWeatherData;
};

MobileDisplay::MobileDisplay(WeatherData* pWeatherdata)
{
	m_pWeatherData = pWeatherdata;
	m_pWeatherData->RegisterObserver(this);
}

MobileDisplay::~MobileDisplay()
{
}

void ObserverModeTest()
{
	WeatherData* pWD = new WeatherData("22C", "65%");
	PCDisplay* pPCDisplay = new PCDisplay(pWD);
	MobileDisplay* pMobile = new MobileDisplay(pWD);
	pWD->SetData("38C", "55%");
	pWD->RemoveObserver(pMobile);
	pWD->SetData("31", "85%");
}