
#include "ExpressNode.h"

ExpressNode::~ExpressNode()
{
}

int ExpressNode::GetUse() const
{
	return m_use;
}

void ExpressNode::SetUse(int use)
{
	m_use = use;
}


