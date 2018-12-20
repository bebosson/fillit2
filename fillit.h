/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:21:00 by artderva          #+#    #+#             */
/*   Updated: 2018/12/20 01:04:24 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_tet
{
	int				x[4];
	int				y[4];
	int				x_y[2];
	char			letter;
	struct s_tet	*next;
}					t_tet;
void	set_tetra_pos(t_tet *next, int x, int y, int flag);
int	ft_check_line(char *line, int i); // return nbr de line ? -> nbr de tetras 
int	check_diese(char **pcs);
int	check_tetra(char **pos);
t_tet	*fix_coor(char **pcs, int ligne, int nbr_tetra);
int		check_read(int i,int ret,char **pos);
char	**read_main(int *ret, int *i);
///t_tet	*fix_coor2(char **pcs);
t_tet	*set_lst_from_file(int *i, char **pos);
void	ft_display_maill(t_tet *bb);
void	ft_display_lst(t_tet *lst);
#endif
