/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:42:11 by tyang             #+#    #+#             */
/*   Updated: 2018/02/11 15:37:27 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_game	*initialize_game(void)
{
	t_game *new;

	new = (t_game*)ft_memalloc(sizeof(t_game));
	new->o_p_dist = 520;
	new->xtemp = 0;
	new->ytemp = 0;
	new->slope = 0;
	new->b = 0;
	new->xpos = 0;
	new->ypos = 0;
	new->xwin = 0;
	new->ywin = 0;
	new->xdir = -1;
	new->ydir = 0;
	new->mlx_ptr = 0;
	new->win_ptr = 0;
	new->maze = 0;
	return (new);
}

int		main(void)
{
	t_game	*game;
	int		x;

	game = initialize_game();
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, W_X, W_Y, "Wolf3d_tyang");
	if ((game = make_map_arr(read_maze(), game)) == NULL)
	{
		ft_putendl_fd(">>>>> Invalid Map (Invalid symbols) <<<<<", 2);
		return (0);
	}
	x = -1;
	while (++x <= W_X)
		get_cord_on_grid(game, x);
	mlx_hook(game->win_ptr, 2, 0, movement, game);
	mlx_key_hook(game->win_ptr, init_press, game);
	mlx_hook(game->win_ptr, 17, 0, exit_hook, game);
	mlx_loop(game->mlx_ptr);
}
