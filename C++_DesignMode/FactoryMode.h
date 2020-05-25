
#ifndef __FACTORY_MODE_H__
#define __FACTORY_MODE_H__

#include <iostream>
#include <string>

class ExportFileApi
{
protected:
	ExportFileApi(){}

public:
	virtual bool ExportData(std::string data) = 0;

};

class ExportTxtFile : public ExportFileApi
{
public:
	bool ExportData(std::string data)
	{
		std::cout << "Out data ing \"" << data << "\"to file" << std::endl;
		return true;
	}

};

class ExportDB : public ExportFileApi
{
public:
	bool ExportData(std::string data)
	{
		std::cout << "Out data ing \"" << data << "\" to DB" << std::endl;
		return true;
	}

};

class ExportOperate
{
public:
	bool ExportData(std::string data)
	{
		ExportFileApi* pApi = FactoryMethod();
		return pApi->ExportData(data);
	}

protected:
	virtual ExportFileApi* FactoryMethod() = 0;

};

class ExprotTxtFileOperate : public ExportOperate
{
protected:
	ExportFileApi* FactoryMethod()
	{
		return new ExportTxtFile();
	}

};

class ExprotDBOperate : public ExportOperate
{
protected:
	ExportFileApi* FactoryMethod()
	{
		return new ExportDB();
	}

};

void FactoryModeTest()
{
	ExportOperate* pOperate = new ExprotTxtFileOperate();
	pOperate->ExportData("XiaoHG_TxtFile");
}

#endif // !__FACTORY_MODE_H__

