/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmxl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:16:21 by tyang             #+#    #+#             */
/*   Updated: 2018/02/05 14:56:30 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_dir(int key)
{
	ft_putstr("key pressed is: ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == KEY_RIGHT)
		ft_putendl(" <--");
	if (key == KEY_LEFT)
		ft_putendl(" -->");
	if (key == KEY_DOWN)
		ft_putendl(" vv");
	if (key == KEY_UP)
		ft_putendl(" ^^");
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int		deal_mouse(int key, int x, int y, t_mouse *mouse)
{
	//ft_putstr("mouse pressed is : ");
	//ft_putnbr(key);
	if(!key)
		return (0);
	ft_putstr("courdinates (x,y) : ");
	ft_putnbr(x);
	ft_putchar(',');
	ft_putnbr(y);
	ft_putchar('\n');
	if (x > 493 && x < 1058 && y > 422 && y < 471)
		mlx_clear_window(mouse->mlx_ptr, mouse->win_ptr);
	return (0);
}

t_mouse		*init_mouse()
{
	t_mouse *new;

	new = malloc(sizeof(t_mouse));
	new->mlx_ptr = 0;
	new->win_ptr = 0;
	return (new);
}


int		main()
{
	int		x;
	int		y;
	int		z;
	int 	fd;
	int		fd2;
	char	*line;
	static t_mouse	*mouse;

	z = 0;
		x = 0;
	y = 0;
	mouse = init_mouse();
	mouse->mlx_ptr = mlx_init();
	mouse->win_ptr = mlx_new_window(mouse->mlx_ptr, 1500, 500, "Wolf_3D");
	fd = open("textart.c", O_RDONLY);
	fd2 = open("start", O_RDONLY);
	while(get_next_line(fd, &line) != 0)
	{
		mlx_string_put(mouse->mlx_ptr, mouse->win_ptr, 130, z, 0xFFFFFF, line);
		z += 25;
	}
	while(get_next_line(fd2, &line) != 0)
	{
		mlx_string_put(mouse->mlx_ptr, mouse->win_ptr, 480, z + 100, 0xFFFFFF, line);
		z += 20;
	}
	mlx_mouse_hook(mouse->win_ptr, deal_mouse, mouse);
	mlx_key_hook(mouse->win_ptr, check_dir, mouse);
	mlx_loop(mouse->mlx_ptr);
}
