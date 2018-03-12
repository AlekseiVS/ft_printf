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
    if (spec.width > 0 || spec.precision >= 0 || spec.plus == 1 || spec.minus == 1 || spec.zero == 1 || spec.space == 1)
    {
        result = ft_string_formation_d(s, spec, ln, n);
        ln = ft_strlen(result);
        write(1, result, ln);
        if (result != s)
            ft_strdel(&result);
        ft_strdel(&s);
        return (ln);
    }
    write(1, s, ln);
    ft_strdel(&s);
    return (ln);
}
