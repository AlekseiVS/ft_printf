#include "ft_printf.h"

static int ft_print_unicode(char *s, wchar_t n)
{
    if (n <= 127)
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
    ft_putstr(s);
    return (ft_strlen(s));
}

int ft_print_C_S(va_list ap, t_spec spec)
{
    wchar_t *n1;
    wchar_t n2;
    int ln;
    char *s;

    n1 = 0;
    n2 = 0;
    ln = 0;
    if (spec.type == 'S' || (spec.size == 2 && spec.type == 's'))
    {
        n1 = va_arg(ap, wchar_t*);
        if (n1 == 0)
            return (write(1, "(null)", 6));
    }
    else if (spec.type == 'C' || (spec.size == 2 && spec.type == 'c'))
    {
        n2 = va_arg(ap, wchar_t);
        if (n2 == 0)
            return (write(1, "\0", 1));
    }
    
    if(spec.type == 'S' || (spec.size == 2 && spec.type == 's'))
    {
        while(*n1 != '\0')
        {
            s = ft_strnew(4);
            ln += ft_print_unicode(s, *n1);
            n1++;
        }
    }
    else
    {
        s = ft_strnew(4);
        ln += ft_print_unicode(s, n2);
    }
    return (ln);
}