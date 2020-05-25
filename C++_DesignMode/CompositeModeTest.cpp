
#include "ExpressNode.h"
#include "ValueNode.h"
#include "UnaryNode.h"
#include "BinaryNode.h"
#include "Express.h"

void CompositeModeTest()
{
	Express t = Express(3);
	t = Express('+', t, 12);
	std::cout << t << " = "<< t.eval() << std::endl;

	Express y = Express('-', 4);
	std::cout << y << "=" << y.eval() << std::endl;

	Express t1 = Express('*', Express('-', 5), Express('+', 3, 4));
	std::cout << t1 << "=" << t1.eval() << std::endl;
}