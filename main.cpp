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
	Int8		num4(*num);
	const	Int8		*num5 = dynamic_cast<const Int8*>(*num3 + *num2);
	const	Int8		*num6 = dynamic_cast<const Int8*>(*num5 - *num);
	const	Int8		*num7 = dynamic_cast<const Int8*>(*num2 * *num2);
	const	Int8		*num8 = dynamic_cast<const Int8*>(*num5 / *num);
	if (num5 == NULL)
		std::cout << "cast is null" << std::endl;

	con.push(num);
	con.push(num2);
	con.push(num3);
	con.push(&num4);
	con.push(num5);
	con.push(num6);
	con.push(num7);
	con.push(num8);
	con.dump();
	return 0;
}
