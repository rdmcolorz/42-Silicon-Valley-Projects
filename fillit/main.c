/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:14:33 by tyang             #+#    #+#             */
/*   Updated: 2018/01/15 13:22:50 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	t_map	*map;
	int		fd;

	fd = 0;
	list = NULL;
	if (argc == 2)
	{
		if ((list = read_file(list, argv[1], fd)) != NULL)
		{
			ft_lstrev(&list);
			map = solve_all_maps(list);
			print_map(map);
			free(map);
			list = free_list(list);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
