#ifndef __INT32_HPP
#define __INT32_HPP

#include "IOperand.hpp"
#include "Factory.hpp"

class Int32 : public IOperand
{
	private:
		int				_value;
		std::string		_str;
		Factory			_fact;
		
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
