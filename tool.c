/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 14:56:58 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 14:26:21 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
int		init_player(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->nb_line)
	{
		j = 0;
		while (j < e->size)
		{
			if (e->map[i][j] == 0)
			{
				e->player.x = i;
				e->player.y = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_init(t_env *e)
{
	e->angle = 0;
	e->ray = (M_PI / 3) / WIDTH;
	if (init_player(e))
		ft_error(1);
}

t_list	*ft_create_elem(char *str)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->str = ft_strdup(str);
	ret->nb_line = 0;
	ret->next = NULL;
	return (ret);
}

void	ft_lstadd(t_list **begin_list, int i, t_list *new)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (!*begin_list)
	{
		*begin_list = new;
		(*begin_list)->nb_line = i;
	}
	else
	{
		(*begin_list)->nb_line = i;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstdel(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	while (tmp->next)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->str);
		free(tmp2);
	}
	*lst = NULL;
}
