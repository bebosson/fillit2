/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:42:59 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/10 06:39:45 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**grille_vide(int dim)
{
	int i;
	int j;
	char **pot;

	i = -1;
	printf("dim_j= %d\n",dim + 1);
	if(!(pot = malloc(sizeof(char *) * (dim + 2))))
		return (NULL);

	while (++i < dim + 1)
	{
		j = -1;
		if (!(pot[i] = malloc(sizeof(char) * (dim + 2))))
			return (NULL);
		while (++j < dim + 1)
			pot[i][j] = '.';
		pot[i][j] = '\0';
	}
	pot[i] = 0;
	return (pot);
}

char	**ass_first_maill(t_tet *new, int dim, char ***tab)
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
			if ((new->x_y[0] == x  && new->x_y[1] == y) && nb_t++ == 0 && (*tab)[y][x] == '.')
				(*tab)[y][x] = '#';
			else if ((new->coor[nb_t - 1][0] == x  && new->coor[nb_t - 1][1] == y) && (*tab)[y][x] == '.' && nb_t++)
				(*tab)[y][x] = '#';
			else
				(*tab)[y][x] = '.';
		}
	}
	print_grille(*tab,3);
	return (*tab);
}

int		ft_can_place(t_tet *new, int dim, char ***tab)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	x = -1;
	if ((*tab)[new->x_y[0]][new->x_y[1]] == '#')
		return (0);
		while (++x < 3)
	{
		if ((*tab)[new->coor[x][0]][new->coor[x][1]]  == '#')
			return (0);
	}
	return (1);

}
/*
int		ft_solve(t_tet **new, int dim, char ***tab)
{
	//ICI on place les pieces 
	//si on arrive a placer (return 1) => on continu
	//des qu on peut pas return 0
 Move right jusqu a atteindre le bord 
 * Move down
 * Move r .......................*/
/* Move down etc
 * Si impossible deplacer la piece precedente*/
/* ----------SI TOUJOURS IMPOSSIBLE APRES LE DEPLACEMENT-------------*/
/*                       Augmenter taille                           

	if (ft_can_place())
	{
		ass_first_maill();
		if(ft_solve(dim +1))
		 *		return (1)
		
	}
	return (0);
}*/




/* A LA FIN :
 *
 * Avoir la grille la plus petite possible
 * Donc : Quand toutes les pieces sont places, il faut recommencer en gardant la dimension precedente pour comparer, en deplacent la premiere piece. Si on depace la dimention, on recommence.
 * Quand toutes les solutions impliquent de depacer la dim min, on arrete.*/
