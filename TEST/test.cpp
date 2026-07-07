#include "lib/_lib.hpp"

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
// #include <ctime>
// std::time; std::clock
// #include <iomanip>
// std::setprecision; std::fixed
// #include <sstream> //	string stream
// std::stringstream; std::istringstream; std::ostringstream
// #include <utility>
// std::pair; std::make_pair
// #include <cassert>
// std::assert
// #include <cctype>
// std::isdigit(int c); std::toupper(int c)
// #include <cstdlib>
// for rand() and srand()

// <!> - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  </!>
///////////////////////////////////////////////////////////////////////////////]
/*******************************************************************************
┌───┬───┐
│   │   │
├───┼───┤
│   │   │
└───┴───┘

template class, template argument ,  static member function??
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////]
#include <sstream>
#include <iomanip>
#define COLOR(fg, bg) "\033[38;5;" << fg << ";48;5;" << bg << "m"
void	printMemory(void *start, int size, bool hexa) {
	if (!start || size < 0)
		return;

	char *str = (char *)start;

if (!hexa) {
	for (int i = 0; i < size; i++) {
		int c = static_cast<unsigned char>(str[i]);


		if (std::isprint(str[i]))
			std::cout << COLOR(0, c) << str[i] << RESET << std::flush;
		else
			std::cout << COLOR(15, c) << "." << RESET << std::flush;
		
		// std::cout << "\033[38;5;0;48;5;" << c << "m" << str[i] << RESET;
	}
} else {
	for (int i = 0; i < size; i++) {
		int c = static_cast<unsigned char>(str[i]);
		std::stringstream ss;
		// if (!c)
		// 	ss << "\033[38;5;0;48;5;100m";
		// ss << std::hex << c;
		ss << std::uppercase << std::hex << c; // "FF"
		std::cout << COLOR(0, c) << ss.str() << RESET << std::flush;
		// std::cout << "\033[38;5;0;48;5;" << c << "m" << std::setw(2) << std::setfill('0') << ss.str() << RESET;
	}
}
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av) {

	std::string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	// printMemory(&a, 1000, false);
	// char *a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printMemory(&a, 11000, true);
	// printMemory((void*)a.c_str(), 5000, false);
	// std::cout << "sound" << std::endl;
	// std::cout << '\a';
	return 0;

}
///////////////////////////////////////////////////////////////////////////////]
template <typename T>
struct isInteger {
    static const bool value = false;
};

template <>
struct isInteger<int> {
    static const bool value = true;
};

// int main() {
//     std::cout << std::boolalpha;
//     std::cout << "Is int an integer? " << isInteger<int>::value << std::endl;     // true
//     std::cout << "Is float an integer? " << isInteger<float>::value << std::endl; // false
// }


/*******************************************************************************

std::string:

    size() / length()
		Returns the number of characters.
    empty()
		Checks if the string is empty.
    clear()
		Clears the string (makes it empty).
    at(size_type pos)
		Accesses the character at a specific position (with bounds checking).
    operator[]
		Accesses a character at a specific position (without bounds checking).
    append(const std::string&)
		Appends another string.
    substr(size_type pos, size_type len)
		Returns a substring.
    find(const std::string&)
		Finds the first occurrence of a substring.
    compare(const std::string&)
		Compares two strings.
    c_str()
		Returns a C-style string (const char*).
    replace(size_type pos, size_type len, const std::string&)
		Replaces part of the string with another.
    insert(size_type pos, const std::string&)
		Inserts another string at a position.
    erase(size_type pos, size_type len)
		Erases part of the string.
    push_back(char)
		Appends a character.
    pop_back()
		Removes the last character.
    resize(size_type newSize)
		Resizes the string to a new size.
    swap(std::string&)
		Swaps the contents of two strings.

std::getline(std::istream& input, std::string& str);










template <typename T>
T add(T a, T b) {
    return a + b;
}


template <typename T>
class Box {
public:
    T value; // value can be of any type T
    Box(T v) : value(v) {}
};

enum Color {
    RED,
    GREEN,
    BLUE
};

union Data {
    int intValue;
    float floatValue;
    char charValue;
};

******************************************************************************/
/*******************************************************************************
struct Base {};
struct Derived : Base {};  // public inheritance

class BaseClass {};
class DerivedClass : BaseClass {};  // private inheritance



extern "C" {
    struct Data {
        int id;
        char name[20];
    };
}


truct Point {
    int x, y;
    
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    ~Point() {}
};

Inheritance and Polymorphism:

cpp

    struct Base {
        virtual void speak() { std::cout << "Base speaking" << std::endl; }
    };

    struct Derived : Base {
        void speak() override { std::cout << "Derived speaking" << std::endl; }
    };

******************************************************************************/