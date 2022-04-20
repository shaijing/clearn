//
// Created by Chaos on 2022/2/2.
//

#ifndef CLEARN_EXAM_H
#define CLEARN_EXAM_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>            /* for strlen() */

typedef struct STUDENT {
    int id;
    char name[10];
    float grade1;
    float grade2;
    float grade3;
    float ave;
} stu;

void exam1_ref(void);

void exam1(void);

void exam1_1(void);

void exam1_2(void);


void exam2(void);

int mycmp(const void *, const void *);

void exam3(void);

void exam3_1(void);

int DigitNum(const char *);

void DigitNum_dr(void);

void question_2(void);

#endif //CLEARN_EXAM_H
