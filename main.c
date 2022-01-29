#include "header/practice/practice1.h"
#include "header/test/test1.h"

/*int main(int argc,char *argv []) {
    printf("There %s %d argument%s.\n",((argc > 1) ? "are":"is"),argc,((argc > 1) ? "s":""));
    return 0;
}*/

int main() {
    puts("Hello world!");
    long double a = my_pow_f(36,5);
    printf("%Lf",a);
    return 0;
}
