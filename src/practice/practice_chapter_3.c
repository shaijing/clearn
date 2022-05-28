#include "practice/practice_chapter_3.h"

void p(void) {
    unsigned int a = 4294967295;
    unsigned int* ptr = &a;
    printf("%u %#p\n", a, ptr);
    printf("%zd bytes\n",sizeof(2.727));
}