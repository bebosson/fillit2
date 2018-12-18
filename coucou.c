/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2018/12/18 18:05:14 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	fix_coor(char **pcs)
{
	int x;
	int	y;
	int i[4];
	int j[4];
	int nbr_pcs;
	int x_y[2];
	
	nbr_pcs = 0;
	x = 0;
	while (pcs[x])
	{
		y = 0;
		while (y < 4)
		{
			if (pcs[x][y] == '#' && nbr_pcs == 0)
			{
				i[0] = 0;
				j[0] = 0;
				x_y[0] = x;
				x_y[1] = y;
				printf("x = %d, y = %d\n",x,y);
				printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,i[0],nbr_pcs,j[0]);
				nbr_pcs++;
			}
			else if (pcs[x][y] == '#' && nbr_pcs < 4)
			{
				i[nbr_pcs] = x - x_y[0];
				j[nbr_pcs] = y - x_y[1];
				printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,i[nbr_pcs],nbr_pcs,j[nbr_pcs]);
				nbr_pcs++;
			}
			y++;
		}
		x++;
	}
}

int main()
{
	char *line;
	char **pot;
	pot = malloc(92000);
	int i = 0;

	int fd=open("test1", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		pot[i] = ft_strdup(line);
		i++;
	}
	fix_coor(pot);
}
