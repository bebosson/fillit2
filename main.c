#include "fillit.h"


int		read_main(char ***pos)
{
	int fd;
	char *line;
	int i;
	int ret;

	i = 0;
	fd = open("testounet", O_RDONLY);

	printf("tata\n");
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		if (!(ft_check_line(line ,i + 1)))
		{
			ft_putendl("pb de checkline");
			return (0);
		}
		(*pos)[i] = ft_strdup(line);
		i++;
	}

	if (!(check_read(i, ret, pos)))
		ft_putendl("check_main failed");
	return (i);
}
int		check_place(t_tet **tab, int ligne)
{
	int i;
	int tetra_place;

	tetra_place = 0;
	i = -1;
	while (tab[++i])
		if (tab[i]->placer == 1)
			tetra_place++;
	if (tetra_place < ligne / 5)
		return (0);
	else
		return (1);
}

int		start_solve(t_tet **tab, int ligne)
{
	char **solve;
	int dim;
	int nbr_tetra;
	int i;

	i = 0;
	nbr_tetra = ligne / 5;
	dim = 3;
	solve = grille_vide(dim);
	while (i < nbr_tetra) // check_place != 1
	{
		printf("----- num piece = %d ----- \n",i);
		ft_display_maill(tab[i], dim);
		printf("result !! = %d \n", ft_solve(tab[i], dim, solve));
		if ()
		{
			if(ft_solve(tab[i], dim, solve) == 1)
			solve = put_next_maill(&tab[i],dim,&solve);
		}
/*		else if (ft_solve(tab[i], dim, solve) == 0)
		{
			if (i == 2)
				i--;
			move_on(tab[i], dim, solve);
		}
*/
			ft_display_maill(tab[i], dim);
		printf("toto\n");
		print_grille(solve, dim);
		i++;
	}
	return (0);
}

int main()
{
	char **pos;
	t_tet **tab;
	int ligne = 0;

	pos = malloc(5550000);
	ligne = read_main(&pos);
	tab = set_lst_from_file(ligne, pos);
	printlist(tab, 3, ligne);
	start_solve(tab,ligne);
	return (0);
}
