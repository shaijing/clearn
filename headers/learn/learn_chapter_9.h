//
// Created by yulin on 2022/1/15.
//
/*C Prime Plus , chapter 9*/
#ifndef CLEARN_LEARN_CHAPTER_9_H
#define CLEARN_LEARN_CHAPTER_9_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>            /* for strlen() */
#include "learn_chapter_9/hotel.h"

//
unsigned long fib(unsigned num);/*This function will use the memory very quickly, when the num is big*/

long factorial(int num);

int factorial_recursion(int num);

void change_value_pointer(int a,int b);
void value_location(unsigned int num);
//

void ex_star_bar();
void show_n_char(char ch, int num);

void ex_recur();
void up_and_down(int n);

void ex_two_ways_fact(void);
long loop_fact(int n);
long recursion_fact(int n);

void ex_decimal_to_binary();
void to_binary(unsigned long n);

void ex_hotel(void);

void ex_value_location(void);
void mikado(int);

void ex_value_change();
void interchange(int * u, int * v);
#endif //CLEARN_LEARN_CHAPTER_9_H

