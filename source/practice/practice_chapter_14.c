//
// Created by yulin on 2022/2/9.
//
#include "../../headers/practice/practice_chapter_14.h"

const char months[12][10]=
        {"January","February","March","April",
         "May","June","July","August",
         "September","October","November","December"
        };
const int days[12]={
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
};
int match_month(char * str){;
    int res = 0;


    if(atoi(str))
         res = atoi(str)-1;
    else{
        for (int i = 0; i < 12; ++i) {
            if(string_in(months[i],str))
                res = i;
        }
    }
    return res;
}
void cal_days(void){

    int i_day;
    char i_month[10];
    int res;
    printf("Please enter day,month:\n");
    while(scanf("%d,%s",&i_day,i_month)){
        int t_days = i_day;
        res = match_month(i_month);
        for (int i = 0; i < res; ++i) {
            t_days+=days[i];
        }
        while (getchar()!='\n')
            continue;
        printf("It's %d.\n",t_days);
        printf("Please enter next day,month:\n");
    }
}


bool is_exist(void){
    bool res = true;
    FILE * fp;
    fp = fopen(path,"r");

    if (fp == NULL) {
        res = false;
    }
    fclose(fp);
    return res;
}
void q_book(FILE * fp,int total_n){
    library book[total_n];
    unsigned long long res;
    res = fread(book, sizeof(library),total_n,fp);
    if(res !=total_n){
        puts("Read failure!\n");
        fclose(fp);
    } else{
        printf("Here %s your book%s.\n",(total_n>1) ? "are":"is",(total_n>1) ? "s":"");
        show_n_char('#',20);
        for (int i = 0; i < total_n; ++i) {
            printf("Book name:%s\nBook author:%s\nBook value:$%.2f\n",book[i].title,book[i].author,book[i].value);
            show_n_char('#',20);
        }
        fclose(fp);
        puts("All done!");
    }

}
void q_book_ui(void){
    FILE * fp;
    bool isexist = is_exist();
    if (isexist){
        int total_n;
        fp = fopen(path,"rb");
        rewind(fp);
        unsigned long long res = fread(&total_n, sizeof(int),1,fp);
        if(res!= 1){
            puts("Error!\n");
        }
        fseek(fp,5l,SEEK_SET);
        q_book(fp,total_n);
    }else{
        printf("Sorry!You don't have any books.\n");
    }
}
void get_book(){
    int in_n;
    printf("How many books you will enter:");
    while (scanf("%d",&in_n)!=1){
        puts("Please enter a num:");
        scanf("%d",&in_n);
    }
    library * books = malloc(in_n* sizeof(library));
    puts("Please enter book information:");
    for (int i = 0; i < in_n; ++i) {
        scanf("%s %s %f",(books+i)->title,(books+i)->author,&(books+i)->value);
    }
    add_book(books,in_n);
}
void add_book(library * books,int in_n){
    FILE * fp;
    fp = fopen(path,"r+b");
    int total_n;
    fseek(fp,5L,SEEK_SET);
    unsigned long long res;
    res = fwrite(books, sizeof(library),in_n,fp);
    if(res ==in_n){
        rewind(fp);
        fread(&total_n, sizeof(int),1,fp);
        total_n+=in_n;
        rewind(fp);
        fwrite(&total_n, sizeof(int),1,fp);
        puts("Write successful!");
    } else{
        puts("Write failed!");
    }
    //fflush(fp);//强制刷新缓冲区，以便能查询新添加书姬。
    fclose(fp);
}
void add_book_ui(void){
    int total_n = 0;
    bool isexist = is_exist();
    if(isexist){
        get_book();
    } else{
        FILE * fp;
        fp = fopen(path,"wb");
        fwrite(&total_n, sizeof(int),1,fp);
        fclose(fp);
        get_book();
    }
}
int ui_menu(void){
    int res = 0;
    show_n_char('*',80);
    printf("                    This is a library control system!\n");
    printf("                        Follows are the function.\n");
    show_n_char('*',80);
    printf("1) Query books           2) Add books\n");
    printf("3) ...        4) ..\n5) quit\n");
    int status;
    status = scanf("%d",&res);
    while (status != 1|| res <1||res>5){
        printf("Please enter the correct num:");
        status = scanf("%d",&res);
        while (getchar()!='\n')
            continue;
    }
    return res;
}
void user_ui(void){
    char username[20];
    char password[30];
    show_n_char('*',80);
    printf("Please enter your username and password:\n");


}
void initial(void){

}
void library_ui(void){
    //cmd终端入口程序
    //user_ui();
    int res;
    while ((res = ui_menu()) != 5){
        switch (res) {
            case 4:
            case 3:
                ;
                break;
            case 2:
                add_book_ui();
                break;
            case 1:
                q_book_ui();
                break;
            default:
                exit(1);
        }
    }
    puts("Bye!\n");
}