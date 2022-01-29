//
// Created by yulin on 2022/1/16.
//
/*C Prime Plus , chapter 10*/
#ifndef C_LEARN5_H
#define C_LEARN5_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>            /* for strlen() */

void ex_auto_num_of_array(void);


__attribute__((unused)) void ex_design_array(void);


void ex_subscript_bound(void);


void ex_two_dimensional_array(void);


void ex_three_dimensional_array(void);


void ex_array_pointer(void);


void ex_array_use_pointer();


void ex_array_sum(void);
int sum(const int array[], int n);//when you don't want to revise the value of array, use const declare array.


void ex_array_sum_2(void);
int sump(int * start, const int * end);


void ex_pointer_order(void);


void ex_pointer_operation(void);


void ex_const_parameter(void);
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);


void ex_two_dimension_array_pointer(void);


void ex_two_dimension_array_pointer_1(void);


void ex_two_dimension_array_pointer_operation(void);
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int );    // ok to omit names
int sum2d(int (*ar)[COLS], int rows); // another syntax


void ex_vary_two_dimension(void);
#define ROWS 3
#define COLS 4
int sum2d_1(int rows, int cols, int ar[rows][cols]);


void ex_constant_array(void);
int sum2d_2(const int ar[][COLS], int rows);
int sum_1(const int ar[], int n);
#endif //C_LEARN5_H
