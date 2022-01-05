//
// Created by Prime on 2022/1/2.
//
#include <time.h>
#include <stdio.h>
#include <string.h>
# include "header/learn1.h"

__attribute__((unused)) void value_location(unsigned int num){//access the memory address of num
    printf( "The memory address of %d is %p \n",num,&num);
}

__attribute__((unused)) void now_time(){ //Pint the system time
    time_t t;
    struct tm * lt;
    time (&t);//Get Unix Timestamp。
    lt = localtime (&t);//convert into time structure。
    printf( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
}

__attribute__((unused)) void default_value_size(){// access the size of default size of different number type
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type unsigned char has a size of %zd bytes.\n\n", sizeof(unsigned char));

    printf("Type short has a size of %zd bytes.\n", sizeof(short));
    printf("Type unsigned short has a size of %zd bytes.\n\n", sizeof(unsigned short));

    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type unsigned has a size of %zd bytes.\n\n", sizeof(unsigned));

    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type unsigned long has a size of %zd bytes.\n\n", sizeof(unsigned long));

    printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Type unsigned long long has a size of %zd bytes.\n\n", sizeof(unsigned long long));

    printf("Type float has a size of %zd bytes.\n\n", sizeof(float)); //Float can not use unsigned.

    printf("Type double has a size of %zd bytes.\n\n", sizeof(double));//Double can not use unsigned.
    printf("Type long double has a size of %zd bytes.\n\n", sizeof(long double));//Double can not use unsigned.

    printf("Type float _Complex has a size of %zd bytes.\n\n", sizeof(float _Complex));
    printf("Type double _Complex has a size of %zd bytes.\n\n", sizeof(double _Complex));
    printf("Type long double has a size of %zd bytes.\n\n", sizeof(long double _Complex));/*sizeof() doesn't support _Imaginary*/

//    printf("Type  has a size of %zd bytes.\n", sizeof());
}

void value_and_format(void){
    char my_c = 'a';
    printf("char value.use %%c:%c\tdec use %%d:%d\toctal use %%o:%o\thex use %%x:%x\n",my_c,my_c,my_c,my_c);
    printf("char value.use %%c:%c\tdec use %%d:%d\toctal use %%#o:%#o\thex use %%#x:%#x\n\n",my_c,my_c,my_c,my_c);

    short my_s = 9;
    printf("short value. dec use %%hd:%hd\toctal use %%o:%o\thex use %%x:%x\n",my_s,my_s,my_s);
    printf("short value. dec use %%hd:%hd\toctal use %%#o:%#o\thex use %%#x:%#x\n\n",my_s,my_s,my_s);
    int my_i = 9;//int
    printf("int value. dec use %%d:%d\toctal use %%o:%o\thex use %%x:%x\n",my_i,my_i,my_i);
    printf("int value. dec use %%d:%d\toctal use %%#o:%#o\thex use %%#x:%#x\n\n",my_i,my_i,my_i);

    unsigned my_u_i = 99;//unsigned or unsigned int
    unsigned my_u_i_1 = 99u;/*when you declare variable,you can add lower u or upper U after the num.But in the conversion below, you must use lower letter*/
    unsigned my_u_i_2 = 99U;
    printf("unsigned int value. dec use %%u:%u\toctal use %%o:%o\thex use %%x:%x\n",my_u_i,my_u_i,my_u_i);
    printf("unsigned int value. dec use %%u:%u\toctal use %%#o:%#o\thex use %%#x:%#x\n\n",my_u_i,my_u_i,my_u_i);

    long my_l = 999;//long or long int
    long my_l_1 = 999l;
    long my_l_2 = 999L;
    printf("long value. dec use %%ld:%ld\toctal use %%lo:%lo\thex use %%lx:%lx\n",my_l,my_l,my_l);
    printf("long value. dec use %%ld:%ld\toctal use %%#lo:%#lo\thex use %%#lx:%#lx\n\n",my_l,my_l,my_l);

    long long my_ll = 9999;//long long or long long int
    long long my_ll_1 = 9999ll;
    long long my_ll_2 = 9999LL;
    printf("long long value. dec use %%lld:%lld\toctal use %%llo:%llo\thex use %%llx:%llx\n",my_ll,my_ll,my_ll);
    printf("long long value. dec use %%lld:%lld\toctal use %%#llo:%#llo\thex use %%#llx:%#llx\n\n",my_ll,my_ll,my_ll);

    unsigned long long my_ull = 99999;
    unsigned long long my_ull_1 = 99999ull;
    unsigned long long my_ull_2 = 99999ULL;
    printf("unsigned long long value. dec use %%llu:%llu\toctal use %%llo:%llo\thex use %%llx:%llx\n",my_ull,my_ull,my_ull);
    printf("unsigned long long value. dec use %%llu:%llu\toctal use %%#llo:%#llo\thex use %%#llx:%#llx\n\n",my_ull,my_ull,my_ull);

    float my_f = 1100.0;//Normally, the float will be regard as double.
    float my_f_1 = 1.1e3f;
    float my_f_2 = 1.1e3F;
    float my_f_3 = 1.1e3f;
    printf("float value. dec use %%f:%f\tuse %%e:%e",my_f,my_f_3);

    double my_d = 111.1;
    printf("float value. dec use %%f:%f\tuse %%e:%e",my_d,my_d);


}

__attribute__((unused)) void default_value_print(void){
    int num1 = 2147483647;
    unsigned num2 =4294967295;
    printf("max int is %d\n",num1);
    printf("max unsigned int is %u\n",num2);
}
__attribute__((unused)) void change_value_pointer(int a,int b){
    printf("initial value is %d\t",a);
    value_location(a);
    *(&a) = b;
    printf("now value is %d\t",a);
    value_location(a);
}

__attribute__((unused)) void value_overflow(void){
    float toobig = 3.4e38 * 100.0f;
    printf("%f\n",toobig);
}

__attribute__((unused)) void value_underflow(void){
    float a,b;
    b = 2147483648.0F + 1.0;
    a = b - 2147483648.0F; //a should be 1.000000, but it is 0.000000
    printf("%f",a);
}

__attribute__((unused)) void value_not_match(void){
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;
    printf("%d \n",n,m);
    printf("%d %d %d\n",n);
    printf("%d %d\n",f,g);
}

__attribute__((unused)) void char_array(void){
    char char_array[40];
    printf("Please enter some word:");
    scanf("%s",char_array);
    for(int i =0;i<strlen(char_array);i++)
        //printf("%c\n",*(&test[i]));/*pointer version*/
        printf("%c\n",char_array[i]);/*normal version*/
    printf("The string you typed has %zd bytes.The machine use %zd bytes to store %s", strlen(char_array),sizeof(char_array),char_array);
}