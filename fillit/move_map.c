/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:31:53 by tyang             #+#    #+#             */
/*   Updated: 2018/01/08 14:58:10 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Moves entire tetris piece x axis + 1;
*/

void	move_tetris(t_tetris *tetris, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tetris->pos[i][0] += x;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetris->pos[i][1] += y;
		i++;
	}
}

/*
**	Places the label of the piece and position into the map.
*/

void	place_on_map(t_tetris *tetris, t_map *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 4)
	{
		x = tetris->pos[i][0];
		y = tetris->pos[i][1];
		map->map[y][x] = tetris->label;
		i++;
	}
	tetris->set = 1;
}

/*
**	Remove the label and position of the peice off the map.
*/

void	remove_off_map(t_tetris *tetris, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->side)
	{
		x = 0;
		while (x < map->side)
		{
			if (map->map[y][x] == tetris->label)
				map->map[y][x] = '.';
			x++;
		}
		y++;
	}
	tetris->set = 0;
}
