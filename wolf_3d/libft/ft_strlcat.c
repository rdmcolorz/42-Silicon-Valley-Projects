/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:31:44 by tyang             #+#    #+#             */
/*   Updated: 2017/12/10 16:24:35 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*cpy_d;
	char	*cpy_s;
	size_t	n;
	size_t	cpy_dlen;

	cpy_d = (char *)dest;
	cpy_s = (char *)src;
	n = size;
	while (n-- && *cpy_d)
		cpy_d++;
	cpy_dlen = cpy_d - dest;
	n = size - cpy_dlen;
	if (n == 0)
		return (cpy_dlen + ft_strlen(cpy_s));
	while (*cpy_s)
	{
		if (n != 1)
		{
			*cpy_d++ = *cpy_s;
			n--;
		}
		cpy_s++;
	}
	*cpy_d = '\0';
	return (cpy_dlen + (cpy_s - src));
}
