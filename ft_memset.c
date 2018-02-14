/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:16:52 by osokoliu          #+#    #+#             */
/*   Updated: 2017/12/03 20:11:41 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		src[i] = c;
		i++;
	}
	return ((void*)src);
}
