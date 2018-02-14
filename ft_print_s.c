#include "ft_printf.h"

int ft_print_s(char *s, t_spec spec)
{
    char *result;
    int ln;

    ln = ft_strlen(s);
    if (spec.width >= 0 || spec.precision >= 0)
    {
        if (spec.minus == 1 && spec.precision >= 0)
            result = ft_left(s, spec.width, spec.precision, ' ');
        else if (spec.minus == 1 && spec.precision < 0)
            result = ft_left(s, spec.width, ln, ' '); 
        else if (spec.zero == 1 && spec.precision >= 0)
            result = ft_right(s, spec.width, spec.precision, '0');
        else if (spec.zero == 1 && spec.precision < 0)
            result = ft_right(s, spec.width, ln, '0');
        else if (spec.zero == 0 && spec.precision >= 0)
            result = ft_right(s, spec.width, spec.precision, ' ');
        else if (spec.zero == 0 && spec.precision < 0)
            result = ft_right(s, spec.width, ln, ' ');
        write (1, result, ft_strlen(result));
        return (ft_strlen(result));
    }
    else
    {
        write (1, s, ft_strlen(s));
        return (ft_strlen(s));
    }
}