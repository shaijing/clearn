//
// Created by Chaos on 2022/2/1.
//

#include "../../header/practice/practice_chapter_8.h"

void file_eof(){
    int ch;
    FILE * fp;
    char fname[50];
    printf("Please enter the path of the file:");
    scanf("%s",fname);
    fp = fopen(fname,"r");
    if (fp == NULL){
        printf("Error!");
        exit(1);
    }
    while ((ch = getc(fp))!=EOF)
        putchar(ch);
    fclose(fp);
}

long get_long(){
    long int num;
    char ch;
    while (scanf("%ld",&num)  != 1){
        while ((ch =getchar())!='\n')
            putchar(ch);
        printf("is not an integer.\n");
        printf("Please enter a correct num:");
    }
    return num;
}

void get_first_d(){
    char ch;
    printf("Please enter a char:");
    while (scanf(" %c",&ch)){//注意，scanf(" %c",&ch)从第一个非空字符开始读取。
        putchar(ch);
        putchar('\n');
        while (getchar() !='\n')
            continue;
        printf("Please enter next char:");
    }
}