/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:04:07 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 19:34:38 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buff;
	char *buff_start;

	if (s == NULL)
		return (NULL);
	s = s + start;
	buff = ft_strnew(len);
	if (buff)
	{
		buff_start = buff;
		while (len > 0)
		{
			*buff++ = *s++;
			len--;
		}
		return (buff_start);
	}
	return (NULL);
}
