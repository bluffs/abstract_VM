#include <string>
#include <cmath>

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Ofloat.hpp"
#include "Odouble.hpp"
#include "tools.hpp"

Odouble::Odouble()
{
}

Odouble::Odouble(double nb) :
	_value(nb),
	_str(std::to_string(nb))
{
	std::cout << "Odouble constructor value = " << _value << std::endl;
}

double	Odouble::getValue() const
{
	return _value;
}

Odouble::Odouble(Odouble const & nb)
{
	*this = nb;
}

Odouble& Odouble::operator=(Odouble const & nb)
{
	_value = nb._value;
	_str = nb._str;
	return *this;
}

int		Odouble::getPrecision( void ) const
{
	return 32;
}

eOperandType	Odouble::getType() const
{
	return eFloat;
}

IOperand const *	Odouble::operator+(IOperand const & rhs) const
{
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() + num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
	{
		std::cout << "create a float" << std::endl;
		const Ofloat	num = dynamic_cast<Ofloat const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eDouble)
	{
		std::cout << "create a double" << std::endl;
		const Odouble	num = dynamic_cast<Odouble const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() + num.getValue());
		//if overflow throw
		return num2;
	}

	return this;
}

IOperand const *	Odouble::operator-(IOperand const & rhs) const
{
	std::cout << rhs.getType() << std::endl;
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() - num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
	{
		std::cout << "create a float" << std::endl;
		const Ofloat	num = dynamic_cast<Ofloat const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eDouble)
	{
		std::cout << "create a double" << std::endl;
		const Odouble	num = dynamic_cast<Odouble const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() - num.getValue());
		//if overflow throw
		return num2;
	}

	return this;
}

IOperand const *	Odouble::operator*(IOperand const & rhs) const
{
	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() * num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
	{
		std::cout << "create a float" << std::endl;
		const Ofloat	num = dynamic_cast<Ofloat const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eDouble)
	{
		std::cout << "create a double" << std::endl;
		const Odouble	num = dynamic_cast<Odouble const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() * num.getValue());
		//if overflow throw
		return num2;
	}

	return this;
}

IOperand const *	Odouble::operator/(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0

	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() / num.getValue());
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
	{
		std::cout << "create a float" << std::endl;
		const Ofloat	num = dynamic_cast<Ofloat const &>(rhs);
		Ofloat	*num2 = new Ofloat(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}
	if (getType() == eDouble)
	{
		std::cout << "create a double" << std::endl;
		const Odouble	num = dynamic_cast<Odouble const &>(rhs);
		Odouble	*num2 = new Odouble(getValue() / num.getValue());
		//if overflow throw
		return num2;
	}

	return this;
}

IOperand const *	Odouble::operator%(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0

	if (rhs.getType() == eInt8)
	{
		std::cout << "create an Int8" << std::endl;
		const Int8 num = dynamic_cast<Int8 const &>(rhs);
		Odouble	*num2 = new Odouble(fmod(getValue(), num.getValue()));
		return num2;
	}
	if (rhs.getType() == eInt16)
	{
		std::cout << "create an int16" << std::endl;
		const Int16	num = dynamic_cast<Int16 const &>(rhs);
		Odouble	*num2 = new Odouble(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eInt32)
	{
		std::cout << "create an int32" << std::endl;
		const Int32	num = dynamic_cast<Int32 const &>(rhs);
		Odouble	*num2 = new Odouble(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eFloat)
	{
		std::cout << "create a float" << std::endl;
		const Ofloat	num = dynamic_cast<Ofloat const &>(rhs);
		Ofloat	*num2 = new Ofloat(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}
	if (getType() == eDouble)
	{
		std::cout << "create a double" << std::endl;
		const Odouble	num = dynamic_cast<Odouble const &>(rhs);
		Odouble	*num2 = new Odouble(fmod(getValue(), num.getValue()));
		//if overflow throw
		return num2;
	}

	return this;
}

std::string const &	Odouble::toString() const
{
	return (_str);
}
