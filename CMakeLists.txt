cmake_minimum_required(VERSION 3.10)


project(3d-engine)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(proj 
    src/main.cpp 
    src/view/adapters/SDLAdapter.cpp 
    src/view/View.cpp 
    src/controller/Controller.cpp 
    src/controller/Engine.cpp 
    src/controller/TransformationMatrix.cpp
    src/controller/TriangleController.cpp
    src/controller/FileManager.cpp
    src/model/Model.cpp 
    src/model/Scene.cpp 
    src/model/Object.cpp 
    src/model/Light.cpp 
    src/model/RGBAColor.cpp 
    src/model/Vector3d.cpp 
    src/model/Observer.cpp
    src/model/Triangle.cpp
    src/model/Matrix4x4.cpp
)

target_link_libraries(proj ${SDL2_LIBRARIES})


target_include_directories(proj PUBLIC
                           "${PROJECT_BINARY_DIR}")

target_include_directories(proj PUBLIC
                           include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

