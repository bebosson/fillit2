/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listebis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artderva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:19:13 by artderva          #+#    #+#             */
/*   Updated: 2018/12/20 04:51:36 by artderva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_pwt(char **tab)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}

t_bis *initlist(char **pot)
{
	t_bis	*new;
	int i;

	i = 0;
	if (!(new = (t_bis *)malloc(sizeof(t_bis))))
		return (NULL);
	if (!pot[i])
	{
		ft_putendl("1");
		new->pcs[i] = NULL;
		new->next = NULL;
	}
	else
	{
		new->pcs = malloc(sizeof(char *) * 5);
		while (i < 4)
		{
			new->pcs[i] = ft_strdup(pot[i]);
			i++;
		}
		new->letter = 'A';
		new->next = NULL;
	}
	return (new);
}

t_bis *addtolist(t_bis *list, char **tab)
{
	t_bis *maillon;
	int i;
	int c;

	i = -1;
	c = 0;
	maillon = malloc(sizeof(t_bis));
	maillon->pcs = malloc(sizeof(char *) * 5);
	while (++i < 4)
		maillon->pcs[i] = ft_strdup(tab[i]);
	maillon->next = NULL;
	if (list == NULL)
		return (maillon);
	else
	{
		while (list->next != NULL)
		{
			list = list->next;
			c++;
		}
		maillon->letter = 'B' + (char)c;
		list->next = maillon;
		return (list);
	}
}

void	printlist(t_bis *lst)
{
	int i = 0;
	t_bis	*tmp;

	tmp = lst;
	if (tmp == NULL)
	{
		ft_putendl("rate frero");
		return ;
	}
	while (tmp->next != NULL)
	{
		ft_putchar(tmp->letter);
		ft_putchar('\n');
		ft_pwt(tmp->pcs);
		tmp = tmp->next;
	}
}
