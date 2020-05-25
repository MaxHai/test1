
#ifndef __FACADE_H__
#define __FACADE_H__

#include <iostream>

class Carmera
{
public:
	Carmera();
	~Carmera();

public:
	void TurnOn()
	{
		std::cout << "open carmera" << std::endl;
	}

	void TurnOff()
	{
		std::cout << "close carmera" << std::endl;
	}

private:

};

Carmera::Carmera()
{
}

Carmera::~Carmera()
{
}

class Light
{
public:
	Light();
	~Light();

public:
	void TurnOn()
	{
		std::cout << "open light" << std::endl;
	}

	void TurnOff()
	{
		std::cout << "close light" << std::endl;
	}

private:

};

Light::Light()
{
}

Light::~Light()
{
}

class Sensor
{
public:
	Sensor();
	~Sensor();

public:
	void Active()
	{
		std::cout << "tach open" << std::endl;
	}

	void Deactive()
	{
		std::cout << "tach close" << std::endl;
	}

private:

};

Sensor::Sensor()
{
}

Sensor::~Sensor()
{
}

class Alarm
{
public:
	Alarm();
	~Alarm();

public:
	void Active()
	{
		std::cout << "Alarm open" << std::endl;
	}

	void Deactive()
	{
		std::cout << "Alarm close" << std::endl;
	}

private:

};

Alarm::Alarm()
{
}

Alarm::~Alarm()
{
}

class SecuritFacade
{
public:
	SecuritFacade();
	~SecuritFacade();

public:
	void Active()
	{
		std::cout << "start system" << std::endl;
		m_pCarmera->TurnOn();
		m_pLight->TurnOn();
		m_pSensor->Active();
		m_pAlarm->Active();
	}

	void Deactive()
	{
		std::cout << "end system" << std::endl;
		m_pAlarm->Deactive();
		m_pSensor->Deactive();
		m_pLight->TurnOff();
		m_pCarmera->TurnOff();
	}

private:
	Carmera* m_pCarmera;
	Light* m_pLight;
	Sensor* m_pSensor;
	Alarm* m_pAlarm;
};

SecuritFacade::SecuritFacade()
{
	m_pCarmera = new Carmera;
	m_pLight = new Light;
	m_pSensor = new Sensor;
	m_pAlarm = new Alarm;
}

SecuritFacade::~SecuritFacade()
{
}

void FacadeModeTest()
{
	/*
	Carmera* pCarmera = new Carmera;
	Light* pLight = new Light;
	Sensor* pSensor = new Sensor;
	Alarm* pAlarm = new Alarm;

	std::cout << "start system" << std::endl;
	pCarmera->TurnOn();
	pLight->TurnOn();
	pSensor->Active();
	pAlarm->Active();

	std::cout << "end system" << std::endl;
	pAlarm->Deactive();
	pSensor->Deactive();
	pLight->TurnOff();
	pCarmera->TurnOff(); */

	SecuritFacade* facade = new SecuritFacade;
	facade->Active();
	facade->Deactive();
}

#endif // !__FACADE_H__

