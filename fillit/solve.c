/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:50:50 by tyang             #+#    #+#             */
/*   Updated: 2018/01/08 14:58:12 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
**	try to place all tetriminos in current map size
**	recursively go through all possibilities.
*/

int		solve_curr_map(t_map *map, t_list *list, int x, int y)
{
	t_tetris	*tetris;

	if (list == NULL)
		return (1);
	y = -1;
	tetris = (t_tetris*)(list->content);
	set_topleft(tetris);
	while (++y < map->side - tetris->y_max + 1)
	{
		x = -1;
		while (++x < map->side - tetris->x_max + 1)
		{
			if (decide_spot(map, tetris) == 1)
			{
				place_on_map(tetris, map);
				if (solve_curr_map(map, list->next, x, y) == 1)
					return (1);
				else
					remove_off_map(tetris, map);
			}
			move_tetris(tetris, 1, 0);
		}
		move_tetris(tetris, -x, 1);
	}
	return (0);
}

/*
**	if can't solve with current map size, increment size by 1,
**	and try again.
*/

t_map	*solve_all_maps(t_list *list)
{
	int			size;
	t_map		*map;
	t_list		*start;
	int			x;
	int			y;

	x = 0;
	y = 0;
	start = list;
	size = ft_sqrt(ft_lstcount(list) * 4);
	map = make_map(size);
	while (solve_curr_map(map, list, x, y) == 0)
	{
		size++;
		free_map(map);
		map = make_map(size);
	}
	return (map);
}

/*
**int		solve_curr_map(t_map *map, t_list *list, t_list *start)
**{
**	t_tetris	*tetris;
**	int			flag;
**
**	flag = 0;
**	if (check_solved(start) == 1)
**		return (1);
**		while (list != NULL)
**		{
**			tetris = (t_tetris*)(list->content);
**			if (tetris->set == 0)
**			{
**				if (decide_spot(map, tetris) == 1)
**				{
**					place_on_map(tetris, map);
**					if (solve_curr_map(map, list->next, start) == 1)
**						return (1);
**					else
**						remove_off_map(tetris, map);
**				}
**				set_topleft(tetris);
**			}
**			list = list->next;
**			if (list == NULL && flag == 0)
**			{
**				list = start;
**				flag = 1;
**			}
**		}
**		return (0);
**
**void	reset_map(t_map *map)
**{
**	int i;
**
**	i = 0;
**	while (i < map->side)
**	{
**		ft_memset(map->map[i], '.', sizeof(char) * map->side);
**		i++;
**	}
**}
**
**t_list	*find_not_set(t_list *list)
**{
**	t_tetris *tetris;
**
**	tetris = list->content;
**	while (list != NULL)
**	{
**		tetris = list->content;
**		if (tetris->set == 0)
**			return (list);
**		list = list->next;
**	}
**	return (list);
**}
**
**int		check_solved(t_list *list)
**{
**	t_tetris *tetris;
**
**	while (list != NULL)
**	{
**		tetris = (t_tetris*)list->content;
**		if (tetris->set == 0 || tetris->set == 2)
**			return (0);
**		list = list->next;
**	}
**	return (1);
**}
*/
