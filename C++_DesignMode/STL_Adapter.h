
#ifndef __STL_ADAPTER_H__
#define __STL_ADAPTER_H__

#include <iostream>
#include <deque>
#include <stack>

void STL_AdapterModeTest()
{
	std::deque<int> myDeq(3, 100);
	std::stack<int> myStack;
	std::stack<int> myStack2(myDeq);
	std::cout << "myStack Size" << (int)myStack.size() << std::endl;
	std::cout << "myStack2 Size" << (int)myStack2.size() << std::endl;
}


#endif // !__STL_ADAPTER_H__

