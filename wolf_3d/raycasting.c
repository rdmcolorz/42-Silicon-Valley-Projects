/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 21:11:59 by tyang             #+#    #+#             */
/*   Updated: 2018/02/09 22:54:22 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	give pixel cordinates as argument to get distance between the wall pixel
**	and the camera pos.
*/

float	get_distance(t_game *game, float xpix, float ypix)
{
	float	xdist;
	float	ydist;

	xdist = fabs(xpix - game->xpos);
	ydist = fabs(ypix - game->ypos);
	printf("xdist %f ydist %f\n",xdist, ydist);
	return (hypot(xdist, ydist));
}

/*
**	input the cordinates intercets with ray and grid line, and check
**	if that dot is on a wall.
*/

int		check_wall(t_game *game, float xpix, float ypix)
{
	int	x;
	int	y;

	x = (int)xpix / 120;
	y = (int)ypix / 120;
	printf("x %i, y %i\n",x,y);
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
	printf("xtemp %f ytemp %f hypot %f\n",game->xtemp, game->ytemp,hypot);
	adjecent = fabs(cos((30 - (x / 10)) * PI / 180) * hypot);
	wall_len = (int)(CUBE_HL / adjecent * game->o_p_dist);
	//printf("x : %d hypot %f  adjecent %f  wall len %d\n",x,hypot, adjecent, wall_len);
	draw_vertical_line(game, wall_len, x);
}

t_game		*get_cord_on_grid(t_game *game, int x)
{
	float	slope;
	float	b;
	int		xnext;
	int		ynext;

	game->xwin = ((game->xpos + W_X / 2) - x);
	game->ywin = (game->ypos - game->o_p_dist);
	slope = (game->ywin - game->ypos) / (game->xwin - game->xpos);
	b = game->ywin - (game->xwin * slope);
	game->xtemp = game->xpos - (int)game->xpos % 120;
	game->ytemp = game->ypos - (int)game->ypos % 120;
	xnext = 0;
	ynext = 0;
	while ()
	while (check_wall(game, game->xtemp, game->ytemp) == 0
			&& game->xtemp <= 1200 && game->ytemp <= 1200)
	{
		ft_putendl("going to while loop");
		if ((int)game->xtemp % CUBE_HL > (int)game->ytemp % CUBE_HL)
		{
			game->xtemp = game->xpos - ((int)game->xpos % CUBE_HL) + xnext;
			game->ytemp = game->xtemp * slope + b;
			xnext =+ CUBE_HL;
		}
		else
		{
			game->ytemp = game->ypos - ((int)game->ypos % CUBE_HL) + ynext;
			game->xtemp = (game->ytemp - b) / slope;
			ynext += CUBE_HL;
		}
		printf("xtemp : %f ytemp : %f\n",game->xtemp, game->ytemp);
	}
	ft_putendl("got wall");
	draw_wall(game, x);
	game->xtemp = 0;
	game->ytemp = 0;
	return (game);
}

/*
int		cast_ray(t_game *game)
{
	int i;
	int	len;
	int	xcross;
	int ycross;

	i = 0;
	while (i < W_X)
	{
		xcross = game->xpos - (game->xpos % CUBE_HL);
		ycorss = game->ypos + (game->ypos % CUBE_HL);
		if (game->xpos % CUBE_HL == 0 || game->ypos % CUBE_HL == 0)
		{
			if (check_wall(game, game->xpos, game->ypos))
				
		draw_vertical_line(game, len, i);
	}
}
*/
