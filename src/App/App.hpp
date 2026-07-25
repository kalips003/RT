#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>


/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class App

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class App {

// ============	VARIABLES ============
private:
	// std::string		_name;

// ============ CONSTRUCTOR ============
public:
	App();
	~App();

	App(const App &) = delete;
	App& operator=(const App&) = delete;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "App" RESET); }
	void	f();
};

