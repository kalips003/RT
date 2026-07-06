#pragma once
#include <vector>
#include "Log.hpp"

class Mesh {
public:
    Mesh(const std::vector<float>& vertices);
    ~Mesh();

    Mesh(const Mesh&)            = delete;
    Mesh& operator=(const Mesh&) = delete;

    void bind()   const;
    void unbind() const;

    int vertexCount() const { return _vertexCount; }

private:
    unsigned int _vao;
    unsigned int _vbo;
    int          _vertexCount;
};