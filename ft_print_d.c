#include "ft_printf.h"

static void ft_cast(va_list ap, t_spec spec, intmax_t *n)
{
    if (spec.size == 0)
        (*n = (signed char)va_arg(ap, int));
    else if (spec.size == 1)
        (*n = (short)va_arg(ap, int));
    else if (spec.size == 2 || spec.size == 5)
        (*n = va_arg(ap, long));
    else if (spec.size == 3)
        (*n = va_arg(ap, long long));
    else if (spec.size == 4)
        (*n = va_arg(ap, intmax_t));
    else
        (*n = va_arg(ap, int));
}

int ft_print_d(va_list ap, t_spec spec)
{
    intmax_t n;
    char *s;

    ft_cast(ap, spec, &n);
    s = ft_itoa(n);
    write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

