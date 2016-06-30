/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/06 14:41:39 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 15:20:25 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "/usr/X11R6/include/X11/X.h"
# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# define WIDTH 1900
# define HEIGHT 1080

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_list
{
	char			*str;
	int				nb_line;
	struct s_list	*next;
}					t_list;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				fd;
	char			*file;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	double			angle;
	double			tmp_angle;
	double			ray;
	int				**map;
	int				size;
	int				nb_line;
	int				hori_or_vert;
	int				direction;
	double			cos;
	double			sin;
	t_point			player;
}					t_env;

/*
** check.c
*/
void				ft_check(t_env *e, int ac, char **av);
void				ft_check2(char *s, int size);
void				ft_error(int error);
/*
** hook.c
*/
int					expose_hook(t_env *e);
int					eventkeypress(int keycode, t_env *e);
/*
** tool.c
*/
int					init_player(t_env *e);
t_list				*ft_create_elem(char *line);
void				ft_lstadd(t_list **begin_list, int i, t_list *new);
void				ft_init(t_env *e);
void				ft_lstdel(t_list **lst);
/*
** draw_img.c
*/
int					draw(t_env *e);
void				wall(t_env *e);
void				ground(t_env *e);
void				sky(t_env *e);
void				mlx_put_pixel_to_img(t_env *e, int color, int x, int y);
/*
** raycaster.c
*/
void				raycasting(t_env *e, int x);
void				draw_col(t_env *e, double height_wall, int x);
/*
** parser.c
*/
void				ft_parser(t_env *e);
void				init_map(t_env *e, t_list *lst);
void				read_line(t_env *e, t_list **lst);
void				init_col(t_env *e, char *line, int k, int nb_line);
/*
** move.c
*/
void				forward(t_env *e);
void				backward(t_env *e);
void				left(t_env *e);
void				right(t_env *e);

#endif
