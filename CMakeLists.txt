cmake_minimum_required(VERSION 3.14)
project(pr7)

set(CMAKE_CXX_STANDARD 14)

add_executable(Demostracion src/main.cpp include/NodoBB.h include/ABB.h src/DNI.cpp include/DNI.h include/NodoAVL.h include/AVL.h)
add_executable(Estadistico src/main2.cpp include/NodoBB.h include/ABB.h src/DNI.cpp include/DNI.h include/NodoAVL.h include/AVL.h)
add_executable(test src/test/test.cpp include/NodoBB.h include/ABB.h include/NodoAVL.h include/AVL.h)