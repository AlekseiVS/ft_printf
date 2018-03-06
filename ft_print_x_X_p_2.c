#include "ft_printf.h"

static char *ft_sf1_1(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;
	char *ox;
	
	ox = "0x";
	if (spec.minus == 1)
	{
		result = ft_right(s, ln, ln, '0');
		result = ft_strjoin(ox, s);
		result = ft_left(result, spec.width, ft_strlen(result), ' ');
	}
	else if (n == 0)
	{
		result = ft_right(s, ln, ln, '0');
		result = ft_right(result, spec.width, ft_strlen(result), ' ');
	}
	else
	{
		result = ft_right(s, ln, ln, '0');
		result = ft_strjoin(ox, s);
		result = ft_right(result, spec.width, ft_strlen(result), ' ');
	}
	return (result);
}

static char *ft_sf1(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;
	char *ox;

	result = 0;
	ox = "0x";
	if (spec.minus == 1 && spec.hesh == 0)
		result = ft_left(s, spec.width, ln, ' ');
	else if (spec.zero == 1 && spec.precision < 0 && spec.minus == 0)
	{    
		if (spec.hesh == 1)
		{
			result = ft_right(s, spec.width - 2, ln, '0');
			result = ft_strjoin(ox, result);
		}
		else
			result = ft_right(s, spec.width, ln, '0');
	}
	else if (spec.hesh == 1 || (spec.hesh == 1 && spec.minus == 1))
		result = ft_sf1_1(s, spec, ln, n);
	else if (n == 0)
		result = ft_right(s, spec.width, 0, ' ');
	else
		result = ft_right(s, spec.width, ln, ' ');
	return (result);
}

static char *ft_sf2(char *s, t_spec spec, int ln, char *result)
{
	if (spec.minus == 1)
	{
		result = ft_right(s, spec.precision, ln, '0');
		result = ft_left(result, spec.width, spec.precision, ' ');
	}
	else
	{
		result = ft_right(s, spec.precision, ln, '0');
		result = ft_right(result, spec.width, spec.precision, ' ');
	}
	return (result);
}

char *ft_string_formation_x(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;
	char *ox;
	int		i;

	result = 0;
	ox = "0x";
	if (spec.type == 'p')
		result = ft_string_formation_p(s, spec, ox, n);
	else if ((ln >= spec.width && ln >= spec.precision))
	{
		if (n == 0 && (spec.precision != -1 || spec.width != -1) && (spec.hesh == 1 || spec.hesh == 0))
			result = "";
		else if (spec.hesh == 1 && n != 0)
			result = ft_strjoin(ox, s);
		else
			result = s;
	}
	else if (ln <= spec.width && ln > spec.precision)
		result = ft_sf1(s, spec, ln, n);
	else if (ln <= spec.width && ln <= spec.precision && spec.width > spec.precision)
		result = ft_sf2(s, spec, ln, result);
	else if (ln < spec.precision && spec.width <= spec.precision)
		result = ft_right(s, spec.precision, ln, '0');
	if ((spec.type == 'X') && (i = -1))
		while (result[++i])
			result[i] = ft_toupper(result[i]);
	return (result);
}