#include "ft_printf.h"

static char *ft_print_unicode(char *s, wchar_t n, int *ln)
{
    if (n <= 127 || (MB_CUR_MAX == 1))
        *s = n;
    else if (n <= 2047)
    {
        s[0] = (n >> 6) | 192;
        s[1] = (n & 63) | 128;
    }
    else if (n <= 65535)
    {
        s[0] = (n >> 12) | 224;
        s[1] = ((n >> 6) & 63) | 128;
        s[2] = (n & 63) | 128;
    }
    else
    {
        s[0] = (n >> 18) | 240;
        s[1] = ((n >> 12) & 63) | 128;
        s[2] = ((n >> 6) & 63) | 128;
        s[3] = (n & 63) | 128;
    }
    *ln += ft_strlen(s);
    return(s);
}

static char *ft_formation_string_C_S(t_spec spec, int *ln, wchar_t *n_S, wchar_t n_C)
{
    char *str;
    char *s;

    str = ft_strdup("");
    if(spec.type == 'S' || (spec.size == 2 && spec.type == 's'))
    {
        while(*n_S != '\0')
        {
            s = ft_strnew(4);
            str = ft_strjoin(str, ft_print_unicode(s, *n_S, ln));
            ft_strdel(&s);
            n_S++;
        }
    }
    else
    {
        s = ft_strnew(4);
        str = ft_print_unicode(s, n_C, ln);
        ft_strdel(&s);        
    }
    return (str);
}

static char *ft_width_C_S(t_spec spec, char *s, int *ln)
{
    if (spec.width > *ln && spec.zero == 0 && spec.minus == 0 && spec.precision == -1)
        s = ft_right(s, spec.width, *ln, ' ');
    else if (spec.width > *ln && spec.zero == 1 && spec.minus == 0 && spec.precision == -1)
        s = ft_right(s, spec.width, *ln, '0');
    else if (spec.width > *ln && spec.minus == 1 && spec.precision == -1)
        s = ft_left(s, spec.width, *ln, ' ');
    else if ((spec.width >= *ln || spec.width < *ln) && spec.zero == 1 && spec.precision == 0)
        s = ft_right(s, spec.width, 0, '0');
    else if ((spec.width >= *ln || spec.width < *ln) && spec.precision == 0)
        s = ft_left(s, spec.width, 0, ' ');
    *ln = ft_strlen(s);
    return (s);
}

int ft_print_C_S(va_list ap, t_spec spec)
{
    wchar_t *n_S;
    wchar_t n_C;
    char *s;
    char *tmp;
    int ln;

    n_S = 0;
    n_C = 0;
    ln = 0;
    if (spec.type == 'S' || (spec.size == 2 && spec.type == 's'))
    {
        n_S = va_arg(ap, wchar_t*);
        if (n_S == 0)
            return (write(1, "(null)", 6));
    }
    else if (spec.type == 'C' || (spec.size == 2 && spec.type == 'c'))
    {
        n_C = va_arg(ap, wchar_t);
        if (n_C == 0)
            return (write(1, "\0", 1));
    }
    s = ft_formation_string_C_S(spec, &ln, n_S, n_C);
    tmp = ft_width_C_S(spec, s, &ln);
    ft_putstr(tmp);
    // ft_strdel(&tmp);
    // ft_strdel(&s);
    return (ln);
}