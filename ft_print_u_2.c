/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:47:32 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 14:48:36 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sf1(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;

	if (spec.minus == 1)
		result = ft_left(s, spec.width, ln, ' ');
	else if (spec.zero == 1 && spec.precision < 0)
		result = ft_right(s, spec.width, ln, '0');
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

char		*ft_string_formation_u(char *s, t_spec spec, int ln, uintmax_t n)
{
	char *result;

	result = 0;
	if (ln >= spec.width && ln >= spec.precision)
	{
		if (n == 0)
			result = ft_strdup("");
		else
			result = s;
	}
	else if (ln <= spec.width && ln > spec.precision)
		result = ft_sf1(s, spec, ln, n);
	else if (ln <= spec.width && ln <= spec.precision
		&& spec.width > spec.precision)
		result = ft_sf2(s, spec, ln, result);
	else if (ln < spec.precision && spec.width <= spec.precision)
		result = ft_right(s, spec.precision, ln, '0');
	return (result);
}
