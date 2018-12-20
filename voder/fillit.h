/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:21:00 by artderva          #+#    #+#             */
/*   Updated: 2018/12/20 05:02:19 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

/*typedef struct		s_tet
{
	int				x[4];
	int				y[4];
	int				x_y[2];
	char			letter;
	struct s_tet	*next;
}					t_tet;*/

typedef struct		s_bis
{
	char			**pcs;
	char			letter;
	struct s_bis	*next;
}					t_bis;

int		ft_check_line(char *line, int i);
t_bis	*initlist(char **pot);
t_bis	*addtolist(t_bis *list, char **tab);
void	printlist(t_bis *lst);
int		check_tetra(char **vdr);
int		check_diese(char **vdr);

#endif
