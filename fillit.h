/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:21:00 by artderva          #+#    #+#             */
/*   Updated: 2019/01/10 01:08:23 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_tet
{
	int				coor[3][2];// Ici faire de 2 tab 1 tab : int coor[3][2]
	int				x_y[2];
	char			letter;
	struct s_tet	*next;
}					t_tet;

int	set_tetra_pos(t_tet **next, int x, int y, int flag);
int	ft_check_line(char *line, int i); // return nbr de line ? -> nbr de tetras 
int	check_diese(char **pcs);
int	check_tetra(char **pos);
t_tet	*fix_coor(char **pcs, int ligne, int nbr_tetra);
int		check_read(int i,int ret,char ***pos);
int		read_main(char ***pos);
///t_tet	*fix_coor2(char **pcs);
t_tet	*set_lst_from_file(int i, char **pos);
void	ft_display_maill(t_tet *bb, int dim);
void	ft_display_lst(t_tet *lst);
int		x_max(t_tet *bb);
int		y_max(t_tet *bb);
char	**grille_vide(int dim);
char	**gorille_vide(int dim);
int		move_right_ok(t_tet *bb, int dim);
void		calcul_from_origin(t_tet **bb, int x_mov, int y_mov);
void	move_right(t_tet **bb, int dim);
void	move_down(t_tet **bb, int dim);
void	print_grille(char **pot, int dim);
void	print_grille_from_pcs(t_tet *new, int dim);
char	**ass_first_maill(t_tet *new, int dim, char ***tab);
int		ft_can_place(t_tet *new, int dim, char ***tab);
#endif
