/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:47:12 by tyang             #+#    #+#             */
/*   Updated: 2017/12/06 12:49:09 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**counts the number of words separated by dilimeters
*/

static int		count_words(const char *str, char dili)
{
	int		size;
	int		flag;

	size = 0;
	flag = 0;
	while (*str)
	{
		if (*str == dili && flag == 1)
			flag = 0;
		else if (*str != dili && flag == 0)
		{
			size++;
			flag = 1;
		}
		str++;
	}
	return (size);
}

/*
**counts the word length, but the word has to start without the dilimeter
**but can end in a dilimeter or null terminator
*/

static size_t	word_len(const char *str, char dili)
{
	size_t	len;

	len = 0;
	while (*str != dili && *str)
	{
		len++;
		str++;
	}
	return (len);
}

/*
**splits string into a string array by dilimeters.
**allocate array memory by the number of elements inside,
**so we want a size of a pointer(8bytes) times the number of elements
**Then malloc memory for each string by using index.
*/

char			**ft_strsplit(char const *s, char c)
{
	char	**arr_s;
	int		w_cnt;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	w_cnt = count_words(s, c);
	arr_s = (char**)malloc(sizeof(*arr_s) * (w_cnt + 1));
	if (arr_s == NULL)
		return (NULL);
	while (w_cnt--)
	{
		while (*s == c && *s)
			s++;
		arr_s[i] = ft_strsub(s, 0, word_len(s, c));
		if (arr_s[i] == NULL)
			return (NULL);
		s += word_len(s, c);
		i++;
	}
	arr_s[i] = NULL;
	return (arr_s);
}
