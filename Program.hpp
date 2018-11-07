#ifndef __PROGRAM_HPP
#define __PROGRAM_HPP

#include <vector>
#include <string>
#include "Container.hpp"

class Program
{
	private:
		std::vector<std::string>	_inst;
		Container					_cont
	
	public:
		Program();
		Program(Program const &);
		~Program();
		Program&	operator=(Program const &);

		void			push(std::string);
		void			execute();
};

#endif
