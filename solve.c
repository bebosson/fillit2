/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:42:59 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/15 23:27:01 by bebosson         ###   ########.fr       */
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

char	**put_next_maill(t_tet **new, int dim, char ***tab)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	y = -1;
	ft_putendl("--------------");
	ft_display_maill(*new,3);
	while(++y < dim + 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if (((*new)->x_y[0] == x  && (*new)->x_y[1] == y)
					&& nb_t == 0 && (*tab)[y][x] == '.')
			{
				(*tab)[y][x] = '#';
				nb_t++;
			}
			else if (((*new)->coor[nb_t - 1][0] == x 
						&& (*new)->coor[nb_t - 1][1] == y) && nb_t > 0)
			{
				(*tab)[y][x] = '#';
				nb_t++;
			}
		}
	}
	(*new)->placer = 1;
	return (*tab);
}

char	**remove_last_maill(t_tet **new, int dim, char ***tab)
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
			if (((*new)->x_y[0] == x  && (*new)->x_y[1] == y) && nb_t == 0)
			{
				(*tab)[y][x] = '.';
				nb_t++;
			}
			else if (((*new)->coor[nb_t - 1][0] == x  && (*new)->coor[nb_t - 1][1] == y) && nb_t > 0)
			{
				(*tab)[y][x] = '.';
				nb_t++;
			}
		}
	}
	(*new)->placer = 1; 
	return (*tab);
}



int		ft_can_place(t_tet *new, int dim, char **tab)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	x = -1;
	if (tab[new->x_y[1]][new->x_y[0]] == '#')
		return (0);
	while (++x < 3)
	{
		if (tab[new->coor[x][1]][new->coor[x][0]]  == '#')
			return (0);
	}
	return (1);

}
int		move_on(t_tet *new, int dim, char **solve) // A mettre dans un while ? 
{

	if (move_right_dim_ok(new,dim) == 1)
	{
		calcul_from_origin(&new,1,0);
		return (ft_solve(new,dim,solve));
	}
	else if (move_down_dim_ok(new,dim) == 1)
	{
		calcul_from_origin(&new,-(new->x_y[0]),1);
		return (ft_solve(new,dim,solve));
	}
	else 
		return (0);

}


int		ft_solve(t_tet *new, int dim, char **solve) // A mettre dans un while ? 
{
	t_tet *new2;

	new2 = new;
	while (ft_can_place(new,dim,solve) != 1)
	{
		while (ft_can_place(new,dim,solve) != 1 && move_right_dim_ok(new,dim) == 1)
		{
			calcul_from_origin(&new,1,0);
			printf("can do ?%d\n",ft_can_place(new,3,solve));
		}
		if (ft_can_place(new,dim,solve) == 1)
			return (1);
		else if (move_down_dim_ok(new,3) == 1)
			calcul_from_origin(&new,-(new->x_y[0]),1);
		else
		{
			set_tetra_pos_origin(&new);
			return (0);
		}
	}
	return (1);
}

	//ICI on place les pieces 
	//si on arrive a placer (return 1) => on continu
	//des qu on peut pas return 0
	//Move right jusqu a atteindre le bord 
	// * Move down
	// * Move r .......................*/
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
