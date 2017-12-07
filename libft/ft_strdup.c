/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:40:23 by tyang             #+#    #+#             */
/*   Updated: 2017/12/02 17:36:58 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*cpy_str;
	size_t	len;

	len = ft_strlen(str);
	cpy_str = (char*)malloc(sizeof(char) * (len + 1));
	if (cpy_str == (NULL))
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy_str[i] = str[i];
		i++;
	}
	cpy_str[i] = '\0';
	return (cpy_str);
}
