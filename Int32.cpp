#include <string>
#include <cmath>
#include <sstream>

#include "Int32.hpp"
#include "tools.hpp"

Int32::Int32()
{
}

Int32::Int32(double nb) :
	_value(nb)
{
	std::stringstream	ss;
	ss << nb;
	_str = ss.str();
}

double	Int32::getValue() const
{
	return _value;
}

Int32::Int32(Int32 const & nb)
{
	*this = nb;
}

Int32& Int32::operator=(Int32 const & nb)
{
	_value = nb._value;
	_str = nb._str;
	return *this;
}

int		Int32::getPrecision( void ) const
{
	return 32;
}

eOperandType	Int32::getType() const
{
	return eInt32;
}

IOperand const *	Int32::operator+(IOperand const & rhs) const
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

IOperand const *	Int32::operator-(IOperand const & rhs) const
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

IOperand const *	Int32::operator*(IOperand const & rhs) const
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

IOperand const *	Int32::operator/(IOperand const & rhs) const
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

IOperand const *	Int32::operator%(IOperand const & rhs) const
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

std::string const &	Int32::toString() const
{
	return (_str);
}
