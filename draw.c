/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:59:32 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 15:47:10 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
void	mlx_put_pixel_to_img(t_env *e, int color, int x, int y)
{
	unsigned int	color2;

	color2 = mlx_get_color_value(e->mlx, color);
	if ((x < WIDTH && x >= 0) && (y < HEIGHT && y >= 0))
		ft_memcpy(&e->data[(x * 4) + (y * e->size_line)],
			&color2, (size_t)sizeof(int));
}

int		draw(t_env *e)
{
	sky(e);
	ground(e);
	wall(e);
	return (0);
}

void	ground(t_env *e)
{
	int			x;
	int			y;

	y = HEIGHT / 2;

	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel_to_img(e, 0x660000, x, y);
			x++;
		}
		y++;
	}
}

void	sky(t_env *e)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel_to_img(e, 0x0099FF, x, y);
			x++;
		}
		y++;
	}
}

void	wall(t_env *e)
{
	int			x;

	x = 0;
	e->tmp_angle = e->angle - M_PI / 6;
	while (e->tmp_angle <= (e->angle + M_PI / 6))
	{
		raycasting(e, x);
		e->tmp_angle += e->ray;
		x++;
	}
}
