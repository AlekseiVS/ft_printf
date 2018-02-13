/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osokoliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:05:13 by osokoliu          #+#    #+#             */
/*   Updated: 2017/11/29 19:39:46 by osokoliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	char *buff;

	buff = (char*)malloc(sizeof(char) * size);
	if (buff)
		ft_bzero(buff, size);
	return (buff);
}
