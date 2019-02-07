/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebosson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:15:49 by bebosson          #+#    #+#             */
/*   Updated: 2019/02/07 19:43:39 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tabdup(char **tab, char *line, int len)
{
	int		i;
	char	**new;
	char	**tmp;

	if (!(new = (char**)malloc(sizeof(char*) * (len + 2))))
		return (NULL);
	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
		{
			if (!(new[i] = ft_strdup(tab[i])))
				return (NULL);
			i++;
		}
	}
	if (!(new[i] = ft_strdup(line)))
		return (NULL);
	new[i + 1] = NULL;
	if (line)
		free(line);
	if (tab)
		ft_free_tab(&tab);
	return (new);
}

int		read_main(char ***tab, char *file)
{
	int fd;
	int ret;
	char *line;
	int i;
	char **new;

	ret = 0;
	i = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (!(ft_check_line(line, i + 1))) // check qui se fait ligne par ligne
			return (0);
		if (!(*tab = ft_tabdup(*tab, line, ++i)))
			return (0);
	}
	free(line);
	if ((i + 1) % 5 || i > 130)
		return (0);
	return (i);
}

void	ft_free_tet(t_tet ***tab)
{
	void	**tmp;

	tmp = (void *)tab;
/*	while (*tmp)
		ft_memdel(tmp++);
*/
	if (*tab)
		free(*tab);
}
int			main(int ac, char **av)
{
	char	**pos;
	t_tet	**tab;
	char	**solve;
	int		ligne;
	int		dim;

	if (!(ligne = read_main(&pos, av[1])))
		return (0);
	tab = set_lst_from_file(ligne, pos);
	ft_free_tab(&pos);
	dim = ft_dimini(tab, &ligne);
	solve = start_solve(tab, ligne, &dim);
	alpha_solve_all(solve, tab, dim, ligne);
	ft_free_tet(&tab);
	print_grille(solve, dim);
	ft_free_tab(&solve);
	return (0);
}
