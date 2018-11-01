#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <vector>
#include "IOperand.hpp"

class Container
{
	private:
		std::vector<const IOperand*>	_vector;

	public:
		Container();
		Container(Container const & con);
		Container& operator=(Container const & con);
		~Container();

		void	push(IOperand *op);
		void	push(const IOperand *op);
		void	pop();
		void	dump();
		void	assert(IOperand *op);
		void	add();
		void	sub();
		void	mul();
		void	div();
		void	mod();
		void	print();
		void	exit();
};

#endif
