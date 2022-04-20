//
// Created by yulin on 2022/2/11.
//
#include "practice/practice_chapter_16.h"
void preproc(void){
    int x = TWO;

    PX;
    x = FOUR;
    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");
}

void subst(void){
    int y = 5;

    PSQR(y);
    PSQR(2 + 4);
}
void glue(void){
    int XNAME(1) = 14;  // becomes int x1 = 14;
    int XNAME(2) = 20;  // becomes int x2 = 20;
    int x3 = 30;
    PRINT_XN(1);        // becomes printf("x1 = %d\n", x1);
    PRINT_XN(2);        // becomes printf("x2 = %d\n", x2);
    PRINT_XN(3);        // becomes printf("x3 = %d\n", x3);
}
//void variadic(void){
//    double x = 48;
//    double y;
//
//    y = sqrt(x);
//    PR(1, "x = %g\n", x);
//    PR(2, "x = %.2f, y = %.4f\n", x, y);
//}