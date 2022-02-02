//
// Created by Chaos on 2022/1/19.
//
/*C Prime Plus , chapter 10*/
#include "../../header/learn/learn6.h"


void ex_strings(void){
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81
    char words[MAXLENGTH] = "I am a string in an array.";
    const char * pt1 = "Something is pointing at me.";
    puts("Here are some strings:");
    puts(MSG);
    puts(words);
    puts(pt1);
    words[8] = 'p';
    puts(words);
}


void ex_string_is_pointer(void){/*strings as pointers*/
    printf("%s, %p, %c\n", "We", "are", *"space farers");
}

void ex_address_of_string(void){
#undef MSG
#define MSG "I'm special."
    char ar[] = MSG;
    const char *pt = MSG;
    printf("address of \"I'm special\": %p \n", "I'm special");
    printf("              address ar: %p\n", ar);
    printf("              address pt: %p\n", pt);
    printf("          address of MSG: %p\n", MSG);
    printf("address of \"I'm special\": %p \n", "I'm special");
}

void ex_two_types_array(void){
#define SLEN 40
#define LIM 5
    const char *mytalents[LIM] = {
            "Adding numbers swiftly",
            "Multiplying accurately", "Stashing data",
            "Following instructions to the letter",
            "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
            "Walking in a straight line",
            "Sleeping", "Watching television",
            "Mailing letters", "Reading email"
    };
    int i;

    puts("Let's compare talents.");
    printf ("%-36s  %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++)
        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof my talents: %zd, sizeof your talents: %zd\n",sizeof(mytalents), sizeof(yourtalents));
}


void point_string(void){
    const char * mesg = "Don't be a fool!";
    const char * copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n",mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n",copy, &copy, copy);
}


void ex_gets_puts(void){
#define STLEN 81
    char words[STLEN];

    puts("Enter a string, please.");
    gets(words);  // typical use
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");
}


void ex_fgets_fputs_1(void){
#undef STLEN
#define STLEN 14
    char words[STLEN];

    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
}


void ex_fgets_fputs_2(void){
#undef STLEN
#define STLEN 10
    char words[STLEN];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL
           && words[0] != '\n')
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
        puts(words);
    }
    puts("done");
}


void ex_scan_str(void){
    char name1[11], name2[11];
    int count;

    printf("Please enter 2 names.\n");
    count = scanf("%5s %10s",name1, name2);
    printf("I read the %d names %s and %s.\n",count, name1, name2);

}


/*11.3 string output*/
//11.3.1 puts() function
void ex_put_out(){
#define DEF "I am a #defined string."
    char str1[80] = "An array was initialized to me.";
    const char * str2 = "A pointer was initialized to me.";

    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2+4);
}


void ex_incorrect_put(void){
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!' };
    char side_b[] = "Side B";

    puts(dont);   /* dont is not a string */
}


//11.3.2 fputs() function
void ex_fput(){
    char line[81];
    while (fgets(line,81,stdin))
        fputs(line,stdout);
}
//11.3.3 printf() function


/*11.4 customize input/output function*/
void ex_put_put(){
    ex_put1("If I'd as much money");
    ex_put1(" as I could spend,\n");
    printf("I count %d characters.\n",ex_put2("I never would cry old chairs to mend."));
}
void ex_put1(const char * string){
    while (*string)/* same as *string != '\0' */
        putchar(*string++);
}
int ex_put2(const char * string){/*print string and count the char*/
    int count = 0;
    while (*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');//except the newline

    return(count);
}


void ex_string_fit(){/*try the string-shrinking function */
    char mesg[] = "Things should be as simple as possible,"
                  " but not simpler.";

    puts(mesg);
    fit(mesg,38);
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39);
}
void fit(char *string, unsigned int size){
    if (strlen(string) > size)
        string[size] = '\0';
}


