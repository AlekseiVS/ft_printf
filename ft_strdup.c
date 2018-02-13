/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:30:39 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 17:55:29 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		ln;
	char	*dst;

	ln = 0;
	while (str[ln] != '\0')
		ln++;
	dst = (char*)malloc(sizeof(char) * (ln + 1));
	if (dst != '\0')
	{
		ln = 0;
		while (str[ln] != '\0')
		{
			dst[ln] = str[ln];
			ln++;
		}
		dst[ln] = '\0';
	}
	return (dst);
}
