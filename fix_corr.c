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

t_tet	*fix_coor(char **pcs)
{
	int x;
	int	y;
	int nbr_pcs;
	t_tet	*bb;

	bb = ft_memalloc(sizeof(t_tet));
	nbr_pcs = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (pcs[y][x] == '#' && nbr_pcs == 0)
			{
				bb->x[0] = 0;
				bb->y[0] = 0;
				bb->x_y[0] = x;
				bb->x_y[1] = y;
//				printf("x = %d, y = %d\n",bb->x_y[0],bb->x_y[1]);
//				printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,bb->x[0],nbr_pcs,bb->y[0]);
				nbr_pcs++;
			}
			else if (pcs[y][x] == '#' && nbr_pcs < 4)
			{
				bb->x[nbr_pcs] = x - bb->x_y[0] ;
				bb->y[nbr_pcs] = y - bb->x_y[1] ;
//				printf("x = %d, y = %d\n",x,y);
//				printf("i[%d] = %d, j[%d] = %d\n",nbr_pcs,bb->x[nbr_pcs],nbr_pcs,bb->y[nbr_pcs]);
				nbr_pcs++;
			}
			x++;
		}
		y++;
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

void	ft_cor_display(char **pot, t_tet)
{


}
