//
// Created by yulin on 2022/1/16.
//
/*C Prime Plus , chapter 10*/
#include "../../headers/learn/learn_chapter_10.h"


void ex_auto_num_of_array(void){
    const int days[] = {31,28,31,30,31,30,31,31,30,31};
    int index;

    for (index = 0; index < sizeof days / sizeof days[0]; index++)
        printf("Month %2d has %d days.\n", index +1,
               days[index]);
}


__attribute__((unused)) void ex_design_array(void){
#define MONTHS 12
    int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};
    int i;

    for (i = 0; i < MONTHS; i++)
        printf("%2d  %d\n", i + 1, days[i]);
}


void ex_subscript_bound(void){
    const int SIZE= 4;
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;
    int i;

    printf("value1 = %d, value2 = %d\n", value1, value2);
    for (i = -1; i <= SIZE; i++)
        arr[i] = 2 * i + 1;

    for (i = -1; i < 7; i++)
        printf("%2d  %d\n", i , arr[i]);
    printf("value1 = %d, value2 = %d\n", value1, value2);

    printf("address of arr[-1]: %p\n", &arr[-1]);
    printf("address of arr[4]:  %p\n", &arr[4]);
    printf("address of value1:  %p\n", &value1);
    printf("address of value2:  %p\n", &value2);
}


void ex_two_dimensional_array(void){
#define YEARS 5
    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
            {
                    {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
                    {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
                    {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
                    {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
                    {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
            };
    int year, month;
    float subtot, total;

    printf(" YEAR    RAINFALL  (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++)
    {             // for each year, sum rainfall for each month
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; // total for all years
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
           total/YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");

    for (month = 0; month < MONTHS; month++)
    {             // for each month, sum rainfall over years
        for (year = 0, subtot =0; year < YEARS; year++)
            subtot += rain[year][month];
        printf("%4.1f ", subtot/YEARS);
    }
    printf("\n");
}


void ex_three_dimensional_array(void){
    int ex[2][2][2] = {{{1,2},{2,2},},{{2,2},{2,2},}};
    for (int i=0;i<2;i++)
        for (int j = 0;j<2;j++)
            for (int k = 0; k < 2; k++) {
                printf("%d\n",ex[i][j][k]);
            };

}


void ex_array_pointer(void){
#define SIZE 4
    short dates [SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double * ptf;

    pti = dates;    // assign address of array to pointer, and it's similar to pti = &dates[0]
    ptf = bills;    // assign address of array to pointer, and it's similar to pti = &bills[0]
    /* dates + 2 == &dates[2] similar address
     * *(dates + 2) == dates[2] similar address
     * */
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index ++)
        printf("pointers + %d: %10p %10p\n",index, pti + index, ptf + index);
}


void ex_array_use_pointer(){
    int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;

    for (index = 0; index < MONTHS; index++)
        printf("Month %2d has %d days.\n", index +1,*(days + index));   // same as days[index]
}


void ex_array_sum(void){
#undef SIZE
#define SIZE 10
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n",sizeof marbles);

}
int sum(const int array[], int n){
    int i;
    int total = 0;

    for( i = 0; i < n; i++)
        total += array[i];
    printf("The size of array is %zd bytes.\n", sizeof array);

    return total;
}


void ex_array_sum_2(void){
    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer = sump(marbles, marbles + SIZE);
    printf("The total number of marbles is %ld.\n", answer);

}
/* use pointer arithmetic   */
int sump(int * start, const int * end){
    int total = 0;

    while (start < end)
    {
        total += *start; // add value to total
        start++;         // advance pointer to next element
    }

    return total;
}


void ex_pointer_order(void){
    int data[2] = {100, 200};
    int moredata[2] = {300, 400};
    int * p1, * p2, * p3;

    p1 = p2 = data;
    p3 = moredata;
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n",*p1,*p2,*p3);
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n",*p1++, *++p2, (*p3)++);
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n",*p1,*p2,*p3);
}

void ex_pointer_operation(void){
    int urn[5] = {100,200,300,400,500};
    int * ptr1, * ptr2, *ptr3;

    ptr1 = urn;         // assign an address to a pointer
    ptr2 = &urn[2];     // ditto
    // dereference a pointer and take
    // the address of a pointer
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",ptr1, *ptr1, &ptr1);

    // pointer addition
    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr4 + 3) = %d\n",ptr1 + 4, *(ptr1 + 3));
    ptr1++;            // increment a pointer
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",ptr1, *ptr1, &ptr1);
    ptr2--;            // decrement a pointer
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",ptr2, *ptr2, &ptr2);
    --ptr1;            // restore to original value
    ++ptr2;            // restore to original value
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
    // subtract one pointer from another
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n",ptr2, ptr1, ptr2 - ptr1);
    // subtract an integer from a pointer
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n",ptr3,  ptr3 - 2);
}


void ex_const_parameter(void){
#undef SIZE
#define SIZE 5
    double dip[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};

    printf("The original dip array:\n");
    show_array(dip, SIZE);
    mult_array(dip, SIZE, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, SIZE);
}
/* displays array contents */
void show_array(const double ar[], int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    putchar('\n');

}
/* multiplies each array member by the same multiplier */
void mult_array(double ar[], int n, double mult){
    int i;

    for (i = 0; i < n; i++)
        ar[i] *= mult;
}


void ex_two_dimension_array_pointer(void){
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };

    printf("   zippo = %p,    zippo + 1 = %p\n",zippo,         zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n",zippo[0],      zippo[0] + 1);
    printf("  *zippo = %p,   *zippo + 1 = %p\n",*zippo,        *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));
}


void ex_two_dimension_array_pointer_1(void){
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
    int (*pz)[2];
    pz = zippo;

    printf("   pz = %p,    pz + 1 = %p\n",
           pz,         pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",
           pz[0],      pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n",
           *pz,        *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz+2) + 1));
}


void ex_two_dimension_array_pointer_operation(void){
    int junk[ROWS][COLS] = {
            {2,4,6,8},
            {3,5,7,9},
            {12,10,8,6}
    };

    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);
    printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

}
void sum_rows(int ar[][COLS], int rows)
{
    int r;
    int c;
    int tot;

    for (r = 0; r < rows; r++)
    {
        tot = 0;
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];
        printf("row %d: sum = %d\n", r, tot);
    }
}
void sum_cols(int ar[][COLS], int rows)
{
    int r;
    int c;
    int tot;

    for (c = 0; c < COLS; c++)
    {
        tot = 0;
        for (r = 0; r < rows; r++)
            tot += ar[r][c];
        printf("col %d: sum = %d\n", c, tot);
    }
}
int sum2d(int ar[][COLS], int rows)
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];

    return tot;
}


