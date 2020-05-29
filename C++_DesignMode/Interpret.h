
#pragma once

#include <iostream>
#include <string>
#include <vector>

/* ����ı��ʽ�����Լ�Context���� 
 * ���ڱ��������м����Լ���ǰִ�еĲ����� */

class Context
{
public:
	~Context();

public:
	int m_value;
	char m_operator;
	Context();
};

Context::Context() :m_value(0), m_operator('\0')
{
}

Context::~Context()
{
}

/* ��ʾ���б��ʽ�ĳ���ӿ� */
class IExpression
{
public:
	IExpression();
	~IExpression();

public:
	virtual void Eval(Context* p) = 0;

private:

};

IExpression::IExpression()
{
}

IExpression::~IExpression()
{
}

/* ��ֱ��ʽ��Ԫ�� */
class Operator : public IExpression
{
public:
	Operator(char op);
	~Operator();

public:
	void Eval(Context* pContext)
	{
		pContext->m_operator = m_op;
	}

private:
	char m_op;
};

Operator::Operator(char op)
{
	this->m_op = op;
}

Operator::~Operator()
{
}

/* ��ֲ����� */
class Operand : public IExpression
{
public:
	Operand(int num);
	~Operand();

public:
	void Eval(Context* pContext)
	{
		switch (pContext->m_operator)
		{
		case '\0':
			pContext->m_value = m_num;
			break;
		case '+':
			pContext->m_value += m_num;
			break;
		case '-':
			pContext->m_value -= m_num;
			break;
		default:
			break;
		}
	}

private:
	int m_num;
};

Operand::Operand(int num)
{
	this->m_num = num;
}

Operand::~Operand()
{
}

class Calculator
{
public:
	Calculator();
	~Calculator();

public:
	int Calc(std::string expression)
	{
		Context* pContext = new Context();
		std::vector<IExpression*> tree;
		for (int i = 0; i < expression.size(); i++)
		{
			if (expression[i] == '+' || expression[i] == '-')
			{
				tree.push_back(new Operator(expression[i]));
				std::cout << "��" << i << "��ѹ��ķ�����" << expression[i] << std::endl;
			}
			else
			{
				tree.push_back(new Operator((int)expression[i] - 48));
				std::cout << "��" << i << "��ѹ���������" << (int)(expression[i] - 48) << std::endl;
			}
		}
		for (std::vector<IExpression*>::iterator iter = tree.begin(); iter != tree.end(); iter++)
		{
			(*iter)->Eval(pContext);
			std::cout << "value = " << pContext->m_value << ", oper = " << pContext->m_operator << std::endl;
		}
		return pContext->m_value;
	}
};

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

void InterpretModeTest()
{
	Calculator* pc = new Calculator;
	std::cout << "1+4+2 = " << pc->Calc("1+4+2") << std::endl;
}