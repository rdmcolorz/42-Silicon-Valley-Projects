/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:41:47 by tyang             #+#    #+#             */
/*   Updated: 2017/12/02 19:46:24 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *cpys;

	cpys = (char *)s;
	while (*s)
	{
		if (*s != c)
		{
			cpys++;
			s++;
		}
		else
			return (cpys);
	}
	if (*s == c)
		return (cpys);
	return (NULL);
}