//11..5.2 strcat() function
void ex_str_cat(){/*joins two strings*/
#undef SIZE
#define SIZE 80
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";

    puts("What is your favorite flower?");
    if (s_gets(flower, SIZE))
    {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("bye");

}


//11.5.3 strncat() function
void ex_join_check(){/*joins two strings, check size first*/
#undef SIZE
#define SIZE 30
#define BUGSIZE 13
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int available;

    puts("What is your favorite flower?");
    s_gets(flower, SIZE);
    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
        strcat(flower, addon);
    puts(flower);
    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);
}


void ex_str_compare(){
#undef SIZE
#define ANSWER "Grant"
#define SIZE 40
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (strcmp(try,ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");
}


//return value of strcmp() function
void ex_return_strcmp(){
    printf("strcmp(\"A\", \"A\") is ");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"B\") is ");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"B\", \"A\") is ");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp(\"C\", \"A\") is ");
    printf("%d\n", strcmp("C", "A"));

    printf("strcmp(\"Z\", \"a\") is ");
    printf("%d\n", strcmp("Z", "a"));

    printf("strcmp(\"apples\", \"apple\") is ");
    printf("%d\n", strcmp("apples", "apple"));
}


//whether the application should quit
void ex_quit(void){
#undef SIZE
#undef LIM
#define SIZE 80
#define LIM 10
#define STOP "quit"
    char input[LIM][SIZE];
    int ct = 0;

    printf("Enter up to %d lines (type quit to quit):\n", LIM);
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           strcmp(input[ct],STOP) != 0)
    {
        ct++;
    }
    printf("%d strings entered\n", ct);
}


void ex_custom_strcmp(){
#define LISTSIZE 6
    const char * list[LISTSIZE] =
            {
                    "astronomy", "astounding",
                    "astrophysics", "ostracize",
                    "asterism", "astrophobia"
            };
    int count = 0;
    int i;

    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i],"astro", 5) == 0)
        {
            printf("Found: %s\n", list[i]);
            count++;
        }
    printf("The list contained %d words beginning"
           " with astro.\n", count);
}


void ex_copy1(){
#undef SIZE
#undef LIM
#define SIZE 40
#define LIM 5
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {
            strcpy(qwords[i], temp);
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++)
        puts(qwords[i]);
}


void ex_copy2(){
#undef SIZE
#define WORDS  "beast"
#define SIZE 40
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);
}



void ex_copy3(void){
#undef SIZE
#undef LIM
#define SIZE 40
#define TARGSIZE 7
#define LIM 5
    char qwords[LIM][TARGSIZE];
    char temp[SIZE];
    int i = 0;

    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {
            strncpy(qwords[i], temp, TARGSIZE - 1);
            qwords[i][TARGSIZE - 1] = '\0';
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++)
        puts(qwords[i]);
}


void ex_sprintf(void){
#define MAX 20
    char first[MAX];
    char last[MAX];
    char formal[2 * MAX + 10];
    double prize;

    puts("Enter your first name:");
    s_gets(first, MAX);
    puts("Enter your last name:");
    s_gets(last, MAX);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts(formal);
}


void ex_sort_string(void){
#undef SIZE
#undef LIM
#define SIZE 81        /* string length limit, including \0  */
#define LIM 20         /* maximum number of lines to be read */
#define HALT ""        /* null string to stop input          */
    char input[LIM][SIZE];     /* array to store input       */
    char *ptstr[LIM];          /* array of pointer variables */
    int ct = 0;                /* input count                */
    int k;                     /* output count               */

    printf("Input up to %d lines, and I will sort them.\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL
           && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];  /* set ptrs to strings        */
        ct++;
    }
    stsrt(ptstr, ct);          /* string sorter              */
    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++)
        puts(ptstr[k]) ;       /* sorted pointers            */
}
/* string-pointer-sorting function */
void stsrt(char *strings[], int num) {
    char *temp;
    int top, seek;

    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top],strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}


//
void ex_mod_str(){
#define LIMIT 81
    char line[LIMIT];
    char * find;

    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');   // look for newline
    if (find)                    // if the address is not NULL,
        *find = '\0';            // place a null character there
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n",
           PunctCount(line));
}
void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
int PunctCount(const char * str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }

    return ct;
}
