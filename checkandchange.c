/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enhaut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:46:12 by artderva          #+#    #+#             */
/*   Updated: 2019/01/07 20:23:16 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_diese(char **pcs)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (pcs[i])
	{
		j = 0;
		while (pcs[i][j] && i < 4)
		{
			if (pcs[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return (count == 4 ? 1 : 0);
}

int		check_tetra(char **new)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (new[i])
	{
		j = 0;
		while (new[i][j] && i < 4)
		{
			if (new[i][j] == '#')
			{
				count = (i != 3 && new[i + 1][j] == '#') ? count + 1 : count;
				count = (i != 0 && new[i - 1][j] == '#') ? count + 1 : count;
				count = (j != 3 && new[i][j + 1] == '#') ? count + 1 : count;
				count = (j != 0 && new[i][j - 1] == '#') ? count + 1 : count;
			}
			j++;
		}
		i++;
	}
	return (count < 6 ? 0 : 1);
}

int check_read(int i, int ret, char ***pot)
{
//	ft_putendl("tu rentres la?");
	if (!(check_diese(*pot)) && !(check_tetra(*pot)) && !ret && ((i % 5) != 0))
	{
		ft_putendl("tetras non valide mgl");
		return (0);
	}
	return (1);

}

int 	ft_check_line(char *line, int i)
{
	if (i % 5 == 0 && ft_strlen(line))
		return (0);
	else if (i % 5 != 0)
	{
		if (ft_strlen(line) != 4)
			return (0);
		while (*line)
		{
			if (*line != '.' && *line != '#')
				return (0);
			line++;
		}
	}
	return (1);
}


