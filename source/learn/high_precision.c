//
// Created by Chaos on 2022/3/3.
//
#include "../../headers/learn/high_precision.h"

void addition(void){
    char num_s_1[LEN],num_s_2[LEN],sum_s[LEN];
    int num_1[LEN],num_2[LEN],sum[LEN];

    memset(num_1,0, sizeof(num_1));
    memset(num_2,0, sizeof(num_2));
    memset(sum,0, sizeof(sum));

    scanf("%s",num_s_1);

    while (getchar()!='\n')
        continue;

    size_t num_lens = strlen(num_s_1);
    printf("Input Ok:%s len:%zd\n",num_s_1,num_lens);

    size_t i,j;
    for (i = 0,j=LEN-1; i < num_lens; ++i,j--) {
        num_1[j] = atoi(&num_s_1[i]);//TODO wrong point
    }
    for (i = num_lens,j=LEN-1;i>0 ;i--,j--) {
        printf("%d",num_1[j]);
    }
}