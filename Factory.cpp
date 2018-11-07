#include "string"
#include "Factory.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Ofloat.hpp"
#include "Odouble.hpp"

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
	try
	{
		nb = std::stoi(value);
		if (nb > 127 || nb < -128)
			throw(std::exception());
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	Int8	*num = new Int8(nb);
	return num;
}

IOperand const *	Factory::createInt16( std::string const & value ) const
{
	int nb = 0;
	try
	{
		nb = std::stoi(value);
		if (nb > 32767 || nb < -32768)
			throw(std::exception());
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	Int16	*num = new Int16(nb);
	return num;
}

IOperand const *	Factory::createInt32( std::string const & value ) const
{
	int nb = 0;
	try
	{
		nb = std::stoi(value);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	Int32	*num = new Int32(nb);
	return num;
}

IOperand const *	Factory::createFloat( std::string const & value ) const
{
	float nb = 0;
	try
	{
		nb = std::stof(value);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	Ofloat	*num = new Ofloat(nb);
	return num;
}

IOperand const *	Factory::createDouble( std::string const & value ) const
{
	double nb = 0;
	try
	{
		nb = std::stod(value);
	}
	catch(std::exception &e)
	{
		std::cout << e.what();
	}
	Odouble	*num = new Odouble(nb);
	return num;
}
