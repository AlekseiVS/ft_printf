/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:37:05 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 18:24:00 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_search_1(char *str_search, t_spec *spec)
{
	char *buff_str_search;

	buff_str_search = str_search;
	str_search++;
	while (*str_search)
	{
		ft_search_flag(str_search, spec);
		ft_search_width_precision(&str_search, spec);
		ft_search_size(&str_search, spec);
		if (*str_search != '\0')
			str_search++;
	}
	ft_strdel(&buff_str_search);
}

void		ft_search(char *format, t_spec *spec)
{
	char *str_search;
	char *type;

	if (!(ft_strchr(format, '%')))
	{
		spec->result += write(1, format, 1);
		return ;
	}
	spec->ln_text = ft_strchr(format, '%') - format;
	spec->result += write(1, format, spec->ln_text);
	type = ft_search_spec_type(format + spec->ln_text + 1);
	if (*type == '\0')
	{
		spec->ln_search = (type - 1) - ft_strchr(format, '%');
		return ;
	}
	spec->type = *type;
	spec->ln_search = type - ft_strchr(format, '%');
	str_search = ft_strsub(format, spec->ln_text, spec->ln_search);
	ft_search_1(str_search, spec);
	if (!(ft_strchr(SPEC, spec->type)))
		ft_not_valid_type(spec->type, spec);
}
