#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <vector>
#include <exception>

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

	class EmptyStackException : public std::exception
	{
		public:
			EmptyStackException();
			virtual ~EmptyStackException() throw();
			virtual const char*	what() const throw();
	};

	class SmallStackException : public std::exception
	{
		public:
			SmallStackException();
			virtual ~SmallStackException() throw();
			virtual const char*	what() const throw();
	};

	class BadTypeException : public std::exception
	{
		public:
			BadTypeException();
			virtual ~BadTypeException() throw();
			virtual const char*	what() const throw();
	};

	class DivisionZeroException : public std::exception
	{
		public:
			DivisionZeroException();
			virtual ~DivisionZeroException() throw();
			virtual const char*	what() const throw();
	};

	class BadAssertException : public std::exception
	{
		public:
			BadAssertException();
			virtual ~BadAssertException() throw();
			virtual const char*	what() const throw();
	};
};

#endif
