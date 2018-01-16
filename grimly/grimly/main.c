/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:03:05 by tyang             #+#    #+#             */
/*   Updated: 2018/01/15 21:43:36 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "grimly.h"

int		main(int ac, char **av)
{
	t_maze	*maze;
	int		i;

	if (ac == 1)
	{
		maze = read_stdinput();
		solve_maze(maze);
		print_maze(maze);
		free(maze):
	}
	while (ac > 1)
	{
		i = 0;
		if (maze = read_file(av[i], maze))
		solve_maze(maze);
		print_maze(maze);
		free(maze);
		i++;
		ac--;
	}
	return (0);
}
