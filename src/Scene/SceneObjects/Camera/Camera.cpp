#include "Camera.hpp"


//================================================================================================]
Camera::Camera() {}
//================================================================================================]
Camera::~Camera() {}


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
void	Camera::f() {

}





//================================================================================================]
//================================================================================================]
//================================================================================================]
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Camera& camera)
{
    os << "Camera { "
       << "origin: " << camera.origin
       << ", dir: " << camera.dir
       << ", fov: " << camera.fov
       << " }";

    return os;
}