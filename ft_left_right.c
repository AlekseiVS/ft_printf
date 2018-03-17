/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:46:07 by osokoliu          #+#    #+#             */
/*   Updated: 2018/03/17 12:49:06 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_left(char *s, int width, int precision, char c)
{
	char	*snew;
	int		i;

	i = 0;
	snew = ft_strnew(width);
	while (i < width)
	{
		if (i < precision)
			snew[i] = s[i];
		else
			snew[i] = c;
		i++;
	}
	return (snew);
}

char	*ft_right(char *s, int width, int precision, char c)
{
	char	*snew;
	int		i;
	int		j;
	int		ln_c;

	i = 0;
	j = 0;
	ln_c = width - precision;
	snew = ft_strnew(width);
	while (i < width)
	{
		if (i < ln_c)
			snew[i] = c;
		else
			snew[i] = s[j++];
		i++;
	}
	return (snew);
}
