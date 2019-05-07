cmake_minimum_required(VERSION 3.14)
project(pr6)

set(CMAKE_CXX_STANDARD 14)

add_executable(demo src/main.cpp include/NodoBB.h include/ABB.h src/DNI.cpp include/DNI.h)
add_executable(test src/test/test.cpp include/NodoBB.h include/ABB.h)