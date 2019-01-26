#include "fillit.h"


int		read_main(char ***pos, char **av)
{
	int fd;
	char *line;
	int i;
	int ret;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (!(*pos =(char**)malloc(sizeof(char*) * 130)))
		return (0);
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		if (!(ft_check_line(line ,i + 1)))
		{
			ft_putendl("error");
			return (0);
		}
		(*pos)[i] = ft_strdup(line);
		i++;
	}
	if (!(check_read(i, ret, pos)))
	{
		ft_putendl("error");
		i = 0;
	}
	return (i);
}
int		check_place(t_tet **tab, int ligne)
{
	int i;
	int tetra_place;

	tetra_place = 0;
	i = -1;
	while (++i < ligne / 5)
		if (tab[i]->placer == 1)
			tetra_place++;
	if (tetra_place < ligne / 5)
		return (0);
	else
		return (1);
}
void	remove_all_maill(t_tet **tab, int nbr_tetra, char **solve, int dim)
{
	int i;

	i = -1;
	while (++i < nbr_tetra)
	{
		set_tetra_pos_origin(&tab[i]);
		remove_last_maill(&tab[i],dim,solve);
	}
}

int		comb_tetra(t_tet **tab, int i, int dim, char **solve)
{
	int j;

	while (ft_solve(tab[i], dim, solve) == 0)
	{
		j = i - 1;
		set_tetra_pos_origin(&tab[i]);
		while (j >= 0 && ft_can_place(tab[j], dim, solve) == 0)
		{
			if (tab[j]->placer != 0)
				remove_last_maill(&tab[j],dim,solve);
			if (move_on(tab[j],dim, solve) == 1)
			{
				solve = put_next_maill(&tab[j], dim,solve);
				return (dim);
			}
			else
				j--;
		}
		if (j < 0)
		{
			dim++;
			return (dim) ;
		}
	}
		return (dim);
}

char		**start_solve(t_tet **tab, int ligne, int *dim)
{
	char **solve;
	int nbr_tetra;
	int i;
	int new_dim;

	new_dim = *dim;
	i = 0;
	nbr_tetra = ligne / 5;
	solve = grille_vide(*dim);
	while (i <= nbr_tetra)
	{
		if (tab[i]->placer == 0)
		{
			if (ft_solve(tab[i], new_dim, solve) == 1)
				solve = put_next_maill(&tab[i++],new_dim,solve);
			else if (ft_solve(tab[i], new_dim, solve) == 0 && i > 0)
			{
				new_dim = comb_tetra(tab, i,new_dim, solve);
				if (new_dim != *dim)
				{
					solve = grille_vide(new_dim);
					remove_all_maill(tab,nbr_tetra, solve, *dim);
				}
				i = 0;
				*dim = new_dim;
			}
		}
		else if (tab[i]->placer == 1)
			i++;
	}
	return (solve);
}
/*
void	free_and_del(void	***tab)
{
	int i;

	i = 0;
	while (tab[i])

}
*/
int main(int ac, char **av)
{
	char **pos;
	t_tet **tab;
	char **solve;
	int ligne = 0;
	int dim = 1;

	ligne = read_main(&pos,av);
	if (ligne == 0)
		return (0);
	tab = set_lst_from_file(ligne, pos);
	solve = start_solve(tab,ligne, &dim);
	alpha_solve_all(solve, tab, dim, ligne);
	print_grille(solve, dim);
/*	while (1)
		;
*/
	return (0);
}
