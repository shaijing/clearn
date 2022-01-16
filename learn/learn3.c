//
// Created by yulin on 2022/1/15.
//
#include "../header/learn3.h"
void ex_echo(void){
    char ch;

    while ((ch = getchar()) != '#')
        putchar(ch);
}


void ex_echo_eof(void){
    int ch;
    while ((ch =getchar()) != EOF)
        putchar(ch);/*It's not capable in clion, but Cmd */
}

void ex_file_eof(void){
    int ch;
    FILE * fp;
    char fname[50];         // to hold the file name

    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); // open file for reading
    if (fp == NULL)         // attempt failed
    {
        printf("Failed to open file. Bye\n");
        exit(0);            // quit program
    }
    // getc(fp) gets a character from the open file
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);             // close the file
}

void ex_guess(){
    int guess = 1;

    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with\n");
    printf("an n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while (getchar() != 'y')      /* get response, compare to y */
        printf("Well, then, is it %d?\n", ++guess);
    printf("I knew I could do it!\n");

}


void ex_new_guess(void){
    int guess = 1;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with\n");
    printf("an n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while ((response = getchar()) != 'y')     /* get response */
    {
        if (response == 'n')
            printf("Well, then, is it %d?\n", ++guess);
        else
            printf("Sorry, I understand only y or n.\n");
        while (getchar() != '\n')
            continue;                 /* skip rest of input line */
    }
    printf("I knew I could do it!\n");
}

void ex_show_char(void){
    int ch;             /* character to be printed    */
    int rows, cols;     /* number of rows and columns */
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        display((char)ch, rows, cols);
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}

void ex_show_char_1(void){
    int ch;             /* character to be printed      */
    int rows, cols;     /* number of rows and columns   */

    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        if (scanf("%d %d",&rows, &cols) != 2)
            break;
        display((char)ch, rows, cols);
        while (getchar() !=  '\n')
            continue;
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}
void display(char cr, int lines, int width){
    int row, col;

    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');  /* end line and start a new one */
    }
}

void ex_checking(void){
    const long MIN = -10000000L;  // lower limit to range
    const long MAX = +10000000L;  // upper limit to range
    long start;                   // start of range
    long stop;                    // end of range
    double answer;

    printf("This program computes the sum of the squares of "
           "integers in a range.\n"
           "The lower bound should not be less than -10000000 and\n"
           "the upper bound should not be more than +10000000.\n"
           "Enter the limits (enter 0 for both limits to quit):\n"
           "lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (start !=0 || stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else
        {
            answer = sum_squares(start, stop);
            printf("The sum of the squares of the integers ");
            printf("from %ld to %ld is %g\n",
                   start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both "
               "limits to quit):\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }
    printf("Done.\n");

}

long get_long(void)
{
    long input;
    char ch;

    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }

    return input;
}

double sum_squares(long a, long b)
{
    double total = 0;
    long i;

    for (i = a; i <= b; i++)
        total += (double)i * (double)i;

    return total;
}

bool bad_limits(long begin, long end,
                long low, long high)
{
    bool not_good = false;

    if (begin > end)
    {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %ld or less.\n", high);
        not_good = true;
    }

    return not_good;
}


char get_choice(void){
    int ch;

    printf("Enter the letter of your choice:\n");
    printf("a. advice           b. bell\n");
    printf("c. count            q. quit\n");
    ch = get_first();
    while (  (ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }

    return ch;

}
char get_first(void){
    int ch;

    ch = getchar();
    while (getchar() != '\n')
        continue;

    return ch;

}
int get_int(void){
    int input;
    char ch;

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }

    return input;

}
void count(void){
    int n,i;

    printf("Count how far? Enter an integer:\n");
    n = get_int();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while ( getchar() != '\n')
        continue;

}
void ex_menu(void){
    int choice;
    void count(void);

    while ( (choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a' :  printf("Buy low, sell high.\n");
                break;
            case 'b' :  putchar('\a');  /* ANSI */
                break;
            case 'c' :  count();
                break;
            default  :  printf("Program error!\n");
                break;
        }
    }
    printf("Bye.\n");
}