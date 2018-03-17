/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:17:13 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 18:22:22 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_formation(va_list ap, t_spec spec)
{
	if (spec.type == 'c' && spec.size != 2)
		ft_print_c(va_arg(ap, int), &spec);
	else if (spec.type == 's' && spec.size != 2)
		spec.result += ft_print_s(va_arg(ap, char *), spec);
	else if (spec.type == 'd' || spec.type == 'i' || spec.type == 'D')
		spec.result += ft_print_d_i(ap, spec);
	else if (spec.type == 'u' || spec.type == 'U')
		spec.result += ft_print_u(ap, spec);
	else if (spec.type == 'o' || spec.type == 'O')
		spec.result += ft_print_o(ap, spec);
	else if (spec.type == 'x' || spec.type == 'X' || spec.type == 'p')
		spec.result += ft_print_x_p(ap, spec);
	else if (spec.type == 'C' || spec.type == 'S'
	|| (spec.size == 2 && (spec.type == 'c' || spec.type == 's')))
		spec.result += ft_print_c_s(ap, spec);
	return (spec.result);
}

int			ft_printf(char *format, ...)
{
	t_spec		spec;
	va_list		ap;

	va_start(ap, format);
	spec.result = 0;
	while (*format)
	{
		ft_initialization(&spec);
		ft_search(format, &spec);
		spec.result = ft_printf_formation(ap, spec);
		format += (spec.ln_search + 1) + spec.ln_text;
	}
	va_end(ap);
	return (spec.result);
}
