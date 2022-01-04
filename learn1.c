//
// Created by Prime on 2022/1/2.
//
#include <time.h>
#include <stdio.h>
# include "header/learn1.h"

__attribute__((unused)) void my_location(unsigned int num){//access the memory address of num
    printf( "The memory address of %d is %p \n",num,&num);
}

__attribute__((unused)) int now_time(){ //Pint the system time
    time_t t;
    struct tm * lt;
    time (&t);//Get Unix Timestamp。
    lt = localtime (&t);//convert into time structure。
    printf( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
    return 0;
}

__attribute__((unused)) void default_size(){// access the size of default size of different number type
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type unsigned char has a size of %zd bytes.\n", sizeof(unsigned char));
    printf("Type short has a size of %zd bytes.\n", sizeof(short));
    printf("Type unsigned short has a size of %zd bytes.\n", sizeof(unsigned short ));
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Type float has a size of %zd bytes.\n", sizeof(float));
    printf("Type double has a size of %zd bytes.\n", sizeof(double));
    printf("Type unsigned has a size of %zd bytes.\n", sizeof(unsigned));
    printf("Type unsigned long has a size of %zd bytes.\n", sizeof(unsigned long));
    printf("Type unsigned long long has a size of %zd bytes.\n", sizeof(unsigned long long));
    printf("Type long double has a size of %zd bytes.\n", sizeof(long double));
    printf("Type double _Complex has a size of %zd bytes.\n", sizeof(double _Complex));
    printf("Type float _Complex has a size of %zd bytes.\n", sizeof(float _Complex));
//    printf("Type  has a size of %zd bytes.\n", sizeof());

}