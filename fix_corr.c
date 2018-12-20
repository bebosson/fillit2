/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2018/12/20 05:25:46 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	set_tetra_pos(t_tet **new, int x, int y,  int flag)
{
	if (flag == 0)
	{
		(*new)->x[0] = 0;
		(*new)->y[0] = 0;
		(*new)->x_y[0] = x;
		(*new)->x_y[1] = y;
//		printf("x = %d, y = %d\n",(*new)->x_y[0],(*new)->x_y[1]);
//		printf("i[%d] = %d, j[%d] = %d\n",flag,(*new)->x[0],flag,(*new)->y[0]);
	}
	else if (flag != 0)
	{
		(*new)->x[flag] = x - (*new)->x_y[0] ;
		(*new)->y[flag] = y - (*new)->x_y[1] ;
//		printf("x = %d, y = %d\n",x,y);
//		printf("i[%d] = %d, j[%d] = %d\n",flag,(*new)->x[flag],flag,(*new)->y[flag]);
	}

}


t_tet	*fix_coor(char **pcs, int ligne, int nbr_tetra)
{
	int x;
	int	y_tetra;
	int y_max;
	t_tet	*new;
	int nbr_pcs;

	if(!(new =(t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	y_tetra = (nbr_tetra > 0) ? 5 * nbr_tetra  : 0;
	if (y_tetra >= ligne)
		ft_putendl("ERROR");
	y_max = y_tetra + 4;
	printf("y_tetra = %d \n",y_tetra);
	nbr_pcs = 0;
	while (y_tetra < y_max)
	{
		x = 0;
		while (x < 4)
		{
			if (pcs[y_tetra][x] == '#' && nbr_pcs == 0)
			{
				set_tetra_pos(&new, x, y_tetra, 0);
				nbr_pcs++;
			}
			else if (pcs[y_tetra][x] == '#' && nbr_pcs < 4)
			{
				set_tetra_pos(&new, x, y_tetra, nbr_pcs);
				nbr_pcs++;
			}

			x++;
		}
		y_tetra++;
	}
	new->next = NULL;
	ft_display_maill(new);
	return (new);
}

void		ft_display_maill(t_tet *bb)
{
	int i;
	int j;

	i = 0;
	//obj parcourir toute la liste ? 
	while (i < 4)
	{
		printf("x[%d] = %d , y[%d] = %d \n",i,bb->x[i],i,bb->y[i]);
		i++;
	}
}

void		ft_display_lst(t_tet *lst)
{
	int i;
	int j;
	
	t_tet *tmp;
	i = 0;
	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		while (i < 4)
		{
			printf("x = %d, y = %d\n",lst->x_y[0],lst->x_y[1]);
			printf("x[%d] = %d , y[%d] = %d \n",i,lst->x[i],i,lst->y[i]);
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
}

t_tet		*set_lst_from_file(int ligne, char **pos)
{
	int nbr_tetr;
	t_tet *new;
	t_tet *lst;

	nbr_tetr = 0;
	printf("ligne = %d", ligne);
	if (!(lst = (t_tet*)malloc(sizeof(t_tet))))
	{
		ft_putendl("malloc echoue");
		return(NULL);
	}
	while (nbr_tetr < ligne / 5)
	{
		if (!(new = fix_coor(pos, ligne, nbr_tetr)))
		{
			ft_putendl("malloc echoue");
			return(NULL);
		}
		lst->next = new;
		nbr_tetr++;
	}
//	ft_display_lst(lst);
	return (lst);
}
