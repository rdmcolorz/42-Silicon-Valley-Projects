/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:54:55 by tyang             #+#    #+#             */
/*   Updated: 2018/01/14 19:47:20 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Deletes the node if the referenced key is in the node,
**	relinks the list. Can be used for different references.
**	First searches from the head node to see if it is the same as the
**	reference, because you would have to relocate the head if that happens.
**	If the first node is not same as reference, then we have to keep track
**	of the previous node, so we can point the prev->next to curr->next when
**	we delete the node.
*/

void	ft_lstdelkey(t_list **head, void *key)
{
	t_list *curr;
	t_list *prev;

	curr = *head;
	while (curr != NULL && curr->content == key)
	{
		*head = curr->next;
		free(curr);
		curr = *head;
	}
	while (curr != NULL)
	{
		while (curr != NULL && curr->content != key)
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr == NULL)
			return ;
		prev->next = curr->next;
		free(curr);
		curr = prev->next;
	}
}
