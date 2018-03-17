/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_p_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:18:20 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 17:19:57 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sf_x_1(char *s, t_spec spec, int ln)
{
	char *ox;
	char *result;

	ox = "0x";
	if (spec.hesh == 1)
	{
		spec.tmp = ft_right(s, spec.precision, ln, '0');
		result = ft_strjoin(ox, spec.tmp);
		ft_strdel(&spec.tmp);
		spec.tmp = result;
		result = ft_right(result, spec.width, spec.precision + 2, ' ');
		ft_strdel(&spec.tmp);
	}
	else
	{
		spec.tmp = ft_right(s, spec.precision, ln, '0');
		result = ft_right(spec.tmp, spec.width, spec.precision, ' ');
		ft_strdel(&spec.tmp);
	}
	return (result);
}

char		*ft_sf_x(char *s, t_spec spec, int ln)
{
	char *ox;
	char *result;

	ox = "0x";
	if (spec.minus == 1)
	{
		if (spec.hesh == 1)
		{
			spec.tmp = ft_right(s, spec.precision, ln, '0');
			result = ft_strjoin(ox, spec.tmp);
			ft_strdel(&spec.tmp);
			spec.tmp = result;
			result = ft_left(result, spec.width, spec.precision + 2, ' ');
			ft_strdel(&spec.tmp);
		}
		else
		{
			spec.tmp = ft_right(s, spec.precision, ln, '0');
			result = ft_left(spec.tmp, spec.width, spec.precision, ' ');
			ft_strdel(&spec.tmp);
		}
	}
	else
		result = ft_sf_x_1(s, spec, ln);
	return (result);
}
