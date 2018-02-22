#include "ft_printf.h"

void  ft_not_valid_type(char c, t_spec *spec)
{
    if (spec->minus == 1)
    {
        spec->result += write (1, &c, 1);
        spec->width--;
        while (spec->width-- > 0)
            spec->result += write (1, " ", 1);
    }
    else if (spec->zero == 1)
    {
        spec->width--;
        while (spec->width-- > 0)
            spec->result += write (1, "0", 1);
        spec->result += write (1, &c, 1);    
    }
    else
    {
        spec->width--;
        while (spec->width-- > 0)
            spec->result += write (1, " ", 1);
        spec->result += write (1, &c, 1); 
    }   
}

void ft_search_flag(char *str_search, t_spec *spec)
{
    while (*str_search == '+' || *str_search == '-' || *str_search == ' ' || *str_search == '#' || *str_search == '0')
    {
        // if (ft_strchr(*str_search, '+'))
        //     spec->plus = 1;
        // if (ft_strchr(*str_search, '-'))
        //     spec->minus = 1;
        // if (ft_strchr(*str_search, ' '))
        //     spec->space = 1;
        // if (ft_strchr(*str_search, '#'))
        //     spec->hesh = 1;
        // if (ft_strchr(*str_search, '0'))
        //     spec->zero = 1;
        if (*str_search == '+')
            spec->plus = 1;
        else if (*str_search == '-')
            spec->minus = 1;
        else if (*str_search == ' ')
            spec->space = 1;
        else if (*str_search == '#')
            spec->hesh = 1;
        else if (*str_search == '0')
            spec->zero = 1;
        str_search++;
    }
}

void ft_search_width_precision(char **str_search, t_spec *spec)
{
    int ln;

    if (ft_isdigit(**str_search) == 1)
    {
        spec->width = ft_atoi(*str_search);
        ln = ft_strlen(ft_itoa(spec->width));
        *str_search = *str_search + ln;
    }
    if (**str_search == '.') //&& ft_isdigit(*((*str_search) + 1)) == 1)  
    {
        (*str_search)++;
        spec->precision = ft_atoi(*str_search);
        ln = ft_strlen(ft_itoa(spec->precision));
        *str_search = *str_search + ln;
    }
}

void ft_search_size(char **s, t_spec *spec)
{
    if (**s == 'h' || **s == 'l' || **s == 'j' || **s == 'z')
    {
        if ((**s) == 'h' && *((*s) + 1) == 'h' && ((int)spec->size <= 0))
        {
            spec->size = hh;
            (*s) += 2;
        }
        else if ((**s) == 'h' && !(*((*s) + 1) == 'h') && ((int)spec->size < 1))
            spec->size = h;
        else if ((**s) == 'l'&& !(*((*s) + 1) == 'l') && ((int)spec->size < 2))
            spec->size = l;
        else if ((**s) == 'l' && *((*s) + 1) == 'l' && ((int)spec->size < 3))
        {
            spec->size = ll;
            (*s) += 2;
        }
        else if ((**s == 'j') && ((int)spec->size < 4))
            spec->size = j;
        else if ((**s == 'z') && ((int)spec->size < 5))
            spec->size = z;
    }
}


char *ft_search_spec_type(char *format)
{
    while (*format)
    {
        if (ft_strchr(SPEC, *format))
            return (format);
        if (*format == '-' || *format == '+' || *format == ' ' || *format == '#' || *format == '0' ||
            (ft_isdigit(*format) == 1) || *format == '.'/*(*format == '.' && ft_isdigit(*(format + 1)) == 1)*/
            || *format == 'h' || *format == 'l' || *format == 'j' || *format == 'z')
            format++;
        else
            break;
    }
    return (format);
}
