#include <iostream>
#include <fstream>
#include <sstream>

#include "Container.hpp"
#include "IOperand.hpp"
#include "Program.hpp"

int main(int argc, char** argv)
{
	Container	con;
	Program		prog;
	std::string	filename;

	if (argc > 3)
	{
		std::cout << "Usage : ./abstract_vm [-i][filename]" << std::endl;
		return (1);
	}
	if (argc == 3)
	{
		std::string arg(argv[1]);
		if (arg == "-i")
			prog.setI(true);
		else
		{
			std::cout << "Usage : ./abstract_vm [-i][filename]" << std::endl;
			return (1);
		}
		filename = argv[2];
	}
	if (argc == 2)
		filename = argv[1];
	if (argc != 1)
	{
		std::ifstream file(filename);
		std::string	line;
		while (getline(file, line))
		{
			prog.push(line);
		}
	}
	else
	{
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
		prog.programExit();
		return 1;
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
