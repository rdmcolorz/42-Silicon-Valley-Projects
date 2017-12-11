/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:58:00 by tyang             #+#    #+#             */
/*   Updated: 2017/11/30 15:24:20 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *cpys1;
	const unsigned char *cpys2;

	cpys1 = (unsigned char*)s1;
	cpys2 = (unsigned char*)s2;
	if (cpys1 == cpys2 || n == 0)
		return (0);
	while (n--)
	{
		if (*cpys1 != *cpys2)
			return (*cpys1 - *cpys2);
		else
		{
			cpys1++;
			cpys2++;
		}
	}
	return (0);
}
