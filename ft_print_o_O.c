#include "ft_printf.h"

static void ft_cast(va_list ap, t_spec spec, uintmax_t *n)
{
    if (spec.size == 0 && spec.type != 'O')
        (*n = (unsigned char)va_arg(ap, unsigned int));
    else if (spec.size == 1 && spec.type != 'O')
        (*n = (unsigned short)va_arg(ap, unsigned int));
    else if (spec.size == 2 || spec.size == 5 || spec.type == 'O')
        (*n = va_arg(ap, unsigned long));
    else if (spec.size == 3 && spec.type != 'O')
        (*n = va_arg(ap, unsigned long long));
    else if (spec.size == 4 && spec.type != 'O')
        (*n = va_arg(ap, uintmax_t));
    else
        (*n = va_arg(ap, unsigned int));
}

int ft_print_o_O(va_list ap, t_spec spec)
{
    uintmax_t n;
    char *s;
    char *result;
    int ln;

    ft_cast(ap, spec, &n);
    s = ft_itoa_base(n, 8);
    ln = ft_strlen(s);

    if (spec.width >= 0 || spec.precision >= 0 || spec.minus == 1 || spec.zero == 1 || spec.hesh == 1)
    {
        result = ft_string_formation_o(s, spec, ln, n);
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

