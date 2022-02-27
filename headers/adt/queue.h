//
// Created by yulin on 2022/2/17.
//
/* interface for a queue */
#ifndef CLEARN_QUEUE_H
#define CLEARN_QUEUE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// INSERT ITEM TYPE HERE
// FOR EXAMPLE,
//typedef int Item;  // for use_q.c
// OR typedef struct item {int gumption; int charisma;} Item;
// OR  (for mall.c)
/**/
typedef struct item
{
    long arrive;      // the time when a customer joins the queue
    int processtime;  // the number of consultation minutes desired
} Item;
/**/

#define MAXQUEUE 10

typedef struct node{
    Item item;
    struct node * next;
} Node;

typedef struct queue{
    Node * front;  /* pointer to front of queue  */
    Node * rear;   /* pointer to rear of queue   */
    int items;     /* number of items in queue   */
} Queue;

/* operation:        initialize the queue                       */
/* precondition:     pq points to a queue                       */
/* post condition:   queue is initialized to being empty        */
void InitializeQueue(Queue * pq);

/* operation:        check if queue is full                     */
/* precondition:     pq points to previously initialized queue  */
/* post condition:   returns True if queue is full, else False  */
bool QueueIsFull(const Queue * pq);

/* operation:        check if queue is empty                    */
/* precondition:     pq points to previously initialized queue  */
/* post condition:   returns True if queue is empty, else False */
bool QueueIsEmpty(const Queue *pq);

/* operation:        determine number of items in queue         */
/* precondition:     pq points to previously initialized queue  */
/* post condition:    returns number of items in queue          */
int QueueItemCount(const Queue * pq);

/* operation:        add item to rear of queue                  */
/* precondition:     pq points to previously initialized queue  */
/*                   item is to be placed at rear of queue      */
/* post condition:   if queue is not empty, item is placed at   */
/*                   rear of queue and function returns         */
/*                   True; otherwise, queue is unchanged and    */
/*                   function returns False                     */
bool EnQueue(Item item, Queue * pq);

/* operation:        remove item from front of queue            */
/* precondition:     pq points to previously initialized queue  */
/* post condition:    if queue is not empty, item at head of    */
/*                   queue is copied to *pitem and deleted from */
/*                   queue, and function returns True; if the   */
/*                   operation empties the queue, the queue is  */
/*                   reset to empty. If the queue is empty to   */
/*                   begin with, queue is unchanged and the     */
/*                   function returns False                     */
bool DeQueue(Item *pitem, Queue * pq);

/* operation:        empty the queue                            */
/* precondition:     pq points to previously initialized queue  */
/* post conditions:   the queue is empty                         */
void EmptyTheQueue(Queue * pq);
#endif //CLEARN_QUEUE_H
