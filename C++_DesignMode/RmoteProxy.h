
#pragma once

#include <iostream>
#include <string>

class AbstractServer
{
protected:
	AbstractServer();
	~AbstractServer();

public:
	virtual void Request() = 0;

private:

};

AbstractServer::AbstractServer()
{
}

AbstractServer::~AbstractServer()
{
}

class RealServer : public AbstractServer
{
public:
	RealServer();
	~RealServer();

public:
	void Request()
	{
		std::cout << "Start server" << std::endl;
	}

private:

};

RealServer::RealServer()
{
}

RealServer::~RealServer()
{
}

class ProxyServer : public AbstractServer
{
public:
	ProxyServer(std::string name, std::string pwd) :m_name(name), m_pwd(pwd)
	{
		m_pServer = new RealServer;
	}
	~ProxyServer();

public:
	void Request()
	{
		if ("admin" == m_name && "123" == m_pwd)
		{
			std::cout << "Request successful" << std::endl;
			std::cout << "Proxy server is starting ..." << std::endl;
			m_pServer->Request();
			std::cout << "Server request over" << std::endl;
		}
		else
		{
			std::cout << "Request failed, use name or pwd error" << std::endl;
		}
	}

private:
	std::string m_name;
	std::string m_pwd;

private:
	AbstractServer* m_pServer;
};

ProxyServer::~ProxyServer()
{
}

void RmoteProxyModeTest()
{
	AbstractServer* pProxy = new ProxyServer("admin", "123");
	pProxy->Request();
}
