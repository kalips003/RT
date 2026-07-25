#include "SceneManager.hpp"


//================================================================================================]
SceneManager::SceneManager() {}
//================================================================================================]
SceneManager::~SceneManager() {}


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
void	SceneManager::f() {

}

//================================================================================================]

#include "Parser.hpp"
bool	SceneManager::loadFromRTFile(const std::string& file_name) {

	std::unique_ptr<Scene> scene = Parser::ParseRT(file_name);
	if (!scene) {
		LOG_ERROR("some error happend while parsing: " C_301 << file_name << RESET)
		return false;
	}

	_scenes.push_back(std::move(scene));
	return true;
}
