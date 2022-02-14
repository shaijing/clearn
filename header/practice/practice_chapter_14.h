//
// Created by yulin on 2022/2/9.
//

#ifndef C_PRACTICE10_H
#define C_PRACTICE10_H
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//14.18

extern char * string_in(const char *,const char*);
extern char * s_gets_1(char*,int);
extern void show_n_char(char ch, int num);
typedef int resul;

int match_month(char *);
void cal_days(void);

typedef struct book{
    char title[40];
    char author[20];
    float value;
} library;
static const char path[20] = "library.dat";
bool is_exist(void);
void q_book(FILE *,int);
void q_book_ui(void);
void get_book();
void add_book(library *,int);
void add_book_ui(void);
int ui_menu(void);
void user_ui(void);
void initial(void);
void library_ui(void);

//TODO
#endif //C_PRACTICE10_H


