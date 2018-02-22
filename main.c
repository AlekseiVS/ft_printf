#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    int n1 = 250;
    int n2 = 250;
    //int n2 = 55;
    //char *b1 = "abcde";
    //char *b2 = "abcde";

    printf("\n--------------------\n");

    i = ft_printf("|%u|", n1); 
    printf("\n");
    j = printf("|%u|", n2);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}