#ifndef __INT8_HPP
#define __INT8_HPP

#include "IOperand.hpp"

class Int8 : public IOperand
{
	private:
		long			_value;
		std::string		_str;
		
		Int8();

	public:
		virtual int				getPrecision( void ) const;
		virtual eOperandType	getType( void ) const;

		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

		virtual ~Int8( void ) {}

		Int8(int nb);
		Int8(Int8 const & nb);
		Int8& operator=(Int8 const & nb);
		long				getValue();
};

#endif
