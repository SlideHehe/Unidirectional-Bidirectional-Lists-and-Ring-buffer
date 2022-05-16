cmake_minimum_required(VERSION 3.21)
project(SSW_LR2)

set(CMAKE_CXX_STANDARD 23)

add_executable(SSW_LR2 main.cpp Bidirectional_List.h Bidirectional_List.cpp Tests.cpp Tests.h)
