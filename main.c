#include "header/practice/practice5.h"

#include "header/test/test1.h"
#include "header/arithmetic/arithmetic.h"
#include "header/exam/exam.h"

/*int main(int argc,char *argv []) {
    printf("There %s %d argument%s.\n",((argc > 1) ? "are":"is"),argc,((argc > 1) ? "s":""));
    return 0;
}*/

int main() {
    system("chcp 65001 > null.log");//解决clion printf中文乱码。
    exam1_1();
    system("pause > null.log");
    return 0;
}
