
#include "fillit.h"


void	free_and_del_ch(char	**tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(*tab);
}

void	free_and_del_tt(t_tet		**tt)
{
	int i;

	i = -1;
	while (tt[++i])
		free(tt[i]);
//	free(*tab);
}
