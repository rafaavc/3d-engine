# 3D Engine
Experimental build of a 3d engine from the ground up.<br/><br/>

<img src = "docs/rotatingCube.gif" width="600" /><br/>
Rendering a rotating cube with constant shading and Z-Buffer.<br/><br/>

<img src = "docs/rotatingTeapot.gif" width="600" /><br/>
Rendering a rotating Utah Teapot with constant shading and Z-Buffer.<br/><br/>

## Features

- Constant Shading
- Z-Buffer
- Backface Culling
- Projection of 3D points in 2D space
- Transformations
- .obj support

## Third party dependencies

- [SDL2](https://libsdl.org)
- [CMake](https://cmake.org)

## Compilation

### Pre-made scripts (linux)
You may need to give execution permission to the files:
```bash
chmod a+x <file_name>
```
#### build and run
```bash
./run -b
```
#### build
```bash
./buildit
```
#### run
```bash
./run
```

### Manual (linux)

#### build
```bash
mkdir -p build && cd build
cmake .. 
make 
```

#### run
```bash
./build/proj
```


