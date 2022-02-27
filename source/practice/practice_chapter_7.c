//
// Created by Chaos on 2022/1/31.
//

#include "../../headers/practice/practice_chapter_7.h"

void divisors() {
    unsigned long num;
    unsigned long div;
    bool isPrime;
    printf("Please enter a numbers:");
    while (scanf("%lu", &num) == 1) {
        for (div = 2, isPrime = true; (div * div) <= num; div++) {
            if (num % div == 0) {
                if ((div * div) != num)
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                else
                    printf("%lu is divisible by %lu\n", num, div);
                isPrime = false;
            }

        }
        if (isPrime)
            printf("%lu is a prime.\n", num);
        printf("Enter next num:");
    }
    printf("Bye!\n");
}


void word_count() {
    char ch;
    bool inWord;
    int chr_count = 0;
    int word_count = 0;
    int line_count = 0;
    int p_l = 0;
    char pre_c;
    printf("Please enter some strings:");
    while ((ch = getchar()) != '|') {
        chr_count++;
        if (ch != ' ' && ch != '\n')
            inWord = true;
        if ((ch == ' ' || ch == '\n') && inWord == true) {
            word_count++;
            inWord = false;
        }
        if (ch == '\n')
            line_count++;
        pre_c = ch;
    }
    if (pre_c != '\n')
        p_l = 1;
    printf("Total char:%d,total word:%d,total line:%d,p line:%d\n", chr_count, word_count, line_count, p_l);
}

void t1() {
    char ch;
    while ((ch = getchar()) != '#') {
        if (ch != '\n') {
            printf("Step 1\n");
            if (ch == 'b')
                break;
            else if (ch != 'c') {
                if (ch != 'h')
                    printf("Step 2\n");
                printf("Step 3");


            }
        }
    }
}


void chr_count(void) {
    char ch;
    int space = 0;
    int n = 0;
    int chr = 0;
    while ((ch = getchar()) != '#') {
        if (ch == ' ')
            space++;
        else if (ch == '\n')
            n++;
        else
            chr++;
    }
    printf("Total space:%d.\nTotal \\n:%d.\nOther char:%d\n", space, n, chr);
}

void p_cr() {
    int r_c = 0;
    char ch;
    printf("请输入一些字符：");
    while ((ch = getchar()) != '#') {
        r_c++;
        printf("%c->%d. ", ch, ch);
        if (r_c % 8 == 0)
            printf("\n");
    }
}

void num_count() {
    int j_num = 0;
    int o_num = 0;
    float j_t = 0;
    float o_t = 0;
    int num;
    printf("请输入一些数：");
    do {
        scanf("%d", &num);
        if (num % 2 == 0) {
            o_num++;
            o_t += num;
        } else {
            j_num++;
            j_t += num;
        }

    } while (num != 0);
    printf("       偶数          奇数\n");
    printf("数量 %6d%13d\n", o_num, j_num);
    printf("平均值 %4.1f%13.1f\n", o_t / (float) o_num, j_t / (float) j_num);

}


void alter() {
    char ch;
    int i = 0;
    printf("Please enter some chars:");
    while ((ch = getchar()) != '#') {
        if (ch == '.') {
            ch = '!';
            i++;
            putchar(ch);
        } else if (ch == '!') {
            putchar(ch);
            putchar(ch);
            i++;
        } else
            putchar(ch);
    };
    putchar('\n');
    printf("Total alter is %d.\n", i);
}


void ei_count() {
    int i = 0;
    char ch;
    char pre;
    bool isE;
    printf("Please enter a string:");
    while ((ch = getchar()) != '#') {
        if (ch == 'i' && pre == 'e')
            i++;
        pre = ch;

    }
    printf("Total:%d", i);
}

void my_menu() {
    int choice;
    bool isQ;
    p_h(65);
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.15/hr                           2) $9.33/hr\n");
    printf("3) $10.00/hr                           4) $11.20/hr\n5) quit\n");
    p_h(65);
    while (scanf("%d",&choice)){
        if (choice<1 || choice >5){
            printf("Error!Please enter a correct number:\n");
            continue;
        }
        switch (choice) {//TODO
            case 1:
                ;
                break;
            case 2:
                ;
                break;
            case 3:
                ;
                break;
            case 4:
                ;
                break;
            case 5:
                isQ = true;
                break;
            default:
                ;
        }
        if (isQ == true)
            break;
        else
            printf("Please enter next number:\n");
    }

}

void p_h(int n) {
    while (n) {
        printf("*");
        n--;
    }
    putchar('\n');
}


void p_prime(){
    unsigned long num;
    unsigned long i;
    printf("Please enter a num:");
    scanf("%lu",&num);
    for (i = 1;i<=num;i++){
        if (isPrime(i)){
            printf("%lu is one.\n",i);
        }
    }

}

bool isPrime(unsigned long num){
    bool prime = true;
    unsigned long i;
    for (i =2;i<num;i++){
        if(num % i == 0){
            prime =false;
            break;
        }
    }
    return prime;
}