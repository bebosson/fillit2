/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:10:37 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/07 17:06:55 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grille(char **pot, int dim)
{
	int i;

	i = -1;
	while (pot[++i])
		ft_putendl(pot[i]);
}

int		coor_neg_test(t_tet *new)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (new->coor[i][0] < 0)
			return (1);
		i++;
	}
	return (0);
}

void	coor_neg(t_tet *new)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (new->coor[i][0] < 0)
			calcul_from_origin(&new, 1, 0);
		i++;
	}
}
