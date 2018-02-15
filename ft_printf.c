#include "ft_printf.h"

void ft_initialization(t_spec *spec)
{
    spec->plus = 0;
    spec->minus = 0;
    spec->space = 0;
    spec->hesh = 0;
    spec->zero = 0;
    spec->width = -1;
    spec->precision = -1;
    spec->size = -1;
    spec->type = 0;
    spec->ln_search = 0;
    spec->ln_text = 0;
}

int ft_printf(char *format, ...)
{
    t_spec spec;
    va_list ap;
	va_start(ap, format);
    
    spec.result = 0;
    while(*format)
    {
        ft_initialization(&spec);   

	    ft_search(format, &spec);
        //printf("flag: %c\nwidth: %d\nprecision: %d\nsize: %d\ntype: %c\n", spec.flag, spec.width, spec.precision, spec.size, spec.type);
        if(spec.type == 'c')
            ft_print_c(va_arg(ap, int), &spec);
        else if(spec.type == 's')
            spec.result += ft_print_s(va_arg(ap, char *), spec);
        else if(spec.type == 'd')
            spec.result += ft_print_d(ap, spec);
        format += (spec.ln_search + 1) + spec.ln_text;
    }
    va_end(ap);
    return (spec.result);
}

