
#pragma once
#include <iostream>

class ExpressNode
{
public:
	ExpressNode() : m_use(1) {}
	virtual ~ExpressNode();

public:
	friend class Express;

public:
	int GetUse() const;
	void SetUse(int);
	friend std::ostream& operator<<(std::ostream& os, const ExpressNode& ExprNode)
	{
		ExprNode.print(os);
		return os;
	}

protected:
	virtual void print(std::ostream& os) const = 0;
	virtual int eval() const = 0;

private:
	int m_use;
};