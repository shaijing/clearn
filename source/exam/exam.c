//
// Created by Chaos on 2022/2/2.
//
#include "../../header/exam/exam.h"
void exam1(){//太复杂了。
    struct num_n{
        int num;
        int n;
    };
    int i,j,k,n;
    int temp;
    int n_s;
    printf("Please enter n:");
    n_s = scanf("%d",&n);
/*    if(n_s !=1){
        printf("Error!");
        printf("Please enter n:");
    }*/
    while (n>=1){

        if(n == 1){
            printf("Please enter the num:");
            scanf("%d",&temp);
            printf("%d 1",temp);
            break;
        }
        struct num_n num_count[n],temp_s;//初始化
        for (i=0;i<n;i++){
            num_count[i].num =0;
            num_count[i].n=0;
        }
        printf("Please enter these numbers:");
        for (j = 0; j <n ; j++) {//读取输入
            scanf("%d",&num_count[j].num);
            num_count[j].n++;

        }
        for (i = 0;i<n-1;i++)
            for (j =i;j<n-1;j++){
                if(num_count[j+1].num==num_count[i].num){
                    num_count[i].n++;
                    num_count[j+1].n =0;
                }
            }
        for (i = 0;i<n-1;i++)//排序
            for (j = 0; j < n-1; j++) {
                if (num_count[j].n<num_count[j+1].n){
                    temp_s = num_count[j];
                    num_count[j] = num_count[j+1];
                    num_count[j+1] = temp_s;
                }
            }
        int max_n = num_count[0].n;
        int max = num_count[0].num;
        for (i = 1;  i<n ;i ++) {
            if (num_count[i].n<max_n)
                break;
            if(max <num_count[i].num){
                max = num_count[i].num;
            }
        }
        printf("It's %d %d",max,max_n);
        break;
    }
}