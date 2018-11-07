#ifndef __OFLOAT_HPP
#define __OFLOAT_HPP

#include "IOperand.hpp"

class Ofloat : public IOperand
{
	private:
		double			_value;
		std::string		_str;
		
		Ofloat();

	public:
		virtual int				getPrecision( void ) const;
		virtual eOperandType	getType( void ) const;

		virtual IOperand const * operator+( IOperand const & rhs ) const;
		virtual IOperand const * operator-( IOperand const & rhs ) const;
		virtual IOperand const * operator*( IOperand const & rhs ) const;
		virtual IOperand const * operator/( IOperand const & rhs ) const;
		virtual IOperand const * operator%( IOperand const & rhs ) const;

		virtual std::string const & toString( void ) const;

		virtual ~Ofloat( void ) {}

		Ofloat(double nb);
		Ofloat(Ofloat const & nb);
		Ofloat& operator=(Ofloat const & nb);
		double				getValue() const;
};

#endif
