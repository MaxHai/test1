
#pragma once

#include <iostream>
#include <string>
#include <map>

class DownloadManager;

class DownState
{
protected:
	DownState();
	~DownState();

public:
	virtual void Down(std::string User, std::string DownItem, DownloadManager* p) = 0;

private:

};

DownState::DownState()
{
}

DownState::~DownState()
{
}

class NormalDownState : public DownState
{
public:
	NormalDownState();
	~NormalDownState();

public:
	void Down(std::string User, std::string DownItem, DownloadManager* p)
	{
		std::cout << "欢迎您下载本资源" << std::endl;
	}

private:

};

NormalDownState::NormalDownState()
{
}

NormalDownState::~NormalDownState()
{
}

class RepeateDownState : public DownState
{
public:
	RepeateDownState();
	~RepeateDownState();

public:
	void Down(std::string User, std::string DownItem, DownloadManager* p)
	{
		std::cout << "请不要重复下载" << std::endl;
	}

private:

};

RepeateDownState::RepeateDownState()
{
}

RepeateDownState::~RepeateDownState()
{
}

class SpiteDownState : public DownState
{
public:
	SpiteDownState();
	~SpiteDownState();

public:
	void Down(std::string User, std::string DownItem, DownloadManager* p)
	{
		std::cout << "你有恶意下载的嫌疑，即将取消下载资格" << std::endl;
	}

private:

};

SpiteDownState::SpiteDownState()
{
}

SpiteDownState::~SpiteDownState()
{
}

class BlackDownState : public DownState
{
public:
	BlackDownState();
	~BlackDownState();

public:
	void Down(std::string User, std::string DownItem, DownloadManager* p)
	{
		std::cout << "你的下载过于频繁，被列入黑名单，禁止登陆本系统" << std::endl;
	}

private:

};

BlackDownState::BlackDownState()
{
}

BlackDownState::~BlackDownState()
{
}

class DownloadManager
{
public:
	DownloadManager();
	~DownloadManager();

public:
	std::map<std::string, std::string> GetMapDown()
	{
		return m_mapDown;
	}

	void Down(std::string User, std::string DownItem)
	{
		int oldDownCount = 0;
		if (m_mapDownCount.count(User) > 0)
		{
			oldDownCount = m_mapDownCount[User];
		}
		else
		{
			m_mapDownCount[User] = 0;
		}
		oldDownCount++;
		m_mapDownCount[User] = oldDownCount;
		if (oldDownCount == 1)
		{
			m_pState = new NormalDownState();
		}
		else if (oldDownCount > 1 && oldDownCount < 3)
		{
			m_pState = new RepeateDownState();
		}
		else if (oldDownCount >= 3 && oldDownCount < 5)
		{
			m_pState = new SpiteDownState();
		}
		else
		{
			m_pState = new BlackDownState();
		}
		m_pState->Down(User, DownItem, this);
	}

private:
	DownState* m_pState;
	std::map<std::string, std::string> m_mapDown;
	std::map<std::string, int> m_mapDownCount;
};

DownloadManager::DownloadManager()
{
}

DownloadManager::~DownloadManager()
{
}

void StateModeTest()
{
	DownloadManager* pVM = new DownloadManager();
	for (int i = 0; i < 5; i++)
	{
		pVM->Down("XiaoHG", "C++ mode");
	}
}