
#ifndef __ADPTER_H__
#define __ADPTER_H__

#include <iostream>

class ThreePhaseOutlet
{
public:
	ThreePhaseOutlet();
	~ThreePhaseOutlet();

public:
	void DoThreePhasePlug()
	{
		std::cout << "Three choice" << std::endl;
	}

private:

};

ThreePhaseOutlet::ThreePhaseOutlet()
{
}

ThreePhaseOutlet::~ThreePhaseOutlet()
{
}

class TwoPhaseOutlet
{
public:
	TwoPhaseOutlet();
	~TwoPhaseOutlet();

public:
	virtual void DoPlug() = 0;

private:

};

TwoPhaseOutlet::TwoPhaseOutlet()
{
}

TwoPhaseOutlet::~TwoPhaseOutlet()
{
}

class OutletConverter : public TwoPhaseOutlet, public ThreePhaseOutlet
{
public:
	OutletConverter();
	~OutletConverter();

public:
	void DoPlug()
	{
		DoConvert();
		DoThreePhasePlug();
	}

	void DoConvert()
	{
		std::cout << "Three to Two let" << std::endl;
	}

private:

};

OutletConverter::OutletConverter()
{
}

OutletConverter::~OutletConverter()
{
}

class OutletObjConverter : public TwoPhaseOutlet
{
public:
	OutletObjConverter(ThreePhaseOutlet* pOut):m_pOut(pOut){}
	~OutletObjConverter();

public:
	void DoPlug()
	{
		m_pOut->DoThreePhasePlug();
	}

	void DoConvert()
	{
		std::cout << " Two choice " << std::endl;
	}

private:
	ThreePhaseOutlet* m_pOut;

};

OutletObjConverter::~OutletObjConverter()
{
}

void AdapterMode()
{
	//TwoPhaseOutlet* pOutlet = new OutletConverter();
	//pOutlet->DoPlug();
	TwoPhaseOutlet* pOutlet = new OutletObjConverter(new ThreePhaseOutlet);
	pOutlet->DoPlug();
}


#endif // !__ADPTER_H__

