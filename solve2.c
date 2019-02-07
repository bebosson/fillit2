/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:21:52 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/07 18:11:02 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	alpha_solve(char **solve, t_tet *bb, int dim)
{
	int		x;
	int		y;
	int		nb_t;

	nb_t = 0;
	y = -1;
	while (++y < dim + 1 && bb->placer == 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if (((bb)->x_y[0] == x && (bb)->x_y[1] == y) && nb_t == 0)
				write_grille_letter(&nb_t, &solve[y][x], bb);
			else if (((bb)->coor[nb_t - 1][0] == x
						&& (bb)->coor[nb_t - 1][1] == y) && nb_t > 0)
				write_grille_letter(&nb_t, &solve[y][x], bb);
		}
	}
}

void	alpha_solve_all(char **solve, t_tet **bb, int dim, int ligne)
{
	int i;

	i = -1;
	while (++i <= ligne)
		alpha_solve(solve, bb[i], dim);
}

char	**grille_vide(int dim)
{
	int		i;
	int		j;
	char	**pot;

	i = -1;
	if (!(pot = malloc(sizeof(char *) * (dim + 2))))
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

int		check_place(t_tet **tab, int ligne)
{
	int i;
	int tetra_place;

	tetra_place = 0;
	i = -1;
	while (++i < ligne / 5)
		if (tab[i]->placer == 1)
			tetra_place++;
	if (tetra_place < ligne / 5)
		return (0);
	else
		return (1);
}

int		dim_min(t_tet **tab, int ligne)
{
	int dim_x;
	int dim_y;
	int i;
	int nbr_tetra;

	nbr_tetra = (ligne > 5) ? ligne / 5 : 1;
	i = 0;
	dim_x = 0;
	dim_y = 0;
	while (i < nbr_tetra)
	{
		if (x_max(tab[i], 3) > dim_x)
			dim_x = x_max(tab[i], 3);
		if (y_max(tab[i], 3) > dim_y)
			dim_y = y_max(tab[i], 3);
		i++;
	}
	if (dim_x > dim_y)
		return (dim_x);
	else
		return (dim_y);
}
