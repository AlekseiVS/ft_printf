#include "ft_printf.h"

void    ft_print_c(char c, t_spec spec)
{
    int ln;
    
    ln = 1;
    if (spec.minus == 1)
    {
        write (1, &c, 1);
        spec.width -= ln;
        while (spec.width-- > 0)
            write (1, " ", 1);
    }
    else if (spec.zero == 1)
    {
        spec.width--;
        while (spec.width-- > 0)
            write (1, "0", 1);
        write (1, &c, 1);    
    }
    else
    {
        spec.width--;
        while (spec.width-- > 0)
             write (1, " ", 1);
        write (1, &c, 1); 
    }   
}