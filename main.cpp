#include <iostream>

#include "Container.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"

int main()
{
	Container	con;
	Int8		*num = new Int8(5);
	Int8		*num2 = new Int8(7);
	Int8		*num3 = new Int8(23);

	con.push(num);
	con.push(num2);
	con.push(num3);
	con.dump();
	return 0;
}
