
#pragma once

#include <iostream>
#include "ExpressNode.h"

class Express
{
public:
	Express(int);
	Express(char, const Express);
	Express(char, const Express, const Express);
	Express(const Express&);
	Express& operator=(const Express&);
	friend std::ostream& operator<<(std::ostream& os, const Express& e)
	{
		os << *(e.p);
		return os;
	}

	int eval() const;

	~Express();

private:
	/* ����Ĺ����������ʵ�֣�����������˸��ָ����ı��ʽ */
	class ExpressNode* p;
};