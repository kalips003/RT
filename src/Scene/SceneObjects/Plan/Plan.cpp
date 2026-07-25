#include "Plan.hpp"


//================================================================================================]
Plan::Plan() {}
//================================================================================================]
Plan::~Plan() {}


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
void	Plan::f() {

}







//================================================================================================]
//================================================================================================]
//================================================================================================]
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Plan& plan)
{
    os << "Camera { "
       << "origin: " << plan.origin
       << ", dir: " << plan.dir
       << ", color: " << plan.color
       << " }";

    return os;
}