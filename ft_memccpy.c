/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:05:35 by tyang             #+#    #+#             */
/*   Updated: 2017/12/03 21:47:41 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*cpysrc;
	char	*cpydest;

	cpysrc = (char*)s2;
	cpydest = (char*)s1;
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
