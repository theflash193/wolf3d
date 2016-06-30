/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 14:12:34 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 14:25:53 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
static void	find_direction(t_env *e, t_point pos)
{
	if (e->hori_or_vert && e->player.x - pos.x > 0)
		e->direction = 1;
	else
		e->direction = 0;
	if (!e->hori_or_vert && e->player.y - pos.y > 0)
		e->direction = 1;
	else
		e->direction = 0;
}

void		raycasting(t_env *e, int x)
{
	t_point		pos;
	double		d;
	double		dist;

	pos.x = e->player.x;
	pos.y = e->player.y;
	d = 0.01;
	e->hori_or_vert = 0;
	e->cos = cos(e->tmp_angle) * 0.001;
	e->sin = sin(e->tmp_angle) * 0.001;
	while (e->map[(int)pos.x][(int)pos.y] == 0)
	{
		pos.x += e->cos;
		if (e->map[(int)pos.x][(int)pos.y] != 0)
			e->hori_or_vert = 1;
		pos.y += e->sin;
		d += 0.001;
	}
	find_direction(e, pos);
	dist = (d * cos(e->angle - e->tmp_angle));
	draw_col(e, HEIGHT / dist, x);
}

void		draw_col(t_env *e, double height_wall, int x)
{
	int		y;
	int		tmp;
	int		color;

	if (e->hori_or_vert && e->direction)
		color = 0x00FF00;
	else if (e->hori_or_vert && !e->direction)
		color = 0x6633FF;
	else if (!e->hori_or_vert && e->direction)
		color = 0x77FF55;
	else
		color = 0xFFFF00;
	y = ((HEIGHT / 2) - ((int)height_wall / 2));
	tmp = ((HEIGHT / 2) + ((int)height_wall / 2));
	while (y <= tmp)
	{
		mlx_put_pixel_to_img(e, color, x, y);
		y++;
	}
}
