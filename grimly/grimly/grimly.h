/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:03:28 by tyang             #+#    #+#             */
/*   Updated: 2018/01/15 21:42:46 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# define IS_DIGIT(x) (x >= '0' && x <= '9')
# include "libft.h"
# include <fcntl.h>


typedef struct		s_maze
{
	int				rows_nb;
	int				cols_nb;
	char			wall;
	char			empty;
	char			path;
	char			start;
	char			exit;
	char			**maze;
	char			start_pos;
	char			*exits_pos;
}					t_maze;

/*
**	read.c
*/

char	*read_file(char *src, t_maze *maze);
t_maze	*get_info(char *str, t_maze *maze);
t_maze	*get_nb(t_maze *maze, char *str, int len);
int		is_diff_char(char *str, int len);
int		is_row_col(char *str, int len);

#endif
