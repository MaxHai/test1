
#include "UnaryNode.h"

UnaryNode::UnaryNode(char c, class Express left): m_opend(c), m_left(left)
{
}

UnaryNode::~UnaryNode()
{

}

void UnaryNode::print(std::ostream& os) const
{
	os << "(" << m_opend << m_left << ")";
}

int UnaryNode::eval() const
{
	if (m_opend == '-')
	{
		return (-1) * m_left.eval();
	}
	throw "error opearator";
}
