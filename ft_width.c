#include "ft_printf.h"

void ft_width(char *s, t_spec *spec, int ln)
{

   if (spec->minus == 1)
    {
        write (1, s, ln);
        spec->width -= ln;
        while (spec->width-- > 0)
            write (1, " ", 1);
    }
    else if (spec->zero == 1)
    {
        spec->width--;
        while (spec->width-- > 0)
            write (1, "0", 1);
        write (1, s, ln);    
    }
    else
    {
        spec->width--;
        while (spec->width-- > 0)
             write (1, " ", 1);
        write (1, s, ln); 
    }   
} 