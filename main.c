#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    //char *b1 = "abcde";
    //char *b2 = "abcde";

    i = ft_printf("%-.2s is a string", "ttt"); 
    printf("\n");
    j = printf("%-.2s is a string", "ttt");
    printf("\n");
    printf("main: %d\norig: %d\n", i, j);
    return (0);
}