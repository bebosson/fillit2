/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2019/01/27 14:32:08 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		set_tetra_pos(t_tet **new, int x, int y, int flag)
{
	if (flag == 0)
	{
		(*new)->x_y[0] = x;
		(*new)->x_y[1] = y;
	}
	else if (flag != 0)
	{
		(*new)->coor[flag - 1][0] = x - (*new)->x_y[0];
		(*new)->coor[flag - 1][1] = y - (*new)->x_y[1];
		if (flag > 2)
		{
			(*new)->x_y[0] = 0;
			(*new)->x_y[1] = 0;
			(*new)->placer = 0;
			coor_neg(*new);
		}
	}
	flag++;
	return (flag);
}

void	set_tetra_pos_origin(t_tet **new)
{
	int i;

	i = 0;
	while (i < 3)
	{
		(*new)->coor[i][0] = (*new)->coor[i][0] - (*new)->x_y[0];
		(*new)->coor[i][1] = (*new)->coor[i][1] - (*new)->x_y[1];
		i++;
	}
	(*new)->x_y[0] = 0;
	(*new)->x_y[1] = 0;
	while (coor_neg_test(*new) == 1)
		coor_neg(*new);
	(*new)->placer = 0;
}

t_tet	*fix_coor(char **pcs, int nbr_tetra)
{
	int		x;
	int		y_tetra;
	int		v_y_max;
	t_tet	*new;
	int		nbr_pcs;

	nbr_pcs = 0;
	y_tetra = (nbr_tetra > 0) ? 5 * nbr_tetra : 0;
	v_y_max = y_tetra + 4;
	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	while (y_tetra < v_y_max)
	{
		x = -1;
		while (++x < 4)
			if (pcs[y_tetra][x] == '#' && nbr_pcs == 0)
				nbr_pcs = set_tetra_pos(&new, x, y_tetra, 0);
			else if (pcs[y_tetra][x] == '#' && nbr_pcs != 0)
				nbr_pcs = set_tetra_pos(&new, x, y_tetra, nbr_pcs);
		y_tetra++;
	}
	new->letter = 'A' + (char)nbr_tetra;
	return (new);
}

t_tet	**set_lst_from_file(int ligne, char **pos)
{
	int		nbr_tetr;
	t_tet	**tab;

	nbr_tetr = 0;
	if (!(tab = (t_tet **)malloc(sizeof(t_tet *) * ligne / 5)))
		return (0);
	while (nbr_tetr <= ligne / 5)
	{
		if (!(tab[nbr_tetr] = fix_coor(pos, nbr_tetr)))
		{
			ft_putendl("malloc echoue");
			return (0);
		}
		nbr_tetr++;
	}
	return (tab);
}
