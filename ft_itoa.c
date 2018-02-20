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

static	size_t		len_n(uintmax_t n, int c)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	if (c == 1)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(intmax_t n)
{
	int				len;
	int				c;
	char			*str;
	uintmax_t 		u_n;
	
	c = 0;
	if (n < 0)
		c = 1;
	u_n = ABS(n);
	len = len_n(u_n, c);
	str = ft_strnew(len);
	if (!str)
		return (0);
	while (len)
	{
		str[len - 1] = (u_n % 10) + '0';
		u_n = u_n / 10;
		len--;
	}
	if (c == 1)
		str[0] = '-';
	return (str);
}
