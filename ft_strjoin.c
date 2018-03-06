/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:22:33 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 18:07:03 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *buff;
	char *buff_start;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	buff = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (buff)
	{
		buff_start = buff;
		while (*s1)
			*buff++ = *s1++;
		while (*s2)
			*buff++ = *s2++;
		return (buff_start);
	}
	return (NULL);
}
