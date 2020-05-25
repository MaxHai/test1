
#pragma once

#include <iostream>

class MakeOther
{
public:
	MakeOther();
	~MakeOther();

public:
	virtual void StartOrder()
	{
		std::cout << "Add order" << std::endl;
	}
	virtual void ReplyStart() = 0;
	//...

	virtual void FinishOrder() = 0;
	virtual void ReplyFinish() = 0;

	//Template meth
	void make()
	{
		StartOrder();
		ReplyStart();
		FinishOrder();
		ReplyFinish();
	}

private:

};

MakeOther::MakeOther()
{
}

MakeOther::~MakeOther()
{
}

class Fanuc : public MakeOther
{
public:
	Fanuc();
	~Fanuc();

public:
	void StartOrder()
	{
		std::cout << "Fanuc start accpet order" << std::endl;
	}
	
	void ReplyStart()
	{
		std::cout << "Fanuc ready, after wait" << std::endl;
	}
	
	void FinishOrder()
	{
		std::cout << "This time fanuc's over, next please" << std::endl;
	}

	void ReplyFinish()
	{
		std::cout << "Fanuc singal is comming, ready to next order" << std::endl;
	}

private:

};

Fanuc::Fanuc()
{
}

Fanuc::~Fanuc()
{
}

class Smis : public MakeOther
{
public:
	Smis();
	~Smis();

public:

	void ReplyStart()
	{
		std::cout << "Smis ready, after wait" << std::endl;
	}

	void FinishOrder()
	{
		std::cout << "This time Smis's over, next please" << std::endl;
	}

	void ReplyFinish()
	{
		std::cout << "Smis singal is comming, ready to next order" << std::endl;
	}

private:

};

Smis::Smis()
{
}

Smis::~Smis()
{
}

void TmeplateMethModeTest()
{
	MakeOther* pMakeOrder = new Fanuc();
	pMakeOrder->make();


	MakeOther* pMakeOrder1 = new Smis();
	pMakeOrder1->make();
}