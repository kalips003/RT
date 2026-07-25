#pragma once
#include "Log.hpp"

//================================================================================================]

struct vect3 {

	float	x;
	float	y;
	float	z;

	vect3() : x(0), y(0), z(0) {}
	vect3(float a, float b, float c) : x(a), y(b), z(c) {}

};

std::ostream& operator<<(std::ostream& os, const vect3& v);

struct rayon
{
	vect3	pos;
	vect3	dir;

};

/** //////////////////////////////////////////////////////////////////////////////////////////////]

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]

std::string	find_extension(const std::string& file_name);