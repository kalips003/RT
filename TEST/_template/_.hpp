#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>


/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class Default

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class Default {

// ============	VARIABLES ============
private:
	// std::string		_name;

// ============ CONSTRUCTOR ============
public:
	Default();
	~Default();

	Default(const Default &) = delete;
	Default& operator=(const Default&) = delete;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "Default" RESET); }
	void	f();
};

