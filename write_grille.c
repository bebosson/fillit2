/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_grille.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:34:05 by bebosson          #+#    #+#             */
/*   Updated: 2019/01/26 16:47:31 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_grille_diese(int x, int y, int *nb_t, char ***tab)
{
	(*tab)[y][x] = '#';
	(*nb_t)++;
}

void	write_grille_point(int x, int y, int *nb_t, char ***tab)
{
	(*tab)[y][x] = '.';
	(*nb_t)++;
}

void	write_grille_letter(int *nb_t, char *tab, t_tet *bb)
{
	(*tab) = bb->letter;
	(*nb_t)++;
}
