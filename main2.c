
#include "fillit.h"

void	dim_piece(int *length, int *width , char **pot)
{
	int i;
	int j;
	int nbr_pcs;

	nbr_pcs = 0;
	i = -1;
	while (pot[++i])
	{
		j = -1;
		while(pot[i][++j])
		{
			if(pot[i][j] ==	'#')
				nbr_pcs++;
			if (pot[i][j - 1] == '#' && pot[i][j] == '#' && ((j > 0) && (j < 4)))
					(*width)++;
			if(nbr_pcs > 3)
				return ;
		}
		if (nbr_pcs != 0)
			(*length)++;
	}
}
void	i_j_max(char **pot, int *i_max, int *j_max)
{
	int i;
	int j;
	int nbr_pcs;

	nbr_pcs = 0;
	i = -1;
	while(pot[++i])
	{
		j = -1;
		while(pot[i][++j])
		{
			if(pot[i][j] == '#')
			{
				if(j > *j_max)
					*j_max  = j;
				if(i > *i_max)
					*i_max = i;
			}
		}
	}
	printf("i_max = %d\n",*i_max);
	printf("j_max = %d\n",*j_max);
}

void	print_pot(char **pot)
{
	int i;

	i = -1;
	ft_putendl("---------------");
	while(pot[++i])
		printf("%s\n",pot[i]);
	ft_putendl("---------------");
}



int		j_trans(char ***pot, int j_max)
{
	int i;
	int j;
	char *tmp;

	i = -1;
	if (j_max ==  3)
		return 0;
	
	printf("caca");
	while (pot[++i])
	{
		j = -1;
		printf("caca");
		while(pot[i][++j])
		{
			if(pot[i][j] ==	"#")
			{
				tmp = ft_strdup(*(*pot + i));
				*pot[i][j] = '.';
				*pot[i] = ft_memmove(pot + i, tmp + 1, 3 - j);
				printf("%s\n",*pot[i]);
			}
		}
	}
	print_pot(*pot);
	return (1);
}


/*
char **xl_trans(char **pot,int l);
*/
char **grille_vide(char **pot, int dim)
{
	int i;
	int j;

	i = -1;

	pot = malloc(66667);

	printf("dim_j= %d\n",dim);
	while(++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if(!(pot[i] = malloc(dim + 1)))
				return (NULL);
			pot[i][j] = '.';
			printf("%c",pot[i][j]);
		}
		pot[i][j] = '\0';
		printf("\n");
	}
	pot[i] = 0;
	return (pot);
}
char **assmbl_piece(char **pot1, char **pot2)
{
	int i;
	int j;
	char **gr_rep;

	i = -1;
		gr_rep = grille_vide(gr_rep,4);
	while (pot1[++i])
	{
		j = -1;
		while(pot1[i][++j])
			if(pot1[i][j] ==	'#' || pot2[i][j] == '#')
				gr_rep[i][j] = '#'; // return 0 
			else
				gr_rep[i][j] = '.';
	}
	print_pot(gr_rep);
	return (gr_rep);
}

int main()
{
	char *line;
	char **pot;
	char **pot2;
	char **grille_rep;
	t_bis	*list;
	int ret;

	pot = malloc(66666);
	pot2 = malloc(45690);
	int i = 0;
	int width = 0;
	int length = 0;
	int fd = open("testoche", O_RDONLY);
	int i_max = 0;
	int j_max = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		pot[i] = ft_strdup(line); //stock la ligne dans un tableau pour LC
		i++;
	}
	i = 0;
	fd = open("testoche2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		pot2[i] = ft_strdup(line); //stock la ligne dans un tableau pour LC
		i++;
	}

	print_pot(pot);
//	pot = assmbl_piece(pot,pot2);
	
	i_j_max(pot,&i_max,&j_max);
	printf("i_max = %d j_max %d \n",i_max,j_max);
	j_trans(&pot,j_max);
	print_pot(pot2);
//	dim_piece(&length,&width,pot 2);
//	xw_trans(pot2,i_max, j_max);
	printf("length = %d\n",length);
	printf("width = %d\n",width);
	return 0;
}
