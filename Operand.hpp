#ifndef __OPERAND_HPP
#define __OPERAND_HPP

#include <cmath>
#include <sstream>

#include "IOperand.hpp"
#include "Factory.hpp"
#include "tools.hpp"

template <typename T>
class Operand : public IOperand
{
	private:
		T				_value;
		int				_precision;
		std::string		_str;
		Factory			_fact;
		eOperandType	_type;

		Operand()
		{}
		
		Operand(Operand const & nb)
		{
			*this = nb;
		}

		Operand& operator=(Operand const & nb)
		{
			_value = nb._value;
			_str = nb._str;
			return *this;
		}

	public:
		virtual int				getPrecision( void ) const
		{
			return _precision;
		}

		virtual	eOperandType	getType( void ) const
		{
			return _type;
		}

		virtual IOperand const * operator+( IOperand const & rhs ) const
		{
			double val = std::stod(rhs.toString());

			//std::cout << val << " + " << _value;
			val += _value;
			//std::cout << " = " << val << std::endl;
			if (getType() >= rhs.getType())
			{
				return (_fact.createOperand(getType(), std::to_string(val)));
			}
			else
			{
				return (_fact.createOperand(rhs.getType(), std::to_string(val)));
			}
		}

		virtual IOperand const * operator-( IOperand const & rhs ) const
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

		virtual IOperand const * operator*( IOperand const & rhs ) const
		{
			double val = std::stod(rhs.toString());

			//std::cout << val << " * " << _value;
			val *= _value;
			//std::cout << " = " << val << std::endl;
			if (getType() >= rhs.getType())
			{
				return (_fact.createOperand(getType(), std::to_string(val)));
			}
			else
			{
				return (_fact.createOperand(rhs.getType(), std::to_string(val)));
			}

		}

		virtual IOperand const * operator/( IOperand const & rhs ) const
		{
			// if val == 0 throw exception
			double val = std::stod(rhs.toString());

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

		virtual IOperand const * operator%( IOperand const & rhs ) const
		{
			// if val == 0 throw exception
			double val = std::stod(rhs.toString());

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

		virtual std::string const & toString( void ) const
		{
			return (_str);
		}

		virtual ~Operand( void )
		{}

		Operand(T nb, int precision, eOperandType type) : 
			_precision(precision),
			_type(type),
			_value(nb)
		{
			std::stringstream ss;
			if (_type == eInt8)
				ss << static_cast<int>(nb);
			else
				ss << nb;
			_str = ss.str();
			//std::cout << "str = " << _str << std::endl;
		}
};

#endif
