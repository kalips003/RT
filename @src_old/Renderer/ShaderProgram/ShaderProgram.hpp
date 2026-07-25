#pragma once
#include <string>
#include "Log.hpp"

class ShaderProgram {
public:
    ShaderProgram(const char* vertexSrc, const char* fragmentSrc);
    ~ShaderProgram();

    ShaderProgram(const ShaderProgram&)            = delete;
    ShaderProgram& operator=(const ShaderProgram&) = delete;
// 
    void bind()   const;
    void unbind() const;

    void setVec4(const std::string& name, float r, float g, float b, float a) const;
    void setVec2(const std::string& name, float x, float y) const;
    
    unsigned int id() const { return _id; }
// 
private:
    unsigned int compileShader(unsigned int type, const char* src);

// 
private:
    unsigned int _id;
};