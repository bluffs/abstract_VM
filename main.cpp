#include <iostream>
#include <fstream>
#include <sstream>

#include "Container.hpp"
#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Program.hpp"

int main(int argc, char** argv)
{
	Container	con;

	if (argc > 2)
	{
		std::cout << "Usage : ./abstract_vm [filename]" << std::endl;
	}
	Program	prog;
	if (argc == 2)
	{
		std::ifstream file(argv[1]);
		std::string	line;
		while (getline(file, line))
		{
			prog.push(line);
		}
	}
	else
	{
		//read from standard input
		std::string	line;
		while (getline(std::cin, line))
		{
			if (line == ";;")
				break;
			prog.push(line);
		}
	}
	try
	{
		prog.check();
	}
	catch(std::exception &e)
	{
		std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
		prog.programExit();
		return 0;
	}
	try
	{
		prog.executeAll();
	}
	catch(std::exception &e)
	{
		std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}
	return 0;
}
