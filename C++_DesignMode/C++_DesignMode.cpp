
#include <iostream>

#include "SimpleFactoryMode.h"
#include "DynFactoryMode.h"
#include "SingletonMode.h"
#include "MultipleSingletonMode.h"
#include "FactoryMode.h"
#include "IOC.h"
#include "AbstractFactory.h"
//#include "Builder.h"
#include "BuildeMode.h"
//#include "CloneNot.h"
#include "Clone.h"
#include "Adapter.h"
#include "STL_Adapter.h"
//#include "Facade.h"
#include "FlyWeight.h"
#include "RmoteProxy.h"
#include "AOP.h"
#include "SmartPointer.h"
#include "Decorade.h"
//#include "MFCCViewDec.h"
//#include "Composite.h"
#include "Bridge.h"
#include "TemplateMeth.h"
#include "ReconstructionStrategy.h"
#include "Observer.h"
#include "Command.h"
#include "ChainOfResponse.h"
#include "Memento.h"
#include "Mediator.h"

extern void CompositeModeTest();

int main()
{
	std::cout << "Hello XiaoHG!" << std::endl;

	//SimpleFactoryModeTest();
	//DynFactoryModeTest();
	//SingletonTest();
	//MultipleSingletonModeTest();
	//FactoryModeTest();
	//IOCTest();
	//AbstractFactoryModeTest();
	//BuilderModeTest();
	//CloneNotModeTest();
	//CloneModeTest();
	//AdapterMode();
	//STL_AdapterModeTest();
	//FacadeModeTest();
	//FlyWeightModeTest();
	//RmoteProxyModeTest();
	//AOPModeTest();
	//SmartPointerModeTest();
	//DecoradeModeTest();
	//MFCCViewDecModeTest();
	//CompositeModeTest();
	//CompositeModeTest();
	//DridgeModeTest();
	//TmeplateMethModeTest();
	//ReconstructionStrategyModeTest();
	//ObserverModeTest();
	//CommandModeTest();
	//ChainOfResponseModeTest();
	//MementoModeTest();
	MediatorModeTest();

	return 0;
}
