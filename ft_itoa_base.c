/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:42:14 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 12:44:45 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t		len_n(uintmax_t n, int base)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(uintmax_t n, int base)
{
	int				len;
	char			*str;

	len = len_n(n, base);
	str = ft_strnew(len);
	if (!str)
		return (0);
	while (len)
	{
		if (n % base >= 10)
			str[len - 1] = (n % base - 10) + 'a';
		else
			str[len - 1] = (n % base) + '0';
		n = n / base;
		len--;
	}
	return (str);
}
