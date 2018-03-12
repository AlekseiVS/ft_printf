#include "ft_printf.h"
//#ifdef NUM
int main()
{
    setlocale(LC_ALL, "");

    int i = 0;
    int j = 0;
    // char a1 = 'a';
    // char a2 = 'a';

    int x;
    x = 3;

    //int nmb = 42;
    //char *s = 0;
    //wchar_t *b = L"我是一只猫。";
    //char *c;

    // int c = 945;
    printf("\n--------------------\n");
    i = ft_printf("%#o", 0);
    printf("\n");
    j = printf("%#o", 0);

    // while (x--)
    // {
    //     ft_printf("|{%10d}|\n", 42);
    //     ft_printf("|{%4d}|\n", 10000);
    //     ft_printf("|{%30d}|\n", 10000);
    // }


    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);

    return (0);
}
  



	

