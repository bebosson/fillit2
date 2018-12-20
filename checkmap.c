/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:53:17 by artderva          #+#    #+#             */
/*   Updated: 2018/12/20 01:08:55 by bebosson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	ft_check_line(char *line, int i)
{
	if (i % 5 == 0 && ft_strlen(line))
		return (0);
	else if (i % 5 != 0)
	{
		if (ft_strlen(line) != 4)
			return (0);
		while (*line)
		{
			if (*line != '.' && *line != '#')
				return (0);
			line++;
		}
	}
	return (i);
}

/*int main()
{
	char *line = ft_strnew(0);
	char *file = ft_strnew(0);
	int fd = open("test5", O_RDONLY);
	int i = 1;
	int ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_check_line(line, i))
		{
			ft_putendl("pb chekline");
			return 0;
		}
		file = ft_strjoin(file, line); //leak sa mere, reutiliser join&free
		i++;
	}
	if (!ret && (i % 5) != 0)
	{
		ft_putendl("pb checkline 2");
		return (0);
	}

	return (1);
}*/

