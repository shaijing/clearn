cmake_minimum_required(VERSION 3.21)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(c main.c learn1.c header/learn1.h learn2.c header/learn2.h header/learn3.h learn3.c learn4.c header/learn4.h)
