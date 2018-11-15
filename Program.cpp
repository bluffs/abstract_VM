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
	/*std::regex	reg("([^;]*){1}[;]?");
	std::smatch	match;
	if (regex_search(line, match, reg) && match.str(1) != "")
	{
		_inst.push_back(match.str(1));
	}*/
	_inst.push_back(line);
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
	std::smatch match;

	if (str == "")
		return ;
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
				// else throw
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
			throw(BadInstructionException());
		}
	}
	else
	{
		std::cout << "NO REGEX MATCH" << std::endl;
		//throw exception
	}
}

void			Program::checkOperand(std::string str)
{
	eOperandType	type;
	std::regex reg("([^\\(]*)[\\()]{1}(.*)[\\)]{1}");
	std::smatch match;
	const IOperand	*ope;
	if (regex_search(str, match, reg))
	{
		//std::cout << match.str(1) << std::endl;
		//std::cout << match.str(2) << std::endl;
		if (match.str(1) == "int8")
			type = eInt8;
		else if (match.str(1) == "int16")
			type = eInt16;
		else if (match.str(1) == "int32")
			type = eInt32;
		else if (match.str(1) == "float")
			type = eFloat;
		else if (match.str(1) == "double")
			type = eDouble;
		else
			throw(BadOperandException());
		ope = _factory.createOperand(type, match.str(2));
		delete ope;
	}
}

std::string		Program::checkLine(std::string str)
{
	//std::cout << str << std::endl;
	std::regex	reg("([^;]*){1}[;]?");
	std::smatch	match;
	if (regex_search(str, match, reg)/* && match.str(1) != ""*/)
	{
		if (match.str(1) == "")
			return "";
		std::regex reg2("([a-z]*)[[ ]?(.*)]*"); 
		std::smatch match2;
		if (regex_search(match.str(1), match2, reg2))
		{
			//std::cout << match2.str(1) << std::endl;
			std::string s = match2.str(1);
			if (match2.str(1) == "push" || match2.str(1) == "assert")
				checkOperand(match2.str(2));
			else if (s == "pop" || s == "dump" || s == "add" || s == "sub" || s == "mul" || 
					s == "div" || s == "mod" || s == "print" || s == "exit")
				return match.str(1);
			else
				throw(BadInstructionException());
		}
		else
			throw(BadInstructionException());
	}
	return str;
}

bool	Program::check()
{
	size_t	size = _inst.size();
	for (size_t i = 0; i < size; i++)
	{
		try
		{
			_inst[i] = checkLine(_inst[i]);
		}
		catch(std::exception &e)
		{
			_inst[i] = "";
			std::cout << "\033[1;33m" << e.what() << " on line " << i + 1 << "\033[0m" << std::endl;
		}
	}
	if (_inst[size - 1] != "exit")
		throw(NoExitException());
	return true;
}

void	Program::programExit()
{
	_cont.exit();
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

Program::NoExitException::NoExitException()
{
}

Program::NoExitException::~NoExitException() throw()
{
}

const char*	Program::NoExitException::what() const throw()
{
	return ("No exit instruction");
}

Program::BadOperandException::BadOperandException()
{
}

Program::BadOperandException::~BadOperandException() throw()
{
}

const char*	Program::BadOperandException::what() const throw()
{
	return ("Bad operand");
}
