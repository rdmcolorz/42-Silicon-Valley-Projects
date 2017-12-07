/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:35:00 by tyang             #+#    #+#             */
/*   Updated: 2017/12/06 10:49:01 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*cpy_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nmblen(n, 10);
	if (!(cpy_n = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cpy_n[len] = '\0';
	if (n == 0)
		cpy_n[0] = '0';
	if (n < 0)
		cpy_n[0] = '-';
	while (n != 0)
	{
		if (n < 0)
			n *= -1;
		cpy_n[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (cpy_n);
}
