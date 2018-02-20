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