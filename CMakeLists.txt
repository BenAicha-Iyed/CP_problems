cmake_minimum_required(VERSION 4.2)
project(coding_betounsi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(coding_betounsi
        main.cpp
        "contests/codeforces round 1103 div3/problem_b.cpp"
        "contests/codeforces round 1103 div3/problem_b.h"
)