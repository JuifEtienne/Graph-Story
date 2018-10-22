cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(MAIN main.cpp)
set(OUTPUT GraphStory)
set(SOURCE_FILES Node.hpp Graph.hpp Files.cpp Graph.cpp Node.cpp Files.hpp)
add_executable(${OUTPUT} ${MAIN} ${SOURCE_FILES})