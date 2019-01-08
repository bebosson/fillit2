/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainatej.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:37:32 by artderva          #+#    #+#             */
/*   Updated: 2019/01/07 20:03:13 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

int main()
{
	char *line;
	char **pot;
	char **tmp;
	char *file;
	t_bis	*list;
	int ret;

	pot = malloc(66666);
	tmp = malloc(45690);
	file = ft_strnew(0);
	int i = 0;
	int j = 0;
	int fd = open("testounet", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_check_line(line, i + 1))
		{
			ft_putendl("ERROR CHECKLINE");
			return 0;
		}
		file = ft_strjoin(file, line); // LLLEAAAAAKKKKKKK
		pot[i] = ft_strdup(line); //stock la ligne dans un tableau pour LC
		i++;
	}
	if (!ret && ((i + 1) % 5) != 0)
	{
		ft_putendl("ERROR CHECKLINE");
		return 0;
	}
	i = 0;
	while (pot[i])
	{
		j = 0;
		while (pot[i] && ft_strlen(pot[i]))
		{
			tmp[j]=pot[i];
			i++;
			j++;
		}
		if (!(check_diese(tmp)) ||!(check_tetra(tmp)))
		{
			ft_putendl("tetrominos non valable deso");
			return 0;
		}
		if (i < 6)
			list = initlist(tmp);
		else
			addtolist(list, tmp);
		i++;
	}
	free(tmp);
	printlist(list);
}
