/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:25:22 by tyang             #+#    #+#             */
/*   Updated: 2018/01/14 15:27:21 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *head)
{
	if (head == NULL)
	{
		ft_putendl("The head is pointing to NULL YOU DUMB FUCKER!");
		return ;
	}
	ft_putendl("--HEAD--");
	while (head != NULL)
	{
		ft_putendl(head->content);
		head = head->next;
	}
	ft_putendl("--NULL--");
}
