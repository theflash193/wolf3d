/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 15:33:11 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 15:19:56 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		eventkeypress(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
		forward(e);
	if (keycode == 65364)
		backward(e);
	if (keycode == 65361)
		left(e);
	if (keycode == 65363)
		right(e);
	expose_hook(e);
	return (0);
}
