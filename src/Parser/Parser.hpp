#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
// #include <Scene.hpp>
#include <Log.hpp>

class Parser {
public:
    static bool loadRT(const std::string& file, Scene& scene);
    // bool loadOBJ(const std::string& file, Mesh& mesh);
    // bool loadMTL(const std::string& file, MaterialLibrary& mtl);
    // bool loadTexture(const std::string& file, Texture& tex);
};

#endif