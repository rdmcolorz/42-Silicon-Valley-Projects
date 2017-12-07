/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:13:54 by tyang             #+#    #+#             */
/*   Updated: 2017/12/04 11:49:52 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cpy_str;

	i = 0;
	if (s != NULL)
	{
		cpy_str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (cpy_str == NULL)
			return (NULL);
		while (s[i])
		{
			cpy_str[i] = f(i, s[i]);
			i++;
		}
		cpy_str[i] = '\0';
		return (cpy_str);
	}
	return (NULL);
}
