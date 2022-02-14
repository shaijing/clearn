//
// Created by yulin on 2022/2/9.
//
#include "../../header/practice/practice_chapter_12.h"
static unsigned long f_seed = 1;//随机数种子
static unsigned f_t = 0;
void s_seed(unsigned int seed){
    f_seed = seed;
}
unsigned int rand0(void){
    //生成伪随机数的魔术公式
    f_seed = f_seed *1103515245+12345;
    return (unsigned int) (f_seed/65536)%32768;
}

unsigned int rand_by_time(void){
    unsigned long seed = (unsigned int) time(0);
    seed = seed *1103515245+12345;
    return (unsigned int) (seed/65536)%32768;
}

void f(void){
    f_t++;
}
void f_dr(void){
    f();
    f();
    f();
    printf("%u",f_t);
}

unsigned int * r_i_arr(void){
    unsigned int * ptr;
    static unsigned int arr[100];
    ptr = arr;
    for (int i = 0; i < 100; ++i) {
        unsigned long seed = (unsigned int) time(0)+i;
        seed = seed *1103515245+12345;
        unsigned int res = ((unsigned int) (seed/65536)%32768)%10+1;
        arr[i] = res;
    }
    int i, j;
    unsigned int temp;
    for (i = 0; i < 99; i++) {
        for (j = 0; j < 99; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return ptr;
}
void r_i_arr_dr(void){
    unsigned int * ptr = r_i_arr();
    for (int i = 0; i <100 ; ++i) {
        printf("%u(%d) ",*(ptr+i),i);
    }
}

void p_word(void){
    int n;
    printf("n:");
    scanf("%d",&n);
    char (* ptr)[10] = (char (*)[10]) malloc(10*n*sizeof(char));
    for (int i = 0; i < n; ++i) {
        scanf("%s",*(ptr+i));
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n",*(ptr+i));
    }
    free(ptr);
}
void p_word_dr(void){
    p_word();
}