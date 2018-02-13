#include "ft_printf.h"

void ft_search(char *format, t_spec *spec)
{
    char *str_search;
    char *type;

    if (!(ft_strchr(format, '%')))
    {
        write(1, format, 1);
        return ;
    }   
    spec->ln_text = ft_strchr(format, '%') - format;
    write (1, format, spec->ln_text);
    type = ft_search_spec_type(format + spec->ln_text + 1);
    if (*type == '\0')
    {
        spec->ln_search = (type - 1) - ft_strchr(format, '%');
        return ;
    }
    spec->type = *type;
    spec->ln_search = type - ft_strchr(format, '%');
    str_search = ft_strsub(format, spec->ln_text, spec->ln_search);
    str_search++; // Переходи со знака % на сдедующий и заходим в цыкл.
    
    while (*str_search)
    {
        ft_search_flag(&str_search, spec);
        ft_search_width_precision(&str_search, spec);
        ft_search_size(&str_search, spec);
        str_search++;
    }
    if (!(ft_strchr(SPEC, spec->type)))
        ft_not_valid_type(spec->type, spec);
}