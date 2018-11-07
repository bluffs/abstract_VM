#include "Program.hpp"

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
	_inst.push_back(line);
}

void	Program::execute()
{
	
}
