#ifndef __INT16_HPP
#define __INT16_HPP

#include "IOperand.hpp"

class Int16 : public IOperand
{
	private:
		double			_value;
		std::string		_str;
		
		Int16();

	public:
		virtual int				getPrecision( void ) const;
		virtual eOperandType	getType( void ) const;

		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

		virtual ~Int16( void ) {}

		Int16(double nb);
		Int16(Int16 const & nb);
		Int16& operator=(Int16 const & nb);
		double				getValue() const;
};

#endif
