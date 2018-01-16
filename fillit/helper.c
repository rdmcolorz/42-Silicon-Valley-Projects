/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:57:01 by tyang             #+#    #+#             */
/*   Updated: 2018/01/01 14:11:59 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_sqrt(int nb)
{
	int answer;

	answer = 1;
	if (nb == 1 || nb == 0)
		return (nb);
	while (answer * answer <= nb)
	{
		if (answer * answer == nb)
			return (answer);
		answer++;
	}
	return (answer);
}

void	find_xy_max(t_tetris *tetris)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 4)
	{
		if (tetris->pos[i][0] > x)
			x = tetris->pos[i][0];
		if (tetris->pos[i][1] > y)
			y = tetris->pos[i][1];
		i++;
	}
	tetris->x_max = x + 1;
	tetris->y_max = y + 1;
}

void	ft_lstrev(t_list **alst)
{
	t_list *curr;
	t_list *prev;
	t_list *next;

	prev = NULL;
	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*alst = prev;
}

int		ft_lstcount(t_list *list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
