#include "Mesh.hpp"
#include <glad/glad.h>


/////////////////////////////////////////////////////////////////////////////////////////]

Mesh::Mesh(const std::vector<float>& vertices)
    : _vertexCount(vertices.size() / 3)  // 3 floats per vertex (x, y, z)
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);

    glBindVertexArray(_vao);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER,
		vertices.size() * sizeof(float),
		vertices.data(),
		GL_STATIC_DRAW);           // data won't change → GPU can optimize

	// tell the shader: attribute 0 = vec3 position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		3 * sizeof(float),         // stride: 3 floats per vertex
		(void*)0);                 // offset: position starts at byte 0
	glEnableVertexAttribArray(0);

    glBindVertexArray(0);              // unbind — clean state
}

/////////////////////////////////////////////////////////////////////////////////////////]

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
}

/* ==================================================================================== */

void Mesh::bind()   const { glBindVertexArray(_vao); }
void Mesh::unbind() const { glBindVertexArray(0); }