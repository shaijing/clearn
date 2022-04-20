//
// Created by Chaos on 2022/1/2.
//
#include "learn/learn_chapter_7.h"

void ex_chr_op(void){
    char ch;
    const char CHR = ' ';
    ch = getchar();
    while (ch !='\n'){
        if (ch == CHR)
            putchar(ch);
        else
            putchar(ch+1);
        ch = getchar();
    }
    putchar(ch);
}

void ex_chr_op_cypher(void){
    char ch;
    while ((ch = getchar()) != '\n'){
        if (isalpha(ch))
            putchar(ch+1);
        else
            putchar(ch);
    }
    putchar(ch);
}

void ex_divisors(void){//This function is not work with 1.
    unsigned long long num;
    unsigned long long  div;
    bool isPrime;
    printf("Please enter an integer for analysis(q to quit):");
    while (scanf("%llu",&num) == 1){
        for (div = 2,isPrime = true;(div*div) <= num;div++){
            if (num % div == 0){
                if ((div*div) != num)
                    printf("%llu is divisible by %llu and %llu.\n",num,div,num/div);
                else
                    printf("%llu is divisible by %llu.\n",num,div);
                isPrime = false;
            }
        }
        if (isPrime && num !=1)
            printf("%llu is prime.\n",num);
        else if(num ==1)
            printf("1 is not a prime.\n");
        printf("Please enter an integer for analysis(q to quit):");
    }
    printf("Bye.\n");

}


void ex_word_count(void){
    char ch;                 // read in character
    char prev;              // previous character read
    long n_chars = 0L;      // number of characters
    int n_lines = 0;        // number of lines
    int n_words = 0;        // number of words
    int p_lines = 0;        // number of partial lines
    bool inword = false;    // == true if c is in a word

    printf("Enter text to be analyzed (^Z to terminate):\n");
    prev = '\n';            // used to identify complete lines
    while ((ch = getchar()) != '|')
    {
        n_chars++;          // count characters
        if (ch == '\n')
            n_lines++;      // count lines
        if (!isspace(ch) && !inword)
        {
            inword = true;  // starting a new word
            n_words++;      // count word
        }
        if (isspace(ch) && inword)
            inword = false; // reached end of word
        prev = ch;           // save character value
    }

    if (prev != '\n')
        p_lines = 1;
    printf("characters = %ld, words = %d, lines = %d, ",
           n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);


}

void ex_paint(void){
    int sq_feet;
    int cans;
    const int COVERAGE = 350;

    printf("Enter number of square feet to be painted:\n");
    while (scanf("%d", &sq_feet) == 1)
    {
        cans = sq_feet / COVERAGE;
        cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
        printf("You need %d %s of paint.\n", cans,cans == 1 ? "can" : "cans");
        printf("Enter next value (q to quit):\n");
    }
}


void ex_skip_part_loop(){
    const float MIN = 0.0f;
    const float MAX = 100.0f;

    float score;
    float total = 0.0f;
    int n = 0;
    float min = MAX;
    float max = MIN;

    printf("Enter the first score (q to quit): ");
    while (scanf("%f", &score) == 1)
    {
        if (score < MIN || score > MAX)
        {
            printf("%0.1f is an invalid value. Try again: ",
                   score);
            continue;   // jumps to while loop test condition
        }
        printf("Accepting %0.1f:\n", score);
        min = (score < min)? score: min;
        max = (score > max)? score: max;
        total += score;
        n++;
        printf("Enter next score (q to quit): ");
    }
    if (n > 0)
    {
        printf("Average of %d scores is %0.1f.\n", n, total / n);
        printf("Low = %0.1f, high = %0.1f\n", min, max);
    }
    else
        printf("No valid scores were entered.\n");
}



void ex_skip_whole_loop(void){
    float length, width;

    printf("Enter the length of the rectangle:\n");
    while (scanf("%f", &length) == 1)
    {
        printf("Length = %0.2f:\n", length);
        printf("Enter its width:\n");
        if (scanf("%f", &width) != 1)
            break;
        printf("Width = %0.2f:\n", width);
        printf("Area = %0.2f:\n", length * width);
        printf("Enter the length of the rectangle:\n");
    }
    printf("Done.\n");
}

void ex_switch(void){
    char ch;

    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter; type # to end my act.\n");
    while ((ch = getchar()) != '#')
    {
        if('\n' == ch)
            continue;
        if (islower(ch))     /* lowercase only          */
            switch (ch)
            {
                case 'a' :
                    printf("argali, a wild sheep of Asia\n");
                    break;
                case 'b' :
                    printf("babirusa, a wild pig of Malay\n");
                    break;
                case 'c' :
                    printf("coati, racoonlike mammal\n");
                    break;
                case 'd' :
                    printf("desman, aquatic, molelike critter\n");
                    break;
                case 'e' :
                    printf("echidna, the spiny anteater\n");
                    break;
                case 'f' :
                    printf("fisher, brownish marten\n");
                    break;
                default :
                    printf("That's a stumper!\n");
            }                /* end of switch           */
        else
            printf("I recognize only lowercase letters.\n");
        while (getchar() != '\n')
            continue;      /* skip rest of input line */
        printf("Please type another letter or a #.\n");
    }                        /* while loop end          */
    printf("Bye!\n");

}


void ex_switch_es(void){
    char ch;
    int a_ct, e_ct, i_ct, o_ct, u_ct;

    a_ct = e_ct = i_ct = o_ct = u_ct = 0;

    printf("Enter some text; enter # to quit.\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case 'a' :
            case 'A' :  a_ct++;
                break;
            case 'e' :
            case 'E' :  e_ct++;
                break;
            case 'i' :
            case 'I' :  i_ct++;
                break;
            case 'o' :
            case 'O' :  o_ct++;
                break;
            case 'u' :
            case 'U' :  u_ct++;
                break;
            default :   break;
        }                    // end of switch
    }                        // while loop end
    printf("number of vowels:   A    E    I    O    U\n");
    printf("                 %4d %4d %4d %4d %4d\n",
           a_ct, e_ct, i_ct, o_ct, u_ct);
}