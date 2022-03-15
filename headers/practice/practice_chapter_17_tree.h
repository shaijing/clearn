//
// Created by Chaos on 2022/3/15.
//

#ifndef CLEARN_PRACTICE_CHAPTER_17_TREE_H
#define CLEARN_PRACTICE_CHAPTER_17_TREE_H
#include "../adt/tree.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char t_menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);

extern char * s_gets(char * st, int n);

void petclub();

#endif //CLEARN_PRACTICE_CHAPTER_17_TREE_H
