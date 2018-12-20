#include "fillit.h"


char	**read_main(int *ret, int *i)
{
	int fd;
	char **pos;
	char *line;

	fd = open("test1", O_RDONLY);
	while (((*ret = get_next_line(fd, &line)) > 0))
	{
		if (!ft_check_line(line ,*i))
		{
			ft_putendl("pb de checkline");
			return (0);
		}
		pos[*i] = ft_strdup(line);
		(*i)++;
	}
	if (!(check_read(*i, *ret, pos)))
		ft_putendl("check_main failed");
	return (pos);

}


int main()
{
	char *line;
	char **pos;
	int i;
	pos = malloc(44300);
	t_tet *lst;
	int ret;

	printf("coucou\n");
	pos = read_main(&ret,&i);
	printf("coucou\n");
	lst = set_lst_from_file(&i, pos);
	ft_display_lst(lst);
	return (0);
}
