/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:49:13 by tyang             #+#    #+#             */
/*   Updated: 2018/01/15 13:37:34 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	opens file and reads it by putting the input into the linked list
**	lstnewtet creates a new node with nothing in it, then uses lstadd to
**	got through the while loop adding valid blocks.
**
**	kept getting segfault  where you have to declare a struct
**	piece rather than a pointer to the struct.
*/

t_list	*read_file(t_list *list, char *src, int fd)
{
	char		label;
	char		buf[22];
	t_tetris	tetris;
	int			ret;

	label = 'A';
	if ((fd = open(src, O_RDONLY)) != -1)
	{
		while ((ret = read(fd, buf, 21)) >= 20)
		{
			if (check_block(buf) == 1 && label <= 'Z')
			{
				buf[ret] = '\0';
				get_tetris(&tetris, buf, label);
				ft_lstadd(&list, ft_lstnew(&tetris, sizeof(tetris)));
				label++;
			}
			else
				return (list = free_list(list));
		}
		if (ret != 0 || buf[20] != '\0')
			return (list = free_list(list));
		close(fd);
	}
	return (list);
}

/*
**	gets the hash cordinates and put it into the tetris struct
**	double array.
*/

void	get_hash_position(t_tetris *tetris)
{
	int		i;
	int		j;
	int		hash;

	i = 0;
	hash = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetris->board[i][j] == '#')
			{
				tetris->pos[hash][0] = j;
				tetris->pos[hash][1] = i;
				hash++;
			}
			j++;
		}
		i++;
	}
}

/*
**	put the validated string into a double array
**	also populate the t_tetris structure.
*/

void	get_tetris(t_tetris *tetris, char *str, char label)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j == 5)
			j = 0;
		if (i < 4)
			tetris->board[0][j] = str[i];
		if (i > 4 && i < 9)
			tetris->board[1][j] = str[i];
		if (i > 9 && i < 14)
			tetris->board[2][j] = str[i];
		if (i > 14 && i < 19)
			tetris->board[3][j] = str[i];
		i++;
		j++;
	}
	tetris->label = label;
	get_hash_position(tetris);
	set_topleft(tetris);
	find_xy_max(tetris);
}

/*
**	checks the block in the buff if it is valid;
**	'#' blocks should equal 4;
**	'\n' should be in the index 5,10,15,20 and 21, hence % 5;
**	if encountered, replace '\n' with '\0' so the array would stop reading.
**	'\0' will be the 21th character in the last piece, so have to
**	include that as well.
*/

int		check_block(char *str)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	while (i < 20)
	{
		if (str[i] == '#' || str[i] == '.' || str[i] == '\n')
		{
			if ((str[i] == '\n' && ((i + 1) % 5 != 0)) || hash > 4)
				return (0);
			if (str[i] == '#')
				hash++;
		}
		else
			return (0);
		i++;
	}
	if ((str[20] == '\n' || str[20] == '\0') && check_links(str) == 1)
		return (1);
	return (0);
}

/*
**	checks if there is more than 6 links total to make valid shape
**	works with valid pieces though.
*/

int		check_links(char *str)
{
	int i;
	int links;

	i = 0;
	links = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				links++;
			if (str[i - 1] == '#')
				links++;
			if (str[i + 5] == '#')
				links++;
			if (str[i - 5] == '#')
				links++;
		}
		i++;
	}
	if (links >= 6)
		return (1);
	return (0);
}
