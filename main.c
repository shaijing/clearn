#include "header/practice/practice_chapter_17.h"
//#include <windows.h>
// load dll file, require window.h file
#include "header/arithmetic/arithmetic.h"
#include "header/test/test1.h"
#include "header/exam/exam.h"
#include "utils/md5.h"



int main() {
    system("chcp 65001 > null.log");//solve the clion printf chinese garbled code。


    system("pause > null.log");

    return 0;
}



















/*      //use dynamic library
 *     // define two functional pointer
    void(*hello)(void) = NULL;
    // load dll file, require window.h file
    HMODULE module = LoadLibraryA("lib/libtest.dll");
    if (module == NULL) {
        system("error load");
    }
    hello = (void(*)(void))GetProcAddress(module, "hello");


    hello();
    FreeLibrary(module);*/
/*
int main(int argc, char *argv[])
{
    char mode = 'p';
    int ok = 1;
    int ch;

    if (argc > 2)
    {
        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
        ok = 0; */
/* skip processing input *//*

    }
    else if (argc == 2)
    {
        if (argv[1][0] != '-')
        {
            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
            ok = 0;
        }
        else
            switch(argv[1][1])
            {
                case 'p' :
                case 'u' :
                case 'l' : mode = argv[1][1];
                    break;
                default : printf("%s is an invalid flag; ", argv[1]);
                    printf("using default flag (-p).\n");
            }
    }

    if (ok)
        while ((ch = getchar() ) != EOF)
        {
            switch(mode)
            {
                case 'p' : putchar(ch);
                    break;
                case 'u' : putchar(toupper(ch));
                    break;
                case 'l' : putchar(tolower(ch));
            }
        }

    return 0;
}*/
