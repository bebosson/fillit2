/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:46:28 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/10 19:11:52 by bebosson         ###   ########.fr       */
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
	printf("placer = %d \n",bb->placer);
	printf("lettre: [%c] \n",bb->letter);
	print_grille_from_pcs(bb, dim);
}

void	printlist(t_tet **tab, int dim, int ligne)
{
	int i;

	i = -1;
	while (++i <= ligne / 5)
		ft_display_maill(tab[i], dim);
}

void	print_grille(char	**pot, int dim)
{
	int i = 0;
	ft_putendl("-----grille solution-----");
	while (pot[i])
	{
		ft_putendl(pot[i]);
		i++;
	}
	ft_putendl("-------------------------");
}

void	print_grille_from_pcs(t_tet *new, int dim)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	y = -1;
	ft_putendl("-------tetra-------");
	while(++y < dim + 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if ((new->x_y[0] == x  && new->x_y[1] == y) && nb_t == 0)
			{
				printf("%c",new->letter);
				nb_t++;
			}
			else if ((new->coor[nb_t - 1][0] == x  && new->coor[nb_t - 1][1] == y) && nb_t > 0)
			{
				printf("%c",new->letter);
				nb_t++;
			}
			else
				printf(".");
		}
		printf("\n");
	}
}
