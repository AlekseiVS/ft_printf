#include "ft_printf.h"

int main()
{
    setlocale(LC_ALL, "");

    int i = 0;
    int j = 0;
    char a1 = 'a';
    char a2 = 'a';

    //int n = -42;
    //char *s = 0;
    //wchar_t *b = L"0";
    //int c = 945;
    printf("\n--------------------\n");

    i = ft_printf("%4.15d", -42); 
    printf("\n");
    j = printf("%4.15d", -42);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}