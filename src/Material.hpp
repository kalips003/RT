#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "general.hpp"
#include <vector>

////////////////////////////////////////////]
struct BaseProperties {
    Color baseColor;   // argb
    Color secondaryColor; // c2
};

struct SurfaceProperties {
    double specular;       // S
    double shininess;      // shiny
    double reflectivity;   // mirror
    double transparency;   // transparence
    double ior;            // gamma
    double emission;       // light
    double ao;             // ambient occlusion
};

#include <memory>

// struct TextureMaps {
//     std::shared_ptr<Texture> albedo;     // txt (X)
//     std::shared_ptr<Texture> normal;     // n_map (N)
//     std::shared_ptr<Texture> alpha;      // a_map (A)
//     std::shared_ptr<Texture> ao;         // ao_map (O)
//     std::shared_ptr<Texture> specular;   // s_map (s)
//     std::shared_ptr<Texture> roughness;  // rough_map (R)
// };

class Texture {
public:
    int width;
    int height;
    std::vector<Color> pixels;
};

////////////////////////////////////////////]
struct Material {
    BaseProperties      base;       // colors
    SurfaceProperties   surface;    // specular, mirror, etc.
    // TextureMaps         maps;       // all textures
};

#endif