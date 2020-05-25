
#pragma once

#include "Express.h"
#include "ExpressNode.h"

class UnaryNode : public ExpressNode
{
public:
	UnaryNode(char, class Express);
	~UnaryNode();

private:
	void print(std::ostream& os) const;
	int eval() const;
	char m_opend;
	class Express m_left;
};