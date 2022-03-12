//
// Created by Chaos on 2022/2/2.
//
#include "../../headers/exam/exam.h"

void exam1_ref(void) {//有些冗余，以后再想想怎样优化 TODO 这个参考答案有问题，不能对出现次数相同的做出正确判断。
    int n, i = 0, j, tmp, count, max = 0;
    scanf("%d", &n);
    if (n == 1) {
        scanf("%d", &tmp);
        printf("%d 1\n", tmp);
    }
    int s[n + 1], in_num[n + 1]; //s[]存储次数，下标表示出现了多少次，相对应的出现这么多次的整数值
    while (n >= 1) {
        count = 1;
        scanf("%d", &tmp);
        in_num[i++] = tmp; //l[]存储输入的整数值，下标从0开始
        for (j = 0; j < i - 1; j++) {
            if (in_num[j] == tmp) {
                s[++count] = tmp; //下标从2开始，因为目标数字唯一，其他循环时不会到s[max],即已有下标最大存储了值的空间
            }
        }
        if (count > max) {
            max = count; //更新max
        }
        n--;
    }
    printf("%d %d\n", s[max], max);
}

void exam1() {//太复杂了。
    struct num_n {
        int num;
        int n;
    };
    int i, j, k, n;
    int temp;
    int n_s;
    printf("Please enter n:");
    n_s = scanf("%d", &n);
/*    if(n_s !=1){
        printf("Error!");
        printf("Please enter n:");
    }*/
    while (n >= 1) {

        if (n == 1) {
            printf("Please enter the num:");
            scanf("%d", &temp);
            printf("%d 1", temp);
            break;
        }
        struct num_n num_count[n], temp_s;//初始化
        for (i = 0; i < n; i++) {
            num_count[i].num = 0;
            num_count[i].n = 0;
        }
        printf("Please enter these numbers:");
        for (j = 0; j < n; j++) {//读取输入
            scanf("%d", &num_count[j].num);
            num_count[j].n++;

        }
        for (i = 0; i < n - 1; i++)
            for (j = i; j < n - 1; j++) {
                if (num_count[j + 1].num == num_count[i].num) {
                    num_count[i].n++;
                    num_count[j + 1].n = 0;
                }
            }
        for (i = 0; i < n - 1; i++)//排序
            for (j = 0; j < n - 1; j++) {
                if (num_count[j].n < num_count[j + 1].n) {
                    temp_s = num_count[j];
                    num_count[j] = num_count[j + 1];
                    num_count[j + 1] = temp_s;
                }
            }
        int max_n = num_count[0].n;
        int max = num_count[0].num;
        for (i = 1; i < n; i++) {
            if (num_count[i].n < max_n)
                break;
            if (max < num_count[i].num) {
                max = num_count[i].num;
            }
        }
        printf("It's %d %d", max, max_n);
        break;
    }
}


void exam1_1(void) {
    struct num_n {
        int num;
        int n;
    };
    typedef struct num_n NUMN;

    int i_n, e_n, t_n, temp;
    int i;
    int j;

    printf("Please enter the n:");
    while (scanf("%d", &i_n)) {
        if (i_n == 1) {
            printf("Please enter the number:");
            scanf("%d", &temp);
            printf("%d 1", temp);
            break;
        }
        NUMN numn[i_n];
        for (i = 0; i < i_n; i++) {
            numn[i].num = 0;
            numn[i].n = 0;
        }
        printf("Please enter nums:");
        e_n = i_n;
        for (i = 0; i < i_n; i++) {
            t_n = i;
            scanf("%d", &temp);
            for (j = 0; j < i; j++) {
                if (temp == numn[j].num) {
                    t_n = j;
                    e_n--;
                }

            }
            numn[t_n].num = temp;
            numn[t_n].n++;
        }
        for (i = 0; i < e_n - 1; i++)
            for (j = 0; j < e_n - 1; j++) {
                if (numn[j].n < numn[j + 1].n) {
                    NUMN t_temp;
                    t_temp = numn[j];
                    numn[j] = numn[j + 1];
                    numn[j + 1] = t_temp;
                } else if (numn[j].n == numn[j + 1].n && numn[j].num < numn[j + 1].num) {
                    NUMN t_temp;
                    t_temp = numn[j];
                    numn[j] = numn[j + 1];
                    numn[j + 1] = t_temp;
                }
            }
        printf("%d %d次。\n", numn[0].num, numn[0].n);
        getchar();//处理换行符
        printf("Please enter next n:");
    }

}

void exam1_2(void) {

}

void exam2(void) {
    char a[14];//contain the isbn code,including '\0'
    int sum = 0;//sum of num
    int count = 1;//location_n
    scanf("%s", a);
    for (int i = 0; i < 11; ++i) {
        if (a[i] == '-')
            continue;
        sum += (a[i] - 48) * count++;
    }
    int end = sum % 11;
    if ((a[12]) ==
        ((end == 10) ? 'X' : 48 + sum % 11))//pay attention to the operating order， use parentheses '()' to ensure it.
        printf("Right\n");
    else {
        for (int i = 0; i < 12; ++i)
            printf("%c", a[i]);
        printf("%c\n", (end == 10) ? 'X' : 48 + sum % 11);

    }
}

int mycmp(const void *p1, const void *p2) {
    stu * ptr_1 = (stu*)p1;
    stu * ptr_2 = (stu*)p2;
    float ave_1 = ptr_1->ave;
    float ave_2 = ptr_2->ave;
    if(ave_1<ave_2)
        return 1;
    else if(ave_1==ave_2)
        return 0;
    else
        return -1;
}

void exam3(void) {
    int n;
    printf("Please enter tne n:");
    scanf("%d", &n);
    struct STUDENT student[n], temp;
    printf("Please enter the value:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %f %f %f", &student[i].id, student[i].name, &student[i].grade1, &student[i].grade2,
              &student[i].grade3);
        student[i].ave = (student[i].grade1 + student[i].grade2 + student[i].grade3) / 3;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (student[j].ave < student[j + 1].ave) {
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d,%s,%.2f\n", student[i].id, student[i].name, student[i].ave);
    }
}

void exam3_1(void) {
    int n;
    printf("Please enter tne n:");
    scanf("%d", &n);
    struct STUDENT student[n], temp;
    printf("Please enter the value:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %f %f %f", &student[i].id, student[i].name, &student[i].grade1, &student[i].grade2,
              &student[i].grade3);
        student[i].ave = (student[i].grade1 + student[i].grade2 + student[i].grade3) / 3;
    }
    qsort(&student[0],n, sizeof(stu),mycmp);
    for (int i = 0; i < n; ++i) {
        printf("%d,%s,%.2f\n", student[i].id, student[i].name, student[i].ave);
    }
}

int DigitNum(const char *str) {
    int n = 0;
    int i = 0;
    while (*(str + i) != '\0') {
        if ('0' <= (*(str + i)) && (*(str + i)) <= '9')
            n++;
        i++;
    }
    return n;


}

void DigitNum_dr(void) {
    printf("%d", DigitNum("123ABC"));
}

void question_2(void) {
    int num[10] = {10, 9, 5, 4, -1, 50, 4, 8, 6, 9};
    int min = num[0];
    int t_n;
    for (int i = 0; i < 10; ++i) {
        if (num[i] < min) {
            min = num[i];
            t_n = i;
        }
    }
    int t;
    t = num[0];
    num[0] = num[t_n];
    num[t_n] = t;
    for (int i = 0; i < 10; ++i) {
        printf("%d ", num[i]);
    }
}