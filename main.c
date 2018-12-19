#include "fillit.h"

int main()
{
	char *line;
	char **pos;
	int i = 0;
	pos = malloc(44300);
	t_tet **lst;
	t_tet *new;
	int fd = open("test1", O_RDONLY);
	int ret;
	while (ret = get_next_line(fd, &line) > 0)
	{
		if (!ft_check_line(line ,i))
		{
			ft_putendl("pb de checkline;");
			return (0);
		}
		pos[i] = ft_strdup(line);
		i++;
	}
	check_main(i, ret, pos);
	lst = set_lst_from_file(i, pos);
	ft_display_lst(lst);
	i = 0;
	return (0);
}
