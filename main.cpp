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
		//prog.check();
	}
	else
	{
		//read from standard input
	}
	prog.executeAll();
	return 0;
}
