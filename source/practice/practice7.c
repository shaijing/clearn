//
// Created by yulin on 2022/2/7.
//

#include "../../header/practice/practice7.h"

char * s_gets_p(char * st, int n){

    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val){
        while (*st != '\n' && *st!= '\0')
            st++;
        if (*st == '\n')
            *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

int strlens(const char str[]){
    int lens=0;
    for (int i = 0;  i>-1 ;i++) {
        if (*str!='\n'&& *str!= '\0'){
            lens++;
            str++;
        }
        else
            break;
    }
    return lens;
}

const char * spaceinstr(const char str[]){
    const char * ptr;
    ptr=NULL;
    for (int i = 0; true; ++i) {
        if(*str != ' ')
            str++;
        else{
            ptr = str;
            break;
        }
    }
    return ptr;
}

void strtoarray(int * ptr){

    int n;
    printf("Please enter the n:");
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; ++i) {
        *ptr = getchar();
        ptr++;
    }
/*    for (int i = 0; i < 5; ++i) {
        printf("%d\n",*(arr+i));
    }*/

}

void gettoarray(char arr[][80],int n){
    printf("enter:");
    for (int i = 0; i <n ; ++i) {
        scanf("%s",arr[i]);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%s\n",arr[i]);
    }
}
void gettoarray_dr(void){
    int n;
    printf("n:");
    scanf("%d",&n);
    char arr[n][80];
    gettoarray(arr,n);
}

char * s_chr(const char *ptr,int ch){
    for (int i = 0; true ; ++i) {
        if(*ptr==ch){
            break;
        }
        if(*ptr=='\0')
            break;
        ptr++;
    }

    return ((char *)ptr);
}
void s_chr_dr(void){
    char a[5]="abcd";
    char *p =s_chr(a,'b');
    printf("%s",p);
}

bool is_sithin(char *ptr,int ch){
    unsigned char c;
    c = (unsigned char) ch;
    bool res = false;
    for (int i = 0;true; ++i) {
        if(*ptr =='\0')//注意检查结尾
            break;
        if(*ptr==c){
            res = true;
            break;
        }
        ptr++;
    }

    return res;
}

void is_within_dr(void){
    printf("%d", is_sithin("asdfdsaf",'y'));
}

char * mystrncpy(char target[],const char source[],int n){
    printf("%d",strlen(target));
    for (int i = 0; i < n-1; ++i) {
        target[strlen(target)]=source[i];

    }
    target[strlen(target)+1]='\0';

    return (char*)target;
}
void mystrncpy_dr(void){
    char si[13]="abc";
    char s2[5]="defg";
    char * s = mystrncpy(si,s2,5);
    printf("%s",s);
}

char * string_in(const char *target,const char *mat){
    const char *ptr;
    ptr = NULL;
    bool isMatch = false;
    char ch1,ch2;
    int t;
    for (int i = 0; i < strlen(target); ++i) {
        if(*(target+i)== *mat){
            t=i;
            for (int j = 0; j < strlen(mat) ; ++j) {

                if ((ch1 =*(target+i+j))== (ch2=*(mat+j))) {
                    //printf("%c\n",*(target+i+j));
                    isMatch = true;
                }
                else {
                    isMatch = false;
                    break;
                }
            }
        }
        if(isMatch)
            ptr = target+t;
    }



    return (char*)ptr;


}
void string_in_dr(void){
    char *ptr = string_in("abcde","xy");
    printf("%s",ptr);
}

void str_rev(char * str){
    char t;
    unsigned long long left,right;
    left = 0;
    right =  strlen(str)-1;
    while (left<right){
        t = str[left];
        str[left] = str[right];
        str[right] = t;
        left++,right--;
    }
}
void str_rev_dr(void){
    char s1[4]="abc";//不能直接使用char *s1="abc"
    printf("%s \n",s1);
    str_rev(s1);
    printf("%s",s1);
}

void str_rev_1(char * str){
    char temp = str[0];
    int len = strlen(str);
    str[0] = str[len - 1];
    str[len - 1] = '\0';//末尾置1方便计算字符串长度以及置换其他位
    if (strlen(str)>1)
    {
        str_rev_1(str + 1);
    }
    str[len - 1] = temp;//将末尾置换
}
void str_rev_1_dr(void){
    char s1[4]="abc";//不能直接使用char *s1="abc"
    printf("%s \n",s1);
    str_rev_1(s1);
    printf("%s",s1);
}