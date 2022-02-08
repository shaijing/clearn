#include "header/practice/practice7.h"

#include "header/test/test1.h"
#include "header/arithmetic/arithmetic.h"
#include "header/exam/exam.h"
#include "header/learn/other.h"
#include <windows.h>
/*int main(int argc,char *argv []) {
    printf("There %s %d argument%s.\n",((argc > 1) ? "are":"is"),argc,((argc > 1) ? "s":""));
    return 0;
}*/
// load dll file, require window.h file

int main() {
    system("chcp 65001 > null.log");//解决clion printf中文乱码。

    system("pause > null.log");
    return 0;
}
/*      //使用动态库
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