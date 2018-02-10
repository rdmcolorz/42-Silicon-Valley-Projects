/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:04:43 by tyang             #+#    #+#             */
/*   Updated: 2017/12/04 14:06:40 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*c12;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		c12 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (c12 == NULL)
			return (NULL);
		while (s1[i])
		{
			c12[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			c12[i + j] = s2[j];
			j++;
		}
		c12[i + j] = '\0';
		return (c12);
	}
	return (NULL);
}
