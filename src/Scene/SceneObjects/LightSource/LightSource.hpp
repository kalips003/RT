#pragma once
#include "Log.hpp"

//================================================================================================]
// 									LIBs
// #include <vector>
// #include <map>
#include "_A.hpp"


/** //////////////////////////////////////////////////////////////////////////////////////////////]

	@class LightSource

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
class LightSource {

// ============	VARIABLES ============
public:
	// std::string		_name;
	vect3	origin;
	float	intensity = 1.0f;
	vect3	color;

// ============ CONSTRUCTOR ============
public:
	LightSource();
	LightSource(vect3 o, float r, vect3 c) : origin(o), intensity(r), color(c) {}
	~LightSource();

	LightSource(const LightSource &) = delete;
	LightSource& operator=(const LightSource&) = delete;

	LightSource(LightSource&&) noexcept = default;
	LightSource& operator=(LightSource&&) noexcept = default;


// ============ METHODS ============
public:
	/**	f:  */
	void	hello() { LOG_LOG("hello from " C_142 "LightSource" RESET); }
	void	f();
};













//================================================================================================]
//================================================================================================]
//================================================================================================]
std::ostream& operator<<(std::ostream& os, const LightSource& light);