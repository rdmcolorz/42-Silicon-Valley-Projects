/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:00:07 by tyang             #+#    #+#             */
/*   Updated: 2018/02/08 21:22:20 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_maze(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putendl(str[i]);
		i++;
	}
}

#include <stdio.h>
void	print_game(t_game *game)
{	
	int i;

	i = 0;
	printf("opdist %f\n",game->o_p_dist);
	printf("xplane %f\n",game->xwin);
	printf("yplane %f\n",game->ywin);
	printf("xpos %f\n",game->xpos);
	printf("ypos %f\n",game->ypos);
	printf("xdir %f\n",game->xdir);
	printf("ydir %f\n",game->ydir);
	while (game->maze[i])
	{
		ft_putendl(game->maze[i]);
		i++;
	}
}

