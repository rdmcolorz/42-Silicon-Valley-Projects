/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:50:56 by tyang             #+#    #+#             */
/*   Updated: 2018/02/08 11:10:22 by tyang            ###   ########.fr       */
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

char	**make_map_arr(char *str, t_game *game)
{
	int		i;
	int		j;
	int		rows;
	int		cols;
	char	**arr;

	if (check_char(str) == 0)
		return (NULL);
	rows = count_rows(str);
	game->maze_rows = rows * CUBE_HL;
	cols = ft_strlen(str) / rows - 1;
	game->maze_cols = cols * CUBE_HL;
	arr = (char**)ft_memalloc(sizeof(char*) * (rows + 1));
	i = -1;
	while (++i < rows)
	{
		j = 0;
		arr[i] = (char*)ft_memalloc(sizeof(char) * (cols + 1));
		while (*str != '\n')
			arr[i][j++] = *str++;
		str++;
	}
	arr[i] = 0;
	return (arr);
}
