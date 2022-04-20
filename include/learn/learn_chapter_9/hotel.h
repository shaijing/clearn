//
// Created by yulin on 2022/1/16.
//
#ifndef CLEARN_HOTEL_H
#define CLEARN_HOTEL_H

#define QUIT       5
#define HOTEL1   180.00
#define HOTEL2   225.00
#define HOTEL3   255.00
#define HOTEL4   355.00
#define DISCOUNT   0.95
#define STARS "**********************************"



// shows list of choices
int menu(void);

// returns number of nights desired
int getnights(void);

// calculates price from rate, nights
// and displays result
void showprice(double rate, int nights);

#endif //CLEARN_HOTEL_H
