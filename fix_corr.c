/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_corr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:30:05 by artderva          #+#    #+#             */
/*   Updated: 2019/01/10 21:59:55 by bebosson         ###   ########.fr       */
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


/*t_tet	*add_to_lst(char **pcs, int ligne, int nbr_tetra, t_tet *lst)
  {
  int x;
  int	y_tetra;
  int v_y_max;
  t_tet	*maillon;
  int nbr_pcs;

  nbr_pcs = 0;
  y_tetra = (nbr_tetra > 0) ? 5 * nbr_tetra  : 0;
  v_y_max = y_tetra + 4;
  printf("tu rentres la coco?\n");
//	if (!(maillon =(t_tet*)malloc(sizeof(t_tet))))
//		return (NULL);
if (!(maillon =(t_tet*)malloc(10000000)))
return (NULL);

//	maillon->coor = malloc(sizeof(int *) * 5);
maillon->next = NULL;
printf("tu rentres la coco?\n");
while (y_tetra < v_y_max)
{
x = -1;
while (++x < 4)
if (pcs[y_tetra][x] == '#' && nbr_pcs == 0)
nbr_pcs = set_tetra_pos(&maillon, x, y_tetra, 0);
else if (pcs[y_tetra][x] == '#' && nbr_pcs != 0)
nbr_pcs = set_tetra_pos(&maillon, x, y_tetra, nbr_pcs);
y_tetra++;
}
ft_display_maill(maillon);
if (lst == NULL)
return (maillon);
else
{
while (lst->next != NULL)
lst = lst->next;
maillon->letter = 'B' + (char)nbr_tetra;
lst->next = maillon;
return (lst);
}
}


t_tet	*init_lst(char **pcs, int ligne, int nbr_tetra) //init_lst
{
int x;
int	y_tetra;
int v_y_max;
t_tet	*lst;
int nbr_pcs;

nbr_pcs = 0;
y_tetra = (nbr_tetra > 0) ? 5 * nbr_tetra  : 0;
v_y_max = y_tetra + 4;
if (!(lst =(t_tet*)malloc(sizeof(t_tet))))
return (NULL);
//if (y_tetra >= ligne)
//	ft_putendl("ERROR");
while (y_tetra < v_y_max)
{
x = -1;
while (++x < 4)
if (pcs[y_tetra][x] == '#' && nbr_pcs == 0)
nbr_pcs = set_tetra_pos(&lst, x, y_tetra, 0);
else if (pcs[y_tetra][x] == '#' && nbr_pcs != 0)
nbr_pcs = set_tetra_pos(&lst, x, y_tetra, nbr_pcs);
y_tetra++;
}
lst->letter = 'A';
lst->next = NULL;
return (lst);
}
*/

/*	ft_putendl("----avant----");
	ft_display_maill(new);
	move_down(&new,3); CA CA MARCHE !! MOUVEMENT DES PIECES
	ft_putendl("----apres----");
	ft_display_maill(new);
	y_max(new);
	OBJECTIF MAINTENANT:
	EN FAIRE UNE LISTE ET L AFFICHER EN DEHORS DE CETTE FONCTION
	*/
t_tet	**set_lst_from_file(int ligne, char **pos)
{
	int nbr_tetr;
	t_tet **tab;
	
	nbr_tetr = 0;
	if (!(tab = (t_tet **)malloc(sizeof(t_tet *) * ligne / 5)))
		return (0);
	
	while (nbr_tetr < ligne / 5)
	{		
		if (!(tab[nbr_tetr] = fix_coor(pos, ligne, nbr_tetr)))
		{
			ft_putendl("malloc echoue");
			return (0) ;
		}
		nbr_tetr++;
	}
	return(tab);
}	
	
/*	solve = grille_vide(3);
	//		print_grille(solve,3);
	//		solve = ass_first_maill(new,3,&solve);
	//		print_grille_from_pcs(new2,3);
	//		ft_display_maill(new,3);
	solve = put_next_maill(new2,3,&solve);
	print_grille(solve,3);


	printf("yo ?? %d\n",ft_can_place(new,3,&solve));
	printf("move R ?%d\n",move_down_dim_ok(new,3));

	
	printf("can do ?%d\n",ft_can_place(new,3,&solve));
	printf("allo?\n");
	ft_solve(&new,3,&solve);
	solve = put_next_maill(new,3,&solve);
	//		ft_display_maill(new,3);
	//		move_right(&new,3);
	//		print_grille_from_pcs(new,3);

	print_grille(solve,3);
	ft_display_maill(new,3);
	//		print_grille_from_pcs(new2,3);
	//		calcul_from_origin(&new,1,0);
	//		calcul_from_origin(&new,1,0);
	//		ft_display_maill(new,3);
	print_grille(solve,3);
	//		printf("%d\n",ft_can_place(new,3,&solve));
	//		solve = ass_first_maill(new2,3,&solve);
	//		lst->next = new;
	//		free(new);
	//			init_lst(char ** ..);
	//		else if nbr_tetr > 0
	//			add_to_lst(char **, t_bis list)
	//	}
	//	printlist(lst);
	return (new);
}
*/

