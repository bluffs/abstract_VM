#include <string>
#include <cmath>
#include <sstream>

#include "Int8.hpp"
#include "tools.hpp"

Int8::Int8()
{
}

Int8::Int8(double nb) :
	_value(nb)
{
	std::stringstream ss;
	ss << nb;
	_str = ss.str();
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
	double val = std::stod(rhs.toString());

	val += _value;
	if (getType() >= rhs.getType())
	{
		return (_fact.createOperand(getType(), std::to_string(val)));
	}
	else
	{
		return (_fact.createOperand(rhs.getType(), std::to_string(val)));
	}
}

IOperand const *	Int8::operator-(IOperand const & rhs) const
{
	double val = std::stod(rhs.toString());

	val -= _value;
	if (getType() >= rhs.getType())
	{
		return (_fact.createOperand(getType(), std::to_string(val)));
	}
	else
	{
		return (_fact.createOperand(rhs.getType(), std::to_string(val)));
	}
}

IOperand const *	Int8::operator*(IOperand const & rhs) const
{
	double val = std::stod(rhs.toString());

	val *= _value;
	if (getType() >= rhs.getType())
	{
		return (_fact.createOperand(getType(), std::to_string(val)));
	}
	else
	{
		return (_fact.createOperand(rhs.getType(), std::to_string(val)));
	}
}

IOperand const *	Int8::operator/(IOperand const & rhs) const
{
	double val = std::stod(rhs.toString());

	// if val == 0 throw exception
	val /= _value;
	if (getType() >= rhs.getType())
	{
		return (_fact.createOperand(getType(), std::to_string(val)));
	}
	else
	{
		return (_fact.createOperand(rhs.getType(), std::to_string(val)));
	}
}

IOperand const *	Int8::operator%(IOperand const & rhs) const
{
	double val = std::stod(rhs.toString());

	//if val == 0 throw exception
	val = fmod(_value, val);
	if (getType() >= rhs.getType())
	{
		return (_fact.createOperand(getType(), std::to_string(val)));
	}
	else
	{
		return (_fact.createOperand(rhs.getType(), std::to_string(val)));
	}
}

std::string const &	Int8::toString() const
{
	return (_str);
}
