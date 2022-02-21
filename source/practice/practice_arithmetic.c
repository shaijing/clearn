//
// Created by yulin on 2022/2/17.
//

#include "../../header/practice/practice_arithmetic.h"

void isbn_easy_1(void){
    int n;
    int arr[100] = {[0]=0};//Must initialize part of the array, the rest of the array would be initialized as 0
    int t;
    scanf("%d",&n);
    for (int i = 0; i <n ; ++i) {
        scanf("%d",&t);
        arr[t]=1;
    }
    for (int i = 0; i <100 ; ++i) {
        if(arr[i] == 1){
            printf("%d ",i);
        }
    }
}

void isbn_easy_2(void){
    int n;
    int t;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i <n ; ++i) {
        scanf("%d",(arr+i));
    }
    quick_sort(0,n-1,arr);
    for (int i = 0; i < n; ++i) {
        if (*(arr+i) !=*(arr+i+1) )
            printf("%d ",*(arr+i));
    }

}

