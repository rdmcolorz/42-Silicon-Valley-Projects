/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:46:03 by tyang             #+#    #+#             */
/*   Updated: 2017/12/08 15:21:26 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	while (lst != NULL)
	{
		new_list = (t_list*)malloc(sizeof(t_list));
		new_list = f(lst);
		lst = lst->next;
		new_list = new_list->next;
	}
	new_list->next = NULL;
	return (new_list);
}
