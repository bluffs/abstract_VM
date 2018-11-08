#include <iostream>
#include <regex>

int main()
{
	//std::string	str("Int32(42.21)");
	//std::regex re("(.*)\\((.*)\\)");
	
	//std::string str("push int32(42)");
	std::string str(";com");
	//std::string str("add");
	//std::regex re("(.*^ )?([ ]?.*)");
	//std::regex re("([a-z]*)[[ ]?(.*)]*"); // regex for instruction + value
	std::regex	re("([^;]*){1}[;]?");

	std::smatch match;
	if (regex_search(str, match, re))
	{
		std::cout << "match found : " << match.size() << std::endl;
		if (match.size() != 3)
		{
			std::cout << "bad match" << std::endl;
			for (unsigned int i = 1; i < match.size(); i++)
			{
				std::cout << "match " << i << " : " << match.str(i) << std::endl;
			}
			return 0;
		}
		for (unsigned int i = 1; i < match.size(); i++)
		{
			std::cout << "match " << i << " : " << match.str(i) << std::endl;
		}
		if (match.str(1) == "Int8")
		{
			std::cout << "create an Int8 with value = " << match.str(2) << std::endl;
		}
		else if (match.str(1) == "Int16")
		{
			std::cout << "create an Int16 with value = " << match.str(2) << std::endl;
		}
		else if (match.str(1) == "Int32")
		{
			std::cout << "create an Int32 with value = " << match.str(2) << std::endl;
		}
	}
	return 0;
}
