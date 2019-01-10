#include "fillit.h"


int		read_main(char ***pos)
{
	int fd;
	char *line;
	int i;
	int ret;

	i = 0;
	fd = open("test4", O_RDONLY);
//	printf("%d\n",i);
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


int main()
{
	char *line;
	char **pos;
	int i = 0;
	pos = malloc(44300);
	t_tet *lst;
	int ret = 0;

//	printf("ret = %d \n i = %d \n",ret,i);
	i = read_main(&pos);
//	printf("ret = %d \n i = %d \n",ret,i);
	lst = set_lst_from_file(i, pos);
//	ft_display_lst(lst);// objectif? au il fonctionne
	return (0);
}

