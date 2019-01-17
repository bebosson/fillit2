#include "fillit.h"


int		read_main(char ***pos)
{
	int fd;
	char *line;
	int i;
	int ret;

	i = 0;
	fd = open("testounet", O_RDONLY);

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
		remove_last_maill(&tab[i],dim,&solve); // fonction
}

void		comb_tetra(t_tet **tab, int i, int dim, char **solve)
{
	int j;
//ERREUR SUR move_on: utilise ft_solve sans remove la piece; 

	ft_putendl("-------comb_tetra------");
	printf("IIIIIIIIII  =============== %d\n",i);
		ft_display_maill(tab[i], dim);
	while (ft_solve(tab[i], dim, solve) == 0)
	{
		
		j = i - 1;
		
		ft_putendl("======= while_ft_solve_comb_tetra ======");
		
		printf("--------ORIGINE------- \n");
		set_tetra_pos_origin(&tab[i]);
		ft_display_maill(tab[i], dim);

		printf("========J===%d========\n",j);

		ft_display_maill(tab[j], dim);
		print_grille(solve, dim);
		
		printf("CAN_PLACE = %d\n",ft_can_place(tab[j], dim, solve));
		while (j >= 0 && ft_can_place(tab[j], dim, solve) == 0)
		{

			ft_putendl("======while_comb_tetra=====");
			printf("======= J === %d =======\n",j);
			ft_display_maill(tab[j], dim);
			printf("REMOVE \n");
			remove_last_maill(&tab[j],dim,&solve); // fonction
			print_grille(solve, dim);
			printf("CAN_MOVE_ON = %d\n",can_move_on(tab[j],dim,solve));
			if ((can_move_on(tab[j],dim,solve) == 1))
			{
				move_on(tab[j],dim,solve);
				ft_display_maill(tab[j], dim);
				ft_putendl("PUT\n");
				solve = put_next_maill(&tab[j], dim,&solve);
				print_grille(solve, dim);
				break ;
			}
			else
				j--;
		}
//	printlist(tab, 3, ligne);
		printf("====J=%d======\n",j);
		ft_display_maill(tab[j], dim);
		printf("t'es la \n");
	}

		ft_display_maill(tab[i], dim);
}

char		**start_solve(t_tet **tab, int ligne, int dim)
{
	char **solve;
	int nbr_tetra;
	int i;

	i = 0;
	nbr_tetra = ligne / 5;
	solve = grille_vide(dim);
	while (i <= nbr_tetra) // check_place != 1 && i <= nbr_tetra pout le dernier
	{
		printf("----- num piece = %d ----- \n",i);
		ft_display_maill(tab[i], dim);
//		printf("result !! = %d \n", ft_solve(tab[i], dim, solve));
		if (ft_can_place(tab[i],dim,solve) == 1)
		{
			printf("wesh\n");
			solve = put_next_maill(&tab[i],dim,&solve);
			print_grille(solve, dim);
			i++;
		}
		else if (ft_can_place(tab[i],dim,solve) == 0 && tab[i]->placer == 0)
		{
			if(ft_solve(tab[i], dim, solve) == 1)
			{
				printf("-----tadam-----\n");
				solve = put_next_maill(&tab[i], dim,&solve);
				i++;
			}
			else if(ft_solve(tab[i], dim, solve) == 0 && i > 0)
			{
				print_grille(solve, dim);
				ft_putendl("-------avant------");
				//remove_last_maill(&tab[i-1],dim,&solve); // fonction
				//move_on(tab[i-1],dim,solve);// fonction
				
				printf("t'es la \n");
//				break ;
				comb_tetra(tab, i, dim, solve);
				i--;
//				break ; 
				//return (start_solve(tab, ligne));
			}
		}
		else if (tab[i]->placer == 1)
				i++;
		print_grille(solve, dim);
//	printf("----- nbr_tetra = %d ----- \n",nbr_tetra);
	}
	//ATTENTION ft_solve met tab[i]->placer = 0 
	return (solve);
}

int main()
{
	char **pos;
	t_tet **tab;
	char **solve;
	int ligne = 0;
	int dim = 3;

	pos = malloc(5550000);
	ligne = read_main(&pos);
	tab = set_lst_from_file(ligne, pos);
	printlist(tab, dim, ligne);
	solve = start_solve(tab,ligne, dim);
	print_grille(solve, dim);
	alpha_solve_all(solve, tab, dim, ligne);
	print_grille(solve, dim);
	return (0);
}
