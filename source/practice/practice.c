//
// Created by Chaos on 2022/1/28.
//
#include "../../headers/practice/practice.h"
void int_to_char(){
    int asciicode;
    printf("Please type an ASCII code value(ctrl^d to quit):");
    while(scanf("%d",&asciicode)){
        printf("Number %5d -> ASCII code is %c\n",asciicode,asciicode);
        printf("Please type an ASCII code value(ctrl^d to quit):");
    }

}


void gf_p(){
    float f;
    printf("Please enter a floating-point value(ctrl^d to quit):");
    while(scanf("%f",&f)){
        printf("fixed-point notation: %-+15.3f.\n",f);
        printf("exponential notation: % -15e.\n",f);
        printf("p-count notation: %-15a.\n\n",f);
        printf("Please enter a floating-point value(ctrl^d to quit):");
    }


}

void get_i_(){
    int a,b;
    printf("Please enter some numbers(ctrl^d to quit):");//such as 12,45, 89 , 98
    scanf("%d,%d",&a,&b);
    printf("%d %d\n",a,b);
    printf("Please enter some numbers(ctrl^d to quit):");//such as 12 45  89     98
    scanf("%d %d",&a,&b);
    printf("%d %d",a,b);
    printf("Please enter some numbers(ctrl^d to quit):");//such as 12 45  89     98
    scanf("%*d %d",&a);
    printf("%d",a);
}

void get_name(){
    char f_name[20];
    char l_name[20];
    printf("Please enter your first name:");
    scanf("%s",f_name);
    printf("Please enter your last name:");
    scanf("%s",l_name);
    printf("Hello! \"%s %s\"",f_name,l_name);
    printf("Hello! %20s %20s",f_name,l_name);
    printf("Hello! %s %s ",f_name,l_name);

}


void d_sd(){
    float speed,size,time;
    printf("Please enter the net speed(Mb/s) and the file size(Mb):");
    scanf("%f %f",&speed,&size);
    time = size/speed;
    printf("File: %.2fMb, Net speed:%.2fMb,Time:%.2fs\n",size,speed,time);

}

void p_n(){
    char f_name[20];
    char l_name[20];
    unsigned long long a,b;
    printf("Please enter your first name:");
    scanf("%s",f_name);
    printf("Please enter your last name:");
    scanf("%s",l_name);
    a = strlen(f_name);
    b = strlen(l_name);
    printf("Hello! %10s %10s\n",f_name,l_name);
    printf("Hello! %10llu %10llu\n",a,b);
    printf("Hello! %-10s %-10s\n",f_name,l_name);
    printf("Hello! %-10llu %-10llu\n",a,b);
}


void mult_table(){
    const int a =10;
    int i,j;
    for (i=1;i<a;i++){
        for (j = 1;j<i+1;j++) {
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
}


void gcd(){
    int m,n,r;
    int a,b;
    printf("(GCD)Please enter two numbers:");
    scanf("%d,%d",&m,&n);
    a = (m>n) ? m:n;
    b = (m>n) ? n:m;
    r = a % b;
    while(r){
        a = b;
        b = r;
        r = a % b;
        printf("%d",r);
    }
    printf("The max common divisor of %d and %d is %d",m,n,b);
}

void s_to_h(void){
    const int S_P_M = 60;
    const int M_P_H = 60;
    unsigned long s;
    int s_t;
    int h,m,m_t;
    printf("Please enter the seconds(ctrl^d to quit):");
    while(scanf("%lu",&s)){
        m = (int)(s /S_P_M);
        s_t = (int)(s % S_P_M);
        h = m /M_P_H;
        m_t = m % M_P_H;
        printf("So, it's %d:%d:%d\n",h,m_t,s_t);
        printf("Please enter the seconds(ctrl^d to quit):");
    }
}

unsigned long long my_pow_n(long num,int n){
    unsigned long long total =1;
    int i;
    for (i =0;i<n;i++){
        total = total * num;
    }
    return total;
}

long double my_pow_f(double num,int n){//when you are using mingw, you must use __mingw_printf() instead of printf()
    long double total = 1;
    int i;
    for (i =0;i<n;i++){
        total = total *(long double) num;
    }
    return total;
}

void modulo(){
    int m,n;
    printf("Please enter an integer as the second operand:");
    while(scanf("%d",&n)){
        printf("Now enter the first operand:");
        scanf("%d",&m);
        printf("%d %% %d = %d\n",m,n,m%n);
        printf("Please enter an integer as the second operand:");
    }
}

void temp_t(){
    double in_t;//input
    double ot_t;//input temperature
    char in_c;//input notation
    char in_tc;//translate notation
    printf("Please enter a temperature including notation:");
    while(scanf("%lf%c %c", &in_t, &in_c, &in_tc)){
        switch (in_c) {
            case 'c':
            case 'C':
                ot_t = c_to_fk(in_t,in_tc);
                break;
            case 'f':
            case 'F':
                ot_t = f_to_ck(in_t,in_tc);
                break;
            case 'k':
            case 'K':
                ot_t = k_to_cf(in_t,in_tc);
                break;
            default:
                printf("Error!\n");
        }

        printf("%.3f%c is %.3f%c\n",in_t,in_c,ot_t,in_tc);
        printf("Please enter another temperature including notation:");
    }

}
double c_to_fk(double te,char cr){
    double res;
    if (cr == 'f' || cr == 'F')
        res = te * 1.8 + 32;
    else
        res = te + 273.16;
    return res;
}
double f_to_ck(double te,char cr){
    double res;
    if (cr == 'k' || cr == 'K')
        res = 5.0/9.0*(te-32)+273.16;
    else
        res = (te-32)/1.8;
    return res;
}
double k_to_cf(double te,char cr){
    double res;
    if (cr == 'c' || cr == 'C')
        res =te - 273.16;
    else
        res = (te-273.16)*1.8+32;
    return res;
}
