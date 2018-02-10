/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:44:50 by tyang             #+#    #+#             */
/*   Updated: 2018/02/09 09:44:48 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		init_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		return (exit_game(game));
	if (key == KEY_UP)
		return (press_draw(game));
	if (key == KEY_DOWN)
		return (0);
	if (key == KEY_RIGHT)
		return (0);
	if (key == KEY_LEFT)
		return (0);
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

int		press_draw(t_game *game)
{
	int i;

	i = 400;
	ft_putendl("here");
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, 400, i, 0xFFFFFF);
	return (0);
}
