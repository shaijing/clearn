//
// Created by yulin on 2022/1/15.
//
/*C Prime Plus , chapter 9*/
#include "../header/learn4.h"


#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

//
void show_n_char(char ch, int num){
    int count;

    for (count = 1; count <= num; count++)
        putchar(ch);
}

void change_value_pointer(int a,int b){
    printf("initial value is %d\t",a);
    value_location(a);
    *(&a) = b;
    printf("now value is %d\t",a);
    value_location(a);
}

void value_location(unsigned int num){//access the memory address of num
    printf( "The memory address of %d is %p \n",num,&num);
}
//


void ex_star_bar(){
    int spaces;

    show_n_char('*', WIDTH);   /* using constants as arguments */
    putchar('\n');
    show_n_char(SPACE, 12);    /* using constants as arguments */
    printf("%s\n", NAME);
    spaces = (WIDTH - strlen(ADDRESS)) / 2;
    /* Let the program calculate    */
    /* how many spaces to skip      */
    show_n_char(SPACE, spaces);/* use a variable as argument   */
    printf("%s\n", ADDRESS);
    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
    /* an expression as argument    */
    printf("%s\n", PLACE);
    show_n_char('*', WIDTH);
    putchar('\n');
}

void ex_recur(){
    up_and_down(1);
}
void up_and_down(int n){
    printf("Level %d: n location %p\n", n, &n); // 1
    if (n < 4)
        up_and_down(n+1);
    printf("LEVEL %d: n location %p\n", n, &n); // 2
}

void ex_two_ways_fact(void){
    int num;

    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        if (num < 0)
            printf("No negative numbers, please.\n");
        else if (num > 12)
            printf("Keep input under 13.\n");
        else
        {
            printf("loop: %d factorial = %ld\n",
                   num, loop_fact(num));
            printf("recursion: %d factorial = %ld\n",
                   num, recursion_fact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");
}
long loop_fact(int n){ // loop-based function
    long ans;

    for (ans = 1; n > 1; n--)
        ans *= n;

    return ans;
}
long recursion_fact(int n){ // recursive version
    long ans;

    if (n > 0)
        ans= n * recursion_fact(n-1);
    else
        ans = 1;

    return ans;
}

void ex_decimal_to_binary(){
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");

}
void to_binary(unsigned long n)   /* recursive function */
{
    int r;

    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
    putchar(r == 0 ? '0' : '1');

    return;
}

void ex_hotel(void){
    int nights;
    double hotel_rate;
    int code;

    while ((code = menu()) != QUIT)
    {
        switch(code)
        {
            case 1 : hotel_rate = HOTEL1;
                break;
            case 2 : hotel_rate = HOTEL2;
                break;
            case 3 : hotel_rate = HOTEL3;
                break;
            case 4 : hotel_rate = HOTEL4;
                break;
            default: hotel_rate = 0.0;
                printf("Oops!\n");
                break;
        }
        nights = getnights();
        showprice(hotel_rate, nights);
    }
    printf("Thank you and goodbye.\n");
}

int menu(void)
{
    int code, status;

    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms           2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza        4) The Stockton\n");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);
    while ((status = scanf("%d", &code)) != 1  ||
           (code < 1 || code > 5))
    {
        if (status != 1)
            scanf("%*s");   // dispose of non-integer input
        printf("Enter an integer from 1 to 5, please.\n");
    }

    return code;
}

int getnights(void)
{
    int nights;

    printf("How many nights are needed? ");
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");       // dispose of non-integer input
        printf("Please enter an integer, such as 2.\n");
    }

    return nights;
}

void showprice(double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
        total += rate * factor;
    printf("The total cost will be $%0.2f.\n", total);
}


void ex_value_location(void){
    int pooh = 2, bah = 5;             /* local to main()   */

    printf("In main(), pooh = %d and &pooh = %p\n",pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n",bah, &bah);
    mikado(pooh);

}
void mikado(int bah)                   /* define function   */
{
    int pooh = 10;                     /* local to mikado() */

    printf("In mikado(), pooh = %d and &pooh = %p\n",pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n",bah, &bah);
}


void ex_value_change(){
    int x = 5, y = 10;

    printf("Originally x = %d and y = %d.\n", x , y);
    interchange(&x, &y);
    printf("Now x = %d and y = %d.\n", x, y);


}
void interchange(int * u, int * v){
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}