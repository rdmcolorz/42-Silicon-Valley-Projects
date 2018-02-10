/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:35:02 by tyang             #+#    #+#             */
/*   Updated: 2017/12/06 11:46:22 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy_s;
	int		i;
	int		temp;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (ft_isblanks(s[i]) == 1 && i < len)
		i++;
	while (ft_isblanks(s[len - 1]) == 1 && i < len)
		len--;
	cpy_s = (char *)malloc(sizeof(char) * (len - i + 1));
	if (cpy_s == NULL)
		return (NULL);
	temp = 0;
	while (s[i] && i < len)
	{
		cpy_s[temp] = s[i];
		i++;
		temp++;
	}
	cpy_s[temp] = '\0';
	return (cpy_s);
}
