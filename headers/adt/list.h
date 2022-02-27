//
// Created by yulin on 2022/2/14.
//

#ifndef CLEARN_LIST_H
#define CLEARN_LIST_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h> /*C99 traits*/

/*Specific Application Statement*/
#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
};

/* function prototypes */
/*General Type Definition*/
typedef struct film Item;

struct node {
    Item item;
    struct node *next;
};
typedef struct node Node;
typedef Node *List;


/* Operation:        Initialize a list                          */
/* Preconditions:    plist points to a linked list              */
/* Post-condition:   The list is initialized to empty           */
void InitializeList(List *plist);

/* Operation:         Check if list is empty                    */
/* Preconditions:     plist points to an initialized list       */
/* Post-condition:    function returns True if list is empty    */
/*                    and returns False otherwise               */
bool ListIsEmpty(const List *plist);

/* Operation:         determine if list is full                 */
/* Preconditions:     plist points to an initialized list       */
/* Post-condition:    function returns True if list is full     */
/*                    and returns False otherwise               */
bool ListIsFull(const List *plist);

/* Operation:         determine number of items in list         */
/* Preconditions:     plist points to an initialized list       */
/* Post-condition:    function returns number of items in list  */
unsigned int ListItemCount(const List *plist);

/* Operation:         add item to end of list                   */
/* Preconditions:     item is an item to be added to list       */
/*                    plist points to an initialized list       */
/* Post-conditions:   if possible, function adds item to end    */
/*                    of list and returns True; otherwise the   */
/*                    function returns False                    */
bool AddItem(Item item, List *plist);

/* Operation:         apply a function to each item in list     */
/* Preconditions:     plist points to an initialized list       */
/*                    pfun points to a function that takes an   */
/*                    Item argument and has no return value     */
/* Post-condition:    the function pointed to by pfun is        */
/*                    executed once for each item in the list   */
void Traverse(const List *plist, void(*pfun)(Item item));

/* operation:        free allocated memory, if any              */
/* Preconditions:    plist points to an initialized list        */
/* Post-conditions:  any memory allocated for the list is freed */
/*                   and the list is set to empty               */
void EmptyTheList(List * plist);

#endif //CLEARN_LIST_H
