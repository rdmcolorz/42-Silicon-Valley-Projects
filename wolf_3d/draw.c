/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:50:42 by tyang             #+#    #+#             */
/*   Updated: 2018/02/09 11:00:41 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_horizontal_line(int x_start, int x_end, int y, t_game *game)
{
	while (x_start < x_end)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x_start, y, 0xFFFFFF);
		x_start++;
	}
}

void	draw_vertical_line(t_game *game, int len, int x)
{
	int bottom;

	bottom = (W_Y / 2) - (len / 2);
	while (len > 0)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, bottom, 0xFFFFFF);
		bottom++;
		len--;
	}
}
