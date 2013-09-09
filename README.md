Computing Cubes
===============

**Computing Cubes** currently looks like it's gonna be (oh please not yet) another
[Minecraft](https://minecraft.net/) clone. But my plans are a bit different: this project aims to
be more technical, more about electronic, programming, inventing, machines, robots. Let's see! It's
written in C++ and uses [SDL 2.0](http://libsdl.org/) / [OpenGL](http://www.opengl.org/)

Computing Cubes is currently in the *embryonic stage*. Yet a bit useless but you can watch it
develop to a full featured creature over time.

Getting it to run
-----------------

### Debian and it's derivatives (e.g. Ubuntu, Mint, ...)

I'm developing under 64 bit (GNU/)Linux Mint 15  
Packages needed I needed to install: libgl1-mesa-dev , libglu1-mesa-dev , libfreetype6-dev

The new version of SDL: SDL 2.0 and SDL_image 2.0 are also needed. Because most distros don't have
a package yet for this libs, they are included as ./libraries/linux*/*.so

Just execute Computing Cubes with

`./computingcubes-linux64.sh`

This will use the precompiled SDL 2.0 libraries in ./libraries .

Of course you can use self-built SDL 2.0 und SDL_image 2.0. If so, you can directly execute the
binary in ./build :

`./build/computingcubes`

Screenshots
--------------

![Computing Cubes](/screenshots/2013-09-09-2.png "Computing Cubes")
