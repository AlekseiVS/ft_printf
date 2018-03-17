/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_formation_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:20:09 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 17:22:57 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sf_p_1_1_1(char *s, t_spec spec, char *ox, uintmax_t n)
{
	char *result;

	if (n == 0 && spec.width >= spec.precision && spec.precision != -1)
	{
		spec.tmp = ft_right(s, spec.precision, 0, '0');
		result = ft_strjoin(ox, spec.tmp);
		ft_strdel(&spec.tmp);
		spec.tmp = result;
		result = ft_right(result, spec.width, spec.precision + 2, ' ');
		ft_strdel(&spec.tmp);
	}
	else
		result = ft_strjoin(ox, s);
	return (result);
}

static char	*ft_sf_p_1_1(char *s, t_spec spec, char *ox, uintmax_t n)
{
	char *result;

	if ((spec.width < (int)ft_strlen(s))
	&& ((int)ft_strlen(s) < spec.precision))
	{
		spec.tmp = ft_right(s, spec.precision, ft_strlen(s), '0');
		result = ft_strjoin(ox, spec.tmp);
		ft_strdel(&spec.tmp);
	}
	else if (n == 0 && spec.width > 0 && spec.precision == -1)
	{
		spec.tmp = ft_strjoin(ox, s);
		result = ft_right(spec.tmp, spec.width, ft_strlen(spec.tmp), ' ');
		ft_strdel(&spec.tmp);
	}
	else
		result = ft_sf_p_1_1_1(s, spec, ox, n);
	return (result);
}

static char	*ft_sf_p_1(char *s, t_spec spec, char *ox, uintmax_t n)
{
	char *result;

	if ((spec.width > (int)ft_strlen(s))
	&& ((int)ft_strlen(s) > spec.precision)
	&& spec.minus == 0 && n != 0)
	{
		spec.tmp = ft_strjoin(ox, s);
		result = ft_right(spec.tmp, spec.width, ft_strlen(spec.tmp), ' ');
		ft_strdel(&spec.tmp);
	}
	else if ((spec.width > (int)ft_strlen(s))
	&& ((int)ft_strlen(s) > spec.precision)
	&& spec.minus == 1 && (n == 0 || n > 0))
	{
		result = ft_strjoin(ox, s);
		if ((int)ft_strlen(result) < spec.width)
		{
			spec.tmp = result;
			result = ft_left(result, spec.width, ft_strlen(result), ' ');
			ft_strdel(&spec.tmp);
		}
	}
	else
		result = ft_sf_p_1_1(s, spec, ox, n);
	return (result);
}

char		*ft_string_formation_p(char *s, t_spec spec, char *ox, uintmax_t n)
{
	char *result;

	if (spec.precision == 0 && n == 0 && spec.width == -1)
		result = ft_strjoin(ox, ft_strdup(""));
	else if (spec.precision >= 0 && n == 0 && spec.width == -1)
	{
		spec.tmp = ft_right(s, spec.precision, 0, '0');
		result = ft_strjoin(ox, spec.tmp);
		ft_strdel(&spec.tmp);
	}
	else if (spec.width > 0 && n == 0 && spec.zero == 1 && spec.minus == 0)
	{
		spec.tmp = ft_right(s, spec.width - 2, 1, '0');
		result = ft_strjoin(ox, spec.tmp);
		ft_strdel(&spec.tmp);
	}
	else
		result = ft_sf_p_1(s, spec, ox, n);
	return (result);
}
