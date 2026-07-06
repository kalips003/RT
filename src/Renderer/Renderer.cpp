#include "Renderer.hpp"
#include <glad/glad.h>

// hardcoded shaders for now — will move to files when ResourceManager exists
static const char* VERT_SRC = R"(
    #version 410 core
    layout (location = 0) in vec3 aPos;

    uniform vec2 uOffset;   // NDC offset

    void main() {
        gl_Position = vec4(aPos.x + uOffset.x, aPos.y + uOffset.y, aPos.z, 1.0);
    }
)";

static const char* FRAG_SRC = R"(
    #version 410 core
    out vec4 fragColor;

    uniform vec4 uColor;    // RGBA color

    void main() {
        fragColor = uColor;
    }
)";

Renderer::Renderer() {
    _shader = std::make_unique<ShaderProgram>(VERT_SRC, FRAG_SRC);
}

void Renderer::clear() const {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::addMesh(const std::string& name, const std::vector<float>& vertices) {
    _meshes[name] = std::make_unique<Mesh>(vertices);
}

void Renderer::draw(const std::string& meshName,
                    float r, float g, float b,
                    float offsetX, float offsetY) const
{
    auto it = _meshes.find(meshName);
    if (it == _meshes.end()) return;

    _shader->bind();
    _shader->setVec4("uColor",  r, g, b, 1.0f);
    _shader->setVec2("uOffset", offsetX, offsetY);

    it->second->bind();
    glDrawArrays(GL_TRIANGLES, 0, it->second->vertexCount());
    it->second->unbind();
    _shader->unbind();
}