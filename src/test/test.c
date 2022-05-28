//
// Created by Chaos on 2022/1/28.
//
#include "test/test.h"
void t_scanf() {
    // unsigned int a;
    // scanf("%u", &a);
    // printf("%u", a);
    // char b[30];
    // scanf("%10s", b);
    // printf("%s\n", b);
    // scanf("%s", b);
    // printf("%s", b);
    char str1[100];
    long double n;
    scanf("%Le", &n);
    printf("%Le\n", n);
    //scanf("%5c", a); // 读取五个字符,其余留在缓冲区
    // scanf("%[a-z]", str1);
    // printf("%s\n", str1);
    //     scanf("%2s", a);
//     scanf("%s", b);
//     printf("%s", a);
//     printf("%s", b);
// }
}

void w_s() {
    int ay[20];
    int i = 0;
    while (scanf("%d", &ay[i++]));
    for (int j = 0; j < strlen((char *)ay); j++) {
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


void eof() {
    int ch;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
}


void pointer_1(void) {
    int n = 10;
    const int* p1=&n;
    const int** pp2 = &p1;
    printf("%d", *p1);
}


//void long_to_str(void){
//    long num = 1000;
//    char str[100];
//    ltoa(num,str,10);
//    for (int i = 0; i < strlen(str) ; ++i) {
//        printf("%c ",str[i]);
//    }
//}

void a(void) {
    unsigned long long  num;
    char str[100];
    char num_name[30] = "";
    int sum = 0;
    char* name[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    char num_l[10] = { '0','1','2','3','4','5','6','7','8','9' };
    scanf("%llu", &num);
    sprintf(str, "%llu", num);
    for (int i = 0; i < strlen(str); ++i) {
        sum += (int)*(str + i) - 48;
    }
    char sum_str[20];
    sprintf(sum_str, "%d", sum);
    for (int i = 0; i < strlen(sum_str); ++i) {
        for (int j = 0; j < 10; ++j) {
            if (sum_str[i] == num_l[j]) {
                strcat(num_name, name[j]);
                if (i < strlen(sum_str) - 1) {
                    strcat(num_name, " ");
                }

            }
        }
    }
    printf("%s", num_name);
}

void string_test() {
    typedef char* string;
    string s2 = "bsdfasf";
    string s1 = (string)malloc(5);
    scanf("%s", s1);
    *s1 = 'a';
    //*s2 = 'a' will show segment fault
    printf("s1: %s\ns2: %s", s1, s2);
    free(s1);
}

void test_for(void) {

    for (int i = 0; i < 0; i++) 
        printf("Test for\n");
    

}