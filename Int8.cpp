#include <string>

#include "Int8.hpp"
#include "tools.hpp"

Int8::Int8()
{
}

Int8::Int8(int nb) :
	_value(nb),
	_str(std::to_string(nb))
{
	std::cout << "int8 constructor value = " << _value << std::endl;
}

long	Int8::getValue()
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
	if (rhs.getPrecision() > getPrecision())
		return (rhs + *this);
	Int8 *ope = new Int8;
	*ope = *this;
	long value = stol(rhs.toString());
	ope->_value += value;
	ope->_str = std::to_string(ope->_value);
	return ope;
}

IOperand const *	Int8::operator-(IOperand const & rhs) const
{
	if (rhs.getPrecision() > getPrecision())
		return (rhs + *this);
	Int8 *ope = new Int8;
	*ope = *this;
	long value = stol(rhs.toString());
	ope->_value -= value;
	ope->_str = std::to_string(ope->_value);
	return ope;
}

IOperand const *	Int8::operator*(IOperand const & rhs) const
{
	if (rhs.getPrecision() > getPrecision())
		return (rhs + *this);
	Int8 *ope = new Int8;
	*ope = *this;
	long value = stol(rhs.toString());
	ope->_value *= value;
	ope->_str = std::to_string(ope->_value);
	return ope;
}

IOperand const *	Int8::operator/(IOperand const & rhs) const
{
	if (rhs.toString() == "0")
		throw(std::exception()); // create an exception for division by 0
	if (rhs.getPrecision() > getPrecision())
	{
		if (getType)
		// create an instance of rhs with value = this / rhs
	}
	Int8 *ope = new Int8;
	*ope = *this;
	long value = stol(rhs.toString());
	ope->_value *= value;
	ope->_str = std::to_string(ope->_value);
	return ope;

}

IOperand const *	Int8::operator%(IOperand const & rhs) const
{
	return this;
}

std::string const &	Int8::toString() const
{
	return (_str);
}