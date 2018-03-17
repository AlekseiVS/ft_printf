/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:18:18 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 13:22:31 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sf2_1(char *s, t_spec spec, int ln)
{
	char *result;
	char *tmp;

	result = 0;
	if (spec.minus == 1 && spec.plus == 1)
	{
		tmp = ft_right(s, spec.precision + 1, ln, '0');
		tmp[0] = '+';
		result = ft_left(tmp, spec.width, spec.precision + 1, ' ');
	}
	else if (spec.plus == 1)
	{
		tmp = ft_right(s, spec.precision + 1, ln, '0');
		tmp[0] = '+';
		result = ft_right(tmp, spec.width, spec.precision + 1, ' ');
	}
	else if (spec.minus == 1)
	{
		tmp = ft_right(s, spec.precision, ln, '0');
		result = ft_left(tmp, spec.width, spec.precision, ' ');
	}
	ft_strdel(&tmp);
	return (result);
}

static char	*ft_sf2(char *s, t_spec spec, int ln, intmax_t n)
{
	char *result;

	if (spec.minus == 0 && n < 0)
	{
		spec.tmp = ft_right(++s, spec.precision + 2, ln, '0');
		spec.tmp[0] = '-';
		result = ft_right(spec.tmp, spec.width, spec.precision + 1, ' ');
	}
	else if (spec.minus == 1 && n < 0)
	{
		spec.tmp = ft_right(++s, spec.precision + 2, ln, '0');
		spec.tmp[0] = '-';
		result = ft_left(spec.tmp, spec.width, spec.precision + 1, ' ');
	}
	else if ((spec.plus == 1) || (spec.minus == 1))
		result = ft_sf2_1(s, spec, ln);
	else
	{
		spec.tmp = ft_right(s, spec.precision, ln, '0');
		result = ft_right(spec.tmp, spec.width, spec.precision, ' ');
	}
	ft_strdel(&spec.tmp);
	return (result);
}

static char	*ft_sf3(char *s, t_spec spec, int ln, intmax_t n)
{
	char *result;

	if (spec.plus == 1)
	{
		result = ft_right(s, spec.precision + 1, ln, '0');
		result[0] = '+';
	}
	else if (n < 0 && spec.precision >= spec.width)
	{
		result = ft_right(s + 1, spec.precision + 2, ln, '0');
		result[0] = '-';
	}
	else if (spec.space == 1)
	{
		result = ft_right(s, spec.precision + 1, ln, '0');
		result[0] = ' ';
	}
	else
		result = ft_right(s, spec.precision, ln, '0');
	return (result);
}

char		*ft_string_formation_d(char *s, t_spec spec, int ln, intmax_t n)
{
	char *result;

	result = 0;
	if (ln >= spec.width && ln > spec.precision && (n < 0 || n >= 0))
	{
		if ((spec.plus == 1 && n >= 0) ||
		(spec.plus == 1 && spec.space == 1 && n >= 0))
			result = ft_right(s, ln + 1, ln, '+');
		else if (spec.space == 1 && n >= 0)
			result = ft_right(s, ln + 1, ln, ' ');
		else if (n == 0)
			result = ft_strdup("");
		else
			result = s;
	}
	else if (ln <= spec.width && ln > spec.precision)
		result = ft_sf_d(s, spec, ln, n);
	else if (ln <= spec.width && ln <= spec.precision &&
		spec.width >= spec.precision)
		result = ft_sf2(s, spec, ln, n);
	else if (ln <= spec.precision && spec.width < spec.precision)
		result = ft_sf3(s, spec, ln, n);
	return (result);
}
