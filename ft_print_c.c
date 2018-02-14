#include "ft_printf.h"

void    ft_print_c(char c, t_spec *spec)
{
    if (spec->minus == 1)
    {
        spec->result += write (1, &c, 1);
        spec->width -= 1;
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