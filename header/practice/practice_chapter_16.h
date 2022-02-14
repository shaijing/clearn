//
// Created by yulin on 2022/2/11.
//

#ifndef C_PRACTICE11_H
#define C_PRACTICE11_H
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <complex.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//16.

#define TWO 2        /* you can use comments if you like   */
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde" /* a backslash continues a definition */
/* to the next line                   */
#define FOUR  TWO*TWO
#define PX printf("X is %d.\n", x)
#define FMT  "X is %d.\n"
void preproc(void);

#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))
void subst(void);

#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n", x ## n);
void glue(void);

#include <math.h>
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
void variadic(void);
#endif //C_PRACTICE11_H
