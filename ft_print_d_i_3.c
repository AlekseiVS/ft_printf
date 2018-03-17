/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:22:45 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 13:24:52 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sf_d_1(char *s, t_spec spec, int ln, intmax_t n)
{
	char	*result;

	if (spec.zero == 1 && n >= 0 && spec.precision < 0 && spec.space == 0)
		result = ft_right(s, spec.width, ln, '0');
	else if (spec.zero == 1 && n >= 0 && spec.precision < 0 && spec.space == 1)
	{
		result = ft_right(s, spec.width, ln, '0');
		result[0] = ' ';
	}
	else if (n == 0 && spec.precision == 0)
		result = ft_right(s, spec.width, 0, ' ');
	else
		result = ft_right(s, spec.width, ln, ' ');
	return (result);
}

char		*ft_sf_d(char *s, t_spec spec, int ln, intmax_t n)
{
	char *result;

	if (spec.minus == 1)
		result = ft_left(s, spec.width, ln, ' ');
	else if (spec.zero == 1 && spec.plus == 1 && n >= 0)
	{
		result = ft_right(s, spec.width, ln, '0');
		result[0] = '+';
	}
	else if ((spec.zero == 1 && n < 0) ||
	(spec.zero == 1 && spec.plus == 1 && n < 0))
	{
		result = ft_right(++s, spec.width + 1, ln, '0');
		result[0] = '-';
	}
	else
		result = ft_sf_d_1(s, spec, ln, n);
	return (result);
}
