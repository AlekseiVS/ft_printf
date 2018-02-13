#include "ft_printf.h"

int main()
{
    char a1 = 'a';
    char a2 = 'a';

    char *b1 = "abcde";
    char *b2 = "abcde";

    ft_printf("%-7s", b1);
    printf("\n");
    printf("%-7s", b2);
    printf("\n");
    return (0);
}