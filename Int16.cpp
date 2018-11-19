#include <string>
#include <cmath>
#include <sstream>

#include "Int16.hpp"
#include "tools.hpp"

Int16::Int16()
{
}

Int16::Int16(short int nb) :
	_value(nb)
{
	std::stringstream	ss;
	ss << nb;
	_str = ss.str();
}

double	Int16::getValue() const
{
	return _value;
}

Int16::Int16(Int16 const & nb)
{
	*this = nb;
}

Int16& Int16::operator=(Int16 const & nb)
{
	_value = nb._value;
	_str = nb._str;
	return *this;
}

int		Int16::getPrecision( void ) const
{
	return 16;
}

eOperandType	Int16::getType() const
{
	return eInt16;
}

IOperand const *	Int16::operator+(IOperand const & rhs) const
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

IOperand const *	Int16::operator-(IOperand const & rhs) const
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

IOperand const *	Int16::operator*(IOperand const & rhs) const
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

IOperand const *	Int16::operator/(IOperand const & rhs) const
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

IOperand const *	Int16::operator%(IOperand const & rhs) const
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

std::string const &	Int16::toString() const
{
	return (_str);
}
