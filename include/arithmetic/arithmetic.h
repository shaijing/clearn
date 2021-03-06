//
// Created by Chaos on 2022/2/1.
//

#ifndef CLEARN_ARITHMETIC_H
#define CLEARN_ARITHMETIC_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
extern char * s_gets(char *,int);
void bucket_sort(void);//桶排序


void bubble_sort_dr(void);
void bubble_sort(int[],int n);

void selection_sort(int [],int);
void selection_sort_dr(void);

void insertion_sort(int [],int);
void insertion_sort_dr(void);

void quick_sort(int,int,int *);
void quick_sort_dr(void);

void bubble_sort_d_f(double num[],int n);

void queue_easy(void);

void stack_easy(void);





#endif //CLEARN_ARITHMETIC_H
