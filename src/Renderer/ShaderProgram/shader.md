# OpenGL / GLSL Rendering Pipeline Summary

## General Architecture

A renderer is divided between the **CPU** and the **GPU**.

The CPU is responsible for:

* Application logic
* Scene management
* Loading objects
* Creating vertex data
* Sending commands and data to the GPU
* Updating GPU parameters (uniforms)
* Calling draw commands

The GPU is responsible for:

* Executing shader programs
* Processing vertices in parallel
* Rasterizing geometry
* Computing fragment colors
* Writing final pixels to the framebuffer

Communication happens through a graphics API such as **OpenGL**.

CPU → OpenGL API → GPU → Screen

---

# GLSL

**GLSL (OpenGL Shading Language)** is a C-like programming language used to write GPU programs called **shaders**.

Shaders are small programs executed directly on the GPU.

Main shader stages:

1. Vertex Shader
2. Fragment Shader

---

# Vertex

A **vertex** is a point in 3D space.

A vertex usually contains:

* Position `(x, y, z)`
* Color
* Texture coordinates
* Normal vector
* Other attributes

Example:

```
Vertex:
x = 0.5
y = 0.5
z = 0.0
```

A triangle is made of three vertices:

```
A
|\
| \
B--C
```

---

# Vertex Shader

The **vertex shader** runs once for every vertex.

Purpose:

* Transform vertex positions
* Apply movement
* Apply rotation
* Apply scaling
* Convert coordinates into screen space

Example:

```glsl
layout(location = 0) in vec3 aPos;
```

Means:

* Input attribute
* Stored in GPU attribute location 0
* Contains vertex position data

The vertex shader output:

```glsl
gl_Position
```

is a built-in GLSL variable.

It defines where the vertex appears on screen.

---

# NDC (Normalized Device Coordinates)

After the vertex shader, OpenGL expects coordinates in NDC.

Range:

```
x:
-1 = left
+1 = right

y:
-1 = bottom
+1 = top
```

Center of the screen:

```
(0,0)
```

Example:

```
(-1,1)          (1,1)


       screen


(-1,-1)        (1,-1)
```

---

# Uniforms

A **uniform** is data sent from the CPU to the GPU shader.

Example GLSL:

```glsl
uniform vec2 uOffset;
uniform vec4 uColor;
```

The shader declares:

"I need this value."

The CPU provides:

```cpp
glUniform2f(...)
glUniform4f(...)
```

Uniforms are used for:

* Object position
* Camera position
* Transformation matrices
* Colors
* Lighting parameters
* Time values

They are constant during a draw call.

---

# Rasterization

After vertex processing, the GPU has geometry.

Example:

```
3 vertices
    |
    v
Triangle
```

The GPU converts geometry into fragments.

This process is called:

**Rasterization**

---

# Fragment

A **fragment** is a candidate pixel generated during rasterization.

Important:

Fragment ≠ Pixel

A fragment contains information needed to decide the final pixel color.

A triangle covering many pixels creates many fragments.

Example:

```
Triangle

   *
  ***
 *****
*******

becomes

   f
  fff
 fffff
fffffff
```

---

# Fragment Shader

The **fragment shader** runs once per fragment.

Purpose:

* Determine final color
* Apply textures
* Apply lighting
* Apply transparency
* Compute material effects

Example:

```glsl
out vec4 fragColor;

uniform vec4 uColor;

void main()
{
    fragColor = uColor;
}
```

`fragColor` is the final output color.

---

# RGBA

A color is represented by a `vec4`:

```
vec4(red, green, blue, alpha)
```

Example:

```glsl
vec4(1,0,0,1)
```

means:

```
Red   = 1
Green = 0
Blue  = 0
Alpha = 1
```

Result:

Full opaque red.

---

# Vertex Buffer Objects (VBO)

Vertices are usually stored in CPU memory first.

Example:

```
CPU RAM

[
 vertex1,
 vertex2,
 vertex3
]
```

They are uploaded to GPU memory:

```
GPU VRAM

Vertex Buffer Object
```

The GPU then reads the data directly.

Important OpenGL functions:

```
glGenBuffers()
glBindBuffer()
glBufferData()
```

---

# Shader Compilation Flow

GLSL code exists as a C++ string:

```cpp
static const char* VERT_SRC = R"(
    GLSL CODE
)";
```

`R"( )"` is a C++ raw string literal.

The CPU sends this text to OpenGL:

```
GLSL source code
        |
        v
OpenGL shader compiler
        |
        v
GPU executable shader
```

Important functions:

```
glCreateShader()
glShaderSource()
glCompileShader()
glCreateProgram()
glAttachShader()
glLinkProgram()
```

---

# Rendering Pipeline

Complete OpenGL pipeline:

```
CPU

Create vertices
      |
Upload data to GPU
      |
Set uniforms
      |
Call glDrawArrays / glDrawElements


GPU

Vertex Shader
      |
      v
Primitive Assembly
      |
      v
Rasterization
      |
      v
Fragments
      |
      v
Fragment Shader
      |
      v
Framebuffer
      |
      v
Screen
```

---

# Important Keywords

OpenGL
GLSL
Shader
Vertex Shader
Fragment Shader
Vertex
Fragment
Pixel
Rasterization
GPU Pipeline
CPU-GPU Communication
VRAM
RAM
Vertex Buffer Object (VBO)
Vertex Array Object (VAO)
Uniform
Attribute
gl_Position
fragColor
Framebuffer
NDC (Normalized Device Coordinates)
Primitive Assembly
Draw Call
glDrawArrays
glDrawElements
Shader Compilation
Shader Program
GPU Parallel Processing

---

# Current Renderer Understanding

The current renderer is a minimal OpenGL pipeline:

1. CPU creates vertex data.
2. CPU uploads vertices to GPU.
3. CPU compiles vertex and fragment shaders.
4. CPU sends uniforms like offset and color.
5. CPU calls a draw command.
6. GPU executes vertex shader for every vertex.
7. GPU builds primitives.
8. GPU rasterizes geometry into fragments.
9. GPU executes fragment shader for every fragment.
10. Final colors are written to the framebuffer and displayed.

This is the foundation of more advanced rendering systems such as:

* 3D engines
* Ray tracers
* Real-time rendering engines
* Game engines
