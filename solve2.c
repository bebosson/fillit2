/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:21:52 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/26 16:47:47 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	alpha_solve(char **solve, t_tet *bb, int dim)
{

	int x;
	int y;
	int nb_t;

	nb_t = 0;
	y = -1;
	while(++y < dim + 1 && bb->placer == 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if (((bb)->x_y[0] == x  && (bb)->x_y[1] == y)
					&& nb_t == 0)
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
	while (++i <= ligne / 5)
		alpha_solve(solve, bb[i], dim);
}

char	**grille_vide(int dim)
{
	int i;
	int j;
	char **pot;

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
