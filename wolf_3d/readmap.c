/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:50:56 by tyang             #+#    #+#             */
/*   Updated: 2018/02/10 22:40:26 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		count_rows(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*read_maze(void)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*str;
	char	*del;

	str = NULL;
	ret = 0;
	fd = open("room.map", O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			del = ft_strjoin(str, buff);
			free(str);
			str = del;
		}
	}
	return (str);
}

int		check_char(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '2' && str[i] != '0' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

t_game	*make_map_arr(char *str, t_game *game)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	game->maze = ft_strsplit(str, '\n');
	while (game->maze[i])
	{
		j = 0;
		while (game->maze[i][j])
		{
			if (game->maze[i][j] == '2')
			{
				game->xpos = (j + 1) * 120 - 60;
				game->ypos = (i + 1) * 120 - 60;
			}
			j++;
		}
		i++;
	}
	return (game);
}
