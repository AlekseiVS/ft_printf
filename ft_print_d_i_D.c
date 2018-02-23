#include "ft_printf.h"

static void ft_cast(va_list ap, t_spec spec, intmax_t *n)
{
    if (spec.size == 0 && spec.type != 'D')
        (*n = (signed char)va_arg(ap, int));
    else if (spec.size == 1 && spec.type != 'D')
        (*n = (short)va_arg(ap, int));
    else if (spec.size == 2 || spec.size == 5 || spec.type == 'D')
        (*n = va_arg(ap, long));
    else if (spec.size == 3 && spec.type != 'D')
        (*n = va_arg(ap, long long));
    else if (spec.size == 4 && spec.type != 'D')
        (*n = va_arg(ap, intmax_t));
    else
        (*n = va_arg(ap, int));
}



int ft_print_d_i_D(va_list ap, t_spec spec)
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
        if (ln >= spec.width && ln >= spec.precision && (n < 0 || n >= 0))
            result = ft_p1(s, spec, ln, n);
        if (ln <= spec.width && ln > spec.precision)
            result = ft_p2(s, spec, ln, n);
        else if (ln <= spec.width && ln <= spec.precision && spec.width > spec.precision)
            result = ft_p3(s, spec, ln, n);
        else if (ln < spec.precision && spec.width <= spec.precision)
            result = ft_p4(s, spec, ln, n);
        write(1, result, ft_strlen(result));
            return (ft_strlen(result));
    }
    else
    {
        write(1, s, ft_strlen(s));
        return (ft_strlen(s));
    }
}

