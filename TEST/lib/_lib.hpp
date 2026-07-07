#ifndef _LIB_HPP
#define _LIB_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
	#include <iostream>
// std::cin; std::cout; std::cerr; std::endl
	#include <string>
// std::string
	// #include <vector>
// std::vector (not allowed until Module 08)
	// #include <map>
// std::map (not allowed until Module 08)
	// #include <set>
// std::set (not allowed until Module 08)
	// #include <algorithm>
// std::sort; std::find; std::for_each (not allowed until Module 08)
	// #include <cstdlib>
// std::malloc; std::free; std::rand; std::exit
	// #include <cmath>
// std::abs; std::sqrt; std::pow
	// #include <iomanip>
// std::setprecision; std::fixed
	#include <sstream> //	string stream
// std::stringstream; std::istringstream; std::ostringstream
	// #include <utility>
// std::pair; std::make_pair
	// #include <cassert>
// std::assert
	// #include <cctype>
// std::isdigit(int c); std::toupper(int c)
	// #include <limits>
// use: std::numeric_limits<type>::min(); std::numeric_limits<type>::max(); std::numeric_limits<type>::epsilon();

	#include <cstdlib>
// for rand() and srand()
	#include <ctime> // 	for time()
// std::time; std::clock
	#include <typeinfo>
// 	typeid(val1).name(); typeid(val) or typeid(T)> std::type_info
///////////////////////////////////////////////////////////////////////////////]
// 									MY_LIBs
#include "_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									FUNCTIONS
/// 	ft_print_cat (c1, c2, c3, ...)
/**
 * @brief Print cat with given 3 colors, 1 int, 1 string
 * @param num the int to track.
 * @param string the cat call.
 * @param bit Bitmask:

 * - `bit[., ., 1]`: Stops and wait for a key press
 * *
 * - `bit[., 1, .]`: Clears the screen
 * *
 * - `bit[1, ., .]`: Returns the input user
 * *
 * - `bit[1, ., ., .]`: Resets
 * 
 * @return the 3rd color with or without RESET.*/
template <typename T1, typename T2>
std::string	ft_print_cat(std::string color1, std::string color2, std::string color3, T1 a, T2 b, int bit)
{
	if (bit & 0b10)
		std::cout << CLEAR;

	std::cout << color2 << "\t\tにゃ~" << color1 << "\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀" << color2 << "~ " << "" << "~ " << a << " ~" + color1 + "\n\
	\t\t⠀|、˜\\\t\t\t" + color2 + "~" << b << "~" + color1 + "\n\
	\t\t⠀じしˍ)ノ\n" << std::endl;

	if (bit & 0b1) {
		std::cout << BLINK + color3 + "\n\t< enter >\n" + R_BLINK << std::endl;
		if (!std::getline(std::cin, color3))
			std::cin.clear();
	}

	if (bit & 0b100) {
		std::cout << color3 + ":" + RESET;
		if (!std::getline(std::cin, color3))
			std::cin.clear();
	}

	if (bit & 0b1000)
		std::cout << RESET;
	return color3;
}

///////////////////////////////////////////////////////////////////////////////]
/// 	ft_print_cat (random 3)
/**
 * @brief Print cat with 3 random colors, 2 strings.
 * @param string the 2 cat calls.
 * @param bit Bitmask:

 * - `bit[., ., 1]`: Stops and wait for a key press
 * *
 * - `bit[., 1, .]`: Clears the screen
 * 
 * @return the 3rd random color.*/
template <typename S1, typename S2>
std::string	ft_print_cat(S1 stringa, S2 stringb, int bit)
{
	srand(time(NULL));

	std::stringstream ss;
	ss << (rand() % 255 + 1);
	std::string color1 = "\e[38;5;" + ss.str() + "m";
	ss.str("");
	ss << (rand() % 255 + 1);
	std::string color2 = "\e[38;5;" + ss.str() + "m";
	ss.str("");
	ss << (rand() % 255 + 1);
	std::string color3 = "\e[38;5;" + ss.str() + "m";
	
	if (bit & 0b10)
		std::cout << CLEAR;

	std::cout << color2 << "\t\tにゃ~" << color1 << "\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀" << color2 << "~ " << stringa << " ~" + color1 + "\n\
	\t\t⠀|、˜\\\t\t\t" + color2 + "~" << stringb << "~" + color1 + "\n\
	\t\t⠀じしˍ)ノ\n" << std::endl;

	if (bit & 0b1)
	{
		std::cout << BLINK + color3 + "\n\t< enter >\n" + R_BLINK;
		if (!std::getline(std::cin, color3))
			std::cin.clear();
	}
	return color3;
}

///////////////////////////////////////////////////////////////////////////////]
/**
 * @brief simple break.
 * @return the user input*/
std::string	ft_print_cat( void );

template <typename T>
void put(T value) {
	std::cout << value << std::endl;
}

#endif