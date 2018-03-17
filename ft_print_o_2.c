/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:18:06 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 14:34:30 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sf1_1(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;

	if (spec.minus == 1)
	{
		spec.tmp = ft_right(s, ln + 1, ln, '0');
		result = ft_left(spec.tmp, spec.width, ft_strlen(spec.tmp), ' ');
		ft_strdel(&spec.tmp);
	}
	else if (n == 0)
	{
		spec.tmp = ft_right(s, ln, ln, '0');
		result = ft_right(spec.tmp, spec.width, ft_strlen(spec.tmp), ' ');
		ft_strdel(&spec.tmp);
	}
	else
	{
		spec.tmp = ft_right(s, ln + 1, ln, '0');
		result = ft_right(spec.tmp, spec.width, ft_strlen(spec.tmp), ' ');
		ft_strdel(&spec.tmp);
	}
	return (result);
}

static char	*ft_sf1(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;

	if (spec.minus == 1 && spec.hesh == 0)
		result = ft_left(s, spec.width, ln, ' ');
	else if (spec.zero == 1 && spec.precision < 0)
		result = ft_right(s, spec.width, ln, '0');
	else if (spec.hesh == 1 || (spec.hesh == 1 && spec.minus == 1))
		result = ft_sf1_1(s, spec, ln, n);
	else if (n == 0 && spec.precision == 0)
		result = ft_right(s, spec.width, 0, ' ');
	else
		result = ft_right(s, spec.width, ln, ' ');
	return (result);
}

static char	*ft_sf2(char *s, t_spec spec, int ln, char *result)
{
	char *tmp;

	if (spec.minus == 1)
	{
		tmp = ft_right(s, spec.precision, ln, '0');
		result = ft_left(tmp, spec.width, spec.precision, ' ');
		ft_strdel(&tmp);
	}
	else
	{
		tmp = ft_right(s, spec.precision, ln, '0');
		result = ft_right(tmp, spec.width, spec.precision, ' ');
		ft_strdel(&tmp);
	}
	return (result);
}

char		*ft_string_formation_o(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;

	result = 0;
	if (ln >= spec.width && ln >= spec.precision)
	{
		if (n == 0 && spec.hesh == 0)
			result = ft_strdup("");
		else if (spec.hesh == 1 && n == 0)
			result = ft_strdup("0");
		else if (spec.hesh == 1 && n != 0)
			result = ft_right(s, ln + 1, ln, '0');
		else
			result = s;
	}
	else if (ln <= spec.width && ln >= spec.precision)
		result = ft_sf1(s, spec, ln, n);
	else if (ln <= spec.width && ln <= spec.precision
		&& spec.width > spec.precision)
		result = ft_sf2(s, spec, ln, result);
	else if (ln < spec.precision && spec.width <= spec.precision)
		result = ft_right(s, spec.precision, ln, '0');
	return (result);
}
