/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:56:33 by tyang             #+#    #+#             */
/*   Updated: 2017/12/08 19:21:25 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cpys;
	int		n;

	cpys = (char*)s;
	n = ft_strlen(cpys);
	cpys = cpys + n;
	while (n >= 0)
	{
		if (s[n] != c)
		{
			n--;
			cpys--;
		}
		else
			return (cpys);
	}
	return (NULL);
}
