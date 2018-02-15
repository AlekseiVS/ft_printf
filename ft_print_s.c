#include "ft_printf.h"

char *ft_print_s_1(t_spec spec, char *s, int ln, char *result)
{
    if (spec.minus == 1 && spec.precision >= 0 && spec.width >= 0 && !(*s))
        result = ft_left(s, spec.width, 0, ' ');
    else if (spec.minus == 1 && spec.precision >= 0 && spec.width >= 0)
        result = ft_left(s, spec.width, spec.precision, ' ');
    else if (spec.minus == 1 && spec.precision == -1 && spec.width >= 0)
        result = ft_left(s, spec.width, ln, ' ');
    else if (spec.minus == 1 && (spec.precision >= 0 && spec.width == -1))
        result = ft_strsub(s, 0, spec.precision);
    else if (spec.zero == 1 && spec.precision >= 0)
        result = ft_right(s, spec.width, spec.precision, '0');
    else if (spec.zero == 1 && spec.precision < 0)
            result = ft_right(s, spec.width, ln, '0');
    return (result);
}

char *ft_print_s_2(t_spec spec, char *s, int ln, char *result)
{
    if (spec.precision >= 0 && spec.width >= 0 && (spec.precision > spec.width))
        result = ft_right(s, spec.width, ln, ' ');
    else if (spec.precision == -1 && spec.width >= 0)
        result = ft_right(s, spec.width, ln, ' ');
    else if (spec.precision < spec.width && !(*s))
        result = ft_right(s, spec.width, 0, ' ');
    else if (spec.precision < spec.width)
        result = ft_right(s, spec.width, spec.precision, ' ');
    else if (spec.precision >= 0 && spec.width == -1)
        result = ft_strsub(s, 0, spec.precision);
    return (result);
}

int ft_print_s(char *s, t_spec spec)
{
    char *result;
    int ln;

    if (!s)
    {
        write (1, "(null)", 6);
        return (6);
    }
    result = 0;
    ln = ft_strlen(s);
    if (spec.width >= 0 || spec.precision >= 0)
    {
        if (spec.minus == 1 || spec.zero == 1)
            result = ft_print_s_1(spec, s, ln, result);
        else
            result = ft_print_s_2(spec, s, ln, result);
        write (1, result, ft_strlen(result));
        return (ft_strlen(result));
    }
    else
    {
        write (1, s, ft_strlen(s));
        return (ft_strlen(s));
    }
}