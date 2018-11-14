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
		_inst.push_back(prog._inst[i]);
	}	
	return *this;
}

Program::~Program()
{
}

void	Program::push(std::string line)
{
	std::regex	reg("([^;]*){1}[;]?");
	std::smatch	match;
	if (regex_search(line, match, reg) && match.str(1) != "")
	{
		_inst.push_back(match.str(1));
	}
}

void	Program::executeAll()
{
	size_t	size = _inst.size();
	for (size_t i = 0; i < size; i++)
	{
		try
		{
			executeLine(_inst[i]);
		}
		catch(std::exception &e)
		{
			std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
}

void	Program::executeLine(std::string & str)
{
	std::regex reg("([a-z]*)[[ ]?(.*)]*");
	std::smatch match;

	if (regex_search(str, match, reg))
	{
		if (match.str(1) == "push")
		{
			eOperandType	type;
			std::regex reg2("([^\\(]*)[\\()]{1}(.*)[\\)]{1}");
			std::smatch match2;
			if (regex_search(match.str(2), match2, reg2))
			{
				if (match2.str(1) == "int8")
					type = eInt8;
				else if (match2.str(1) == "int16")
					type = eInt16;
				else if (match2.str(1) == "int32")
					type = eInt32;
				else if (match2.str(1) == "float")
					type = eFloat;
				else if (match2.str(1) == "double")
					type = eDouble;
			}
			_cont.push(_factory.createOperand(type, match2.str(2)));
		}
		else if (match.str(1) == "pop")
			_cont.pop();
		else if (match.str(1) == "dump")
			_cont.dump();
		else if (match.str(1) == "assert")
		{
			eOperandType	type;
			std::regex reg2("([^\\(]*)[\\()]{1}(.*)[\\)]{1}");
			std::smatch match2;
			if (regex_search(match.str(2), match2, reg2))
			{
				if (match2.str(1) == "int8")
					type = eInt8;
				else if (match2.str(1) == "int16")
					type = eInt16;
				else if (match2.str(1) == "int32")
					type = eInt32;
				else if (match2.str(1) == "float")
					type = eFloat;
				else if (match2.str(1) == "double")
					type = eDouble;
			}
			_cont.assert(_factory.createOperand(type, match2.str(2)));

		}
		else if (match.str(1) == "add")
			_cont.add();
		else if (match.str(1) == "sub")
			_cont.sub();
		else if (match.str(1) == "mul")
			_cont.mul();
		else if (match.str(1) == "div")
			_cont.div();
		else if (match.str(1) == "mod")
			_cont.mod();
		else if (match.str(1) == "print")
			_cont.print();
		else if (match.str(1) == "exit")
			_cont.exit();
		else
		{
			std::cout << "match1 = " << match.str(1) << " match2 = " << match.str(2) << std::endl;
			throw(BadInstructionException());
		}
	}
	else
	{
		std::cout << "NO REGEX MATCH" << std::endl;
		//throw exception
	}
}

Program::BadInstructionException::BadInstructionException()
{
}

Program::BadInstructionException::~BadInstructionException() throw()
{
}

const char*	Program::BadInstructionException::what() const throw()
{
	return ("Bad instruction");
}
