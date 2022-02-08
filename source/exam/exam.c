//
// Created by Chaos on 2022/2/2.
//
#include "../../header/exam/exam.h"

void exam1_ref(void){//有些冗余，以后再想想怎样优化 TODO 这个参考答案有问题，不能对出现次数相同的做出正确判断。
    int n,i=0,j,tmp,count,max=0;
    scanf("%d",&n);
    if (n==1){
        scanf("%d",&tmp);
        printf("%d 1\n",tmp);
    }
    int s[n+1],l[n+1]; //s[]存储次数，下标表示出现了多少次，相对应的出现这么多次的整数值
    while(n>=1){
        count=1;
        scanf("%d",&tmp);
        l[i++]=tmp; //l[]存储输入的整数值，下标从0开始
        for(j=0;j<i-1;j++){
            if (tmp==l[j]){
                s[++count]=tmp; //下标从2开始，因为目标数字唯一，其他循环时不会到s[max],即已有下标最大存储了值的空间
            }
        }
        if(count>max){
            max=count; //更新max
        }
        n--;
    }
    printf("%d %d\n",s[max],max);
}
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


void exam1_1(void){
    struct num_n{
            int num;
            int n;
    };
    typedef struct num_n NUMN;

    int i_n,e_n,t_n,temp;
    int i;
    int j;

    printf("Please enter the n:");
    while (scanf("%d",&i_n)){
        if (i_n==1){
            printf("Please enter the number:");
            scanf("%d",&temp);
            printf("%d 1",temp);
            break;
        }
        NUMN numn[i_n];
        for (i=0;i<i_n;i++){
            numn[i].num =0;
            numn[i].n=0;
        }
        printf("Please enter nums:");
        e_n = i_n;
        for (i=0;i<i_n;i++){
            t_n = i;
            scanf("%d",&temp);
            for (j=0;j<i;j++){
                if (temp==numn[j].num) {
                    t_n = j;
                    e_n--;
                }

            }
            numn[t_n].num=temp;
            numn[t_n].n++;
        }
        for (i = 0;i<e_n-1;i++)
            for (j=0;j<e_n-1;j++){
                if (numn[j].n<numn[j+1].n){
                    NUMN t_temp;
                    t_temp = numn[j];
                    numn[j] = numn[j+1];
                    numn[j+1]= t_temp;
                } else if(numn[j].n==numn[j+1].n&&numn[j].num<numn[j+1].num){
                    NUMN t_temp;
                    t_temp = numn[j];
                    numn[j] = numn[j+1];
                    numn[j+1]= t_temp;
                }
            }
        printf("%d %d次。\n",numn[0].num,numn[0].n);
        getchar();//处理换行符
        printf("Please enter next n:");
    }

}

void exam2(void){
    char a[14];
    int sum =0;
    int count =1;
    for (int i = 0; i < 13; ++i) {
        scanf("%c",&a[i]);
    }
    for (int i = 0; i < 11; ++i) {
        if (a[i]==45)
            continue;
        sum +=(a[i]-48)*count;
        count++;
    }
    if((a[12]-48)==sum%11)
        printf("Right!\n");
    else{
        for (int i = 0; i < 12; ++i)
            printf("%c",a[i]);
        printf("%c\n",(sum%11==10)?'x':48+sum%11);

    }
}


void exam3(void){
    struct STUDENT{
        int id;
        char name[10];
        float grade1;
        float grade2;
        float grade3;
        float ave;
    };
    int n;
    printf("Please enter tne n:");
    scanf("%d",&n);
    struct STUDENT student[n],temp;
    printf("Please enter the value:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %s %f %f %f",&student[i].id,student[i].name,&student[i].grade1,&student[i].grade2,&student[i].grade3);
        student[i].ave=(student[i].grade1+student[i].grade2+student[i].grade3)/3;
    }
    for (int i = 0; i <n-1 ; ++i) {
        for (int j = 0; j <n-1 ; ++j) {
            if (student[j].ave<student[j+1].ave){
                temp = student[j];
                student[j]= student[j+1];
                student[j+1]=temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d,%s,%.2f\n",student[i].id,student[i].name,student[i].ave);
    }
}