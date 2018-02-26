#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    //int n = -42;

    printf("\n--------------------\n");

    i = ft_printf("|%.p, %.0p|", 0, 0); 
    printf("\n");
    j = printf("|%.p, %.0p|", 0, 0);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}