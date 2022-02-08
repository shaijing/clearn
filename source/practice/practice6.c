//
// Created by Chaos on 2022/2/4.
//

#include "../../header/practice/practice6.h"

void to_show(void){
    //show((double []) {8, 3, 9, 2}, 4);
    //show2((double [][3]){{8,3,9},{5,4,1}},2);
}

void copy_array(void){
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1,source,5);
    copy_ptr(target2,source,5);
    copy_ptrs(target3,source,5);
    printf("Target1:");
    for (int i = 0; i <5 ; ++i) {
        printf("%lf ",target1[i]);
    }
    putchar('\n');
    printf("Target2:");
    for (int i = 0; i <5 ; ++i) {
        printf("%lf ",target2[i]);
    }
    putchar('\n');
    printf("Target3:");
    for (int i = 0; i <5 ; ++i) {
        printf("%lf ",target3[i]);
    }
    putchar('\n');
}

void copy_arr(double target[],const double source[],int n){
    int i;
    for (i=0;i<n;i++){
        target[i] = source[i];
    }
}
void copy_ptr(double target[],double source[],int n){
    int i;
    double *pr_s;
    double *pr_t;
    pr_s = source;
    pr_t = target;
    for (i=0;i<n;i++){
        *(pr_t+i) = *(pr_s+i);
    }
}
void copy_ptrs(double target[],double source[],int n){
    int i;
    double *pr_s;
    double *pr_t;
    pr_s = source;
    pr_t = target;
    for (i=0;i<n;i++){
        *pr_t = *pr_s;
        pr_s++,pr_t++;
    }
}

void scan_max(void){
    int n,i;
    printf("Please enter the n:");
    scanf("%d",&n);
    int ar[n];

    printf("Please enter theses nums:");
    for(i =0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    int max =ar[0];
    for (i=1; i < n; i++){
        if (ar[i]>max){
            max = ar[i];
        }
    }
    printf("Max value: %d",max);
}

void d_sort(void){
    int n,i;
    scanf("%d",&n);
    double nums[n];
    for (i=0;i<n;i++){
        scanf("%lf",&nums[i]);
    }
    bubble_sort_d_f(nums,n);
    for (int j = 0; j < n; ++j) {
        printf("%lf ",nums[j]);
    }
}

void copy_2d_arr(void){
    double source[2][2]={
            {1,2},
            {3,4}
    };
    double target[2][2];
    for (int i = 0; i <2 ; ++i) {
        copy_arr(target[i],source[i],2);
    }
    printf("Source:");
    for (int i = 0; i <2 ; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%lf ",source[i][j]);
        }
    }
    putchar('\n');
    printf("Target:");
    for (int i = 0; i <2 ; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%lf ",target[i][j]);
        }
    }
}

void copy_arr_part(void){
    double source[7] = {1,2,3,4,5,6,7};
    double target[3];
    copy_ptr(target,(source+3),3);
    printf("Target:");
    for (int i = 0; i < 3; ++i) {
        printf("%lf ",target[i]);
    }
}

void cp_2darr_f(int m,int n,double target[][n],double source[][n]){
    for (int i = 0; i <m ; ++i) {
        for (int j = 0; j < n; ++j) {
            target[i][j] = source[i][j];
        }
    }
}
void cp_2darr(void){
    double source[2][2]={
            {1,2},
            {3,4}
    };
    double target[2][2];
    cp_2darr_f(2,2,target,source);
    printf("Target:");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <2 ; ++j) {
            printf("%lf",target[i][j]);
        }
    }
}

void sum_arr(void){
    int a1[4]={1,2,3,4};
    int a2[4]={1,2,3,4};
    int a3[4];
    sum_arr_f(a1,a2,a3,4);
    for (int i = 0; i <4 ; ++i) {
        printf("%d ",a3[i]);
    }
}

void sum_arr_f(const int a1[],const int a2[],int a3[],int n){
    for (int i = 0; i <n ; ++i) {
        a3[i] = a1[i]+a2[i];
    }
}

void dr_13(void){
    get_arr();
}

void get_arr(void){
    printf("Please enter 3 num array,each have 5 num:");
    double a[3][5];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%lf",&a[i][j]);
        }
    }
    printf("Get done!\n");
    double ao1 = ca_av_o(a[0],5);
    double ao2 = ca_av_o(a[1],5);
    double ao3 = ca_av_o(a[2],5);
    double res_o[3]={ao1,ao2,ao3};
    p_r(res_o,3, ca_av_a(a,3), g_max(a,3));
}

double ca_av_o(const double a[],int n){
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum/n;
}

double ca_av_a(double a[][5],int n){
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <5 ; ++j) {
            sum+=a[i][j];
        }
    }
    return sum/(n*5);
}

double g_max(double a[][5],int n){
    double max = a[0][0];
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i][j]>max)
                max = a[i][j];
        }
    }
    return max;
}

void p_r(double avo[],int n,double ava,double max){
    for (int i = 0; i <n ; ++i) {
        printf("Average one is:%lf\n",avo[i]);
    }
    printf("Average of all is:%lf\n",ava);
    printf("Max value is:%lf",max);
}