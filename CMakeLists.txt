cmake_minimum_required(VERSION 4.2)
project(coding_betounsi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(coding_betounsi
        main.cpp
        main.h
        "Contests/Educational Codeforces Round 191 (Rated for Div. 2)/ProblemA_AI_Project_Development.h"
        "Contests/Educational Codeforces Round 191 (Rated for Div. 2)/Problem-A_AI-Project-Development.cpp"
        "Contests/Educational Codeforces Round 191 (Rated for Div. 2)/Problem-A_AI-Project-Development.h")
