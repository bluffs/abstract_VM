#include <stdexcept>
#include <limits>
#include "string"
#include "Factory.hpp"
#include "Operand.hpp"

Factory::Factory()
{}

Factory::~Factory()
{}

IOperand const *	Factory::createOperand( eOperandType type, std::string const & value ) const
{
	if (type == eInt8)
		return createInt8(value);
	else if (type == eInt16)
		return createInt16(value);
	else if (type == eInt32)
		return createInt32(value);
	else if (type == eFloat)
		return createFloat(value);
	else
		return createDouble(value);
}

IOperand const *	Factory::createInt8( std::string const & value ) const
{
	int nb = 0;
	if (value == "max")
		nb = SCHAR_MAX;
	else if (value == "min")
		nb = SCHAR_MIN;
	else
	{
		//std::cout << "int8 : value = " << value << std::endl;
		nb = std::stoi(value);
		//std::cout << "stoi ok" << std::endl;
		if (nb > 127 || nb < -128)
			throw(std::out_of_range("Overflow"));
	}
	Operand<char>	*num = new Operand<char>(nb, 0, eInt8);
	return num;
}

IOperand const *	Factory::createInt16( std::string const & value ) const
{
	short int nb = 0;
	if (value == "max")
		nb = SHRT_MAX;
	else if (value == "min")
		nb = SHRT_MIN;
	else
	{
		//std::cout << "int16 : value = " << value << std::endl;
		nb = std::stoi(value);
		//std::cout << "stoi ok" << std::endl;
		if (nb > 32767 || nb < -32768)
			throw(std::out_of_range("Overflow"));
	}
	Operand<short int>	*num = new Operand<short int>(nb, 0, eInt16);
	return num;
}

IOperand const *	Factory::createInt32( std::string const & value ) const
{
	int nb = 0;
	if (value == "max")
		nb = INT_MAX;
	else if (value == "min")
		nb = INT_MIN;
	else
	{
		//std::cout << "int32 : value = " << value << std::endl;
		nb = std::stoi(value);
		//std::cout << "stoi ok" << std::endl;
	}
	Operand<int>	*num = new Operand<int>(nb, 0, eInt32);
	return num;
}

IOperand const *	Factory::createFloat( std::string const & value ) const
{
	float nb = 0;
	if (value == "max")
		nb = std::numeric_limits<float>::max();
	else if (value == "min")
		nb = std::numeric_limits<float>::min();
	else
		nb = std::stof(value);
	Operand<float>	*num = new Operand<float>(nb, 7, eFloat);
	return num;
}

IOperand const *	Factory::createDouble( std::string const & value ) const
{
	double nb = 0;
	if (value == "max")
		nb = std::numeric_limits<double>::max();
	else if (value == "min")
		nb = std::numeric_limits<double>::min();
	else
		nb = std::stod(value);
	Operand<double>	*num = new Operand<double>(nb, 16, eDouble);
	return num;
}
