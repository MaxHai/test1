
#ifndef __BUILDER_MODE_H__
#define __BUILDER_MODE_H__


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
	ExportHeaderModel(std::string strDepId, std::string strExportDate) :m_strDepId(strDepId), m_strExportDate(strExportDate)
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
	ExportDataMode(std::string strTransId, double Quantity) :m_strTransId(strTransId), m_Quantity(Quantity)
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

class Builder
{
protected:
	Builder() {}

public:
	virtual void BuilderHeader(ExportHeaderModel& ehm) = 0;
	virtual void BuilderBody(std::vector<ExportDataMode*>& edmCollection) = 0;
	virtual void BuilderFool(ExportFooterModel& efm) = 0;
	virtual std::string GetResult() = 0;
private:

};

class TxtBuilder : public Builder
{
public:
	TxtBuilder() 
	{
		m_strResulst = "";
	}
	~TxtBuilder() {}

public:
	void BuilderHeader(ExportHeaderModel& ehm)
	{
		m_strResulst.append(ehm.GetDepId() + ", " + ehm.GetExportDate() + "\n");
	}

	void BuilderBody(std::vector<ExportDataMode*>& edmCollection)
	{
		for (std::vector<ExportDataMode*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++)
		{
			m_strResulst.append((*iter)->GetTransId() + ":" + ConvertToString((*iter)->GetQuantity()) + "\n");
		}
	}

	void BuilderFool(ExportFooterModel& efm)
	{
		m_strResulst.append(efm.GetExportUser() + "\n");
	}

	std::string GetResult()
	{
		return m_strResulst;
	}

private:
	std::string m_strResulst;
};

class XmlBuilder : public Builder
{
public:
	XmlBuilder()
	{
		m_strResulst = "";
	}
	~XmlBuilder() {}

public:
	void BuilderHeader(ExportHeaderModel& ehm)
	{
		m_strResulst.append("<?xml version='1.0' encoding='utf-8'>\n");
		m_strResulst.append("<Receipt>\n");
		m_strResulst.append("	<Header>\n");
		m_strResulst.append("		<DepId>");
		m_strResulst.append(ehm.GetDepId() + "</DepId>\n");
		m_strResulst.append("		<ExportDate>" + ehm.GetExportDate() + "</ExportDate>\n");
		m_strResulst.append("	</Header>\n");
	}

	void BuilderBody(std::vector<ExportDataMode*>& edmCollection)
	{
		m_strResulst.append("	<Body>\n");
		for (std::vector<ExportDataMode*>::iterator iter = edmCollection.begin(); iter != edmCollection.end(); iter++)
		{
			m_strResulst.append("		<id>" + (*iter)->GetTransId() + "</id>\n");
			m_strResulst.append("		<amount>" + ConvertToString((*iter)->GetQuantity()) + "</amount>\n");
		}
		m_strResulst.append("	</Body>\n");
	}

	void BuilderFool(ExportFooterModel& efm)
	{
		m_strResulst.append("	<Footer>\n");
		m_strResulst.append("		<ExportUser>" + efm.GetExportUser() + "</ExportUser>\n");
		m_strResulst.append("	</Footer>\n</Receipt>\n");
	}

	std::string GetResult()
	{
		return m_strResulst;
	}

private:
	std::string m_strResulst;
};

class Director
{
public:
	Director(Builder* pBuilder):m_pBuilder(pBuilder) {}
	~Director() {}

public:
	void Construct(ExportHeaderModel& ehm, std::vector<ExportDataMode*>& edmCollection, ExportFooterModel& efm)
	{
		m_pBuilder->BuilderHeader(ehm);
		m_pBuilder->BuilderBody(edmCollection);
		m_pBuilder->BuilderFool(efm);
	}

private:
	Builder* m_pBuilder;
};



void BuilderModeTest()
{
	ExportHeaderModel* pEhm = new ExportHeaderModel("XiaoHG", "20200519");
	ExportDataMode* pEdm1 = new ExportDataMode("1", 10000.00f);
	ExportDataMode* pEdm2 = new ExportDataMode("2", 20000.00f);
	std::vector<ExportDataMode*> myVec;
	myVec.push_back(pEdm1);
	myVec.push_back(pEdm2);
	ExportFooterModel* pEfm = new ExportFooterModel("XCJ");

	//ExportToTxtHelper helper;
	//ExportToXmlHelper helper;
	//helper.DoExport(*pEhm, myVec, *pEfm);
	Builder* pBuilder = new TxtBuilder();
	Director* pDirector = new Director(pBuilder);
	pDirector->Construct(*pEhm, myVec, *pEfm);
	std::cout << pBuilder->GetResult() << std::endl;

	pBuilder = new XmlBuilder();
	pDirector = new Director(pBuilder);
	pDirector->Construct(*pEhm, myVec, *pEfm);
	std::cout << pBuilder->GetResult() << std::endl;
}


#endif // !__BUILDER_MODE_H__
