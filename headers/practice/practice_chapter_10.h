//
// Created by Chaos on 2022/2/4.
//

#ifndef CLEARN_PRACTICE_CHAPTER_10_H
#define CLEARN_PRACTICE_CHAPTER_10_H
//10.13
#include "../../headers/arithmetic/arithmetic.h"
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


void copy_arr(double target[],const double source[],int);
void copy_ptr(double target[],double source[],int);
void copy_ptrs(double [],double [],int);

void copy_array(void);

void scan_max(void);

void d_sort(void);

void copy_2d_arr(void);

void copy_arr_part(void);

void cp_2darr_f(int,int,double [][*],double [][*]);
void cp_2darr(void);

void sum_arr(void);

void sum_arr_f(const int [],const int[],int[],int);

void  dr_13(void);

void get_arr(void);

double ca_av_o(const double [],int);

double ca_av_a(double [][5],int);

double g_max(double [][5],int);

void p_r(double[],int ,double,double );
#endif //CLEARN_PRACTICE_CHAPTER_10_H
