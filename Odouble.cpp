#include <string>
#include <cmath>

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Ofloat.hpp"
#include "tools.hpp"

Ofloat::Ofloat()
{
}

Ofloat::Ofloat(double nb) :
	_value(nb),
	_str(std::to_string(nb))
{
	std::cout << "Ofloat constructor value = " << _value << std::endl;
}

double	Ofloat::getValue() const
{
	return _value;
}

Ofloat::Ofloat(Ofloat const & nb)
{
	*this = nb;
}

Ofloat& Ofloat::operator=(Ofloat const & nb)
{
	_value = nb._value;
	_str = nb._str;
	return *this;
}

int		Ofloat::getPrecision( void ) const
{
	return 32;
}

eOperandType	Ofloat::getType() const
{
	return eFloat;
}

IOperand const *	Ofloat::operator+(IOperand const & rhs) const
{
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() + num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;

	return this;
}

IOperand const *	Ofloat::operator-(IOperand const & rhs) const
{
	std::cout << rhs.getType() << std::endl;
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() - num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() - num.getValue());
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

IOperand const *	Ofloat::operator*(IOperand const & rhs) const
{
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() * num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() * num.getValue());
		//if overflow throw
		return num2;

	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;

	return this;
}

IOperand const *	Ofloat::operator/(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0

	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() / num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() / num.getValue());
		//if overflow throw
		return num2;

	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;

	return this;
}

IOperand const *	Ofloat::operator%(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0

	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Ofloat	*num2 = new Ofloat(fmod(getValue(), num.getValue()));
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Ofloat	*num2 = new Ofloat(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Ofloat	*num2 = new Ofloat(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
		std::cout << "create a float" << std::endl;
	if (getType() == eDouble)
		std::cout << "create a double" << std::endl;

	return this;
}

std::string const &	Ofloat::toString() const
{
	return (_str);
}
