#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <vector>
#include "IOperand.hpp"
#include "Factory.hpp"

class Container
{
	private:
		std::vector<const IOperand*>	_vector;
		Factory							_factory;

	public:
		Container();
		Container(Container const & con);
		Container& operator=(Container const & con);
		~Container();

		void	push(IOperand *op);
		void	push(const IOperand *op);
		void	pop();
		void	dump();
		void	assert(const IOperand *op);
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();
		void	print();
		void	exit();
};

#endif
