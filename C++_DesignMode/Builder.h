
#ifndef __BUILDER_H__
#define __BUILDER_H__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<class T>
std::string ConvertToString(T value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

class ExportHeaderModel
{
public:
	ExportHeaderModel(std::string strDepId, std::string strExportDate):m_strDepId(strDepId), m_strExportDate(strExportDate)
	{

	}
	~ExportHeaderModel() {}
public:
	std::string GetDepId()
	{
		return m_strDepId;
	}
	std::string GetExportDate()
	{
		return m_strExportDate;
	}
private:
	std::string m_strDepId;
	std::string m_strExportDate;

};

class ExportDataMode
{
public:
	ExportDataMode(std::string strTransId, double Quantity):m_strTransId(strTransId), m_Quantity(Quantity)
	{

	}
	~ExportDataMode() {}

public:
	std::string GetTransId()
	{
		return m_strTransId;
	}
	double GetQuantity()
	{
		return m_Quantity;
	}

private:
	std::string m_strTransId;
	double m_Quantity;
};

class ExportFooterModel
{
public:
	ExportFooterModel(std::string exportUser) :m_exportUser(exportUser)
	{

	}
	~ExportFooterModel() {}
public:
	std::string GetExportUser()
	{
		return m_exportUser;
	}

private:
	std::string m_exportUser;
};

class ExportToTxtHelper
{
public:
	ExportToTxtHelper() {}
	~ExportToTxtHelper() {}
public:
	void DoExport(ExportHeaderModel& ehm, std::vector<ExportDataMode*>& edmCollection, ExportFooterModel& efm);

private:

};

void ExportToTxtHelper::DoExport(ExportHeaderModel& ehm, std::vector<ExportDataMode*>& edmCollection, ExportFooterModel& efm)
{
	std::string strTemp = "";
	strTemp += ehm.GetDepId() + "," + ehm.GetExportDate() + "\n";
	for (std::vector<ExportDataMode*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++)
	{
		strTemp += (*iter)->GetTransId() + ":" + ConvertToString((*iter)->GetQuantity()) + "\n";
	}
	strTemp += efm.GetExportUser() + "\n";
	std::cout << strTemp << std::endl;
}

class ExportToXmlHelper
{
public:
	ExportToXmlHelper() {}
	~ExportToXmlHelper() {}
public:
	void DoExport(ExportHeaderModel& ehm, std::vector<ExportDataMode*>& edmCollection, ExportFooterModel& efm);
private:

};

void ExportToXmlHelper::DoExport(ExportHeaderModel& ehm, std::vector<ExportDataMode*>& edmCollection, ExportFooterModel& efm)
{
	std::string strTemp = "";
	strTemp.append("<?xml version='1.0' encoding='utf-8'>\n");
	strTemp.append("<Receipt>\n");
	strTemp.append("	<Header>\n");
	strTemp.append("		<DepId>");
	strTemp.append(ehm.GetDepId() + "</DepId>\n");
	strTemp.append("		<ExportDate>" + ehm.GetExportDate() + "</ExportDate>\n");
	strTemp.append("	</Header>\n");
	strTemp.append("	<Body>\n");
	for (std::vector<ExportDataMode*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++)
	{
		strTemp.append("		<id>" + (*iter)->GetTransId() + "</id>\n");
		strTemp.append("		<amount>" + ConvertToString((*iter)->GetQuantity()) + "</amount>\n");

	}
	strTemp.append("	</Body>\n");
	strTemp.append("	<Footer>\n");
	strTemp.append("		<ExportUser>" + efm.GetExportUser() + "</ExportUser>\n");
	strTemp.append("	</Footer>\n</Receipt>\n");
	std::cout << strTemp << std::endl;
}



void BuilderTest()
{
	ExportHeaderModel* pEhm = new ExportHeaderModel("XiaoHG", "20200519");
	ExportDataMode* pEdm1 = new ExportDataMode("1", 10000.00f);
	ExportDataMode* pEdm2 = new ExportDataMode("2", 20000.00f);
	std::vector<ExportDataMode*> myVec;
	myVec.push_back(pEdm1);
	myVec.push_back(pEdm2);
	ExportFooterModel* pEfm = new ExportFooterModel("XCJ");

	//ExportToTxtHelper helper;
	ExportToXmlHelper helper;
	helper.DoExport(*pEhm, myVec, *pEfm);
}

#endif // !__BUILDER_H__
