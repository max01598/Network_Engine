cmake_minimum_required(VERSION 3.10)

set(ENGINE_HEADERS include/engine/engine.hpp)
set(ENGINE_SOURCES src/engine.cpp)

add_library(engine STATIC ${ENGINE_HEADERS} ${ENGINE_SOURCES})
target_include_directories(engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

