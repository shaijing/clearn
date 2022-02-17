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

void bubble_sort_dr() {
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

void bubble_sort(int num[], int n) {
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

void bubble_sort_d_f(double num[], int n) {
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

void selection_sort(int arr[], int len) {
    int temp, n;
    for (int i = 0; i < len; ++i) {
        int min = arr[i];
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < min) {
                min = arr[j];
                n = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[n];
        arr[n] = temp;
    }

}

void selection_sort_dr(void) {
    int a[10] = {8, 99, -1, 55, -20, 30, 40, 11, 18, 20};
    selection_sort(a, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
}

void insertion_sort(int num[], int len) { //didn't comprehension
    int i, j, temp;
    for (i = 1; i < len; i++) {
        temp = num[i];
        for (j = i; j > 0 && num[j - 1] > temp; j--)
            num[j] = num[j - 1];

    }
}

void insertion_sort_dr(void) {

}

void quick_sort_dr(void) {
    int i, j, n;

    scanf("%d", &n);
    double ar[n];
    for (i = 0; i < n; i++) {
        scanf("%lf", &ar[i]);
    }
    quick_sort(0, n - 1, ar);/* Must pay attention to the argument n-1 */
    for (j = 0; j < n; j++) {
        printf("%lf ", ar[j]);
    }
}

void quick_sort(int left, int right, double ar[]) {//
    double temp, t;
    int l, r;
    if (left > right)
        return;
    temp = ar[left];
    l = left, r = right;
    while (l != r) {
        while (ar[r] >= temp && l < r)
            r--;
        while (ar[l + 1] <= temp && l < r)
            l++;
        if (l < r) {
            t = ar[l];
            ar[l] = ar[r];
            ar[r] = t;
        }
    }
    ar[left] = ar[l];
    ar[l] = temp;
    quick_sort(left, l - 1, ar);
    quick_sort(r + 1, right, ar);
}