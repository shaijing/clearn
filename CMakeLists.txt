cmake_minimum_required(VERSION 3.21)

#form 1：
#project(<PROJECT-NAME> [<language-name>...])
#form 2：
#project(<PROJECT-NAME>
#[VERSION <major>[.<minor>[.<patch>[.<tweak>]=]=]]
#[DESCRIPTION <project-description-string>]
#[HOMEPAGE_URL <url-string>]
#[LANGUAGES <language-name>...])

project(clearn C)
set(CMAKE_C_STANDARD 99)

add_executable(clearn main.c source/learn/learn.c headers/learn/learn.h source/learn/learn_chapter_7.c headers/learn/learn_chapter_7.h headers/learn/learn_chapter_8.h source/learn/learn_chapter_8.c source/learn/learn_chapter_9.c headers/learn/learn_chapter_9.h headers/learn/learn_chapter_9/hotel.h headers/learn/learn_chapter_10.h source/learn/learn_chapter_10.c headers/learn/learn_chapter_11.h source/learn/learn_chapter_11.c headers/learn/other.h source/learn/other.c headers/practice/practice.h source/practice/practice.c headers/test/test.h source/test/test.c headers/practice/practice_chapter_6.h source/practice/practice_chapter_6.c headers/practice/practice_chapter_7.h source/practice/practice_chapter_7.c headers/practice/practice_chapter_8.h source/practice/practice_chapter_8.c headers/arithmetic/arithmetic.h source/arithmetic/arithmetic.c source/exam/exam.c headers/exam/exam.h headers/practice/practice_chapter_9.h source/practice/practice_chapter_9.c headers/practice/practice_chapter_10.h source/practice/practice_chapter_10.c headers/practice/practice_chapter_11.h source/practice/practice_chapter_11.c source/practice/practice_chapter_12.c headers/practice/practice_chapter_12.h headers/practice/practice_chapter_13.h source/practice/practice_chapter_13.c headers/practice/practice_chapter_14.h source/practice/practice_chapter_14.c source/practice/practice_chapter_16.c headers/practice/practice_chapter_16.h utils/md5.c utils/md5.h utils/cJSON.c utils/cJSON.h source/practice/practice_chapter_17.c headers/practice/practice_chapter_17.h headers/adt/list.h source/adt/list.c headers/practice/practice_arithmetic.h source/practice/practice_arithmetic.c headers/adt/queue.h source/adt/queue.c source/learn/high_precision.c headers/learn/high_precision.h source/practice/practice_chapter_17_queue.c headers/practice/practice_chapter_17_queue.h headers/adt/tree.h source/adt/tree.c)
#the first value of add_executable() is the exe name.