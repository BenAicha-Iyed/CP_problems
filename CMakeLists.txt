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
        "contests/Bayan 2015 Contest Warm Up/StronglyConnectedCity.h"
        "Leetcode daily challenges/1833. Maximum Ice Cream Bars.h"
        "Leetcode daily challenges/1189. Maximum Number of Balloons .h"
        "contests/Codeforces Round 321 (Div 2)/Kefa and Park.h"
        "contests/Codeforces Round 360 (Div 1)/NP-Hard Problem.h"
        "contests/VK Cup 2015 - Qualification Round 1/Reposts.h"
        "Leetcode daily challenges/Bus Routes.h"
)

target_include_directories(coding_betounsi PUBLIC contests)