/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2018/12/18 19:45:33 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tet	*fix_coor(char **pcs)
{
	int x;
	int	y;
//	int i[4];
//	int j[4];
	int nbr_pcs;
//	int x_y[2];
	t_tet	*bb;
	bb = ft_memalloc(sizeof(t_tet));

	nbr_pcs = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (pcs[y][x] == '#' && nbr_pcs == 0)
			{
				bb->x[0] = 0;
				bb->y[0] = 0;
				bb->x_y[0] = x;
				bb->x_y[1] = y;
//				printf("x = %d, y = %d\n",bb->x_y[0],bb->x_y[1]);
//				printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,bb->x[0],nbr_pcs,bb->y[0]);
				nbr_pcs++;
			}
			else if (pcs[y][x] == '#' && nbr_pcs < 4)
			{
				bb->x[nbr_pcs] = x - bb->x_y[0] ;
				bb->y[nbr_pcs] = y - bb->x_y[1] ;

//				printf("x = %d, y = %d\n",x,y);
//				printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,bb->x[nbr_pcs],nbr_pcs,bb->y[nbr_pcs]);
				nbr_pcs++;
			}
			x++;
		}
		y++;
	}
	bb->next = NULL;
	return (bb);
}

void		ft_display_cor(t_tet *bb)
{
	int i;
	int j;
	
	i = 0;
	//obj parcourir toute la liste ? 
	while (i < 4)
	{
		printf("x = %d, y = %d\n",bb->x_y[0],bb->x_y[1]);
		printf("x[%d] = %d , y[%d] = %d \n",i,bb->x[i],i,bb->y[i]);
		i++;
	}

}

int main(int ac, char **av)
{
	char *line;
	char **pot;
	int i = 0;
	int fd=open(av[1], O_RDONLY);
	t_tet *bb;
	pot = malloc(92000);
	while (get_next_line(fd, &line) > 0)
	{
		pot[i] = ft_strdup(line);
		i++;
	}

	bb = fix_coor(pot);
	ft_display_cor(bb);
}
