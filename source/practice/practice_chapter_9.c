//
// Created by Chaos on 2022/2/2.
//

#include "../../header/practice/practice_chapter_9.h"

int max_3num(int n1, int n2, int n3) {
    int max = n1;
    if (n2 > max)
        max = n2;
    if (n3 > max)
        max = n3;
    return max;
}

int min_3num(int n1, int n2, int n3) {
    int min = n1;
    if (n2 < min)
        min = n2;
    if (n3 < min)
        min = n3;
    return min;
}


void max_3num_1(int *n1, int *n2, int *n3) {
    int array[3] = {*n1, *n2, *n3};
    bubble_sort(array, 3);
    *n1 = array[0];
    *n2 = array[1];
    *n3 = array[2];

}

void crk_nv(void) {
    struct ck_nv {
        char ch;
        char chU;
        int n;
    };
    typedef struct ck_nv c_r;
    c_r char_n[26];
    int i, j;
    for (i = 0; i < 26; i++) {
        char_n[i].ch = 'a' + i;
        char_n[i].chU = 'A' + i;
        char_n[i].n = i + 1;
    }
    printf("Plsase enter a char:");
    char temp;
    while (scanf(" %c", &temp) && temp != '#') {
        if (isalpha(temp)) {
            for (i = 0; i < 26; i++)
                if (char_n[i].ch == temp || char_n[i].chU == temp) {
                    printf("%c : %d\n", temp, char_n[i].n);
                }
        } else {
            printf("Error!\n");
            printf("Plsase enter a char:");
            continue;
        }
        printf("Plsase enter next char:");
    }
}

double power_p(double num, int n) {
    double res = 1.0;
    if (num == 0) {
        printf("0^%d is not defined.\n", n);
    } else
        for (int i = 0; i < n; ++i) {
            res *= num;
        }
    return res;
}

double power_p_r(double num, int n) {
    if (n == 0)
        return 1.0;
    else
        return num * power_p_r(num, n - 1);
}

void to_binary_base(void) {
    int number;
    int b;
    int count;

    printf("Enter an integer (q to quit):\n");
    while (scanf("%d", &number) == 1) {
        printf("Enter number base (2-10): ");
        while ((count = scanf("%d", &b)) == 1
               && (b < 2 || b > 10)) {
            printf("base should be in the range 2-10: ");
        }
        if (count != 1)
            break;
        printf("Base %d equivalent: ", b);
        to_base_n(number, b);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");
}

void to_base_n(int x, int base) {/* recursive function */
    int r;
    r = x % base;
    if (x >= base)
        to_base_n(x / base, base);
    putchar('0' + r);
}