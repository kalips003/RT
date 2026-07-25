#include "_A.hpp"


#include <iostream>
std::ostream& operator<<(std::ostream& os, const vect3& v)
{
		return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}


//================================================================================================]
#include <algorithm>
std::string	find_extension(const std::string& file_name) {

	size_t pos = file_name.find_last_of('.');
	if (pos == std::string::npos) {
		LOG_ERROR("Couldn't find extension type")
		return "";
	}
	return file_name.substr(pos + 1);
}
