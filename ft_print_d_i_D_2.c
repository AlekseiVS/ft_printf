#include "ft_printf.h"

static char *ft_sf1(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    if (spec.minus == 1)
        result = ft_left(s, spec.width, ln, ' ');
    else if (spec.zero == 1 && spec.plus == 1 && n >= 0)
    {
        result = ft_right(s, spec.width, ln, '0');
        result[0] = '+';
    }
    else if ((spec.zero == 1 && n < 0) || (spec.zero == 1 && spec.plus == 1 && n < 0))
    {
        result = ft_right(++s, spec.width + 1, ln, '0');
        result[0] = '-';
    }   
    else if (spec.zero == 1 && n >= 0 && spec.precision < 0 && spec.space == 0)
        result = ft_right(s, spec.width, ln, '0');
    else if (spec.zero == 1 && n >= 0 && spec.precision < 0 && spec.space == 1)
    {
        result = ft_right(s, spec.width, ln, '0');
        result[0] = ' ';
    }
    else if (n == 0)
        result = ft_right("", spec.width, 0, ' ');
    else
        result = ft_right(s, spec.width, ln, ' ');
    return (result); // Сократить на 1 строку
}

 static char *ft_sf2_1(char *s, t_spec spec, int ln)
 {
    char *result;

    result = 0;
    if (spec.minus == 1 && spec.plus == 1)
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
    else if (spec.minus == 1)
    {
        result = ft_right(s, spec.precision, ln, '0');
        result = ft_left(result, spec.width, spec.precision, ' ');
    }
    return (result);
 } 

static char *ft_sf2(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    if (spec.minus == 0 && n < 0) 
    {
        result = ft_right(++s, spec.precision + 2, ln, '0');
        result[0] = '-';
        result = ft_right(result, spec.width, spec.precision + 1, ' ');
    }
    else if (spec.minus == 1 && n < 0) 
    {
        result = ft_right(++s, spec.precision + 2, ln, '0');
        result[0] = '-';
        result = ft_left(result, spec.width, spec.precision + 1, ' ');
    }
    else if (/*(spec.minus == 1 && spec.plus == 1) || */(spec.plus == 1) || (spec.minus == 1))
        result = ft_sf2_1(s, spec, ln);
    else
    {
        result = ft_right(s, spec.precision, ln, '0');
        result = ft_right(result, spec.width, spec.precision, ' ');
    }
    return (result);
}

static char *ft_sf3(char *s, t_spec spec, int ln, intmax_t n)
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
    else if (spec.space == 1) 
    {
        result = ft_right(s, spec.precision + 1, ln, '0');
        result[0] = ' ';
    }      
    else
        result = ft_right(s, spec.precision, ln, '0');
    return (result);
}

char *ft_string_formation_d(char *s, t_spec spec, int ln, intmax_t n)
{
    char *result;

    result = 0;
    if (ln >= spec.width && ln > spec.precision && (n < 0 || n >= 0))
    {
        if ((spec.plus == 1 && n >= 0) || (spec.plus == 1 && spec.space == 1 && n >= 0))
            result = ft_right(s, ln + 1, ln, '+');
        else if (spec.space == 1 && n >= 0)
            result = ft_right(s, ln + 1, ln, ' ');
        else if (n == 0)
            result = "";
        else
            result = s;
    }
    else if (ln <= spec.width && ln > spec.precision)
        result = ft_sf1(s, spec, ln, n);
    else if (ln <= spec.width && ln <= spec.precision && spec.width > spec.precision)
        result = ft_sf2(s, spec, ln, n);
    else if (ln <= spec.precision && spec.width <= spec.precision)
        result = ft_sf3(s, spec, ln, n);
    return (result);
}