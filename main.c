/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:07:26 by bebosson          #+#    #+#             */
/*   Updated: 2018/12/18 21:27:05 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

int main(int ac, char **av)
{
	char *line;
	char **pot;
	int i = 0;
	int fd = open(av[1], O_RDONLY);
	t_tet **lst;
	t_tet *new;
	pot = malloc(92000);
	while (get_next_line(fd, &line) > 0)
	{
		pot[i] = ft_strdup(line);
		i++;
	}
	printf("i = %d \n",i);
	new = fix_coor(pot); //obj : retourner un nouveau maillon (tetra) a chaque retour de fonction
	// ? mettre dans while ? 
	// faire pointer lst sur 
	// faire un display parcourant toute la liste ? 
	ft_display_maill(new);
}
