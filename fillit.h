/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:21:00 by artderva          #+#    #+#             */
/*   Updated: 2018/12/18 18:40:08 by artderva         ###   ########.fr       */
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



#endif
