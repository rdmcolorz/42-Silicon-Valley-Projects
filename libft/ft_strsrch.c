/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:01:49 by tyang             #+#    #+#             */
/*   Updated: 2017/12/03 15:37:44 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsrch(const char *book, const char *word)
{
	int i;
	int j;

	i = 0;
	while (book[i])
	{
		while (word[i] == book[i])
			i++;
		return (1);
	}
	return (0);
}
