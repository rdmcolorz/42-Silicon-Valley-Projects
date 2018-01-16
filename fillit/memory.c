/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:26:02 by tyang             #+#    #+#             */
/*   Updated: 2018/01/01 19:55:07 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*free_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*temp;

	while (list != NULL)
	{
		tetris = (t_tetris*)list->content;
		temp = list->next;
		ft_memdel((void**)(&tetris));
		ft_memdel((void**)&list);
		list = temp;
	}
	return (NULL);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->side)
	{
		ft_memdel((void**)(&(map->map[i])));
		i++;
	}
	ft_memdel((void**)(&(map->map)));
	ft_memdel((void**)&map);
}
