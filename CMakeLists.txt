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

add_executable(clearn main.c source/learn/learn.c header/learn/learn.h source/learn/learn_chapter_7.c header/learn/learn_chapter_7.h header/learn/learn_chapter_8.h source/learn/learn_chapter_8.c source/learn/learn_chapter_9.c header/learn/learn_chapter_9.h header/learn/learn_chapter_9/hotel.h header/learn/learn_chapter_10.h source/learn/learn_chapter_10.c header/learn/learn_chapter_11.h source/learn/learn_chapter_11.c header/learn/other.h source/learn/other.c header/practice/practice.h source/practice/practice.c header/test/test.h source/test/test.c header/practice/practice_chapter_6.h source/practice/practice_chapter_6.c header/practice/practice_chapter_7.h source/practice/practice_chapter_7.c header/practice/practice_chapter_8.h source/practice/practice_chapter_8.c header/arithmetic/arithmetic.h source/arithmetic/arithmetic.c source/exam/exam.c header/exam/exam.h header/practice/practice_chapter_9.h source/practice/practice_chapter_9.c header/practice/practice_chapter_10.h source/practice/practice_chapter_10.c header/practice/practice_chapter_11.h source/practice/practice_chapter_11.c source/practice/practice_chapter_12.c header/practice/practice_chapter_12.h header/practice/practice_chapter_13.h source/practice/practice_chapter_13.c header/practice/practice_chapter_14.h source/practice/practice_chapter_14.c source/practice/practice_chapter_16.c header/practice/practice_chapter_16.h utils/md5.c utils/md5.h utils/cJSON.c utils/cJSON.h source/practice/practice_chapter_17.c header/practice/practice_chapter_17.h header/adt/list.h source/adt/list.c)
#the first value of add_executable() is the exe name.