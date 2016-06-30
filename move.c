/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 15:02:15 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 14:25:00 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
void	forward(t_env *e)
{
	double		x;
	double		y;

	x = e->player.x + cos(e->angle) * 0.5;
	y = e->player.y + sin(e->angle) * 0.5;
	if (e->map[(int)x][(int)y] == 1)
		return ;
	e->player.x = x;
	e->player.y = y;
	draw(e);
}

void	backward(t_env *e)
{
	double		x;
	double		y;

	x = e->player.x - cos(e->angle) * 0.5;
	y = e->player.y - sin(e->angle) * 0.5;
	if (e->map[(int)x][(int)y] == 1)
		return ;
	e->player.x -= cos(e->angle) * 0.5;
	e->player.y -= sin(e->angle) * 0.5;
	draw(e);
}

void	left(t_env *e)
{
	e->angle -= M_PI / 18;
	draw(e);
}

void	right(t_env *e)
{
	e->angle += M_PI / 18;
	draw(e);
}
