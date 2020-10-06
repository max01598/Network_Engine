cmake_minimum_required(VERSION 3.10)

set(ENGINE_HEADERS 
include/engine/common.hpp
include/engine/engine/engine.hpp
include/engine/system/system.hpp
include/engine/system/fps_counter.hpp
)
set(ENGINE_SOURCES src/engine/engine.cpp
src/system/fps_counter.cpp)

add_library(engine STATIC ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_include_directories(engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
