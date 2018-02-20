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
    char *result;
    int ln;

    ft_cast(ap, spec, &n);
    s = ft_itoa(n);
    ln = ft_strlen(s);

    if (spec.width >= 0 || spec.precision >= 0 || spec.plus == 1 || spec.minus == 1 || spec.zero == 1 || spec.space == 1)
    {
        if ((spec.space == 1 && spec.plus == 0) && (n > 0))
            result = ft_right(s, ln + 1, ln, ' ');
        if ((spec.space == 0 && spec.plus == 1) && (n > 0))
            result = ft_right(s, ln + 1, ln, '+');
        if ((spec.space == 1 && spec.plus == 1) && (n > 0))
            result = ft_right(s, ln + 1, ln, '+');
        if ((spec.space == 1 && spec.plus == 1) && (n < 0))
            result = ft_right(s, ln, ln, ' ');
        write(1, result, ft_strlen(result));
            return (ft_strlen(result));
    }
    else
    {
        write(1, s, ft_strlen(s));
        return (ft_strlen(s));
    }
}

