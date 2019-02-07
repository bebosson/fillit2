/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:38:56 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/07 19:38:17 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**remove_all_maill(t_tet **tab, int nb_tet, char **solve, int *dim)
{
	int i;

	i = -1;
	while (++i < nb_tet)
	{
		set_tetra_pos_origin(&tab[i]);
		remove_last_maill(&tab[i], *dim, solve);
	}
	(*dim)++;
	ft_free_tab(&solve);
	return (grille_vide(*dim));
}

int			comb_tetra(t_tet **tab, int i, int dim, char **solve)
{
	int j;

	while (ft_solve(tab[i], dim, solve) == 0)
	{
		j = i - 1;
		set_tetra_pos_origin(&tab[i]);
		while (j >= 0 && ft_can_place(tab[j], dim, solve) == 0)
		{
			if (tab[j]->placer != 0)
				remove_last_maill(&tab[j], dim, solve);
			if (move_on(tab[j], dim, solve) == 1)
			{
				solve = put_next_maill(&tab[j], dim, solve);
				return (dim);
			}
			else
				j--;
		}
		if (j < 0)
		{
			dim++;
			return (dim);
		}
	}
	return (dim);
}

char		**start_solve(t_tet **tab, int nbr_tetra, int *dim)
{
	char	**solve;
	int		i;
	int		new_dim;

	new_dim = *dim;
	i = 0;
	solve = grille_vide(*dim);
	while (i <= nbr_tetra)
	{
		if (tab[i]->placer == 0)
		{
			if (ft_solve(tab[i], new_dim, solve) == 1)
				solve = put_next_maill(&tab[i++], new_dim, solve);
			else if (ft_solve(tab[i], new_dim, solve) == 0 && i > 0)
			{
				new_dim = comb_tetra(tab, i, new_dim, solve);
				if (new_dim != *dim)
					solve = remove_all_maill(tab, nbr_tetra, solve, dim);
				i = 0;
			}
		}
		else if (tab[i]->placer == 1)
			i++;
	}
	return (solve);
}

int		ft_dimini(t_tet **tab, int *line)
{
	int		tet;
	int		dim;
	int		dim_mini;

	tet = (*line + 1) / 5 * 4;
	dim = 2;
	while (dim * dim < tet)
		dim++;
	dim_mini = dim_min(tab, *line);
	*line = *line / 5;
	dim--;
	if (dim_mini > dim)
		return (dim_mini);
	else
		return (dim);
}
