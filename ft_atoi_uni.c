#include "ft_printf.h"

int ft_atoi_uni(char *s)
{
    int res;
    int j;
    int i;

    j = 8;
    i = 1;
    res = 0;
    while (j--)
    {
        res += i * (int)(s[j] - '0');
        i = i * 2;
    }
    return (res);
}