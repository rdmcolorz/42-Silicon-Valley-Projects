/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 21:11:59 by tyang             #+#    #+#             */
/*   Updated: 2018/02/11 15:21:44 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	give pixel cordinates as argument to get distance between the wall pixel
**	and the camera pos.
*/

float		get_distance(t_game *game, float xpix, float ypix)
{
	float	xdist;
	float	ydist;

	xdist = fabs(xpix - game->xpos);
	ydist = fabs(ypix - game->ypos);
	return (hypot(xdist, ydist));
}

/*
**	input the cordinates intercets with ray and grid line, and check
**	if that dot is on a wall.
*/

int			check_wall(t_game *game, float xpix, float ypix)
{
	int	x;
	int	y;

	if (xpix == 0 || ypix == 0)
		return (0);
	x = (int)xpix / 120;
	y = (int)ypix / 120;
	if ((int)ypix % CUBE_HL == 0)
	{
		if (game->ypos < ypix)
			return (game->maze[y][x] == '1' ? 1 : 0);
		else
			return (game->maze[y - 1][x] == '1' ? 1 : 0);
	}
	else if ((int)xpix % CUBE_HL == 0)
	{
		if (game->xpos > xpix)
			return (game->maze[y][x - 1] == '1' ? 1 : 0);
		else
			return (game->maze[y][x] == '1' ? 1 : 0);
	}
	return (2);
}

/*
**	get the slope by y = mx + b,
*/

void		draw_wall(t_game *game, int x)
{
	float	hypot;
	float	adjecent;
	int		wall_len;

	hypot = get_distance(game, game->xtemp, game->ytemp);
	adjecent = fabs(cos((30 - (x / 10)) * PI / 180) * hypot);
	wall_len = (int)(CUBE_HL / adjecent * game->o_p_dist);
	draw_vertical_line(game, wall_len, x);
	game->xtemp = 0;
	game->ytemp = 0;
}

char		get_cross(t_game *game, int vcount, int hcount, int x)
{
	float	xv;
	float	yv;
	float	xh;
	float	yh;

	if (x <= 300)
		xv = game->xpos + (120 - ((int)game->xpos % 120)) + vcount;
	else
		xv = game->xpos - ((int)game->xpos % 120) + vcount;
	yv = (xv * game->slope) + game->b;
	yh = game->ypos - ((int)game->ypos % 120) + hcount;
	xh = (yh - game->b) / game->slope;
	if (get_distance(game, xv, yv) < get_distance(game, xh, yh))
	{
		game->xtemp = xv;
		game->ytemp = yv;
		return ('v');
	}
	game->xtemp = xh;
	game->ytemp = yh;
	return ('h');
}

t_game		*get_cord_on_grid(t_game *game, int x)
{
	int		vcount;
	int		hcount;

	vcount = 0;
	hcount = 0;
	game->xwin = ((game->xpos + W_X / 2) - x);
	game->ywin = (game->ypos - game->o_p_dist);
	game->slope = (game->ywin - game->ypos) / (game->xwin - game->xpos);
	if (game->slope == -INFINITY)
		game->slope = -1000;
	game->b = game->ywin - (game->xwin * game->slope);
	while (check_wall(game, game->xtemp, game->ytemp) != 1)
	{
		if (get_cross(game, vcount, hcount, x) == 'v')
		{
			if (x <= 300)
				vcount += 120;
			else
				vcount -= 120;
		}
		else
			hcount -= 120;
	}
	printf("xpos %f ypos %f\n", game->xpos, game->ypos);
	draw_wall(game, x);
	return (game);
}
