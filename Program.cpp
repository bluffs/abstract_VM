#include "Program.hpp"
#include <regex>

Program::Program()
{
}

Program::Program(Program const & prog)
{
	*this = prog;
}

Program& Program::operator=(Program const & prog)
{
	size_t	size = prog._inst.size();
	for (size_t i = 0; i < size; i++)
	{
		_inst.push_back(prog._inst[i];
	}	
	return *this;
}

Program::~Program()
{
}

void	Program::push(std::string line)
{
	std::regex	re("([^;]*){1}[;]?");
	std::match	match;
	if (regex_search(line, match, reg))
	{
		_inst.push_back(match.str(1));
	}
	else
	{
		//throw exception
	}
}

void	Program::executeAll()
{
	size_t	size = _inst.size();
	for (size_t i = 0; i < size; i++)
	{
		executeLine(_inst[i]);
	}
}

void	Program::executeLine(std::string & str)
{
	std::regex reg("([a-z]*)[[ ]?(.*)]*");	
	std::match match;

	if (str[0] == ;)
	{
		return ;
	}
	if (regex_search(str, match, reg))
	{
		if (match.str(1) == "push")
			//container.push
		else if (match.str(1) == "pop")
			//container.pop
	}
	else
	{
		//throw exception
	}
}
