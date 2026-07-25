## Using OpenGL

These following steps are setting up the foundation for a C++ programming environment to create graphics using OpenGL.

Because OpenGL is "just a spec" (as we talked about), you need helper tools to actually get a window onto your screen and talk to your graphics card. Here is exactly what these two steps are doing:

# Install GLFW (The Window Manager)

OpenGL itself cannot create a window, handle a mouse, or detect keyboard presses. It only knows how to draw shapes once a window already exists.

```bash
sudo apt install libglfw3-dev
```

GLFW is a library that handles the boring, operating-system-specific stuff for you. It tells macOS or Linux: "Hey, open a $640 \times 480$ window, and let me know if the user hits the Escape key."

# Get GLAD (The Function Loader)

Because there are thousands of different graphics cards and drivers out there, the actual location of OpenGL functions (like glDrawArrays) inside your computer's memory isn't fixed. They have to be looked up at runtime.
Doing this manually is incredibly tedious. GLAD is a tool that generates a custom "loader" script that automatically finds all those hidden OpenGL functions for you.

When you go to the website and pick those options, you are configuring your loader:

- Language (C/C++): Tells GLAD to generate files that C++ understands.
- API gl (4.1 or 3.3): Tells GLAD which version of OpenGL features you want access to. Version 3.3 is highly compatible with older computers; 4.1 is usually the maximum supported version on macOS.
- Profile (Core): Tells GLAD to only include modern OpenGL functions and remove old, outdated features from the 1990s (called the "Compatibility" profile).

permalink:
```bash
https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D3.3&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=core&loader=on
```



### Given the architecture you've been building, a complete engine could look something like this:

Application / Engine
│
├── Window Manager
│     │
│     ├── Window
│     │     ├── OS window handle
│     │     ├── OpenGL/Vulkan context
│     │     └── Swap buffers
│     │
│     └── manages multiple windows (optional)
│
├── Input Manager
│     │
│     ├── Keyboard events
│     ├── Mouse events
│     ├── Controller events
│     └── Event callbacks
│
├── Resource Manager
│     │
│     ├── Meshes
│     │     └── OBJ / GLTF data
│     │
│     ├── Textures
│     │
│     ├── Materials
│     │
│     ├── Shaders
│     │
│     └── Caches loaded assets
│
├── Scene Manager
│     │
│     ├── Scene
│     │     │
│     │     ├── Scene Objects
│     │     │      ├── Transform
│     │     │      ├── Mesh reference
│     │     │      ├── Material reference
│     │     │      └── Components
│     │     │
│     │     ├── Lights
│     │     ├── Cameras
│     │     └── World settings
│     │
│     └── Scene switching/loading
│
├── Renderer
│     │
│     ├── Render pipeline
│     │
│     ├── GPU communication
│     │
│     ├── OpenGL/Vulkan backend
│     │
│     ├── Raster renderer
│     │
│     └── Ray tracer (your future part)
│
├── Camera System
│     │
│     ├── View matrix
│     ├── Projection matrix
│     └── Camera controls
│
├── Physics Engine (optional)
│     │
│     ├── Collision
│     ├── Rigid bodies
│     └── Simulation
│
├── Audio System (optional)
│
├── Animation System (optional)
│     │
│     ├── Skeletons
│     ├── Bones
│     └── Keyframes
│
├── Scripting System (optional)
│     │
│     └── Game logic
│
└── Editor / GUI Layer
      │
      ├── Scene hierarchy
      ├── Inspector
      ├── Asset browser
      ├── Console
      ├── Render settings
      └── Debug tools

The important relationships are:

Resource side (things that exist once)
ResourceManager

Mesh
Texture
Material
Shader
Sound

Example:

Tree.obj
    |
    v
Mesh resource

Loaded once.

Scene side (instances in the world)
Scene

TreeObject
    position = (10,0,5)
    mesh = TreeMesh*

TreeObject2
    position = (20,0,3)
    mesh = TreeMesh*

Multiple objects can share the same resource.

Runtime loop

Everything eventually meets in the main loop:

while(running)
{
    InputManager.update();

    SceneManager.update();

    Renderer.render(scene);

    WindowManager.present();
}
With the GUI added

The GUI is usually not part of the engine core. It sits on top:

                Editor GUI
                   |
                   v
Application Layer
                   |
        +----------+----------+
        |                     |
 Scene Manager        Resource Manager
        |
 Renderer
        |
 GPU

The editor asks the engine:

"Give me the list of objects."
"Change this object's position."
"Load this mesh."
"Change this material."

It doesn't own those systems.

One thing I would consider adding to your design later is an Entity/Component system. Instead of making SceneObject contain everything:

SceneObject
{
    Mesh*
    Material*
    Camera*
    Light*
}

you move toward:

Entity
{
    TransformComponent
    MeshComponent
    LightComponent
    CameraComponent
}

This is the architecture used by many modern engines because it scales much better. But your current separation (Scene → Objects → Resources) is already the right foundation.