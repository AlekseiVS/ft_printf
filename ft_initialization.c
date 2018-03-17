/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:36:14 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 12:36:59 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialization(t_spec *spec)
{
	spec->plus = 0;
	spec->minus = 0;
	spec->space = 0;
	spec->hesh = 0;
	spec->zero = 0;
	spec->width = -1;
	spec->precision = -1;
	spec->size = -1;
	spec->type = 0;
	spec->ln_search = 0;
	spec->ln_text = 0;
	spec->tmp = 0;
}
