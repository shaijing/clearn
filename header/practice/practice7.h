//
// Created by yulin on 2022/2/7.
//

#ifndef C_PRACTICE7_H
#define C_PRACTICE7_H
#include "../../header/arithmetic/arithmetic.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
#endif //C_PRACTICE7_H
//11
char * s_gets_p(char * st, int n);

int strlens(const char[]);

const char * spaceinstr(const char []);

void strtoarray(int*);

void gettoarray(char [][80],int n);
void gettoarray_dr(void);

void s_chr_dr(void);
char * s_chr(const char *,int);

bool is_sithin(char *,int);
void is_within_dr(void);

char * mystrncpy(char [],const char [],int);
void mystrncpy_dr(void);

char * string_in(const char *,const char*);
void string_in_dr(void);

void str_rev(char *);
void str_rev_dr(void);

void str_rev_1(char *);
void str_rev_1_dr(void);