/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 21:27:47 by tyang             #+#    #+#             */
/*   Updated: 2018/02/15 21:50:41 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define BUFF_SIZE 4096
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_ESC 53
# define  W_X 600
# define W_Y 600
# define CUBE_HL 120
# define WALL_H 120
# define PI 3.14159265
# include "minilibx/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h> /////////////////////////
typedef struct	s_gnl
{
	int			fd;
	char		*store;
	char		*new_store;
}				t_gnl;

typedef struct	s_game
{
	float		o_p_dist;
	float		xwin;
	float		ywin;
	float		xtemp;
	float		ytemp;
	float		slope;
	float		b;
	int			maze_rows;
	int			maze_cols;
	float		xpos;
	float		ypos;
	float		xdir;
	float		ydir;
	char		**maze;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_game;


int				get_next_line(int fd, char **line);

/*
**	hooks.c
*/

int				init_press(int key, t_game *game);
int				exit_game(t_game *game);
int				exit_hook(t_game *game);
int				press_draw(t_game *game);

int				up_down(int key, t_game *game);
int				left_right(int key, t_game *game);
int				key_release_hook(int key, t_game *game);
int				movement(int key, t_game *game);
/*
**	readmap.c
*/

int				count_rows(char *str);
char			*read_maze(char *str);
t_game			*make_map_arr(char *str, t_game *game);
int				check_char(char *str);

/*
**	draw.c
*/

void			draw_horizontal_line(int x_s, int x_e, int y,  t_game *game);
void			draw_vertical_line(t_game *game, int len, int x);

/*
**	raycasting.c
*/

float			get_distance(t_game *game, float xpix, float ypix);
int				check_wall(t_game *game, float xpix, float ypix);
t_game			*get_cord_on_grid(t_game *game, int x);
char			get_cross(t_game *game, int vcount, int hcount, int x);

/*
**	debug.c
*/

void			print_maze(char **str);
void			print_game(t_game *game);
#endif
