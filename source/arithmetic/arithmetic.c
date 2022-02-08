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
    int i, j;
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

void bubble_sort_d_f(double num[],int n){
    int i, j;
    double temp;
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


void quick_sort(void){
    int i,j,n;

    scanf("%d",&n);
    double ar[n];
    for (i = 0;i  <n ;i++) {
        scanf("%lf",&ar[i]);
    }
    quick_sotr_f(0,n,ar);
    for (j = 0; j <n ;j ++) {
        printf("%lf ",ar[j]);
    }
}
void quick_sotr_f(int left,int right,double ar[]){//有问题 TODO
    double temp,t;
    int i,j;
    if (left>right)
        return;
    temp = ar[left];
    i=left,j=right;
    while (i!=j){
        while (ar[j]>=temp && i<j)
            j--;
        while (ar[i]<=temp &&i<j)
            i++;
        if (i<j){
            t = ar[i];
            ar[i] = ar[j];
            ar[j]=t;
        }
    }
    ar[left] = ar[i];
    ar[i] = temp;
    quick_sotr_f(left,i-1,ar);
    quick_sotr_f(i+1,right,ar);
}