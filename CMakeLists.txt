cmake_minimum_required(VERSION 3.27)
project(Project_Euler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_Euler main.cpp
        header.h
        problems/problem3.cpp
        problems/problem1.cpp
        problems/problem2.cpp
        problems/problem4.cpp
        problems/problem5.cpp
        problems/problem6.cpp
        problems/problem7.cpp
        problems/problem8.cpp
        problems/problem9.cpp
        problems/problem10.cpp
        problems/problem11.cpp
)
