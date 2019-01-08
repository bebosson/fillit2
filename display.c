/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:46:28 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/08 23:40:39 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_display_maill(t_tet *bb)
{
	int i;
	int j;

	i = -1;
	j = -1;
	//obj parcourir toute la liste ? 

	printf("o_x = %d \n",bb->x_y[0]);

	printf("o_y = %d \n",bb->x_y[1]);
	while (++i < 3)
	{
		printf("x = %d || ",bb->coor[i][0]);
		printf("y = %d \n",bb->coor[i][1]);
	}
	ft_putendl("-------------------");
}
char	**grille_vide(int dim)
{
	int i;
	int j;
	char **pot;

	i = -1;
	printf("dim_j= %d\n",dim);
	if(!(pot = malloc(sizeof(char *) * (dim + 1))))
		return (NULL);

	while(++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if(!(pot[i] = malloc(dim + 1)))
				return (NULL);
			pot[i][j] = '.';
			printf("%c",pot[i][j]);
		}
		pot[i][j] = '\0';
		printf("\n");
	}
	pot[i] = 0;
	return (pot);
}



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
	printf("right ok  = %d ? \n",move_right_ok(*bb,dim)); //ici x_y[0] + 3 ?? 
	printf("o_x_2 = %d \n",(*bb)->x_y[0]);
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

void	printlist(t_tet *lst)
{
	t_tet *tmp;

	tmp = lst;
	if (tmp == NULL)
	{
		ft_putendl("rate frero");
		return ;
	}
	while (tmp->next != NULL)
	{
		//ft_putchar(tmp->letter);
		ft_display_maill(tmp->next);
		tmp = tmp->next;
	}
}
/*void		ft_display_lst(t_tet *lst)
  {
  int i;
  int j;

  t_tet *tmp;
  if (!lst)
  return ;
  tmp = lst;
  while (tmp)
  {
  i = -1;
  while (++i < 4)
  printf("x[%d] = %d , y[%d] = %d \n",i,lst->x[i],i,lst->y[i]);
  tmp = tmp->next;
  }
  }*/
