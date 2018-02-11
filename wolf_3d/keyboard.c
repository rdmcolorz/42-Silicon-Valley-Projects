/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:44:50 by tyang             #+#    #+#             */
/*   Updated: 2018/02/11 15:25:26 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		return (exit_game(game));
	return (0);
}

int		movement(int key, t_game *game)
{
	if (key == KEY_UP || key == KEY_DOWN)
		return (up_down(key, game));
	if (key == KEY_RIGHT || key == KEY_LEFT)
		return (left_right(key, game));
	return (0);
}

int		up_down(int key, t_game *game)
{
	int	x;

	x = -1;
	if (game->ypos >= 180 && key == KEY_UP)
	{
		game->ypos -= 10;
		while (++x <= W_X)
			get_cord_on_grid(game, x);
		return (0);
	}
	if (game->ypos <= 1020 && key == KEY_DOWN)
	{
		game->ypos += 10;
		while (++x <= W_X)
			get_cord_on_grid(game, x);
		return (0);
	}
	return (0);
}

int		left_right(int key, t_game *game)
{
	int	x;

	x = -1;
	if (game->xpos <= 1020 && key == KEY_RIGHT)
	{
		game->xpos += 10;
		while (++x <= W_X)
			get_cord_on_grid(game, x);
		return (0);
	}
	if (game->xpos >= 180 && key == KEY_LEFT)
	{
		game->xpos -= 10;
		while (++x <= W_X)
			get_cord_on_grid(game, x);
		return (0);
	}
	return (0);
}


int		exit_game(t_game *game)
{
	int i;

	i = 0;
	free(game->mlx_ptr);
	free(game->win_ptr);
	while (game->maze[i])
	{
		free(game->maze[i]);
		i++;
	}
	exit(0);
	return (0);
}
