/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:03:17 by tyang             #+#    #+#             */
/*   Updated: 2017/12/04 19:44:25 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *book, const char *word)
{
	int i;
	int len;
	int pos;

	i = 0;
	len = ft_strlen(word);
	if (len == 0)
		return ((char*)book);
	while (book[i])
	{
		pos = 0;
		while (word[pos] == book[i + pos])
		{
			if (pos == (len - 1))
				return ((char*)book + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
