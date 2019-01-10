/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2019/01/10 06:42:09 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		set_tetra_pos(t_tet **new, int x, int y,  int flag)
{
	if (flag == 0)  // essayer de faire sans;
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
		}
	}
	flag++;
	return (flag);
}


t_tet	*fix_coor(char **pcs, int ligne, int nbr_tetra)
{
	int x;
	int	y_tetra;
	int v_y_max;
	t_tet	*new;
	int nbr_pcs;

	nbr_pcs = 0;
	y_tetra = (nbr_tetra > 0) ? 5 * nbr_tetra  : 0;
	v_y_max = y_tetra + 4;
	if (!(new =(t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	//if (y_tetra >= ligne)
	//	ft_putendl("ERROR");
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
	new->next = NULL;
/*	ft_putendl("----avant----");
	ft_display_maill(new);
	move_down(&new,3); CA CA MARCHE !! MOUVEMENT DES PIECES
	ft_putendl("----apres----");
	ft_display_maill(new);
	y_max(new);
						OBJECTIF MAINTENANT:
				EN FAIRE UNE LISTE ET L AFFICHER EN DEHORS DE CETTE FONCTION
*/
	return (new);
}

t_tet		*set_lst_from_file(int ligne, char **pos)
{
	int nbr_tetr;
	t_tet *new;
	t_tet *new2;
	char **solve;

	nbr_tetr = 0;
	printf("ligne = %d \n", ligne);
/*	if (!(lst = (t_tet*)malloc(sizeof(t_tet))))
	{
		ft_putendl("malloc echoue");
		return(NULL);
	}
	while (nbr_tetr < ligne / 5)
	{
*/		if (!(new = fix_coor(pos, ligne, nbr_tetr)))
		{
			ft_putendl("malloc echoue");
			return(NULL);
		}
		nbr_tetr++;
		if (!(new2 = fix_coor(pos, ligne, 1)))
		{
			ft_putendl("malloc echoue");
			return(NULL);
		}

		solve = grille_vide(3);
		print_grille(solve,3);
//		solve = ass_first_maill(new,3,&solve);
//		print_grille_from_pcs(new2,3);
		ft_display_maill(new,3);
		solve = ass_first_maill(new,3,&solve);
		print_grille(solve,3);

		ft_display_maill(new,3);
		move_right(&new,3);
		ft_display_maill(new,3);
		print_grille_from_pcs(new2,3);
		solve = ass_first_maill(new,3,&solve);
		print_grille(solve,3);

		printf("%d\n",ft_can_place(new,3,&solve));
//		solve = ass_first_maill(new2,3,&solve);
		//		lst->next = new;
//		free(new);
		nbr_tetr++;
//		if nbr_tetr = 0;
//			init_lst(char ** ..);
//		else if nbr_tetr > 0
//			add_to_lst(char **, t_bis list)
//	}
//	printlist(lst);
	return (new);
}
