/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:05:35 by tyang             #+#    #+#             */
/*   Updated: 2017/12/09 10:57:04 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*cpysrc;
	char	*cpydest;

	if (!dest && !src && !n)
		return (NULL);
	cpysrc = (char*)src;
	cpydest = (char*)dest;
	while (n--)
	{
		*cpydest = *cpysrc;
		cpydest++;
		if (*cpysrc == (char)c)
			return ((void*)cpydest);
		cpysrc++;
	}
	return (NULL);
}
