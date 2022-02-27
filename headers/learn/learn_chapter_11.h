//
// Created by Chaos on 2022/1/19.
//
/*C Prime Plus , chapter 11*/
#ifndef CLEARN_LEARN_CHAPTER_11_H
#define CLEARN_LEARN_CHAPTER_11_H

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>            /* for strlen() */
#include "other.h"


void ex_strings(void);


void ex_string_is_pointer(void);


void ex_address_of_string(void);


void ex_two_types_array(void);


void point_string(void);


void ex_gets_puts(void);


void ex_fgets_fputs_1(void);


void ex_fgets_fputs_2(void);


void ex_scan_str(void);


/*11.3 string output*/
//11.3.1 puts() function
void ex_put_out(void);


void ex_incorrect_put(void);


//11.3.2 fputs() function
void ex_fput();


//11.3.3 printf() function


/*11.4 customize input/output function*/
void ex_put_put();
void ex_put1(const char * string);
int ex_put2(const char *);


/*11.5 string function*/
//11.5.1 strlen() function
void ex_string_fit();/*try the string-shrinking function */
void fit(char *, unsigned int);


//11..5.2 strcat() function
void ex_str_cat(void);/*joins two strings*/


//11.5.3 strncat() function
void ex_join_check(void);/*joins two strings, check size first*/


//11.5.4 strcmp() function
void ex_str_compare(void);


//return value of strcmp() function
void ex_return_strcmp(void);/*the return value of the strcmp() function is the difference of ASNCLL code of first argument and second argument,
 * however different compiler have different methods  */


//whether the application should quit
void ex_quit(void);


//strncmp() function
void ex_custom_strcmp(void);


//11.5.5 strcpy() and strncpy() function
//copy string
void ex_copy1(void);


//two traits of strcpy() function
void ex_copy2(void);


//strncpy() function
void ex_copy3(void);


//11.5.6 sprintf() function
void ex_sprintf(void);

/*11.6 string examples*/
//sort string
void ex_sort_string(void);
void stsrt(char *strings[], int num);/* string-sort function */


/*11.7 ctype.h*/
//modify string
void ex_mod_str(void);
void ToUpper(char *);
int PunctCount(const char *);
#endif //CLEARN_LEARN_CHAPTER_11_H
