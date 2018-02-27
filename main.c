#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    int n = 42;
    char *s = 0;
    printf("\n--------------------\n");

    i = ft_printf("|%5s|", s); 
    printf("\n");
    j = printf("|%5s|", s);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}