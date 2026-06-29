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