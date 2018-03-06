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
    wchar_t *b = L"Кит";
    //int c = 945;
    printf("\n--------------------\n");

    i = ft_printf("%5S", b); 
    printf("\n");
    j = printf("%5S", b);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}