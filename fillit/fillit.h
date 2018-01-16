/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:17:50 by tyang             #+#    #+#             */
/*   Updated: 2018/01/08 14:57:10 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

/*
** The struct where we keep our linked list of block of tetriminos
** the box is 4 x 4 but since we need to check if the last row that
** contains a \n, we need a extra row for that.
*/

typedef struct		s_tetris
{
	char			board[4][4];
	int				pos[4][2];
	int				x_max;
	int				y_max;
	int				x_curr;
	int				y_curr;
	char			label;
	int				set;
}					t_tetris;

typedef struct		s_map
{
	char			**map;
	int				side;
}					t_map;

/*
**	read.c vvvvv
*/
int					check_block(char *str);
int					check_links(char *str);
void				get_tetris(t_tetris *tetris, char *str, char label);
t_list				*read_file(t_list *list, char *src, int fd);
void				get_hash_position(t_tetris *tetris);
/*
**	map.c vvvvv
*/
void				set_topleft(t_tetris *tetris);
t_map				*make_map(int size);
void				print_map(t_map *map);
int					decide_spot(t_map *map, t_tetris *tetris);

/*
**	move_map.c vvvvv
*/

void				move_tetris(t_tetris *tetris, int x,int y);
void				remove_off_map(t_tetris *tetris, t_map *map);
void				place_on_map(t_tetris *tetris, t_map *map);

/*
**	solve.c vvvvv
*/

int					solve_curr_map(t_map *map, t_list *list, int x, int y);
t_map				*solve_all_maps(t_list *list);

/*
**	helper.c vvvvv
*/

int					ft_sqrt(int nb);
void				find_xy_max(t_tetris *tetris);
void				ft_lstrev(t_list **alst);
int					ft_lstcount(t_list *list);

/*
**	memory.c vvvvv
*/

t_list				*free_list(t_list *list);
void				free_map(t_map *map);

#endif
