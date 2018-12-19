/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2018/12/18 21:33:42 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	set_tetra_pos(t_tet *new, int x, int y,  int flag)
{



	if (flag == 0)
	{
		bb->x[0] = 0;
		bb->y[0] = 0;
		bb->x_y[0] = x;
		bb->x_y[1] = y;
		//printf("x = %d, y = %d\n",bb->x_y[0],bb->x_y[1]);
		//printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,bb->x[0],nbr_pcs,bb->y[0]);
	}
	else if (flag != 0)
	{
		bb->x[nbr_pcs] = x - bb->x_y[0] ;
		bb->y[nbr_pcs] = y - bb->x_y[1] ;
		//printf("x = %d, y = %d\n",x,y);
		//printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,bb->x[nbr_pcs],nbr_pcs,bb->y[nbr_pcs]);
	}

}

}

t_tet	*fix_coor(char **pcs, int ligne, int nbr_tetra)
{
	int x;
	int	y_tetra;
	int y_max;
	t_tet	*bb;

	printf("%d\n",ligne);
	bb = ft_memalloc(sizeof(t_tet));
	y_tetra = 5 * nbr_tetra;
	if (y_tetra >= ligne)
		ft_putendl("ERROR");
	y_max = y_tetra + 4; 
	while (y_tetra < y_max)
	{
		x = 0;
		while (x < 4)
		{
			if (pcs[y_tetra][x] == '#' && nbr_pcs == 0)
				set_tetra_pos(bb, x, y_tetra, ymax, 0);
			else if (pcs[y_tetra][x] == '#' && nbr_pcs < 4)
			{
				set_tetra_pos(bb, x, y, ymax, nbr_pcs);
				nbr_pcs++;
			}
		}
		x++;
	}
	y_tetra++;
}
bb->next = NULL;
return (bb);
}

/*t_tet	*fix_coor2(char **pcs, int i)
  {
// marche pas
int x;
int	y;
int j;
int nbr_pcs;
t_tet *bb;

bb = ft_memalloc(sizeof(t_tet));
nbr_pcs = -1;

while (++y < 4)
{
x = -1;
while (++x < 4)
{
if (pcs[y][x] == '#' && ++nbr_pcs == 0)
{
printf("caca\n");
bb->x[0] = 0;
bb->y[0] = 0;
bb->x_y[0] = x;
bb->x_y[1] = y;
}
else if (pcs[y][x] == '#' && ++nbr_pcs < 4)
{
printf("caca\n");
bb->x[nbr_pcs] = x - bb->x_y[0] ;
bb->y[nbr_pcs] = y - bb->x_y[1] ;
}
}
}
}
bb->next = NULL;
return (bb);
}
*/
void		ft_display_maill(t_tet *bb)
{
	int i;
	int j;

	i = 0;
	//obj parcourir toute la liste ? 
	while (i < 4)
	{
		printf("x = %d, y = %d\n",bb->x_y[0],bb->x_y[1]);
		printf("x[%d] = %d , y[%d] = %d \n",i,bb->x[i],i,bb->y[i]);
		i++;
	}

}

void		ft_display_lst(t_tet *lst)
{
	int i;
	int j;

	i = 0;
	if (!lst)
		return ;
	while (lst)
	{
		while (i < 4)
		{
			printf("x = %d, y = %d\n",lst->x_y[0],lst->x_y[1]);
			printf("x[%d] = %d , y[%d] = %d \n",i,lst->x[i],i,lst->y[i]);
			i++;
		}
		lst = lst -> next;
	}
}

t_tetr		**set_lst_from_file(int i, char **pos)
{
	int nbr_tetr;
	t_tet *new;
	t_tet **lst;	
	nbr_tetr = 0;
	//malloc lst
	if (!(lst = malloc(sizeof(*t_tet))))
	{
		ft_putend("malloc echoue");
		return(NULL);
	}
	while (nbr_tetra < i / 5)
	{
		if (!new = fix_coor(pos, i, nbr_tetra))
		{
			ft_putend("malloc echoue");
			return(NULL);
		}
		lst->next = new;
		nbr_tetras++;
	}
	return (lst);
}
