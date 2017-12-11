/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:13:45 by tyang             #+#    #+#             */
/*   Updated: 2017/12/02 18:26:51 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (i < len)
	{
		if (src[i] && end == 0)
			dest[i] = src[i];
		else
		{
			end = 1;
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}
