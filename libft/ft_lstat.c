/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:52:03 by tyang             #+#    #+#             */
/*   Updated: 2017/12/08 15:58:52 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#incldue "libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*temp;

	temp = begin_list;
	while (i <= nbr && begin_list != NULL)
	{
		temp = begin_list->next;
		begin_list = temp;
		i++;
	}
	return (temp);
}
