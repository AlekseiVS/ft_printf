#include "ft_printf.h"

char *ft_p1(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    if ((spec.plus == 1 && n >= 0) || (spec.plus == 1 && spec.space == 1 && n >= 0))
        result = ft_right(s, ln + 1, ln, '+');
    else if (spec.space == 1 && n >= 0)
        result = ft_right(s, ln + 1, ln, ' ');
    else if (n == 0)
        result = "";
    else
        result = s;
    return (result);
}

char *ft_p2(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    if (spec.minus == 1)
        result = ft_left(s, spec.width, ln, ' ');
    else if (spec.zero == 1 && spec.plus == 1 && n > 0)
    {
        result = ft_right(s, spec.width, ln, '0');
    result[0] = '+';
    }
    else if ((spec.zero == 1 && n < 0) || (spec.zero == 1 && spec.plus == 1 && n < 0))
    {
        result = ft_right(++s, spec.width + 1, ln, '0');
        result[0] = '-';
    }   
    else if (spec.zero == 1 && n >= 0)
        result = ft_right(s, spec.width, ln, '0');
    else if (n == 0)
        result = ft_right("", spec.width, 0, ' ');
    else
        result = ft_right(s, spec.width, ln, ' ');
    return (result);
}

static char *ft_p3_1(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    result = 0;
    if (spec.minus == 1 && n < 0) 
    {
        result = ft_right(++s, spec.precision + 2, ln, '0');
        result[0] = '-';
        result = ft_left(result, spec.width, spec.precision + 1, ' ');
    }
    else if (spec.minus == 1 && spec.plus == 1)
    {
        result = ft_right(s, spec.precision + 1, ln, '0');
        result[0] = '+';
        result = ft_left(result, spec.width, spec.precision + 1, ' ');
    }
    else if (spec.plus == 1)
    {
        result = ft_right(s, spec.precision + 1, ln, '0');
        result[0] = '+';
        result = ft_right(result, spec.width, spec.precision + 1, ' ');
    }
    return (result);
} 

char *ft_p3(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    if (spec.minus == 0 && n < 0) 
    {
        result = ft_right(++s, spec.precision + 2, ln, '0');
        result[0] = '-';
        result = ft_right(result, spec.width, spec.precision + 1, ' ');
    }
    else if ((spec.minus == 1 && n < 0) || (spec.minus == 1 && spec.plus == 1) || (spec.plus == 1))
    {
        result = ft_p3_1(s, spec, ln, n);
    }
    else if (spec.minus == 1)
    {
        result = ft_right(s, spec.precision, ln, '0');
        result = ft_left(result, spec.width, spec.precision, ' ');
    }
    else
        {
            result = ft_right(s, spec.precision, ln, '0');
            result = ft_right(result, spec.width, spec.precision, ' ');
        }
    return (result);
}

char *ft_p4(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    if (spec.plus == 1)
    {
        result = ft_right(s, spec.precision + 1, ln, '0');
        result[0] = '+';
    }
    else if ( n < 0) 
    {
        result = ft_right(++s, spec.precision + 2, ln, '0');
        result[0] = '-';
    }   
    else
        result = ft_right(s, spec.precision, ln, '0');
    return (result);
}