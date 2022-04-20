//
// Created by yulin on 2022/2/14.
//

#include "practice/practice_chapter_17.h"


void film_2(void){
    struct film_1 * head = NULL;
    struct film_1 * prev,* current;
    char input[TSIZE];
    puts("Enter first movie title:");
    while(s_gets(input,TSIZE) != NULL && input[0]!='\0'){
        current = (struct film_1 *) malloc(sizeof(struct film_1));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title,input);
        //*(current->title) = *(input);//it's not work, for it's only receive the first value.
        puts("Enter your rating<0-10>:");
        scanf("%d",&current->rating);
        while (getchar()!='\n')
            continue;
        puts("Enter next moive title(empty line to stop):");
        prev = current;
    }
    if(head)
        printf("No data entered!\n");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current){
        printf("Movie:%s Rating: %d\n",current->title,current->rating);
        current = current->next;
    }
    current = head;
    while (current){
        head = current->next;
        free(current);
        current = head;
    }
}

void film_3(void){
    List movies;
    Item temp;
    InitializeList(&movies);
    if(ListIsFull(&movies)){
        fprintf(stderr,"No memory is available! Bye\n");
        exit(1);
    }
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0'){
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while(getchar() != '\n')
            continue;
        if (AddItem(temp, &movies)==false){
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    /* display          */
    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else{
        printf ("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    /* clean up         */
    EmptyTheList(&movies);
    printf("Bye!\n");

}
void showmovies(Item item){
    printf("Movie: %s  Rating: %d\n", item.title,item.rating);
}

