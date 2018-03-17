/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:20:50 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 18:46:06 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_unicode(char *s, wchar_t n, int *ln)
{
	if (n <= 127 || (MB_CUR_MAX == 1))
		*s = n;
	else if (n <= 2047)
	{
		s[0] = (n >> 6) | 192;
		s[1] = (n & 63) | 128;
	}
	else if (n <= 65535)
	{
		s[0] = (n >> 12) | 224;
		s[1] = ((n >> 6) & 63) | 128;
		s[2] = (n & 63) | 128;
	}
	else
	{
		s[0] = (n >> 18) | 240;
		s[1] = ((n >> 12) & 63) | 128;
		s[2] = ((n >> 6) & 63) | 128;
		s[3] = (n & 63) | 128;
	}
	*ln += ft_strlen(s);
	return (s);
}

static char	*ft_form_str_c_s(t_spec spec, int *ln, wchar_t *n_s, wchar_t n_c)
{
	char *str;
	char *s;

	str = ft_strdup("");
	if (spec.type == 'S' || (spec.size == 2 && spec.type == 's'))
	{
		while (*n_s != '\0')
		{
			s = ft_strnew(4);
			spec.tmp = str;
			str = ft_strjoin(str, ft_print_unicode(s, *n_s, ln));
			ft_strdel(&spec.tmp);
			ft_strdel(&s);
			n_s++;
		}
	}
	else
	{
		s = ft_strnew(4);
		spec.tmp = str;
		str = ft_strdup(ft_print_unicode(s, n_c, ln));
		ft_strdel(&spec.tmp);
		ft_strdel(&s);
	}
	return (str);
}

static char	*ft_width_c_s(t_spec spec, char *s, int *ln)
{
	char *result;

	if (spec.width > *ln && spec.zero == 0 && spec.minus == 0
		&& spec.precision == -1)
		result = ft_right(s, spec.width, *ln, ' ');
	else if (spec.width > *ln && spec.zero == 1 && spec.minus == 0
		&& spec.precision == -1)
		result = ft_right(s, spec.width, *ln, '0');
	else if (spec.width > *ln && spec.minus == 1 && spec.precision == -1)
		result = ft_left(s, spec.width, *ln, ' ');
	else if ((spec.width >= *ln || spec.width < *ln) && spec.zero == 1
		&& spec.precision == 0)
		result = ft_right(s, spec.width, 0, '0');
	else if ((spec.width >= *ln || spec.width < *ln) && spec.precision == 0)
		result = ft_left(s, spec.width, 0, ' ');
	else
		result = ft_strdup(s);
	free(s);
	*ln = ft_strlen(result);
	return (result);
}

int			ft_print_c_s(va_list ap, t_spec spec)
{
	wchar_t	*n_s;
	wchar_t	n_c;
	char	*s;
	int		ln;

	n_s = 0;
	n_c = 0;
	ln = 0;
	if (spec.type == 'S' || (spec.size == 2 && spec.type == 's'))
	{
		n_s = va_arg(ap, wchar_t*);
		if (n_s == 0)
			return (write(1, "(null)", 6));
	}
	else if (spec.type == 'C' || (spec.size == 2 && spec.type == 'c'))
	{
		n_c = va_arg(ap, wchar_t);
		if (n_c == 0)
			return (write(1, "\0", 1));
	}
	s = ft_form_str_c_s(spec, &ln, n_s, n_c);
	spec.tmp = ft_width_c_s(spec, s, &ln);
	ft_putstr(spec.tmp);
	ft_strdel(&spec.tmp);
	return (ln);
}
