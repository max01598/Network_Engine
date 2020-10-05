cmake_minimum_required(VERSION 3.10)

project(
    engine
    VERSION 0.1.0
    DESCRIPTION "Network engine"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENGINE_BUILD_TESTS "Build tests" ON)
option(ENGINE_BUILD_EXAMPLES "Build examples" ON)

# add external folder => external librairies
add_subdirectory(externes)

#add main lib code
add_subdirectory(engine)

#add game code
add_subdirectory(games)

#add test code
if(ENGINE_BUILD_TESTS)
    add_subdirectory(tests) 
endif(ENGINE_BUILD_TESTS)


#add examples code
if(ENGINE_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif(ENGINE_BUILD_EXAMPLES)


