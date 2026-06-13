cmake_minimum_required(VERSION 3.28)
project(coding_betounsi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(coding_betounsi
        main.cpp
        "contests/codeforces round 1103 div3/problem_b.cpp"
        "contests/codeforces round 1103 div3/problem_b.h"
        "contests/Codeforces Round 222 (div 1)/Maze.cpp"
        "contests/Codeforces Round 222 (div 1)/Maze.h"
)

target_include_directories(coding_betounsi PUBLIC contests)