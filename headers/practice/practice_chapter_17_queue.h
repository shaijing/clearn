//
// Created by Chaos on 2022/3/12.
//

#ifndef CLEARN_PRACTICE_CHAPTER_17_QUEUE_H
#define CLEARN_PRACTICE_CHAPTER_17_QUEUE_H
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../adt/queue.h"
#define MIN_PER_HR 60.0
void q_use(void);


bool newcustomer(double x);   // is there a new customer?
Item customertime(long when); // set customer parameters
void mall(void);
#endif //CLEARN_PRACTICE_CHAPTER_17_QUEUE_H
