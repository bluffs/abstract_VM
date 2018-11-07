#ifndef __ODOUBLE_HPP
#define __ODOUBLE_HPP

#include "IOperand.hpp"

class Odouble : public IOperand
{
	private:
		double			_value;
		std::string		_str;
		
		Odouble();

	public:
		virtual int				getPrecision( void ) const;
		virtual eOperandType	getType( void ) const;

		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

		virtual ~Odouble( void ) {}

		Odouble(double nb);
		Odouble(Odouble const & nb);
		Odouble& operator=(Odouble const & nb);
		double				getValue() const;
};

#endif
