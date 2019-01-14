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
int		start_solve(t_tet **tab, int ligne)
{
	char **solve;
	int dim;
	int nbr_tetra;

	nbr_tetra = ligne / 5;
	dim = 3;
	solve = grille_vide(dim);
	printf("tata\n");
	solve = put_next_maill(tab[0],dim,&solve);
	print_grille(solve,3);
	ft_solve(tab[1], dim, solve);
	print_grille(solve, dim);
	solve = put_next_maill(tab[1],dim,&solve);
	print_grille(solve, dim);
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
