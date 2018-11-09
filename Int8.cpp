#include <string>
#include <cmath>

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "tools.hpp"

Int8::Int8()
{
}

Int8::Int8(double nb) :
	_value(nb),
	_str(std::to_string(nb))
{
	std::cout << "int8 constructor value = " << _value << std::endl;
}

double	Int8::getValue() const
{
	return _value;
}

Int8::Int8(Int8 const & nb)
{
	*this = nb;
}

Int8& Int8::operator=(Int8 const & nb)
{
	_value = nb._value;
	_str = nb._str;
	return *this;
}

int		Int8::getPrecision( void ) const
{
	return 8;
}

eOperandType	Int8::getType() const
{
	return eInt8;
}

IOperand const *	Int8::operator+(IOperand const & rhs) const
{
	if (rhs.getType() == eInt8)
	{
		//std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Int8	*num2 = new Int8(getValue() + num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		//std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Int16	*num2 = new Int16(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		//std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Int32	*num2 = new Int32(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}

	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;

	return this;
}

IOperand const *	Int8::operator-(IOperand const & rhs) const
{
	std::cout << rhs.getType() << std::endl;
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Int8	*num2 = new Int8(getValue() - num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Int16	*num2 = new Int16(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Int32	*num2 = new Int32(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;
	// create an instance of rhs with value = this / rhs

	return this;
}

IOperand const *	Int8::operator*(IOperand const & rhs) const
{
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Int8	*num2 = new Int8(getValue() * num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Int16	*num2 = new Int16(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Int32	*num2 = new Int32(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;

	return this;
}

IOperand const *	Int8::operator/(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0

	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Int8	*num2 = new Int8(getValue() / num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Int16	*num2 = new Int16(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Int32	*num2 = new Int32(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;


	return this;
}

IOperand const *	Int8::operator%(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0

	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Int8	*num2 = new Int8(fmod(getValue(), num.getValue()));
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Int16	*num2 = new Int16(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Int16	*num2 = new Int16(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;
	return this;
}

std::string const &	Int8::toString() const
{
	return (_str);
}
