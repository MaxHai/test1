
#include "Express.h"
#include "ValueNode.h"
#include "UnaryNode.h"
#include "BinaryNode.h"

Express::Express(int a)
{
	p = new ValueNode(a);
}

Express::Express(char c, const Express e)
{
	p = new UnaryNode(c, e);
}

Express::Express(char c, const Express el, const Express er)
{
	p = new BinaryNode(c, el, er);
}

Express::Express(const Express& el)
{
	p = el.p;
	p->SetUse(p->GetUse() + 1);
}

Express& Express::operator=(const Express& el)
{
	(el.p)->SetUse((el.p)->GetUse() + 1);
	p->SetUse(p->GetUse() -1);
	if (p->GetUse() == 0)
	{
		delete p;
	}
	p = el.p;
	return *this;
}

Express::~Express()
{
	p->SetUse(p->GetUse() - 1);
	if (p->GetUse() == 0)
	{
		delete p;
	}
}

int Express::eval() const
{
	return p->eval();
}

