/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 14:59:25 by fpons             #+#    #+#             */
/*   Updated: 2014/05/15 14:40:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_next_line(int const fd, char **line)
{
	t_var			v;

	v.j = 0;
	v.ret = 1;
	if (fd < 0)
		return (-1);
	return (get_next_line_2(&v, fd, line));
}

int		get_next_line_2(t_var *v, int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};

	while (1)
	{
		v->i = 0;
		while (buf[v->i] && buf[v->i] != '\n')
			v->i++;
		if (v->j == 0 && buf[0] != 0)
			*line = ft_strsub(buf, 0, v->i);
		else if (buf[0] != 0)
			*line = ft_strjoin(*line, ft_strsub(buf, 0, v->i));
		if (buf[v->i] == '\n')
		{
			ft_memcpy(buf, &buf[v->i + 1], BUFF_SIZE - v->i);
			return (1);
		}
		if (buf[v->i] == 0 && v->ret == 0)
			return (0);
		if (buf[0] != 0)
			v->j++;
		if ((v->ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[v->ret] = 0;
	}
	return (0);
}
