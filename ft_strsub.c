/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:56:28 by tyang             #+#    #+#             */
/*   Updated: 2017/12/06 16:14:09 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy_s;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		cpy_s = (char*)malloc(sizeof(char) * (len + 1));
		if (cpy_s == NULL)
			return (NULL);
		while (s[i] && i < len)
		{
			cpy_s[i] = s[start + i];
			i++;
		}
		cpy_s[i] = '\0';
		return (cpy_s);
	}
	return (NULL);
}
