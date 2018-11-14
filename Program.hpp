#ifndef __PROGRAM_HPP
#define __PROGRAM_HPP

#include <vector>
#include <string>
#include "Container.hpp"
#include "Factory.hpp"

class Program
{
	private:
		std::vector<std::string>	_inst;
		Container					_cont;
		Factory						_factory;
	
	public:
		Program();
		Program(Program const &);
		~Program();
		Program&	operator=(Program const &);

		void			push(std::string);
		void			executeAll();
		void			executeLine(std::string & str);

	class BadInstructionException : public std::exception
	{
		public:
			BadInstructionException();
			virtual ~BadInstructionException() throw();
			virtual const char* what() const throw();
	};
};

#endif
