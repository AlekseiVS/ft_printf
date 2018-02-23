#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    int n = 4242;
    //int n2 = 250;
    //int n2 = 55;
    //char *b1 = "abcde";
    //char *b2 = "abcde";

    printf("\n--------------------\n");

    i = ft_printf("|@moulitest: %.d %5.0u|", 0, 0); 
    printf("\n");
    j = printf("|@moulitest: %.d %5.0u|", 0, 0);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}