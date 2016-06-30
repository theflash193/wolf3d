/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:22:08 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/14 11:53:13 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
void	ft_parser(t_env *e)
{
	t_list		*tmp;
	t_list		*lst;
	int			i;
	int			ret;

	i = 0;
	tmp = lst;
	ret = 0;
	lst = NULL;
	read_line(e, &lst);
	init_map(e, lst);
	ft_lstdel(&lst);
}

void	read_line(t_env *e, t_list **lst)
{
	int			i;

	i = 1;
	get_next_line(e->fd, &(e->file));
	if (e->size == 0)
		e->size = ft_strlen(e->file);
	ft_check2(e->file, e->size);
	ft_lstadd(lst, i, ft_create_elem(e->file));
	i++;
	while (get_next_line(e->fd, &(e->file)))
	{
		ft_check2(e->file, e->size);
		ft_lstadd(lst, i, ft_create_elem(e->file));
		i++;
	}
	get_next_line(e->fd, &(e->file));
	ft_check2(e->file, e->size);
	ft_lstadd(lst, i, ft_create_elem(e->file));
}

void	init_map(t_env *e, t_list *lst)
{
	int			i;
	char		**spl_tmp;
	t_list		*tmp;

	i = 0;
	spl_tmp = NULL;
	tmp = lst;
	e->nb_line = lst->nb_line;
	e->map = (int **)malloc(sizeof(int *) * lst->nb_line);
	while (i < lst->nb_line)
	{
		e->map[i] = (int *)malloc(sizeof(int) * e->size);
		i++;
	}
	i = 0;
	while (tmp)
	{
		init_col(e, tmp->str, i, lst->nb_line);
		i++;
		tmp = tmp->next;
	}
}

void	init_col(t_env *e, char *line, int k, int nb_line)
{
	int			i;
	int			j;
	t_list		*tmp;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (k == 0 || (k == nb_line - 1) || (i == 0) || (i == e->size - 1))
			e->map[k][j] = 1;
		else
			e->map[k][j] = (line[i] - '0');
		j++;
		i++;
	}
}
