#include "Scene.hpp"


//================================================================================================]
Scene::Scene() {}
//================================================================================================]
Scene::~Scene() {}


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
void	Scene::f() {

}









//================================================================================================]
//================================================================================================]
//================================================================================================]
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Scene& scene)
{
    os << "Scene {\n";

    os << "  Cameras (" << scene._cameras.size() << "):\n";
    for (const auto& camera : scene._cameras)
        os << "    " << camera << '\n';

    os << "  LightSources (" << scene._lightsources.size() << "):\n";
    for (const auto& light : scene._lightsources)
        os << "    " << light << '\n';

    os << "  Spheres (" << scene._spheres.size() << "):\n";
    for (const auto& sphere : scene._spheres)
        os << "    " << sphere << '\n';

    os << "  Plans (" << scene._plans.size() << "):\n";
    for (const auto& plan : scene._plans)
        os << "    " << plan << '\n';

    os << "}";

    return os;
}