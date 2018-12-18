/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:21:00 by artderva          #+#    #+#             */
/*   Updated: 2018/12/18 21:12:08 by bebosson         ###   ########.fr       */
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

t_tet	*fix_coor(char **pcs);
t_tet	*fix_coor2(char **pcs);
void	ft_display_maill(t_tet *bb);
void	ft_display_lst(t_tet *lst);
#endif
