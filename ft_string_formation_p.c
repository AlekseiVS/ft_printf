#include "ft_printf.h"

char *ft_string_formation_p(char *s, t_spec spec, char *ox, uintmax_t n)
{
	char *result;
	
	if (spec.precision == 0 && n == 0)
		result = ft_strjoin(ox, "");
	else if (spec.precision >= 0 && n == 0)
	{
		result = ft_right(s, spec.precision, 0, '0');
		result = ft_strjoin(ox, result);
	}
	else
		result = ft_strjoin(ox, s);
	return (result);	
}