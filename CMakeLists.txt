cmake_minimum_required(VERSION 3.16)
project(contest)

set(CMAKE_CXX_STANDARD 20)

add_library(gen io/gen.cpp)
add_executable(GoodluckSolvingProblems problems/cses/2189.cpp problems/cses/2190.cpp)
