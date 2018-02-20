#include "ft_printf.h"

int main()
{
    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    int n1 = -2147483648;
    int n2 = -2147483648;
    //char *b1 = "abcde";
    //char *b2 = "abcde";

    i = ft_printf("res: %jd", n1); 
    printf("\n");
    j = printf("res: %jd", n2);
    printf("\n");
    printf("main: %d\norig: %d\n", i, j);
    return (0);
}