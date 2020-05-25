
#pragma once

#include <iostream>
#include <string>

class Colleague;

/* 对象在自身改变的情况下，通知Mediator进行变更
 * 让我们Mediator这个总线，负责响应的同时对象交互 */
class Mediator
{
protected:
	Mediator();
	~Mediator();

public:
	virtual void Changed(Colleague* pColleague) = 0;

private:

};

Mediator::Mediator()
{
}

Mediator::~Mediator()
{
}


class Colleague
{
public:
	Colleague();
	Colleague(Mediator* pMediator):m_pMediator(pMediator){}
	~Colleague();

public:
	Mediator* GetMediator()
	{
		return m_pMediator;
	}

private:
	Mediator* m_pMediator;
};

Colleague::Colleague()
{
}

Colleague::~Colleague()
{
}

class SoundCard : public Colleague
{
public:
	//模拟声卡工作
	SoundCard(Mediator* pMediator):Colleague(pMediator){}
	~SoundCard();

public:
	void SoundData(std::string data)
	{
		std::cout << "声卡在工作 " << data << std::endl;
	}

private:

};

SoundCard::~SoundCard()
{
}

class VideoCard : public Colleague
{
public:
	VideoCard(Mediator* pMediator):Colleague(pMediator){}
	~VideoCard();

public:
	void VideoData(std::string data)
	{
		std::cout << "显卡在工作 " << data << std::endl;
	}

private:

};

VideoCard::~VideoCard()
{
}

class CPU : public Colleague
{
public:
	CPU(Mediator* pMediator) :Colleague(pMediator) {}
	~CPU();

public:
	void ExecuteData(std::string data[])
	{
		m_strVideoData = data[0];
		m_strSoundData = data[1];
		this->GetMediator()->Changed(this);
	}

	std::string GetVideoData()
	{
		return m_strVideoData;
	}

	std::string GetSoundData()
	{
		return m_strSoundData;
	}

private:
	std::string m_strVideoData;
	std::string m_strSoundData;
};

CPU::~CPU()
{
}

class MotherBoard : public Mediator
{
public:
	MotherBoard();
	~MotherBoard();

public:
	void SetCPU(CPU* pCpu)
	{
		m_pCPU = pCpu;
	}

	void SetVideoCard(VideoCard* pVideoCard)
	{
		m_pVideoCard = pVideoCard;
	}

	void SetSoundCard(SoundCard* pSoundCard)
	{
		m_pSoundCard = pSoundCard;
	}

	void Changed(Colleague* pColleague)
	{
		if (pColleague == m_pCPU)
		{
			this->OpenCPU((CPU*)pColleague);
		}
	}

private:
	void OpenCPU(CPU* pCPU)
	{
		/* 主板开始进行各个部件的运行，首先调用CPU，将处理好的数据得到 */
		std::string strVideoData = pCPU->GetVideoData();
		std::string strSoundData = pCPU->GetSoundData();
		/* 将这些处理好的数据交付给SoundCard，VideoCard，让他们工作 */
		m_pVideoCard->VideoData(strVideoData);
		m_pSoundCard->SoundData(strSoundData);
	}

private:
	CPU* m_pCPU;
	VideoCard* m_pVideoCard;
	SoundCard* m_pSoundCard;
};

MotherBoard::MotherBoard()
{
}

MotherBoard::~MotherBoard()
{
}

void MediatorModeTest()
{
	/* 创建Mediator */
	MotherBoard* pMediator = new MotherBoard();
	/* 创建同事类的对象 */
	CPU* pCPU = new CPU(pMediator);
	VideoCard* pVC = new VideoCard(pMediator);
	SoundCard* pSC = new SoundCard(pMediator);
	/* 让Mediator都知道这些Colleague的对象 */
	pMediator->SetCPU(pCPU);
	pMediator->SetSoundCard(pSC);
	pMediator->SetVideoCard(pVC);
	/* 让数据运行起来 */
	std::string arr[] = {"XiaoHG", "C++ mode"};
	pCPU->ExecuteData(arr);
}