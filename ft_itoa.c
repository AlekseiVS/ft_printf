/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:04:45 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/05 17:42:48 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t		len_n(intmax_t n)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(intmax_t n)
{
	intmax_t		len;
	intmax_t		c;
	char			*str;
	

	len = len_n(n);
	c = n;
	// if (n == -2147483648)
	// 	return (ft_strdup("-2147483648"));
	n = ABS(n);
	str = ft_strnew(len);
	if (!str)
		return (0);
	while (len)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (c < 0)
		str[0] = '-';
	return (str);
}
