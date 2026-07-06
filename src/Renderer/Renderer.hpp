#pragma once
#include "ShaderProgram.hpp"
#include "Mesh.hpp"
#include <memory>
#include <unordered_map>
#include <string>
#include "Log.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer() = default;

    Renderer(const Renderer&)            = delete;
    Renderer& operator=(const Renderer&) = delete;

    void addMesh(const std::string& name, const std::vector<float>& vertices);
    // draw at a specific NDC position with a specific color
    void draw(const std::string& meshName,
              float r, float g, float b,
              float offsetX = 0.0f, float offsetY = 0.0f) const;
    void clear() const;

private:
    std::unique_ptr<ShaderProgram>                        _shader;
    std::unordered_map<std::string, std::unique_ptr<Mesh>> _meshes;
};