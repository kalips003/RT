#include "ShaderProgram.hpp"
#include <glad/glad.h>
#include <stdexcept>
#include <string>

/* ================================================================================ */

ShaderProgram::ShaderProgram(const char* vertexSrc, const char* fragmentSrc) {
    unsigned int vert = compileShader(GL_VERTEX_SHADER,   vertexSrc);
    unsigned int frag = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    _id = glCreateProgram();
    glAttachShader(_id, vert);
    glAttachShader(_id, frag);
    glLinkProgram(_id);

    int success;
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if (!success) {
        char log[512];
        glGetProgramInfoLog(_id, 512, nullptr, log);
        glDeleteShader(vert);
        glDeleteShader(frag);
        throw std::runtime_error(std::string("Shader link error: ") + log);
    }

    // once linked, individual shaders are no longer needed
    glDeleteShader(vert);
    glDeleteShader(frag);
}

/* ================================================================================ */

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(_id);
}

/* ================================================================================ */

void ShaderProgram::bind()   const { glUseProgram(_id); }
void ShaderProgram::unbind() const { glUseProgram(0); }


/* ================================================================================ */

void ShaderProgram::setVec4(const std::string& name, float r, float g, float b, float a) const {
    glUniform4f(glGetUniformLocation(_id, name.c_str()), r, g, b, a);
}

/* ================================================================================ */

void ShaderProgram::setVec2(const std::string& name, float x, float y) const {
    glUniform2f(glGetUniformLocation(_id, name.c_str()), x, y);
}

/* ================================================================================ */

unsigned int ShaderProgram::compileShader(unsigned int type, const char* src) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        throw std::runtime_error(std::string("Shader compile error: ") + log);
    }
    return shader;
}