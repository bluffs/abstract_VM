#include <string>
#include <cmath>
#include <sstream>

#include "Ofloat.hpp"
#include "tools.hpp"

Ofloat::Ofloat()
{
}

Ofloat::Ofloat(double nb) :
	_value(nb)
{
	std::stringstream	ss;
	ss << nb;
	_str = ss.str();
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

IOperand const *	Ofloat::operator-(IOperand const & rhs) const
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

IOperand const *	Ofloat::operator*(IOperand const & rhs) const
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

IOperand const *	Ofloat::operator/(IOperand const & rhs) const
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

IOperand const *	Ofloat::operator%(IOperand const & rhs) const
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

std::string const &	Ofloat::toString() const
{
	return (_str);
}
