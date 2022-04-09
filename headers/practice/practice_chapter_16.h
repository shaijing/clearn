//
// Created by yulin on 2022/2/11.
//

#ifndef CLEARN_PRACTICE_CHAPTER_16_H
#define CLEARN_PRACTICE_CHAPTER_16_H

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


#define min(x, y) ({\
        const typeof(x) _x = (x); \
        const typeof(y) _y = (y);\
        (void) (&_x == &_y);                  \
        _x < _y ? _x : _y;})
/*这段代码是在阅读《Linux设备驱动开发详解》的时候看到的，自己查阅相关资料对其中几个点做一个解释。

1、首先整体（先赋值再比较）避免了一般宏定义的副作用。如x++,y++

2、用const可以提高可读性。

3、通过地址之间的比较判断两个数据是否是相同类型的。

4、添加（void）避免编译器弹出无意义的警告（因为其后面的地址比较的结果并没有使用）。
 (void) (&_x == &_y) 用于判断输入的两个值的类型是否是一致的。如果不一致，那么编译器就会做出如下警告：warning: comparison of distinct pointer types lacks a cast
 */

#define TYPE(x) _Generic((x),\
        int:"int",           \
        float:"float",\
        double:"double",\
        default:"other"\
)

#define SQRT(X) _Generic((X), \
        long double :sqrtl,                              \
        float: sqrtf,                      \
        default: sqrt                      \
                              \
) (X)

#endif //CLEARN_PRACTICE_CHAPTER_16_H
