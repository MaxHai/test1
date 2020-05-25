
#pragma once

#include "ExpressNode.h"
#include "Express.h"

class BinaryNode : public ExpressNode
{
public:
	friend class Express;
	BinaryNode(char, class Express, class Express);

private:
	void print(std::ostream& os) const;
	int eval() const;
	char m_opend;
	class Express m_left;
	class Express m_right;
};
