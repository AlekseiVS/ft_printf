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

    printf("\n--------------------\n");

    i = ft_printf("res main: %++ d", -42); 
    printf("\n");
    j = printf("res orig: %++ d", -42);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}