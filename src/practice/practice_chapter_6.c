//
// Created by Chaos on 2022/1/30.
//

#include "practice/practice_chapter_6.h"

void p_a() {
    char alphabet[26] = {97, 98, 99, 100, 101, 102, 103,
                         104, 105, 106, 107, 108, 109, 110,
                         111, 112, 113, 114, 115, 116, 117,
                         118, 119, 120, 121, 122};
    int i, j, k;
    for (i = 0; i < 26; i++)
        printf("%c", alphabet[i]);
    printf("\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < i + 1; j++)
            printf("*");
        printf("\n");
    }
    for (i = 0; i < 6; i++) {
        for (j = 0, k = 'F'; j < i + 1; j++, k--)
            printf("%c", k);
        printf("\n");
    }
    for (i = 0, k = 'A'; i < 6; i++) {
        for (j = 0; j < i + 1; j++, k++)
            printf("%c", k);
        printf("\n");
    }

}

void d_p() {//wo gan ou
    char i;
    int j, k, t;
    char c;
    printf("Please enter a letter:");
    scanf("%c", &c);
    for (i = 'A'; i <= c; i++) {
        for (j = c - i; j > 0; j--) {
            printf("%c", ' ');
        }
        for (k = 'A'; k <= i; k++) {
            printf("%c", k);
        }
        for (t = i - 1; t >= 'A'; t--) {
            printf("%c", t);
        }
        printf("\n");

    }
}


void in_pu_al() {
    char word[21];
    unsigned long long i;
    printf("Please enter a word:");
    scanf("%s", word);
    printf("It's:");
    for (i = strlen(word); i > 0; i--) {
        printf("%c", word[i - 1]);
    }
}

void sum_pow() {
    int lower, upper;
    unsigned long long res = 0;
    printf("Please enter lower and upper integer limits:");
    while (scanf("%d,%d", &lower, &upper)) {
        if (lower > upper) {
            printf("Bye!");
            break;
        }
        for (long i = lower; i <= upper; i++)
            res += my_pow_n(i, 2);
        printf("The result is %llu\n", res);
        printf("Please enter lower and upper integer limits:");
    }
}

void p_int(void) {
    int it[8];
    int i = 0;
    printf("Please enter 8 nums:");
    do {
        scanf("%d", &it[i++]);
    } while (i < 8);
    for (i = 7; i >= 0; i--)
        printf("%d\n", it[i]);
}


void seq_s(void) {
    const double mi = 1.0;
    double i_end;
    double res = 0;
    printf("Please enter a double value:");
    scanf("%lf", &i_end);
    for (int i = 1; i <= i_end; i++) {
        res += (mi) / i;
    }
    printf("%f", res);
}

void seq_s_r() {
    const double mi = 1.0;
    double i_end;
    double res = 0;
    printf("Please enter a double value:");
    scanf("%lf", &i_end);
    for (int i = 1; i <= i_end; i++) {
        res += (double) my_pow_f(-1, i - 1) * (mi) / i;
    }
    printf("%f", res);
}

void pow_ay(void) {
    int di[8];
    int i, j, k;
    for (i = 2, k = 0; k < 8; k++, i = i * 2) {
        di[k] = i;
    }
    j = 0;
    do {
        printf("%d\n", di[j++]);
    } while (j < 8);
}

void s_i_ay() {
    int a1[8], a2[8], i, j, k;
    printf("Please enter 8 nums:");
    i = 0;
    do {
        scanf("%d", &a1[i++]);
    } while (i < 8);
    for (j = 0; j < 8; j++) {
        int res = 0;
        for (k = 0; k <= j; k++) {
            res += a1[k];
        }
        a2[j] = res;
    }
    for (i = 0; i < 8; i++)
        printf("%3d ", a1[i]);
    printf("\n");
    for (i = 0; i < 8; i++)
        printf("%3d ", a2[i]);

}

void i_o_r() {
    char c1[225];
    char c, h;
    int i = 0;
    printf("Please enter a string:");
    scanf("%s", c1);
    for (i = (int) strlen(c1) - 1; i >= 0; i--)
        printf("%c", *(c1 + i));
}


void d_d() {
    long double da, de;
    da = 100;
    de = 100;
    int i;
    for (i = 1; true; i++) {
        da += i * 10;
        de *= 1.05;
        if (de > da) {
            printf("After %d years,D has the money %Lf.Deirdre has the money:%Lf.\n", i, da, de);
            break;
        }
    }
}


void chuckie() {
    double my = 100;
    int i;
    for (i = 1; true; i++) {
        my = my * 1.08 - 10;
        if (my < 0) {
            printf("After %d years, Chuckie will use out the money.", i);
            break;
        }

    }
}


void rabnud() {
    int b_f = 5;
    int i;
    for (i = 1; i > -1; i++) {
        b_f = (b_f - i) * 2;
        if (b_f > 150) {
            printf("After %d weeks.Dr.Rabnud has the frindes exceeded 150.It's %d.\n ", i, b_f);
            break;
        }
    }
}