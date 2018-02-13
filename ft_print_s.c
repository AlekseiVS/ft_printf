#include "ft_printf.h"

void ft_print_s(char *s, t_spec spec)
{
   int ln;

   ln = ft_strlen(s);
   if (spec.minus == 1)
    {
        write (1, s, ft_strlen(s));
        spec.width -= ln;
        while (spec.width-- > 0)
            write (1, " ", 1);
    }
    else if (spec.zero == 1)
    {
        spec.width--;
        while (spec.width-- > 0)
            write (1, "0", 1);
        write (1, s, ft_strlen(s));    
    }
    else
    {
        spec.width--;
        while (spec.width-- > 0)
             write (1, " ", 1);
        write (1, s, ft_strlen(s)); 
    }   
}

