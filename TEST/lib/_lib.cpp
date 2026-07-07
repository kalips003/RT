#include "_lib.hpp"

std::string	ft_print_cat()
{
	std::string string;
	std::cout << BLINK << "\n\t< enter >\n" << R_BLINK << std::endl;
	if (!std::getline(std::cin, string))
		std::cin.clear();
	return string;
}

