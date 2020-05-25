
#include "BinaryNode.h"

BinaryNode::BinaryNode(char c, class Express left, Express right) :m_opend(c), m_left(left), m_right(right) {}

void BinaryNode::print(std::ostream& os) const
{
	os << "(" << m_left << m_opend << m_right << ")";
}

int BinaryNode::eval() const
{
	int result = 0;
	int op1 = m_left.eval();
	int op2 = m_right.eval();
	switch (m_opend)
	{
	case '-':
		result = op1 - op2;
		break;
	case '+':
		result = op1 + op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		if (op2 != 0)
		{
			result = op1 / op2;
		}
		else
		{
			throw "error, 除数为0";
		}
		break;
	default:
		throw "error, 二叉归并上中的根操作符不正确";
		break;
	}

	return result;
}