void ex_vary_two_dimension(void){
    int i, j;
    int rs = 3;
    int cs = 10;
    int junk[ROWS][COLS] = {
            {2,4,6,8},
            {3,5,7,9},
            {12,10,8,6}
    };

    int morejunk[ROWS-1][COLS+2] = {
            {20,30,40,50,60,70},
            {5,6,7,8,9,10}
    };

    int varr[rs][cs];  // VLA

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
            varr[i][j] = i * j + j;

    printf("3x5 array\n");
    printf("Sum of all elements = %d\n",sum2d_1(ROWS, COLS, junk));

    printf("2x6 array\n");
    printf("Sum of all elements = %d\n",sum2d_1(ROWS-1, COLS+2, morejunk));

    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n",sum2d_1(rs, cs, varr));

}
// function with a VLA parameter
int sum2d_1(int rows, int cols, int ar[rows][cols]){
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            tot += ar[r][c];

    return tot;
}


void ex_constant_array(void){
    int total1, total2, total3;
    int * pt1;
    int (*pt2)[COLS];

    pt1 = (int [2]) {10, 20};
    pt2 = (int [2][COLS]) { {1,2,3,-9}, {4,5,6,-8} };

    total1 = sum_1(pt1, 2);
    total2 = sum2d_2(pt2, 2);
    total3 = sum_1((int []){4,4,4,5,5,5}, 6);
    printf("total1 = %d\n", total1);
    printf("total2 = %d\n", total2);
    printf("total3 = %d\n", total3);
}
int sum2d_2(const int ar[][COLS], int rows){
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < COLS; c++)
            tot += ar[r][c];

    return tot;
}
int sum_1(const int ar[], int n){
    int i;
    int total = 0;

    for( i = 0; i < n; i++)
        total += ar[i];

    return total;
}