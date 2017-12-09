/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:23:52 by tyang             #+#    #+#             */
/*   Updated: 2017/12/08 11:18:50 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *next;

	if (!*alst || !*del)
		return ;
	temp = *alst;
	while (temp != NULL)
	{
		next = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp = next;
	}
	*alst = NULL;
	return ;
}
