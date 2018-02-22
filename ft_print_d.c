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
        if ((spec.space == 1 && spec.plus == 0 && spec.width < 0) && (n > 0))
            result = ft_right(s, ln + 1, ln, ' ');
        else if ((spec.space == 1 && spec.plus == 0 && spec.width < 0) && (n < 0))
            result = ft_right(s, ln, ln, ' ');
        else if ((spec.space == 0 && spec.plus == 1 && spec.width < 0) && (n >= 0))
            result = ft_right(s, ln + 1, ln, '+');
        else if ((spec.space == 0 && spec.plus == 1 && spec.width < 0) && (n < 0))
            result = ft_right(s, ln, ln, '+');
        else if ((spec.space == 1 && spec.plus == 1 && spec.width < 0) && (n > 0))
            result = ft_right(s, ln + 1, ln, '+');
        else if ((spec.space == 1 && spec.plus == 1 && spec.width < 0) && (n < 0))
            result = ft_right(s, ln, ln, ' ');
        else if ((spec.space == 0 || spec.space == 1) && (spec.plus == 0 || spec.plus == 1) && (spec.minus == 0 || spec.minus == 1) && spec.width < ln && spec.precision < 0)
            result = ft_strsub(s, 0, ln);
        else if ((spec.zero == 1 && spec.plus == 0 && spec.width < 0) && (n < 0))
            result = ft_right(s, ln, ln, ' ');
        else if (spec.zero == 0 && spec.precision < 0 && spec.width > 0 && spec.minus == 0)
            result = ft_right(s, spec.width, ln, ' ');
        else if ((spec.zero == 1 && spec.plus == 0 && spec.width > 0 && spec.precision < 0 && spec.minus == 0) && (n > 0))
            result = ft_right(s, spec.width, ln, '0');
        else if ((spec.zero == 1 && spec.plus == 1 && spec.width > 0) && (n > 0))
        {
            result = ft_right(s, spec.width, ln, '0');
            result[0] = '+'; 
        }
        else if ((spec.zero == 1 && (spec.plus == 0 || spec.plus == 1 ) && spec.minus == 0 && spec.width > 0) && (n < 0))
        {
            result = ft_right(++s, spec.width, ln - 1, '0');
            result[0] = '-'; 
        }
        else if ((spec.zero == 0 || spec.zero == 1) && spec.plus == 0 && spec.width > 0 && spec.precision < 0 && spec.minus == 1)
            result = ft_left(s, spec.width, ln, ' ');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision >= 0 && spec.precision >= ln && spec.minus == 0 && n > 0)
            result = ft_right(s, spec.precision, ln, '0');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision >= 0 && spec.precision < ln && spec.minus == 0 && n > 0)
            result = ft_right(s, ln, ln, '0');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision >= 0 && spec.minus == 0 && n == 0)
            result = "";
        else if (spec.zero == 0 && spec.plus == 0 && spec.width >= spec.precision && spec.precision >= 0 && spec.minus == 0 && n == 0)
            result = ft_right(s, spec.width, 0, ' ');
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision > 0 && spec.precision >= ln && spec.minus == 0 && n < 0)
        {
            result = ft_right(s + 1, spec.precision + 2, ln, '0');
            result[0] = '-';
        }
        else if (spec.zero == 0 && spec.plus == 0 && spec.width <= spec.precision && spec.precision > 0 && spec.precision <= ln && spec.minus == 0)
            result = ft_right(s, ln, ln, '0');
        else if (spec.zero == 0 && spec.plus == 1 && (spec.width < spec.precision) && spec.precision > 0 && spec.precision > ln && spec.minus == 0)
        {
            result = ft_right(s, spec.precision + 1, ln, '0');
            result[0] = '+';
        }
        else if (spec.zero == 0 && spec.plus == 0 && spec.width < 0 && spec.precision > 0 && spec.precision < ln && spec.minus == 0)
            result = ft_right(s, ln, ln, ' ');
        else if ((spec.zero == 0 || spec.zero == 1) && spec.plus == 0 && spec.width > 0 && spec.precision > 0 && (spec.precision < spec.width) && spec.minus == 0)
        {
            result = ft_right(s, spec.precision, ln, '0');
            result = ft_right(result, spec.width, ft_strlen(result), ' ');
        }
        else if (spec.zero == 0 && spec.plus == 0 && spec.width > 0 && spec.precision > 0 && spec.minus == 1)
        {
            result = ft_right(s, spec.precision, ln, '0');
            result = ft_left(result, spec.width, ft_strlen(result), ' ');
        }
        else if (spec.zero == 0 && spec.plus == 1 && spec.width > spec.precision && spec.minus == 1)
        {
            result = ft_right(s, spec.precision + 1, ln, '0');
            result = ft_left(result, spec.width, ft_strlen(result), ' ');
            result[0] = '+';
        }
        else if (spec.zero == 0 && spec.plus == 1 && spec.width < spec.precision && spec.minus == 1)
        {
            result = ft_right(s, spec.precision + 1, ln, '0');
            result[0] = '+';
        }
        else if (spec.zero == 0 && spec.plus == 1 && spec.width > 0 && spec.precision > 0 && (spec.precision < spec.width) && spec.minus == 0)
        {
            result = ft_right(s, spec.precision + 1, ln, '0');
            result[0] = '+';
            result = ft_right(result, spec.width, ft_strlen(result), ' ');
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

