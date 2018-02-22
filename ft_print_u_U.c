#include "ft_printf.h"

static void ft_cast(va_list ap, t_spec spec, uintmax_t *n)
{
    if (spec.size == 0 && spec.type != 'U')
        (*n = (unsigned char)va_arg(ap, unsigned int));
    else if (spec.size == 1 && spec.type != 'U')
        (*n = (unsigned short)va_arg(ap, unsigned int));
    else if (spec.size == 2 || spec.size == 5 || spec.type == 'U')
        (*n = va_arg(ap, unsigned long));
    else if (spec.size == 3 && spec.type != 'U')
        (*n = va_arg(ap, unsigned long long));
    else if (spec.size == 4 && spec.type != 'U')
        (*n = va_arg(ap, uintmax_t));
    else
        (*n = va_arg(ap, unsigned int));
}

int ft_print_u_U(va_list ap, t_spec spec)
{
    uintmax_t n;
    char *s;
    char *result;
    int ln;

    ft_cast(ap, spec, &n);
    s = ft_itoa_base(n, 10);
    ln = ft_strlen(s);

    if (spec.width >= 0 || spec.precision >= 0 || spec.minus == 1 || spec.zero == 1)
    {
        if ((spec.space == 1 && spec.plus == 0 && spec.width < 0))
            result = ft_right(s, ln + 1, ln, ' ');
        else if ((spec.space == 1 && spec.plus == 0 && spec.width < 0))
            result = ft_right(s, ln, ln, ' ');
        else if ((spec.space == 1 && spec.plus == 1 && spec.width < 0))
            result = ft_right(s, ln, ln, ' ');
        else if ((spec.space == 0 || spec.space == 1) && (spec.plus == 0 || spec.plus == 1) && (spec.minus == 0 || spec.minus == 1) && spec.width < ln && spec.precision < 0)
            result = ft_strsub(s, 0, ln);
        else if ((spec.zero == 1 && spec.plus == 0 && spec.width < 0))
            result = ft_right(s, ln, ln, ' ');
        else if (spec.zero == 0 && spec.precision < 0 && spec.width > 0 && spec.minus == 0)
            result = ft_right(s, spec.width, ln, ' ');
        else if ((spec.zero == 1 && spec.plus == 0 && spec.width > 0 && spec.precision < 0 && spec.minus == 0))
            result = ft_right(s, spec.width, ln, '0');
        else if ((spec.zero == 0 || spec.zero == 1) && spec.plus == 0 && spec.width > 0 && spec.precision < 0 && spec.minus == 1)
            result = ft_left(s, spec.width, ln, ' ');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision >= 0 && spec.precision >= ln && spec.minus == 0)
            result = ft_right(s, spec.precision, ln, '0');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision >= 0 && spec.precision < ln && spec.minus == 0)
            result = ft_right(s, ln, ln, '0');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision >= 0 && spec.minus == 0 && n == 0)
            result = "";
        else if (spec.zero == 0 && spec.plus == 0 && spec.width >= spec.precision && spec.precision >= 0 && spec.minus == 0 && n == 0)
            result = ft_right(s, spec.width, 0, ' ');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision > 0 && spec.precision <= ln && spec.minus == 0)
            result = ft_right(s, ln, ln, '0');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width < 0 && spec.precision > 0 && spec.precision < ln && spec.minus == 0)
            result = ft_right(s, ln, ln, ' ');
        else if ((spec.zero == 0 || spec.zero == 1) && spec.plus == 0 && spec.width > 0 && spec.precision > 0 && (spec.precision < spec.width) && spec.minus == 0 && spec.precision >= ln)
        {
            result = ft_right(s, spec.precision, ln, '0');
            result = ft_right(result, spec.width, ft_strlen(result), ' ');
        }
        else if ((spec.zero == 0 || spec.zero == 1) && spec.plus == 0 && spec.width > 0 && spec.precision >= 0 && (spec.precision < spec.width) && spec.minus == 0 && spec.precision < ln)
            result = ft_right(s, spec.width, ln, ' ');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width > 0 && spec.precision > 0 && spec.minus == 1)
        {
            result = ft_right(s, spec.precision, ln, '0');
            result = ft_left(result, spec.width, ft_strlen(result), ' ');
        }
        

        write(1, result, ft_strlen(result));
            return (ft_strlen(result));
    }
    else
    {
        write(1, s, ft_strlen(s));
        return (ft_strlen(s));
    }
}

