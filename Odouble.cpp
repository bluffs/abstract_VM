#include <string>
#include <cmath>
#include <sstream>

#include "Odouble.hpp"
#include "tools.hpp"

Odouble::Odouble()
{
}

Odouble::Odouble(double nb) :
	_value(nb)
{	
	std::stringstream	ss;
	ss << nb;
	_str = ss.str();
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

IOperand const *	Odouble::operator-(IOperand const & rhs) const
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

IOperand const *	Odouble::operator*(IOperand const & rhs) const
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

IOperand const *	Odouble::operator/(IOperand const & rhs) const
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

IOperand const *	Odouble::operator%(IOperand const & rhs) const
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

std::string const &	Odouble::toString() const
{
	return (_str);
}
