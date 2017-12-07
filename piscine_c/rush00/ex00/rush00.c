/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 09:10:02 by tyang             #+#    #+#             */
/*   Updated: 2017/10/29 17:38:14 by tyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int		ft_putchar(char c);
int 	rush(int x, int y);

int main()
{
	rush(5, 5);
	return (0);
}

int		rush(int x, int y)
{
	int xcount;
	int ycount;
	
	ycount = 0;
	while ((ycount == 0) || (ycount == (y-1))
	{
		xcount = 0;
		if ((xcount == 0) || (xcount == (x - 1)
		{
			ft_putchar('o');
		}
		while (xcount < (x - 1))
		{
			ft_putchar('-');
			xcount++;
		}
		ycount++;
		ft_putchar('\n');
	}

	xcount = 0;
	while (ycount < (y - 1))
	{
		xcount = 0;
		if ((xcount == 0) || (xcount == (x - 1))
		{
			ft_putchar ('|');
		}
		while (xcount < x)
		{
			ft_putchar(' ');
			xcount++;
		}
	}
	ycount++;
	ft_putchar('\n');

int		ft_putchar(char c)
{
	write (1,&c,1);
}
