/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:30:56 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 14:42:29 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_s_1(t_spec spec, char *s, int ln)
{
	if (spec.minus == 1 && spec.precision >= 0 && spec.width >= 0 && !(*s))
		s = ft_left(s, spec.width, 0, ' ');
	else if (spec.minus == 1 && spec.precision >= 0 && spec.width >= 0
		&& (spec.precision < spec.width))
		s = ft_left(s, spec.width, spec.precision, ' ');
	else if (spec.minus == 1 && spec.precision == -1 && spec.width >= 0)
		s = ft_left(s, spec.width, ln, ' ');
	else if (spec.minus == 1 && (spec.precision >= 0 && spec.width == -1))
		s = ft_strsub(s, 0, spec.precision);
	else if (spec.zero == 1 && spec.precision >= 0
		&& (spec.precision < spec.width))
		s = ft_right(s, spec.width, spec.precision, '0');
	else if (spec.precision >= 0 && spec.width >= 0
		&& (spec.precision > spec.width))
		s = ft_right(s, spec.precision, ln, ' ');
	else if (spec.zero == 1 && spec.precision < 0)
		s = ft_right(s, spec.width, ln, '0');
	return (s);
}

char static	*ft_print_s_2(t_spec spec, char *s, int ln)
{
	if (spec.precision >= 0 && spec.width >= 0 && (spec.precision > spec.width)
		&& spec.precision <= ln)
		s = ft_right(s, spec.precision, ln, ' ');
	else if (spec.precision >= 0 && spec.width >= 0
		&& (spec.precision > spec.width)
		&& spec.precision > ln && spec.width > ln)
		s = ft_right(s, spec.width, ln, ' ');
	else if (spec.precision >= 0 && spec.width >= 0
		&& (spec.precision > spec.width)
		&& spec.precision > ln && spec.width < ln)
		s = ft_right(s, ln, ln, ' ');
	else if (spec.precision == -1 && spec.width >= 0 && spec.width >= ln)
		s = ft_right(s, spec.width, ln, ' ');
	else if (spec.precision == -1 && spec.width >= 0 && spec.width < ln)
		s = ft_right(s, ln, ln, ' ');
	else if (spec.precision < spec.width && !(*s))
		s = ft_right(s, spec.width, 0, ' ');
	else if (spec.precision < spec.width && ln <= spec.precision)
		s = ft_right(s, spec.width, ln, ' ');
	else if (spec.precision < spec.width && ln > spec.precision)
		s = ft_right(s, spec.width, spec.precision, ' ');
	else if (spec.precision >= 0 && spec.width == -1)
		s = ft_strsub(s, 0, spec.precision);
	return (s);
}

int			ft_print_s(char *s, t_spec spec)
{
	int ln;

	if (!s)
		s = "(null)";
	ln = ft_strlen(s);
	if (spec.width >= 0 || spec.precision >= 0)
	{
		if (spec.minus == 1 || spec.zero == 1)
			s = ft_print_s_1(spec, s, ln);
		else
			s = ft_print_s_2(spec, s, ln);
		ln = ft_strlen(s);
		write(1, s, ln);
		ft_strdel(&s);
		return (ln);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
