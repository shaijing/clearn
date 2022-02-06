//
// Created by Chaos on 2022/1/28.
//
#include "../header/test/test1.h"

void t_scanf() {
    unsigned int a;
    scanf("%u", &a);
    printf("%u", a);
    char b[30];
    scanf("%10s", b);
    printf("%s\n", b);
    scanf("%s", b);
    printf("%s", b);


}

void w_s() {
    int ay[20];
    int i = 0;
    while (scanf("%d", &ay[i++]));
    for (int j = 0; j < strlen(ay); j++) {
        printf("|%d|", ay[j]);
    }
}


void ch() {
    const char SPACE = ' ';
    int ch;

    ch = getchar();

    while (ch != '\n') {
        if (ch == SPACE)
            putchar(ch);
        else {
            putchar(ch + 1);
        }

        ch = getchar();
    }
    putchar(ch);//换行符
}


void eof(){
    int ch;
    while ((ch = getchar())!= EOF){
        putchar(ch);
    }
}


void pointer_1(void){
    const int **pp2;
    int *p1;
    const int n = 13;
    pp2 = &p1;
    *p1 = 10;
    printf("%d",n);
}


