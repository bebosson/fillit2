/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:21:00 by artderva          #+#    #+#             */
/*   Updated: 2019/02/07 18:08:50 by bebosson         ###   ########.fr       */
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
	int				placer;
	char			letter;
}					t_tet;

void	write_grille_point(int x, int y, int *nb_t, char ***tab);
void	write_grille_diese(int x, int y, int *nb_t, char ***tab);
int		coor_neg_test(t_tet *new);
void		coor_neg(t_tet *new);
void	alpha_solve_all(char **solve, t_tet **bb, int dim, int ligne);
void	alpha_solve(char **solve, t_tet *bb, int dim);
int	set_tetra_pos(t_tet **next, int x, int y, int flag);
void		set_tetra_pos_origin(t_tet **new);
int		comb_tetra(t_tet **tab, int i, int dim, char **solve);
int	ft_check_line(char *line, int i); // return nbr de line ? -> nbr de tetras 
int	check_diese(char **pcs);
char		**remove_all_maill(t_tet **tab, int nb_tet, char **solve, int *dim);

char		**start_solve(t_tet **tab, int nbr_tetra, int *dim);
int	check_tetra(char **pos);
t_tet	*fix_coor(char **pcs, int nbr_tetra);
int		check_read(int i,int ret,char ***pos);
//int		read_main(char ***pos, char **av);
///t_tet	*fix_coor2(char **pcs);
void	ft_free_tab(char ***tab);
int		ft_dimini(t_tet **tab, int *line);
void	ft_free_tab(char ***tab);
t_tet	**set_lst_from_file(int i, char **pos);
void	ft_display_maill(t_tet *bb, int dim);
//void	ft_display_lst(t_tet *lst);
int		x_max(t_tet *bb, int dim);
int		y_max(t_tet *bb, int dim);
char	**grille_vide(int dim);
int		move_right_dim_ok(t_tet *bb, int dim);
int		move_down_dim_ok(t_tet *bb, int dim);
void		calcul_from_origin(t_tet **bb, int x_mov, int y_mov);
int		move_right(t_tet *bb, int dim, char **grille);
int		move_down(t_tet **bb, int dim, char **grille);
void	print_grille(char **pot, int dim);
void	print_grille_from_pcs(t_tet *new, int dim);
char	**put_next_maill(t_tet **new, int dim, char **tab);
char	**remove_last_maill(t_tet **new, int dim, char **tab);
int		ft_solve(t_tet *new, int dim, char **tab);
int		move_on(t_tet *new, int dim, char **solve); 
int		ft_can_place(t_tet *new, int dim, char **tab);
void	printlist(t_tet **lst, int dim, int ligne);
int		can_move_on(t_tet *new, int dim, char **solve);
int		dim_min(t_tet **tab, int nbr_tetra);
void	write_grille_letter(int *nb_t, char *tab, t_tet *bb);
#endif
