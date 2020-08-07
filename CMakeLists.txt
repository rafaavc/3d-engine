cmake_minimum_required(VERSION 3.10)


project(CMakeTest)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(proj 
    main.cpp 
    view/graphics/SDLAdapter.cpp 
    view/View.cpp 
    controller/Controller.cpp 
    model/Model.cpp 
    view/graphics/RGBAColor.cpp 
    view/graphics/engine/Scene.cpp 
    view/graphics/engine/Object.cpp 
    view/graphics/engine/Engine.cpp 
    view/graphics/engine/Light.cpp
    model/Vector.cpp 
    model/UnitVector.cpp 
    view/graphics/engine/Observer.cpp)

target_link_libraries(proj ${SDL2_LIBRARIES})


target_include_directories(proj PUBLIC
                           "${PROJECT_BINARY_DIR}")

target_include_directories(proj PUBLIC
                           include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

