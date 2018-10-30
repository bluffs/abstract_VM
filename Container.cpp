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
	//Int8*	val = new Int8;
	//_stack.push(val);
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
	//std::cout << "Container dump" << std::endl;
	//std::cout << "size = " << _vector.size() << std::endl;
	/*for (unsigned int i = 0; i < _stack.size(); i++)
	{
		std::cout << _stack.top()->toString() << std::endl;
	}*/
	//std::stack<IOperand*>::iterator it = std::stack<IOperand*>::c.begin();
	//auto it2 = std::stack<IOperand*>::c.end();
	/*if (it == it2)
	{
		std::cout << "equal" << std::endl;
	}*/
	//std::cout << "begin = " << it << std::endl << "end = " << it2 << std::endl;
	for (auto it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << (*it)->toString() << std::endl;
		//std::cout << "hi" << std::endl;
	}
}

void	Container::assert(IOperand op)
{
	//throw exception no assert
	if (op != _vector.begin())
	{}
}

void	Container::add()
{
	//thorw exception stack too small
	if (_vector.size() < 2)
	{}
	//add the 2 first elems of the vector
	//pop 2 times
	//add the new elem
}

Container::~Container()
{
}
