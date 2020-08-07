cmake_minimum_required(VERSION 3.10)


project(3d-engine)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(proj 
    src/main.cpp 
    src/view/graphics/SDLAdapter.cpp 
    src/view/View.cpp 
    src/controller/Controller.cpp 
    src/model/Model.cpp 
    src/view/graphics/RGBAColor.cpp 
    src/view/graphics/engine/Scene.cpp 
    src/view/graphics/engine/Object.cpp 
    src/view/graphics/engine/Engine.cpp 
    src/view/graphics/engine/Light.cpp
    src/model/Vector.cpp 
    src/model/UnitVector.cpp 
    src/view/graphics/engine/Observer.cpp)

target_link_libraries(proj ${SDL2_LIBRARIES})


target_include_directories(proj PUBLIC
                           "${PROJECT_BINARY_DIR}")

target_include_directories(proj PUBLIC
                           include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

