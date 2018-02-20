#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    int n1 = 55;
    int n2 = 55;
    //char *b1 = "abcde";
    //char *b2 = "abcde";

    printf("\n------------------------------\n");

    i = ft_printf("res main: %lld", -9223372036854775555); 
    printf("\n");
    j = printf("res orig: %lld", -9223372036854775555);

    printf("\n------------------------------\n(return) main: %d\n(return) orig: %d\n------------------------------\n\n", i, j);

    return (0);
}