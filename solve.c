/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:42:59 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/26 16:32:55 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_next_maill(t_tet **n, int dim, char **t)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	y = -1;
	while (++y < dim + 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if (((*n)->x_y[0] == x && (*n)->x_y[1] == y))
				write_grille_diese(x, y, &nb_t, &t);
			else if (((*n)->coor[nb_t - 1][0] == x
						&& (*n)->coor[nb_t - 1][1] == y) && nb_t > 0)
				write_grille_diese(x, y, &nb_t, &t);
		}
	}
	(*n)->placer = 1;
	return (t);
}

char	**remove_last_maill(t_tet **new, int dim, char **tab)
{
	int x;
	int y;
	int nb_t;

	nb_t = 0;
	y = -1;
	while (++y < dim + 1)
	{
		x = -1;
		while (++x < dim + 1)
		{
			if (((*new)->x_y[0] == x && (*new)->x_y[1] == y) && nb_t == 0)
				write_grille_point(x, y, &nb_t, &tab);
			else if (((*new)->coor[nb_t - 1][0] == x
						&& (*new)->coor[nb_t - 1][1] == y)
					&& nb_t > 0)
				write_grille_point(x, y, &nb_t, &tab);
		}
	}
	(*new)->placer = 0;
	return (tab);
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
		if (tab[new->coor[x][1]][new->coor[x][0]] == '#')
			return (0);
	}
	return (1);
}

int		move_on(t_tet *new, int dim, char **solve)
{
	if (move_right_dim_ok(new, dim) == 1)
	{
		calcul_from_origin(&new, 1, 0);
		return (ft_solve(new, dim, solve));
	}
	else if (move_down_dim_ok(new, dim) == 1)
	{
		calcul_from_origin(&new, -(new->x_y[0]), 1);
		while (coor_neg_test(new) == 1)
			coor_neg(new);
		return (ft_solve(new, dim, solve));
	}
	else
		return (0);
}

int		ft_solve(t_tet *new, int dim, char **solve)
{
	int i_placer;

	i_placer = new->placer;
	while (ft_can_place(new, dim, solve) != 1)
	{
		while (ft_can_place(new, dim, solve) != 1
				&& move_right_dim_ok(new, dim) == 1)
			calcul_from_origin(&new, 1, 0);
		if (ft_can_place(new, dim, solve) == 1)
			return (1);
		else if (move_down_dim_ok(new, dim) == 1)
		{
			calcul_from_origin(&new, -(new->x_y[0]), 1);
			while (coor_neg_test(new) == 1)
				coor_neg(new);
		}
		else
		{
			set_tetra_pos_origin(&new);
			new->placer = i_placer;
			return (0);
		}
	}
	return (1);
}
