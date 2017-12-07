/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:02:40 by tyang             #+#    #+#             */
/*   Updated: 2017/12/04 11:48:58 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy_str;
	int		i;

	i = 0;
	if (s != NULL)
	{
		cpy_str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (cpy_str == NULL)
			return (NULL);
		while (s[i])
		{
			cpy_str[i] = f(s[i]);
			i++;
		}
		cpy_str[i] = '\0';
		return (cpy_str);
	}
	return (NULL);
}
