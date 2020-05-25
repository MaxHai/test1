
#pragma once

#include "Express.h"
#include "ExpressNode.h"

class ValueNode : public ExpressNode
{
public:
	ValueNode(int value):m_value(value){}

public:
	friend class Express;

private:
	void print(std::ostream& os) const
	{
		os << m_value;
	}
	int eval() const { return m_value; }
	int m_value;
};
