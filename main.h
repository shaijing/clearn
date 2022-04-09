//
// Created by Chaos on 2022/4/9.
//

#ifndef CLEARN_MAIN_H
#define CLEARN_MAIN_H
#pragma c9x on

/*#if __STDC_VERSION__ != 201112L
#error Not C11
#endif*/
#if __STDC_VERSION__ != 199901L
#error Not C9X
#endif


#include "headers/practice/practice_chapter_9.h"
//#include <windows.h>
// load dll file, require window.h file
#include "headers/arithmetic/arithmetic.h"
#include "headers/test/test.h"
#include "headers/exam/exam.h"
#include "headers/practice/practice_arithmetic.h"
#include "headers/learn/high_precision.h"
#include "headers/practice/practice_chapter_16.h"



void OS_TYPE(void);
void OS_TYPE(void){
#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
    printf("windows");
#elif defined(__linux__)
    printf("linux");
#elif defined(__APPLE__)
	printf("apple");
#else
	printf("other");
#endif
}
#endif //CLEARN_MAIN_H
//__FILE__     //进行编译的源文件的路径
//__LINE__     //文件当前的行号
//__DATE__     //文件被编译的日期
//__TIME__     //文件被编译的时间
//__STDC__     //如果编译器遵循ANSI c（c标准），其值为1，否则未定义


//system("chcp 65001 > null.log");//solve the clion printf chinese garbled code。


















/*      //use dynamic library
 *     // define two functional pointer
    void(*hello)(void) = NULL;
    // load dll file, require window.h file
    HMODULE module = LoadLibraryA("lib/libtest.dll");
    if (module == NULL) {
        system("error load");
    }
    hello = (void(*)(void))GetProcAddress(module, "hello");


    hello();
    FreeLibrary(module);*/
/*
int main(int argc, char *argv[])
{
    char mode = 'p';
    int ok = 1;
    int ch;

    if (argc > 2)
    {
        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
        ok = 0; */
/* skip processing input *//*

    }
    else if (argc == 2)
    {
        if (argv[1][0] != '-')
        {
            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
            ok = 0;
        }
        else
            switch(argv[1][1])
            {
                case 'p' :
                case 'u' :
                case 'l' : mode = argv[1][1];
                    break;
                default : printf("%s is an invalid flag; ", argv[1]);
                    printf("using default flag (-p).\n");
            }
    }

    if (ok)
        while ((ch = getchar() ) != EOF)
        {
            switch(mode)
            {
                case 'p' : putchar(ch);
                    break;
                case 'u' : putchar(toupper(ch));
                    break;
                case 'l' : putchar(tolower(ch));
            }
        }

    return 0;
}*/
