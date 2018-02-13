#include "ft_printf.h"

char *ft_serch_spec_type(char *format)
{
    while (*format)
    {
        if (ft_strchr(SPEC, *format))
            return (format);
        format++;
    }
    return (0);
}

void ft_serch_size(char **s, t_spec *spec)
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

void ft_search(char *format, t_spec *spec)
{
    char *str_search;
    int ln;
    char *type;

    spec->ln_text = ft_strchr(format, '%') - format;
    write (1, format, spec->ln_text);
    write (1, "\n", 1);
    spec->type = *(type = ft_serch_spec_type(format + spec->ln_text));
    //type = ft_serch_spec_type(format + spec->ln_text);
    spec->type = *type;
    spec->ln_search = ft_strchr(format, *type) - ft_strchr(format, '%');
    str_search = ft_strsub(format, spec->ln_text, spec->ln_search);// + 1 'type'); 
    str_search++; // Переходи со знака % на сдедующий и заходим в цыкл.
        
    while (*str_search)
    {
        if (*str_search == '-' || *str_search == '+' || *str_search == ' ' || *str_search == '#' || *str_search == '0')
            spec->flag = *str_search;
        if (ft_isdigit(*str_search) == 1)
        {
            spec->width = ft_atoi(str_search);
            ln = ft_strlen(ft_itoa(spec->width));
            str_search = str_search + ln;
        }
        if (*str_search == '.' && ft_isdigit(*(str_search + 1)) == 1)  
        {
            str_search++;
            spec->precision = ft_atoi(str_search);
            ln = ft_strlen(ft_itoa(spec->precision));
            str_search = str_search + ln;
        }
        if (*str_search == 'h' || *str_search == 'l' || *str_search == 'j' || *str_search == 'z')
            ft_serch_size(&str_search, spec);
        // if (ft_serch_spec(*str_search) == 1)
        //     spec->type = *str_search;
        str_search++;
    }
    //return (spec);
}