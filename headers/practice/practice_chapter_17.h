//
// Created by yulin on 2022/2/14.
//

#ifndef CLEARN_PRACTICE_CHAPTER_17_H
#define CLEARN_PRACTICE_CHAPTER_17_H
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/list.h"
//17.2
extern char * s_gets(char * st, int n);
struct film_1{
    char title[45];
    int rating;
    struct film_1 * next;
};

void film_2(void);

void showmovies(Item item);
void film_3(void);
#endif //CLEARN_PRACTICE_CHAPTER_17_H
