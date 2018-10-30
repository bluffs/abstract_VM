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
int8_t	Int8::getValue()
{
	return _value;
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
	return this;
}

IOperand const *	Int8::operator-(IOperand const & rhs) const
{
	return this;
}

IOperand const *	Int8::operator*(IOperand const & rhs) const
{
	return this;
}

IOperand const *	Int8::operator/(IOperand const & rhs) const
{
	return this;
}

IOperand const *	Int8::operator%(IOperand const & rhs) const
{
	return this;
}

std::string const &	Int8::toString() const
{
	return _str;
}
