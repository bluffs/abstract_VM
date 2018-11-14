#include "iterator"
#include "Container.hpp"
#include <iostream>
#include "Int8.hpp"

Container::Container()
{
}

Container::Container(Container const & con)
{
}

void	Container::push(const IOperand *op)
{
	_vector.insert(_vector.begin(), op);
}

void	Container::pop()
{
	if (_vector.empty())
	{
		throw(EmptyStackException());
	}
	_vector.erase(_vector.begin());
}

void	Container::dump()
{
	for (auto it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void	Container::assert(const IOperand *op)
{
	if (_vector.empty())
	{
		throw(EmptyStackException());
	}
	if (op->getType() != _vector[0]->getType())
	{
		throw(BadTypeException());
	}
	if (op->toString() != _vector[0]->toString())
	{
		throw(BadAssertException());
	}
}

void	Container::add()
{
	if (_vector.size() < 2)
	{
		throw(SmallStackException());
	}
	IOperand const *	ope = *_vector[0] + *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::sub()
{
	if (_vector.size() < 2)
	{
		throw(SmallStackException());
	}
	IOperand const *	ope = *_vector[0] - *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::mul()
{
	if (_vector.size() < 2)
	{
		throw(SmallStackException());
	}
	IOperand const *	ope = *_vector[0] * *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::div()
{
	if (_vector.size() < 2)
	{
		throw(SmallStackException());
	}
	if (_vector[1]->toString() == "0")
		throw(DivisionZeroException());
	IOperand const *	ope = *_vector[0] / *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::mod()
{
	if (_vector.size() < 2)
	{
		throw(SmallStackException());
	}
	if (_vector[1]->toString() == "0")
		throw(DivisionZeroException());
	IOperand const *	ope = *_vector[0] % *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::print()
{
	if (_vector.empty())
	{
		throw(EmptyStackException());
	}
	if (_vector[0]->getType() != eInt8)
	{
		throw(BadTypeException());
	}
	char c = stoi(_vector[0]->toString()) ;
	std::cout << c << std::endl;
}

void	Container::exit()
{
	//delete all Operand
}

Container::~Container()
{
}

Container::EmptyStackException::EmptyStackException()
{
}

Container::EmptyStackException::~EmptyStackException() throw()
{
}

const char*	Container::EmptyStackException::what() const throw()
{
	return ("Instruction on an empty stack");
}

Container::SmallStackException::SmallStackException()
{
}

Container::SmallStackException::~SmallStackException() throw()
{
}

const char*	Container::SmallStackException::what() const throw()
{
	return ("Stack is too small");
}

Container::BadTypeException::BadTypeException()
{
}

Container::BadTypeException::~BadTypeException() throw()
{
}

const char*	Container::BadTypeException::what() const throw()
{
	return ("Bad type");
}

Container::DivisionZeroException::DivisionZeroException()
{
}

Container::DivisionZeroException::~DivisionZeroException() throw()
{
}

const char*	Container::DivisionZeroException::what() const throw()
{
	return ("Division by 0");
}

Container::BadAssertException::BadAssertException()
{
}

Container::BadAssertException::~BadAssertException() throw()
{
}

const char*	Container::BadAssertException::what() const throw()
{
	return ("Bad Assert");
}
