/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:38:23 by tyang             #+#    #+#             */
/*   Updated: 2017/12/03 17:38:49 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *book, const char *word, size_t len)
{
	size_t i;
	size_t word_len;
	size_t pos;

	i = 0;
	word_len = ft_strlen(word);
	if (word_len == 0)
		return ((char*)book);
	while (book[i] && word_len + i <= len)
	{
		pos = 0;
		while (word[pos] == book[i + pos])
		{
			if (pos == (word_len - 1))
				return ((char*)book + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
