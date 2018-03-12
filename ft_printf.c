#include "ft_printf.h"

int ft_printf(char *format, ...)
{
	t_spec spec;
	va_list ap;
	va_start(ap, format);
	
	ft_initialization(&spec);
	spec.result = 0;
	while(*format)
	{
		ft_initialization(&spec);   
		ft_search(format, &spec);

		if(spec.type == 'c' && spec.size != 2)
			ft_print_c(va_arg(ap, int), &spec);
		else if(spec.type == 's' && spec.size != 2)
			spec.result += ft_print_s(va_arg(ap, char *), spec);
		else if(spec.type == 'd' || spec.type == 'i' || spec.type == 'D')
			spec.result += ft_print_d_i_D(ap, spec);
		else if(spec.type == 'u' || spec.type == 'U')
			spec.result += ft_print_u_U(ap, spec);
		else if(spec.type == 'o' || spec.type == 'O')
			spec.result += ft_print_o_O(ap, spec);
		else if(spec.type == 'x' || spec.type == 'X' || spec.type == 'p')
			spec.result += ft_print_x_X_p(ap, spec);
		else if(spec.type == 'C' || spec.type == 'S' || (spec.size == 2 && (spec.type == 'c' || spec.type == 's')))
			spec.result += ft_print_C_S(ap, spec);
		format += (spec.ln_search + 1) + spec.ln_text;
	}
	va_end(ap);
	return (spec.result);
}

