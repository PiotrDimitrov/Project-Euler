cmake_minimum_required(VERSION 3.27)
project(Project_Euler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_Euler main.cpp
        header.h
        libs/bigNum.h
        libs/simpleTimer.h
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
        problems/problem12.cpp
        problems/problem13.cpp
        libs/bigNum.cpp
        problems/problem14.cpp
        libs/simpleTimer.cpp
        problems/problem15.cpp
        problems/problem16.cpp
        problems/problem17.cpp
        problems/problem18.cpp
        problems/problem19.cpp
        problems/problem20.cpp
        problems/problem21.cpp
        problems/problem22.cpp
        problems/problem23.cpp
        problems/problem24.cpp
        problems/problem25.cpp
        problems/problem26.cpp
        problems/problem27.cpp
        problems/problem28.cpp
        problems/problem29.cpp
        problems/problem30.cpp
        problems/problem31.cpp
        problems/problem32.cpp
        problems/problem33.cpp
        problems/problem34.cpp
)
