//
// Created by Chaos on 2022/2/1.
//
#include "../../header/arithmetic/arithmetic.h"


void bucket_sort() {/*桶排序简单版，浪费空间*/
    int array[11] = {};//注意先全部初始化为0
    int temp;
    int i, j;
    printf("Please enter some scores(0-10):");
    while (scanf("%d", &temp)) {
        array[temp]++;
    }
    for (i = 0; i < 10; i++)
        for (j = 0; j < array[i]; j++)
            printf("%d ", i);

}

void bubble_sort() {
    int n, i, j, k;
    int temp;
    printf("Please enter the n:");
    scanf("%d", &n);
    printf("Please enter numbers:");
/*        if(n == 1){
            scanf("%d",&temp);
            printf("%d 1",temp);
            break;
        }*/
    int array[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (k = 0; k < n; k++) {
        printf("%d<", array[k]);
    }
}

void bubble_sort_f(int num[],int n){
    int i, j, k;
    int temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}
