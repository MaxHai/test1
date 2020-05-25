
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
	/* 具体的功能由这个类实现，这个类派生了各种各样的表达式 */
	class ExpressNode* p;
};