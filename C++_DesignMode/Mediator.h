
#pragma once

#include <iostream>
#include <string>

class Colleague;

/* ����������ı������£�֪ͨMediator���б��
 * ������Mediator������ߣ�������Ӧ��ͬʱ���󽻻� */
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
	//ģ����������
	SoundCard(Mediator* pMediator):Colleague(pMediator){}
	~SoundCard();

public:
	void SoundData(std::string data)
	{
		std::cout << "�����ڹ��� " << data << std::endl;
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
		std::cout << "�Կ��ڹ��� " << data << std::endl;
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
		/* ���忪ʼ���и������������У����ȵ���CPU��������õ����ݵõ� */
		std::string strVideoData = pCPU->GetVideoData();
		std::string strSoundData = pCPU->GetSoundData();
		/* ����Щ����õ����ݽ�����SoundCard��VideoCard�������ǹ��� */
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
	/* ����Mediator */
	MotherBoard* pMediator = new MotherBoard();
	/* ����ͬ����Ķ��� */
	CPU* pCPU = new CPU(pMediator);
	VideoCard* pVC = new VideoCard(pMediator);
	SoundCard* pSC = new SoundCard(pMediator);
	/* ��Mediator��֪����ЩColleague�Ķ��� */
	pMediator->SetCPU(pCPU);
	pMediator->SetSoundCard(pSC);
	pMediator->SetVideoCard(pVC);
	/* �������������� */
	std::string arr[] = {"XiaoHG", "C++ mode"};
	pCPU->ExecuteData(arr);
}