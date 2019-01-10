/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:43:10 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/10 06:37:39 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void		calcul_from_origin(t_tet **bb, int x_mov, int y_mov)
{
	int i;
	int j;

	i = -1;

	// transformer la fonction en app generique a tt les deplacements en ajoutant des params
	(*bb)->x_y[0] += x_mov;
	(*bb)->x_y[1] += y_mov;
	//(*bb)->x_y[1] = o_y;
	printf("o_x = %d \n",(*bb)->x_y[0]);
	while (++i < 3)
	{
		j = -1;
		while(++j < 2)
			(*bb)->coor[i][j] = (*bb)->coor[i][j] + (*bb)->x_y[j];
	}
}

int		move_right_ok(t_tet *bb, int dim)
{
	int i_x_max;

	i_x_max = x_max(bb);
	if (i_x_max + 1 > dim)
		return (0);
	else
		return (1);
}

int		move_down_ok(t_tet *bb, int dim)
{
	int i_y_max;

	i_y_max = y_max(bb);
	if (i_y_max + 1 > dim)
		return (0);
	else
		return (1);
}
//move_down => calcul_from_origin(**bb,bb->x_y[0],bb->x_y + 1)
//
void	move_right(t_tet **bb, int dim)
{
	if(move_right_ok(*bb,dim))
		calcul_from_origin(bb,1,0);
	//		calcul_from_origin(&bb,(*bb)->x_y[0] + 1,(*bb)->x_y[1]);
	else
		return ;
}
//on fait les test dans les fonctions de deplacement ou en dehors ???

void	move_down(t_tet **bb, int dim)
{
	if(move_down_ok(*bb,dim))
		calcul_from_origin(bb,0,1);
	//		calcul_from_origin(&bb,(*bb)->x_y[0] + 1,(*bb)->x_y[1]);
	else
		return ;
}
// Objectif : repeter les move_right  m_r m_r m_d m_r m_r ...
//             pour parcourir toute la grille 

/*void	move_grille(t_tet **bb, int dim, char **tab)
{
	while (


}
*/
// Objectif : parcourir la liste et en sortir le x_max et y_max pour la dim min
// Exemple :
//
int		dim_min(t_tet *new, t_tet *bb)
{
	int dim;
	int dim_x;
	int dim_y;

	dim = 0;
	dim_x = x_max(bb);
	dim_y = y_max(bb);
	if (x_max(new) > dim_x)
		dim_x = x_max(new);
	if (y_max(new) > dim_y)
		dim_y = y_max(new);
	if (dim_x > dim_y)
		return (dim_x);
	else
		return (dim_y);
}


int		x_max(t_tet *bb)
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
	printf("x_max = %d\n",x_max);
	ft_putendl("--------");
	return (x_max);
}

int		y_max(t_tet *bb)
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
	printf("y_max = %d\n",y_max);
	ft_putendl("--------");
	return (y_max);
}


