#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>
#include "_A.hpp"


/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class Plan

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class Plan {

// ============	VARIABLES ============
public:
	// std::string		_name;
	vect3	origin;
	vect3	dir;
	vect3	color;

// ============ CONSTRUCTOR ============
public:
	Plan();
	Plan(vect3 o, vect3 r, vect3 c) : origin(o), dir(r), color(c) {}
	~Plan();

	Plan(const Plan &) = delete;
	Plan& operator=(const Plan&) = delete;

	Plan(Plan&&) noexcept = default;
	Plan& operator=(Plan&&) noexcept = default;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "Plan" RESET); }
	void	f();
};













//================================================================================================]
//================================================================================================]
//================================================================================================]
std::ostream& operator<<(std::ostream& os, const Plan& plan);