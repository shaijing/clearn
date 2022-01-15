//
// Created by yulin on 2022/1/15.
//
/*C Prime Plus , chapter 8*/

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>

#ifndef C_LEARN3_H
#define C_LEARN3_H

void ex_echo(void);

void ex_echo_eof(void);

void ex_file_eof(void);

void ex_guess(void);

void ex_new_guess(void);

void ex_show_char(void);
void ex_show_char_1(void);
void display(char cr, int line, int width);

void ex_checking(void);
// validate that input is an integer
long get_long(void);
// validate that range limits are valid
bool bad_limits(long begin, long end, long low, long high);
// calculate the sum of the squares of the integers
// a through b
double sum_squares(long a, long b);

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
void ex_menu(void);
#endif //C_LEARN3_H
