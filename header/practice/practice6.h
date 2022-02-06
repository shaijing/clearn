//
// Created by Chaos on 2022/2/4.
//

#ifndef C_PRACTICE6_H
#define C_PRACTICE6_H
//10.13
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
void sum_1d(int ar[], int);

void sum_1d_v(int, int ar[ *]);

void sum_2d(int ar[][2], int rows);

void sum_2d_v(int, int, int ar[ *][ *]);

void sum_3d(int ar[][2][2], int rows);

void sum_3d_v(int, int, int, int ar[ *][ *][ *]);


void show(const double ar[], int n);

void show2(const double ar2[][3], int n);

void to_show(void);

#endif //C_PRACTICE6_H
