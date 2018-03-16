#include "ft_printf.h"

int main()
{
    setlocale(LC_ALL, "");

    int i = 0;
    int j = 0;
    // char a1 = 'a';
    // char a2 = 'a';

    int x;
    x = 3;

    int n = 42;
    //char *s = 0;
    //wchar_t *b = L"我是一只猫。";
    //char *c;

    // int c = 945;
    printf("\n--------------------\n");
    i = ft_printf("%.p", &n);
    printf("\n");
    j = printf("%.p", &n);

    printf("\n--------------------\n(return) main: %d\n(return) orig: %d\n--------------------\n\n", i, j);
    system("leaks a.out");
    return (0);
}
  
// int main(void)
// {
//     setlocale(LC_ALL, "");

//   ft_printf("%S\n", L"ݗݜशব");
//   //ft_printf("%C\n", 15000);

//   return (0);
// }




	

