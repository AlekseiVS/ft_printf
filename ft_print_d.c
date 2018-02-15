#include "ft_printf.h"

int ft_print_d(va_list ap, t_spec spec)
{
    long long int n = va_arg(ap, long long int);
    n++;
    spec.plus++;
    return (0);
}