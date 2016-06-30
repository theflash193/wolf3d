/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/11 18:20:02 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 14:22:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
static int	is_escape(char c)
{
	if (c == '\n'
		|| c == '\v'
		|| c == '\t'
		|| c == '\r'
		|| c == '\f')
		return (1);
	else
		return (0);
}

void		ft_error(int error)
{
	if (error == 0)
		ft_putendl("usage : .fdf file1");
	if (error == 1)
		ft_putendl("invalid map");
	exit(0);
}

void		ft_check(t_env *e, int ac, char **av)
{
	if (ac != 2)
		ft_error(0);
	e->file = av[1];
	e->fd = open(av[1], O_RDONLY);
	if (e->fd == -1)
	{
		ft_putendl(strerror(errno));
		exit(0);
	}
}

void		ft_check2(char *s, int size)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((!ft_isdigit(s[i])) || is_escape(s[i]) ||
			(s[i] != '0' && s[i] != '1'))
			ft_error(1);
		i++;
	}
	if (size != i)
		ft_error(1);
}
