//
// Created by Chaos on 2022/2/1.
//
#include "arithmetic/arithmetic.h"


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
            printf("%d\n ", i);

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
        int min = arr[i]; // 记录最小值，第一个元素默认最小
        for (int j = i + 1; j < len; ++j) { // 访问未排序的元素
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
    int a[10] = { 8, 99, -1, 55, -20, 30, 40, 11, 18, 20 };
    selection_sort(a, (int)sizeof(a) / sizeof(*a));
    for (int i = 0; i < 10; ++i) {
        printf("%d ", a[i]);
    }
}

void insertion_sort(int arr[], int len) { //didn't comprehension
    int i, j, temp;
    for (i = 1;i < len;i++) {
        temp = arr[i];
        for (j = i;j > 0 && arr[j - 1] > temp;j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

void insertion_sort_dr(void) {
    int a[10] = { 9,6,8,3,0,4,5,7,1,2 };
    insertion_sort(a, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }


}

void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}
inline int min(int x, int y);
int min(int x, int y) {
    return x < y ? x : y;
}

void merge_sort(int arr[], int len) {
    int* a = arr;
    int* b = (int*)malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}
void quick_sort_dr(void) {
    int i, j, n;

    scanf("%d", &n);
    double ar[n];
    for (i = 0; i < n; i++) {
        scanf("%lf", &ar[i]);
    }
    //quick_sort(0, n - 1, ar);/* Must pay attention to the argument n-1 */
    for (j = 0; j < n; j++) {
        printf("%lf ", ar[j]);
    }
}

void quick_sort(int left, int right, int* ar) {//
    int temp, t;
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

void queue_easy(void) {
    int num[100] = { 6,3,1,7,5,8,9,2,4 };
    int head, tail;
    head = 0;
    tail = 9;
    while (head < tail) {
        printf("%d ", num[head]);
        head++;
        num[tail] = num[head];
        tail++;
        head++;
    }

}

void stack_easy(void) {
    char arr[101], s[101];
    int top = 0;
    unsigned long long len, mid, next, i, j;
    s_gets(arr, 101);
    len = strlen(arr);
    mid = len / 2 - 1;
    for (i = 0;i <= mid;i++) {
        s[++top] = arr[i];
    }
    if (len % 2 == 0)
        next = mid + 1;
    else
        next = mid + 2;

    for (j = next; j <= len - 1; ++j) {
        if (s[top] != arr[j])
            break;
        top--;
    }
    if (top == 0)
        printf("Yes!\n");
    else
        printf("No!\n");


}