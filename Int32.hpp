#ifndef __INT32_HPP
#define __INT32_HPP

#include "IOperand.hpp"

class Int32 : public IOperand
{
	private:
		double			_value;
		std::string		_str;
		
		Int32();

	public:
		virtual int				getPrecision( void ) const;
		virtual eOperandType	getType( void ) const;

		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

		virtual ~Int32( void ) {}

		Int32(double nb);
		Int32(Int32 const & nb);
		Int32& operator=(Int32 const & nb);
		double				getValue() const;
};

#endif
