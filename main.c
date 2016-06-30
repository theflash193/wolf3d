/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:22:20 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 15:21:15 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_env	e;
	int		width;
	int		height;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "wolf3d");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line), &(e.endian));
	ft_check(&e, argc, argv);
	ft_parser(&e);
	ft_init(&e);
	draw(&e);
	mlx_loop_hook(e.win, draw, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, eventkeypress, &e);
	mlx_loop(e.mlx);
	return (0);
}
