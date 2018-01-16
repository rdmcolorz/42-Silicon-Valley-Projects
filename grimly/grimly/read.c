/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:15:37 by tyang             #+#    #+#             */
/*   Updated: 2018/01/15 21:42:36 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_maze	*read_file(char *src, t_maze *maze)
{
	int			fd;
	int			ret;
	char		buff[4242];
	char		*temp_maze;

	if ((fd = open(src, O_RDONLY)) != -1)
	{
		if ((ret = read(fd, buff, 4241)) > 0)
		{
			buff[ret] = '\0';
			temp_maze = ft_strdup(buff);
		}
		while ((ret = read(fd, buff, 4241)) > 0)
		{
			buff[ret] = '\0';
			temp_maze = ft_strjoin(temp_maze, buff);
		}
		return (maze = get_info(temp_maze, maze));
	}
	return (NULL);
}

t_maze	*get_info(char *str, t_maze *maze)
{
	char	*info;
	int		i;
	int		len;

	i = 0;
	while (str[i] != '\n')
		i++;
	info = ft_strsub(str, 0, i);
	len = ft_strlen(info);
	if (is_diff_char(info, len) != 1 || is_row_col(info, len) != 1 ||
			((maze = (t_maze*)malloc(sizeof(t_maze))) == NULL))
		return (NULL);
	maze = get_nb(maze, info, len);
	maze->wall = str[len - 5];
	maze->empty = str[len - 4];
	maze->path = str[len - 3];
	maze->start = str[len - 2];
	maze->exit = str[len - 1];
	return (maze);
}

/*
**	Gets the row and colum numbers.
*/

t_maze	*get_nb(t_maze *maze, char *str, int len)
{
	char	*nb;
	int		i;

	i = 0;
	while (str[i] != 'x')
	{
		i++;
		if (str[i] == 'x')
			maze->rows_nb = ft_atoi(ft_strsub(str, 0, i));
		maze->cols_nb = ft_atoi(ft_strsub(str, i + 1, len - i));
	}
	return (maze);
}

/*
**	Checks if the characters in the info overlaps.
**	excluding the rows and col numbers.
*/

int		is_diff_char(char *str, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[len + i - 5])
	{
		j = 0;
		while (str[len + j - 5])
		{
			if (i != j)
			{
				if (str[len + i - 5] == str[len + j - 5])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	Check if besides the five characters input, the others are numbers
**	or the 'x' character.
*/

int		is_row_col(char *str, int len)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	if (!IS_DIGIT(str[i]))
		return (0);
	i++;
	while (i < len - 5)
	{
		if (IS_DIGIT(str[i]))
			i++;
		else if (str[i] == 'x')
		{
			i++;
			flag = 1;
		}
		else
			return (0);
	}
	if (flag == 0)
		return (0);
	return (1);
}

/*
**int		main(int ac, char **av)
**{
**	char *read;
**	t_maze *maze;
**
**	read = read_file(av[1]);
**	maze = get_info(read);
**	if (maze == NULL)
**		ft_putendl("MAZE IS NULL IDIOT");
**	printf("%c%c%c%c%c\n%ix%i\n", maze->wall, maze->empty, maze->path,
**			maze->start, maze->exit, maze->rows_nb, maze->cols_nb);
**
**}
*/
