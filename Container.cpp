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

void	Container::push(IOperand *op)
{
	_vector.insert(_vector.begin(), op);
}

void	Container::push(const IOperand *op)
{
	_vector.insert(_vector.begin(), op);
}

void	Container::pop()
{
	//throw exception empty stack
	if (_vector.empty())
	{}
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
	//throw exception empty stack
	if (op->getType() != _vector[0]->getType())
		//throw exception diff types
	{}
	if (op->toString() != _vector[0]->toString())
		//throw exception diff values
	{}
}

void	Container::add()
{
	//thorw exception stack too small
	if (_vector.size() < 2)
	{}
	IOperand const *	ope = *_vector[0] + *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::sub()
{
	//thorw exception stack too small
	if (_vector.size() < 2)
	{}
	IOperand const *	ope = *_vector[0] - *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::mul()
{
	//thorw exception stack too small
	if (_vector.size() < 2)
	{}
	IOperand const *	ope = *_vector[0] * *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::div()
{
	//thorw exception stack too small
	if (_vector.size() < 2)
	{}
	//throw exception if _vector[2] == 0
	IOperand const *	ope = *_vector[0] / *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::mod()
{
	//thorw exception stack too small
	if (_vector.size() < 2)
	{}
	//throw exception if _vector[2] == 0
	IOperand const *	ope = *_vector[0] % *_vector[1];
	pop();
	pop();
	push(ope);
}

void	Container::print()
{
	//throw exception if empty stack
	if (_vector[0]->getType() != eInt8)
		//throw exception not an int8
	{}
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
