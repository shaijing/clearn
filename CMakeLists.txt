cmake_minimum_required(VERSION 3.21)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(c main.c learn/learn1.c header/learn/learn1.h learn/learn2.c header/learn/learn2.h header/learn/learn3.h learn/learn3.c learn/learn4.c header/learn/learn4.h header/learn/learn4/hotel.h header/learn/learn5.h learn/learn5.c header/learn/learn6.h learn/learn6.c header/learn/other.h learn/other.c header/practice/practice1.h practice/practice1.c header/test/test1.h test/test1.c)
