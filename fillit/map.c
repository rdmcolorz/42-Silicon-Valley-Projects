/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:33:47 by tyang             #+#    #+#             */
/*   Updated: 2018/01/01 20:07:54 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
**	relocates the cordinates of hashes to the top left,
*/

void	set_topleft(t_tetris *tetris)
{
	int i;
	int x_min;
	int y_min;

	i = 0;
	x_min = 100;
	y_min = 100;
	while (i < 4)
	{
		if (tetris->pos[i][0] < x_min)
			x_min = tetris->pos[i][0];
		if (tetris->pos[i][1] < y_min)
			y_min = tetris->pos[i][1];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetris->pos[i][0] = tetris->pos[i][0] - x_min;
		tetris->pos[i][1] = tetris->pos[i][1] - y_min;
		i++;
	}
}

/*
**	mallocs the map from the sqrt of the amount of hashes there are
**	so to calculate the smallest possible square at the start
*/

t_map	*make_map(int side)
{
	int		i;
	t_map	*new;

	i = 0;
	new = (t_map*)ft_memalloc(sizeof(t_map));
	new->side = side;
	new->map = (char**)ft_memalloc(sizeof(char*) * side);
	while (i < side)
	{
		new->map[i] = (char*)ft_memalloc(sizeof(char) * side + 1);
		ft_memset(new->map[i], '.', sizeof(char) * side);
		new->map[i][side] = '\0';
		i++;
	}
	return (new);
}

/*
**	prints out the map onto the screen.
*/

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->side)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		decide_spot(t_map *map, t_tetris *tetris)
{
	int i;

	i = 0;
	while (map->map[tetris->pos[i][1]][tetris->pos[i][0]] == '.')
	{
		i++;
		if (i == 4)
			return (1);
	}
	return (0);
}

/*
**	sets a piece in place, if not able to place it a piece
**	return (0), otherwise return (1);
**	failed!!! because I had to check all positions before going to the next
**	piece.
**
**int		decide_spot(t_map *map, t_tetris *tetris)
**{
**	int i;
**	int y_counter;
**	int x_counter;
**
**	i = 0;
**	y_counter = 0;
**	while (y_counter < map->side - tetris->x_max)
**	{
**		x_counter = 0;
**		while (x_counter < map->side - tetris->x_max)
**		{
**			while (map->map[tetris->pos[i][1]][tetris->pos[i][0]] == '.')
**			{
**				i++;
**				if (i == 4)
**					return (1);
**			}
**			i = 0;
**			x_move_tetris(tetris, 1);
**			x_counter++;
**		}
**		i = 0;
**		x_move_tetris(tetris, -x_counter);
**		y_move_tetris(tetris, 1);
**		y_counter++;
**	}
**	return (0);
**}
*/
