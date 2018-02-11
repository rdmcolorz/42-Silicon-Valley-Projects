/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:50:42 by tyang             #+#    #+#             */
/*   Updated: 2018/02/10 22:41:56 by tyang            ###   ########.fr       */
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
	int half_wall;
	int	sky;
	int	ground;
	int	max;

	max = W_Y;
	half_wall = len / 2;
	sky = max / 2 - half_wall;
	ground = sky;
	while (max > 0)
	{
		if (sky-- > 0)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, 600 - x, max, 0x884b4b);
		else if (len-- > 0)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, 600 - x, max, 0xeeeeee);
		else if (ground-- > 0)
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, 600 - x, max, 0x0080ff);
		max--;
	}
}
