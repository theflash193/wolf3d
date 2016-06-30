/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 17:10:42 by grass-kw          #+#    #+#             */
/*   Updated: 2014/05/15 14:28:14 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_display_tab(int **tab, int line, int col)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < line)
	{
		j = 0;
		ft_putstr("ligne ");
		ft_putnbr(i);
		ft_putstr(": ");
		while (j < col)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
