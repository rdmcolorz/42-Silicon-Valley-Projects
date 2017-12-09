/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:56:16 by tyang             #+#    #+#             */
/*   Updated: 2017/11/07 20:20:14 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	*rt;
	int i;

	i = 0;
	rt = (int*)malloc(sizeof(*rt) * length);
	while (i < length)
	{
		rt[i] = f(tab[i]);
		i++;
	}
	return (rt);
}
