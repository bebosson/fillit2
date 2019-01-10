/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:46:28 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/10 00:48:59 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_display_maill(t_tet *bb, int dim)
{
	int i;
	int j;

	i = -1;
	j = -1;
	//obj parcourir toute la liste ? 

	printf("o_x = %d \n",bb->x_y[0]);

	printf("o_y = %d \n",bb->x_y[1]);
	ft_putendl("-------------------");
	while (++i < 3)
	{
		printf("x = %d || ",bb->coor[i][0]);
		printf("y = %d \n",bb->coor[i][1]);
	}
	print_grille_from_pcs(bb, dim);
}
void	printlist(t_tet *lst, int dim)
{
	t_tet *tmp;

	tmp = lst;
	if (tmp == NULL)
	{
		ft_putendl("rate frero");
		return ;
	}
	while (tmp->next != NULL)
	{
		//ft_putchar(tmp->letter);
		ft_display_maill(tmp->next, dim);
		tmp = tmp->next;
	}
}

void	print_grille(char	**pot, int dim)
{
	int i = 0;
	while (pot[i])
	{
		ft_putendl(pot[i]);
		i++;
	}
}

void	print_grille_from_pcs(t_tet *new, int dim)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	y = -1;
	ft_putendl("--------------");
	while(++y < dim + 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if ((new->x_y[0] == x  && new->x_y[1] == y) && nb_t++ == 0)
				printf("#");
			else if ((new->coor[nb_t - 1][0] == x  && new->coor[nb_t - 1][1] == y) && nb_t++)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
}
