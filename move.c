/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:43:10 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/07 17:05:22 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	calcul_from_origin(t_tet **bb, int x_mov, int y_mov)
{
	int i;
	int j;

	i = -1;
	(*bb)->x_y[0] += x_mov;
	(*bb)->x_y[1] += y_mov;
	while (++i < 3)
	{
		(*bb)->coor[i][0] = (*bb)->coor[i][0] + x_mov;
		(*bb)->coor[i][1] = (*bb)->coor[i][1] + y_mov;
	}
}

int		move_right_dim_ok(t_tet *bb, int dim)
{
	int i_x_max;

	i_x_max = x_max(bb, dim);
	if (i_x_max + 1 > dim)
		return (0);
	else
		return (1);
}

int		move_down_dim_ok(t_tet *bb, int dim)
{
	int i_y_max;

	i_y_max = y_max(bb, dim);
	if (i_y_max + 1 > dim)
		return (0);
	else
		return (1);
}

int		x_max(t_tet *bb, int dim)
{
	int i;
	int x_max;

	i = -1;
	x_max = 0;
	while (++i < 3)
	{
		if (x_max < bb->coor[i][0])
			x_max = bb->coor[i][0];
	}
	return (x_max);
}

int		y_max(t_tet *bb, int dim)
{
	int i;
	int y_max;

	i = -1;
	y_max = 0;
	while (++i < 3)
	{
		if (y_max < bb->coor[i][1])
			y_max = bb->coor[i][1];
	}
	return (y_max);
}
