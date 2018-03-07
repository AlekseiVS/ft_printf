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
	else if (spec.width > 0 && n == 0)
	{
		result = ft_right(s, spec.width - 2, 0, '0');
		result = ft_strjoin(ox, result);
	}
	else if ((spec.width > (int)ft_strlen(s)) && ((int)ft_strlen(s) > spec.precision))
	{
		result = ft_strjoin(ox, s);
		result = ft_right(result, spec.width, ft_strlen(result), ' ');
	}
	else if ((spec.width < (int)ft_strlen(s)) && ((int)ft_strlen(s) < spec.precision))
	{
		result = ft_right(s, spec.precision, ft_strlen(s), '0');
		result = ft_strjoin(ox, result);
	}
	else
		result = ft_strjoin(ox, s);
	return (result);	
}