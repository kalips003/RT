#include "Parser.hpp"


//================================================================================================]

#include "_A.hpp"
/** //////////////////////////////////////////////////////////////////////////////////////////////]

    @brief      Short description.

    @details    Longer explanation if needed.

    @param[in]      name    Description.
    @param[out]     name    Description.
    @param[in,out]  name    Description.

    @tparam     T           Template parameter.

    @return     Description of returned value.

    @retval     VALUE       Meaning of a specific return value.
    @retval     VALUE2      Meaning.

    @throws     ExceptionType Description.
    @exception  ExceptionType Description.

    @pre        Preconditions.
    @post       Postconditions.
    @warning    Important warning.
    @note       Additional note.
    @remark     Extra information.
    @attention  Something requiring attention.
    @see        OtherFunction()
    @sa         OtherClass

*/ ///////////////////////////////////////////////////////////////////////////////////////////////]
std::unique_ptr<Scene>	Parser::ParseRT(const std::string& file_name) {

	if (find_extension(file_name) != "rt") {
		LOG_ERROR("NOT \'.rt\' <!> - to handle some way...")
		return nullptr;
	}

// NORMALLY:
	// auto scene = helper_parseRT(file_name);

//	HARD CODED SCENE:
	auto scene = std::make_unique<Scene>();
	scene->_cameras.push_back(Camera({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, -10.0f}, 90.0f));
	scene->_lightsources.push_back(LightSource({10.0f, 10.0f, 10.0f}, 0.8f, {1.0f, 1.0f, 0.0f}));
	scene->_spheres.push_back(Sphere({0.0f, 0.0f, 0.0f}, 5, {1.0f, 1.0f, 1.0f}));
// 

	return scene;
}
